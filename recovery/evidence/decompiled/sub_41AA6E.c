// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x0041AA6E; original name: ?AfxInitialize@@YGHHK@Z
int __stdcall AfxInitialize(int a1, unsigned int a2)
{
  struct AFX_MODULE_STATE *ModuleState; // eax

  ModuleState = AfxGetModuleState();
  *((_BYTE *)ModuleState + 20) = a1;
  *((_DWORD *)ModuleState + 1040) = a2;
  if ( a1 == 0 )
    setmbcp(-3);
  return 1;
}
