// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x0041A516; original name: ?OnAmbientProperty@CWnd@@UAEHPAVCOleControlSite@@JPAUtagVARIANT@@@Z
// attributes: thunk
int __thiscall CWnd::OnAmbientProperty(CWnd *this, struct COleControlSite *a2, int a3, struct tagVARIANT *a4)
{
  return __imp_?OnAmbientProperty@CWnd@@UAEHPAVCOleControlSite@@JPAUtagVARIANT@@@Z(this, a2, a3, a4);
}
