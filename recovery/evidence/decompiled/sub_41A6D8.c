// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x0041A6D8; original name: ?Attach@CMenu@@QAEHPAUHMENU__@@@Z
// attributes: thunk
int __thiscall CMenu::Attach(CMenu *this, HMENU a2)
{
  return __imp_?Attach@CMenu@@QAEHPAUHMENU__@@@Z(this, a2);
}
