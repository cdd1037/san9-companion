// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x0041A654; original name: ?WriteString@CStdioFile@@UAEXPBD@Z
// attributes: thunk
void __thiscall CStdioFile::WriteString(CStdioFile *this, const char *a2)
{
  __imp_?WriteString@CStdioFile@@UAEXPBD@Z(this, a2);
}
