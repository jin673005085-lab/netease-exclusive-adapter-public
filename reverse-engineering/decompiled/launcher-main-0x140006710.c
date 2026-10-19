/* Ghidra pseudocode; NOT original or compilable C++. Evidence: ev_85894382d4dbf4e0b00fac87a99683ca683fcfd9906b6e8f384dc202f737ce0a */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Type propagation algorithm not settling */

undefined8 FUN_140006710(int param_1,longlong param_2)

{
  LPVOID pvVar1;
  HANDLE hObject;
  HANDLE hThread;
  DWORD DVar2;
  BOOL BVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  LPWSTR pWVar6;
  undefined1 (*pauVar7) [32];
  uint *puVar8;
  longlong *plVar9;
  LPCWSTR ******pppppppWVar10;
  char cVar11;
  undefined1 (*pauVar12) [32];
  LPVOID pvVar13;
  LPCWSTR ******lpApplicationName;
  LPWSTR ******pppppppWVar14;
  undefined8 *******pppppppuVar15;
  undefined **ppuVar16;
  char cVar17;
  bool bVar18;
  undefined1 auStackY_378 [32];
  byte local_328;
  _PROCESS_INFORMATION local_318;
  HANDLE local_300;
  longlong local_2f0 [3];
  longlong local_2d8 [3];
  longlong local_2c0 [3];
  longlong local_2a8 [3];
  longlong local_290 [3];
  _STARTUPINFOW local_278;
  LPCWSTR ******local_208;
  longlong lStack_200;
  ulonglong local_1f8;
  ulonglong uStack_1f0;
  WCHAR local_1e8;
  undefined6 uStack_1e6;
  undefined8 local_1d8;
  ulonglong uStack_1d0;
  LPVOID local_1c8;
  undefined8 uStack_1c0;
  undefined8 local_1b8;
  ulonglong uStack_1b0;
  LPVOID local_1a8;
  undefined8 uStack_1a0;
  undefined8 local_198;
  ulonglong uStack_190;
  WCHAR local_188;
  undefined6 uStack_186;
  undefined8 local_178;
  ulonglong uStack_170;
  LPWSTR ******local_168;
  LPCWSTR *****ppppppWStack_160;
  LPCWSTR *****local_158;
  LPCWSTR *****ppppppWStack_150;
  LPCWSTR ******local_148 [3];
  ulonglong local_130;
  undefined8 *******local_128 [2];
  ulonglong local_118;
  ulonglong local_110;
  LPCWSTR ******local_108 [3];
  ulonglong local_f0;
  undefined1 (*local_e8 [2]) [32];
  ulonglong local_d8;
  ulonglong local_d0;
  undefined1 (*local_c8 [2]) [32];
  ulonglong local_b8;
  ulonglong local_b0;
  undefined1 (*local_a8 [2]) [32];
  ulonglong local_98;
  ulonglong local_90;
  longlong local_88 [4];
  longlong local_68 [4];
  longlong local_48 [4];
  ulonglong local_28;

  local_28 = DAT_14003d040 ^ (ulonglong)auStackY_378;
  if (param_1 == 3) {
    pauVar7 = *(undefined1 (**) [32])(param_2 + 8);
    uVar4 = FUN_140013bb0(pauVar7);
    if ((uVar4 == 8) &&
       (uVar5 = FUN_1400075d0(pauVar7,(undefined1 (*) [32])L"--launch",8), (int)uVar5 == 0)) {
      uVar4 = FUN_140013bb0(*(undefined1 (**) [32])(param_2 + 0x10));
      local_208 = (LPCWSTR ******)0x0;
      lStack_200 = 0;
      local_1f8 = 0;
      uStack_1f0 = 0;
      FUN_140001da0(&local_208,*(undefined8 **)(param_2 + 0x10),uVar4);
      pWVar6 = FUN_140004fe0(&local_1e8,(LPCWSTR)&local_208);
      FUN_140005860((uint *)pWVar6,local_148);
      FUN_140004f00((longlong *)&local_1e8);
      if (7 < uStack_1f0) {
        pppppppWVar10 = local_208;
        if ((0xfff < uStack_1f0 * 2 + 2) &&
           (pppppppWVar10 = (LPCWSTR ******)local_208[-1],
           0x1f < (ulonglong)((longlong)local_208 + (-8 - (longlong)pppppppWVar10)))) {
                    /* WARNING: Subroutine does not return */
          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
        }
        thunk_FUN_14001aec0(pppppppWVar10);
      }
      local_1f8 = 0;
      uStack_1f0 = 7;
      local_208 = (LPCWSTR ******)((ulonglong)local_208 & 0xffffffffffff0000);
      FUN_1400063f0((uint *)local_148,local_108);
      FUN_1400028c0(&local_1c8,local_148);
      FUN_140007790(local_a8,(LPCWSTR)&local_1c8);
      if (7 < uStack_1b0) {
        pvVar13 = local_1c8;
        if ((0xfff < uStack_1b0 * 2 + 2) &&
           (pvVar13 = *(LPVOID *)((longlong)local_1c8 + -8),
           0x1f < (ulonglong)((longlong)local_1c8 + (-8 - (longlong)pvVar13)))) {
                    /* WARNING: Subroutine does not return */
          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
        }
        thunk_FUN_14001aec0(pvVar13);
      }
      local_1b8 = 0;
      uStack_1b0 = 7;
      local_1c8 = (LPVOID)((ulonglong)local_1c8 & 0xffffffffffff0000);
      local_1a8 = (LPVOID)0x0;
      uStack_1a0 = 0;
      local_198 = 0;
      uStack_190 = 0;
      FUN_140001da0(&local_1a8,(undefined8 *)L"cloudmusic.dll",0xe);
      pauVar7 = FUN_140003510((undefined1 (*) [32])local_88,(uint *)local_108,
                              (undefined1 (*) [32])&local_1a8);
      FUN_1400028c0((undefined8 *)&local_188,(undefined8 *)pauVar7);
      FUN_140007790(local_c8,&local_188);
      if (7 < uStack_170) {
        pvVar1 = (LPVOID)CONCAT62(uStack_186,local_188);
        pvVar13 = pvVar1;
        if ((0xfff < uStack_170 * 2 + 2) &&
           (pvVar13 = *(LPVOID *)((longlong)pvVar1 + -8),
           0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)pvVar13)))) {
                    /* WARNING: Subroutine does not return */
          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
        }
        thunk_FUN_14001aec0(pvVar13);
      }
      local_178 = 0;
      uStack_170 = 7;
      local_188 = L'\0';
      FUN_140004f00(local_88);
      FUN_140004f00((longlong *)&local_1a8);
      local_208 = (LPCWSTR ******)0x0;
      lStack_200 = 0;
      local_1f8 = 0;
      uStack_1f0 = 0;
      FUN_140001da0(&local_208,(undefined8 *)L"libcef.dll",10);
      pauVar7 = FUN_140003510((undefined1 (*) [32])local_68,(uint *)local_108,
                              (undefined1 (*) [32])&local_208);
      FUN_1400028c0((undefined8 *)&local_1e8,(undefined8 *)pauVar7);
      FUN_140007790(local_e8,&local_1e8);
      if (7 < uStack_1d0) {
        pvVar1 = (LPVOID)CONCAT62(uStack_1e6,local_1e8);
        pvVar13 = pvVar1;
        if ((0xfff < uStack_1d0 * 2 + 2) &&
           (pvVar13 = *(LPVOID *)((longlong)pvVar1 + -8),
           0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)pvVar13)))) {
                    /* WARNING: Subroutine does not return */
          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
        }
        thunk_FUN_14001aec0(pvVar13);
      }
      local_1d8 = 0;
      uStack_1d0 = 7;
      local_1e8 = L'\0';
      FUN_140004f00(local_68);
      if (7 < uStack_1f0) {
        pppppppWVar10 = local_208;
        if ((0xfff < uStack_1f0 * 2 + 2) &&
           (pppppppWVar10 = (LPCWSTR ******)local_208[-1],
           0x1f < (ulonglong)((longlong)local_208 + (-8 - (longlong)pppppppWVar10)))) {
                    /* WARNING: Subroutine does not return */
          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
        }
        thunk_FUN_14001aec0(pppppppWVar10);
      }
      local_1f8 = 0;
      uStack_1f0 = 7;
      local_208 = (LPCWSTR ******)((ulonglong)local_208 & 0xffffffffffff0000);
      ppuVar16 = &PTR_u_98874023cab8d13f4e7e3fbc74fbc301_140029980;
      do {
        pauVar7 = (undefined1 (*) [32])ppuVar16[-1];
        uVar4 = FUN_140013bb0(pauVar7);
        pauVar12 = (undefined1 (*) [32])local_a8;
        if (7 < local_90) {
          pauVar12 = local_a8[0];
        }
        if ((local_98 == uVar4) &&
           ((local_98 == 0 || (uVar5 = FUN_1400075d0(pauVar12,pauVar7,local_98), (int)uVar5 == 0))))
        {
          pauVar7 = (undefined1 (*) [32])*ppuVar16;
          uVar4 = FUN_140013bb0(pauVar7);
          pauVar12 = (undefined1 (*) [32])local_c8;
          if (7 < local_b0) {
            pauVar12 = local_c8[0];
          }
          if ((local_b8 == uVar4) &&
             ((local_b8 == 0 || (uVar5 = FUN_1400075d0(pauVar12,pauVar7,local_b8), (int)uVar5 == 0))
             )) {
            pauVar7 = (undefined1 (*) [32])ppuVar16[1];
            uVar4 = FUN_140013bb0(pauVar7);
            pauVar12 = (undefined1 (*) [32])local_e8;
            if (7 < local_d0) {
              pauVar12 = local_e8[0];
            }
            if ((local_d8 == uVar4) &&
               ((local_d8 == 0 ||
                (uVar5 = FUN_1400075d0(pauVar12,pauVar7,local_d8), (int)uVar5 == 0)))) {
              FUN_1400028c0((undefined8 *)&local_188,local_148);
              uVar5 = FUN_140003910(&local_188);
              if (7 < uStack_170) {
                pvVar1 = (LPVOID)CONCAT62(uStack_186,local_188);
                pvVar13 = pvVar1;
                if ((0xfff < uStack_170 * 2 + 2) &&
                   (pvVar13 = *(LPVOID *)((longlong)pvVar1 + -8),
                   0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)pvVar13)))) {
                    /* WARNING: Subroutine does not return */
                  _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
                }
                thunk_FUN_14001aec0(pvVar13);
              }
              if ((char)uVar5 != '\0') {
                FUN_1400030b0(local_2f0,0x14002a2a0);
                    /* WARNING: Subroutine does not return */
                FUN_14000eb10(local_2f0,&DAT_14003b2c8);
              }
              local_1c8 = (LPVOID)0x0;
              uStack_1c0 = 0;
              local_1b8 = 0;
              uStack_1b0 = 0;
              FUN_140001da0(&local_1c8,(undefined8 *)L"nc-exclusive-hook.dll",0x15);
              pWVar6 = FUN_140007df0(&local_188,(HMODULE)0x0);
              local_1a8 = *(LPVOID *)pWVar6;
              uStack_1a0 = *(undefined8 *)(pWVar6 + 4);
              local_198 = *(undefined8 *)(pWVar6 + 8);
              uStack_190 = *(ulonglong *)(pWVar6 + 0xc);
              *pWVar6 = L'\0';
              pWVar6[8] = L'\0';
              pWVar6[9] = L'\0';
              pWVar6[10] = L'\0';
              pWVar6[0xb] = L'\0';
              pWVar6[0xc] = L'\a';
              pWVar6[0xd] = L'\0';
              pWVar6[0xe] = L'\0';
              pWVar6[0xf] = L'\0';
              puVar8 = (uint *)FUN_1400063f0((uint *)&local_1a8,local_48);
              pauVar7 = FUN_140003510((undefined1 (*) [32])local_88,puVar8,
                                      (undefined1 (*) [32])&local_1c8);
              FUN_1400028c0(local_128,(undefined8 *)pauVar7);
              FUN_140004f00(local_88);
              FUN_140004f00(local_48);
              if (7 < uStack_190) {
                pvVar13 = local_1a8;
                if ((0xfff < uStack_190 * 2 + 2) &&
                   (pvVar13 = *(LPVOID *)((longlong)local_1a8 + -8),
                   0x1f < (ulonglong)((longlong)local_1a8 + (-8 - (longlong)pvVar13)))) {
                    /* WARNING: Subroutine does not return */
                  _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
                }
                thunk_FUN_14001aec0(pvVar13);
              }
              local_198 = 0;
              uStack_190 = 7;
              local_1a8 = (LPVOID)((ulonglong)local_1a8 & 0xffffffffffff0000);
              if (7 < uStack_170) {
                pvVar1 = (LPVOID)CONCAT62(uStack_186,local_188);
                pvVar13 = pvVar1;
                if ((0xfff < uStack_170 * 2 + 2) &&
                   (pvVar13 = *(LPVOID *)((longlong)pvVar1 + -8),
                   0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)pvVar13)))) {
                    /* WARNING: Subroutine does not return */
                  _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
                }
                thunk_FUN_14001aec0(pvVar13);
              }
              local_178 = 0;
              uStack_170 = 7;
              local_188 = L'\0';
              if (7 < uStack_1b0) {
                pvVar13 = local_1c8;
                if ((0xfff < uStack_1b0 * 2 + 2) &&
                   (pvVar13 = *(LPVOID *)((longlong)local_1c8 + -8),
                   0x1f < (ulonglong)((longlong)local_1c8 + (-8 - (longlong)pvVar13)))) {
                    /* WARNING: Subroutine does not return */
                  _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
                }
                thunk_FUN_14001aec0(pvVar13);
              }
              local_1b8 = 0;
              uStack_1b0 = 7;
              local_1c8 = (LPVOID)((ulonglong)local_1c8 & 0xffffffffffff0000);
              pppppppuVar15 = local_128;
              if (7 < local_110) {
                pppppppuVar15 = local_128[0];
              }
              local_208 = (LPCWSTR ******)0x0;
              lStack_200 = 0;
              local_1f8 = 0;
              uStack_1f0 = 0;
              FUN_140001da0(&local_208,pppppppuVar15,local_118);
              pppppppWVar10 = (LPCWSTR ******)&local_208;
              if (7 < uStack_1f0) {
                pppppppWVar10 = local_208;
              }
              DVar2 = FUN_1400083f8((LPCWSTR)pppppppWVar10,(ulonglong *)&local_1e8,3,0xffffffff);
              cVar11 = '\0';
              if (DVar2 == 0) {
                if (((uint)local_1d8 >> 10 & 1) != 0) {
                  if (local_1d8._4_4_ == -0x5ffffff4) {
                    cVar11 = '\x04';
                    cVar17 = '\x04';
                    goto LAB_140006f80;
                  }
                  if (local_1d8._4_4_ == -0x5ffffffd) {
                    cVar11 = '\n';
                    cVar17 = '\n';
                    goto LAB_140006f80;
                  }
                }
                cVar11 = ((local_1d8 & 0x10) != 0) + '\x02';
                cVar17 = (((uint)local_1d8 >> 4 & 1) != 0) + '\x02';
                goto LAB_140006f80;
              }
              if (DVar2 < 0x41) {
                if (((DVar2 != 0x40) && (DVar2 != 2)) && (DVar2 != 3)) {
                  bVar18 = DVar2 == 0x35;
LAB_140006f74:
                  cVar17 = cVar11;
                  if (!bVar18) goto LAB_140006f80;
                }
              }
              else if (DVar2 != 0x7b) {
                bVar18 = DVar2 == 0x10b;
                goto LAB_140006f74;
              }
              cVar11 = '\x01';
              cVar17 = cVar11;
