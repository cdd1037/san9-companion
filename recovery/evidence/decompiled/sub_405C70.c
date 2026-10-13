// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x00405C70; original name: sub_405C70
int __thiscall sub_405C70(CWnd *this)
{
  int result; // eax

  result = sub_4050B0(this);
  if ( result != 0 )
  {
    *((_DWORD *)this + 86) = *((__int16 *)this + 162);
    return sub_405130(this);
  }
  return result;
}
