00403FF0  56                                            push    esi
00403FF1  8b f1                                         mov     esi, ecx
00403FF3  6a 01                                         push    1; int
00403FF5  e8 30 66 01 00                                call    ?UpdateData@CWnd@@QAEHH@Z; CWnd::UpdateData(int)
00403FFA  85 c0                                         test    eax, eax
00403FFC  75 04                                         jnz     short loc_404002
00403FFE  32 c0                                         xor     al, al
00404000  5e                                            pop     esi
00404001  c3                                            retn
00404002  8b 46 7c                                      mov     eax, [esi+7Ch]
00404005  8b 4e 78                                      mov     ecx, [esi+78h]
00404008  3b c8                                         cmp     ecx, eax
0040400A  76 07                                         jbe     short loc_404013
0040400C  68 fc 03 00 00                                push    3FCh
00404011  eb 47                                         jmp     short loc_40405A
00404013  3b 86 80 00 00 00                             cmp     eax, [esi+80h]
00404019  76 07                                         jbe     short loc_404022
0040401B  68 fd 03 00 00                                push    3FDh
00404020  eb 38                                         jmp     short loc_40405A
00404022  8b 46 70                                      mov     eax, [esi+70h]
00404025  8b 4e 6c                                      mov     ecx, [esi+6Ch]
00404028  3b c8                                         cmp     ecx, eax
0040402A  76 07                                         jbe     short loc_404033
0040402C  68 ff 03 00 00                                push    3FFh
00404031  eb 27                                         jmp     short loc_40405A
00404033  3b 46 74                                      cmp     eax, [esi+74h]
00404036  76 07                                         jbe     short loc_40403F
00404038  68 00 04 00 00                                push    400h
0040403D  eb 1b                                         jmp     short loc_40405A
0040403F  8b 46 60                                      mov     eax, [esi+60h]
00404042  8b 4e 64                                      mov     ecx, [esi+64h]
00404045  3b c8                                         cmp     ecx, eax
00404047  76 07                                         jbe     short loc_404050
00404049  68 02 04 00 00                                push    402h
0040404E  eb 0a                                         jmp     short loc_40405A
00404050  3b 46 68                                      cmp     eax, [esi+68h]
00404053  76 25                                         jbe     short loc_40407A
00404055  68 03 04 00 00                                push    403h; int
0040405A  8b ce                                         mov     ecx, esi; this
0040405C  e8 59 66 01 00                                call    ?GetDlgItem@CWnd@@QBEPAV1@H@Z; CWnd::GetDlgItem(int)
00404061  8b c8                                         mov     ecx, eax; this
00404063  e8 4c 66 01 00                                call    ?SetFocus@CWnd@@QAEPAV1@XZ; CWnd::SetFocus(void)
00404068  6a 00                                         push    0; unsigned int
0040406A  6a 00                                         push    0; unsigned int
0040406C  68 0c f7 41 00                                push    offset byte_41F70C; char *
00404071  e8 9c 65 01 00                                call    ?AfxMessageBox@@YGHPBDII@Z; AfxMessageBox(char const *,uint,uint)
00404076  32 c0                                         xor     al, al
00404078  5e                                            pop     esi
00404079  c3                                            retn
0040407A  b0 01                                         mov     al, 1
0040407C  5e                                            pop     esi
0040407D  c3                                            retn
