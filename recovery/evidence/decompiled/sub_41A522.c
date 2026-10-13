// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x0041A522; original name: ?GetSuperWndProcAddr@CWnd@@MAEPAP6GJPAUHWND__@@IIJ@ZXZ
// attributes: thunk
int (__stdcall **__thiscall CWnd::GetSuperWndProcAddr(CWnd *this))(HWND, unsigned int, unsigned int, int)
{
  return __imp_?GetSuperWndProcAddr@CWnd@@MAEPAP6GJPAUHWND__@@IIJ@ZXZ(this);
}
