"""Validate the shipped transition helper and patched Hook layout."""
import ctypes
import importlib.util
import os
from pathlib import Path
import struct
import unittest
import zipfile

import pefile

ROOT = Path(__file__).resolve().parents[1]
spec = importlib.util.spec_from_file_location('declick', ROOT/'scripts/build_declick.py')
declick = importlib.util.module_from_spec(spec)
spec.loader.exec_module(declick)


class TransitionPatch(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        with zipfile.ZipFile(ROOT/'runtime/payload.zip') as archive:
            cls.original = archive.read('NetEase/nc-exclusive-hook.dll')
        cls.helper = (ROOT/'runtime/declick-helper.dll').read_bytes()
        cls.patched = declick.patch_hook(cls.original, cls.helper)
        cls.pe = pefile.PE(data=cls.patched)

    def test_rejects_changed_input(self):
        changed = bytearray(self.original)
        changed[0x1000] ^= 1
        with self.assertRaisesRegex(ValueError, 'Unrecognized Hook'):
            declick.patch_hook(bytes(changed), self.helper)
        bad_helper = pefile.PE(data=self.helper)
        bad_helper.sections[4].VirtualAddress += 0x10000
        with self.assertRaisesRegex(ValueError, 'linked with .bss'):
            declick.patch_hook(self.original, bad_helper.write())

    def test_pe_layout_and_unwind(self):
        old = pefile.PE(data=self.original)
        new = self.pe
        self.assertEqual(new.OPTIONAL_HEADER.CheckSum, new.generate_checksum())
        self.assertEqual(new.sections[-2].Characteristics, 0x60000020)
        self.assertEqual(new.sections[-1].Characteristics, 0xc0000080)
        self.assertEqual(new.sections[-1].VirtualAddress, 0x62000)
        self.assertEqual(new.OPTIONAL_HEADER.SizeOfImage, 0x63000)
        self.assertEqual(new.OPTIONAL_HEADER.DllCharacteristics, old.OPTIONAL_HEADER.DllCharacteristics)
        self.assertEqual(new.get_data(0x5a000, 2128), old.get_data(0x5a000, 2128))
        rows = new.DIRECTORY_ENTRY_EXCEPTION
        self.assertEqual(len(rows), len(old.DIRECTORY_ENTRY_EXCEPTION)+4)
        starts = [r.struct.BeginAddress for r in rows]
        self.assertEqual(starts, sorted(set(starts)))
        for row in rows:
            self.assertLess(row.struct.BeginAddress, row.struct.EndAddress)
            self.assertTrue(new.get_data(row.struct.UnwindData, 4))
        # Only the two reviewed callsite ranges may change in original executable code.
        for section in old.sections:
            if section.Characteristics & 0x20000000:
                before = section.get_data()
                after = new.get_data(section.VirtualAddress, len(before))
                for i, (a, b) in enumerate(zip(before, after)):
                    if a != b:
                        rva = section.VirtualAddress+i
                        self.assertTrue(0x15bed <= rva < 0x15bfa or 0x1665c <= rva < 0x16689)
        exports = {e.name: e.address for e in pefile.PE(data=self.helper).DIRECTORY_ENTRY_EXPORT.symbols}
        for call, name in [(0x15bf0, b'declick_stop'), (0x16678, b'declick_release')]:
            self.assertEqual(new.get_data(call, 1), b'\xe8')
            delta = struct.unpack('<i', new.get_data(call+1, 4))[0]
            self.assertEqual(call+5+delta, exports[name])

    @unittest.skipUnless(os.name == 'nt', 'Windows execution check')
    def test_native_execution_at_relocated_address(self):
        # Map without DllMain: only our helper and the reviewed Stop callsite execute.
        kernel = ctypes.WinDLL('kernel32', use_last_error=True)
        kernel.VirtualAlloc.restype = ctypes.c_void_p
        kernel.VirtualAlloc.argtypes = [ctypes.c_void_p, ctypes.c_size_t, ctypes.c_uint32, ctypes.c_uint32]
        kernel.VirtualFree.argtypes = [ctypes.c_void_p, ctypes.c_size_t, ctypes.c_uint32]
        kernel.VirtualProtect.argtypes = [ctypes.c_void_p, ctypes.c_size_t, ctypes.c_uint32, ctypes.POINTER(ctypes.c_uint32)]
        base = kernel.VirtualAlloc(None, 0x63000, 0x3000, 4)
        self.assertTrue(base)
        try:
            self.assertNotEqual(base, self.pe.OPTIONAL_HEADER.ImageBase)
            mapped = pefile.PE(data=self.patched).get_memory_mapped_image()
            ctypes.memmove(base, mapped, len(mapped))
            # Entry wrapper preserves R14 and shadow space; callsite's next instruction returns.
            wrapper = bytes.fromhex('41564883ec284c8bf1e8')+struct.pack('<i', 0x15bed-(0x5b900+14))+bytes.fromhex('4883c428415ec3')
            ctypes.memmove(base+0x5b900, wrapper, len(wrapper))
            ctypes.memmove(base+0x15bfa, b'\xc3', 1)
            waits, sleeps = [], []
            wait_fn = ctypes.WINFUNCTYPE(ctypes.c_uint32, ctypes.c_void_p, ctypes.c_uint32)(lambda p, ms: waits.append(ms) or 0)
            sleep_fn = ctypes.WINFUNCTYPE(None, ctypes.c_uint32)(lambda ms: sleeps.append(ms))
            ctypes.c_void_p.from_address(base+0x3a140).value = ctypes.cast(wait_fn, ctypes.c_void_p).value
            ctypes.c_void_p.from_address(base+0x3a210).value = ctypes.cast(sleep_fn, ctypes.c_void_p).value
            previous = ctypes.c_uint32()
            self.assertTrue(kernel.VirtualProtect(base, 0x62000, 0x20, ctypes.byref(previous)))
            stopped = []
            stopped_fn = ctypes.WINFUNCTYPE(ctypes.c_int32, ctypes.c_void_p)(lambda p: stopped.append(p) or 123)
            table = (ctypes.c_void_p*12)()
            table[11] = ctypes.cast(stopped_fn, ctypes.c_void_p).value
            client = ctypes.c_void_p(ctypes.addressof(table))
            sink = ctypes.create_string_buffer(0x340)
            struct.pack_into('<Q', sink, 0x220, ctypes.addressof(client))
            # A stopped/silent sink must call the original Stop without waiting on the device.
            run = ctypes.WINFUNCTYPE(ctypes.c_int32, ctypes.c_void_p)(base+0x5b900)
            self.assertEqual(run(ctypes.addressof(sink)), 123)
            self.assertEqual(stopped, [ctypes.addressof(client)])
            pcm = (ctypes.c_int16*1920)(*([20000]*1920))
            tail = (ctypes.c_int16*1920)()
            submitted = []
            def get_buffer(p, frames, target):
                target[0] = ctypes.addressof(tail)
                return 0
            get_fn = ctypes.WINFUNCTYPE(ctypes.c_int32, ctypes.c_void_p, ctypes.c_uint32, ctypes.POINTER(ctypes.c_void_p))(get_buffer)
            release_fn = ctypes.WINFUNCTYPE(ctypes.c_int32, ctypes.c_void_p, ctypes.c_uint32, ctypes.c_uint32)(lambda p, n, flags: submitted.append((n, flags)) or 0)
            render_table = (ctypes.c_void_p*5)()
            render_table[3] = ctypes.cast(get_fn, ctypes.c_void_p).value
            render_table[4] = ctypes.cast(release_fn, ctypes.c_void_p).value
            render = ctypes.c_void_p(ctypes.addressof(render_table))
            for offset, fmt, value in [(0x53, 'B', 1), (0x56, 'H', 2), (0x58, 'I', 48000),
                                       (0x244, 'H', 4), (0x246, 'H', 16), (0x24a, 'H', 16),
                                       (0x260, 'I', 960), (0x228, 'Q', ctypes.addressof(render)), (0x1f8, 'Q', 1)]:
                struct.pack_into('<'+fmt, sink, offset, value)
            exports = {e.name: e.address for e in pefile.PE(data=self.helper).DIRECTORY_ENTRY_EXPORT.symbols}
            release = ctypes.WINFUNCTYPE(ctypes.c_int32, ctypes.c_void_p, ctypes.c_void_p, ctypes.c_uint32, ctypes.c_int)(base+exports[b'declick_release'])
            self.assertEqual(release(ctypes.addressof(sink), pcm, 0, 1), 0)
            self.assertEqual((pcm[0], pcm[478], pcm[-1]), (0, 20000, 20000))
            self.assertEqual(run(ctypes.addressof(sink)), 123)
            self.assertEqual((tail[0], tail[478], tail[-1]), (20000, 0, 0))
            self.assertEqual((waits, sleeps, submitted), ([100], [42], [(960, 0), (960, 0)]))
        finally:
            kernel.VirtualFree(base, 0, 0x8000)


if __name__ == '__main__':
    unittest.main()
