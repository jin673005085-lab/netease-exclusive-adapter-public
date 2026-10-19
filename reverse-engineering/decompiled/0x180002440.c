/* Ghidra pseudocode; NOT original C++ source and NOT directly compilable.
 * DLL SHA256: 4a9e32cfffaed5b0ec60f3e5844113218245571f66837aae19adb23a149122db
 * Evidence: ev_14f9b8ef1f4c49dbdd4a95a2f714c90b43d561290468e73c2974573c5ba7b1e1
 */

void FUN_180002440(void)

{
  char cVar1;
  int iVar2;
  HMODULE pHVar3;
  uint *puVar4;
  undefined8 uVar5;
  char *pcVar6;
  LPSTR *****local_18;
  undefined8 local_10;

  pcVar6 = (char *)(*(longlong *)((longlong)ThreadLocalStoragePointer + (ulonglong)_tls_index * 8) +
                   8);
  if (*pcVar6 == '\0') {
    *pcVar6 = '\x01';
    iVar2 = FUN_180025e38((uint *)&DAT_180050000);
    if (iVar2 != 0) {
                    /* WARNING: Subroutine does not return */
      FUN_180026614(5);
    }
    if (DAT_18005004c == 0x7fffffff) {
      DAT_18005004c = 0x7ffffffe;
                    /* WARNING: Subroutine does not return */
      FUN_180026614(6);
    }
    if (DAT_180051380 == '\0') {
      pHVar3 = GetModuleHandleW(L"cloudmusic.dll");
      if (pHVar3 != (HMODULE)0x0) {
        DAT_180051380 = '\x01';
        cVar1 = FUN_18000e8e0(pHVar3);
        if (cVar1 == '\0') {
          puVar4 = (uint *)FUN_180004ae0();
          FUN_1800048f0(puVar4,0);
          local_18 = (LPSTR *****)0x18003aed0;
          local_10 = 0x15;
          FUN_1800225c0(&local_18,0x80004001);
        }
      }
    }
    if (DAT_180051381 == '\0') {
      pHVar3 = GetModuleHandleW(L"libcef.dll");
      if (pHVar3 != (HMODULE)0x0) {
        DAT_180051381 = '\x01';
        uVar5 = FUN_18001e010(pHVar3,DAT_180051368);
        if ((char)uVar5 == '\0') {
          local_18 = (LPSTR *****)0x18003af18;
          local_10 = 0x12;
          FUN_1800225c0(&local_18,0x80004001);
        }
      }
    }
    FUN_180025e40(0x180050000);
    *pcVar6 = '\0';
  }
  return;
}
