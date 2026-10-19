/* Ghidra pseudocode; NOT original or compilable C++. Evidence: ev_8e1e5263b0e9e8c64ea3255ca7388905c20f3d018c1f407cf2cd5253af5b5faf */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FUN_18001e010(HMODULE param_1,HMODULE param_2)

{
  bool bVar1;
  DWORD DVar2;
  LPWSTR pWVar3;
  undefined1 (*pauVar4) [32];
  ulonglong uVar5;
  undefined8 uVar6;
  FARPROC pFVar7;
  HRSRC hResInfo;
  HGLOBAL hResData;
  longlong *plVar8;
  FARPROC pFVar9;
  FARPROC pFVar10;
  ulonglong uVar11;
  LPSTR *****ppppppCVar12;
  LPVOID pvVar13;
  undefined **ppuVar14;
  undefined1 (*pauVar15) [32];
  undefined1 auStackY_a8 [32];
  LPSTR *****local_78;
  ulonglong local_70;
  undefined8 local_68;
  ulonglong uStack_60;
  LPVOID local_58 [3];
  ulonglong local_40;
  ulonglong local_38;

  local_38 = DAT_180050580 ^ (ulonglong)auStackY_a8;
  pWVar3 = FUN_180023480((LPWSTR)local_58,param_1);
  pauVar4 = (undefined1 (*) [32])FUN_180021920(&local_78,pWVar3);
  pauVar15 = pauVar4;
  if (7 < *(ulonglong *)((longlong)*pauVar4 + 0x18)) {
    pauVar15 = *(undefined1 (**) [32])*pauVar4;
  }
  uVar11 = *(ulonglong *)((longlong)*pauVar4 + 0x10);
  ppuVar14 = &PTR_u_3_1_36_205322_18003aa10;
  while( true ) {
    pauVar4 = (undefined1 (*) [32])ppuVar14[3];
    uVar5 = FUN_18002cb80(pauVar4);
    if ((uVar11 == uVar5) &&
       ((uVar11 == 0 || (uVar6 = FUN_180003970(pauVar15,pauVar4,uVar11), (int)uVar6 == 0)))) break;
    ppuVar14 = ppuVar14 + 6;
    if (ppuVar14 == (undefined **)L"3.1.36.205322") {
      bVar1 = true;
LAB_18001e0bc:
      if (7 < uStack_60) {
        ppppppCVar12 = local_78;
        if ((0xfff < uStack_60 * 2 + 2) &&
           (ppppppCVar12 = (LPSTR *****)local_78[-1],
           0x1f < (ulonglong)((longlong)local_78 + (-8 - (longlong)ppppppCVar12)))) {
                    /* WARNING: Subroutine does not return */
          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
        }
        thunk_FUN_180030590(ppppppCVar12);
      }
      local_68 = 0;
      uStack_60 = 7;
      local_78 = (LPSTR *****)((ulonglong)local_78 & 0xffffffffffff0000);
      if (7 < local_40) {
        pvVar13 = local_58[0];
        if ((0xfff < local_40 * 2 + 2) &&
           (pvVar13 = *(LPVOID *)((longlong)local_58[0] + -8),
           0x1f < (ulonglong)((longlong)local_58[0] + (-8 - (longlong)pvVar13)))) {
                    /* WARNING: Subroutine does not return */
          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
        }
        thunk_FUN_180030590(pvVar13);
      }
      if (bVar1) {
        local_78 = (LPSTR *****)0x18003cef0;
        local_70 = 0xf;
        pFVar7 = (FARPROC)FUN_1800225c0(&local_78,0x80004001);
      }
      else {
        hResInfo = FindResourceW(param_2,(LPCWSTR)0x65,(LPCWSTR)0xa);
        pFVar7 = (FARPROC)0x0;
        if (hResInfo != (HRSRC)0x0) {
          hResData = LoadResource(param_2,hResInfo);
          local_78 = LockResource(hResData);
          pFVar7 = (FARPROC)0x0;
          if (local_78 != (LPSTR *****)0x0) {
            DVar2 = SizeofResource(param_2,hResInfo);
            local_70 = (ulonglong)DVar2;
            plVar8 = FUN_180023570(local_58,&local_78);
            FUN_1800044f0(&DAT_1800501f0,plVar8);
            if (7 < local_40) {
              pvVar13 = local_58[0];
              if ((0xfff < local_40 * 2 + 2) &&
                 (pvVar13 = *(LPVOID *)((longlong)local_58[0] + -8),
                 0x1f < (ulonglong)((longlong)local_58[0] + (-8 - (longlong)pvVar13)))) {
                    /* WARNING: Subroutine does not return */
                _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
              }
              thunk_FUN_180030590(pvVar13);
            }
            DAT_180051610 = GetProcAddress(param_1,"cef_string_userfree_utf16_free");
            pFVar9 = GetProcAddress(param_1,"cef_browser_host_create_browser");
            pFVar10 = GetProcAddress(param_1,"cef_browser_host_create_browser_sync");
            pFVar7 = pFVar10;
            if ((((DAT_180051610 != (FARPROC)0x0) && (pFVar9 != (FARPROC)0x0)) &&
                (pFVar10 != (FARPROC)0x0)) &&
               (pFVar7 = (FARPROC)FUN_180023e40((undefined8 *)pFVar9,FUN_18001d9c0,&DAT_180051618),
               (int)pFVar7 == 0)) {
              uVar6 = FUN_180023e40((undefined8 *)pFVar10,FUN_18001da60,&DAT_1800517a0);
              if ((int)uVar6 == 0) {
                FUN_180024180((longlong)pFVar9);
                FUN_180024180((longlong)pFVar10);
                uVar11 = FUN_180023c90();
                if ((int)uVar11 == 0) {
                  local_78 = (LPSTR *****)0x18003cf78;
                  local_70 = 0xf;
                  uVar6 = FUN_1800225c0(&local_78,0);
                  return CONCAT71((int7)((ulonglong)uVar6 >> 8),1);
                }
                FUN_1800240c0((longlong)pFVar9);
                FUN_1800240c0((longlong)pFVar10);
                FUN_180024190((longlong)pFVar9);
                pFVar9 = pFVar10;
              }
              pFVar7 = (FARPROC)FUN_180024190((longlong)pFVar9);
            }
          }
        }
      }
      return (ulonglong)pFVar7 & 0xffffffffffffff00;
    }
  }
  bVar1 = false;
  goto LAB_18001e0bc;
}
