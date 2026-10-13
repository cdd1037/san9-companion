// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x0041A66C; original name: ??0CFileDialog@@QAE@HPBD0K0PAVCWnd@@@Z
// attributes: thunk
CFileDialog *__thiscall CFileDialog::CFileDialog(
        CFileDialog *this,
        int a2,
        const char *a3,
        const char *a4,
        unsigned int a5,
        const char *a6,
        struct CWnd *a7)
{
  return __imp_??0CFileDialog@@QAE@HPBD0K0PAVCWnd@@@Z(this, a2, a3, a4, a5, a6, a7);
}
