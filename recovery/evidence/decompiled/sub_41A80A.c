// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x0041A80A; original name: ?ReadString@CStdioFile@@UAEHAAVCString@@@Z
// attributes: thunk
int __thiscall CStdioFile::ReadString(CStdioFile *this, struct CString *a2)
{
  return __imp_?ReadString@CStdioFile@@UAEHAAVCString@@@Z(this, a2);
}
