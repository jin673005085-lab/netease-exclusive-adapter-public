/* Ghidra pseudocode; NOT original or compilable C++. Evidence: ev_bb2ae974a91e24f31414505bf83bb4c6f3b198a781a90ee14c52616caac5728b */

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FUN_18000a290(longlong *param_1,void *param_2,undefined8 param_3,undefined8 param_4,
                       byte *param_5)

{
  LPVOID *ppvVar1;
  longlong lVar2;
  bool bVar3;
  undefined1 (*pauVar4) [32];
  int iVar5;
  uint uVar6;
  undefined *puVar7;
  undefined8 *puVar8;
  uint *puVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  longlong *plVar12;
  LPVOID pvVar13;
  LPVOID pvVar14;
  bool bVar15;
  undefined1 auStackY_1a8 [32];
  int local_178 [2];
  undefined1 (*local_170) [32];
  undefined1 (*local_168) [32];
  longlong *local_160;
  LPSTR *****local_158;
  undefined8 local_150;
  LPVOID local_148;
  undefined8 uStack_140;
  undefined8 local_138;
  ulonglong uStack_130;
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

  local_48 = DAT_180050580 ^ (ulonglong)auStackY_1a8;
  bVar15 = false;
  local_168 = (undefined1 (*) [32])((ulonglong)local_168 & 0xffffffff00000000);
  iVar5 = (*DAT_180051440)();
  local_168 = (undefined1 (*) [32])CONCAT44(local_168._4_4_,iVar5);
  if ((((iVar5 < 0) || (param_5 == (byte *)0x0)) || (*(longlong *)param_5 == 0)) ||
     (((iVar5 = memcmp(param_2,&DAT_18003b758,0x10), iVar5 != 0 &&
       (iVar5 = memcmp(param_2,&DAT_18003bb38,0x10), iVar5 != 0)) &&
      (iVar5 = memcmp(param_2,&DAT_18003bb48,0x10), iVar5 != 0)))) goto LAB_18000a910;
  local_160 = (longlong *)0x0;
  local_178[0] = 2;
  iVar5 = (**(code **)*param_1)(param_1,&DAT_18003bb58);
  if (-1 < iVar5) {
    (**(code **)(*local_160 + 0x18))(local_160,local_178);
    (**(code **)(*local_160 + 0x10))();
  }
  if (((local_178[0] == 0) &&
      (*(char *)(*(longlong *)((longlong)ThreadLocalStoragePointer + (ulonglong)_tls_index * 8) +
                0x10) != '\0')) && (puVar7 = FUN_180004ae0(), puVar7[0x50] != '\0')) {
    puVar8 = FUN_1800104a0(&local_148);
    bVar15 = true;
    if ((puVar8[2] == 0) || (iVar5 = memcmp(param_2,&DAT_18003b758,0x10), iVar5 != 0))
    goto LAB_18000a40b;
    bVar3 = true;
  }
  else {
LAB_18000a40b:
    bVar3 = false;
  }
  if ((bVar15) && (7 < uStack_130)) {
    pvVar13 = local_148;
    if ((0xfff < uStack_130 * 2 + 2) &&
       (pvVar13 = *(LPVOID *)((longlong)local_148 + -8),
       0x1f < (ulonglong)((longlong)local_148 + (-8 - (longlong)pvVar13)))) {
                    /* WARNING: Subroutine does not return */
      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
    }
    thunk_FUN_180030590(pvVar13);
  }
  if (bVar3) {
    plVar12 = *(longlong **)param_5;
    local_170 = (undefined1 (*) [32])0x0;
    puVar8 = FUN_180012770(plVar12,&local_170);
    uVar6 = (uint)puVar8;
    if ((int)uVar6 < 0) {
      (**(code **)(*plVar12 + 0x10))(plVar12);
      param_5[0] = 0;
      param_5[1] = 0;
      param_5[2] = 0;
      param_5[3] = 0;
      param_5[4] = 0;
      param_5[5] = 0;
      param_5[6] = 0;
      param_5[7] = 0;
      puVar9 = (uint *)FUN_180004ae0();
      FUN_180004ec0(puVar9,uVar6);
      local_158 = (LPSTR *****)0x18003bb68;
      local_150 = 0x17;
      FUN_1800225c0(&local_158,uVar6);
      return (ulonglong)puVar8 & 0xffffffff;
    }
    *(undefined1 (**) [32])param_5 = local_170;
    return 0;
  }
  if (local_178[0] == 0) {
    if (*(char *)(*(longlong *)((longlong)ThreadLocalStoragePointer + (ulonglong)_tls_index * 8) +
                 0x10) != '\0') {
      puVar7 = FUN_180004ae0();
      if ((puVar7[0x50] != '\0') && (iVar5 = memcmp(param_2,&DAT_18003b758,0x10), iVar5 == 0)) {
        uVar11 = 0;
        local_168 = (undefined1 (*) [32])0x0;
        uVar6 = (**(code **)(*param_1 + 0x28))(param_1,&local_168);
        pauVar4 = local_168;
        if (((int)uVar6 < 0) || (local_168 == (undefined1 (*) [32])0x0)) {
          (**(code **)(**(longlong **)param_5 + 0x10))();
          param_5[0] = 0;
          param_5[1] = 0;
          param_5[2] = 0;
          param_5[3] = 0;
          param_5[4] = 0;
          param_5[5] = 0;
          param_5[6] = 0;
          param_5[7] = 0;
          if (-1 < (int)uVar6) {
            return 0x8000ffff;
          }
          return (ulonglong)uVar6;
        }
        local_148 = (LPVOID)0x0;
        uStack_140 = 0;
        local_138 = 0;
        uStack_130 = 0;
        uVar10 = FUN_18002cb80(local_168);
        FUN_180001c40(&local_148,(undefined8 *)pauVar4,uVar10);
        CoTaskMemFree(local_168);
        local_170 = (undefined1 (*) [32])0x0;
        uVar10 = FUN_180016210(*(undefined8 *)param_5,&local_148,&local_170);
        if ((int)(uint)uVar10 < 0) {
          (**(code **)(**(longlong **)param_5 + 0x10))();
          param_5[0] = 0;
          param_5[1] = 0;
          param_5[2] = 0;
          param_5[3] = 0;
          param_5[4] = 0;
          param_5[5] = 0;
          param_5[6] = 0;
          param_5[7] = 0;
          puVar9 = (uint *)FUN_180004ae0();
          FUN_180004ec0(puVar9,(uint)uVar10);
          uVar11 = uVar10 & 0xffffffff;
        }
        else {
          *(undefined1 (**) [32])param_5 = local_170;
        }
        if (uStack_130 < 8) {
          return uVar11;
        }
        pvVar13 = local_148;
        if ((0xfff < uStack_130 * 2 + 2) &&
           (pvVar13 = *(LPVOID *)((longlong)local_148 + -8),
           0x1f < (ulonglong)((longlong)local_148 + (-8 - (longlong)pvVar13)))) {
                    /* WARNING: Subroutine does not return */
          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
        }
        thunk_FUN_180030590(pvVar13);
        return uVar11;
      }
      if (local_178[0] != 0) goto LAB_18000a910;
    }
    local_170 = (undefined1 (*) [32])0x0;
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
    iVar5 = (**(code **)(*param_1 + 0x28))(param_1,&local_170);
    pauVar4 = local_170;
    if ((-1 < iVar5) && (local_170 != (undefined1 (*) [32])0x0)) {
      uVar11 = FUN_18002cb80(local_170);
      FUN_18000f3f0(&local_128,(undefined8 *)pauVar4,uVar11);
      CoTaskMemFree(local_170);
    }
    local_158 = (LPSTR *****)&DAT_1800500b0;
    iVar5 = FUN_180025e38((uint *)&DAT_1800500b0);
    if (iVar5 != 0) {
                    /* WARNING: Subroutine does not return */
      FUN_180026614(5);
    }
    if (DAT_1800500fc == 0x7fffffff) {
      DAT_1800500fc = 0x7ffffffe;
                    /* WARNING: Subroutine does not return */
      FUN_180026614(6);
    }
    plVar12 = FUN_180007af0((float *)&DAT_1800514b0,&local_148,param_5);
    lVar2 = *plVar12;
    ppvVar1 = (LPVOID *)(lVar2 + 0x18);
    if (ppvVar1 != &local_128) {
      if (7 < *(ulonglong *)(lVar2 + 0x30)) {
        pvVar13 = *ppvVar1;
        pvVar14 = pvVar13;
        if ((0xfff < *(ulonglong *)(lVar2 + 0x30) * 2 + 2) &&
           (pvVar14 = *(LPVOID *)((longlong)pvVar13 + -8),
           0x1f < (ulonglong)((longlong)pvVar13 + (-8 - (longlong)pvVar14)))) {
                    /* WARNING: Subroutine does not return */
          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
        }
        thunk_FUN_180030590(pvVar14);
      }
      *(undefined8 *)(lVar2 + 0x28) = 0;
      *(undefined8 *)(lVar2 + 0x30) = 7;
      *(undefined2 *)ppvVar1 = 0;
      *ppvVar1 = local_128;
      *(undefined8 *)(lVar2 + 0x20) = uStack_120;
      *(undefined8 *)(lVar2 + 0x28) = local_118;
      *(ulonglong *)(lVar2 + 0x30) = uStack_110;
      local_118 = 0;
      uStack_110 = 7;
      local_128 = (LPVOID)((ulonglong)local_128 & 0xffffffffffff0000);
    }
    *(undefined1 *)(lVar2 + 0x38) = (undefined1)local_108;
    *(undefined1 *)(lVar2 + 0x39) = local_108._1_1_;
    *(undefined1 *)(lVar2 + 0x3a) = local_108._2_1_;
    *(undefined1 *)(lVar2 + 0x3b) = local_108._3_1_;
    *(undefined1 *)(lVar2 + 0x3c) = (undefined1)local_104;
    *(undefined1 *)(lVar2 + 0x3d) = local_104._1_1_;
    *(undefined8 *)(lVar2 + 0x3e) = local_102;
    *(undefined8 *)(lVar2 + 0x46) = uStack_fa;
    *(undefined8 *)(lVar2 + 0x4e) = local_f2;
    *(undefined8 *)(lVar2 + 0x56) = uStack_ea;
    *(undefined8 *)(lVar2 + 0x5e) = local_e2;
    *(undefined8 *)(lVar2 + 0x68) = local_d8;
    *(undefined8 *)(lVar2 + 0x70) = uStack_d0;
    *(undefined8 *)(lVar2 + 0x78) = local_c8;
    *(undefined4 *)(lVar2 + 0x80) = local_c0;
    *(undefined8 *)(lVar2 + 0x88) = local_b8;
    *(undefined8 *)(lVar2 + 0x90) = local_b0;
    *(undefined8 *)(lVar2 + 0x98) = local_a8;
    *(undefined8 *)(lVar2 + 0xa0) = local_a0;
    *(undefined8 *)(lVar2 + 0xa8) = local_98;
    *(undefined8 *)(lVar2 + 0xb0) = local_90;
    *(undefined8 *)(lVar2 + 0xb8) = local_88;
    *(undefined8 *)(lVar2 + 0xc0) = local_80;
    *(undefined8 *)(lVar2 + 200) = local_78;
    *(undefined8 *)(lVar2 + 0xd0) = local_70;
    *(undefined8 *)(lVar2 + 0xd8) = local_68;
    *(undefined8 *)(lVar2 + 0xe0) = local_60;
    *(undefined8 *)(lVar2 + 0xe8) = local_58;
    FUN_180025e40(0x1800500b0);
    if (7 < uStack_110) {
      pvVar13 = local_128;
      if ((0xfff < uStack_110 * 2 + 2) &&
         (pvVar13 = *(LPVOID *)((longlong)local_128 + -8),
         0x1f < (ulonglong)((longlong)local_128 + (-8 - (longlong)pvVar13)))) {
                    /* WARNING: Subroutine does not return */
        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
      }
      thunk_FUN_180030590(pvVar13);
    }
  }
LAB_18000a910:
  return (ulonglong)local_168 & 0xffffffff;
}
