/* Ghidra pseudocode; NOT original C++ source and NOT directly compilable.
 * DLL SHA256: 4a9e32cfffaed5b0ec60f3e5844113218245571f66837aae19adb23a149122db
 * Evidence: ev_c24cecd9d0cc3e6333437c94d85386b55da0fc2330275a3ceebcf2ea7bee20bc
 */

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

char FUN_18000e5b0(void)

{
  longlong lVar1;
  undefined8 *puVar2;
  HRESULT HVar3;
  HRESULT HVar4;
  int iVar5;
  undefined8 uVar6;
  ulonglong uVar7;
  longlong *plVar8;
  wchar_t *pwVar9;
  longlong lVar10;
  char cVar11;
  longlong *local_res8;
  longlong *local_res10;
  longlong *local_res18;
  undefined1 (*local_128) [32];
  ulonglong local_120;
  longlong local_118;
  code *local_110;
  undefined8 *local_108;
  undefined8 local_100;
  code *local_f8;
  undefined8 *local_f0;
  undefined8 local_e8;
  code *local_e0;
  undefined8 *local_d8;
  undefined8 local_d0;
  code *local_c8;
  undefined8 *local_c0;
  undefined8 local_b8;
  code *local_b0;
  undefined8 *local_a8;
  undefined8 local_a0;
  code *local_98;
  undefined8 *local_90;
  undefined8 local_88;
  code *local_80;
  undefined8 *local_78;
  undefined8 local_70;
  code *local_68;
  undefined8 *local_60;
  undefined8 local_58;
  code *local_50;
  undefined8 *local_48;
  undefined8 local_40;
  code *local_38;
  undefined8 *local_30;

  HVar3 = CoInitializeEx((LPVOID)0x0,2);
  lVar10 = 0;
  local_res18 = (longlong *)0x0;
  local_res8 = (longlong *)0x0;
  local_res10 = (longlong *)0x0;
  cVar11 = '\0';
  HVar4 = CoCreateInstance((IID *)&DAT_18003b0b8,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_18003b0c8,
                           &local_res18);
  if (((-1 < HVar4) &&
      (iVar5 = (**(code **)(*local_res18 + 0x20))(local_res18,0,1,&local_res8), -1 < iVar5)) &&
     (iVar5 = (**(code **)(*local_res8 + 0x18))(local_res8,&DAT_18003b758,0x17,0,&local_res10),
     -1 < iVar5)) {
    plVar8 = &local_118;
    lVar1 = *local_res10;
    local_118 = *(longlong *)(*local_res8 + 0x18);
    local_110 = FUN_18000a290;
    local_108 = &DAT_180051440;
    local_100 = *(undefined8 *)(lVar1 + 0x18);
    local_f8 = FUN_18000b050;
    local_f0 = &DAT_180051448;
    local_e8 = *(undefined8 *)(lVar1 + 0x70);
    local_e0 = FUN_18000d310;
    local_d8 = &DAT_180051450;
    local_d0 = *(undefined8 *)(lVar1 + 0x50);
    local_c8 = FUN_18000d7e0;
    local_c0 = &DAT_180051458;
    local_b8 = *(undefined8 *)(lVar1 + 0x58);
    local_b0 = FUN_18000dae0;
    local_a8 = &DAT_180051460;
    local_a0 = *(undefined8 *)(lVar1 + 0x60);
    local_98 = FUN_18000d190;
    local_90 = &DAT_180051468;
    local_88 = *(undefined8 *)(lVar1 + 0x10);
    local_80 = FUN_18000cd90;
    local_78 = &DAT_180051470;
    local_70 = *(undefined8 *)(lVar1 + 0x30);
    local_68 = FUN_18000c820;
    local_60 = &DAT_180051478;
    local_58 = *(undefined8 *)(lVar1 + 0x48);
    local_50 = FUN_18000cc10;
    local_48 = &DAT_180051480;
    local_40 = *(undefined8 *)(lVar1 + 0x68);
    local_38 = FUN_18000ae90;
    local_30 = &DAT_180051488;
    do {
      puVar2 = (undefined8 *)*plVar8;
      uVar6 = FUN_180023e40(puVar2,(LPCVOID)plVar8[1],(longlong *)plVar8[2]);
      if ((int)uVar6 != 0) break;
      lVar10 = lVar10 + 1;
      FUN_180024180((longlong)puVar2);
      plVar8 = plVar8 + 3;
    } while (plVar8 != (longlong *)&stack0xffffffffffffffd8);
    if ((lVar10 == 10) && (uVar7 = FUN_180023c90(), (int)uVar7 == 0)) {
      cVar11 = '\x01';
    }
    else {
      cVar11 = '\0';
      if (lVar10 != 0) {
        plVar8 = &local_118;
        do {
          FUN_1800240c0(*plVar8);
          FUN_180024190(*plVar8);
          plVar8 = plVar8 + 3;
          lVar10 = lVar10 + -1;
        } while (lVar10 != 0);
      }
    }
  }
  if (local_res10 != (longlong *)0x0) {
    (**(code **)(*local_res10 + 0x10))();
  }
  if (local_res8 != (longlong *)0x0) {
    (**(code **)(*local_res8 + 0x10))();
  }
  if (local_res18 != (longlong *)0x0) {
    (**(code **)(*local_res18 + 0x10))();
  }
  if (-1 < HVar3) {
    CoUninitialize();
  }
  pwVar9 = L"actual_audio_observer_failed";
  if (cVar11 != '\0') {
    pwVar9 = L"actual_audio_observer_ready";
  }
  local_120 = FUN_18002cb80((undefined1 (*) [32])pwVar9);
  local_128 = (undefined1 (*) [32])pwVar9;
  FUN_1800225c0((LPSTR ******)&local_128,0);
  return cVar11;
}
