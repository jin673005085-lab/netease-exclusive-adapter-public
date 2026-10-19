/* Ghidra pseudocode; NOT original C++ source and NOT directly compilable.
 * DLL SHA256: 4a9e32cfffaed5b0ec60f3e5844113218245571f66837aae19adb23a149122db
 * Evidence: ev_ceab58dbd10902d2af2af1187a9ed971fbffc2ccea859a32a38e3e08540b45ae
 */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

char FUN_18000e8e0(HMODULE param_1)

{
  LPVOID pvVar1;
  undefined **ppuVar2;
  int iVar3;
  LPWSTR pWVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  uint *puVar7;
  undefined1 (*pauVar8) [32];
  undefined1 (*pauVar9) [32];
  LPVOID pvVar10;
  undefined **ppuVar11;
  longlong *plVar12;
  wchar_t *pwVar13;
  char cVar14;
  undefined1 auStackY_e8 [32];
  undefined1 (*local_b8) [32];
  ulonglong local_b0;
  undefined1 (*local_a8 [2]) [32];
  ulonglong local_98;
  ulonglong local_90;
  LPVOID local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  ulonglong uStack_70;
  WCHAR local_68;
  undefined6 uStack_66;
  undefined8 local_58;
  ulonglong uStack_50;
  undefined2 local_48;
  undefined6 uStack_46;
  undefined8 local_38;
  ulonglong uStack_30;
  ulonglong local_28;

  local_28 = DAT_180050580 ^ (ulonglong)auStackY_e8;
  pWVar4 = FUN_180023480(&local_68,param_1);
  FUN_180021920(local_a8,pWVar4);
  if (7 < uStack_50) {
    pvVar1 = (LPVOID)CONCAT62(uStack_66,local_68);
    pvVar10 = pvVar1;
    if ((0xfff < uStack_50 * 2 + 2) &&
       (pvVar10 = *(LPVOID *)((longlong)pvVar1 + -8),
       0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)pvVar10)))) {
                    /* WARNING: Subroutine does not return */
      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
    }
    thunk_FUN_180030590(pvVar10);
  }
  local_58 = 0;
  uStack_50 = 7;
  local_68 = L'\0';
  ppuVar11 = &PTR_u_3_1_36_205322_18003aa10;
  do {
    pauVar8 = (undefined1 (*) [32])ppuVar11[2];
    uVar5 = FUN_18002cb80(pauVar8);
    pauVar9 = (undefined1 (*) [32])local_a8;
    if (7 < local_90) {
      pauVar9 = local_a8[0];
    }
  } while (((local_98 != uVar5) ||
           ((ppuVar2 = ppuVar11, local_98 != 0 &&
            (uVar6 = FUN_180003970(pauVar9,pauVar8,local_98), (int)uVar6 != 0)))) &&
          (ppuVar11 = ppuVar11 + 6, ppuVar2 = DAT_1800514a8,
          ppuVar11 != (undefined **)L"3.1.36.205322"));
  DAT_1800514a8 = ppuVar2;
  if (DAT_1800514a8 != (undefined **)0x0) {
    plVar12 = (longlong *)((longlong)&param_1->unused + (longlong)DAT_1800514a8[4]);
    local_b8 = (undefined1 (*) [32])0x4c89481024548948;
    local_b0 = 0x1f90b85756550824;
    if ((*plVar12 == 0x4c89481024548948) && (plVar12[1] == 0x1f90b85756550824)) {
      uVar6 = FUN_180023e40(plVar12,FUN_18000c710,&DAT_1800514a0);
      if (((int)uVar6 == 0) && (iVar3 = FUN_1800240d0((longlong)plVar12), iVar3 == 0)) {
        cVar14 = '\x01';
      }
      else {
        cVar14 = '\0';
      }
      puVar7 = (uint *)FUN_180004ae0();
      FUN_1800048f0(puVar7,cVar14);
      pwVar13 = L"actual_native_hook_failed";
      if (cVar14 != '\0') {
        pwVar13 = L"actual_native_hook_ready";
      }
      local_b0 = FUN_18002cb80((undefined1 (*) [32])pwVar13);
      local_b8 = (undefined1 (*) [32])pwVar13;
      FUN_1800225c0((LPSTR ******)&local_b8,0);
      if (cVar14 != '\0') {
        pauVar8 = (undefined1 (*) [32])*DAT_1800514a8;
        local_88 = (LPVOID)0x0;
        uStack_80 = 0;
        local_78 = 0;
        uStack_70 = 0;
        uVar5 = FUN_18002cb80(pauVar8);
        FUN_180001c40(&local_88,(undefined8 *)pauVar8,uVar5);
        pauVar8 = (undefined1 (*) [32])
                  FUN_180001a30((undefined8 *)&local_48,(undefined1 (*) [32])L"native_profile_",
                                (undefined1 (*) [32])&local_88);
        local_b8 = pauVar8;
        if (7 < *(ulonglong *)((longlong)*pauVar8 + 0x18)) {
          local_b8 = *(undefined1 (**) [32])*pauVar8;
        }
        local_b0 = *(ulonglong *)((longlong)*pauVar8 + 0x10);
        FUN_1800225c0((LPSTR ******)&local_b8,0);
        if (7 < uStack_30) {
          pvVar1 = (LPVOID)CONCAT62(uStack_46,local_48);
          pvVar10 = pvVar1;
          if ((0xfff < uStack_30 * 2 + 2) &&
             (pvVar10 = *(LPVOID *)((longlong)pvVar1 + -8),
             0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)pvVar10)))) {
                    /* WARNING: Subroutine does not return */
            _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
          }
          thunk_FUN_180030590(pvVar10);
        }
        local_38 = 0;
        uStack_30 = 7;
        local_48 = 0;
        if (7 < uStack_70) {
          pvVar10 = local_88;
          if ((0xfff < uStack_70 * 2 + 2) &&
             (pvVar10 = *(LPVOID *)((longlong)local_88 + -8),
             0x1f < (ulonglong)((longlong)local_88 + (-8 - (longlong)pvVar10)))) {
                    /* WARNING: Subroutine does not return */
            _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
          }
          thunk_FUN_180030590(pvVar10);
        }
      }
      goto LAB_18000eba3;
    }
  }
  cVar14 = '\0';
LAB_18000eba3:
  if (7 < local_90) {
    pauVar8 = local_a8[0];
    if ((0xfff < local_90 * 2 + 2) &&
       (pauVar8 = *(undefined1 (**) [32])(local_a8[0][-1] + 0x18),
       0x1f < (ulonglong)((longlong)local_a8[0] + (-8 - (longlong)pauVar8)))) {
                    /* WARNING: Subroutine does not return */
      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
    }
    thunk_FUN_180030590(pauVar8);
  }
  return cVar14;
}
