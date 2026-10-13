// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x0041AAAE; original name: ?AfxWinMain@@YGHPAUHINSTANCE__@@0PADH@Z
// attributes: thunk
int __stdcall AfxWinMain(HINSTANCE a1, HINSTANCE a2, char *a3, int a4)
{
  return __imp_?AfxWinMain@@YGHPAUHINSTANCE__@@0PADH@Z(a1, a2, a3, a4);
}
