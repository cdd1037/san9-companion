// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x0041A492; original name: ?CompareItem@CListBox@@UAEHPAUtagCOMPAREITEMSTRUCT@@@Z
// attributes: thunk
int __thiscall CListBox::CompareItem(CListBox *this, struct tagCOMPAREITEMSTRUCT *a2)
{
  return __imp_?CompareItem@CListBox@@UAEHPAUtagCOMPAREITEMSTRUCT@@@Z(this, a2);
}
