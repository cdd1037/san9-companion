// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x00402C10; original name: sub_402C10
unsigned __int8 __thiscall sub_402C10(int this)
{
  if ( sub_402BB0(this) == 0 )
    return SendMessageA(*(HWND *)(this + 128), 0x186u, *(unsigned __int8 *)(this + 181), 0);
  *(_BYTE *)(this + 181) = SendMessageA(*(HWND *)(this + 128), 0x188u, 0, 0);
  return sub_402B40((CWnd *)this);
}
