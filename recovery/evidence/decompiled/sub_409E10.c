// Hex-Rays pseudocode: analysis evidence, NOT a compilable translation unit.
// Sample VA: 0x00409E10; original name: sub_409E10
void __thiscall sub_409E10(int this, int a2)
{
  HWND WindowA; // eax
  int v4; // ecx
  HANDLE v5; // eax
  LPVOID v6; // eax
  LPCVOID *v7; // ebx
  LPCVOID *v8; // ebx
  LPCVOID *v9; // ebx
  char *v10; // ebp
  int v11; // ebx
  LPCVOID *v12; // ebx
  LPCVOID *v13; // ebx
  LPCVOID *v14; // ebx
  LPCVOID *v15; // ebx
  LPCVOID *v16; // ebx
  LPCVOID *v17; // ebx
  LPCVOID *v18; // ebx
  LPCVOID *v19; // ebx
  LPCVOID *v20; // ebx
  LPCVOID *v21; // ebx
  LPCVOID *v22; // ebx
  LPCVOID *v23; // ebx
  LPCVOID *v24; // ebx
  LPCVOID *v25; // ebx
  LPCVOID *v26; // ebx
  LPCVOID *v27; // ebx
  LPCVOID *v28; // ebx
  LPCVOID *v29; // ebx
  int i; // ebx
  int j; // ebx
  int *v32; // ebp
  int v33; // ebx
  int k; // ebx
  UINT v35; // eax
  DWORD v36; // eax
  char *v37; // ebp
  int v38; // ebx
  int *v39; // ebp
  int v40; // ebx
  LPCVOID *v41; // ebx
  LPCVOID *v42; // ebx
  LPVOID *v43; // ebx
  LPCVOID *v44; // ebx
  int m; // ebx
  LPCVOID *v46; // ebx
  int n; // ebx
  LPCVOID *v48; // ebx
  int ii; // ebx
  int jj; // ebx
  int kk; // ebx
  int mm; // ebx
  LPCVOID *v53; // ebx
  LPCVOID *v54; // ebx
  LPCVOID *v55; // ebx
  LPCVOID *v56; // ebx
  LPVOID *v57; // ebx
  LPVOID *v58; // ebx
  BOOL v59; // eax
  int v60; // eax
  int v61; // eax
  int v62; // eax
  int v63; // eax
  int v64; // ecx
  int v65; // ebx
  DWORD v66; // eax
  int v67; // ebp
  DWORD v68; // eax
  _BYTE *v69; // ebp
  unsigned int v70; // eax
  unsigned __int8 *v71; // ebp
  unsigned int v72; // eax
  unsigned int v73; // eax
  unsigned int v74; // eax
  char v75; // al
  int v76; // ebx
  unsigned __int8 *v77; // ebp
  DWORD v78; // eax
  DWORD v79; // eax
  int v80; // eax
  _BYTE *v81; // ecx
  char v82; // dl
  char v83; // al
  int v84; // ebx
  int v85; // ebp
  unsigned int v86; // ecx
  DWORD LastError; // eax
  int v88; // eax
  _WORD *v89; // ecx
  int v90; // eax
  int v91; // eax
  int v92; // edi
  DWORD flOldProtect; // [esp+10h] [ebp-24h] BYREF
  char *v94; // [esp+14h] [ebp-20h] BYREF
  int v95; // [esp+18h] [ebp-1Ch]
  unsigned __int8 *v96; // [esp+1Ch] [ebp-18h]
  unsigned int v97; // [esp+20h] [ebp-14h] BYREF
  int Buffer; // [esp+24h] [ebp-10h] BYREF
  int v99; // [esp+30h] [ebp-4h]

  Buffer = 1;
  CString::CString((CString *)&v94);
  v99 = 0;
  v97 = 0;
  flOldProtect = 0;
  WindowA = FindWindowA(ClassName, nullptr);
  if ( WindowA != nullptr )
  {
    if ( *(HWND *)(this + 108) == WindowA )
    {
      if ( a2 != 4 )
      {
        if ( a2 != 2 && a2 != 3 )
        {
          if ( a2 != 1 )
            goto LABEL_2194;
          goto LABEL_2187;
        }
LABEL_2113:
        if ( *(_DWORD *)(this + 4412) != 0 && *(_DWORD *)(this + 4416) != 0 )
        {
          *(_DWORD *)(this + 4416) = 0;
          v95 = 0;
          v96 = (unsigned __int8 *)(this + 4420);
          v65 = 19192746;
          while ( 1 )
          {
            v66 = v96[1];
            flOldProtect = v66;
            if ( v66 > 0x32 )
              flOldProtect = 50;
            v67 = v95;
            if ( !WriteProcessMemory(
                    *(HANDLE *)(this + 112),
                    (LPVOID)(*(_DWORD *)(this + 4720) + v95),
                    &flOldProtect,
                    1u,
                    nullptr) )
              goto LABEL_2164;
            v68 = v96[3];
            flOldProtect = v68;
            if ( v68 > 0xA )
              flOldProtect = 10;
            if ( !WriteProcessMemory(
                    *(HANDLE *)(this + 112),
                    (LPVOID)(v67 + *(_DWORD *)(this + 4724)),
                    &flOldProtect,
                    1u,
                    nullptr) )
              goto LABEL_2164;
            v69 = v96;
            v70 = *v96 & 0xF;
            v97 = v70;
            flOldProtect = v70 > 2 ? 0 : 1 << (v70 + 1);
            if ( !WriteProcessMemory(*(HANDLE *)(this + 112), (LPVOID)(v65 - 1), &flOldProtect, 1u, nullptr) )
              goto LABEL_2164;
            if ( v97 > 2 )
            {
              flOldProtect = v97 != 3 ? 0 : 0x80;
              if ( !WriteProcessMemory(*(HANDLE *)(this + 112), (LPVOID)v65, &flOldProtect, 1u, nullptr) )
                goto LABEL_2164;
              if ( v97 != 3 )
              {
                flOldProtect = 1 << (v97 - 4);
                if ( !WriteProcessMemory(*(HANDLE *)(this + 112), (LPVOID)(v65 + 1), &flOldProtect, 1u, nullptr) )
                  goto LABEL_2164;
              }
            }
            flOldProtect = 8 * (*v69 & 0x10);
            if ( !WriteProcessMemory(*(HANDLE *)(this + 112), (LPVOID)(v65 + 2), &flOldProtect, 1u, nullptr) )
              goto LABEL_2164;
            flOldProtect = (*v69 & 0x20) != 0;
            if ( !WriteProcessMemory(*(HANDLE *)(this + 112), (LPVOID)(v65 + 3), &flOldProtect, 1u, nullptr) )
              goto LABEL_2164;
            if ( !ReadProcessMemory(*(HANDLE *)(this + 112), (LPCVOID)(v65 + 398), &v97, 1u, nullptr) )
            {
              flOldProtect = 455;
              goto LABEL_2181;
            }
            flOldProtect = v97 | (*v96 >> 7);
            if ( !WriteProcessMemory(*(HANDLE *)(this + 112), (LPVOID)(v65 + 398), &flOldProtect, 1u, nullptr) )
              goto LABEL_2164;
            v71 = v96;
            v72 = v96[4];
            if ( v72 > 0xA )
              v72 = 10;
            flOldProtect = 100 * v72;
            if ( !WriteProcessMemory(*(HANDLE *)(this + 112), (LPVOID)(v65 + 386), &flOldProtect, 4u, nullptr) )
              goto LABEL_2164;
            v73 = v71[5];
            if ( v73 > 0xA )
              v73 = 10;
            flOldProtect = 100 * v73;
            if ( !WriteProcessMemory(*(HANDLE *)(this + 112), (LPVOID)(v65 + 390), &flOldProtect, 4u, nullptr) )
              goto LABEL_2164;
            v74 = v71[2];
            if ( v74 > 0xF )
              v74 = 15;
            flOldProtect = 100 * v74;
            if ( !WriteProcessMemory(*(HANDLE *)(this + 112), (LPVOID)(v65 + 374), &flOldProtect, 4u, nullptr) )
              goto LABEL_2164;
            v65 += 496;
            ++v95;
            v96 = v71 + 6;
            if ( v65 >= 19217546 )
              goto LABEL_2144;
          }
        }
        if ( a2 == 1 )
        {
          v80 = this + 4778;
          v81 = (_BYTE *)(this + 4423);
          do
          {
            v82 = *(_BYTE *)(v80 - 50);
            ++v80;
            *(v81 - 2) = v82;
            *v81 = *(_BYTE *)(v80 - 1);
            v81 += 6;
          }
          while ( v80 + -4778 - this < 50 );
          if ( !WriteProcessMemory(
                  *(HANDLE *)(this + 112),
                  *(LPVOID *)(this + 4720),
                  (LPCVOID)(this + 4728),
                  0x32u,
                  nullptr) )
          {
            flOldProtect = 454;
            goto LABEL_2181;
          }
          if ( !WriteProcessMemory(
                  *(HANDLE *)(this + 112),
                  *(LPVOID *)(this + 4724),
                  (LPCVOID)(this + 4778),
                  0x32u,
                  nullptr) )
          {
LABEL_2164:
            flOldProtect = 454;
            goto LABEL_2181;
          }
        }
LABEL_2144:
        v75 = *(_BYTE *)(this + 4836);
        if ( (v75 & 3) != 0 )
        {
          v76 = 22010700;
          *(_BYTE *)(this + 4836) = v75 & 0xFD;
          v77 = (unsigned __int8 *)(this + 4839);
          while ( 1 )
          {
            v78 = *(v77 - 1);
            flOldProtect = v78;
            if ( v78 > 0x1E )
              flOldProtect = 30;
            if ( !WriteProcessMemory(*(HANDLE *)(this + 112), (LPVOID)(v76 - 24), &flOldProtect, 4u, nullptr) )
              break;
            v79 = *v77;
            flOldProtect = v79;
            if ( v79 > 0x1E )
              flOldProtect = 30;
            if ( !WriteProcessMemory(*(HANDLE *)(this + 112), (LPVOID)v76, &flOldProtect, 4u, nullptr) )
              break;
            flOldProtect = *(unsigned __int16 *)(v77 + 1);
            if ( flOldProtect > 0x5DC )
              flOldProtect = 1500;
            if ( !WriteProcessMemory(*(HANDLE *)(this + 112), (LPVOID)(v76 - 36), &flOldProtect, 4u, nullptr) )
              break;
            v76 += 140;
            v77 += 4;
            if ( v76 >= 22016160 )
              goto LABEL_2166;
          }
          flOldProtect = 456;
          goto LABEL_2181;
        }
LABEL_2166:
        v83 = *(_BYTE *)(this + 4994);
        if ( (v83 & 3) != 0 )
        {
          v95 = 0;
          *(_BYTE *)(this + 4994) = v83 & 0xFD;
          v84 = this + 4996;
          v85 = 22023124;
          while ( 1 )
          {
            flOldProtect = *(_DWORD *)v84 & 0x3F;
            if ( !WriteProcessMemory(*(HANDLE *)(this + 112), (LPVOID)(v85 - 4), &flOldProtect, 1u, nullptr) )
              break;
            flOldProtect = (*(_DWORD *)v84 >> 6) & 0x3F;
            if ( !WriteProcessMemory(*(HANDLE *)(this + 112), (LPVOID)v85, &flOldProtect, 1u, nullptr) )
              break;
            flOldProtect = (*(_DWORD *)v84 >> 12) & 0x3F;
            if ( !WriteProcessMemory(*(HANDLE *)(this + 112), (LPVOID)(v85 + 4), &flOldProtect, 1u, nullptr) )
              break;
            flOldProtect = (*(_DWORD *)v84 >> 18) & 0x3F;
            if ( !WriteProcessMemory(*(HANDLE *)(this + 112), (LPVOID)(v85 + 8), &flOldProtect, 1u, nullptr) )
              break;
            flOldProtect = HIBYTE(*(_DWORD *)v84) & 0x3F;
            if ( !WriteProcessMemory(*(HANDLE *)(this + 112), (LPVOID)(v85 - 8), &flOldProtect, 1u, nullptr) )
              break;
            flOldProtect = *(_BYTE *)(v84 + 4) & 0xF;
            if ( !WriteProcessMemory(
                    *(HANDLE *)(this + 112),
                    (LPVOID)(v95 + *(_DWORD *)(this + 5212)),
                    &flOldProtect,
                    1u,
                    nullptr) )
              break;
            flOldProtect = *(_BYTE *)(v84 + 4) >> 4;
            if ( !WriteProcessMemory(*(HANDLE *)(this + 112), (LPVOID)(v85 + 12), &flOldProtect, 1u, nullptr) )
              break;
            LOWORD(v86) = *(_WORD *)(v84 + 4);
            flOldProtect = (v86 >> 8) & 0xF;
            if ( !WriteProcessMemory(*(HANDLE *)(this + 112), (LPVOID)(v85 + 16), &flOldProtect, 1u, nullptr) )
              break;
            flOldProtect = *(unsigned __int16 *)(v84 + 6);
            if ( !WriteProcessMemory(*(HANDLE *)(this + 112), (LPVOID)(v85 + 20), &flOldProtect, 2u, nullptr) )
              break;
            v85 += 136;
            v84 += 8;
            ++v95;
            if ( v85 >= 22026796 )
              goto LABEL_2178;
          }
        }
        else
        {
          if ( a2 != 1 )
            goto LABEL_2178;
          v88 = 0;
          v89 = (_WORD *)(this + 5000);
          do
          {
            *v89 = (unsigned __int8)byte_42DB0C[v88++];
            v89 += 4;
          }
          while ( v88 < 27 );
          if ( WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 5212), byte_42DB0C, 0x1Bu, nullptr) )
          {
LABEL_2178:
            if ( *(_DWORD *)(this + 296) != 0 && sub_41A1F0(*(_DWORD *)(this + 296)) == 0 )
            {
              flOldProtect = 501;
              goto LABEL_2181;
            }
LABEL_2187:
            v90 = *(_DWORD *)(this + 144) + 1;
            *(_DWORD *)(this + 144) = v90;
            if ( v90 < 1 )
              goto LABEL_2194;
            CString::Format((CString *)&v94, &byte_42ED40, *(_DWORD *)(this + 140));
            v91 = *(_DWORD *)(this + 144);
            if ( v91 > 1 )
            {
              v92 = v91 - 1;
              do
              {
                CString::operator+=(&v94, &unk_42ED3C);
                --v92;
              }
              while ( v92 != 0 );
            }
            if ( *(_DWORD *)(this + 144) == 6 )
              *(_DWORD *)(this + 144) = 0;
LABEL_2193:
            CWnd::SetWindowTextA((CWnd *)(this + 7624), v94);
            goto LABEL_2194;
          }
        }
        flOldProtect = 457;
        goto LABEL_2181;
      }
    }
    else
    {
      v4 = *(_DWORD *)(this + 136) + 1;
      *(_DWORD *)(this + 136) = v4;
      if ( v4 <= 5 )
        goto LABEL_2194;
      *(_DWORD *)(this + 136) = 0;
      *(_DWORD *)(this + 144) = 0;
      *(_DWORD *)(this + 108) = WindowA;
      GetWindowThreadProcessId(WindowA, (LPDWORD)(this + 116));
      v5 = OpenProcess(0x38u, false, *(_DWORD *)(this + 116));
      *(_DWORD *)(this + 112) = v5;
      if ( v5 == nullptr )
      {
        *(_DWORD *)(this + 108) = 0;
        CWnd::SetWindowTextA((CWnd *)(this + 7624), byte_42EDB4);
        goto LABEL_2194;
      }
      if ( (unsigned __int8)sub_409840(this) == 0 )
      {
        *(_DWORD *)(this + 108) = 0;
        CloseHandle(*(HANDLE *)(this + 112));
        *(_DWORD *)(this + 112) = 0;
        CWnd::SetWindowTextA((CWnd *)(this + 7624), byte_42ED9C);
        goto LABEL_2194;
      }
      if ( !VirtualProtectEx(
              *(HANDLE *)(this + 112),
              *(LPVOID *)(this + 7448),
              *(_DWORD *)(this + 7472),
              0x40u,
              &flOldProtect) )
      {
        flOldProtect = 600;
LABEL_2181:
        LastError = GetLastError();
        CString::Format((CString *)&v94, "%d : error=%d", flOldProtect, LastError);
        ++*(_DWORD *)(this + 140);
        *(_DWORD *)(this + 144) = -8;
        goto LABEL_2193;
      }
      if ( !VirtualProtectEx(
              *(HANDLE *)(this + 112),
              *(LPVOID *)(this + 7452),
              *(_DWORD *)(this + 7472),
              4u,
              &flOldProtect) )
      {
        flOldProtect = 601;
        goto LABEL_2181;
      }
      if ( !VirtualProtectEx(
              *(HANDLE *)(this + 112),
              *(LPVOID *)(this + 7456),
              *(_DWORD *)(this + 7472),
              4u,
              &flOldProtect) )
      {
        flOldProtect = 605;
        goto LABEL_2181;
      }
      if ( !VirtualProtectEx(
              *(HANDLE *)(this + 112),
              *(LPVOID *)(this + 7468),
              *(_DWORD *)(this + 7472),
              0x40u,
              &flOldProtect) )
      {
        flOldProtect = 604;
        goto LABEL_2181;
      }
      v6 = VirtualAllocEx(
             *(HANDLE *)(this + 112),
             nullptr,
             *(_DWORD *)(this + 7472) * *(_DWORD *)(this + 7476),
             0x1000u,
             0x40u);
      *(_DWORD *)(this + 96) = v6;
      if ( v6 == nullptr )
      {
        CWnd::SetWindowTextA((CWnd *)(this + 7624), byte_42ED84);
        goto LABEL_2194;
      }
      if ( sub_41A400((_DWORD *)this) != 0 )
        lpAddress = *(_DWORD *)(this + 96);
      *(_DWORD *)(this + 132) = 0;
      v7 = (LPCVOID *)&unk_42F620;
      do
      {
        if ( !WriteProcessMemory(*(HANDLE *)(this + 112), (LPVOID)*(v7 - 2), *v7, (SIZE_T)*(v7 - 1), nullptr) )
        {
          flOldProtect = 19;
          goto LABEL_2181;
        }
        v7 += 3;
      }
      while ( (int)v7 < (int)dword_42F650 );
      v8 = dword_42F720;
      do
      {
        if ( !WriteProcessMemory(*(HANDLE *)(this + 112), (LPVOID)*(v8 - 2), *v8, (SIZE_T)*(v8 - 1), nullptr) )
        {
          flOldProtect = 35;
          goto LABEL_2181;
        }
        v8 += 3;
      }
      while ( (int)v8 < (int)&dword_42F744 );
      v9 = dword_42F698;
      do
      {
        if ( !WriteProcessMemory(*(HANDLE *)(this + 112), (LPVOID)*(v9 - 2), *v9, (SIZE_T)*(v9 - 1), nullptr) )
        {
          flOldProtect = 23;
          goto LABEL_2181;
        }
        v9 += 3;
      }
      while ( (int)v9 < (int)dword_42F6C8 );
      v10 = (char *)&unk_41F930;
      v11 = 0;
      do
      {
        if ( !WriteProcessMemory(*(HANDLE *)(this + 112), (LPVOID)dword_41F920[v11], v10, dword_41F928[v11], nullptr) )
        {
          flOldProtect = 57;
          goto LABEL_2181;
        }
        v10 += 16;
        ++v11;
      }
      while ( (int)v10 < (int)byte_41F950 );
      v12 = (LPCVOID *)&unk_42F748;
      do
      {
        if ( !WriteProcessMemory(*(HANDLE *)(this + 112), (LPVOID)*(v12 - 2), *v12, (SIZE_T)*(v12 - 1), nullptr) )
        {
          flOldProtect = 44;
          goto LABEL_2181;
        }
        v12 += 3;
      }
      while ( (int)v12 < (int)&dword_42F76C );
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), lpBaseAddress, &unk_42171C, 0xFu, nullptr) )
      {
        flOldProtect = 24;
        goto LABEL_2181;
      }
      v13 = (LPCVOID *)&unk_42F6F0;
      do
      {
        if ( !WriteProcessMemory(*(HANDLE *)(this + 112), (LPVOID)*(v13 - 2), *v13, (SIZE_T)*(v13 - 1), nullptr) )
        {
          flOldProtect = 30;
          goto LABEL_2181;
        }
        v13 += 3;
      }
      while ( (int)v13 < (int)dword_42F708 );
      v14 = dword_42F7D8;
      do
      {
        if ( !WriteProcessMemory(*(HANDLE *)(this + 112), (LPVOID)*(v14 - 2), *v14, (SIZE_T)*(v14 - 1), nullptr) )
        {
          flOldProtect = 26;
          goto LABEL_2181;
        }
        v14 += 3;
      }
      while ( (int)v14 < (int)dword_42F7F0 );
      v15 = (LPCVOID *)&unk_42F588;
      do
      {
        if ( !WriteProcessMemory(*(HANDLE *)(this + 112), (LPVOID)*(v15 - 2), *v15, (SIZE_T)*(v15 - 1), nullptr) )
        {
          flOldProtect = 10;
          goto LABEL_2181;
        }
        v15 += 3;
      }
      while ( (int)v15 < (int)dword_42F5A0 );
      v16 = dword_42F6C8;
      do
      {
        if ( !WriteProcessMemory(*(HANDLE *)(this + 112), (LPVOID)*(v16 - 2), *v16, (SIZE_T)*(v16 - 1), nullptr) )
        {
          flOldProtect = 27;
          goto LABEL_2181;
        }
        v16 += 3;
      }
      while ( (int)v16 < (int)&dword_42F6EC );
      v17 = (LPCVOID *)&dword_42F610;
      do
      {
        if ( !WriteProcessMemory(*(HANDLE *)(this + 112), (LPVOID)*(v17 - 2), *v17, (SIZE_T)*(v17 - 1), nullptr) )
        {
          flOldProtect = 16;
          goto LABEL_2181;
        }
        v17 += 3;
      }
      while ( (int)v17 < (int)&dword_42F61C );
      v18 = (LPCVOID *)&unk_42F770;
      do
      {
        if ( !WriteProcessMemory(*(HANDLE *)(this + 112), (LPVOID)*(v18 - 2), *v18, (SIZE_T)*(v18 - 1), nullptr) )
        {
          flOldProtect = 46;
          goto LABEL_2181;
        }
        v18 += 3;
      }
      while ( (int)v18 < (int)&dword_42F794 );
      v19 = dword_42F708;
      do
      {
        if ( !WriteProcessMemory(*(HANDLE *)(this + 112), (LPVOID)*(v19 - 2), *v19, (SIZE_T)*(v19 - 1), nullptr) )
        {
          flOldProtect = 33;
          goto LABEL_2181;
        }
        v19 += 3;
      }
      while ( (int)v19 < (int)dword_42F720 );
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_421640, &unk_421644, 0xEu, nullptr) )
      {
        flOldProtect = 29;
        goto LABEL_2181;
      }
      v20 = dword_42F5A0;
      do
      {
        if ( !WriteProcessMemory(*(HANDLE *)(this + 112), (LPVOID)*(v20 - 2), *v20, (SIZE_T)*(v20 - 1), nullptr) )
        {
          flOldProtect = 13;
          goto LABEL_2181;
        }
        v20 += 3;
      }
      while ( (int)v20 < (int)&dword_42F5DC );
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_420510, &unk_420514, 9u, nullptr) )
      {
        flOldProtect = 38;
        goto LABEL_2181;
      }
      v21 = dword_42F668;
      do
      {
        if ( !WriteProcessMemory(*(HANDLE *)(this + 112), (LPVOID)*(v21 - 2), *v21, (SIZE_T)*(v21 - 1), nullptr) )
        {
          flOldProtect = 21;
          goto LABEL_2181;
        }
        v21 += 3;
      }
      while ( (int)v21 < (int)dword_42F680 );
      v22 = (LPCVOID *)&unk_42F7C0;
      do
      {
        if ( !WriteProcessMemory(*(HANDLE *)(this + 112), (LPVOID)*(v22 - 2), *v22, (SIZE_T)*(v22 - 1), nullptr) )
        {
          flOldProtect = 48;
          goto LABEL_2181;
        }
        v22 += 3;
      }
      while ( (int)v22 < (int)dword_42F7D8 );
      v23 = (LPCVOID *)&dword_42F5E0;
      do
      {
        if ( !WriteProcessMemory(*(HANDLE *)(this + 112), (LPVOID)*(v23 - 2), *v23, (SIZE_T)*(v23 - 1), nullptr) )
        {
          flOldProtect = 15;
          goto LABEL_2181;
        }
        v23 += 3;
      }
      while ( (int)v23 < (int)&dword_42F5EC );
      v24 = (LPCVOID *)&dword_42F5F0;
      do
      {
        if ( !WriteProcessMemory(*(HANDLE *)(this + 112), (LPVOID)*(v24 - 2), *v24, (SIZE_T)*(v24 - 1), nullptr) )
        {
          flOldProtect = 17;
          goto LABEL_2181;
        }
        v24 += 3;
      }
      while ( (int)v24 < (int)&dword_42F5FC );
      v25 = (LPCVOID *)&unk_42F798;
      do
      {
        if ( !WriteProcessMemory(*(HANDLE *)(this + 112), (LPVOID)*(v25 - 2), *v25, (SIZE_T)*(v25 - 1), nullptr) )
        {
          flOldProtect = 47;
          goto LABEL_2181;
        }
        v25 += 3;
      }
      while ( (int)v25 < (int)&dword_42F7BC );
      v26 = (LPCVOID *)&dword_42F600;
      do
      {
        if ( !WriteProcessMemory(*(HANDLE *)(this + 112), (LPVOID)*(v26 - 2), *v26, (SIZE_T)*(v26 - 1), nullptr) )
        {
          flOldProtect = 18;
          goto LABEL_2181;
        }
        v26 += 3;
      }
      while ( (int)v26 < (int)&dword_42F60C );
      v27 = dword_42F7F0;
      do
      {
        if ( !WriteProcessMemory(*(HANDLE *)(this + 112), (LPVOID)*(v27 - 2), *v27, (SIZE_T)*(v27 - 1), nullptr) )
        {
          flOldProtect = 3;
          goto LABEL_2181;
        }
        v27 += 3;
      }
      while ( (int)v27 < (int)&dword_42F808 );
      v28 = dword_42F680;
      do
      {
        if ( !WriteProcessMemory(*(HANDLE *)(this + 112), (LPVOID)*(v28 - 2), *v28, (SIZE_T)*(v28 - 1), nullptr) )
        {
          flOldProtect = 22;
          goto LABEL_2181;
        }
        v28 += 3;
      }
      while ( (int)v28 < (int)dword_42F698 );
      v29 = dword_42F650;
      do
      {
        if ( !WriteProcessMemory(*(HANDLE *)(this + 112), (LPVOID)*(v29 - 2), *v29, (SIZE_T)*(v29 - 1), nullptr) )
        {
          flOldProtect = 20;
          goto LABEL_2181;
        }
        v29 += 3;
      }
      while ( (int)v29 < (int)dword_42F668 );
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_4215D4, &unk_4215D8, 8u, nullptr) )
      {
        flOldProtect = 25;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_421608, &unk_42160C, 9u, nullptr) )
      {
        flOldProtect = 4;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_422598, &unk_42259C, 9u, nullptr) )
      {
        flOldProtect = 14;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_423888, &unk_42388C, 0xBu, nullptr) )
      {
        flOldProtect = 36;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_4244C0, &unk_4244C4, 0xFu, nullptr) )
      {
        flOldProtect = 52;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_422D60, &unk_422D64, 0xBu, nullptr) )
      {
        flOldProtect = 54;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_425A10, &unk_425A14, 0xFu, nullptr) )
      {
        flOldProtect = 45;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F0D0, &unk_4298B8, 0x36u, nullptr) )
      {
        flOldProtect = 55;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F0CC, &unk_429918, 0x14u, nullptr) )
      {
        flOldProtect = 1154;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_420014, &unk_420018, 0xDu, nullptr) )
      {
        flOldProtect = 56;
        goto LABEL_2181;
      }
      for ( i = 0; i < 4; ++i )
      {
        if ( !WriteProcessMemory(
                *(HANDLE *)(this + 112),
                (LPVOID)dword_42B890[i],
                (char *)&unk_42B8C0 + dword_42B8B0[i],
                dword_42B8A0[i],
                nullptr) )
        {
          flOldProtect = 60;
          goto LABEL_2181;
        }
      }
      for ( j = 0; j < 4; ++j )
      {
        if ( !WriteProcessMemory(
                *(HANDLE *)(this + 112),
                (LPVOID)dword_42B908[j],
                (char *)&unk_42B938 + dword_42B928[j],
                dword_42B918[j],
                nullptr) )
        {
          flOldProtect = 61;
          goto LABEL_2181;
        }
      }
      v32 = (int *)&unk_42B990;
      v33 = 0;
      do
      {
        if ( !WriteProcessMemory(*(HANDLE *)(this + 112), (LPVOID)dword_42B970[v33], v32, dword_42B980[v33], nullptr) )
        {
          flOldProtect = 62;
          goto LABEL_2181;
        }
        v32 += 4;
        ++v33;
      }
      while ( (int)v32 < (int)dword_42B9D0 );
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F56C, &unk_4201BC, 0x20u, nullptr) )
      {
        flOldProtect = 631;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F568, &unk_4201DC, 0x20u, nullptr) )
      {
        flOldProtect = 766;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F3DC, &unk_423D8C, 0x18u, nullptr) )
      {
        flOldProtect = 808;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7620), &unk_41CD60, 0x4Du, nullptr) )
      {
        flOldProtect = 450;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 5216), &unk_42DDE0, 0xCu, nullptr) )
      {
        flOldProtect = 480;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_420008, &unk_42000C, 8u, nullptr) )
      {
        flOldProtect = 481;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F578, &unk_420054, 0x39u, nullptr) )
      {
        flOldProtect = 613;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F564, &unk_4201FC, 0x86u, nullptr) )
      {
        flOldProtect = 633;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F560, &unk_4202B0, 0xF4u, nullptr) )
      {
        flOldProtect = 1096;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F530, &unk_420BE8, 0x8Fu, nullptr) )
      {
        flOldProtect = 649;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F514, &unk_421230, 0x2D4u, nullptr) )
      {
        flOldProtect = 663;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F50C, &unk_421680, 0x6Au, nullptr) )
      {
        flOldProtect = 669;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F508, &unk_421800, 0x52u, nullptr) )
      {
        flOldProtect = 671;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F4F8, &unk_421B30, 0x2Fu, nullptr) )
      {
        flOldProtect = 679;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F4E8, &unk_421C84, 0x85u, nullptr) )
      {
        flOldProtect = 687;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F4D8, &unk_421F40, 0x3Fu, nullptr) )
      {
        flOldProtect = 692;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F4CC, &unk_4220E0, 0x26u, nullptr) )
      {
        flOldProtect = 698;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F4E4, &unk_421D38, 0x1Au, nullptr) )
      {
        flOldProtect = 709;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F4DC, &unk_421F00, 0x1Eu, nullptr) )
      {
        flOldProtect = 717;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F104, &unk_4290E8, 0x26u, nullptr) )
      {
        flOldProtect = 1109;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F4B4, &unk_4223A8, 0xDu, nullptr) )
      {
        flOldProtect = 725;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F4A4, &unk_422550, 0x20u, nullptr) )
      {
        flOldProtect = 733;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F4A0, &unk_4225D0, 0x2Fu, nullptr) )
      {
        flOldProtect = 735;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F490, &unk_422760, 0x31u, nullptr) )
      {
        flOldProtect = 743;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F48C, &unk_4227C0, 0x66u, nullptr) )
      {
        flOldProtect = 750;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F480, &unk_422970, 0x17u, nullptr) )
      {
        flOldProtect = 757;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F46C, &unk_422AD8, 0x5Cu, nullptr) )
      {
        flOldProtect = 685;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F458, &unk_422CD8, 0x5Du, nullptr) )
      {
        flOldProtect = 767;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F450, &unk_422E90, 0x28u, nullptr) )
      {
        flOldProtect = 775;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F43C, &unk_423110, 0x66u, nullptr) )
      {
        flOldProtect = 783;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F3D8, &unk_423DA4, 0x20u, nullptr) )
      {
        flOldProtect = 791;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F40C, &unk_4237A8, 0x18u, nullptr) )
      {
        flOldProtect = 797;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F3EC, &unk_423A68, 0xA6u, nullptr) )
      {
        flOldProtect = 635;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F3AC, &unk_424298, 0x4Fu, nullptr) )
      {
        flOldProtect = 815;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F3A4, &unk_424420, 0x1Du, nullptr) )
      {
        flOldProtect = 817;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F3B4, &unk_424120, 0xC3u, nullptr) )
      {
        flOldProtect = 825;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F3C8, &unk_423EC8, 0x2Fu, nullptr) )
      {
        flOldProtect = 832;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F464, &unk_422BB0, 0x3Cu, nullptr) )
      {
        flOldProtect = 839;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F378, &unk_424870, 0xBAu, nullptr) )
      {
        flOldProtect = 852;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F3F4, &unk_4239F8, 0x10u, nullptr) )
      {
        flOldProtect = 860;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F3F0, &unk_423A30, 0x10u, nullptr) )
      {
        flOldProtect = 860;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F424, &unk_4233A8, 0x81u, nullptr) )
      {
        flOldProtect = 867;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F38C, &unk_424650, 0x24u, nullptr) )
      {
        flOldProtect = 876;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F340, &unk_425170, 0x28u, nullptr) )
      {
        flOldProtect = 903;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F330, &unk_4252F8, 0x28u, nullptr) )
      {
        flOldProtect = 909;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F2C0, &unk_425530, 0x50u, nullptr) )
      {
        flOldProtect = 920;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F350, &unk_424CD8, 0x34u, nullptr) )
      {
        flOldProtect = 928;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F298, &unk_425A50, 0x26u, nullptr) )
      {
        flOldProtect = 941;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F294, &unk_425B18, 0x12u, nullptr) )
      {
        flOldProtect = 943;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F274, &unk_425EA0, 0xBDu, nullptr) )
      {
        flOldProtect = 958;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F264, &unk_426108, 0x118u, nullptr) )
      {
        flOldProtect = 966;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F254, &unk_4264E8, 0x2Eu, nullptr) )
      {
        flOldProtect = 972;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F244, &unk_426A64, 0x82u, nullptr) )
      {
        flOldProtect = 979;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F238, &unk_426C20, 0x6Au, nullptr) )
      {
        flOldProtect = 984;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F224, &unk_426E40, 0x16u, nullptr) )
      {
        flOldProtect = 990;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F1D4, &unk_4277A8, 0xB5u, nullptr) )
      {
        flOldProtect = 996;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F1C8, &unk_427940, 0x3Au, nullptr) )
      {
        flOldProtect = 1001;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F1B8, &unk_427A88, 0x7Au, nullptr) )
      {
        flOldProtect = 1008;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F354, &unk_424C98, 0x16u, nullptr) )
      {
        flOldProtect = 1013;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F19C, &unk_427DC8, 0x1Fu, nullptr) )
      {
        flOldProtect = 1019;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F190, &unk_427F38, 0x6Au, nullptr) )
      {
        flOldProtect = 1027;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F220, &unk_426E80, 0x1Bu, nullptr) )
      {
        flOldProtect = 1034;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F208, &unk_4270E4, 0x3Eu, nullptr) )
      {
        flOldProtect = 1040;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F1F0, &unk_4272E0, 0x18u, nullptr) )
      {
        flOldProtect = 1053;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F1E4, &unk_4273F0, 0x63u, nullptr) )
      {
        flOldProtect = 1062;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F17C, &unk_428360, 0xA9u, nullptr) )
      {
        flOldProtect = 1066;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F570, &unk_4201A8, 0x14u, nullptr) )
      {
        flOldProtect = 1071;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F154, &unk_428728, 0x72u, nullptr) )
      {
        flOldProtect = 1077;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F130, &unk_428B88, 0x26u, nullptr) )
      {
        flOldProtect = 1090;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F120, &unk_428E90, 0x2Eu, nullptr) )
      {
        flOldProtect = 1099;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F110, &unk_428FD8, 0x4Cu, nullptr) )
      {
        flOldProtect = 1103;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F100, &unk_429138, 0x35u, nullptr) )
      {
        flOldProtect = 1115;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F0FC, &unk_429190, 0x10u, nullptr) )
      {
        flOldProtect = 1117;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F0F8, &unk_429220, 0x9Au, nullptr) )
      {
        flOldProtect = 1113;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F0F4, &unk_4292E8, 0x62u, nullptr) )
      {
        flOldProtect = 1126;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F0F0, &unk_429378, 0x28u, nullptr) )
      {
        flOldProtect = 1128;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F0EC, &unk_4293D0, 0x13u, nullptr) )
      {
        flOldProtect = 1130;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F0E8, &unk_429410, 0x67u, nullptr) )
      {
        flOldProtect = 1132;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F0E4, &unk_4294F0, 0xF4u, nullptr) )
      {
        flOldProtect = 1137;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F0E0, &unk_429610, 0x5Au, nullptr) )
      {
        flOldProtect = 1139;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F0DC, &unk_429690, 0x70u, nullptr) )
      {
        flOldProtect = 1141;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F0D8, &unk_429728, 0x48u, nullptr) )
      {
        flOldProtect = 1143;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F0D4, &unk_429798, 0xF4u, nullptr) )
      {
        flOldProtect = 1156;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F070, &unk_42B3F0, 0xECu, nullptr) )
      {
        flOldProtect = 1158;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F06C, &unk_42B5C8, 0x98u, nullptr) )
      {
        flOldProtect = 1172;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42B700, lpBuffer, nSize, nullptr) )
      {
        flOldProtect = 1182;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F068, &unk_42B718, 0x4Fu, nullptr) )
      {
        flOldProtect = 1168;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F064, aQhld, 0x2Cu, nullptr) )
      {
        flOldProtect = 1177;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F060, &unk_42B7BC, 0x40u, nullptr) )
      {
        flOldProtect = 1178;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F05C, &unk_42B850, 0x17u, nullptr) )
      {
        flOldProtect = 1180;
        goto LABEL_2181;
      }
      for ( k = 0; k < 6; ++k )
      {
        if ( !WriteProcessMemory(
                *(HANDLE *)(this + 112),
                (LPVOID)dword_42B9D0[k],
                (char *)&unk_42BA18 + dword_42BA00[k],
                dword_42B9E8[k],
                nullptr) )
        {
          flOldProtect = 63;
          goto LABEL_2181;
        }
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F058, &unk_42BA48, 0x358u, nullptr) )
      {
        flOldProtect = 1184;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F054, &unk_42BDE0, 0x1A0u, nullptr) )
      {
        flOldProtect = 1186;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F050, &unk_42BFA8, 0xA0u, nullptr) )
      {
        flOldProtect = 1212;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F04C, &unk_42C070, 0xC4u, nullptr) )
      {
        flOldProtect = 1188;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F048, &unk_42C4F0, 0x4Eu, nullptr) )
      {
        flOldProtect = 1214;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F044, &unk_42C568, 0x2Eu, nullptr) )
      {
        flOldProtect = 1216;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F040, &unk_42C5C0, 0x2Au, nullptr) )
      {
        flOldProtect = 1190;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), off_42C7C8, &unk_42C7CC, 8u, nullptr) )
      {
        flOldProtect = 1193;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F03C, &dword_42C7D4, 0xBEu, nullptr) )
      {
        flOldProtect = 1199;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F038, &unk_42C894, 0x88u, nullptr) )
      {
        flOldProtect = 1197;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F034, &unk_42C9D0, 0x20u, nullptr) )
      {
        flOldProtect = 1195;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F030, &unk_42CA18, 0x2Eu, nullptr) )
      {
        flOldProtect = 1204;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F02C, &unk_42CC90, 0x72u, nullptr) )
      {
        flOldProtect = 1210;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F024, &unk_42CE68, 0x6Eu, nullptr) )
      {
        flOldProtect = 1220;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F020, &unk_42CFF0, 0x9Eu, nullptr) )
      {
        flOldProtect = 1222;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F01C, aHX, 0x84u, nullptr) )
      {
        flOldProtect = 1224;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F018, &unk_42D568, 0xAEu, nullptr) )
      {
        flOldProtect = 1228;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F0A8, &unk_42A1B8, 0x24u, nullptr) )
      {
        flOldProtect = 274;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F0A4, &unk_42A1DC, 0x34u, nullptr) )
      {
        flOldProtect = 275;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F0A0, &unk_42A210, 0xECu, nullptr) )
      {
        flOldProtect = 276;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F09C, &unk_42A2FC, 0x112u, nullptr) )
      {
        flOldProtect = 277;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F098, &unk_42A410, 0x13Eu, nullptr) )
      {
        flOldProtect = 278;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F094, &unk_42A578, 0x32u, nullptr) )
      {
        flOldProtect = 283;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F090, &unk_42A5D8, 0x18Cu, nullptr) )
      {
        flOldProtect = 285;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F08C, &unk_42A798, 0x6C0u, nullptr) )
      {
        flOldProtect = 296;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F088, &unk_42AE58, 0x98u, nullptr) )
      {
        flOldProtect = 297;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F084, &unk_42AEF0, 0x9Cu, nullptr) )
      {
        flOldProtect = 280;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F080, &unk_42AFB8, 0xFCu, nullptr) )
      {
        flOldProtect = 287;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F07C, asc_42B0B4, 0xEAu, nullptr) )
      {
        flOldProtect = 290;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F078, &unk_42B1C8, 0x9Eu, nullptr) )
      {
        flOldProtect = 292;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F074, &unk_42B2B8, 0xBCu, nullptr) )
      {
        flOldProtect = 294;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F0C8, sub_429958, 0x80u, nullptr) )
      {
        flOldProtect = 85;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F0C4, &unk_4299D8, 0xBAu, nullptr) )
      {
        flOldProtect = 95;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F0C0, &unk_429D18, 0x88u, nullptr) )
      {
        flOldProtect = 96;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F0BC, &unk_429DC8, 0x14u, nullptr) )
      {
        flOldProtect = 83;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F0B8, &unk_429DDC, 0x88u, nullptr) )
      {
        flOldProtect = 73;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F0B4, &unk_42A048, 0x1Au, nullptr) )
      {
        flOldProtect = 632;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F0B0, &unk_42A098, 0x6Eu, nullptr) )
      {
        flOldProtect = 97;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F0AC, &unk_42A158, 0x34u, nullptr) )
      {
        flOldProtect = 98;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F55C, &unk_4203A4, 0x49u, nullptr) )
      {
        flOldProtect = 620;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F540, &unk_4209C0, 0x59u, nullptr) )
      {
        flOldProtect = 642;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F534, &unk_420B80, 0x40u, nullptr) )
      {
        flOldProtect = 647;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F524, &unk_420E80, 0x27u, nullptr) )
      {
        flOldProtect = 654;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F51C, &unk_420FF8, 0x72u, nullptr) )
      {
        flOldProtect = 658;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F504, &unk_4218A8, 0x6Au, nullptr) )
      {
        flOldProtect = 674;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F4F4, &unk_421B88, 0x2Eu, nullptr) )
      {
        flOldProtect = 681;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F4E0, &unk_421DD8, 0xA7u, nullptr) )
      {
        flOldProtect = 694;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F4C4, &unk_422170, 0x84u, nullptr) )
      {
        flOldProtect = 707;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F4B0, &unk_4223E0, 0x78u, nullptr) )
      {
        flOldProtect = 727;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F498, &unk_422684, 0x6Eu, nullptr) )
      {
        flOldProtect = 737;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F47C, &unk_4229B0, 0x10u, nullptr) )
      {
        flOldProtect = 759;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F468, &unk_422B60, 0x4Du, nullptr) )
      {
        flOldProtect = 765;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F454, &unk_422D98, 0xCDu, nullptr) )
      {
        flOldProtect = 769;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F444, &unk_422F80, 0x24u, nullptr) )
      {
        flOldProtect = 777;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F438, &unk_4231A8, 0x5Cu, nullptr) )
      {
        flOldProtect = 786;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F428, &unk_423350, 0x2Bu, nullptr) )
      {
        flOldProtect = 793;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F404, &unk_423828, 0x35u, nullptr) )
      {
        flOldProtect = 799;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F3E8, &unk_423B38, 0x1A2u, nullptr) )
      {
        flOldProtect = 805;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F3D4, &unk_423DF0, 0x54u, nullptr) )
      {
        flOldProtect = 809;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F3A0, &unk_424468, 0x29u, nullptr) )
      {
        flOldProtect = 819;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F3D0, &unk_423E70, 0xCu, nullptr) )
      {
        flOldProtect = 827;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F3C0, &unk_423F80, 0x29u, nullptr) )
      {
        flOldProtect = 834;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F398, &unk_424560, 0x23u, nullptr) )
      {
        flOldProtect = 840;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F390, &unk_4245F8, 0x29u, nullptr) )
      {
        flOldProtect = 846;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F374, &unk_424958, 0xD0u, nullptr) )
      {
        flOldProtect = 854;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F430, &unk_423288, 0x7Fu, nullptr) )
      {
        flOldProtect = 862;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F420, &unk_42342C, 0x3Eu, nullptr) )
      {
        flOldProtect = 868;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F368, &unk_424B08, 0x16u, nullptr) )
      {
        flOldProtect = 878;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F360, &unk_424BC8, 0x30u, nullptr) )
      {
        flOldProtect = 884;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F34C, &unk_424D38, 0x2Au, nullptr) )
      {
        flOldProtect = 897;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F33C, &unk_425198, 0x5Bu, nullptr) )
      {
        flOldProtect = 904;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F380, &unk_424750, 0x16u, nullptr) )
      {
        flOldProtect = 912;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F2BC, &unk_4255A8, 0x15u, nullptr) )
      {
        flOldProtect = 922;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F2B0, &unk_4256B8, 0x5Du, nullptr) )
      {
        flOldProtect = 930;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F2A0, &unk_4257F0, 0x2Fu, nullptr) )
      {
        flOldProtect = 937;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F290, &unk_425B80, 0x17u, nullptr) )
      {
        flOldProtect = 945;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F27C, &unk_425D18, 0x46u, nullptr) )
      {
        flOldProtect = 952;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F270, &unk_425F88, 0x8Cu, nullptr) )
      {
        flOldProtect = 960;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F260, &unk_426220, 0xBDu, nullptr) )
      {
        flOldProtect = 967;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F250, &unk_426540, 0x100u, nullptr) )
      {
        flOldProtect = 974;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F54C, &unk_420878, 0x4Fu, nullptr) )
      {
        flOldProtect = 980;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F230, &unk_426D30, 0x35u, nullptr) )
      {
        flOldProtect = 986;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F1E0, &unk_427480, 0x1Eu, nullptr) )
      {
        flOldProtect = 992;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F0BC, &unk_429DC8, 0x14u, nullptr) )
      {
        flOldProtect = 83;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F1B4, &unk_427B58, 0x19u, nullptr) )
      {
        flOldProtect = 713;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F1A4, &unk_427D30, 0x21u, nullptr) )
      {
        flOldProtect = 1015;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F198, aHX_0, 0xBCu, nullptr) )
      {
        flOldProtect = 1021;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F1CC, &unk_4278F8, 0x1Du, nullptr) )
      {
        flOldProtect = 1029;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F21C, &unk_426E9C, 0x1Du, nullptr) )
      {
        flOldProtect = 1003;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F204, &unk_4271A0, 0x2Du, nullptr) )
      {
        flOldProtect = 1043;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F1F8, &unk_42725C, 0x1Au, nullptr) )
      {
        flOldProtect = 1048;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F1EC, &unk_427320, 0x17u, nullptr) )
      {
        flOldProtect = 1055;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F188, &unk_4280C4, 0x40u, nullptr) )
      {
        flOldProtect = 397;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F170, &unk_428534, 0xA4u, nullptr) )
      {
        flOldProtect = 1072;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F150, &unk_4287C8, 0x58u, nullptr) )
      {
        flOldProtect = 1079;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F144, &unk_428954, 0x60u, nullptr) )
      {
        flOldProtect = 1124;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F140, &unk_4289E0, 0x22u, nullptr) )
      {
        flOldProtect = 1084;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F13C, &unk_428A30, 0x98u, nullptr) )
      {
        flOldProtect = 1162;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F12C, &unk_428BD8, 0xBCu, nullptr) )
      {
        flOldProtect = 1092;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F11C, &unk_428EE8, 0x37u, nullptr) )
      {
        flOldProtect = 1101;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F10C, &unk_429050, 0x2Du, nullptr) )
      {
        flOldProtect = 1105;
        goto LABEL_2181;
      }
      if ( *(_DWORD *)(this + 124) == 0 )
      {
        v35 = RegisterWindowMessageA(String);
        *(_DWORD *)(this + 124) = v35;
        if ( v35 == 0 )
        {
          v36 = GetLastError();
          CString::Format((CString *)&v94, aCreatemessage, v36);
          goto LABEL_2181;
        }
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), (LPVOID)0x43F7E4, (LPCVOID)(this + 120), 0xCu, nullptr) )
      {
        flOldProtect = 200;
        goto LABEL_2181;
      }
      v37 = (char *)&unk_41F848;
      v38 = 0;
      do
      {
        if ( !WriteProcessMemory(*(HANDLE *)(this + 112), (LPVOID)dword_41F818[v38], v37, dword_41F830[v38], nullptr) )
        {
          flOldProtect = 201;
          goto LABEL_2181;
        }
        v37 += 16;
        ++v38;
      }
      while ( (int)v37 < (int)byte_41F8A8 );
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F574, &unk_4200E0, 0x9Bu, nullptr) )
      {
        flOldProtect = 618;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F0B4, &unk_42A048, 0x1Au, nullptr) )
      {
        flOldProtect = 632;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F520, &unk_420ED0, 0x8Bu, nullptr) )
      {
        flOldProtect = 656;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F550, &unk_4206A8, 0x1A1u, nullptr) )
      {
        flOldProtect = 616;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F548, &unk_4208C8, 0xC7u, nullptr) )
      {
        flOldProtect = 616;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F500, &unk_421914, 0x13Eu, nullptr) )
      {
        flOldProtect = 675;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F4F0, &unk_421BE0, 0x47u, nullptr) )
      {
        flOldProtect = 683;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F4D0, &unk_422020, 0x19u, nullptr) )
      {
        flOldProtect = 700;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F4BC, &unk_4222C8, 0x23u, nullptr) )
      {
        flOldProtect = 715;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F4B8, &unk_422318, 0x3Cu, nullptr) )
      {
        flOldProtect = 720;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F4AC, &unk_422480, 0x51u, nullptr) )
      {
        flOldProtect = 729;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F494, &unk_422720, 0x13u, nullptr) )
      {
        flOldProtect = 739;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F488, &unk_422850, 0x1Au, nullptr) )
      {
        flOldProtect = 745;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F474, &unk_422A88, 0x14u, nullptr) )
      {
        flOldProtect = 763;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F478, &unk_4229E8, 0x71u, nullptr) )
      {
        flOldProtect = 761;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F44C, &unk_422EE0, 0x18u, nullptr) )
      {
        flOldProtect = 771;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_422FD0, &unk_422FD4, 0xFu, nullptr) )
      {
        flOldProtect = 779;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F510, &unk_421530, 0xA2u, nullptr) )
      {
        flOldProtect = 764;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F414, &unk_423570, 0x1AEu, nullptr) )
      {
        flOldProtect = 741;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F400, &unk_4238C0, 0x26u, nullptr) )
      {
        flOldProtect = 801;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F3E4, &unk_423D08, 0x55u, nullptr) )
      {
        flOldProtect = 691;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F3B8, &unk_424060, 0x6Bu, nullptr) )
      {
        flOldProtect = 811;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F408, &unk_4237E8, 0x13u, nullptr) )
      {
        flOldProtect = 821;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F3BC, &unk_423FD8, 0x60u, nullptr) )
      {
        flOldProtect = 836;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F3C4, &unk_423F20, 0x31u, nullptr) )
      {
        flOldProtect = 842;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F384, &unk_4246E8, 0x3Bu, nullptr) )
      {
        flOldProtect = 848;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F3A8, &unk_424310, 0x12u, nullptr) )
      {
        flOldProtect = 856;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F554, &unk_420658, 0x23u, nullptr) )
      {
        flOldProtect = 863;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F41C, &unk_423498, 0x4Eu, nullptr) )
      {
        flOldProtect = 870;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F370, &unk_424A50, 0x40u, nullptr) )
      {
        flOldProtect = 829;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F388, &unk_4246A0, 0x1Du, nullptr) )
      {
        flOldProtect = 880;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F35C, &unk_424BF8, 0x21u, nullptr) )
      {
        flOldProtect = 885;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F348, &unk_424D88, 0x3Fu, nullptr) )
      {
        flOldProtect = 899;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F338, &unk_4251F4, 0x50u, nullptr) )
      {
        flOldProtect = 905;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F2C8, &unk_4253FC, 0x34u, nullptr) )
      {
        flOldProtect = 895;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F2B8, &unk_4255E8, 0x16u, nullptr) )
      {
        flOldProtect = 924;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F2AC, &unk_425740, 0x20u, nullptr) )
      {
        flOldProtect = 932;
        goto LABEL_2181;
      }
      v39 = (int *)&unk_425870;
      v40 = 0;
      do
      {
        if ( !WriteProcessMemory(*(HANDLE *)(this + 112), (LPVOID)dword_425840[v40], v39, dword_425858[v40], nullptr) )
        {
          flOldProtect = 939;
          goto LABEL_2181;
        }
        v39 += 4;
        ++v40;
      }
      while ( (int)v39 < (int)dword_4258D0 );
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F28C, &unk_425BC0, 0x14u, nullptr) )
      {
        flOldProtect = 947;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F288, &unk_425C28, 0x18u, nullptr) )
      {
        flOldProtect = 1200;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F284, &unk_425C80, 0x12u, nullptr) )
      {
        flOldProtect = 1202;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F26C, &unk_426040, 0x35u, nullptr) )
      {
        flOldProtect = 962;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F25C, &unk_4262E0, 0x1Cu, nullptr) )
      {
        flOldProtect = 968;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F24C, &unk_42670C, 0x1Eu, nullptr) )
      {
        flOldProtect = 976;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F240, &unk_426AE8, 0x30u, nullptr) )
      {
        flOldProtect = 981;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F22C, &unk_426D68, 0x9Bu, nullptr) )
      {
        flOldProtect = 987;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F1DC, &unk_4274C8, 0x274u, nullptr) )
      {
        flOldProtect = 994;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F1C4, &unk_4279A8, 0x24u, nullptr) )
      {
        flOldProtect = 1005;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F1B0, &unk_427BA0, 0xBCu, nullptr) )
      {
        flOldProtect = 1010;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F49C, &unk_422628, 0x59u, nullptr) )
      {
        flOldProtect = 1017;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F194, &unk_427EF8, 0x17u, nullptr) )
      {
        flOldProtect = 1023;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F1BC, &unk_427A10, 0x4Eu, nullptr) )
      {
        flOldProtect = 1031;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F214, &unk_426F7C, 0x1Au, nullptr) )
      {
        flOldProtect = 1035;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F200, &unk_4271F8, 0x1Au, nullptr) )
      {
        flOldProtect = 1045;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F1F4, &unk_4272A0, 0x17u, nullptr) )
      {
        flOldProtect = 1050;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F18C, &unk_427FD0, 0x10u, nullptr) )
      {
        flOldProtect = 1058;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F234, &unk_426CB8, 0x75u, nullptr) )
      {
        flOldProtect = 889;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F184, &unk_428130, 0xDu, nullptr) )
      {
        flOldProtect = 890;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F178, &unk_428438, 0x2Fu, nullptr) )
      {
        flOldProtect = 1068;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F15C, &unk_428600, 0x47u, nullptr) )
      {
        flOldProtect = 1073;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F14C, &unk_4288F8, 0x28u, nullptr) )
      {
        flOldProtect = 838;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F138, &unk_428AF0, 0xAu, nullptr) )
      {
        flOldProtect = 1086;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F128, &unk_428CC0, 0x64u, nullptr) )
      {
        flOldProtect = 1094;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F118, &unk_428F48, 0x4Cu, nullptr) )
      {
        flOldProtect = 639;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F108, &unk_4290A8, 0x17u, nullptr) )
      {
        flOldProtect = 1107;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F558, &unk_4205B8, 0x78u, nullptr) )
      {
        flOldProtect = 640;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F538, &unk_420A80, 0x64u, nullptr) )
      {
        flOldProtect = 645;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F52C, &unk_420D10, 0x146u, nullptr) )
      {
        flOldProtect = 652;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F53C, &unk_420A48, 0x36u, nullptr) )
      {
        flOldProtect = 644;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F518, &unk_4210F0, 0x6Bu, nullptr) )
      {
        flOldProtect = 660;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F4FC, &unk_421A80, 0x85u, nullptr) )
      {
        flOldProtect = 677;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F4EC, &unk_421C50, 0x34u, nullptr) )
      {
        flOldProtect = 788;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F544, &unk_420990, 0x2Eu, nullptr) )
      {
        flOldProtect = 51;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F4D4, &unk_421FA0, 0x54u, nullptr) )
      {
        flOldProtect = 696;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F4C8, &unk_422130, 0x1Eu, nullptr) )
      {
        flOldProtect = 705;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F4C0, &unk_422220, 0x7Du, nullptr) )
      {
        flOldProtect = 711;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F4A8, &unk_4224F8, 0x29u, nullptr) )
      {
        flOldProtect = 731;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F484, &unk_422898, 0x26u, nullptr) )
      {
        flOldProtect = 754;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F470, &unk_422A9C, 0x13u, nullptr) )
      {
        flOldProtect = 752;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F45C, &unk_422C90, 0x19u, nullptr) )
      {
        flOldProtect = 689;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F448, &unk_422F20, 0x38u, nullptr) )
      {
        flOldProtect = 773;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F440, &unk_423010, 0xD4u, nullptr) )
      {
        flOldProtect = 781;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F42C, &unk_423308, 0x1Cu, nullptr) )
      {
        flOldProtect = 789;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F028, &unk_42CD8C, 0x86u, nullptr) )
      {
        flOldProtect = 1218;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F410, &unk_423748, 0x36u, nullptr) )
      {
        flOldProtect = 795;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F3FC, &unk_423910, 0x68u, nullptr) )
      {
        flOldProtect = 803;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F3E0, &unk_423D60, 0x2Au, nullptr) )
      {
        flOldProtect = 807;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F3B0, &unk_424258, 0x14u, nullptr) )
      {
        flOldProtect = 813;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F39C, &unk_424500, 0x31u, nullptr) )
      {
        flOldProtect = 823;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F3CC, &unk_423EA8, 0x1Eu, nullptr) )
      {
        flOldProtect = 831;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F394, &unk_4245B0, 0x20u, nullptr) )
      {
        flOldProtect = 844;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F37C, &unk_424830, 0x13u, nullptr) )
      {
        flOldProtect = 850;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F3F8, &unk_4239B8, 0x16u, nullptr) )
      {
        flOldProtect = 858;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F460, &unk_422BEC, 0xA2u, nullptr) )
      {
        flOldProtect = 612;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F434, &unk_423230, 0x29u, nullptr) )
      {
        flOldProtect = 865;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F418, &unk_423510, 0x34u, nullptr) )
      {
        flOldProtect = 872;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F36C, &unk_424AB8, 0x25u, nullptr) )
      {
        flOldProtect = 874;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F364, &unk_424B48, 0x55u, nullptr) )
      {
        flOldProtect = 882;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F358, &unk_424C48, 0x21u, nullptr) )
      {
        flOldProtect = 887;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F344, &unk_424DF0, 0x356u, nullptr) )
      {
        flOldProtect = 901;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F334, &unk_425270, 0x60u, nullptr) )
      {
        flOldProtect = 907;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F2C4, &unk_425458, 0xACu, nullptr) )
      {
        flOldProtect = 918;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F2B4, &unk_425628, 0x68u, nullptr) )
      {
        flOldProtect = 926;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F2A8, &unk_425760, 0x2Bu, nullptr) )
      {
        flOldProtect = 933;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F29C, &unk_425944, 0x27u, nullptr) )
      {
        flOldProtect = 723;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F2A4, &unk_4257B0, 0x12u, nullptr) )
      {
        flOldProtect = 935;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F280, &unk_425CD8, 0x11u, nullptr) )
      {
        flOldProtect = 949;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F278, &unk_425D88, 0xEAu, nullptr) )
      {
        flOldProtect = 956;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F268, &unk_4260A0, 0x3Fu, nullptr) )
      {
        flOldProtect = 964;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F258, &unk_426328, 0x198u, nullptr) )
      {
        flOldProtect = 970;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F248, &unk_426758, 0x30Bu, nullptr) )
      {
        flOldProtect = 978;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F23C, &unk_426B40, 0xE0u, nullptr) )
      {
        flOldProtect = 983;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F228, &unk_426E04, 0x10u, nullptr) )
      {
        flOldProtect = 988;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F1D8, &unk_42773C, 0x6Cu, nullptr) )
      {
        flOldProtect = 995;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F1D0, &unk_427860, 0x17u, nullptr) )
      {
        flOldProtect = 997;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F1C0, &unk_4279CC, 0x1Cu, nullptr) )
      {
        flOldProtect = 1006;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F1A8, &unk_427CD8, 0x58u, nullptr) )
      {
        flOldProtect = 1012;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F1A0, &unk_427D80, 0x48u, nullptr) )
      {
        flOldProtect = 1018;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F1AC, &unk_427C88, 0x22u, nullptr) )
      {
        flOldProtect = 1025;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F218, &unk_426F10, 0x6Cu, nullptr) )
      {
        flOldProtect = 1033;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F210, &unk_426FE8, 0xB8u, nullptr) )
      {
        flOldProtect = 1038;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F1FC, &unk_427240, 0x1Bu, nullptr) )
      {
        flOldProtect = 1047;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F20C, &unk_4270C8, 0x1Cu, nullptr) )
      {
        flOldProtect = 1052;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F1E8, &unk_427388, 0x39u, nullptr) )
      {
        flOldProtect = 1060;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F180, &unk_428168, 0x1C9u, nullptr) )
      {
        flOldProtect = 892;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F174, &unk_428490, 0xA4u, nullptr) )
      {
        flOldProtect = 1070;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F158, &unk_428690, 0x6Bu, nullptr) )
      {
        flOldProtect = 1075;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F148, &unk_428920, 0x32u, nullptr) )
      {
        flOldProtect = 1081;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F134, &unk_428B28, 0x33u, nullptr) )
      {
        flOldProtect = 1088;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F124, &unk_428D90, 0xD1u, nullptr) )
      {
        flOldProtect = 1097;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F114, &unk_428F94, 0x1Bu, nullptr) )
      {
        flOldProtect = 637;
        goto LABEL_2181;
      }
      v41 = (LPCVOID *)&off_42CF70;
      do
      {
        if ( !WriteProcessMemory(*(HANDLE *)(this + 112), (LPVOID)*(v41 - 2), *v41, (SIZE_T)*(v41 - 1), nullptr) )
        {
          flOldProtect = 1221;
          goto LABEL_2181;
        }
        v41 += 3;
      }
      while ( (int)v41 < (int)&dword_42CFC4 );
      v42 = (LPCVOID *)&off_41FA60;
      do
      {
        if ( !WriteProcessMemory(*(HANDLE *)(this + 112), (LPVOID)*(v42 - 2), *v42, (SIZE_T)*(v42 - 1), nullptr) )
        {
          flOldProtect = 12;
          goto LABEL_2181;
        }
        v42 += 3;
      }
      while ( (int)v42 < (int)&off_41FAA8 );
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_41F960, off_41F968, dword_41F964, nullptr) )
      {
        flOldProtect = 58;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_41FB68, off_41FB70, dword_41FB6C, nullptr) )
      {
        flOldProtect = 112;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_422390, off_422398, dword_422394, nullptr) )
      {
        flOldProtect = 722;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_422368, off_422370, dword_42236C, nullptr) )
      {
        flOldProtect = 721;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_41FBA8, off_41FBB0, dword_41FBAC, nullptr) )
      {
        flOldProtect = 115;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_41FBD0, off_41FBD8, dword_41FBD4, nullptr) )
      {
        flOldProtect = 116;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_41FC10, off_41FC18, dword_41FC14, nullptr) )
      {
        flOldProtect = 118;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_41FC50, off_41FC58, dword_41FC54, nullptr) )
      {
        flOldProtect = 119;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_41FC90, off_41FC98, dword_41FC94, nullptr) )
      {
        flOldProtect = 117;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_41FD18, off_41FD20, dword_41FD1C, nullptr) )
      {
        flOldProtect = 120;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_41FDC0, off_41FDC8, dword_41FDC4, nullptr) )
      {
        flOldProtect = 121;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_41FE18, off_41FE20, dword_41FE1C, nullptr) )
      {
        flOldProtect = 122;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_41FE70, off_41FE78, dword_41FE74, nullptr) )
      {
        flOldProtect = 123;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_41FF00, off_41FF08, dword_41FF04, nullptr) )
      {
        flOldProtect = 124;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_421518, off_421520, dword_42151C, nullptr) )
      {
        flOldProtect = 664;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_421700, off_421708, dword_421704, nullptr) )
      {
        flOldProtect = 670;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_421D20, off_421D28, dword_421D24, nullptr) )
      {
        flOldProtect = 688;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_41FF98, off_41FFA0, dword_41FF9C, nullptr) )
      {
        flOldProtect = 128;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_41FFF0, off_41FFF8, dword_41FFF4, nullptr) )
      {
        flOldProtect = 130;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_4200A0, off_4200A8, dword_4200A4, nullptr) )
      {
        flOldProtect = 614;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_4200C8, off_4200D0, dword_4200CC, nullptr) )
      {
        flOldProtect = 615;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_420690, off_420698, dword_420694, nullptr) )
      {
        flOldProtect = 864;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_420190, off_420198, dword_420194, nullptr) )
      {
        flOldProtect = 619;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_4204F8, off_420500, dword_4204FC, nullptr) )
      {
        flOldProtect = 132;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_420400, off_420408, dword_420404, nullptr) )
      {
        flOldProtect = 621;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_420428, off_420430, dword_42042C, nullptr) )
      {
        flOldProtect = 622;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_420450, off_420458, dword_420454, nullptr) )
      {
        flOldProtect = 623;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_420478, off_420480, dword_42047C, nullptr) )
      {
        flOldProtect = 624;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_4204A0, off_4204A8, dword_4204A4, nullptr) )
      {
        flOldProtect = 625;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_420298, off_4202A0, dword_42029C, nullptr) )
      {
        flOldProtect = 634;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_4205A0, off_4205A8, dword_4205A4, nullptr) )
      {
        flOldProtect = 134;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_420530, off_420538, dword_420534, nullptr) )
      {
        flOldProtect = 137;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_420640, off_420648, dword_420644, nullptr) )
      {
        flOldProtect = 641;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_420AF8, off_420B00, dword_420AFC, nullptr) )
      {
        flOldProtect = 646;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_420860, off_420868, dword_420864, nullptr) )
      {
        flOldProtect = 617;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_420A30, off_420A38, dword_420A34, nullptr) )
      {
        flOldProtect = 643;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_420B68, off_420B70, dword_420B6C, nullptr) )
      {
        flOldProtect = 143;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_420BD0, off_420BD8, dword_420BD4, nullptr) )
      {
        flOldProtect = 648;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_420C88, off_420C90, dword_420C8C, nullptr) )
      {
        flOldProtect = 650;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_424BB0, off_424BB8, dword_424BB4, nullptr) )
      {
        flOldProtect = 883;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_420CF8, off_420D00, dword_420CFC, nullptr) )
      {
        flOldProtect = 145;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_420E68, off_420E70, dword_420E6C, nullptr) )
      {
        flOldProtect = 653;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_420EB8, off_420EC0, dword_420EBC, nullptr) )
      {
        flOldProtect = 655;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_420F70, off_420F78, dword_420F74, nullptr) )
      {
        flOldProtect = 657;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_420FE0, off_420FE8, dword_420FE4, nullptr) )
      {
        flOldProtect = 146;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_4210D8, off_4210E0, dword_4210DC, nullptr) )
      {
        flOldProtect = 147;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_421168, off_421170, dword_42116C, nullptr) )
      {
        flOldProtect = 661;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_421180, off_421188, dword_421184, nullptr) )
      {
        flOldProtect = 662;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_421080, off_421088, dword_421084, nullptr) )
      {
        flOldProtect = 659;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_4215F0, off_4215F8, dword_4215F4, nullptr) )
      {
        flOldProtect = 126;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_421628, off_421630, dword_42162C, nullptr) )
      {
        flOldProtect = 103;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_421668, off_421670, dword_42166C, nullptr) )
      {
        flOldProtect = 129;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_421740, off_421748, dword_421744, nullptr) )
      {
        flOldProtect = 125;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_421868, off_421870, dword_42186C, nullptr) )
      {
        flOldProtect = 672;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_421890, off_421898, dword_421894, nullptr) )
      {
        flOldProtect = 673;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_421A68, off_421A70, dword_421A6C, nullptr) )
      {
        flOldProtect = 676;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_421B18, off_421B20, dword_421B1C, nullptr) )
      {
        flOldProtect = 678;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_421B70, off_421B78, dword_421B74, nullptr) )
      {
        flOldProtect = 680;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_421BC8, off_421BD0, dword_421BCC, nullptr) )
      {
        flOldProtect = 682;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_421C38, off_421C40, dword_421C3C, nullptr) )
      {
        flOldProtect = 684;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_422B48, off_422B50, dword_422B4C, nullptr) )
      {
        flOldProtect = 686;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_421E90, off_421E98, dword_421E94, nullptr) )
      {
        flOldProtect = 695;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_421EE8, off_421EF0, dword_421EEC, nullptr) )
      {
        flOldProtect = 102;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_421F88, off_421F90, dword_421F8C, nullptr) )
      {
        flOldProtect = 693;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_422008, off_422010, dword_42200C, nullptr) )
      {
        flOldProtect = 697;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_422050, off_422058, dword_422054, nullptr) )
      {
        flOldProtect = 701;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_422078, off_422080, dword_42207C, nullptr) )
      {
        flOldProtect = 702;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_422118, off_422120, dword_42211C, nullptr) )
      {
        flOldProtect = 699;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_4220A0, off_4220A8, dword_4220A4, nullptr) )
      {
        flOldProtect = 703;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_4220C8, off_4220D0, dword_4220CC, nullptr) )
      {
        flOldProtect = 704;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_422158, off_422160, dword_42215C, nullptr) )
      {
        flOldProtect = 706;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_422208, off_422210, dword_42220C, nullptr) )
      {
        flOldProtect = 708;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_421D68, off_421D70, dword_421D6C, nullptr) )
      {
        flOldProtect = 710;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_421DC0, off_421DC8, dword_421DC4, nullptr) )
      {
        flOldProtect = 127;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_422300, off_422308, dword_422304, nullptr) )
      {
        flOldProtect = 716;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_4222B0, off_4222B8, dword_4222B4, nullptr) )
      {
        flOldProtect = 712;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_421F28, off_421F30, dword_421F2C, nullptr) )
      {
        flOldProtect = 718;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_429120, off_429128, dword_429124, nullptr) )
      {
        flOldProtect = 1110;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_4223C8, off_4223D0, dword_4223CC, nullptr) )
      {
        flOldProtect = 726;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_422468, off_422470, dword_42246C, nullptr) )
      {
        flOldProtect = 728;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_4224E0, off_4224E8, dword_4224E4, nullptr) )
      {
        flOldProtect = 730;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_422538, off_422540, dword_42253C, nullptr) )
      {
        flOldProtect = 732;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_422580, off_422588, dword_422584, nullptr) )
      {
        flOldProtect = 734;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_4225B8, off_4225C0, dword_4225BC, nullptr) )
      {
        flOldProtect = 114;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_422610, off_422618, dword_422614, nullptr) )
      {
        flOldProtect = 736;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_422708, off_422710, dword_42270C, nullptr) )
      {
        flOldProtect = 738;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_4227A8, off_4227B0, dword_4227AC, nullptr) )
      {
        flOldProtect = 744;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_422880, off_422888, dword_422884, nullptr) )
      {
        flOldProtect = 746;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_4211A0, off_4211A8, dword_4211A4, nullptr) )
      {
        flOldProtect = 747;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_4211B8, off_4211C0, dword_4211BC, nullptr) )
      {
        flOldProtect = 748;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_4211D0, off_4211D8, dword_4211D4, nullptr) )
      {
        flOldProtect = 749;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_4211E8, off_4211F0, dword_4211EC, nullptr) )
      {
        flOldProtect = 785;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_421200, off_421208, dword_421204, nullptr) )
      {
        flOldProtect = 785;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_421218, off_421220, dword_42121C, nullptr) )
      {
        flOldProtect = 785;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_422838, off_422840, dword_42283C, nullptr) )
      {
        flOldProtect = 751;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_4228D0, off_4228D8, dword_4228D4, nullptr) )
      {
        flOldProtect = 755;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_4228F8, off_422900, dword_4228FC, nullptr) )
      {
        flOldProtect = 756;
        goto LABEL_2181;
      }
      v43 = (LPVOID *)&unk_422918;
      do
      {
        if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *v43, &unk_422910, 4u, nullptr) )
        {
          flOldProtect = 131;
          goto LABEL_2181;
        }
        ++v43;
      }
      while ( (int)v43 < (int)&dword_422948 );
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_422958, off_422960, dword_42295C, nullptr) )
      {
        flOldProtect = 133;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_4229D0, off_4229D8, dword_4229D4, nullptr) )
      {
        flOldProtect = 760;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_422A70, off_422A78, dword_422A74, nullptr) )
      {
        flOldProtect = 762;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_422AC0, off_422AC8, dword_422AC4, nullptr) )
      {
        flOldProtect = 753;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_422CC0, off_422CC8, dword_422CC4, nullptr) )
      {
        flOldProtect = 690;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_422D48, off_422D50, dword_422D4C, nullptr) )
      {
        flOldProtect = 768;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_422E78, off_422E80, dword_422E7C, nullptr) )
      {
        flOldProtect = 770;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_422F08, off_422F10, dword_422F0C, nullptr) )
      {
        flOldProtect = 772;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_422F68, off_422F70, dword_422F6C, nullptr) )
      {
        flOldProtect = 774;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_422EC8, off_422ED0, dword_422ECC, nullptr) )
      {
        flOldProtect = 776;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_422FB8, off_422FC0, dword_422FBC, nullptr) )
      {
        flOldProtect = 778;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_422FF8, off_423000, dword_422FFC, nullptr) )
      {
        flOldProtect = 780;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_4230F8, off_423100, dword_4230FC, nullptr) )
      {
        flOldProtect = 782;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_423190, off_423198, dword_423194, nullptr) )
      {
        flOldProtect = 784;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42B5B0, off_42B5B8, dword_42B5B4, nullptr) )
      {
        flOldProtect = 1170;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_423218, off_423220, dword_42321C, nullptr) )
      {
        flOldProtect = 787;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_423338, off_423340, dword_42333C, nullptr) )
      {
        flOldProtect = 790;
        goto LABEL_2181;
      }
      v44 = (LPCVOID *)&off_42CE40;
      do
      {
        if ( !WriteProcessMemory(*(HANDLE *)(this + 112), (LPVOID)*(v44 - 2), *v44, (SIZE_T)*(v44 - 1), nullptr) )
        {
          flOldProtect = 1219;
          goto LABEL_2181;
        }
        v44 += 3;
      }
      while ( (int)v44 < (int)&off_42CE58 );
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_423DD8, off_423DE0, dword_423DDC, nullptr) )
      {
        flOldProtect = 792;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_423390, off_423398, dword_423394, nullptr) )
      {
        flOldProtect = 794;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_423730, off_423738, dword_423734, nullptr) )
      {
        flOldProtect = 742;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_423790, off_423798, dword_423794, nullptr) )
      {
        flOldProtect = 796;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_4237D0, off_4237D8, dword_4237D4, nullptr) )
      {
        flOldProtect = 798;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_423870, off_423878, dword_423874, nullptr) )
      {
        flOldProtect = 800;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_4238A8, off_4238B0, dword_4238AC, nullptr) )
      {
        flOldProtect = 135;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_4238F8, off_423900, dword_4238FC, nullptr) )
      {
        flOldProtect = 802;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_4239A0, off_4239A8, dword_4239A4, nullptr) )
      {
        flOldProtect = 804;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_423CF0, off_423CF8, dword_423CF4, nullptr) )
      {
        flOldProtect = 806;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_423E58, off_423E60, dword_423E5C, nullptr) )
      {
        flOldProtect = 810;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_4240E0, off_4240E8, dword_4240E4, nullptr) )
      {
        flOldProtect = 812;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_424280, off_424288, dword_424284, nullptr) )
      {
        flOldProtect = 814;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_4242F8, off_424300, dword_4242FC, nullptr) )
      {
        flOldProtect = 816;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_424450, off_424458, dword_424454, nullptr) )
      {
        flOldProtect = 818;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_4244A8, off_4244B0, dword_4244AC, nullptr) )
      {
        flOldProtect = 820;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_423810, off_423818, dword_423814, nullptr) )
      {
        flOldProtect = 822;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_424108, off_424110, dword_42410C, nullptr) )
      {
        flOldProtect = 142;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_4244E8, off_4244F0, dword_4244EC, nullptr) )
      {
        flOldProtect = 148;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_424548, off_424550, dword_42454C, nullptr) )
      {
        flOldProtect = 824;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_4241F8, off_424200, dword_4241FC, nullptr) )
      {
        flOldProtect = 826;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_424218, off_424220, dword_42421C, nullptr) )
      {
        flOldProtect = 826;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_423E90, off_423E98, dword_423E94, nullptr) )
      {
        flOldProtect = 828;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_423F08, off_423F10, dword_423F0C, nullptr) )
      {
        flOldProtect = 833;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_423FC0, off_423FC8, dword_423FC4, nullptr) )
      {
        flOldProtect = 835;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_424048, off_424050, dword_42404C, nullptr) )
      {
        flOldProtect = 837;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_424598, off_4245A0, dword_42459C, nullptr) )
      {
        flOldProtect = 841;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_423F68, off_423F70, dword_423F6C, nullptr) )
      {
        flOldProtect = 843;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_4245E0, off_4245E8, dword_4245E4, nullptr) )
      {
        flOldProtect = 845;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_424638, off_424640, dword_42463C, nullptr) )
      {
        flOldProtect = 847;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_424738, off_424740, dword_42473C, nullptr) )
      {
        flOldProtect = 849;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_424858, off_424860, dword_42485C, nullptr) )
      {
        flOldProtect = 851;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_424940, off_424948, dword_424944, nullptr) )
      {
        flOldProtect = 853;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_424A38, off_424A40, dword_424A3C, nullptr) )
      {
        flOldProtect = 855;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_424338, off_424340, dword_42433C, nullptr) )
      {
        flOldProtect = 857;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_4239E0, off_4239E8, dword_4239E4, nullptr) )
      {
        flOldProtect = 859;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_423A18, off_423A20, dword_423A1C, nullptr) )
      {
        flOldProtect = 861;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_423A50, off_423A58, dword_423A54, nullptr) )
      {
        flOldProtect = 861;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_422D80, off_422D88, dword_422D84, nullptr) )
      {
        flOldProtect = 149;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_423270, off_423278, dword_423274, nullptr) )
      {
        flOldProtect = 866;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_423480, off_423488, dword_423484, nullptr) )
      {
        flOldProtect = 869;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_4234F8, off_423500, dword_4234FC, nullptr) )
      {
        flOldProtect = 871;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_423558, off_423560, dword_42355C, nullptr) )
      {
        flOldProtect = 873;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_424AA0, off_424AA8, dword_424AA4, nullptr) )
      {
        flOldProtect = 830;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_424AF0, off_424AF8, dword_424AF4, nullptr) )
      {
        flOldProtect = 875;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_424688, off_424690, dword_42468C, nullptr) )
      {
        flOldProtect = 877;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_424B30, off_424B38, dword_424B34, nullptr) )
      {
        flOldProtect = 879;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_4246D0, off_4246D8, dword_4246D4, nullptr) )
      {
        flOldProtect = 881;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_424C30, off_424C38, dword_424C34, nullptr) )
      {
        flOldProtect = 886;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_424C80, off_424C88, dword_424C84, nullptr) )
      {
        flOldProtect = 888;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_424CC0, off_424CC8, dword_424CC4, nullptr) )
      {
        flOldProtect = 1014;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_424D70, off_424D78, dword_424D74, nullptr) )
      {
        flOldProtect = 898;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_425590, off_425598, dword_425594, nullptr) )
      {
        flOldProtect = 921;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_424DD8, off_424DE0, dword_424DDC, nullptr) )
      {
        flOldProtect = 900;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_425158, off_425160, dword_42515C, nullptr) )
      {
        flOldProtect = 902;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_425258, off_425260, dword_42525C, nullptr) )
      {
        flOldProtect = 906;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_4252E0, off_4252E8, dword_4252E4, nullptr) )
      {
        flOldProtect = 908;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_425328, off_425330, dword_42532C, nullptr) )
      {
        flOldProtect = 910;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_424778, off_424780, dword_42477C, nullptr) )
      {
        flOldProtect = 913;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_4247A0, off_4247A8, dword_4247A4, nullptr) )
      {
        flOldProtect = 914;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_4247C8, off_4247D0, dword_4247CC, nullptr) )
      {
        flOldProtect = 915;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_4247F0, off_4247F8, dword_4247F4, nullptr) )
      {
        flOldProtect = 916;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_424818, off_424820, dword_42481C, nullptr) )
      {
        flOldProtect = 917;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_425440, off_425448, dword_425444, nullptr) )
      {
        flOldProtect = 896;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_425518, off_425520, dword_42551C, nullptr) )
      {
        flOldProtect = 919;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_4255D0, off_4255D8, dword_4255D4, nullptr) )
      {
        flOldProtect = 923;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_425610, off_425618, dword_425614, nullptr) )
      {
        flOldProtect = 925;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_425728, off_425730, dword_42572C, nullptr) )
      {
        flOldProtect = 931;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_425798, off_4257A0, dword_42579C, nullptr) )
      {
        flOldProtect = 934;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_4257D8, off_4257E0, dword_4257DC, nullptr) )
      {
        flOldProtect = 936;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_425828, off_425830, dword_42582C, nullptr) )
      {
        flOldProtect = 938;
        goto LABEL_2181;
      }
      for ( m = 0; m < 2; ++m )
      {
        if ( !WriteProcessMemory(
                *(HANDLE *)(this + 112),
                (LPVOID)dword_4258D0[m],
                (char *)&unk_425900 + dword_4258E0[m],
                dword_4258D8[m],
                nullptr) )
        {
          flOldProtect = 940;
          goto LABEL_2181;
        }
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_425980, off_425988, dword_425984, nullptr) )
      {
        flOldProtect = 724;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_4259A8, off_4259B0, dword_4259AC, nullptr) )
      {
        flOldProtect = 724;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_4259D0, off_4259D8, dword_4259D4, nullptr) )
      {
        flOldProtect = 724;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_4259F8, off_425A00, dword_4259FC, nullptr) )
      {
        flOldProtect = 724;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_425A38, off_425A40, dword_425A3C, nullptr) )
      {
        flOldProtect = 144;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_425A88, off_425A90, dword_425A8C, nullptr) )
      {
        flOldProtect = 942;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_425AB0, off_425AB8, dword_425AB4, nullptr) )
      {
        flOldProtect = 942;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_425AD8, off_425AE0, dword_425ADC, nullptr) )
      {
        flOldProtect = 942;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_425B00, off_425B08, dword_425B04, nullptr) )
      {
        flOldProtect = 942;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_425B40, off_425B48, dword_425B44, nullptr) )
      {
        flOldProtect = 944;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_425B68, off_425B70, dword_425B6C, nullptr) )
      {
        flOldProtect = 944;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_425BA8, off_425BB0, dword_425BAC, nullptr) )
      {
        flOldProtect = 946;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_425BE8, off_425BF0, dword_425BEC, nullptr) )
      {
        flOldProtect = 948;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_425C10, off_425C18, dword_425C14, nullptr) )
      {
        flOldProtect = 948;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_425C48, off_425C50, dword_425C4C, nullptr) )
      {
        flOldProtect = 1201;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_425C68, off_425C70, dword_425C6C, nullptr) )
      {
        flOldProtect = 1201;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_425CA0, off_425CA8, dword_425CA4, nullptr) )
      {
        flOldProtect = 1203;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_425CC0, off_425CC8, dword_425CC4, nullptr) )
      {
        flOldProtect = 1203;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_425D00, off_425D08, dword_425D04, nullptr) )
      {
        flOldProtect = 950;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_425D70, off_425D78, dword_425D74, nullptr) )
      {
        flOldProtect = 953;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_425E88, off_425E90, dword_425E8C, nullptr) )
      {
        flOldProtect = 957;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_425F70, off_425F78, dword_425F74, nullptr) )
      {
        flOldProtect = 959;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_426028, off_426030, dword_42602C, nullptr) )
      {
        flOldProtect = 961;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_426088, off_426090, dword_42608C, nullptr) )
      {
        flOldProtect = 963;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_4260F0, off_4260F8, dword_4260F4, nullptr) )
      {
        flOldProtect = 965;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_426310, off_426318, dword_426314, nullptr) )
      {
        flOldProtect = 969;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_426528, off_426530, dword_42652C, nullptr) )
      {
        flOldProtect = 973;
        goto LABEL_2181;
      }
      v46 = (LPCVOID *)&off_426698;
      do
      {
        if ( !WriteProcessMemory(*(HANDLE *)(this + 112), (LPVOID)*(v46 - 2), *v46, (SIZE_T)*(v46 - 1), nullptr) )
        {
          flOldProtect = 975;
          goto LABEL_2181;
        }
        v46 += 3;
      }
      while ( (int)v46 < (int)&dword_4266D4 );
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_426740, off_426748, dword_426744, nullptr) )
      {
        flOldProtect = 977;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_426B28, off_426B30, dword_426B2C, nullptr) )
      {
        flOldProtect = 982;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_426CA0, off_426CA8, dword_426CA4, nullptr) )
      {
        flOldProtect = 985;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_426E28, off_426E30, dword_426E2C, nullptr) )
      {
        flOldProtect = 989;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_426E68, off_426E70, dword_426E6C, nullptr) )
      {
        flOldProtect = 991;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_426FD0, off_426FD8, dword_426FD4, nullptr) )
      {
        flOldProtect = 1037;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_4274B0, off_4274B8, dword_4274B4, nullptr) )
      {
        flOldProtect = 993;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_427890, off_427898, dword_427894, nullptr) )
      {
        flOldProtect = 998;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_4278B8, off_4278C0, dword_4278BC, nullptr) )
      {
        flOldProtect = 999;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_4278E0, off_4278E8, dword_4278E4, nullptr) )
      {
        flOldProtect = 1000;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_427990, off_427998, dword_427994, nullptr) )
      {
        flOldProtect = 1002;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_429900, off_429908, dword_429904, nullptr) )
      {
        flOldProtect = 155;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_427B18, off_427B20, dword_427B1C, nullptr) )
      {
        flOldProtect = 1009;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_427B40, off_427B48, dword_427B44, nullptr) )
      {
        flOldProtect = 1009;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_429940, off_429948, dword_429944, nullptr) )
      {
        flOldProtect = 1155;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_427B88, off_427B90, dword_427B8C, nullptr) )
      {
        flOldProtect = 714;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_427C70, off_427C78, dword_427C74, nullptr) )
      {
        flOldProtect = 1011;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_427D68, off_427D70, dword_427D6C, nullptr) )
      {
        flOldProtect = 1016;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_427DF8, off_427E00, dword_427DFC, nullptr) )
      {
        flOldProtect = 1020;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_427EE0, off_427EE8, dword_427EE4, nullptr) )
      {
        flOldProtect = 1022;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_427F20, off_427F28, dword_427F24, nullptr) )
      {
        flOldProtect = 1024;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_427CC0, off_427CC8, dword_427CC4, nullptr) )
      {
        flOldProtect = 1026;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_427FB8, off_427FC0, dword_427FBC, nullptr) )
      {
        flOldProtect = 1028;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_427928, off_427930, dword_42792C, nullptr) )
      {
        flOldProtect = 1030;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_426ED0, off_426ED8, dword_426ED4, nullptr) )
      {
        flOldProtect = 1004;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_426FA8, off_426FB0, dword_426FAC, nullptr) )
      {
        flOldProtect = 1036;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_4270B0, off_4270B8, dword_4270B4, nullptr) )
      {
        flOldProtect = 1039;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_427138, off_427140, dword_42713C, nullptr) )
      {
        flOldProtect = 1041;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_427160, off_427168, dword_427164, nullptr) )
      {
        flOldProtect = 1042;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_420038, off_420040, dword_42003C, nullptr) )
      {
        flOldProtect = 156;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_426EF8, off_426F00, dword_426EFC, nullptr) )
      {
        flOldProtect = 1004;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_4271E0, off_4271E8, dword_4271E4, nullptr) )
      {
        flOldProtect = 1044;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_427228, off_427230, dword_42722C, nullptr) )
      {
        flOldProtect = 1046;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_427288, off_427290, dword_42728C, nullptr) )
      {
        flOldProtect = 1049;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_4272C8, off_4272D0, dword_4272CC, nullptr) )
      {
        flOldProtect = 1051;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_427FE8, off_427FF0, dword_427FEC, nullptr) )
      {
        flOldProtect = 1059;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_427308, off_427310, dword_42730C, nullptr) )
      {
        flOldProtect = 1054;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_427348, off_427350, dword_42734C, nullptr) )
      {
        flOldProtect = 1056;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_427370, off_427378, dword_427374, nullptr) )
      {
        flOldProtect = 1057;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_4273D8, off_4273E0, dword_4273DC, nullptr) )
      {
        flOldProtect = 1061;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_427468, off_427470, dword_42746C, nullptr) )
      {
        flOldProtect = 1063;
        goto LABEL_2181;
      }
      for ( n = 0; n < 5; ++n )
      {
        if ( !WriteProcessMemory(
                *(HANDLE *)(this + 112),
                (LPVOID)dword_428000[n],
                (char *)&unk_42803C + dword_428028[n],
                dword_428014[n],
                nullptr) )
        {
          flOldProtect = 1065;
          goto LABEL_2181;
        }
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_428118, off_428120, dword_42811C, nullptr) )
      {
        flOldProtect = 398;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_428150, off_428158, dword_428154, nullptr) )
      {
        flOldProtect = 891;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_428348, off_428350, dword_42834C, nullptr) )
      {
        flOldProtect = 893;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_428420, off_428428, dword_428424, nullptr) )
      {
        flOldProtect = 1067;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_428478, off_428480, dword_42847C, nullptr) )
      {
        flOldProtect = 1069;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_428658, off_428660, dword_42865C, nullptr) )
      {
        flOldProtect = 1074;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_428678, off_428680, dword_42867C, nullptr) )
      {
        flOldProtect = 1074;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_428710, off_428718, dword_428714, nullptr) )
      {
        flOldProtect = 1076;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_4287B0, off_4287B8, dword_4287B4, nullptr) )
      {
        flOldProtect = 1078;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_428830, off_428838, dword_428834, nullptr) )
      {
        flOldProtect = 1080;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_428850, off_428858, dword_428854, nullptr) )
      {
        flOldProtect = 1080;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_428870, off_428878, dword_428874, nullptr) )
      {
        flOldProtect = 1080;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_428890, off_428898, dword_428894, nullptr) )
      {
        flOldProtect = 1080;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_4288B8, off_4288C0, dword_4288BC, nullptr) )
      {
        flOldProtect = 1183;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_4288E0, off_4288E8, dword_4288E4, nullptr) )
      {
        flOldProtect = 1183;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_4289C8, off_4289D0, dword_4289CC, nullptr) )
      {
        flOldProtect = 1125;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_428A18, off_428A20, dword_428A1C, nullptr) )
      {
        flOldProtect = 1085;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_428CA8, off_428CB0, dword_428CAC, nullptr) )
      {
        flOldProtect = 1093;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_428D38, off_428D40, dword_428D3C, nullptr) )
      {
        flOldProtect = 1095;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_428D58, off_428D60, dword_428D5C, nullptr) )
      {
        flOldProtect = 1095;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_428D78, off_428D80, dword_428D7C, nullptr) )
      {
        flOldProtect = 1095;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_423B20, off_423B28, dword_423B24, nullptr) )
      {
        flOldProtect = 636;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_428ED0, off_428ED8, dword_428ED4, nullptr) )
      {
        flOldProtect = 1100;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_428BC0, off_428BC8, dword_428BC4, nullptr) )
      {
        flOldProtect = 1091;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), off_428F30, off_428F38, dword_428F34, nullptr) )
      {
        flOldProtect = 1102;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_428FC0, off_428FC8, dword_428FC4, nullptr) )
      {
        flOldProtect = 638;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_429090, off_429098, dword_429094, nullptr) )
      {
        flOldProtect = 1106;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_4290D0, off_4290D8, dword_4290D4, nullptr) )
      {
        flOldProtect = 1108;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_4291B0, off_4291B8, dword_4291B4, nullptr) )
      {
        flOldProtect = 1118;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_4292D0, off_4292D8, dword_4292D4, nullptr) )
      {
        flOldProtect = 1114;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_429360, off_429368, dword_429364, nullptr) )
      {
        flOldProtect = 1127;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_4293B8, off_4293C0, dword_4293BC, nullptr) )
      {
        flOldProtect = 1129;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_4293F8, off_429400, dword_4293FC, nullptr) )
      {
        flOldProtect = 1131;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_429488, off_429490, dword_42948C, nullptr) )
      {
        flOldProtect = 1133;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_4294B0, off_4294B8, dword_4294B4, nullptr) )
      {
        flOldProtect = 1135;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_4294D8, off_4294E0, dword_4294DC, nullptr) )
      {
        flOldProtect = 1136;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_4295F8, off_429600, dword_4295FC, nullptr) )
      {
        flOldProtect = 1138;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_429678, off_429680, dword_42967C, nullptr) )
      {
        flOldProtect = 1140;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_429710, off_429718, dword_429714, nullptr) )
      {
        flOldProtect = 1142;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_429780, off_429788, dword_429784, nullptr) )
      {
        flOldProtect = 1144;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_4298A0, off_4298A8, dword_4298A4, nullptr) )
      {
        flOldProtect = 1157;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42B500, off_42B508, dword_42B504, nullptr) )
      {
        flOldProtect = 1159;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42B528, off_42B530, dword_42B52C, nullptr) )
      {
        flOldProtect = 1160;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42B540, off_42B548, dword_42B544, nullptr) )
      {
        flOldProtect = 1161;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42B568, off_42B570, dword_42B56C, nullptr) )
      {
        flOldProtect = 1165;
        goto LABEL_2181;
      }
      v48 = (LPCVOID *)&off_42B698;
      do
      {
        if ( !WriteProcessMemory(*(HANDLE *)(this + 112), (LPVOID)*(v48 - 2), *v48, (SIZE_T)*(v48 - 1), nullptr) )
        {
          flOldProtect = 1174;
          goto LABEL_2181;
        }
        v48 += 3;
      }
      while ( (int)v48 < (int)&dword_42B6BC );
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42B778, off_42B780, dword_42B77C, nullptr) )
      {
        flOldProtect = 1169;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42B810, off_42B818, dword_42B814, nullptr) )
      {
        flOldProtect = 1179;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42B838, off_42B840, dword_42B83C, nullptr) )
      {
        flOldProtect = 1179;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42B878, off_42B880, dword_42B87C, nullptr) )
      {
        flOldProtect = 1181;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42BDC8, off_42BDD0, dword_42BDCC, nullptr) )
      {
        flOldProtect = 1185;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42BF90, off_42BF98, dword_42BF94, nullptr) )
      {
        flOldProtect = 1187;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42C058, off_42C060, dword_42C05C, nullptr) )
      {
        flOldProtect = 1213;
        goto LABEL_2181;
      }
      for ( ii = 0; ii < 6; ++ii )
      {
        if ( !WriteProcessMemory(
                *(HANDLE *)(this + 112),
                (LPVOID)dword_42C134[ii],
                (char *)&unk_42C17C + dword_42C164[ii],
                dword_42C14C[ii],
                nullptr) )
        {
          flOldProtect = 1189;
          goto LABEL_2181;
        }
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42C550, off_42C558, dword_42C554, nullptr) )
      {
        flOldProtect = 1215;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), off_42C5A8, off_42C5B0, dword_42C5AC, nullptr) )
      {
        flOldProtect = 1217;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42C600, off_42C608, dword_42C604, nullptr) )
      {
        flOldProtect = 1191;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42C930, off_42C938, dword_42C934, nullptr) )
      {
        flOldProtect = 1198;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42C9B8, off_42C9C0, dword_42C9BC, nullptr) )
      {
        flOldProtect = 1194;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42CA00, off_42CA08, dword_42CA04, nullptr) )
      {
        flOldProtect = 1196;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42CA60, off_42CA68, dword_42CA64, nullptr) )
      {
        flOldProtect = 1205;
        goto LABEL_2181;
      }
      for ( jj = 0; jj < 3; ++jj )
      {
        if ( !WriteProcessMemory(
                *(HANDLE *)(this + 112),
                (LPVOID)dword_42CA78[jj],
                (char *)&unk_42CA9C + dword_42CA90[jj],
                dword_42CA84[jj],
                nullptr) )
        {
          flOldProtect = 1206;
          goto LABEL_2181;
        }
      }
      for ( kk = 0; kk < 4; ++kk )
      {
        if ( !WriteProcessMemory(
                *(HANDLE *)(this + 112),
                (LPVOID)dword_42CADC[kk],
                (char *)&unk_42CB0C + dword_42CAFC[kk],
                dword_42CAEC[kk],
                nullptr) )
        {
          flOldProtect = 1207;
          goto LABEL_2181;
        }
      }
      for ( mm = 0; mm < 4; ++mm )
      {
        if ( !WriteProcessMemory(
                *(HANDLE *)(this + 112),
                (LPVOID)dword_42CB74[mm],
                (char *)&unk_42CBA4 + dword_42CB94[mm],
                dword_42CB84[mm],
                nullptr) )
        {
          flOldProtect = 1208;
          goto LABEL_2181;
        }
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42CC78, off_42CC80, dword_42CC7C, nullptr) )
      {
        flOldProtect = 1209;
        goto LABEL_2181;
      }
      v53 = (LPCVOID *)&off_42CD48;
      do
      {
        if ( !WriteProcessMemory(*(HANDLE *)(this + 112), (LPVOID)*(v53 - 2), *v53, (SIZE_T)*(v53 - 1), nullptr) )
        {
          flOldProtect = 1211;
          goto LABEL_2181;
        }
        v53 += 3;
      }
      while ( (int)v53 < (int)&dword_42CD6C );
      v54 = (LPCVOID *)&off_42D0C8;
      do
      {
        if ( !WriteProcessMemory(*(HANDLE *)(this + 112), (LPVOID)*(v54 - 2), *v54, (SIZE_T)*(v54 - 1), nullptr) )
        {
          flOldProtect = 1223;
          goto LABEL_2181;
        }
        v54 += 3;
      }
      while ( (int)v54 < (int)&dword_42D0EC );
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42D1A0, off_42D1A8, dword_42D1A4, nullptr) )
      {
        flOldProtect = 1225;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42D1C8, off_42D1D0, dword_42D1CC, nullptr) )
      {
        flOldProtect = 1226;
        goto LABEL_2181;
      }
      v55 = (LPCVOID *)&off_42D340;
      do
      {
        if ( !WriteProcessMemory(*(HANDLE *)(this + 112), (LPVOID)*(v55 - 2), *v55, (SIZE_T)*(v55 - 1), nullptr) )
        {
          flOldProtect = 1227;
          goto LABEL_2181;
        }
        v55 += 3;
      }
      while ( (int)v55 < (int)dword_42D454 );
      v56 = (LPCVOID *)&off_42D7C0;
      do
      {
        if ( !WriteProcessMemory(*(HANDLE *)(this + 112), (LPVOID)*(v56 - 2), *v56, (SIZE_T)*(v56 - 1), nullptr) )
        {
          flOldProtect = 1229;
          goto LABEL_2181;
        }
        v56 += 3;
      }
      while ( (int)v56 < (int)&dword_42D88C );
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42A080, off_42A088, dword_42A084, nullptr) )
      {
        flOldProtect = 171;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42A118, off_42A120, dword_42A11C, nullptr) )
      {
        flOldProtect = 172;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42A140, off_42A148, dword_42A144, nullptr) )
      {
        flOldProtect = 173;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42A1A0, off_42A1A8, dword_42A1A4, nullptr) )
      {
        flOldProtect = 169;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_429E78, off_429E80, dword_429E7C, nullptr) )
      {
        flOldProtect = 170;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_429EA0, off_429EA8, dword_429EA4, nullptr) )
      {
        flOldProtect = 174;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_429EC8, off_429ED0, dword_429ECC, nullptr) )
      {
        flOldProtect = 175;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_429EF0, off_429EF8, dword_429EF4, nullptr) )
      {
        flOldProtect = 176;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_429F18, off_429F20, dword_429F1C, nullptr) )
      {
        flOldProtect = 177;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_429F40, off_429F48, dword_429F44, nullptr) )
      {
        flOldProtect = 178;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_429F68, off_429F70, dword_429F6C, nullptr) )
      {
        flOldProtect = 181;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_429F90, off_429F98, dword_429F94, nullptr) )
      {
        flOldProtect = 179;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_429FB8, off_429FC0, dword_429FBC, nullptr) )
      {
        flOldProtect = 180;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_429FE0, off_429FE8, dword_429FE4, nullptr) )
      {
        flOldProtect = 182;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42A008, off_42A010, dword_42A00C, nullptr) )
      {
        flOldProtect = 183;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42A030, off_42A038, dword_42A034, nullptr) )
      {
        flOldProtect = 184;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_429AA8, off_429AB0, dword_429AAC, nullptr) )
      {
        flOldProtect = 185;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_429AD0, off_429AD8, dword_429AD4, nullptr) )
      {
        flOldProtect = 186;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_429AF8, off_429B00, dword_429AFC, nullptr) )
      {
        flOldProtect = 187;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_429B20, off_429B28, dword_429B24, nullptr) )
      {
        flOldProtect = 187;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_429B48, off_429B50, dword_429B4C, nullptr) )
      {
        flOldProtect = 188;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_429B70, off_429B78, dword_429B74, nullptr) )
      {
        flOldProtect = 188;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_429B98, off_429BA0, dword_429B9C, nullptr) )
      {
        flOldProtect = 189;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_429BC0, off_429BC8, dword_429BC4, nullptr) )
      {
        flOldProtect = 189;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_429BE8, off_429BF0, dword_429BEC, nullptr) )
      {
        flOldProtect = 190;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_429C10, off_429C18, dword_429C14, nullptr) )
      {
        flOldProtect = 190;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_429C38, off_429C40, dword_429C3C, nullptr) )
      {
        flOldProtect = 191;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_429C60, off_429C68, dword_429C64, nullptr) )
      {
        flOldProtect = 191;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_429C88, off_429C90, dword_429C8C, nullptr) )
      {
        flOldProtect = 192;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_429CB0, off_429CB8, dword_429CB4, nullptr) )
      {
        flOldProtect = 192;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_429CD8, off_429CE0, dword_429CDC, nullptr) )
      {
        flOldProtect = 193;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_429D00, off_429D08, dword_429D04, nullptr) )
      {
        flOldProtect = 195;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_429DB0, off_429DB8, dword_429DB4, nullptr) )
      {
        flOldProtect = 194;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_41F8E0, off_41F8E8, dword_41F8E4, nullptr) )
      {
        flOldProtect = 204;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_41F908, off_41F910, dword_41F90C, nullptr) )
      {
        flOldProtect = 203;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_41F8B8, off_41F8C0, dword_41F8BC, nullptr) )
      {
        flOldProtect = 206;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6440), &Buffer, 1u, nullptr) )
      {
        flOldProtect = 268;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42A560, off_42A568, dword_42A564, nullptr) )
      {
        flOldProtect = 279;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42A5C0, off_42A5C8, dword_42A5C4, nullptr) )
      {
        flOldProtect = 284;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), off_42AFA0, off_42AFA8, dword_42AFA4, nullptr) )
      {
        flOldProtect = 281;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42B1B0, off_42B1B8, dword_42B1B4, nullptr) )
      {
        flOldProtect = 291;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), off_42B278, off_42B280, dword_42B27C, nullptr) )
      {
        flOldProtect = 293;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), off_42B2A0, off_42B2A8, dword_42B2A4, nullptr) )
      {
        flOldProtect = 293;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), off_42B388, off_42B390, dword_42B38C, nullptr) )
      {
        flOldProtect = 295;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), off_42B3B0, off_42B3B8, dword_42B3B4, nullptr) )
      {
        flOldProtect = 295;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), off_42B3D8, off_42B3E0, dword_42B3DC, nullptr) )
      {
        flOldProtect = 295;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_41F988, off_41F990, dword_41F98C, nullptr) )
      {
        flOldProtect = 235;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_421788, off_421790, dword_42178C, nullptr) )
      {
        flOldProtect = 234;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_4217B8, off_4217C0, dword_4217BC, nullptr) )
      {
        flOldProtect = 233;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_4217E8, off_4217F0, dword_4217EC, nullptr) )
      {
        flOldProtect = 232;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_424240, off_424248, dword_424244, nullptr) )
      {
        flOldProtect = 231;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_424360, off_424368, dword_424364, nullptr) )
      {
        flOldProtect = 230;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_4243E0, off_4243E8, dword_4243E4, nullptr) )
      {
        flOldProtect = 236;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_424408, off_424410, dword_42440C, nullptr) )
      {
        flOldProtect = 237;
        goto LABEL_2181;
      }
      if ( !ReadProcessMemory(*(HANDLE *)(this + 112), dword_4253B4, off_4253BC, dword_4253B8, nullptr) )
      {
        flOldProtect = 238;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_4253A8, off_4253B0, dword_4253AC, nullptr) )
      {
        flOldProtect = 239;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_4253C0, &unk_4253C4, 0x38u, nullptr) )
      {
        flOldProtect = 240;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_427188, off_427190, dword_42718C, nullptr) )
      {
        flOldProtect = 241;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6272), (LPCVOID)(this + 6276), 4u, nullptr) )
      {
        flOldProtect = 308;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6284), (LPCVOID)(this + 6288), 4u, nullptr) )
      {
        flOldProtect = 309;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6296), (LPCVOID)(this + 6300), 4u, nullptr) )
      {
        flOldProtect = 310;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6308), (LPCVOID)(this + 6312), 4u, nullptr) )
      {
        flOldProtect = 311;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6320), (LPCVOID)(this + 6324), 4u, nullptr) )
      {
        flOldProtect = 312;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6236), (LPCVOID)(this + 6240), 1u, nullptr) )
      {
        flOldProtect = 313;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6416), (LPCVOID)(this + 6420), 1u, nullptr) )
      {
        flOldProtect = 314;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6428), (LPCVOID)(this + 6432), 1u, nullptr) )
      {
        flOldProtect = 315;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6452), (LPCVOID)(this + 6456), 4u, nullptr) )
      {
        flOldProtect = 318;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6464), (LPCVOID)(this + 6472), 1u, nullptr) )
      {
        flOldProtect = 320;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6480), (LPCVOID)(this + 6484), 1u, nullptr) )
      {
        flOldProtect = 321;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6468), (LPCVOID)(this + 6472), 1u, nullptr) )
      {
        flOldProtect = 323;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6344), (LPCVOID)(this + 6348), 1u, nullptr) )
      {
        flOldProtect = 325;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6356), (LPCVOID)(this + 6360), 1u, nullptr) )
      {
        flOldProtect = 326;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6368), (LPCVOID)(this + 6372), 1u, nullptr) )
      {
        flOldProtect = 327;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6380), (LPCVOID)(this + 6384), 1u, nullptr) )
      {
        flOldProtect = 328;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6392), (LPCVOID)(this + 6396), 1u, nullptr) )
      {
        flOldProtect = 329;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6332), (LPCVOID)(this + 6336), 1u, nullptr) )
      {
        flOldProtect = 330;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6492), (LPCVOID)(this + 6496), 4u, nullptr) )
      {
        flOldProtect = 324;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6528), (LPCVOID)(this + 6532), 1u, nullptr) )
      {
        flOldProtect = 331;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6504), (LPCVOID)(this + 6508), 4u, nullptr) )
      {
        flOldProtect = 332;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6540), (LPCVOID)(this + 6544), 1u, nullptr) )
      {
        flOldProtect = 333;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6516), (LPCVOID)(this + 6520), 4u, nullptr) )
      {
        flOldProtect = 334;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6404), (LPCVOID)(this + 6408), 1u, nullptr) )
      {
        flOldProtect = 335;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6552), (LPCVOID)(this + 6556), 1u, nullptr) )
      {
        flOldProtect = 340;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6564), (LPCVOID)(this + 6568), 4u, nullptr) )
      {
        flOldProtect = 341;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6636), (LPCVOID)(this + 6640), 1u, nullptr) )
      {
        flOldProtect = 346;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6672), (LPCVOID)(this + 6676), 4u, nullptr) )
      {
        flOldProtect = 348;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6684), (LPCVOID)(this + 6688), 1u, nullptr) )
      {
        flOldProtect = 352;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6740), (LPCVOID)(this + 6744), 1u, nullptr) )
      {
        flOldProtect = 354;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6752), (LPCVOID)(this + 6756), 1u, nullptr) )
      {
        flOldProtect = 355;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6764), (LPCVOID)(this + 6768), 4u, nullptr) )
      {
        flOldProtect = 357;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6776), (LPCVOID)(this + 6780), 1u, nullptr) )
      {
        flOldProtect = 359;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6788), (LPCVOID)(this + 6792), 2u, nullptr) )
      {
        flOldProtect = 360;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6800), (LPCVOID)(this + 6804), 1u, nullptr) )
      {
        flOldProtect = 317;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6812), (LPCVOID)(this + 6816), 1u, nullptr) )
      {
        flOldProtect = 361;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6824), (LPCVOID)(this + 6828), 1u, nullptr) )
      {
        flOldProtect = 362;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6836), (LPCVOID)(this + 6844), 1u, nullptr) )
      {
        flOldProtect = 363;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6840), (LPCVOID)(this + 6844), 1u, nullptr) )
      {
        flOldProtect = 363;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6864), (LPCVOID)(this + 6868), 1u, nullptr) )
      {
        flOldProtect = 365;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6928), (LPCVOID)(this + 6932), 1u, nullptr) )
      {
        flOldProtect = 356;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6940), (LPCVOID)(this + 6944), 1u, nullptr) )
      {
        flOldProtect = 371;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6964), (LPCVOID)(this + 6968), 4u, nullptr) )
      {
        flOldProtect = 378;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6976), (LPCVOID)(this + 6980), 1u, nullptr) )
      {
        flOldProtect = 380;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6988), (LPCVOID)(this + 6992), 4u, nullptr) )
      {
        flOldProtect = 381;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7000), (LPCVOID)(this + 7004), 1u, nullptr) )
      {
        flOldProtect = 382;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7012), (LPCVOID)(this + 7024), 4u, nullptr) )
      {
        flOldProtect = 385;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7016), (LPCVOID)(this + 7020), 4u, nullptr) )
      {
        flOldProtect = 386;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7028), (LPCVOID)(this + 7032), 1u, nullptr) )
      {
        flOldProtect = 379;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7040), (LPCVOID)(this + 7044), 1u, nullptr) )
      {
        flOldProtect = 387;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7064), (LPCVOID)(this + 7068), 1u, nullptr) )
      {
        flOldProtect = 390;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7076), (LPCVOID)(this + 7080), 1u, nullptr) )
      {
        flOldProtect = 391;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7088), (LPCVOID)(this + 7092), 4u, nullptr) )
      {
        flOldProtect = 393;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7108), (LPCVOID)(this + 7112), 1u, nullptr) )
      {
        flOldProtect = 403;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7120), (LPCVOID)(this + 7124), 1u, nullptr) )
      {
        flOldProtect = 372;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7132), (LPCVOID)(this + 7136), 4u, nullptr) )
      {
        flOldProtect = 405;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7144), (LPCVOID)(this + 7148), 1u, nullptr) )
      {
        flOldProtect = 370;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7168), (LPCVOID)(this + 7172), 1u, nullptr) )
      {
        flOldProtect = 407;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7180), (LPCVOID)(this + 7184), 4u, nullptr) )
      {
        flOldProtect = 409;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7192), (LPCVOID)(this + 7196), 1u, nullptr) )
      {
        flOldProtect = 410;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7204), (LPCVOID)(this + 7212), 1u, nullptr) )
      {
        flOldProtect = 414;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7208), (LPCVOID)(this + 7212), 1u, nullptr) )
      {
        flOldProtect = 414;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7256), (LPCVOID)(this + 7260), 1u, nullptr) )
      {
        flOldProtect = 420;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7268), (LPCVOID)(this + 7272), 1u, nullptr) )
      {
        flOldProtect = 422;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7280), (LPCVOID)(this + 7284), 1u, nullptr) )
      {
        flOldProtect = 423;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7292), (LPCVOID)(this + 7296), 4u, nullptr) )
      {
        flOldProtect = 425;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(
              *(HANDLE *)(this + 112),
              (LPVOID)(*(_DWORD *)(this + 7304) - 32),
              (LPCVOID)(this + 7308),
              1u,
              nullptr) )
      {
        flOldProtect = 301;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7304), (LPCVOID)(this + 7308), 1u, nullptr) )
      {
        flOldProtect = 301;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7316), (LPCVOID)(this + 7320), 1u, nullptr) )
      {
        flOldProtect = 427;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7328), (LPCVOID)(this + 7332), 1u, nullptr) )
      {
        flOldProtect = 428;
        goto LABEL_2181;
      }
      v57 = (LPVOID *)&unk_42C258;
      do
      {
        if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(v57 - 2), v57, (SIZE_T)*(v57 - 1), nullptr) )
        {
          flOldProtect = 1149;
          goto LABEL_2181;
        }
        v57 += 4;
      }
      while ( (int)v57 < (int)&dword_42C4F8 );
      v58 = (LPVOID *)&unk_42C620;
      do
      {
        if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(v58 - 2), v58, (SIZE_T)*(v58 - 1), nullptr) )
        {
          flOldProtect = 1192;
          goto LABEL_2181;
        }
        v58 += 4;
      }
      while ( (int)v58 < (int)&dword_42C7D0 );
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7480), (LPCVOID)(this + 7484), 1u, nullptr) )
      {
        flOldProtect = 1152;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7492), (LPCVOID)(this + 7504), 1u, nullptr) )
      {
        flOldProtect = 1153;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7496), (LPCVOID)(this + 7504), 1u, nullptr) )
      {
        flOldProtect = 1153;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7500), (LPCVOID)(this + 7512), 1u, nullptr) )
      {
        flOldProtect = 1153;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7520), (LPCVOID)(this + 7524), 1u, nullptr) )
      {
        flOldProtect = 1150;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7532), (LPCVOID)(this + 7536), 1u, nullptr) )
      {
        flOldProtect = 1167;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7544), (LPCVOID)(this + 7548), 4u, nullptr) )
      {
        flOldProtect = 1167;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7556), (LPCVOID)(this + 7560), 1u, nullptr) )
      {
        flOldProtect = 1167;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7580), (LPCVOID)(this + 7584), 1u, nullptr) )
      {
        flOldProtect = 1171;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7592), (LPCVOID)(this + 7596), 4u, nullptr) )
      {
        flOldProtect = 1175;
        goto LABEL_2181;
      }
      if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7604), (LPCVOID)(this + 7608), 4u, nullptr) )
      {
        flOldProtect = 1175;
        goto LABEL_2181;
      }
    }
    if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 4404), (LPCVOID)(this + 4408), 2u, nullptr) )
    {
      flOldProtect = 392;
      goto LABEL_2181;
    }
    if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 3700), (LPCVOID)(this + 500), 0xC80u, nullptr) )
    {
      flOldProtect = 453;
      goto LABEL_2181;
    }
    if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 4400), (LPCVOID)(this + 3704), 0x2B8u, nullptr) )
    {
      flOldProtect = 500;
      goto LABEL_2181;
    }
    byte_42F164 = *(_BYTE *)(this + 372);
    byte_42F165 = *(_BYTE *)(this + 376);
    byte_42F166 = *(_BYTE *)(this + 380);
    byte_42F167 = *(_BYTE *)(this + 384);
    byte_42F168 = *(_BYTE *)(this + 388);
    byte_42F169 = *(_BYTE *)(this + 392);
    byte_42F16A = *(_BYTE *)(this + 396);
    byte_42F16B = *(_BYTE *)(this + 400);
    byte_42F16C = *(_BYTE *)(this + 404);
    if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F160, &byte_42F164, 9u, nullptr) )
    {
      flOldProtect = 300;
      goto LABEL_2181;
    }
    flOldProtect = *(_DWORD *)(this + 408);
    if ( !WriteProcessMemory(*(HANDLE *)(this + 112), (char *)dword_42F394 + 2, &flOldProtect, 4u, nullptr) )
    {
      flOldProtect = 366;
      goto LABEL_2181;
    }
    if ( !WriteProcessMemory(*(HANDLE *)(this + 112), (char *)dword_42F194 + 12, &flOldProtect, 4u, nullptr) )
    {
      flOldProtect = 366;
      goto LABEL_2181;
    }
    flOldProtect = *(_DWORD *)(this + 412);
    if ( !WriteProcessMemory(*(HANDLE *)(this + 112), (char *)dword_42F4A0 + 29, &flOldProtect, 1u, nullptr) )
    {
      flOldProtect = 395;
      goto LABEL_2181;
    }
    flOldProtect = *(_DWORD *)(this + 7104) + 4 * *(_DWORD *)(this + 416);
    if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7100), &flOldProtect, 1u, nullptr) )
    {
      flOldProtect = 401;
      goto LABEL_2181;
    }
    flOldProtect = *(_DWORD *)(this + 224) == 0;
    v59 = WriteProcessMemory(
            *(HANDLE *)(this + 112),
            (LPVOID)dword_4264D0[3 * flOldProtect],
            *(&off_4264D8 + 3 * flOldProtect),
            dword_4264D4[3 * flOldProtect],
            nullptr);
    if ( !v59 )
    {
      flOldProtect = 971;
      goto LABEL_2181;
    }
    flOldProtect = *(_DWORD *)(this + 420);
    if ( flOldProtect != 0 )
      v59 = WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7616), &flOldProtect, 4u, nullptr);
    if ( !v59 )
    {
      flOldProtect = 373;
      goto LABEL_2181;
    }
    flOldProtect = 40 - 2 * *(_DWORD *)(this + 424);
    if ( !WriteProcessMemory(*(HANDLE *)(this + 112), (char *)dword_42F1E0 + 8, &flOldProtect, 1u, nullptr) )
    {
      flOldProtect = 408;
      goto LABEL_2181;
    }
    flOldProtect = *(_DWORD *)(this + 428);
    if ( flOldProtect != 0 )
      flOldProtect = 10 - flOldProtect;
    if ( !WriteProcessMemory(*(HANDLE *)(this + 112), (LPVOID)0x43F4CC, &flOldProtect, 1u, nullptr) )
    {
      flOldProtect = 419;
      goto LABEL_2181;
    }
    if ( !WriteProcessMemory(*(HANDLE *)(this + 112), (LPVOID)0x43F4CF, (LPCVOID)(this + 432), 1u, nullptr) )
    {
      flOldProtect = 426;
      goto LABEL_2181;
    }
    if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7360), (LPCVOID)(this + 436), 1u, nullptr) )
    {
      flOldProtect = 421;
      goto LABEL_2181;
    }
    if ( !WriteProcessMemory(
            *(HANDLE *)(this + 112),
            (LPVOID)(*(_DWORD *)(this + 7360) + 8),
            (LPCVOID)(this + 440),
            1u,
            nullptr) )
    {
      flOldProtect = 421;
      goto LABEL_2181;
    }
    if ( !WriteProcessMemory(
            *(HANDLE *)(this + 112),
            (LPVOID)(*(_DWORD *)(this + 7360) + 16),
            (LPCVOID)(this + 444),
            1u,
            nullptr) )
    {
      flOldProtect = 421;
      goto LABEL_2181;
    }
    if ( !WriteProcessMemory(
            *(HANDLE *)(this + 112),
            (LPVOID)(*(_DWORD *)(this + 7360) + 24),
            (LPCVOID)(this + 448),
            1u,
            nullptr) )
    {
      flOldProtect = 421;
      goto LABEL_2181;
    }
    if ( !WriteProcessMemory(
            *(HANDLE *)(this + 112),
            (LPVOID)(*(_DWORD *)(this + 7360) + 32),
            (LPCVOID)(this + 452),
            1u,
            nullptr) )
    {
      flOldProtect = 421;
      goto LABEL_2181;
    }
    if ( !WriteProcessMemory(*(HANDLE *)(this + 112), (LPVOID)0x43FF19, (LPCVOID)(this + 456), 1u, nullptr) )
    {
      flOldProtect = 389;
      goto LABEL_2181;
    }
    flOldProtect = 4 - (*(_DWORD *)(this + 456) >> 2);
    if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6576), &flOldProtect, 1u, nullptr) )
    {
      flOldProtect = 337;
      goto LABEL_2181;
    }
    if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7340), (LPCVOID)(this + 460), 1u, nullptr) )
    {
      flOldProtect = 338;
      goto LABEL_2181;
    }
    if ( !WriteProcessMemory(*(HANDLE *)(this + 112), (LPVOID)0x43FF1A, (LPCVOID)(this + 464), 1u, nullptr) )
    {
      flOldProtect = 430;
      goto LABEL_2181;
    }
    if ( !WriteProcessMemory(*(HANDLE *)(this + 112), (LPVOID)0x43FF1D, (LPCVOID)(this + 468), 1u, nullptr) )
    {
      flOldProtect = 347;
      goto LABEL_2181;
    }
    if ( !WriteProcessMemory(*(HANDLE *)(this + 112), (LPVOID)0x43F3D1, (LPCVOID)(this + 472), 1u, nullptr) )
    {
      flOldProtect = 432;
      goto LABEL_2181;
    }
    if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7364), (LPCVOID)(this + 476), 1u, nullptr) )
    {
      flOldProtect = 434;
      goto LABEL_2181;
    }
    flOldProtect = (unsigned __int8)*(_DWORD *)(this + 488)
                 + (((unsigned __int8)*(_DWORD *)(this + 484)
                   + (((unsigned __int8)*(_DWORD *)(this + 480) + ((*(_DWORD *)(this + 492) & 0x7F) << 8)) << 8)) << 8);
    if ( !WriteProcessMemory(*(HANDLE *)(this + 112), (LPVOID)0x43F887, &flOldProtect, 4u, nullptr) )
    {
      flOldProtect = 412;
      goto LABEL_2181;
    }
    if ( !WriteProcessMemory(*(HANDLE *)(this + 112), (LPVOID)0x43F88F, (LPCVOID)(this + 496), 1u, nullptr) )
    {
      flOldProtect = 418;
      goto LABEL_2181;
    }
    if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 4828), &dword_42D948, 0x190u, nullptr) )
    {
      flOldProtect = 452;
      goto LABEL_2181;
    }
    if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 4832), &byte_42DAD8, 0x32u, nullptr) )
    {
      flOldProtect = 451;
      goto LABEL_2181;
    }
    flOldProtect = *(_DWORD *)(this + 148) != 0 ? 0x32 : 0;
    if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6224), &flOldProtect, 1u, nullptr) )
    {
      flOldProtect = 302;
      goto LABEL_2181;
    }
    if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6228), &flOldProtect, 1u, nullptr) )
    {
      flOldProtect = 302;
      goto LABEL_2181;
    }
    if ( *(_DWORD *)(this + 208) != 0 )
      flOldProtect = *(_DWORD *)(this + 6588);
    else
      flOldProtect = *(_DWORD *)(this + 6592);
    if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6584), &flOldProtect, 1u, nullptr) )
    {
      flOldProtect = 344;
      goto LABEL_2181;
    }
    flOldProtect = *(_DWORD *)(this + 264) != 0 ? 47513 : 10219;
    if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F2B0, &flOldProtect, 2u, nullptr) )
    {
      flOldProtect = 342;
      goto LABEL_2181;
    }
    flOldProtect = *(_DWORD *)(this + 216) != 0 ? 22 : 10;
    if ( !WriteProcessMemory(*(HANDLE *)(this + 112), (LPVOID)(dword_41FFA4 + 24), &flOldProtect, 1u, nullptr) )
    {
      flOldProtect = 343;
      goto LABEL_2181;
    }
    v60 = -(*(_DWORD *)(this + 220) != 0);
    LOBYTE(v60) = v60 & 0xFE;
    flOldProtect = v60 + 204;
    if ( !WriteProcessMemory(*(HANDLE *)(this + 112), (char *)dword_42F49C + 88, &flOldProtect, 1u, nullptr) )
    {
      flOldProtect = 349;
      goto LABEL_2181;
    }
    if ( *(_DWORD *)(this + 212) != 0 )
      flOldProtect = *(_DWORD *)(this + 6608);
    else
      flOldProtect = *(_DWORD *)(this + 6612);
    if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6596), &flOldProtect, 1u, nullptr) )
    {
      flOldProtect = 345;
      goto LABEL_2181;
    }
    if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6600), &flOldProtect, 1u, nullptr) )
    {
      flOldProtect = 345;
      goto LABEL_2181;
    }
    if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6604), &flOldProtect, 1u, nullptr) )
    {
      flOldProtect = 345;
      goto LABEL_2181;
    }
    flOldProtect = *(_DWORD *)(this + 228) == 0;
    if ( !WriteProcessMemory(
            *(HANDLE *)(this + 112),
            (LPVOID)dword_424D20[3 * flOldProtect],
            *(&off_424D28 + 3 * flOldProtect),
            dword_424D24[3 * flOldProtect],
            nullptr) )
    {
      flOldProtect = 929;
      goto LABEL_2181;
    }
    if ( *(_DWORD *)(this + 228) != 0 )
      flOldProtect = *(_DWORD *)(this + 7056);
    else
      flOldProtect = *(_DWORD *)(this + 7060);
    if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7052), &flOldProtect, 1u, nullptr) )
    {
      flOldProtect = 406;
      goto LABEL_2181;
    }
    flOldProtect = *(_DWORD *)(this + 228) != 0;
    if ( !WriteProcessMemory(
            *(HANDLE *)(this + 112),
            (LPVOID)dword_4256A0[3 * flOldProtect],
            *(&off_4256A8 + 3 * flOldProtect),
            dword_4256A4[3 * flOldProtect],
            nullptr) )
    {
      flOldProtect = 927;
      goto LABEL_2181;
    }
    flOldProtect = *(_DWORD *)(this + 228) == 0;
    if ( !WriteProcessMemory(
            *(HANDLE *)(this + 112),
            (LPVOID)dword_428B10[3 * flOldProtect],
            *(&off_428B18 + 3 * flOldProtect),
            dword_428B14[3 * flOldProtect],
            nullptr) )
    {
      flOldProtect = 1087;
      goto LABEL_2181;
    }
    flOldProtect = *(_DWORD *)(this + 288) == 0;
    if ( !WriteProcessMemory(
            *(HANDLE *)(this + 112),
            (LPVOID)dword_427A70[3 * flOldProtect],
            *(&off_427A78 + 3 * flOldProtect),
            dword_427A74[3 * flOldProtect],
            nullptr) )
    {
      flOldProtect = 1032;
      goto LABEL_2181;
    }
    flOldProtect = *(_DWORD *)(this + 336) == 0;
    if ( !WriteProcessMemory(
            *(HANDLE *)(this + 112),
            (LPVOID)dword_429038[3 * flOldProtect],
            *(&off_429040 + 3 * flOldProtect),
            dword_42903C[3 * flOldProtect],
            nullptr) )
    {
      flOldProtect = 1104;
      goto LABEL_2181;
    }
    if ( *(_DWORD *)(this + 232) != 0 )
      flOldProtect = *(_DWORD *)(this + 6720);
    else
      flOldProtect = *(_DWORD *)(this + 6724);
    if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6716), &flOldProtect, 1u, nullptr) )
    {
      flOldProtect = 336;
      goto LABEL_2181;
    }
    if ( *(_DWORD *)(this + 232) != 0 )
      flOldProtect = *(_DWORD *)(this + 6732);
    else
      flOldProtect = *(_DWORD *)(this + 6736);
    if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6728), &flOldProtect, 1u, nullptr) )
    {
      flOldProtect = 336;
      goto LABEL_2181;
    }
    flOldProtect = *(_DWORD *)(this + 272) == 0;
    if ( !WriteProcessMemory(
            *(HANDLE *)(this + 112),
            (LPVOID)dword_4279F8[3 * flOldProtect],
            *(&off_427A00 + 3 * flOldProtect),
            dword_4279FC[3 * flOldProtect],
            nullptr) )
    {
      flOldProtect = 1007;
      goto LABEL_2181;
    }
    flOldProtect = *(_DWORD *)(this + 152) != 0 ? 5 : 0;
    if ( !WriteProcessMemory(*(HANDLE *)(this + 112), (char *)dword_42F454 + 26, &flOldProtect, 1u, nullptr) )
    {
      flOldProtect = 358;
      goto LABEL_2181;
    }
    flOldProtect = *(_DWORD *)(this + 152) != 0;
    if ( !WriteProcessMemory(*(HANDLE *)(this + 112), (char *)dword_42F450 + 9, &flOldProtect, 1u, nullptr) )
    {
      flOldProtect = 358;
      goto LABEL_2181;
    }
    v61 = -(*(_DWORD *)(this + 152) != 0);
    LOBYTE(v61) = v61 & 0x8A;
    flOldProtect = v61 + 235;
    if ( !WriteProcessMemory(*(HANDLE *)(this + 112), (char *)dword_42F3B8 + 28, &flOldProtect, 1u, nullptr) )
    {
      flOldProtect = 358;
      goto LABEL_2181;
    }
    if ( *(_DWORD *)(this + 236) != 0 )
      flOldProtect = *(_DWORD *)(this + 6856);
    else
      flOldProtect = *(_DWORD *)(this + 6860);
    if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6852), &flOldProtect, 1u, nullptr) )
    {
      flOldProtect = 364;
      goto LABEL_2181;
    }
    if ( *(_DWORD *)(this + 240) != 0 )
      flOldProtect = *(_DWORD *)(this + 6892);
    else
      flOldProtect = *(_DWORD *)(this + 6896);
    if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6888), &flOldProtect, 1u, nullptr) )
    {
      flOldProtect = 368;
      goto LABEL_2181;
    }
    if ( *(_DWORD *)(this + 240) != 0 )
      flOldProtect = *(_DWORD *)(this + 6904);
    else
      flOldProtect = *(_DWORD *)(this + 6908);
    if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6900), &flOldProtect, 1u, nullptr) )
    {
      flOldProtect = 368;
      goto LABEL_2181;
    }
    if ( *(_DWORD *)(this + 240) != 0 )
      flOldProtect = *(_DWORD *)(this + 6916);
    else
      flOldProtect = *(_DWORD *)(this + 6920);
    if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6912), &flOldProtect, 1u, nullptr) )
    {
      flOldProtect = 368;
      goto LABEL_2181;
    }
    v62 = -(*(_DWORD *)(this + 244) != 0);
    LOBYTE(v62) = v62 & 0xAE;
    flOldProtect = v62 + 133;
    if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6924), &flOldProtect, 1u, nullptr) )
    {
      flOldProtect = 369;
      goto LABEL_2181;
    }
    flOldProtect = *(_DWORD *)(this + 248) != 0 ? 0 : 3;
    if ( !WriteProcessMemory(*(HANDLE *)(this + 112), (char *)dword_42F364 + 41, &flOldProtect, 1u, nullptr) )
    {
      flOldProtect = 399;
      goto LABEL_2181;
    }
    if ( *(_DWORD *)(this + 252) != 0 )
      flOldProtect = *(_DWORD *)(this + 6956);
    else
      flOldProtect = *(_DWORD *)(this + 6960);
    if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6952), &flOldProtect, 1u, nullptr) )
    {
      flOldProtect = 350;
      goto LABEL_2181;
    }
    if ( *(_DWORD *)(this + 172) != 0 )
      flOldProtect = *(_DWORD *)(this + 7160);
    else
      flOldProtect = *(_DWORD *)(this + 7164);
    if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7156), &flOldProtect, 1u, nullptr) )
    {
      flOldProtect = 394;
      goto LABEL_2181;
    }
    flOldProtect = *(_DWORD *)(this + 180) != 0;
    if ( !WriteProcessMemory(*(HANDLE *)(this + 112), (LPVOID)0x43FF1C, &flOldProtect, 1u, nullptr) )
    {
      flOldProtect = 411;
      goto LABEL_2181;
    }
    flOldProtect = *(_DWORD *)(this + 268) != 0 ? 6 : 0;
    if ( !WriteProcessMemory(*(HANDLE *)(this + 112), (char *)dword_42F27C + 1, &flOldProtect, 1u, nullptr) )
    {
      flOldProtect = 400;
      goto LABEL_2181;
    }
    flOldProtect = *(_DWORD *)(this + 168) != 0 ? 116 : 235;
    if ( !WriteProcessMemory(*(HANDLE *)(this + 112), (char *)dword_42F33C + 45, &flOldProtect, 1u, nullptr) )
    {
      flOldProtect = 388;
      goto LABEL_2181;
    }
    flOldProtect = *(_DWORD *)(this + 156) != 0 ? 3 : 1;
    if ( !WriteProcessMemory(*(HANDLE *)(this + 112), (LPVOID)(dword_41FD34 + 3), &flOldProtect, 1u, nullptr) )
    {
      flOldProtect = 374;
      goto LABEL_2181;
    }
    flOldProtect = *(_DWORD *)(this + 156) != 0 ? 9 : 5;
    if ( !WriteProcessMemory(*(HANDLE *)(this + 112), (char *)dword_41FDC0 + 29, &flOldProtect, 1u, nullptr) )
    {
      flOldProtect = 374;
      goto LABEL_2181;
    }
    flOldProtect = *(_DWORD *)(this + 160) != 0;
    if ( !WriteProcessMemory(*(HANDLE *)(this + 112), (LPVOID)0x43FF16, &flOldProtect, 1u, nullptr) )
    {
      flOldProtect = 375;
      goto LABEL_2181;
    }
    if ( *(_DWORD *)(this + 276) != 0 )
      flOldProtect = *(_DWORD *)(this + 6704);
    else
      flOldProtect = *(_DWORD *)(this + 6708);
    if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6712), &flOldProtect, 1u, nullptr) )
    {
      flOldProtect = 396;
      goto LABEL_2181;
    }
    if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6700), &flOldProtect, 1u, nullptr) )
    {
      flOldProtect = 319;
      goto LABEL_2181;
    }
    if ( !WriteProcessMemory(
            *(HANDLE *)(this + 112),
            (LPVOID)(*(_DWORD *)(this + 6700) + 48),
            &flOldProtect,
            1u,
            nullptr) )
    {
      flOldProtect = 319;
      goto LABEL_2181;
    }
    if ( !WriteProcessMemory(
            *(HANDLE *)(this + 112),
            (LPVOID)(*(_DWORD *)(this + 6700) + 96),
            &flOldProtect,
            1u,
            nullptr) )
    {
      flOldProtect = 319;
      goto LABEL_2181;
    }
    if ( !WriteProcessMemory(
            *(HANDLE *)(this + 112),
            (LPVOID)(*(_DWORD *)(this + 6700) + 144),
            &flOldProtect,
            1u,
            nullptr) )
    {
      flOldProtect = 319;
      goto LABEL_2181;
    }
    flOldProtect = *(_DWORD *)(this + 256) != 0 ? 3051 : 1795;
    if ( !WriteProcessMemory(*(HANDLE *)(this + 112), (char *)dword_42F140 + 14, &flOldProtect, 2u, nullptr) )
    {
      flOldProtect = 376;
      goto LABEL_2181;
    }
    flOldProtect = *(_DWORD *)(this + 260) != 0 ? 0xE : 0;
    if ( !WriteProcessMemory(*(HANDLE *)(this + 112), (char *)dword_42F36C + 1, &flOldProtect, 1u, nullptr) )
    {
      flOldProtect = 377;
      goto LABEL_2181;
    }
    flOldProtect = *(_DWORD *)(this + 176) != 0 ? 86 : 195;
    if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F1A8, &flOldProtect, 1u, nullptr) )
    {
      flOldProtect = 351;
      goto LABEL_2181;
    }
    v63 = -(*(_DWORD *)(this + 164) != 0);
    LOBYTE(v63) = v63 & 0x8A;
    flOldProtect = v63 + 235;
    if ( !WriteProcessMemory(*(HANDLE *)(this + 112), (char *)dword_42F52C + 20, &flOldProtect, 1u, nullptr) )
    {
      flOldProtect = 384;
      goto LABEL_2181;
    }
    flOldProtect = *(_DWORD *)(this + 236) != 0;
    if ( !WriteProcessMemory(*(HANDLE *)(this + 112), (LPVOID)0x43F4CD, &flOldProtect, 1u, nullptr) )
    {
      flOldProtect = 364;
      goto LABEL_2181;
    }
    flOldProtect = *(_DWORD *)(this + 280) != 0 ? 86 : 195;
    if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F1A0, &flOldProtect, 1u, nullptr) )
    {
      flOldProtect = 404;
      goto LABEL_2181;
    }
    if ( *(_DWORD *)(this + 284) != 0 )
      flOldProtect = *(_DWORD *)(this + 6880);
    else
      flOldProtect = *(_DWORD *)(this + 6884);
    if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6876), &flOldProtect, 1u, nullptr) )
    {
      flOldProtect = 316;
      goto LABEL_2181;
    }
    if ( *(_DWORD *)(this + 284) != 0 )
      flOldProtect = *(_DWORD *)(this + 7440);
    else
      flOldProtect = *(_DWORD *)(this + 7444);
    if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7436), &flOldProtect, 1u, nullptr) )
    {
      flOldProtect = 1145;
      goto LABEL_2181;
    }
    flOldProtect = *(_DWORD *)(this + 292) != 0;
    if ( !WriteProcessMemory(
            *(HANDLE *)(this + 112),
            (LPVOID)dword_41F9E0[3 * flOldProtect],
            *(&off_41F9E8 + 3 * flOldProtect),
            dword_41F9E4[3 * flOldProtect],
            nullptr) )
    {
      flOldProtect = 109;
      goto LABEL_2181;
    }
    flOldProtect = *(_DWORD *)(this + 300) == 0;
    if ( !WriteProcessMemory(
            *(HANDLE *)(this + 112),
            (LPVOID)dword_422998[3 * flOldProtect],
            *(&off_4229A0 + 3 * flOldProtect),
            dword_42299C[3 * flOldProtect],
            nullptr) )
    {
      flOldProtect = 758;
      goto LABEL_2181;
    }
    flOldProtect = *(_DWORD *)(this + 188) == 0;
    if ( !WriteProcessMemory(
            *(HANDLE *)(this + 112),
            (LPVOID)dword_422748[3 * flOldProtect],
            *(&off_422750 + 3 * flOldProtect),
            dword_42274C[3 * flOldProtect],
            nullptr) )
    {
      flOldProtect = 740;
      goto LABEL_2181;
    }
    flOldProtect = *(_DWORD *)(this + 304) == 0;
    if ( !WriteProcessMemory(
            *(HANDLE *)(this + 112),
            (LPVOID)dword_4285E8[3 * flOldProtect],
            *(&off_4285F0 + 3 * flOldProtect),
            dword_4285EC[3 * flOldProtect],
            nullptr) )
    {
      flOldProtect = 242;
      goto LABEL_2181;
    }
    if ( *(_DWORD *)(this + 304) != 0 )
      flOldProtect = *(_DWORD *)(this + 7392);
    else
      flOldProtect = *(_DWORD *)(this + 7396);
    if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7388), &flOldProtect, 1u, nullptr) )
    {
      flOldProtect = 1111;
      goto LABEL_2181;
    }
    flOldProtect = *(_DWORD *)(this + 192) != 0;
    if ( !WriteProcessMemory(*(HANDLE *)(this + 112), (LPVOID)0x43F4CE, &flOldProtect, 1u, nullptr) )
    {
      flOldProtect = 424;
      goto LABEL_2181;
    }
    if ( *(_DWORD *)(this + 196) != 0 )
      flOldProtect = *(_DWORD *)(this + 6652);
    else
      flOldProtect = *(_DWORD *)(this + 6656);
    if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6648), &flOldProtect, 1u, nullptr) )
    {
      flOldProtect = 347;
      goto LABEL_2181;
    }
    if ( *(_DWORD *)(this + 196) != 0 )
      flOldProtect = *(_DWORD *)(this + 6664);
    else
      flOldProtect = *(_DWORD *)(this + 6668);
    if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6660), &flOldProtect, 1u, nullptr) )
    {
      flOldProtect = 347;
      goto LABEL_2181;
    }
    flOldProtect = *(_DWORD *)(this + 308) != 0 ? 61943 : 747;
    if ( !WriteProcessMemory(*(HANDLE *)(this + 112), (char *)dword_42F49C + 33, &flOldProtect, 2u, nullptr) )
    {
      flOldProtect = 349;
      goto LABEL_2181;
    }
    flOldProtect = *(_DWORD *)(this + 200) == 0;
    if ( !WriteProcessMemory(
            *(HANDLE *)(this + 112),
            (LPVOID)dword_428AD8[3 * flOldProtect],
            (&off_428AE0)[3 * flOldProtect],
            dword_428ADC[3 * flOldProtect],
            nullptr) )
    {
      flOldProtect = 1163;
      goto LABEL_2181;
    }
    flOldProtect = *(_DWORD *)(this + 312) == 0;
    if ( !WriteProcessMemory(
            *(HANDLE *)(this + 112),
            (LPVOID)dword_428B70[3 * flOldProtect],
            *(&off_428B78 + 3 * flOldProtect),
            dword_428B74[3 * flOldProtect],
            nullptr) )
    {
      flOldProtect = 1089;
      goto LABEL_2181;
    }
    flOldProtect = *(_DWORD *)(this + 316) != 0;
    if ( !WriteProcessMemory(*(HANDLE *)(this + 112), (LPVOID)0x43FF1B, &flOldProtect, 1u, nullptr) )
    {
      flOldProtect = 431;
      goto LABEL_2181;
    }
    flOldProtect = *(_DWORD *)(this + 320) == 0;
    if ( !WriteProcessMemory(
            *(HANDLE *)(this + 112),
            (LPVOID)dword_428E78[3 * flOldProtect],
            *(&off_428E80 + 3 * flOldProtect),
            dword_428E7C[3 * flOldProtect],
            nullptr) )
    {
      flOldProtect = 1098;
      goto LABEL_2181;
    }
    if ( *(_DWORD *)(this + 324) != 0 )
      flOldProtect = *(_DWORD *)(this + 7352);
    else
      flOldProtect = *(_DWORD *)(this + 7356);
    if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7348), &flOldProtect, 1u, nullptr) )
    {
      flOldProtect = 433;
      goto LABEL_2181;
    }
    if ( *(_DWORD *)(this + 328) != 0 )
      flOldProtect = *(_DWORD *)(this + 6252);
    else
      flOldProtect = *(_DWORD *)(this + 6256);
    if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6248), &flOldProtect, 1u, nullptr) )
    {
      flOldProtect = 306;
      goto LABEL_2181;
    }
    if ( *(_DWORD *)(this + 328) != 0 )
      flOldProtect = *(_DWORD *)(this + 6264);
    else
      flOldProtect = *(_DWORD *)(this + 6268);
    if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6260), &flOldProtect, 1u, nullptr) )
    {
      flOldProtect = 307;
      goto LABEL_2181;
    }
    if ( *(_DWORD *)(this + 204) != 0 )
      flOldProtect = *(_DWORD *)(this + 7376);
    else
      flOldProtect = *(_DWORD *)(this + 7380);
    if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7372), &flOldProtect, 1u, nullptr) )
    {
      flOldProtect = 435;
      goto LABEL_2181;
    }
    if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7384), &flOldProtect, 1u, nullptr) )
    {
      flOldProtect = 435;
      goto LABEL_2181;
    }
    if ( *(_DWORD *)(this + 332) != 0 )
      flOldProtect = *(_DWORD *)(this + 6628);
    else
      flOldProtect = *(_DWORD *)(this + 6632);
    if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6616), &flOldProtect, 1u, nullptr) )
    {
      flOldProtect = 345;
      goto LABEL_2181;
    }
    if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6620), &flOldProtect, 1u, nullptr) )
    {
      flOldProtect = 345;
      goto LABEL_2181;
    }
    if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 6624), &flOldProtect, 1u, nullptr) )
    {
      flOldProtect = 345;
      goto LABEL_2181;
    }
    if ( *(_DWORD *)(this + 340) != 0 )
      flOldProtect = *(_DWORD *)(this + 7412);
    else
      flOldProtect = *(_DWORD *)(this + 7416);
    if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7400), &flOldProtect, 1u, nullptr) )
    {
      flOldProtect = 1112;
      goto LABEL_2181;
    }
    if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7404), &flOldProtect, 1u, nullptr) )
    {
      flOldProtect = 1112;
      goto LABEL_2181;
    }
    if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7408), &flOldProtect, 1u, nullptr) )
    {
      flOldProtect = 1112;
      goto LABEL_2181;
    }
    flOldProtect = *(_DWORD *)(this + 344) == 0;
    if ( !WriteProcessMemory(
            *(HANDLE *)(this + 112),
            (LPVOID)dword_429178[3 * flOldProtect],
            *(&off_429180 + 3 * flOldProtect),
            dword_42917C[3 * flOldProtect],
            nullptr) )
    {
      flOldProtect = 1116;
      goto LABEL_2181;
    }
    flOldProtect = *(_DWORD *)(this + 344) != 0 ? 1 : 5;
    if ( !WriteProcessMemory(*(HANDLE *)(this + 112), (char *)dword_42F0FC + 9, &flOldProtect, 1u, nullptr) )
    {
      flOldProtect = 1120;
      goto LABEL_2181;
    }
    flOldProtect = 6 - (*(_DWORD *)(this + 348) != 0);
    if ( !WriteProcessMemory(*(HANDLE *)(this + 112), (char *)dword_42F0FC + 4, &flOldProtect, 1u, nullptr) )
    {
      flOldProtect = 1121;
      goto LABEL_2181;
    }
    flOldProtect = *(_DWORD *)(this + 348) == 0;
    if ( !WriteProcessMemory(
            *(HANDLE *)(this + 112),
            (LPVOID)dword_429208[3 * flOldProtect],
            *(&off_429210 + 3 * flOldProtect),
            dword_42920C[3 * flOldProtect],
            nullptr) )
    {
      flOldProtect = 1119;
      goto LABEL_2181;
    }
    if ( *(_DWORD *)(this + 356) != 0 )
      flOldProtect = *(_DWORD *)(this + 7428);
    else
      flOldProtect = *(_DWORD *)(this + 7432);
    if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7420), &flOldProtect, 1u, nullptr) )
    {
      flOldProtect = 1123;
      goto LABEL_2181;
    }
    if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7424), &flOldProtect, 1u, nullptr) )
    {
      flOldProtect = 1123;
      goto LABEL_2181;
    }
    v64 = -(*(_DWORD *)(this + 360) != 0);
    LOBYTE(v64) = v64 & 0x4C;
    flOldProtect = v64 + 195;
    if ( !WriteProcessMemory(*(HANDLE *)(this + 112), (char *)dword_42F150 + 6, &flOldProtect, 1u, nullptr) )
    {
      flOldProtect = 1148;
      goto LABEL_2181;
    }
    if ( *(_DWORD *)(this + 364) != 0 )
      flOldProtect = *(_DWORD *)(this + 7572);
    else
      flOldProtect = *(_DWORD *)(this + 7576);
    if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7568), &flOldProtect, 2u, nullptr) )
    {
      flOldProtect = 1166;
      goto LABEL_2181;
    }
    flOldProtect = *(_DWORD *)(this + 368) != 0 ? 30089 : 59011;
    if ( !WriteProcessMemory(*(HANDLE *)(this + 112), (char *)dword_42B5B0 + 8, &flOldProtect, 2u, nullptr) )
    {
      flOldProtect = 1170;
      goto LABEL_2181;
    }
    flOldProtect = *(_DWORD *)(this + 184) != 0 ? 53811 : 5867;
    if ( !WriteProcessMemory(*(HANDLE *)(this + 112), dword_42F1FC, &flOldProtect, 2u, nullptr) )
    {
      flOldProtect = 413;
      goto LABEL_2181;
    }
    if ( *(_DWORD *)(this + 184) != 0 )
      flOldProtect = *(_DWORD *)(this + 7224);
    else
      flOldProtect = *(_DWORD *)(this + 7228);
    if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7220), &flOldProtect, 1u, nullptr) )
    {
      flOldProtect = 415;
      goto LABEL_2181;
    }
    if ( *(_DWORD *)(this + 184) != 0 )
      flOldProtect = *(_DWORD *)(this + 7236);
    else
      flOldProtect = *(_DWORD *)(this + 7240);
    if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7232), &flOldProtect, 1u, nullptr) )
    {
      flOldProtect = 416;
      goto LABEL_2181;
    }
    if ( *(_DWORD *)(this + 184) != 0 )
      flOldProtect = *(_DWORD *)(this + 7248);
    else
      flOldProtect = *(_DWORD *)(this + 7252);
    if ( !WriteProcessMemory(*(HANDLE *)(this + 112), *(LPVOID *)(this + 7244), &flOldProtect, 1u, nullptr) )
    {
      flOldProtect = 417;
      goto LABEL_2181;
    }
    flOldProtect = *(_DWORD *)(this + 184) != 0;
    if ( !WriteProcessMemory(
            *(HANDLE *)(this + 112),
            (LPVOID)dword_42A780[3 * flOldProtect],
            *(&off_42A788 + 3 * flOldProtect),
            dword_42A784[3 * flOldProtect],
            nullptr) )
    {
      flOldProtect = 286;
      goto LABEL_2181;
    }
    goto LABEL_2113;
  }
  *(_DWORD *)(this + 112) = 0;
  *(_DWORD *)(this + 108) = 0;
  *(_DWORD *)(this + 136) = 0;
  CWnd::SetWindowTextA((CWnd *)(this + 7624), byte_42EDC4);
LABEL_2194:
  v99 = -1;
  CString::~CString((CString *)&v94);
}
