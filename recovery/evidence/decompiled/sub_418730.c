// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x00418730; original name: sub_418730
int __thiscall sub_418730(CWnd *this, unsigned int a2, unsigned int a3, int a4)
{
  int v5; // eax
  int v6; // eax
  int v7; // esi
  _BYTE v9[4]; // [esp+Ch] [ebp-10h] BYREF
  int v10; // [esp+18h] [ebp-4h]

  CString::CString((CString *)v9);
  v5 = *((_DWORD *)this + 31);
  v10 = 0;
  if ( a2 == v5 )
  {
    v6 = *((_DWORD *)this + 33);
    if ( v6 != 0 )
    {
      if ( v6 == 1 && a3 == 2 )
      {
        if ( a4 != 1003 )
        {
          if ( a4 != 0 )
            goto LABEL_15;
          sub_409E10((int)this, 3);
        }
        *((_DWORD *)this + 33) = 0;
      }
    }
    else if ( a3 == 1 )
    {
      if ( a4 != 0 )
        sub_409E10((int)this, 2);
    }
    else if ( a3 == 2 && a4 == 1020 )
    {
      *((_DWORD *)this + 33) = 1;
    }
  }
LABEL_15:
  v7 = CWnd::WindowProc(this, a2, a3, a4);
  v10 = -1;
  CString::~CString((CString *)v9);
  return v7;
}
