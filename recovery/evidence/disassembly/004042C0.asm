004042C0  b8 b8 2a 00 00                                mov     eax, 2AB8h
004042C5  e8 86 65 01 00                                call    __alloca_probe
004042CA  53                                            push    ebx
004042CB  55                                            push    ebp
004042CC  56                                            push    esi
004042CD  57                                            push    edi
004042CE  8b f9                                         mov     edi, ecx
004042D0  8d b7 c0 01 00 00                             lea     esi, [edi+1C0h]
004042D6  8b ce                                         mov     ecx, esi; this
004042D8  89 74 24 18                                   mov     [esp+2AC8h+var_2AB0], esi
004042DC  e8 bb 63 01 00                                call    ?DestroyMenu@CMenu@@QAEHXZ; CMenu::DestroyMenu(void)
004042E1  8b 87 c8 01 00 00                             mov     eax, [edi+1C8h]
004042E7  8b 48 70                                      mov     ecx, [eax+70h]
004042EA  85 c9                                         test    ecx, ecx
004042EC  0f 84 47 01 00 00                             jz      loc_404439
004042F2  ff 15 68 c3 41 00                             call    ds:CreatePopupMenu; USER32
004042F8  50                                            push    eax; HMENU
004042F9  8b ce                                         mov     ecx, esi; this
004042FB  e8 d8 63 01 00                                call    ?Attach@CMenu@@QAEHPAUHMENU__@@@Z; CMenu::Attach(HMENU__ *)
00404300  85 c0                                         test    eax, eax
00404302  0f 84 31 01 00 00                             jz      loc_404439
00404308  8b 97 c8 01 00 00                             mov     edx, [edi+1C8h]
0040430E  6a 00                                         push    0; lpNumberOfBytesRead
00404310  8d 8c 24 64 01 00 00                          lea     ecx, [esp+2ACCh+Buffer]
00404317  68 68 29 00 00                                push    2968h; nSize
0040431C  8b 42 70                                      mov     eax, [edx+70h]
0040431F  51                                            push    ecx; lpBuffer
00404320  68 38 3c 25 01                                push    1253C38h; lpBaseAddress
00404325  50                                            push    eax; hProcess
00404326  ff 15 3c c0 41 00                             call    ds:ReadProcessMemory; KERNEL32
0040432C  85 c0                                         test    eax, eax
0040432E  0f 84 05 01 00 00                             jz      loc_404439
00404334  be 38 3c 25 01                                mov     esi, 1253C38h
00404339  8d 94 24 18 02 00 00                          lea     edx, [esp+2AC8h+var_28B0]
00404340  8d 8c 24 1c 02 00 00                          lea     ecx, [esp+2AC8h+var_28AC]
00404347  2b d6                                         sub     edx, esi
00404349  2b ce                                         sub     ecx, esi
0040434B  8d 9c 24 94 01 00 00                          lea     ebx, [esp+2AC8h+var_2934]
00404352  33 ed                                         xor     ebp, ebp
00404354  89 54 24 10                                   mov     [esp+2AC8h+var_2AB8], edx
00404358  89 4c 24 14                                   mov     [esp+2AC8h+var_2AB4], ecx
0040435C  2b de                                         sub     ebx, esi
0040435E  f6 04 33 04                                   test    byte ptr [ebx+esi], 4
00404362  0f 85 8b 00 00 00                             jnz     loc_4043F3
00404368  39 34 32                                      cmp     [edx+esi], esi
0040436B  0f 85 82 00 00 00                             jnz     loc_4043F3
00404371  8b 04 31                                      mov     eax, [ecx+esi]
00404374  85 c0                                         test    eax, eax
00404376  74 7b                                         jz      short loc_4043F3
00404378  8b 97 c8 01 00 00                             mov     edx, [edi+1C8h]
0040437E  6a 00                                         push    0; lpNumberOfBytesRead
00404380  8d 4c 24 3c                                   lea     ecx, [esp+2ACCh+var_2A90]
00404384  68 28 01 00 00                                push    128h; nSize
00404389  51                                            push    ecx; lpBuffer
0040438A  50                                            push    eax; lpBaseAddress
0040438B  8b 42 70                                      mov     eax, [edx+70h]
0040438E  50                                            push    eax; hProcess
0040438F  ff 15 3c c0 41 00                             call    ds:ReadProcessMemory; KERNEL32
00404395  85 c0                                         test    eax, eax
00404397  0f 84 9c 00 00 00                             jz      loc_404439
0040439D  8d 4c 24 4d                                   lea     ecx, [esp+2AC8h+var_2A7B]
004043A1  8d 54 24 48                                   lea     edx, [esp+2AC8h+var_2A80]
004043A5  51                                            push    ecx
004043A6  52                                            push    edx
004043A7  8d 44 24 24                                   lea     eax, [esp+2AD0h+NewItem]
004043AB  68 20 f7 41 00                                push    offset Format; "%s%s"
004043B0  50                                            push    eax; Buffer
004043B1  ff 15 08 c3 41 00                             call    ds:sprintf; MSVCRT
004043B7  8d 4c 24 2c                                   lea     ecx, [esp+2AD8h+NewItem]
004043BB  51                                            push    ecx
004043BC  e8 4f 5d 01 00                                call    sub_41A110
004043C1  8a 04 33                                      mov     al, [ebx+esi]
004043C4  83 c4 14                                      add     esp, 14h
004043C7  83 e0 01                                      and     eax, 1
004043CA  8d 54 24 1c                                   lea     edx, [esp+2AC8h+NewItem]
004043CE  8d 8d 03 80 00 00                             lea     ecx, [ebp+8003h]
004043D4  52                                            push    edx; lpNewItem
004043D5  8b 97 c4 01 00 00                             mov     edx, [edi+1C4h]
004043DB  51                                            push    ecx; uIDNewItem
004043DC  c1 e0 03                                      shl     eax, 3
004043DF  50                                            push    eax; uFlags
004043E0  52                                            push    edx; hMenu
004043E1  ff 15 58 c3 41 00                             call    ds:AppendMenuA; USER32
004043E7  85 c0                                         test    eax, eax
004043E9  74 4e                                         jz      short loc_404439
004043EB  8b 4c 24 14                                   mov     ecx, [esp+2AC8h+var_2AB4]
004043EF  8b 54 24 10                                   mov     edx, [esp+2AC8h+var_2AB8]
004043F3  81 c6 d4 00 00 00                             add     esi, 0D4h
004043F9  45                                            inc     ebp
004043FA  81 fe a0 65 25 01                             cmp     esi, 12565A0h
00404400  0f 82 58 ff ff ff                             jb      loc_40435E
00404406  68 f2 03 00 00                                push    3F2h; int
0040440B  8b cf                                         mov     ecx, edi; this
0040440D  e8 a8 62 01 00                                call    ?GetDlgItem@CWnd@@QBEPAV1@H@Z; CWnd::GetDlgItem(int)
00404412  8b 50 20                                      mov     edx, [eax+20h]
00404415  8d 4c 24 28                                   lea     ecx, [esp+2AC8h+Rect]
00404419  51                                            push    ecx; lpRect
0040441A  52                                            push    edx; hWnd
0040441B  ff 15 5c c3 41 00                             call    ds:GetWindowRect; USER32
00404421  8b 44 24 2c                                   mov     eax, [esp+2AC8h+Rect.top]
00404425  8b 4c 24 28                                   mov     ecx, [esp+2AC8h+Rect.left]
00404429  6a 00                                         push    0; struct tagRECT *
0040442B  57                                            push    edi; struct CWnd *
0040442C  50                                            push    eax; int
0040442D  51                                            push    ecx; int
0040442E  8b 4c 24 28                                   mov     ecx, [esp+2AD8h+var_2AB0]; this
00404432  6a 00                                         push    0; unsigned int
00404434  e8 99 62 01 00                                call    ?TrackPopupMenu@CMenu@@QAEHIHHPAVCWnd@@PBUtagRECT@@@Z; CMenu::TrackPopupMenu(uint,int,int,CWnd *,tagRECT const *)
00404439  5f                                            pop     edi
0040443A  5e                                            pop     esi
0040443B  5d                                            pop     ebp
0040443C  5b                                            pop     ebx
0040443D  81 c4 b8 2a 00 00                             add     esp, 2AB8h
00404443  c3                                            retn
