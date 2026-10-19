/* Ghidra pseudocode; NOT original C++ source and NOT directly compilable.
 * DLL SHA256: 4a9e32cfffaed5b0ec60f3e5844113218245571f66837aae19adb23a149122db
 * Evidence: ev_1abec682882a7d9f5ee8835452fc639dca4f692f4b0940855b00452b248d258c
 */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Type propagation algorithm not settling */

ulonglong FUN_180017140(longlong param_1)

{
  longlong *plVar1;
  uint *puVar2;
  longlong lVar3;
  LPVOID pvVar4;
  uint uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  undefined8 *puVar9;
  undefined8 *puVar10;
  undefined1 (*pauVar11) [32];
  undefined8 *puVar12;
  LPVOID pvVar13;
  undefined2 *puVar14;
  uint uVar15;
  undefined8 *puVar16;
  undefined1 auStackY_198 [32];
  byte local_158;
  uint local_154 [3];
  LPSTR ***********local_148 [2];
  undefined8 local_138 [2];
  longlong local_128;
  ulonglong uStack_120;
  LPSTR ***********local_118 [3];
  ulonglong local_100;
  LPVOID local_f8;
  undefined8 uStack_f0;
  undefined8 local_e8;
  ulonglong uStack_e0;
  LPVOID local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  ulonglong uStack_c0;
  undefined2 local_b8;
  undefined6 uStack_b6;
  undefined8 local_a8;
  ulonglong uStack_a0;
  undefined2 local_98;
  undefined6 uStack_96;
  undefined8 local_88;
  ulonglong uStack_80;
  undefined2 local_78;
  undefined6 uStack_76;
  undefined8 local_68;
  ulonglong uStack_60;
  LPVOID local_58 [3];
  ulonglong local_40;
  ulonglong local_38;

  local_38 = DAT_180050580 ^ (ulonglong)auStackY_198;
  uVar15 = 0;
  plVar1 = (longlong *)(param_1 + 0x220);
  if (*plVar1 == 0) {
    uVar8 = *(ulonglong *)(param_1 + 0x88);
    do {
      uVar5 = (**(code **)(param_1 + 0x48))(param_1 + 0x28,plVar1);
      if (((int)uVar5 < 0) || ((longlong *)*plVar1 == (longlong *)0x0)) {
        if (-1 < (int)uVar5) {
          return 0x80004003;
        }
        return (ulonglong)uVar5;
      }
      uVar7 = FUN_180018140((longlong *)*plVar1,*(int *)(param_1 + 0x58),*(ushort *)(param_1 + 0x56)
                            ,(undefined8 *)(param_1 + 0x238));
      uVar6 = uVar7 & 0xffffffff;
      if ((int)uVar7 < 0) break;
      uVar5 = (**(code **)(*(longlong *)*plVar1 + 0x18))((longlong *)*plVar1,1,0x40000,uVar8);
      uVar6 = (ulonglong)uVar5;
      if (uVar5 != 0x88890019) {
        if (-1 < (int)uVar5) {
          puVar2 = (uint *)(param_1 + 0x260);
          uVar15 = (**(code **)(*(longlong *)*plVar1 + 0x20))();
          if ((((int)uVar15 < 0) || (*puVar2 == 0)) || (*(uint *)(param_1 + 0x80) < *puVar2)) {
            FUN_180015bc0(param_1,'\0');
            if (-1 < (int)uVar15) {
              return 0x88890016;
            }
            return (ulonglong)uVar15;
          }
          uVar15 = (**(code **)(*(longlong *)*plVar1 + 0x68))();
          if (((-1 < (int)uVar15) &&
              (uVar15 = (**(code **)(*(longlong *)*plVar1 + 0x70))
                                  ((longlong *)*plVar1,&DAT_18003ba50,param_1 + 0x228),
              -1 < (int)uVar15)) &&
             ((uVar15 = (**(code **)(*(longlong *)*plVar1 + 0x70))
                                  ((longlong *)*plVar1,&DAT_18003b6a0,param_1 + 0x230),
              -1 < (int)uVar15 &&
              ((uVar15 = (**(code **)(**(longlong **)(param_1 + 0x230) + 0x18))(), -1 < (int)uVar15
               && (*(longlong *)(param_1 + 0x268) != 0)))))) {
            local_154[0] = 0;
            FUN_18001a670((undefined8 *)(param_1 + 0x288),
                          (ulonglong)*(ushort *)(param_1 + 0x56) * (ulonglong)*puVar2,
                          (undefined1 (*) [32])local_154);
            *(uint *)(param_1 + 0x2d8) = *puVar2 << 2;
            local_154[0] = 0;
            FUN_18001a670((undefined8 *)(param_1 + 0x2a0),
                          (ulonglong)(*puVar2 << 2) * (ulonglong)*(ushort *)(param_1 + 0x56),
                          (undefined1 (*) [32])local_154);
            *(undefined8 *)(param_1 + 0x280) = 0;
            *(undefined8 *)(param_1 + 0x270) = 0;
            *(undefined8 *)(param_1 + 0x278) = *(undefined8 *)(param_1 + 0x2e0);
            uVar8 = FUN_1800162b0(param_1,'\x01');
            uVar7 = uVar8 & 0xffffffff;
            if (-1 < (int)uVar8) {
              uVar15 = (**(code **)(*(longlong *)*plVar1 + 0x50))();
              uVar7 = (ulonglong)uVar15;
              if (-1 < (int)uVar15) {
                LOCK();
                *(uint *)(param_1 + 0x328) = *puVar2;
                UNLOCK();
                LOCK();
                *(undefined2 *)(param_1 + 0x32c) = *(undefined2 *)(param_1 + 0x246);
                UNLOCK();
                LOCK();
                *(undefined2 *)(param_1 + 0x32e) = *(undefined2 *)(param_1 + 0x24a);
                UNLOCK();
                LOCK();
                *(undefined1 *)(param_1 + 0x53) = 1;
                UNLOCK();
                LOCK();
                *(longlong *)(param_1 + 0x310) = *(longlong *)(param_1 + 0x310) + 1;
                UNLOCK();
                puVar9 = FUN_180007830(local_58,*puVar2);
                puVar10 = FUN_180007760((undefined8 *)&local_78,(uint)*(ushort *)(param_1 + 0x246));
                pauVar11 = (undefined1 (*) [32])
                           FUN_180007830((undefined8 *)&local_98,*(uint *)(param_1 + 0x58));
                puVar12 = FUN_180001a30((undefined8 *)&local_b8,
                                        (undefined1 (*) [32])L"wasapi_exclusive_acquired_rate_",
                                        pauVar11);
                lVar3 = puVar12[2];
                if ((ulonglong)(puVar12[3] - lVar3) < 6) {
                  puVar12 = FUN_180001d30(puVar12,6,(ulonglong)local_158,(undefined8 *)L"_bits_",6);
                }
                else {
                  puVar12[2] = lVar3 + 6;
                  puVar16 = puVar12;
                  if (7 < (ulonglong)puVar12[3]) {
                    puVar16 = (undefined8 *)*puVar12;
                  }
                  FUN_180037000((undefined8 *)((longlong)puVar16 + lVar3 * 2),
                                (undefined8 *)L"_bits_",0xc);
                  *(undefined2 *)((longlong)puVar16 + (lVar3 + 6) * 2) = 0;
                }
                local_d8 = (LPVOID)*puVar12;
                uStack_d0 = puVar12[1];
                local_c8 = puVar12[2];
                uStack_c0 = puVar12[3];
                *(undefined2 *)puVar12 = 0;
                puVar12[2] = 0;
                puVar12[3] = 7;
                FUN_180002060(local_138,(ulonglong)local_158,&local_d8,puVar10);
                lVar3 = local_128;
                if (uStack_120 - local_128 < 8) {
                  puVar10 = FUN_180001d30(local_138,8,(ulonglong)local_158,(undefined8 *)L"_frames_"
                                          ,8);
                }
                else {
                  puVar14 = (undefined2 *)local_138;
                  if (7 < uStack_120) {
                    puVar14 = (undefined2 *)CONCAT62(local_138[0]._2_6_,(undefined2)local_138[0]);
                  }
                  puVar10 = (undefined8 *)(puVar14 + local_128);
                  local_128 = local_128 + 8;
                  FUN_180037000(puVar10,(undefined8 *)L"_frames_",0x10);
                  puVar14[lVar3 + 8] = 0;
                  puVar10 = local_138;
                }
                local_f8 = (LPVOID)*puVar10;
                uStack_f0 = puVar10[1];
                local_e8 = puVar10[2];
                uStack_e0 = puVar10[3];
                *(undefined2 *)puVar10 = 0;
                puVar10[2] = 0;
                puVar10[3] = 7;
                FUN_180002060(local_118,(ulonglong)local_158,&local_f8,puVar9);
                local_148[0] = (LPSTR ***********)local_118;
                if (7 < local_100) {
                  local_148[0] = local_118[0];
                }
                local_148[1] = local_118[2];
                FUN_1800225c0((LPSTR ******)local_148,0);
                FUN_180002330((longlong *)local_118);
                if (7 < uStack_e0) {
                  pvVar13 = local_f8;
                  if ((0xfff < uStack_e0 * 2 + 2) &&
                     (pvVar13 = *(LPVOID *)((longlong)local_f8 + -8),
                     0x1f < (ulonglong)((longlong)local_f8 + (-8 - (longlong)pvVar13)))) {
                    /* WARNING: Subroutine does not return */
                    _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
                  }
                  thunk_FUN_180030590(pvVar13);
                }
                if (7 < uStack_120) {
                  pvVar4 = (LPVOID)CONCAT62(local_138[0]._2_6_,(undefined2)local_138[0]);
                  pvVar13 = pvVar4;
                  if ((0xfff < uStack_120 * 2 + 2) &&
                     (pvVar13 = *(LPVOID *)((longlong)pvVar4 + -8),
                     0x1f < (ulonglong)((longlong)pvVar4 + (-8 - (longlong)pvVar13)))) {
                    /* WARNING: Subroutine does not return */
                    _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
                  }
                  thunk_FUN_180030590(pvVar13);
                }
                local_128 = 0;
                uStack_120 = 7;
                local_138[0]._0_2_ = 0;
                if (7 < uStack_c0) {
                  pvVar13 = local_d8;
                  if ((0xfff < uStack_c0 * 2 + 2) &&
                     (pvVar13 = *(LPVOID *)((longlong)local_d8 + -8),
                     0x1f < (ulonglong)((longlong)local_d8 + (-8 - (longlong)pvVar13)))) {
                    /* WARNING: Subroutine does not return */
                    _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
                  }
                  thunk_FUN_180030590(pvVar13);
                }
                if (7 < uStack_a0) {
                  pvVar4 = (LPVOID)CONCAT62(uStack_b6,local_b8);
                  pvVar13 = pvVar4;
                  if ((0xfff < uStack_a0 * 2 + 2) &&
                     (pvVar13 = *(LPVOID *)((longlong)pvVar4 + -8),
                     0x1f < (ulonglong)((longlong)pvVar4 + (-8 - (longlong)pvVar13)))) {
                    /* WARNING: Subroutine does not return */
                    _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
                  }
                  thunk_FUN_180030590(pvVar13);
                }
                local_a8 = 0;
                uStack_a0 = 7;
                local_b8 = 0;
                if (7 < uStack_80) {
                  pvVar4 = (LPVOID)CONCAT62(uStack_96,local_98);
                  pvVar13 = pvVar4;
                  if ((0xfff < uStack_80 * 2 + 2) &&
                     (pvVar13 = *(LPVOID *)((longlong)pvVar4 + -8),
                     0x1f < (ulonglong)((longlong)pvVar4 + (-8 - (longlong)pvVar13)))) {
                    /* WARNING: Subroutine does not return */
                    _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
                  }
                  thunk_FUN_180030590(pvVar13);
                }
                local_88 = 0;
                uStack_80 = 7;
                local_98 = 0;
                if (7 < uStack_60) {
                  pvVar4 = (LPVOID)CONCAT62(uStack_76,local_78);
                  pvVar13 = pvVar4;
                  if ((0xfff < uStack_60 * 2 + 2) &&
                     (pvVar13 = *(LPVOID *)((longlong)pvVar4 + -8),
                     0x1f < (ulonglong)((longlong)pvVar4 + (-8 - (longlong)pvVar13)))) {
                    /* WARNING: Subroutine does not return */
                    _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
                  }
                  thunk_FUN_180030590(pvVar13);
                }
                local_68 = 0;
                uStack_60 = 7;
                local_78 = 0;
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
                return 0;
              }
            }
            FUN_180015bc0(param_1,'\0');
            return uVar7;
          }
          FUN_180015bc0(param_1,'\0');
          if (-1 < (int)uVar15) {
            return 0x8000ffff;
          }
          return (ulonglong)uVar15;
        }
        break;
      }
      local_154[0] = 0;
      uVar5 = (**(code **)(*(longlong *)*plVar1 + 0x20))();
      FUN_180015bc0(param_1,'\0');
      if (((int)uVar5 < 0) || (local_154[0] == 0)) {
        if (-1 < (int)uVar5) {
          return 0x8000ffff;
        }
        return (ulonglong)uVar5;
      }
      uVar7 = ((ulonglong)(*(uint *)(param_1 + 0x58) >> 1) + (ulonglong)local_154[0] * 10000000) /
              (ulonglong)*(uint *)(param_1 + 0x58);
      if (uVar7 == uVar8) {
        return 0x88890019;
      }
      uVar15 = uVar15 + 1;
      uVar8 = uVar7;
    } while (uVar15 < 3);
    FUN_180015bc0(param_1,'\0');
  }
  else {
    uVar6 = 0x88890005;
  }
  return uVar6;
}
