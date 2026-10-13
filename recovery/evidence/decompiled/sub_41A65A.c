// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x0041A65A; original name: ?Open@CStdioFile@@UAEHPBDIPAVCFileException@@@Z
// attributes: thunk
int __thiscall CStdioFile::Open(CStdioFile *this, const char *a2, unsigned int a3, struct CFileException *a4)
{
  return __imp_?Open@CStdioFile@@UAEHPBDIPAVCFileException@@@Z(this, a2, a3, a4);
}
