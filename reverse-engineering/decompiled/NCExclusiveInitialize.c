/* Ghidra pseudocode; NOT original C++ source and NOT directly compilable.
 * DLL SHA256: 4a9e32cfffaed5b0ec60f3e5844113218245571f66837aae19adb23a149122db
 * Evidence: ev_a45a53d03d55d8e5c4ac774ac966d2c49b7084ae7f5e6ea89916bb7267d31f63
 */

undefined8 NCExclusiveInitialize(void)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  undefined *puVar4;
  ulonglong uVar5;
  HMODULE hModule;
  FARPROC pFVar6;
  FARPROC pFVar7;
  LPSTR *****local_18;
  undefined8 local_10;

                    /* 0x3750  1  NCExclusiveInitialize */
  iVar2 = FUN_180025e38((uint *)&DAT_180050050);
  if (iVar2 != 0) {
                    /* WARNING: Subroutine does not return */
    FUN_180026614(5);
  }
  if (DAT_18005009c != 0x7fffffff) {
    if (DAT_180051382 != '\0') {
      FUN_180025e40(0x180050050);
      return 1;
    }
    uVar3 = FUN_180003450();
    if ((char)uVar3 == '\0') {
      FUN_180025e40(0x180050050);
      uVar3 = 0;
    }
    else {
      AddVectoredExceptionHandler(1,FUN_1800025a0);
      puVar4 = FUN_180004ae0();
      FUN_180004b60((longlong)puVar4);
      uVar5 = FUN_1800240e0();
      if ((int)uVar5 == 0) {
        cVar1 = FUN_18000e5b0();
        if (cVar1 == '\0') {
          FUN_180024350();
          FUN_180025e40(0x180050050);
          uVar3 = 0;
        }
        else {
          hModule = GetModuleHandleW(L"kernel32.dll");
          pFVar6 = GetProcAddress(hModule,"LoadLibraryW");
          pFVar7 = GetProcAddress(hModule,"LoadLibraryExW");
          uVar3 = FUN_180023e40((undefined8 *)pFVar6,FUN_180003300,&DAT_180051370);
          if ((int)uVar3 == 0) {
            uVar3 = FUN_180023e40((undefined8 *)pFVar7,FUN_180003350,&DAT_180051378);
            if ((int)uVar3 == 0) {
              FUN_180024180((longlong)pFVar6);
              FUN_180024180((longlong)pFVar7);
              uVar5 = FUN_180023c90();
              if ((int)uVar5 == 0) {
                FUN_180002440();
                DAT_180051382 = '\x01';
                local_18 = (LPSTR *****)0x18003afb8;
                local_10 = 0xf;
                FUN_1800225c0(&local_18,0);
                FUN_180025e40(0x180050050);
                uVar3 = 1;
              }
              else {
                FUN_1800240c0((longlong)pFVar6);
                FUN_1800240c0((longlong)pFVar7);
                FUN_180024190((longlong)pFVar6);
                FUN_180024190((longlong)pFVar7);
                FUN_180025e40(0x180050050);
                uVar3 = 0;
              }
            }
            else {
              FUN_180024190((longlong)pFVar6);
              FUN_180025e40(0x180050050);
              uVar3 = 0;
            }
          }
          else {
            FUN_180025e40(0x180050050);
            uVar3 = 0;
          }
        }
      }
      else {
        FUN_180025e40(0x180050050);
        uVar3 = 0;
      }
    }
    return uVar3;
  }
  DAT_18005009c = 0x7ffffffe;
                    /* WARNING: Subroutine does not return */
  FUN_180026614(6);
}
