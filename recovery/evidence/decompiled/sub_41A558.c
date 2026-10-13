// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x0041A558; original name: ?PreCreateWindow@CWnd@@UAEHAAUtagCREATESTRUCTA@@@Z
// attributes: thunk
int __thiscall CWnd::PreCreateWindow(CWnd *this, struct tagCREATESTRUCTA *a2)
{
  return __imp_?PreCreateWindow@CWnd@@UAEHAAUtagCREATESTRUCTA@@@Z(this, a2);
}
