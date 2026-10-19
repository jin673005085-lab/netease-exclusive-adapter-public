/* Ghidra pseudocode; NOT original or compilable C++. Evidence: ev_5105817d5ca07dc6b4fec3d48e1caa9a982fc342f53f3df2656ebd6c849187f1 */

undefined8 FUN_180016210(undefined8 param_1,undefined8 *param_2,undefined8 *param_3)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  longlong *plVar3;
  undefined8 *puVar4;
  undefined8 local_38 [4];

  if (param_3 == (undefined8 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    puVar4 = (undefined8 *)0x0;
    *param_3 = 0;
    puVar2 = (undefined8 *)FUN_180026aa4(0x330);
    if (puVar2 != (undefined8 *)0x0) {
      plVar3 = FUN_180003f70(local_38,param_2);
      puVar4 = FUN_180015390(puVar2,param_1,plVar3,FUN_180015ad0);
    }
    *param_3 = puVar4;
    uVar1 = 0;
  }
  return uVar1;
}
