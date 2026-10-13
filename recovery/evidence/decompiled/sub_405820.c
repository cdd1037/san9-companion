// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x00405820; original name: sub_405820
void __thiscall sub_405820(const unsigned __int8 **this)
{
  HWND Focus; // eax
  CWnd *v3; // eax
  int DlgCtrlID; // eax
  int v5; // ebx
  const unsigned __int8 *v6; // eax
  const unsigned __int8 *v7; // edi
  int v8; // eax
  int v9; // eax
  unsigned int v10; // eax
  int v11; // ebp
  int v12; // ebp
  int v13; // [esp+10h] [ebp-20h]
  char v14[4]; // [esp+14h] [ebp-1Ch] BYREF
  int v15; // [esp+18h] [ebp-18h]
  int v16; // [esp+1Ch] [ebp-14h]
  char v17[4]; // [esp+20h] [ebp-10h] BYREF
  int v18; // [esp+2Ch] [ebp-4h]

  v13 = 0;
  CString::CString((CString *)v14);
  v18 = 0;
  v15 = 0;
  if ( sub_4050B0((CWnd *)this) != 0 )
  {
    Focus = GetFocus();
    v3 = CWnd::FromHandle(Focus);
    DlgCtrlID = CWnd::GetDlgCtrlID(v3);
    v5 = DlgCtrlID;
    v16 = DlgCtrlID;
    if ( DlgCtrlID == 1043 )
    {
      if ( mbscmp(*(this + 7890), &Str2) != 0 )
      {
        CString::operator=(this + 56, this + 7890);
      }
      else
      {
        v8 = CString::Left(this + 56, v17, 4);
        LOBYTE(v18) = 1;
        CString::operator=(this + 56, v8);
        LOBYTE(v18) = 0;
        CString::~CString((CString *)v17);
        if ( mbscmp(*(this + 56), &Str2) == 0 )
          goto LABEL_75;
      }
      v5 = v16;
    }
    else if ( DlgCtrlID == 1135 )
    {
      v9 = CString::Left(this + 83, v17, 4);
      LOBYTE(v18) = 2;
      CString::operator=(this + 83, v9);
      LOBYTE(v18) = 0;
      CString::~CString((CString *)v17);
      if ( mbscmp(*(this + 83), &Str2) == 0 )
        goto LABEL_75;
    }
    else
    {
      if ( DlgCtrlID == 1092 )
      {
        LOBYTE(v10) = *((_BYTE *)this + 31564);
        if ( (_BYTE)v10 == 0xFF )
          LOBYTE(v10) = *((_BYTE *)this + 264);
        v10 = (unsigned __int8)v10;
        v13 = (unsigned __int8)v10;
      }
      else
      {
        if ( DlgCtrlID == 1094 )
        {
          LOBYTE(v10) = *((_BYTE *)this + 31566);
          if ( (_BYTE)v10 == 0xFF )
            LOBYTE(v10) = *((_BYTE *)this + 265);
        }
        else
        {
          if ( DlgCtrlID != 1093 && DlgCtrlID != 1095 )
            goto LABEL_75;
          if ( DlgCtrlID == 1093 )
          {
            LOBYTE(v10) = *((_BYTE *)this + 31565);
            if ( (_BYTE)v10 == 0xFF )
              LOBYTE(v10) = *((_BYTE *)this + 266);
          }
          else
          {
            LOBYTE(v10) = *((_BYTE *)this + 31567);
            if ( (_BYTE)v10 == 0xFF )
              LOBYTE(v10) = *((_BYTE *)this + 267);
          }
        }
        v10 = (unsigned __int8)v10;
        v13 = (unsigned __int8)v10;
      }
      if ( v10 <= 0x5A )
      {
        if ( v10 <= 0x50 )
        {
          if ( v10 <= 0x3C )
          {
            if ( v10 <= 0x32 )
            {
              if ( v10 <= 0x1E )
                v15 = 5;
              else
                v15 = 2;
            }
            else
            {
              v15 = 1;
            }
          }
          else
          {
            v15 = 0;
          }
        }
        else
        {
          v15 = 1;
        }
      }
      else
      {
        v15 = 2;
      }
    }
    v6 = *(this + 86);
    v7 = v6 + 1;
    if ( v6 + 1 >= *(this + 87) )
      v7 = nullptr;
    if ( v7 != v6 )
    {
      do
      {
        if ( v5 == 1043 )
        {
          CString::operator=(v14, (char *)this + 10 * (_DWORD)v7 + 352);
          if ( CString::Find((CString *)v14, (const char *)*(this + 56)) != -1 )
          {
            CString::operator=(this + 7890, this + 56);
            break;
          }
        }
        else
        {
          switch ( v5 )
          {
            case 1135:
              CString::operator=(v14, 8 * *((char *)this + (_DWORD)v7 + 8352) + 4323112);
              if ( CString::Find((CString *)v14, (const char *)*(this + 83)) != -1 )
                goto LABEL_73;
              goto LABEL_61;
            case 1092:
              v11 = *((char *)this + (_DWORD)v7 + 9152);
              break;
            case 1094:
              v11 = *((char *)this + (_DWORD)v7 + 10752);
              break;
            case 1093:
            case 1095:
              if ( v5 == 1093 )
                v11 = *((char *)this + (_DWORD)v7 + 9952);
              else
                v11 = *((char *)this + (_DWORD)v7 + 11552);
              break;
            default:
              goto LABEL_61;
          }
          v12 = v11 - v13;
          if ( v12 < 0 )
            v12 = -v12;
          if ( v12 <= v15 )
          {
            switch ( v5 )
            {
              case 1092:
                *((_BYTE *)this + 31564) = v13;
                break;
              case 1094:
                *((_BYTE *)this + 31566) = v13;
                break;
              case 1093:
                *((_BYTE *)this + 31565) = v13;
                break;
              default:
                *((_BYTE *)this + 31567) = v13;
                break;
            }
            break;
          }
        }
LABEL_61:
        if ( ++v7 >= *(this + 87) )
          v7 = nullptr;
      }
      while ( v7 != *(this + 86) );
    }
LABEL_73:
    if ( *(this + 86) != v7 )
    {
      *(this + 86) = v7;
      sub_405130((CWnd *)this);
    }
  }
LABEL_75:
  v18 = -1;
  CString::~CString((CString *)v14);
}
