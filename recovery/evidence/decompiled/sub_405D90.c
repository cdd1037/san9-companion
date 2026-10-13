// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x00405D90; original name: unknown_libname_1
// Microsoft VisualC 2-14/net runtime
_DWORD *unknown_libname_1()
{
  CWinApp::CWinApp((CWinApp *)dword_42EF50, nullptr);
  dword_42EF50[0] = &off_41CCB8;
  return dword_42EF50;
}
