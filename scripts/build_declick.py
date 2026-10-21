"""Build the transition patch for the pinned Hook; never install it."""
import argparse
import hashlib
from pathlib import Path
import shutil
import struct
import subprocess

import pefile


ROOT=Path(__file__).resolve().parents[1]
PATCH_RVA=0x5b000
ORIGINAL_HASH='4a9e32cfffaed5b0ec60f3e5844113218245571f66837aae19adb23a149122db'
ADAPTED_HASH='25293c9679cd4b9616d8e4151d1cdf7eef77da86a326c844afc78a9fceba1bed'


def check(condition,message):
    if not condition:
        raise ValueError(message)


def align(value,boundary):
    return (value+boundary-1)//boundary*boundary


def patch_hook(data,helper):
    check(hashlib.sha256(data).hexdigest() in (ORIGINAL_HASH,ADAPTED_HASH),'Unrecognized Hook')
    host=pefile.PE(data=data)
    compiled=pefile.PE(data=helper)
    check(host.FILE_HEADER.Machine==compiled.FILE_HEADER.Machine==0x8664,'Expected x64 PE')
    check(host.OPTIONAL_HEADER.SizeOfImage==PATCH_RVA,'Unexpected host image size')
    check(not hasattr(compiled,'DIRECTORY_ENTRY_IMPORT'),'Helper must have no imports')
    check(not hasattr(compiled,'DIRECTORY_ENTRY_BASERELOC'),'Helper must use only relative addresses')
    check(compiled.OPTIONAL_HEADER.ImageBase==host.OPTIONAL_HEADER.ImageBase,'Helper image base differs')
    exports={s.name.decode():s.address for s in compiled.DIRECTORY_ENTRY_EXPORT.symbols}
    sections={s.Name.rstrip(b'\0').decode():s for s in compiled.sections}
    check(sections['.text'].VirtualAddress==PATCH_RVA,'Helper text address differs')
    blob=bytearray(0x4000)
    for name in ['.text','.rdata','.pdata','.xdata']:
        section=sections[name]
        offset=section.VirtualAddress-PATCH_RVA
        check(0<=offset and offset+section.SizeOfRawData<=len(blob),'Helper section outside patch')
        blob[offset:offset+section.SizeOfRawData]=section.get_data()
    old_exception=host.OPTIONAL_HEADER.DATA_DIRECTORY[3]
    rows=[host.get_data(old_exception.VirtualAddress+i,12) for i in range(0,old_exception.Size,12)]
    new_exception=compiled.OPTIONAL_HEADER.DATA_DIRECTORY[3]
    rows.extend(compiled.get_data(new_exception.VirtualAddress+i,12) for i in range(0,new_exception.Size,12))
    rows.sort(key=lambda row:struct.unpack('<I',row[:4])[0])
    table=b''.join(rows)
    table_offset=len(blob)
    blob.extend(table)
    rw_rva=align(PATCH_RVA+len(blob),0x1000)
    check(rw_rva==0x62000,'Unexpected merged exception table size')
    # Keep compiler-generated RIP-relative state references in a separate RW section.
    check(sections['.bss'].VirtualAddress==rw_rva,'Helper must be linked with .bss at the RW section RVA')
    return _finish(host,data,blob,rw_rva,sections['.bss'].Misc_VirtualSize,table_offset,len(table),exports)


