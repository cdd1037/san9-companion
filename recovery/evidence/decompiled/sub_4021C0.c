// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x004021C0; original name: sub_4021C0
int __thiscall sub_4021C0(int this)
{
  int result; // eax
  int v3; // ecx
  _BYTE *v4; // eax

  result = CWnd::UpdateData((CWnd *)this, 1);
  if ( result != 0 )
  {
    *(_BYTE *)(*(_DWORD *)(this + 236) + 6 * *(unsigned __int8 *)(this + 245)) = *(_BYTE *)(this + 160)
                                                                               + 16
                                                                               * (*(_BYTE *)(this + 168)
                                                                                + 2
                                                                                * (*(_BYTE *)(this + 164)
                                                                                 + 4 * *(_BYTE *)(this + 172)));
    *(_BYTE *)(*(_DWORD *)(this + 236) + 6 * *(unsigned __int8 *)(this + 245) + 1) = *(_BYTE *)(this + 192);
    *(_BYTE *)(*(_DWORD *)(this + 236) + 6 * *(unsigned __int8 *)(this + 245) + 2) = *(_BYTE *)(this + 176);
    *(_BYTE *)(*(_DWORD *)(this + 236) + 6 * *(unsigned __int8 *)(this + 245) + 3) = *(_BYTE *)(this + 188);
    *(_BYTE *)(*(_DWORD *)(this + 236) + 6 * *(unsigned __int8 *)(this + 245) + 4) = *(_BYTE *)(this + 184);
    *(_BYTE *)(*(_DWORD *)(this + 236) + 6 * *(unsigned __int8 *)(this + 245) + 5) = *(_BYTE *)(this + 180);
    v3 = *(unsigned __int8 *)(this + 245);
    LOBYTE(dword_42D948[2 * v3]) = *(_BYTE *)(this + 200);
    BYTE1(dword_42D948[2 * v3]) = *(_BYTE *)(this + 204);
    BYTE2(dword_42D948[2 * v3]) = *(_BYTE *)(this + 208);
    HIBYTE(dword_42D948[2 * v3]) = *(_BYTE *)(this + 212);
    LOBYTE(dword_42D94C[2 * v3]) = *(_BYTE *)(this + 216);
    BYTE1(dword_42D94C[2 * v3]) = *(_BYTE *)(this + 220);
    v4 = (_BYTE *)(8 * v3 + 4381006);
    *v4 = *(_BYTE *)(this + 224);
    v4[1] = *(_BYTE *)(this + 228);
    byte_42DAD8[*(unsigned __int8 *)(this + 245)] = *(_BYTE *)(this + 232);
    return 1;
  }
  return result;
}
