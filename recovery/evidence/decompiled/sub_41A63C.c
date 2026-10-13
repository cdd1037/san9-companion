// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x0041A63C; original name: ?GetRuntimeClass@CFileException@@UBEPAUCRuntimeClass@@XZ
// attributes: thunk
struct CRuntimeClass *__thiscall CFileException::GetRuntimeClass(CFileException *this)
{
  return __imp_?GetRuntimeClass@CFileException@@UBEPAUCRuntimeClass@@XZ(this);
}