def _finish(host,data,blob,rw_rva,rw_size,table_offset,table_size,exports):
    result=bytearray(data)
    patches=[
        (0x15bed,bytes.fromhex('488b01488b4058ff15d6480200'),
         bytes.fromhex('498bce')+b'\xe8'+struct.pack('<i',exports['declick_stop']-0x15bf5)+b'\x90'*5),
        (0x1665c,bytes.fromhex('488b8f2802000041b8020000008b97600200004585ff41bd00000000450f45c5488b01488b4020ff15473e0200'),None),
    ]
    # Preserve nonvolatile R13's zero value used by the host after ReleaseBuffer.
    code=bytes.fromhex('4533ed488bcf488b5424204533c04585ff750641b802000000458bcc')
    code+=b'\xe8'+struct.pack('<i',exports['declick_release']-(0x1665c+len(code)+5))
    patches[1]=(patches[1][0],patches[1][1],code+b'\x90'*(len(patches[1][1])-len(code)))
    for rva,expected,replacement in patches:
        offset=host.get_offset_from_rva(rva)
        check(data[offset:offset+len(expected)]==expected,f'Unexpected patch site {rva:#x}')
        check(len(expected)==len(replacement),'Patch length mismatch')
        result[offset:offset+len(expected)]=replacement
    section_header=host.sections[-1].get_file_offset()+40
    check(section_header+80<=host.OPTIONAL_HEADER.SizeOfHeaders,'No space for PE headers')
    raw=align(len(result),host.OPTIONAL_HEADER.FileAlignment)
    raw_size=align(len(blob),host.OPTIONAL_HEADER.FileAlignment)
    result.extend(b'\0'*(raw-len(result)))
    result.extend(blob+b'\0'*(raw_size-len(blob)))
    def header(name,size,rva,raw_bytes,raw_offset,flags):
        return struct.pack('<8sIIIIIIHHI',name,size,rva,raw_bytes,raw_offset,0,0,0,0,flags)
    result[section_header:section_header+40]=header(b'.ncpop',len(blob),PATCH_RVA,raw_size,raw,0x60000020)
    result[section_header+40:section_header+80]=header(b'.ncpdat',rw_size,rw_rva,0,0,0xc0000080)
    struct.pack_into('<H',result,host.FILE_HEADER.get_field_absolute_offset('NumberOfSections'),len(host.sections)+2)
    struct.pack_into('<I',result,host.OPTIONAL_HEADER.get_field_absolute_offset('SizeOfCode'),host.OPTIONAL_HEADER.SizeOfCode+raw_size)
    struct.pack_into('<I',result,host.OPTIONAL_HEADER.get_field_absolute_offset('SizeOfUninitializedData'),host.OPTIONAL_HEADER.SizeOfUninitializedData+align(rw_size,host.OPTIONAL_HEADER.SectionAlignment))
    struct.pack_into('<I',result,host.OPTIONAL_HEADER.get_field_absolute_offset('SizeOfImage'),align(rw_rva+rw_size,0x1000))
    struct.pack_into('<II',result,host.OPTIONAL_HEADER.DATA_DIRECTORY[3].get_file_offset(),PATCH_RVA+table_offset,table_size)
    final=pefile.PE(data=bytes(result))
    struct.pack_into('<I',result,final.OPTIONAL_HEADER.get_field_absolute_offset('CheckSum'),final.generate_checksum())
    return bytes(result)


def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--hook',type=Path,required=True)
    parser.add_argument('--out',type=Path,required=True)
    parser.add_argument('--gcc',default=shutil.which('gcc'))
    args=parser.parse_args()
    check(not args.out.exists(),'Output already exists')
    data=args.hook.read_bytes()
    check(args.gcc,'A local MinGW-w64 GCC is required')
    work=ROOT/'artifacts/declick'
    work.mkdir(parents=True,exist_ok=True)
    helper=work/'helper.dll'
    subprocess.run([args.gcc,'-O2','-fno-ident','-fno-stack-protector','-fno-builtin','-mno-stack-arg-probe',
                    '-nostdlib','-shared','-Wl,--entry,0,--image-base,0x180000000,--section-start,.text=0x18005b000,--section-start,.bss=0x180062000,--no-insert-timestamp',
                    'native/declick.c','-o','artifacts/declick/helper.dll'],cwd=ROOT,check=True)
    patched=patch_hook(data,helper.read_bytes())
    args.out.parent.mkdir(parents=True,exist_ok=True)
    args.out.write_bytes(patched)
    print('Built transition patch:',args.out,'SHA256:',hashlib.sha256(args.out.read_bytes()).hexdigest())


if __name__=='__main__':
    main()
