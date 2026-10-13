// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x004020A0; original name: sub_4020A0
int __thiscall sub_4020A0(CWnd *this)
{
  unsigned __int8 v2; // cl
  unsigned __int8 *v3; // eax

  v2 = *((_BYTE *)this + 245);
  if ( v2 < *((_BYTE *)this + 244) )
  {
    v3 = (unsigned __int8 *)(*((_DWORD *)this + 59) + 6 * v2);
    *((_DWORD *)this + 40) = *v3 & 0xF;
    *((_DWORD *)this + 42) = (*v3 & 0x10) != 0;
    *((_DWORD *)this + 41) = (*v3 & 0x20) != 0;
    *((_DWORD *)this + 43) = *v3 >> 7;
    *((_DWORD *)this + 48) = v3[1];
    *((_DWORD *)this + 44) = v3[2];
    *((_DWORD *)this + 47) = v3[3];
    *((_DWORD *)this + 46) = v3[4];
    *((_DWORD *)this + 45) = v3[5];
    *((_DWORD *)this + 50) = LOBYTE(dword_42D948[2 * v2]);
    *((_DWORD *)this + 51) = BYTE1(dword_42D948[2 * v2]);
    *((_DWORD *)this + 52) = BYTE2(dword_42D948[2 * v2]);
    *((_DWORD *)this + 53) = HIBYTE(dword_42D948[2 * v2]);
    *((_DWORD *)this + 54) = LOBYTE(dword_42D94C[2 * v2]);
    *((_DWORD *)this + 55) = BYTE1(dword_42D94C[2 * v2]);
    *((_DWORD *)this + 56) = BYTE2(dword_42D94C[2 * v2]);
    *((_DWORD *)this + 57) = HIBYTE(dword_42D94C[2 * v2]);
    *((_DWORD *)this + 58) = (unsigned __int8)byte_42DAD8[v2];
    SendMessageA(*((HWND *)this + 32), 0x186u, v2, 0);
  }
  return CWnd::UpdateData(this, 0);
}
