// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x00405CA0; original name: sub_405CA0
int __thiscall sub_405CA0(CWnd *this)
{
  int result; // eax

  result = sub_4050B0(this);
  if ( result != 0 )
  {
    *((_DWORD *)this + 86) = *((__int16 *)this + 163);
    return sub_405130(this);
  }
  return result;
}
