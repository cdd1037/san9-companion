// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x00402610; original name: sub_402610
int __thiscall sub_402610(struct CWnd **this)
{
  struct CWnd *v2; // ecx

  sub_419BE0(*(this + 60), 1);
  v2 = *((struct CWnd **)*(this + 60) + 1103);
  *((_BYTE *)this + 245) = 0;
  *(this + 49) = v2;
  return sub_4020A0((CWnd *)this);
}
