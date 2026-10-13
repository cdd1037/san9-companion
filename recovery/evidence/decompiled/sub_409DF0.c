// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x00409DF0; original name: sub_409DF0
int __thiscall sub_409DF0(CWnd *this, int a2)
{
  if ( a2 == *((_DWORD *)this + 26) )
    sub_409E10((int)this, 1);
  return CWnd::Default(this);
}
