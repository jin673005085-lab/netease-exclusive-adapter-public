/* Ghidra pseudocode; NOT original C++ source and NOT directly compilable.
 * DLL SHA256: 4a9e32cfffaed5b0ec60f3e5844113218245571f66837aae19adb23a149122db
 * Evidence: ev_e186c4b5088577547f95a08c752b6c11b59c7fb8c0e6579917624fb3b7116b8b
 */

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint FUN_18000c710(longlong param_1,undefined8 param_2)

{
  char cVar1;
  undefined1 uVar2;
  longlong lVar3;
  uint uVar4;
  undefined *puVar5;
  longlong *plVar6;
  undefined1 *puVar7;
  undefined1 (*local_38) [32];
  ulonglong local_30;
  undefined1 local_28;
  longlong local_20;

  puVar5 = FUN_180004ae0();
  cVar1 = puVar5[0x50];
  *(uint *)(param_1 + 0x158) = (uint)(cVar1 != '\0');
  puVar7 = (undefined1 *)
           (*(longlong *)((longlong)ThreadLocalStoragePointer + (ulonglong)_tls_index * 8) + 0x10);
  uVar2 = *puVar7;
  plVar6 = (longlong *)
           (*(longlong *)((longlong)ThreadLocalStoragePointer + (ulonglong)_tls_index * 8) + 0x18);
  lVar3 = *plVar6;
  *puVar7 = 1;
  *plVar6 = param_1;
  local_38 = (undefined1 (*) [32])0x18003b630;
  if (cVar1 != '\0') {
    local_38 = (undefined1 (*) [32])0x18003b5f0;
  }
  local_28 = uVar2;
  local_20 = lVar3;
  local_30 = FUN_18002cb80(local_38);
  FUN_1800225c0((LPSTR ******)&local_38,0);
  uVar4 = (*DAT_1800514a0)(param_1,param_2);
  local_38 = (undefined1 (*) [32])0x18003b668;
  local_30 = 0x19;
  FUN_1800225c0((LPSTR ******)&local_38,uVar4);
  *puVar7 = uVar2;
  *plVar6 = lVar3;
  return uVar4;
}
