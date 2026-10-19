/* Ghidra pseudocode; NOT original or compilable C++. Evidence: ev_a48e1b826266dae345d5dcf4c038b7e14937de6efbbe7c0fd5432800c443dbf7 */

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_18000cd90(ulonglong param_1)

{
  longlong *plVar1;
  ulonglong uVar2;
  longlong lVar3;
  longlong *plVar4;
  bool bVar5;
  int iVar6;
  int iVar7;
  uint *puVar8;
  longlong *plVar9;
  LPVOID pvVar10;
  longlong *plVar11;
  undefined1 auStackY_148 [32];
  LPVOID local_118;
  undefined8 uStack_110;
  undefined8 local_108;
  ulonglong uStack_100;
  undefined4 local_f8;
  undefined2 local_f4;
  undefined8 local_f2;
  undefined8 uStack_ea;
  undefined8 local_e2;
  undefined8 uStack_da;
  undefined8 local_d2;
  undefined8 local_c8;
  ulonglong uStack_c0;
  undefined8 local_b8;
  undefined4 local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  ulonglong local_38;

  local_38 = DAT_180050580 ^ (ulonglong)auStackY_148;
  uStack_110 = 0;
  local_108 = 0;
  uStack_100 = 7;
  local_118 = (LPVOID)0x0;
  local_f8 = 0;
  local_f4 = 0;
  local_f2 = 0;
  uStack_ea = 0;
  local_e2 = 0;
  uStack_da = 0;
  local_d2 = 0;
  local_c8 = 0;
  uStack_c0 = 0;
  local_b8 = 0;
  local_b0 = 0;
  local_a8 = 0;
  local_a0 = 0;
  local_98 = 0;
  local_90 = 0;
  local_88 = 0;
  local_80 = 0;
  local_78 = 0;
  local_70 = 0;
  local_68 = 0;
  local_60 = 0;
  local_58 = 0;
  local_50 = 0;
  local_48 = 0;
  bVar5 = FUN_18000a130(param_1,&local_118);
  iVar6 = (*DAT_180051470)(param_1);
  if ((iVar6 == 0) && (bVar5)) {
    iVar7 = FUN_180025e38((uint *)&DAT_1800500b0);
    plVar4 = DAT_1800514b8;
    if (iVar7 != 0) {
                    /* WARNING: Subroutine does not return */
      FUN_180026614(5);
    }
    if (DAT_1800500fc == 0x7fffffff) {
      DAT_1800500fc = 0x7ffffffe;
                    /* WARNING: Subroutine does not return */
      FUN_180026614(6);
    }
    plVar9 = (longlong *)
             ((((param_1 >> 0x30 & 0xff ^
                (((((param_1 >> 8 & 0xff ^ (param_1 & 0xff ^ 0xcbf29ce484222325) * 0x100000001b3) *
                    0x100000001b3 ^ param_1 >> 0x10 & 0xff) * 0x100000001b3 ^ param_1 >> 0x18 & 0xff
                  ) * 0x100000001b3 ^ param_1 >> 0x20 & 0xff) * 0x100000001b3 ^
                param_1 >> 0x28 & 0xff) * 0x100000001b3) * 0x100000001b3 ^ param_1 >> 0x38) *
               0x100000001b3 & _DAT_1800514e0) * 0x10 + DAT_1800514c8);
    plVar1 = (longlong *)plVar9[1];
    if (plVar1 == DAT_1800514b8) {
LAB_18000cf61:
      plVar11 = (longlong *)0x0;
    }
    else {
      uVar2 = plVar1[2];
      plVar11 = plVar1;
      while (param_1 != uVar2) {
        if (plVar11 == (longlong *)*plVar9) goto LAB_18000cf61;
        plVar11 = (longlong *)plVar11[1];
        uVar2 = plVar11[2];
      }
    }
    if (plVar11 != (longlong *)0x0) {
      if (plVar1 == plVar11) {
        if ((longlong *)*plVar9 == plVar11) {
          *plVar9 = (longlong)DAT_1800514b8;
          plVar9[1] = (longlong)plVar4;
        }
        else {
          plVar9[1] = plVar11[1];
        }
      }
      else if ((longlong *)*plVar9 == plVar11) {
        *plVar9 = *plVar11;
      }
      lVar3 = *plVar11;
      _DAT_1800514c0 = _DAT_1800514c0 + -1;
      *(longlong *)plVar11[1] = lVar3;
      *(longlong *)(lVar3 + 8) = plVar11[1];
      FUN_180002330(plVar11 + 3);
      thunk_FUN_180030590(plVar11);
    }
    plVar4 = DAT_1800514f8;
    if (uStack_c0 != 0) {
      plVar9 = (longlong *)
               ((((((((((uStack_c0 & 0xff ^ 0xcbf29ce484222325) * 0x100000001b3 ^
                       uStack_c0 >> 8 & 0xff) * 0x100000001b3 ^ uStack_c0 >> 0x10 & 0xff) *
                      0x100000001b3 ^ uStack_c0 >> 0x18 & 0xff) * 0x100000001b3 ^
                    uStack_c0 >> 0x20 & 0xff) * 0x100000001b3 ^ uStack_c0 >> 0x28 & 0xff) *
                   0x100000001b3 ^ uStack_c0 >> 0x30 & 0xff) * 0x100000001b3 ^ uStack_c0 >> 0x38) *
                 0x100000001b3 & _DAT_180051520) * 0x10 + DAT_180051508);
      plVar1 = (longlong *)plVar9[1];
      if (plVar1 == DAT_1800514f8) {
LAB_18000d067:
        plVar11 = (longlong *)0x0;
      }
      else {
        uVar2 = plVar1[2];
        plVar11 = plVar1;
        while (uStack_c0 != uVar2) {
          if (plVar11 == (longlong *)*plVar9) goto LAB_18000d067;
          plVar11 = (longlong *)plVar11[1];
          uVar2 = plVar11[2];
        }
      }
      if (plVar11 != (longlong *)0x0) {
        if (plVar1 == plVar11) {
          if ((longlong *)*plVar9 == plVar11) {
            *plVar9 = (longlong)DAT_1800514f8;
            plVar9[1] = (longlong)plVar4;
          }
          else {
            plVar9[1] = plVar11[1];
          }
        }
        else if ((longlong *)*plVar9 == plVar11) {
          *plVar9 = *plVar11;
        }
        lVar3 = *plVar11;
        _DAT_180051500 = _DAT_180051500 + -1;
        *(longlong *)plVar11[1] = lVar3;
        *(longlong *)(lVar3 + 8) = plVar11[1];
        FUN_18000f340(plVar11 + 7);
        thunk_FUN_180030590(plVar11);
      }
    }
    FUN_180025e40(0x1800500b0);
    if ((char)local_f8 != '\0') {
      puVar8 = (uint *)FUN_180004ae0();
      FUN_180004750(puVar8,param_1);
    }
  }
  if (7 < uStack_100) {
    pvVar10 = local_118;
    if ((0xfff < uStack_100 * 2 + 2) &&
       (pvVar10 = *(LPVOID *)((longlong)local_118 + -8),
       0x1f < (ulonglong)((longlong)local_118 + (-8 - (longlong)pvVar10)))) {
                    /* WARNING: Subroutine does not return */
      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
    }
    thunk_FUN_180030590(pvVar10);
  }
  return iVar6;
}
