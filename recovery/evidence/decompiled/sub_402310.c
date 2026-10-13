// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x00402310; original name: sub_402310
LRESULT __thiscall sub_402310(HWND *this)
{
  if ( sub_4021C0((int)this) == 0 )
    return SendMessageA(*(this + 32), 0x186u, *((unsigned __int8 *)this + 245), 0);
  *((_BYTE *)this + 245) = SendMessageA(*(this + 32), 0x188u, 0, 0);
  return sub_4020A0((CWnd *)this);
}
