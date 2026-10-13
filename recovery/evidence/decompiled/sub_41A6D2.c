// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x0041A6D2; original name: ?TrackPopupMenu@CMenu@@QAEHIHHPAVCWnd@@PBUtagRECT@@@Z
// attributes: thunk
int __thiscall CMenu::TrackPopupMenu(
        CMenu *this,
        unsigned int a2,
        int a3,
        int a4,
        struct CWnd *a5,
        const struct tagRECT *a6)
{
  return __imp_?TrackPopupMenu@CMenu@@QAEHIHHPAVCWnd@@PBUtagRECT@@@Z(this, a2, a3, a4, a5, a6);
}
