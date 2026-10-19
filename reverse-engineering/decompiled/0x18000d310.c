/* Ghidra pseudocode; NOT original or compilable C++. Evidence: ev_146d15beb622e70f1f2d63c4ba7eb3b5209568393f493e395547042a4e9cd893 */

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint FUN_18000d310(ulonglong param_1,longlong *param_2,byte *param_3)

{
  longlong lVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  bool bVar5;
  uint uVar6;
  int iVar7;
  undefined8 uVar8;
  ulonglong uVar9;
  longlong *plVar10;
  uint *puVar11;
  LPVOID pvVar12;
  LPVOID pvVar13;
  uint uVar14;
  wchar_t *pwVar15;
  undefined2 uVar16;
  undefined1 auStackY_1d8 [32];
  undefined1 (*local_198) [32];
  ulonglong local_190;
  ulonglong local_188;
  ulonglong local_180;
  ulonglong local_178;
  undefined8 local_170;
  undefined4 local_168;
  undefined2 local_164;
  undefined2 local_162;
  undefined2 local_160;
  undefined1 local_15e;
  longlong local_158 [6];
  LPVOID local_128;
  undefined8 uStack_120;
  undefined8 local_118;
  ulonglong uStack_110;
  undefined4 local_108;
  undefined2 local_104;
  undefined8 local_102;
  undefined8 uStack_fa;
  undefined8 local_f2;
  undefined8 uStack_ea;
  undefined8 local_e2;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined4 local_c0;
  undefined8 local_b8;
  undefined8 local_b0;
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
  ulonglong local_48;

  local_48 = DAT_180050580 ^ (ulonglong)auStackY_1d8;
  local_188 = param_1;
  uVar6 = (*DAT_180051450)();
  uStack_120 = 0;
  local_118 = 0;
  uStack_110 = 7;
  local_128 = (LPVOID)0x0;
  local_108 = 0;
  local_104 = 0;
  local_102 = 0;
  uStack_fa = 0;
  local_f2 = 0;
  uStack_ea = 0;
  local_e2 = 0;
  local_d8 = 0;
  uStack_d0 = 0;
  local_c8 = 0;
  local_c0 = 0;
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
  bVar5 = FUN_18000a130(param_1,&local_128);
  if ((!bVar5) || ((char)local_108 == '\0')) goto LAB_18000d417;
  if ((int)uVar6 < 0) {
    local_198 = (undefined1 (*) [32])0x18003ba60;
    local_190 = 0x19;
    uVar14 = uVar6;
  }
  else {
    if ((((param_3 == (byte *)0x0) || (plVar10 = *(longlong **)param_3, plVar10 == (longlong *)0x0))
        || (*param_2 != 0x44833146f294acfc)) || (param_2[1] != -0x1d9f3d5823524059))
    goto LAB_18000d417;
    iVar7 = FUN_180025e38((uint *)&DAT_180050100);
    if (iVar7 != 0) goto LAB_18000d799;
    if (DAT_18005014c == 0x7fffffff) {
      DAT_18005014c = 0x7ffffffe;
      goto LAB_18000d7c3;
    }
    lVar1 = *plVar10;
    if (DAT_180051530 == 0) {
      uVar8 = FUN_180023e40(*(undefined8 **)(lVar1 + 0x18),FUN_18000a9b0,&DAT_180051490);
      if ((int)uVar8 == 0) {
        uVar8 = FUN_180023e40(*(undefined8 **)(lVar1 + 0x20),FUN_18000df80,&DAT_180051498);
        if ((int)uVar8 == 0) {
          FUN_180024180(*(longlong *)(lVar1 + 0x18));
          FUN_180024180(*(longlong *)(lVar1 + 0x20));
          uVar9 = FUN_180023c90();
          if ((int)uVar9 == 0) {
            DAT_180051538 = *(longlong *)(lVar1 + 0x20);
            bVar5 = true;
            DAT_180051530 = *(longlong *)(lVar1 + 0x18);
            FUN_180025e40(0x180050100);
            goto LAB_18000d5c2;
          }
          FUN_1800240c0(*(longlong *)(lVar1 + 0x18));
          FUN_1800240c0(*(longlong *)(lVar1 + 0x20));
        }
        else {
          FUN_180024190(*(longlong *)(lVar1 + 0x18));
        }
      }
      bVar5 = false;
      FUN_180025e40(0x180050100);
LAB_18000d59b:
      uStack_d0 = 0;
    }
    else {
      if ((DAT_180051530 == *(longlong *)(lVar1 + 0x18)) &&
         (DAT_180051538 == *(longlong *)(lVar1 + 0x20))) {
        bVar5 = true;
      }
      else {
        bVar5 = false;
      }
      FUN_180025e40(0x180050100);
      if (!bVar5) goto LAB_18000d59b;
LAB_18000d5c2:
      uStack_d0 = *(undefined8 *)param_3;
    }
    local_198 = (undefined1 (*) [32])&DAT_1800500b0;
    iVar7 = FUN_180025e38((uint *)&DAT_1800500b0);
    if (iVar7 != 0) {
LAB_18000d799:
                    /* WARNING: Subroutine does not return */
      FUN_180026614(5);
    }
    if (DAT_1800500fc == 0x7fffffff) {
      DAT_1800500fc = 0x7ffffffe;
LAB_18000d7c3:
                    /* WARNING: Subroutine does not return */
      FUN_180026614(6);
    }
    local_180 = param_1;
    plVar10 = FUN_180007af0((float *)&DAT_1800514b0,local_158 + 3,(byte *)&local_180);
    FUN_180008820((undefined8 *)(*plVar10 + 0x18),&local_128);
    if (bVar5) {
      local_170 = 0;
      local_168 = 0;
      uVar3 = uStack_fa._4_2_;
      local_164 = uStack_fa._4_2_;
      uVar4 = uStack_fa._6_2_;
      local_162 = uStack_fa._6_2_;
      uVar16 = uStack_fa._6_2_;
      if ((short)local_102 == -2) {
        uVar16 = local_f2._2_2_;
      }
      uVar2 = (undefined1)local_104;
      local_15e = (undefined1)local_104;
      local_158[0] = 0;
      local_158[1] = 0;
      local_158[2] = 0;
      local_178 = param_1;
      local_160 = uVar16;
      plVar10 = FUN_180007dd0((float *)&DAT_1800514f0,local_158 + 3,param_3);
      lVar1 = *plVar10;
      *(ulonglong *)(lVar1 + 0x18) = local_188;
      *(undefined8 *)(lVar1 + 0x20) = 0;
      *(undefined4 *)(lVar1 + 0x28) = 0;
      *(undefined2 *)(lVar1 + 0x2c) = uVar3;
      *(undefined2 *)(lVar1 + 0x2e) = uVar4;
      *(undefined2 *)(lVar1 + 0x30) = uVar16;
      *(undefined1 *)(lVar1 + 0x32) = uVar2;
      plVar10 = (longlong *)(lVar1 + 0x38);
      param_1 = local_188;
      if (plVar10 != local_158) {
        pvVar12 = (LPVOID)*plVar10;
        if (pvVar12 == (LPVOID)0x0) {
          *plVar10 = 0;
          *(undefined8 *)(lVar1 + 0x40) = 0;
          *(undefined8 *)(lVar1 + 0x48) = 0;
        }
        else {
          pvVar13 = pvVar12;
          if ((0xfff < (ulonglong)(*(longlong *)(lVar1 + 0x48) - (longlong)pvVar12)) &&
             (pvVar13 = *(LPVOID *)((longlong)pvVar12 + -8),
             0x1f < (ulonglong)((longlong)pvVar12 + (-8 - (longlong)pvVar13)))) {
                    /* WARNING: Subroutine does not return */
            _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
          }
          thunk_FUN_180030590(pvVar13);
          *(undefined8 *)(lVar1 + 0x40) = 0;
          *plVar10 = 0;
          *(undefined8 *)(lVar1 + 0x40) = 0;
          *(undefined8 *)(lVar1 + 0x48) = 0;
          param_1 = local_188;
        }
      }
    }
    FUN_180025e40(0x1800500b0);
    puVar11 = (uint *)FUN_180004ae0();
    uVar9 = 0;
    if (bVar5) {
      uVar9 = param_1;
    }
    FUN_180004db0(puVar11,param_1,'\x01',uVar9,uStack_d0,(longlong)&local_102);
    pwVar15 = L"render_observer_failed";
    if (bVar5) {
      pwVar15 = L"render_observer_ready";
    }
    local_190 = FUN_18002cb80((undefined1 (*) [32])pwVar15);
    uVar9 = 0x80004002;
    if (bVar5) {
      uVar9 = 0;
    }
    uVar14 = (uint)uVar9;
    local_198 = (undefined1 (*) [32])pwVar15;
  }
  FUN_1800225c0((LPSTR ******)&local_198,uVar14);
LAB_18000d417:
  if (7 < uStack_110) {
    pvVar12 = local_128;
    if ((0xfff < uStack_110 * 2 + 2) &&
       (pvVar12 = *(LPVOID *)((longlong)local_128 + -8),
       0x1f < (ulonglong)((longlong)local_128 + (-8 - (longlong)pvVar12)))) {
                    /* WARNING: Subroutine does not return */
      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
    }
    thunk_FUN_180030590(pvVar12);
  }
  return uVar6;
}
