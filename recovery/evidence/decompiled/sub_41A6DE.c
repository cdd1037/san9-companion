// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x0041A6DE; original name: ?GetRuntimeClass@CScrollBar@@UBEPAUCRuntimeClass@@XZ
// attributes: thunk
struct CRuntimeClass *__thiscall CScrollBar::GetRuntimeClass(CScrollBar *this)
{
  return __imp_?GetRuntimeClass@CScrollBar@@UBEPAUCRuntimeClass@@XZ(this);
}
