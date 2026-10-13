// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x0041A7C2; original name: ?GetRuntimeClass@CWinApp@@UBEPAUCRuntimeClass@@XZ
// attributes: thunk
struct CRuntimeClass *__thiscall CWinApp::GetRuntimeClass(CWinApp *this)
{
  return __imp_?GetRuntimeClass@CWinApp@@UBEPAUCRuntimeClass@@XZ(this);
}
