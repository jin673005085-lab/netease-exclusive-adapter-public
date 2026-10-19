/* Ghidra pseudocode; NOT original or compilable C++. Evidence: ev_01ae598dea2ae2231b034c48ec98d714c2ec30eacdad360630fe9e9c9b00c5cb */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_180004b60(longlong param_1)

{
  undefined1 uVar1;
  UINT UVar2;
  LPCWSTR lpFileName;
  undefined4 extraout_var;
  undefined8 uVar3;
  LPVOID pvVar4;
  undefined1 auStackY_68 [32];
  LPVOID local_38 [3];
  ulonglong local_20;
  ulonglong local_18;

  local_18 = DAT_180050580 ^ (ulonglong)auStackY_68;
  lpFileName = (LPCWSTR)FUN_180021580((ulonglong *)local_38);
  if (7 < *(ulonglong *)(lpFileName + 0xc)) {
    lpFileName = *(LPCWSTR *)lpFileName;
  }
  UVar2 = GetPrivateProfileIntW(L"exclusive",L"enabled",0,lpFileName);
  LOCK();
  uVar1 = *(undefined1 *)(param_1 + 0x50);
  *(undefined1 *)(param_1 + 0x50) = UVar2 == 1;
  uVar3 = CONCAT71((int7)(CONCAT44(extraout_var,UVar2) >> 8),uVar1);
  UNLOCK();
  if (7 < local_20) {
    pvVar4 = local_38[0];
    if ((0xfff < local_20 * 2 + 2) &&
       (pvVar4 = *(LPVOID *)((longlong)local_38[0] + -8),
       0x1f < (ulonglong)((longlong)local_38[0] + (-8 - (longlong)pvVar4)))) {
                    /* WARNING: Subroutine does not return */
      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
    }
    uVar3 = thunk_FUN_180030590(pvVar4);
  }
  return uVar3;
}
