// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x0041A51C; original name: ?PreTranslateMessage@CDialog@@UAEHPAUtagMSG@@@Z
// attributes: thunk
int __thiscall CDialog::PreTranslateMessage(CDialog *this, struct tagMSG *a2)
{
  return __imp_?PreTranslateMessage@CDialog@@UAEHPAUtagMSG@@@Z(this, a2);
}
