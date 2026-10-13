// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x004016A0; original name: sub_4016A0
unsigned __int8 __thiscall sub_4016A0(int this)
{
  if ( sub_401570(this) == 0 )
    return SendMessageA(*(HWND *)(this + 128), 0x186u, *(unsigned __int8 *)(this + 205), 0);
  *(_BYTE *)(this + 205) = SendMessageA(*(HWND *)(this + 128), 0x188u, 0, 0);
  return sub_4014A0((CWnd *)this);
}
