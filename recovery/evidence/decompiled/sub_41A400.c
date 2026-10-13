// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x0041A400; original name: sub_41A400
int __thiscall sub_41A400(_DWORD *this)
{
  int v1; // edx
  int *v3; // eax
  _DWORD *v4; // ecx

  v1 = *(this + 24) - lpAddress;
  if ( v1 == 0 )
    return 0;
  dword_42DDF8 = (int)(this + 1905);
  dword_42DDFC = (int)(this + 925);
  dword_42DE00 = (int)(this + 1180);
  dword_42DE04 = (int)(this + 1181);
  dword_42DE08 = (int)(this + 1207);
  dword_42DE0C = (int)(this + 1208);
  dword_42DE10 = (int)(this + 1303);
  v3 = &dword_42DDF8;
  do
  {
    v4 = (_DWORD *)*v3++;
    *v4 += v1;
  }
  while ( (int)v3 < (int)byte_42ED1C );
  return 1;
}
