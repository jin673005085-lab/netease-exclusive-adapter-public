/* Ghidra pseudocode; NOT original C++ source and NOT directly compilable.
 * DLL SHA256: 4a9e32cfffaed5b0ec60f3e5844113218245571f66837aae19adb23a149122db
 * Evidence: ev_06e82777ab5301a516d971fd302b75a0f262ec8f7c63dbadf7db995087a196b3
 */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_180003450(void)

{
  longlong lVar1;
  LPVOID pvVar2;
  bool bVar3;
  bool bVar4;
  undefined1 (*pauVar5) [32];
  ulonglong uVar6;
  undefined1 (*pauVar7) [32];
  LPWSTR pWVar8;
  ulonglong uVar9;
  undefined8 uVar10;
  LPVOID pvVar11;
  undefined **ppuVar12;
  undefined1 auStackY_c8 [32];
  undefined1 (*local_90) [32];
  undefined8 uStack_88;
  ulonglong local_80;
  ulonglong local_78;
  undefined2 local_70;
  undefined6 uStack_6e;
  undefined8 local_60;
  ulonglong uStack_58;
  WCHAR local_50;
  undefined6 uStack_4e;
  undefined8 local_40;
  ulonglong uStack_38;
  ulonglong local_30;

  local_30 = DAT_180050580 ^ (ulonglong)auStackY_c8;
  bVar4 = false;
  bVar3 = false;
  pauVar5 = (undefined1 (*) [32])GetCommandLineW();
  local_90 = (undefined1 (*) [32])0x0;
  uStack_88 = 0;
  local_80 = 0;
  local_78 = 0;
  uVar6 = FUN_18002cb80(pauVar5);
  FUN_180001c40(&local_90,(undefined8 *)pauVar5,uVar6);
  pauVar5 = (undefined1 (*) [32])&local_90;
  if (7 < local_78) {
    pauVar5 = local_90;
  }
  if (6 < local_80) {
    lVar1 = local_80 * 2;
    pauVar7 = thunk_FUN_180025a50(pauVar5,(undefined1 (*) [32])(*pauVar5 + lVar1),
                                  (undefined1 (*) [16])L"--type=",7);
    if ((pauVar7 != (undefined1 (*) [32])(*pauVar5 + lVar1)) &&
       ((longlong)pauVar7 - (longlong)pauVar5 >> 1 != -1)) goto LAB_18000358d;
  }
  pWVar8 = FUN_180023480(&local_50,(HMODULE)0x0);
  pauVar7 = (undefined1 (*) [32])FUN_180021920((undefined8 *)&local_70,pWVar8);
  bVar4 = true;
  bVar3 = true;
  pauVar5 = pauVar7;
  if (7 < *(ulonglong *)((longlong)*pauVar7 + 0x18)) {
    pauVar5 = *(undefined1 (**) [32])*pauVar7;
  }
  uVar6 = *(ulonglong *)((longlong)*pauVar7 + 0x10);
  ppuVar12 = &PTR_u_3_1_36_205322_18003aa10;
  do {
    pauVar7 = (undefined1 (*) [32])ppuVar12[1];
    uVar9 = FUN_18002cb80(pauVar7);
    if (uVar6 == uVar9) {
      if (uVar6 != 0) {
        uVar10 = FUN_180003970(pauVar5,pauVar7,uVar6);
        if ((int)uVar10 != 0) goto LAB_180003584;
      }
      uVar10 = 1;
      goto LAB_18000358f;
    }
LAB_180003584:
    ppuVar12 = ppuVar12 + 6;
  } while (ppuVar12 != (undefined **)L"3.1.36.205322");
LAB_18000358d:
  uVar10 = 0;
LAB_18000358f:
  if (bVar3) {
    if (7 < uStack_58) {
      pvVar2 = (LPVOID)CONCAT62(uStack_6e,local_70);
      pvVar11 = pvVar2;
      if ((0xfff < uStack_58 * 2 + 2) &&
         (pvVar11 = *(LPVOID *)((longlong)pvVar2 + -8),
         0x1f < (ulonglong)((longlong)pvVar2 + (-8 - (longlong)pvVar11)))) {
                    /* WARNING: Subroutine does not return */
        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
      }
      thunk_FUN_180030590(pvVar11);
    }
    local_60 = 0;
    uStack_58 = 7;
    local_70 = 0;
  }
  if (bVar4) {
    if (7 < uStack_38) {
      pvVar2 = (LPVOID)CONCAT62(uStack_4e,local_50);
      pvVar11 = pvVar2;
      if ((0xfff < uStack_38 * 2 + 2) &&
         (pvVar11 = *(LPVOID *)((longlong)pvVar2 + -8),
         0x1f < (ulonglong)((longlong)pvVar2 + (-8 - (longlong)pvVar11)))) {
                    /* WARNING: Subroutine does not return */
        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
      }
      thunk_FUN_180030590(pvVar11);
    }
    local_40 = 0;
    uStack_38 = 7;
    local_50 = L'\0';
  }
  if (7 < local_78) {
    pauVar5 = local_90;
    if ((0xfff < local_78 * 2 + 2) &&
       (pauVar5 = *(undefined1 (**) [32])(local_90[-1] + 0x18),
       0x1f < (ulonglong)((longlong)local_90 + (-8 - (longlong)pauVar5)))) {
                    /* WARNING: Subroutine does not return */
      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
    }
    thunk_FUN_180030590(pauVar5);
  }
  return uVar10;
}