LAB_140006f80:
              if ((DVar2 == 0) || (cVar11 == '\x01')) {
                FUN_140004f00((longlong *)&local_208);
                if (cVar17 == '\x02') {
                  local_278.cb = 0x68;
                  local_278.lpReserved = (LPWSTR)0x0;
                  local_278.lpDesktop = (LPWSTR)0x0;
                  local_278.lpTitle = (LPWSTR)0x0;
                  local_278.dwX = 0;
                  local_278.dwY = 0;
                  local_278.dwXSize = 0;
                  local_278.dwYSize = 0;
                  local_278.dwXCountChars = 0;
                  local_278.dwYCountChars = 0;
                  local_278.dwFillAttribute = 0;
                  local_278.dwFlags = 0;
                  local_278.wShowWindow = 0;
                  local_278.cbReserved2 = 0;
                  local_278._68_4_ = 0;
                  local_278.lpReserved2 = (LPBYTE)0x0;
                  local_278.hStdInput = (HANDLE)0x0;
                  local_278.hStdOutput = (HANDLE)0x0;
                  local_278.hStdError = (HANDLE)0x0;
                  local_318.hProcess = (HANDLE)0x0;
                  local_318.hThread = (HANDLE)0x0;
                  local_318.dwProcessId = 0;
                  local_318.dwThreadId = 0;
                  FUN_1400028c0((undefined8 *)&local_1e8,local_148);
                  plVar9 = FUN_1400056c0((undefined8 *)&local_1e8,0,(undefined8 *)&DAT_14002a33c,1);
                  local_208 = (LPCWSTR ******)*plVar9;
                  lStack_200 = plVar9[1];
                  uVar4 = plVar9[2];
                  uStack_1f0 = plVar9[3];
                  *(undefined2 *)plVar9 = 0;
                  plVar9[2] = 0;
                  plVar9[3] = 7;
                  if (uStack_1f0 == uVar4) {
                    local_1f8 = uVar4;
                    pppppppWVar10 =
                         (LPCWSTR ******)
                         FUN_140002210(&local_208,1,(ulonglong)local_328,
                                       (undefined8 *)&DAT_14002a33c,1);
                  }
                  else {
                    local_1f8 = uVar4 + 1;
                    pppppppWVar10 = (LPCWSTR ******)&local_208;
                    if (7 < uStack_1f0) {
                      pppppppWVar10 = local_208;
                    }
                    *(undefined4 *)((longlong)pppppppWVar10 + uVar4 * 2) = 0x22;
                    pppppppWVar10 = (LPCWSTR ******)&local_208;
                  }
                  local_168 = (LPWSTR ******)0x0;
                  ppppppWStack_160 = (LPCWSTR *****)0x0;
                  local_158 = (LPCWSTR *****)0x0;
                  ppppppWStack_150 = (LPCWSTR *****)0x0;
                  local_168 = (LPWSTR ******)*pppppppWVar10;
                  ppppppWStack_160 = pppppppWVar10[1];
                  local_158 = pppppppWVar10[2];
                  ppppppWStack_150 = pppppppWVar10[3];
                  *(undefined2 *)pppppppWVar10 = 0;
                  pppppppWVar10[2] = (LPCWSTR *****)0x0;
                  pppppppWVar10[3] = (LPCWSTR *****)0x7;
                  if (7 < uStack_1f0) {
                    pppppppWVar10 = local_208;
                    if ((0xfff < uStack_1f0 * 2 + 2) &&
                       (pppppppWVar10 = (LPCWSTR ******)local_208[-1],
                       0x1f < (ulonglong)((longlong)local_208 + (-8 - (longlong)pppppppWVar10)))) {
                    /* WARNING: Subroutine does not return */
                      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
                    }
                    thunk_FUN_14001aec0(pppppppWVar10);
                  }
                  local_1f8 = 0;
                  uStack_1f0 = 7;
                  local_208 = (LPCWSTR ******)((ulonglong)local_208 & 0xffffffffffff0000);
                  if (7 < uStack_1d0) {
                    pvVar1 = (LPVOID)CONCAT62(uStack_1e6,local_1e8);
                    pvVar13 = pvVar1;
                    if ((0xfff < uStack_1d0 * 2 + 2) &&
                       (pvVar13 = *(LPVOID *)((longlong)pvVar1 + -8),
                       0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)pvVar13)))) {
                    /* WARNING: Subroutine does not return */
                      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
                    }
                    thunk_FUN_14001aec0(pvVar13);
                  }
                  local_1d8 = 0;
                  uStack_1d0 = 7;
                  local_1e8 = L'\0';
                  pppppppWVar10 = (LPCWSTR ******)local_108;
                  if (7 < local_f0) {
                    pppppppWVar10 = local_108[0];
                  }
                  pppppppWVar14 = (LPWSTR ******)&local_168;
                  if ((LPCWSTR *****)0x7 < ppppppWStack_150) {
                    pppppppWVar14 = local_168;
                  }
                  lpApplicationName = (LPCWSTR ******)local_148;
                  if (7 < local_130) {
                    lpApplicationName = local_148[0];
                  }
                  BVar3 = CreateProcessW((LPCWSTR)lpApplicationName,(LPWSTR)pppppppWVar14,
                                         (LPSECURITY_ATTRIBUTES)0x0,(LPSECURITY_ATTRIBUTES)0x0,0,4,
                                         (LPVOID)0x0,(LPCWSTR)pppppppWVar10,&local_278,&local_318);
                  hThread = local_318.hThread;
                  hObject = local_318.hProcess;
                  if (BVar3 != 0) {
                    local_300 = local_318.hThread;
                    FUN_140003c80(local_318.hProcess,local_318.dwProcessId,(LPCWSTR)local_128);
                    DVar2 = ResumeThread(hThread);
                    if (DVar2 == 0xffffffff) {
                      FUN_1400030b0(local_2a8,0x14002a358);
                    /* WARNING: Subroutine does not return */
                      FUN_14000eb10(local_2a8,&DAT_14003b2c8);
                    }
                    FUN_140001910(&DAT_14003e590,(undefined1 (*) [32])&DAT_14002a370);
                    if ((longlong)hThread - 1U < 0xfffffffffffffffe) {
                      CloseHandle(hThread);
                    }
                    if ((longlong)hObject - 1U < 0xfffffffffffffffe) {
                      CloseHandle(hObject);
                    }
                    if ((LPCWSTR *****)0x7 < ppppppWStack_150) {
                      pppppppWVar14 = local_168;
                      if ((0xfff < (longlong)ppppppWStack_150 * 2 + 2U) &&
                         (pppppppWVar14 = (LPWSTR ******)local_168[-1],
                         0x1f < (ulonglong)((longlong)local_168 + (-8 - (longlong)pppppppWVar14))))
                      {
                    /* WARNING: Subroutine does not return */
                        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
                      }
                      thunk_FUN_14001aec0(pppppppWVar14);
                    }
                    local_158 = (LPCWSTR *****)0x0;
                    ppppppWStack_150 = (LPCWSTR *****)0x7;
                    local_168 = (LPWSTR ******)((ulonglong)local_168 & 0xffffffffffff0000);
                    FUN_140004f00((longlong *)local_128);
                    FUN_140004f00((longlong *)local_e8);
                    FUN_140004f00((longlong *)local_c8);
                    FUN_140004f00((longlong *)local_a8);
                    FUN_140004f00((longlong *)local_108);
                    FUN_140004f00((longlong *)local_148);
                    return 0;
                  }
                  FUN_1400030b0(local_2c0,0x14002a340);
                    /* WARNING: Subroutine does not return */
                  FUN_14000eb10(local_2c0,&DAT_14003b2c8);
                }
              }
              else {
                FUN_140004e10("status",DVar2,&local_208);
              }
              FUN_1400030b0(local_2d8,0x14002a328);
                    /* WARNING: Subroutine does not return */
              FUN_14000eb10(local_2d8,&DAT_14003b2c8);
            }
          }
        }
        bVar18 = ppuVar16 == &PTR_u_d1b6d5da6143d414f6cdc54c5ca15661_1400299b0;
        ppuVar16 = ppuVar16 + 6;
        if (bVar18) {
          FUN_1400030b0(local_290,0x14002a260);
                    /* WARNING: Subroutine does not return */
          FUN_14000eb10(local_290,&DAT_14003b2c8);
        }
      } while( true );
    }
  }
  FUN_140001910(&DAT_14003e6c0,(undefined1 (*) [32])&DAT_14002a130);
  return 2;
}
