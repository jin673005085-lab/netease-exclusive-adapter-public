/* Ghidra pseudocode; NOT original or compilable C++. Evidence: ev_6197f60f0ed539173313ccc91ab28185d559c688943623bb0d3d405949ae33bb */

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_180018140(longlong *param_1,int param_2,ushort param_3,undefined8 *param_4)

{
  ushort uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 *puVar8;
  undefined8 *puVar9;
  int iVar10;
  ushort *puVar11;
  undefined8 *puVar12;
  undefined8 uVar13;
  ushort uVar14;
  undefined8 *puVar15;
  longlong lVar16;
  undefined8 *puVar17;
  uint uVar18;
  bool bVar19;
  undefined1 auStack_2d8 [48];
  ushort local_2a8 [8];
  ushort local_298 [8];
  undefined8 *local_288;
  undefined8 local_280;
  undefined8 local_168 [35];
  undefined8 local_50;
  ulonglong local_48;

  local_48 = DAT_180050580 ^ (ulonglong)auStack_2d8;
  local_288 = param_4;
  FUN_1800376a0((undefined1 (*) [32])&local_280,0,0x118);
  puVar8 = local_288;
  local_2a8[0] = 0x20;
  local_2a8[1] = 0x20;
  local_2a8[2] = 0x18;
  local_2a8[3] = 0x10;
  local_2a8[4] = 0x20;
  local_2a8[5] = 0x18;
  local_2a8[6] = 0x10;
  local_298[0] = 0x20;
  local_298[1] = 0x18;
  uVar2 = 0;
  if (param_3 == 2) {
    uVar2 = 3;
  }
  local_298[2] = 0x18;
  local_298[3] = 0x10;
  local_298[4] = 0x20;
  local_298[5] = 0x18;
  local_298[6] = 0x10;
  uVar18 = 0;
  puVar11 = (ushort *)((longlong)&local_280 + 2);
  lVar16 = 0;
  do {
    uVar1 = *(ushort *)((longlong)local_2a8 + lVar16);
    uVar14 = 1;
    if (uVar18 < 4) {
      uVar14 = 0xfffe;
    }
    puVar11[-1] = uVar14;
    *puVar11 = param_3;
    *(int *)(puVar11 + 1) = param_2;
    *(uint *)(puVar11 + 3) = (uint)(uVar1 >> 3) * (uint)param_3 * param_2;
    bVar19 = uVar18 < 4;
    uVar18 = uVar18 + 1;
    puVar11[5] = (uVar1 >> 3) * param_3;
    puVar11[6] = uVar1;
    puVar11[7] = -(ushort)bVar19 & 0x16;
    puVar11[8] = *(ushort *)((longlong)local_298 + lVar16);
    *(undefined4 *)(puVar11 + 9) = uVar2;
    puVar11[0xb] = 1;
    puVar11[0xc] = 0;
    puVar11[0xd] = 0;
    puVar11[0xe] = 0x10;
    puVar11[0xf] = 0x80;
    puVar11[0x10] = 0xaa00;
    puVar11[0x11] = 0x3800;
    puVar11[0x12] = 0x719b;
    puVar11 = puVar11 + 0x14;
    lVar16 = lVar16 + 2;
  } while (uVar18 < 7);
  lVar16 = 2;
  puVar17 = &local_280;
  puVar9 = local_168;
  do {
    puVar15 = puVar9;
    puVar12 = puVar17;
    uVar13 = puVar12[1];
    uVar5 = puVar12[2];
    uVar6 = puVar12[3];
    *puVar15 = *puVar12;
    puVar15[1] = uVar13;
    uVar13 = puVar12[4];
    uVar7 = puVar12[5];
    puVar15[2] = uVar5;
    puVar15[3] = uVar6;
    uVar5 = puVar12[6];
    uVar6 = puVar12[7];
    puVar15[4] = uVar13;
    puVar15[5] = uVar7;
    uVar13 = puVar12[8];
    uVar7 = puVar12[9];
    puVar15[6] = uVar5;
    puVar15[7] = uVar6;
    uVar5 = puVar12[10];
    uVar6 = puVar12[0xb];
    puVar15[8] = uVar13;
    puVar15[9] = uVar7;
    uVar13 = puVar12[0xc];
    uVar7 = puVar12[0xd];
    puVar15[10] = uVar5;
    puVar15[0xb] = uVar6;
    uVar5 = puVar12[0xe];
    uVar6 = puVar12[0xf];
    puVar15[0xc] = uVar13;
    puVar15[0xd] = uVar7;
    puVar15[0xe] = uVar5;
    puVar15[0xf] = uVar6;
    lVar16 = lVar16 + -1;
    puVar17 = puVar12 + 0x10;
    puVar9 = puVar15 + 0x10;
  } while (lVar16 != 0);
  uVar2 = *(undefined4 *)((longlong)puVar12 + 0x84);
  uVar3 = *(undefined4 *)(puVar12 + 0x11);
  uVar4 = *(undefined4 *)((longlong)puVar12 + 0x8c);
  uVar13 = puVar12[0x12];
  puVar17 = local_168;
  *(undefined4 *)(puVar15 + 0x10) = *(undefined4 *)(puVar12 + 0x10);
  *(undefined4 *)((longlong)puVar15 + 0x84) = uVar2;
  *(undefined4 *)(puVar15 + 0x11) = uVar3;
  *(undefined4 *)((longlong)puVar15 + 0x8c) = uVar4;
  puVar15[0x12] = uVar13;
  while( true ) {
    uVar13 = (**(code **)(*param_1 + 0x38))(param_1,1,puVar17,0);
    iVar10 = (int)uVar13;
    if (iVar10 == 0) {
      uVar13 = puVar17[1];
      uVar5 = puVar17[2];
      uVar6 = puVar17[3];
      *puVar8 = *puVar17;
      puVar8[1] = uVar13;
      uVar13 = puVar17[4];
      puVar8[2] = uVar5;
      puVar8[3] = uVar6;
      puVar8[4] = uVar13;
      return 0;
    }
    if (((iVar10 != -0x7776fff8) && (iVar10 != 1)) && (iVar10 != -0x7ff8ffa9)) break;
    puVar17 = puVar17 + 5;
    if (puVar17 == &local_50) {
      return 0x88890008;
    }
  }
  return uVar13;
}
