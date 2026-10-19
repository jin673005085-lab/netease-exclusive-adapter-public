/* Ghidra pseudocode; NOT original C++ source and NOT directly compilable.
 * DLL SHA256: 4a9e32cfffaed5b0ec60f3e5844113218245571f66837aae19adb23a149122db
 * Evidence: ev_1268b1d70c0fa65cbff85948be014b9ea5ebcde88a6946ec317e2f1d5e0dc907
 */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Type propagation algorithm not settling */

ulonglong FUN_18000b050(LPSTR *****param_1,uint param_2,uint param_3,LPSTR *****param_4,
                       LPSTR *****param_5,undefined8 *param_6,LPSTR *****param_7)

{
  ushort uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  undefined2 uVar7;
  undefined2 uVar8;
  undefined2 uVar9;
  short sVar10;
  undefined2 uVar11;
  undefined2 uVar12;
  undefined2 uVar13;
  undefined2 uVar14;
  undefined2 uVar15;
  undefined2 uVar16;
  undefined2 uVar17;
  undefined8 uVar18;
  LPVOID pvVar19;
  bool bVar20;
  ushort uVar21;
  ushort uVar22;
  uint uVar23;
  uint uVar24;
  int iVar25;
  undefined *puVar26;
  uint *puVar27;
  HMODULE pHVar28;
  undefined8 *puVar29;
  undefined1 (*pauVar30) [32];
  undefined8 *puVar31;
  short *psVar32;
  char cVar33;
  undefined8 *puVar34;
  LPVOID pvVar35;
  LPSTR *****ppppppCVar36;
  longlong lVar37;
  ulonglong uVar38;
  undefined8 *******pppppppuVar39;
  undefined4 uVar40;
  uint uVar41;
  ulonglong uVar42;
  undefined2 *puVar43;
  undefined8 *puVar44;
  ushort *puVar45;
  uint uVar46;
  longlong *plVar47;
  undefined1 auStackY_658 [32];
  uint local_618;
  uint local_614;
  LPSTR *****local_608;
  undefined8 local_600;
  LPSTR *****local_5f8;
  longlong *local_5f0;
  undefined4 local_5e8;
  undefined2 local_5e4;
  LPSTR *****local_5e0 [3];
  LPSTR *****local_5c8;
  undefined8 local_5c0;
  undefined8 local_5b0;
  undefined8 *******local_498;
  undefined8 uStack_490;
  undefined8 local_488;
  ulonglong uStack_480;
  undefined4 local_478;
  ushort local_474;
  undefined8 local_472;
  undefined8 uStack_46a;
  undefined8 local_462;
  undefined8 uStack_45a;
  undefined8 local_452;
  LPSTR *****local_448;
  undefined8 uStack_440;
  undefined8 local_438;
  uint local_430;
  undefined8 local_428;
  undefined8 local_420;
  undefined8 local_418;
  undefined8 local_410;
  undefined8 local_408;
  undefined8 local_400;
  undefined8 local_3f8;
  undefined8 local_3f0;
  undefined8 local_3e8;
  undefined8 local_3e0;
  undefined8 local_3d8;
  undefined8 local_3d0;
  undefined8 local_3c8;
  LPSTR *****local_3b8;
  LPSTR ****pppppCStack_3b0;
  undefined8 local_3a8;
  ulonglong uStack_3a0;
  undefined8 local_398 [2];
  longlong local_388;
  ulonglong uStack_380;
  undefined8 local_378 [2];
  longlong local_368;
  ulonglong uStack_360;
  undefined2 local_358;
  undefined6 uStack_356;
  undefined8 local_348;
  ulonglong uStack_340;
  undefined2 local_338;
  undefined6 uStack_336;
  undefined8 local_328;
  ulonglong uStack_320;
  LPVOID local_318 [3];
  ulonglong local_300;
  undefined8 local_2f8;
  undefined8 local_2f0;
  undefined8 uStack_2e8;
  undefined8 local_2e0;
  undefined8 uStack_2d8;
  undefined8 local_2d0;
  undefined2 local_2c8;
  undefined6 uStack_2c6;
  undefined8 local_2b8;
  ulonglong uStack_2b0;
  undefined2 local_2a8;
  undefined6 uStack_2a6;
  undefined8 local_298;
  ulonglong uStack_290;
  LPVOID local_288;
  undefined8 uStack_280;
  undefined8 local_278;
  ulonglong uStack_270;
  LPVOID local_268;
  undefined8 uStack_260;
  undefined8 local_258;
  ulonglong uStack_250;
  undefined2 local_248;
  undefined6 uStack_246;
  undefined8 local_238;
  ulonglong uStack_230;
  undefined2 local_228;
  undefined6 uStack_226;
  undefined8 local_218;
  ulonglong uStack_210;
  LPVOID local_208 [3];
  ulonglong local_1f0;
  undefined8 local_1e8 [35];
  undefined8 local_d0;
  LPVOID local_c8 [3];
  ulonglong local_b0;
  short local_a0;
  undefined1 local_9e [6];
  LPVOID local_98 [3];
  ulonglong local_80;
  short local_6e [3];
  ulonglong local_68;

  local_68 = DAT_180050580 ^ (ulonglong)auStackY_658;
  local_608 = param_5;
  local_5c8 = param_7;
  uStack_490 = 0;
  local_488 = 0;
  uStack_480 = 7;
  local_498 = (undefined8 *******)0x0;
  local_478 = 0;
  local_474 = 0;
  local_472 = 0;
  uStack_46a = 0;
  local_462 = 0;
  uStack_45a = 0;
  local_452 = 0;
  local_448 = (LPSTR *****)0x0;
  uStack_440 = 0;
  local_438 = 0;
  local_430 = 0;
  local_428 = 0;
  local_420 = 0;
  local_418 = 0;
  local_410 = 0;
  local_408 = 0;
  local_400 = 0;
  local_3f8 = 0;
  local_3f0 = 0;
  local_3e8 = 0;
  local_3e0 = 0;
  local_3d8 = 0;
  local_3d0 = 0;
  local_3c8 = 0;
  local_618 = param_3;
  local_614 = param_2;
  local_5f8 = param_1;
  local_5e0[0] = param_4;
  bVar20 = FUN_18000a130((ulonglong)param_1,&local_498);
  local_2f0 = 0;
  uStack_2e8 = 0;
  local_2e0 = 0;
  uStack_2d8 = 0;
  local_2d0 = 0;
  if (!bVar20) {
LAB_18000c512:
    uVar41 = (*DAT_180051448)(param_1,local_614,param_3,param_4);
    uVar42 = (ulonglong)uVar41;
    goto LAB_18000c541;
  }
  lVar37 = *(longlong *)((longlong)ThreadLocalStoragePointer + (ulonglong)_tls_index * 8);
  if ((((*(char *)(lVar37 + 0x10) == '\0') && (puVar26 = FUN_180004ae0(), puVar26[0x50] != '\0')) &&
      (local_614 == 0)) && ((param_3 >> 0x11 & 1) == 0)) {
    local_608 = (LPSTR *****)0x18003b768;
    local_600 = 0x17;
    uVar42 = 0x8889000e;
    FUN_1800225c0(&local_608,0x8889000e);
    goto LAB_18000c541;
  }
  if (*(char *)(lVar37 + 0x10) == '\0') goto LAB_18000c512;
  puVar27 = (uint *)FUN_180004ae0();
  bVar20 = local_614 == 1;
  FUN_180004c20(puVar27,param_1,bVar20);
  local_478._0_2_ = CONCAT11(bVar20,1);
  if (local_614 == 1) {
    if (((param_6 == (undefined8 *)0x0) || (uVar1 = *(ushort *)((longlong)param_6 + 2), uVar1 == 0))
       || ((uVar41 = *(uint *)((longlong)param_6 + 4), uVar41 < 8000 || (0xbb800 < uVar41)))) {
      puVar27 = (uint *)FUN_180004ae0();
      uVar42 = 0x88890008;
      FUN_180004ec0(puVar27,0x88890008);
      goto LAB_18000c541;
    }
    param_3 = local_618;
    if (*(longlong *)(lVar37 + 0x18) != 0) {
      FUN_1800376a0((undefined1 (*) [32])&local_5b0,0,0x118);
      param_1 = local_5f8;
      param_5 = local_608;
      local_5f0 = (longlong *)0x10001800200020;
      local_5e8 = 0x180020;
      local_5e4 = 0x10;
      local_3b8 = (LPSTR *****)0x10001800180020;
      pppppCStack_3b0 = (LPSTR ****)CONCAT26(pppppCStack_3b0._6_2_,0x1000180020);
      uVar46 = 0;
      uVar40 = 0;
      if (uVar1 == 2) {
        uVar40 = 3;
      }
      puVar45 = (ushort *)((longlong)&local_5b0 + 2);
      lVar37 = 0;
      do {
        uVar22 = *(ushort *)((longlong)&local_5f0 + lVar37);
        uVar21 = 1;
        if (uVar46 < 4) {
          uVar21 = 0xfffe;
        }
        puVar45[-1] = uVar21;
        *puVar45 = uVar1;
        *(uint *)(puVar45 + 1) = uVar41;
        *(uint *)(puVar45 + 3) = (uVar22 >> 3) * uVar41 * (uint)uVar1;
        puVar45[5] = (uVar22 >> 3) * uVar1;
        puVar45[6] = uVar22;
        puVar45[7] = -(ushort)(uVar46 < 4) & 0x16;
        puVar45[8] = *(ushort *)((longlong)&local_3b8 + lVar37);
        *(undefined4 *)(puVar45 + 9) = uVar40;
        puVar45[0xb] = 1;
        puVar45[0xc] = 0;
        puVar45[0xd] = 0;
        puVar45[0xe] = 0x10;
        puVar45[0xf] = 0x80;
        puVar45[0x10] = 0xaa00;
        puVar45[0x11] = 0x3800;
        puVar45[0x12] = 0x719b;
        uVar46 = uVar46 + 1;
        lVar37 = lVar37 + 2;
        puVar45 = puVar45 + 0x14;
      } while (uVar46 < 7);
      lVar37 = 2;
      uVar38 = (ulonglong)_tls_index;
      puVar29 = &local_5b0;
      puVar31 = local_1e8;
      do {
        puVar34 = puVar31;
        puVar44 = puVar29;
        uVar18 = puVar44[1];
        *puVar34 = *puVar44;
        puVar34[1] = uVar18;
        uVar18 = puVar44[3];
        puVar34[2] = puVar44[2];
        puVar34[3] = uVar18;
        uVar18 = puVar44[5];
        puVar34[4] = puVar44[4];
        puVar34[5] = uVar18;
        uVar18 = puVar44[7];
        puVar34[6] = puVar44[6];
        puVar34[7] = uVar18;
        uVar18 = puVar44[9];
        puVar34[8] = puVar44[8];
        puVar34[9] = uVar18;
        uVar18 = puVar44[0xb];
        puVar34[10] = puVar44[10];
        puVar34[0xb] = uVar18;
        uVar18 = puVar44[0xd];
        puVar34[0xc] = puVar44[0xc];
        puVar34[0xd] = uVar18;
        uVar18 = puVar44[0xf];
        puVar34[0xe] = puVar44[0xe];
        puVar34[0xf] = uVar18;
        lVar37 = lVar37 + -1;
        puVar29 = puVar44 + 0x10;
        puVar31 = puVar34 + 0x10;
      } while (lVar37 != 0);
      uVar40 = *(undefined4 *)((longlong)puVar44 + 0x84);
      uVar2 = *(undefined4 *)(puVar44 + 0x11);
      uVar3 = *(undefined4 *)((longlong)puVar44 + 0x8c);
      *(undefined4 *)(puVar34 + 0x10) = *(undefined4 *)(puVar44 + 0x10);
      *(undefined4 *)((longlong)puVar34 + 0x84) = uVar40;
      *(undefined4 *)(puVar34 + 0x11) = uVar2;
      *(undefined4 *)((longlong)puVar34 + 0x8c) = uVar3;
      puVar34[0x12] = puVar44[0x12];
      puVar29 = local_1e8;
      uVar42 = 0x88890008;
      do {
        uVar41 = (*(code *)(*param_1)[7])(param_1,1,puVar29,0);
        if (uVar41 == 0) {
          uVar4 = *(undefined2 *)((longlong)puVar29 + 2);
          uVar5 = *(undefined2 *)((longlong)puVar29 + 4);
          uVar6 = *(undefined2 *)((longlong)puVar29 + 6);
          local_2f0 = *puVar29;
          uVar7 = *(undefined2 *)(puVar29 + 1);
          uVar8 = *(undefined2 *)((longlong)puVar29 + 10);
          uVar9 = *(undefined2 *)((longlong)puVar29 + 0xc);
          sVar10 = *(short *)((longlong)puVar29 + 0xe);
          uStack_2e8 = puVar29[1];
          uVar11 = *(undefined2 *)(puVar29 + 2);
          uVar1 = *(ushort *)((longlong)puVar29 + 0x12);
          uVar12 = *(undefined2 *)((longlong)puVar29 + 0x14);
          uVar13 = *(undefined2 *)((longlong)puVar29 + 0x16);
          local_2e0 = puVar29[2];
          uVar14 = *(undefined2 *)(puVar29 + 3);
          uVar15 = *(undefined2 *)((longlong)puVar29 + 0x1a);
          uVar16 = *(undefined2 *)((longlong)puVar29 + 0x1c);
          uVar17 = *(undefined2 *)((longlong)puVar29 + 0x1e);
          uStack_2d8 = puVar29[3];
          local_2f8 = puVar29[4];
          plVar47 = (longlong *)
                    (*(longlong *)((longlong)ThreadLocalStoragePointer + uVar38 * 8) + 0x18);
          lVar37 = *plVar47;
          puVar43 = (undefined2 *)(lVar37 + 0x130);
          param_6 = &local_2f0;
          *puVar43 = *(undefined2 *)puVar29;
          *(undefined2 *)(lVar37 + 0x132) = uVar4;
          *(undefined2 *)(lVar37 + 0x134) = uVar5;
          *(undefined2 *)(lVar37 + 0x136) = uVar6;
          *(undefined2 *)(lVar37 + 0x138) = uVar7;
          *(undefined2 *)(lVar37 + 0x13a) = uVar8;
          *(undefined2 *)(lVar37 + 0x13c) = uVar9;
          *(short *)(lVar37 + 0x13e) = sVar10;
          *(undefined2 *)(lVar37 + 0x140) = uVar11;
          *(ushort *)(lVar37 + 0x142) = uVar1;
          *(undefined2 *)(lVar37 + 0x144) = uVar12;
          *(undefined2 *)(lVar37 + 0x146) = uVar13;
          *(undefined2 *)(lVar37 + 0x148) = uVar14;
          *(undefined2 *)(lVar37 + 0x14a) = uVar15;
          *(undefined2 *)(lVar37 + 0x14c) = uVar16;
          *(undefined2 *)(lVar37 + 0x14e) = uVar17;
          *(undefined8 *)(lVar37 + 0x150) = local_2f8;
          local_3b8 = (LPSTR *****)CONCAT62(local_3b8._2_6_,sVar10);
          if ((sVar10 != 0x20) || (local_474 = local_474 & 0xff00, uVar1 != 0x20)) {
            local_474 = CONCAT11(local_474._1_1_,1);
          }
          *puVar43 = 0xfffe;
          *(undefined4 *)(lVar37 + 0x13e) = 0x160020;
          *(undefined2 *)(lVar37 + 0x142) = 0x20;
          uVar22 = *(short *)(lVar37 + 0x132) << 2;
          *(ushort *)(lVar37 + 0x13c) = uVar22;
          *(uint *)(lVar37 + 0x138) = (uint)uVar22 * *(int *)(lVar37 + 0x134);
          lVar37 = *(longlong *)(DAT_1800514a8 + 0x28);
          local_2d0 = local_2f8;
          pHVar28 = GetModuleHandleW(L"cloudmusic.dll");
          (*(code *)((longlong)&pHVar28->unused + lVar37))(puVar43,*plVar47 + 0xe8);
          puVar29 = FUN_180007760(local_c8,(uint)uVar1);
          pauVar30 = (undefined1 (*) [32])
                     FUN_180007760((undefined8 *)&local_2a8,(uint)(ushort)local_3b8);
          puVar31 = FUN_180001a30((undefined8 *)&local_2c8,
                                  (undefined1 (*) [32])L"native_pcm_selected_container_",pauVar30);
          lVar37 = puVar31[2];
          if ((ulonglong)(puVar31[3] - lVar37) < 7) {
            puVar31 = FUN_180001d30(puVar31,7,(ulonglong)local_3b8 & 0xff,(undefined8 *)L"_valid_",7
                                   );
          }
          else {
            puVar31[2] = lVar37 + 7;
            puVar44 = puVar31;
            if (7 < (ulonglong)puVar31[3]) {
              puVar44 = (undefined8 *)*puVar31;
            }
            FUN_180037000((undefined8 *)((longlong)puVar44 + lVar37 * 2),(undefined8 *)L"_valid_",
                          0xe);
            *(undefined2 *)((longlong)puVar44 + (lVar37 + 7) * 2) = 0;
          }
          local_3b8 = (LPSTR *****)*puVar31;
          pppppCStack_3b0 = (LPSTR ****)puVar31[1];
          local_3a8 = puVar31[2];
          uStack_3a0 = puVar31[3];
          *(undefined2 *)puVar31 = 0;
          puVar31[2] = 0;
          puVar31[3] = 7;
          FUN_180002060((undefined8 *)&local_358,(ulonglong)local_3b8 & 0xff,&local_3b8,puVar29);
          local_608 = (LPSTR *****)&local_358;
          if (7 < uStack_340) {
            local_608 = (LPSTR *****)CONCAT62(uStack_356,local_358);
          }
          local_600 = local_348;
          FUN_1800225c0(&local_608,0);
          if (7 < uStack_340) {
            pvVar19 = (LPVOID)CONCAT62(uStack_356,local_358);
            pvVar35 = pvVar19;
            if ((0xfff < uStack_340 * 2 + 2) &&
               (pvVar35 = *(LPVOID *)((longlong)pvVar19 + -8),
               0x1f < (ulonglong)((longlong)pvVar19 + (-8 - (longlong)pvVar35)))) {
                    /* WARNING: Subroutine does not return */
              _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
            }
            thunk_FUN_180030590(pvVar35);
          }
          local_348 = 0;
          uStack_340 = 7;
          local_358 = 0;
          if (7 < uStack_3a0) {
            ppppppCVar36 = local_3b8;
            if ((0xfff < uStack_3a0 * 2 + 2) &&
               (ppppppCVar36 = (LPSTR *****)local_3b8[-1],
               0x1f < (ulonglong)((longlong)local_3b8 + (-8 - (longlong)ppppppCVar36)))) {
                    /* WARNING: Subroutine does not return */
              _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
            }
            thunk_FUN_180030590(ppppppCVar36);
          }
          if (7 < uStack_2b0) {
            pvVar19 = (LPVOID)CONCAT62(uStack_2c6,local_2c8);
            pvVar35 = pvVar19;
            if ((0xfff < uStack_2b0 * 2 + 2) &&
               (pvVar35 = *(LPVOID *)((longlong)pvVar19 + -8),
               0x1f < (ulonglong)((longlong)pvVar19 + (-8 - (longlong)pvVar35)))) {
                    /* WARNING: Subroutine does not return */
              _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
            }
            thunk_FUN_180030590(pvVar35);
          }
          local_2b8 = 0;
          uStack_2b0 = 7;
          local_2c8 = 0;
          if (7 < uStack_290) {
            pvVar19 = (LPVOID)CONCAT62(uStack_2a6,local_2a8);
            pvVar35 = pvVar19;
            if ((0xfff < uStack_290 * 2 + 2) &&
               (pvVar35 = *(LPVOID *)((longlong)pvVar19 + -8),
               0x1f < (ulonglong)((longlong)pvVar19 + (-8 - (longlong)pvVar35)))) {
                    /* WARNING: Subroutine does not return */
              _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
            }
            thunk_FUN_180030590(pvVar35);
          }
          local_298 = 0;
          uStack_290 = 7;
          local_2a8 = 0;
          param_3 = local_618;
          if (7 < local_b0) {
            pvVar35 = local_c8[0];
            if ((0xfff < local_b0 * 2 + 2) &&
               (pvVar35 = *(LPVOID *)((longlong)local_c8[0] + -8),
               0x1f < (ulonglong)((longlong)local_c8[0] + (-8 - (longlong)pvVar35)))) {
                    /* WARNING: Subroutine does not return */
              _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
            }
            thunk_FUN_180030590(pvVar35);
            param_3 = local_618;
          }
          goto LAB_18000b866;
        }
        if (((uVar41 != 0x88890008) && (uVar41 != 1)) && (uVar41 != 0x80070057)) {
          puVar27 = (uint *)FUN_180004ae0();
          FUN_180004ec0(puVar27,uVar41);
          uVar42 = (ulonglong)uVar41;
          goto LAB_18000c541;
        }
        puVar29 = puVar29 + 5;
      } while (puVar29 != &local_d0);
      local_608 = (LPSTR *****)0x18003b7a0;
      local_600 = 0x2c;
      FUN_1800225c0(&local_608,0x88890008);
      puVar27 = (uint *)FUN_180004ae0();
      FUN_180004ec0(puVar27,0x88890008);
      goto LAB_18000c541;
    }
LAB_18000b866:
    uVar41 = local_614;
    uVar42 = 0x28;
    if ((ulonglong)*(ushort *)(param_6 + 2) + 0x12 < 0x28) {
      uVar42 = (ulonglong)*(ushort *)(param_6 + 2) + 0x12;
    }
    FUN_180037000(&local_472,param_6,uVar42);
  }
  else {
    uVar41 = local_614;
    if (param_6 != (undefined8 *)0x0) goto LAB_18000b866;
  }
  puVar29 = FUN_180007760(local_318,(uint)uStack_46a._6_2_);
  psVar32 = (short *)local_9e;
  uVar46 = local_472._4_4_;
  do {
    psVar32 = psVar32 + -1;
    *psVar32 = (short)uVar46 + (short)((ulonglong)uVar46 / 10) * -10 + 0x30;
    uVar46 = (uint)((ulonglong)uVar46 / 10);
  } while (uVar46 != 0);
  FUN_180001830(local_98,(undefined8 *)psVar32,(undefined8 *)local_9e);
  psVar32 = (short *)local_9e;
  uVar42 = (ulonglong)param_3;
  do {
    psVar32 = psVar32 + -1;
    uVar38 = uVar42 / 10;
    *psVar32 = (short)uVar42 + (short)uVar38 * -10 + 0x30;
    uVar42 = uVar38;
  } while ((int)uVar38 != 0);
  FUN_180001830(local_208,(undefined8 *)psVar32,(undefined8 *)local_9e);
  pauVar30 = (undefined1 (*) [32])FUN_180007760((undefined8 *)&local_228,uVar41);
  puVar31 = FUN_180001a30((undefined8 *)&local_248,(undefined1 (*) [32])L"actual_initialize_mode_",
                          pauVar30);
  lVar37 = puVar31[2];
  if ((ulonglong)(puVar31[3] - lVar37) < 7) {
    puVar31 = FUN_180001d30(puVar31,7,(ulonglong)local_3b8 & 0xff,(undefined8 *)L"_flags_",7);
  }
  else {
    puVar31[2] = lVar37 + 7;
    puVar44 = puVar31;
    if (7 < (ulonglong)puVar31[3]) {
      puVar44 = (undefined8 *)*puVar31;
    }
    FUN_180037000((undefined8 *)((longlong)puVar44 + lVar37 * 2),(undefined8 *)L"_flags_",0xe);
    *(undefined2 *)((longlong)puVar44 + (lVar37 + 7) * 2) = 0;
  }
  local_268 = (LPVOID)*puVar31;
  uStack_260 = puVar31[1];
  local_258 = puVar31[2];
  uStack_250 = puVar31[3];
  uVar41 = 0;
  *(undefined2 *)puVar31 = 0;
  puVar31[2] = 0;
  puVar31[3] = 7;
  FUN_180002060(local_378,(ulonglong)local_3b8 & 0xff,&local_268,local_208);
  lVar37 = local_368;
  if (uStack_360 - local_368 < 6) {
    puVar31 = FUN_180001d30(local_378,6,(ulonglong)local_3b8 & 0xff,(undefined8 *)L"_rate_",6);
  }
  else {
    puVar43 = (undefined2 *)local_378;
    if (7 < uStack_360) {
      puVar43 = (undefined2 *)CONCAT62(local_378[0]._2_6_,(undefined2)local_378[0]);
    }
    puVar31 = (undefined8 *)(puVar43 + local_368);
    local_368 = local_368 + 6;
    FUN_180037000(puVar31,(undefined8 *)L"_rate_",0xc);
    puVar43[lVar37 + 6] = 0;
    puVar31 = local_378;
  }
  local_288 = (LPVOID)*puVar31;
  uStack_280 = puVar31[1];
  local_278 = puVar31[2];
  uStack_270 = puVar31[3];
  *(undefined2 *)puVar31 = 0;
  puVar31[2] = 0;
  puVar31[3] = 7;
  FUN_180002060(local_398,(ulonglong)local_3b8 & 0xff,&local_288,local_98);
  lVar37 = local_388;
  if (uStack_380 - local_388 < 6) {
    puVar31 = FUN_180001d30(local_398,6,(ulonglong)local_3b8 & 0xff,(undefined8 *)L"_bits_",6);
  }
  else {
    puVar43 = (undefined2 *)local_398;
    if (7 < uStack_380) {
      puVar43 = (undefined2 *)CONCAT62(local_398[0]._2_6_,(undefined2)local_398[0]);
    }
    puVar31 = (undefined8 *)(puVar43 + local_388);
    local_388 = local_388 + 6;
    FUN_180037000(puVar31,(undefined8 *)L"_bits_",0xc);
    puVar43[lVar37 + 6] = 0;
    puVar31 = local_398;
  }
  local_3b8 = (LPSTR *****)*puVar31;
  pppppCStack_3b0 = (LPSTR ****)puVar31[1];
  local_3a8 = puVar31[2];
  uStack_3a0 = puVar31[3];
  *(undefined2 *)puVar31 = 0;
  puVar31[2] = 0;
  puVar31[3] = 7;
  FUN_180002060((undefined8 *)&local_338,(ulonglong)local_3b8 & 0xff,&local_3b8,puVar29);
  local_608 = (LPSTR *****)&local_338;
  if (7 < uStack_320) {
    local_608 = (LPSTR *****)CONCAT62(uStack_336,local_338);
  }
  local_600 = local_328;
  FUN_1800225c0(&local_608,0);
  if (7 < uStack_320) {
    pvVar19 = (LPVOID)CONCAT62(uStack_336,local_338);
    pvVar35 = pvVar19;
    if ((0xfff < uStack_320 * 2 + 2) &&
       (pvVar35 = *(LPVOID *)((longlong)pvVar19 + -8),
       0x1f < (ulonglong)((longlong)pvVar19 + (-8 - (longlong)pvVar35)))) {
                    /* WARNING: Subroutine does not return */
      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
    }
    thunk_FUN_180030590(pvVar35);
  }
  local_328 = 0;
  uStack_320 = 7;
  local_338 = 0;
  if (7 < uStack_3a0) {
    ppppppCVar36 = local_3b8;
    if ((0xfff < uStack_3a0 * 2 + 2) &&
       (ppppppCVar36 = (LPSTR *****)local_3b8[-1],
       0x1f < (ulonglong)((longlong)local_3b8 + (-8 - (longlong)ppppppCVar36)))) {
                    /* WARNING: Subroutine does not return */
      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
    }
    thunk_FUN_180030590(ppppppCVar36);
  }
  if (7 < uStack_380) {
    pvVar19 = (LPVOID)CONCAT62(local_398[0]._2_6_,(undefined2)local_398[0]);
    pvVar35 = pvVar19;
    if ((0xfff < uStack_380 * 2 + 2) &&
       (pvVar35 = *(LPVOID *)((longlong)pvVar19 + -8),
       0x1f < (ulonglong)((longlong)pvVar19 + (-8 - (longlong)pvVar35)))) {
                    /* WARNING: Subroutine does not return */
      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
    }
    thunk_FUN_180030590(pvVar35);
  }
  local_388 = 0;
  uStack_380 = 7;
  local_398[0]._0_2_ = 0;
  if (7 < uStack_270) {
    pvVar35 = local_288;
    if ((0xfff < uStack_270 * 2 + 2) &&
       (pvVar35 = *(LPVOID *)((longlong)local_288 + -8),
       0x1f < (ulonglong)((longlong)local_288 + (-8 - (longlong)pvVar35)))) {
                    /* WARNING: Subroutine does not return */
      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
    }
    thunk_FUN_180030590(pvVar35);
  }
  if (7 < uStack_360) {
    pvVar19 = (LPVOID)CONCAT62(local_378[0]._2_6_,(undefined2)local_378[0]);
    pvVar35 = pvVar19;
    if ((0xfff < uStack_360 * 2 + 2) &&
       (pvVar35 = *(LPVOID *)((longlong)pvVar19 + -8),
       0x1f < (ulonglong)((longlong)pvVar19 + (-8 - (longlong)pvVar35)))) {
                    /* WARNING: Subroutine does not return */
      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
    }
    thunk_FUN_180030590(pvVar35);
  }
  local_368 = 0;
  uStack_360 = 7;
  local_378[0]._0_2_ = 0;
  if (7 < uStack_250) {
    pvVar35 = local_268;
    if ((0xfff < uStack_250 * 2 + 2) &&
       (pvVar35 = *(LPVOID *)((longlong)local_268 + -8),
       0x1f < (ulonglong)((longlong)local_268 + (-8 - (longlong)pvVar35)))) {
                    /* WARNING: Subroutine does not return */
      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
    }
    thunk_FUN_180030590(pvVar35);
  }
  if (7 < uStack_230) {
    pvVar19 = (LPVOID)CONCAT62(uStack_246,local_248);
    pvVar35 = pvVar19;
    if ((0xfff < uStack_230 * 2 + 2) &&
       (pvVar35 = *(LPVOID *)((longlong)pvVar19 + -8),
       0x1f < (ulonglong)((longlong)pvVar19 + (-8 - (longlong)pvVar35)))) {
                    /* WARNING: Subroutine does not return */
      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
    }
    thunk_FUN_180030590(pvVar35);
  }
  local_238 = 0;
  uStack_230 = 7;
  local_248 = 0;
  if (7 < uStack_210) {
    pvVar19 = (LPVOID)CONCAT62(uStack_226,local_228);
    pvVar35 = pvVar19;
    if ((0xfff < uStack_210 * 2 + 2) &&
       (pvVar35 = *(LPVOID *)((longlong)pvVar19 + -8),
       0x1f < (ulonglong)((longlong)pvVar19 + (-8 - (longlong)pvVar35)))) {
                    /* WARNING: Subroutine does not return */
      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
    }
    thunk_FUN_180030590(pvVar35);
  }
  local_218 = 0;
  uStack_210 = 7;
  local_228 = 0;
  if (7 < local_1f0) {
    pvVar35 = local_208[0];
    if ((0xfff < local_1f0 * 2 + 2) &&
       (pvVar35 = *(LPVOID *)((longlong)local_208[0] + -8),
       0x1f < (ulonglong)((longlong)local_208[0] + (-8 - (longlong)pvVar35)))) {
                    /* WARNING: Subroutine does not return */
      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
    }
    thunk_FUN_180030590(pvVar35);
  }
  if (7 < local_80) {
    pvVar35 = local_98[0];
    if ((0xfff < local_80 * 2 + 2) &&
       (pvVar35 = *(LPVOID *)((longlong)local_98[0] + -8),
       0x1f < (ulonglong)((longlong)local_98[0] + (-8 - (longlong)pvVar35)))) {
                    /* WARNING: Subroutine does not return */
      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
    }
    thunk_FUN_180030590(pvVar35);
  }
  if (7 < local_300) {
    pvVar35 = local_318[0];
    if ((0xfff < local_300 * 2 + 2) &&
       (pvVar35 = *(LPVOID *)((longlong)local_318[0] + -8),
       0x1f < (ulonglong)((longlong)local_318[0] + (-8 - (longlong)pvVar35)))) {
                    /* WARNING: Subroutine does not return */
      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
    }
    thunk_FUN_180030590(pvVar35);
  }
  uVar46 = local_618;
  ppppppCVar36 = local_5e0[0];
  if (((local_478._1_1_ != '\0') && ((local_618 >> 0x12 & 1) != 0)) &&
     (param_6 != (undefined8 *)0x0)) {
    local_5f8 = (LPSTR *****)0x0;
    local_608 = (LPSTR *****)0x0;
    uVar23 = (*DAT_180051480)(param_1,&local_5f8,&local_608);
    uVar42 = (ulonglong)uVar23;
    if ((int)uVar23 < 0) goto LAB_18000c541;
    ppppppCVar36 = local_5f8;
    if ((longlong)local_5f8 < (longlong)local_608) {
      ppppppCVar36 = local_608;
    }
    uVar23 = *(uint *)((longlong)param_6 + 4);
    if ((longlong)ppppppCVar36 < 200000) {
      ppppppCVar36 = (LPSTR *****)0x30d40;
    }
    uVar38 = ((longlong)ppppppCVar36 * (ulonglong)uVar23 + 9999999) / 10000000;
    if ((uVar38 == 0) || (0xffffffff < uVar38)) {
      uVar42 = 0x80070057;
      goto LAB_18000c541;
    }
    local_5e0[0] = (LPSTR *****)0x0;
    local_5f0 = (longlong *)0x0;
    uVar24 = CoCreateInstance((IID *)&DAT_18003b0b8,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_18003b0c8,
                              local_5e0);
    uVar42 = (ulonglong)uVar24;
    if (-1 < (int)uVar24) {
      pppppppuVar39 = &local_498;
      if (7 < uStack_480) {
        pppppppuVar39 = local_498;
      }
      uVar24 = (*(code *)(*local_5e0[0])[5])(local_5e0[0],pppppppuVar39,&local_5f0);
      uVar42 = (ulonglong)uVar24;
      if (-1 < (int)uVar24) {
        uVar42 = 0x88890019;
        param_5 = (LPSTR *****)
                  (((uVar38 & 0xffffffff) * 10000000 + (ulonglong)(uVar23 >> 1)) / (ulonglong)uVar23
                  );
        while( true ) {
          local_3b8 = (LPSTR *****)0x0;
          uVar23 = (*DAT_180051440)(local_5f0,&DAT_18003b758,0x17,0);
          if ((int)uVar23 < 0) {
            uVar42 = (ulonglong)uVar23;
            goto LAB_18000c1f2;
          }
          if (local_3b8 == (LPSTR *****)0x0) break;
          uVar23 = (*DAT_180051448)(local_3b8,1,uVar46);
          if (-1 < (int)uVar23) {
            (*(code *)(*local_3b8)[2])();
            uVar42 = 0;
            goto LAB_18000c1f2;
          }
          if (uVar23 != 0x88890019) {
            (*(code *)(*local_3b8)[2])();
            uVar42 = (ulonglong)uVar23;
            goto LAB_18000c1f2;
          }
          local_618 = 0;
          uVar23 = (*(code *)(*local_3b8)[4])(local_3b8,&local_618);
          (*(code *)(*local_3b8)[2])();
          if (((int)uVar23 < 0) || (local_618 == 0)) {
            uVar42 = 0x8000ffff;
            if ((int)uVar23 < 0) {
              uVar42 = (ulonglong)uVar23;
            }
            goto LAB_18000c1f2;
          }
          ppppppCVar36 = (LPSTR *****)
                         (((ulonglong)local_618 * 10000000 +
                          (ulonglong)(*(uint *)((longlong)param_6 + 4) >> 1)) /
                         (ulonglong)*(uint *)((longlong)param_6 + 4));
          if ((ppppppCVar36 == param_5) || (uVar41 = uVar41 + 1, param_5 = ppppppCVar36, 2 < uVar41)
             ) goto LAB_18000c1f2;
        }
        uVar42 = 0x80004003;
      }
    }
LAB_18000c1f2:
    if (local_5f0 != (longlong *)0x0) {
      (**(code **)(*local_5f0 + 0x10))();
    }
    if (local_5e0[0] != (LPSTR *****)0x0) {
      (*(code *)(*local_5e0[0])[2])();
    }
    uVar41 = (uint)uVar42;
    if ((int)uVar41 < 0) {
      local_5c8 = (LPSTR *****)0x18003b8b0;
      local_5c0 = 0x24;
      FUN_1800225c0(&local_5c8,uVar41);
      puVar27 = (uint *)FUN_180004ae0();
      FUN_180004ec0(puVar27,uVar41);
      goto LAB_18000c541;
    }
    local_448 = param_5;
    if ((longlong)param_5 < 0) {
      psVar32 = FUN_180002010(local_6e,-(longlong)param_5);
      psVar32 = psVar32 + -1;
      *psVar32 = 0x2d;
    }
    else {
      psVar32 = FUN_180002010(local_6e,(ulonglong)param_5);
    }
    FUN_180001830(local_318,(undefined8 *)psVar32,(undefined8 *)local_6e);
    ppppppCVar36 = (LPSTR *****)
                   FUN_180001a30(local_c8,(undefined1 (*) [32])L"exclusive_event_period_",
                                 (undefined1 (*) [32])local_318);
    local_3b8 = ppppppCVar36;
    if ((LPSTR ****)0x7 < ppppppCVar36[3]) {
      local_3b8 = (LPSTR *****)*ppppppCVar36;
    }
    pppppCStack_3b0 = ppppppCVar36[2];
    FUN_1800225c0(&local_3b8,0);
    FUN_180002330((longlong *)local_c8);
    FUN_180002330((longlong *)local_318);
    ppppppCVar36 = param_5;
  }
  local_5f8 = (LPSTR *****)&DAT_1800500b0;
  iVar25 = FUN_180025e38((uint *)&DAT_1800500b0);
  if (iVar25 != 0) {
                    /* WARNING: Subroutine does not return */
    FUN_180026614(5);
  }
  if (DAT_1800500fc == 0x7fffffff) {
    DAT_1800500fc = 0x7ffffffe;
                    /* WARNING: Subroutine does not return */
    FUN_180026614(6);
  }
  local_608 = param_1;
  plVar47 = FUN_180007af0((float *)&DAT_1800514b0,local_5e0,(byte *)&local_608);
  FUN_180008820((undefined8 *)(*plVar47 + 0x18),&local_498);
  FUN_180025e40(0x1800500b0);
  uVar41 = (*DAT_180051448)(param_1,local_614,uVar46,ppppppCVar36);
  cVar33 = -(char)((int)uVar41 >> 0x1f);
  local_478 = CONCAT13(local_478._3_1_,CONCAT12(cVar33,(ushort)local_478)) ^ 0x10000;
  local_618 = 0;
  uVar42 = (ulonglong)uVar41;
  if (cVar33 != '\x01') {
    uVar41 = (*(code *)(*param_1)[4])(param_1);
    if (((int)uVar41 < 0) || (local_618 == 0)) {
      uVar42 = 0x8000ffff;
      if ((int)uVar41 < 0) {
        uVar42 = (ulonglong)uVar41;
      }
      local_478._0_3_ = (uint3)(ushort)local_478;
    }
    else if (local_478._1_1_ != '\0') {
      local_448 = (LPSTR *****)
                  (((ulonglong)local_618 * 10000000 + (ulonglong)(local_472._4_4_ >> 1)) /
                  (ulonglong)local_472._4_4_);
    }
  }
  local_5f8 = (LPSTR *****)&DAT_1800500b0;
  local_430 = local_618;
  iVar25 = FUN_180025e38((uint *)&DAT_1800500b0);
  if (iVar25 != 0) {
                    /* WARNING: Subroutine does not return */
    FUN_180026614(5);
  }
  if (DAT_1800500fc == 0x7fffffff) {
    DAT_1800500fc = 0x7ffffffe;
                    /* WARNING: Subroutine does not return */
    FUN_180026614(6);
  }
  local_608 = param_1;
  plVar47 = FUN_180007af0((float *)&DAT_1800514b0,&local_5c8,(byte *)&local_608);
  FUN_180008820((undefined8 *)(*plVar47 + 0x18),&local_498);
  FUN_180025e40(0x1800500b0);
  pauVar30 = (undefined1 (*) [32])FUN_180004ae0();
  plVar47 = FUN_180003f70(local_318,&local_498);
  FUN_1800049d0(pauVar30,param_1,(uint)uVar42,local_618,plVar47);
  puVar27 = (uint *)FUN_180004ae0();
  FUN_180004db0(puVar27,param_1,(byte)(uVar42 >> 0x1f) ^ 1,param_1,0,(longlong)&local_472);
  local_608 = (LPSTR *****)0x18003b930;
  local_600 = 0x18;
  FUN_1800225c0(&local_608,(uint)uVar42);
LAB_18000c541:
  FUN_180002330((longlong *)&local_498);
  return uVar42;
}
