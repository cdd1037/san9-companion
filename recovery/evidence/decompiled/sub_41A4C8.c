// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x0041A4C8; original name: ?GetRuntimeClass@CListBox@@UBEPAUCRuntimeClass@@XZ
// attributes: thunk
struct CRuntimeClass *__thiscall CListBox::GetRuntimeClass(CListBox *this)
{
  return __imp_?GetRuntimeClass@CListBox@@UBEPAUCRuntimeClass@@XZ(this);
}
