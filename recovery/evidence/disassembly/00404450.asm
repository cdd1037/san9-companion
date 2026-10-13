00404450  53                                            push    ebx
00404451  8b 5c 24 08                                   mov     ebx, [esp+4+Buffer]
00404455  8b c3                                         mov     eax, ebx
00404457  57                                            push    edi
00404458  25 ff ff 00 00                                and     eax, 0FFFFh
0040445D  8b f9                                         mov     edi, ecx
0040445F  3d 03 80 00 00                                cmp     eax, 8003h
00404464  72 6a                                         jb      short loc_4044D0
00404466  3d 34 80 00 00                                cmp     eax, 8034h
0040446B  77 63                                         ja      short loc_4044D0
0040446D  8d 0c 40                                      lea     ecx, [eax+eax*2]
00404470  56                                            push    esi
00404471  6a 00                                         push    0; lpNumberOfBytesRead
00404473  8d 54 24 14                                   lea     edx, [esp+10h+Buffer]
00404477  8d 0c c9                                      lea     ecx, [ecx+ecx*8]
0040447A  6a 01                                         push    1; nSize
0040447C  d1 e1                                         shl     ecx, 1
0040447E  2b c8                                         sub     ecx, eax
00404480  52                                            push    edx; lpBuffer
00404481  8d 04 8d bc 39 bb 00                          lea     eax, ds:0BB39BCh[ecx*4]
00404488  8d 70 34                                      lea     esi, [eax+34h]
0040448B  8b 87 c8 01 00 00                             mov     eax, [edi+1C8h]
00404491  56                                            push    esi; lpBaseAddress
00404492  8b 48 70                                      mov     ecx, [eax+70h]
00404495  51                                            push    ecx; hProcess
00404496  ff 15 3c c0 41 00                             call    ds:ReadProcessMemory; KERNEL32
0040449C  85 c0                                         test    eax, eax
0040449E  74 24                                         jz      short loc_4044C4
004044A0  8a 44 24 10                                   mov     al, byte ptr [esp+0Ch+Buffer]
004044A4  6a 00                                         push    0; lpNumberOfBytesWritten
004044A6  34 01                                         xor     al, 1
004044A8  8d 54 24 14                                   lea     edx, [esp+10h+Buffer]
004044AC  88 44 24 14                                   mov     byte ptr [esp+10h+Buffer], al
004044B0  8b 87 c8 01 00 00                             mov     eax, [edi+1C8h]
004044B6  6a 01                                         push    1; nSize
004044B8  52                                            push    edx; lpBuffer
004044B9  8b 48 70                                      mov     ecx, [eax+70h]
004044BC  56                                            push    esi; lpBaseAddress
004044BD  51                                            push    ecx; hProcess
004044BE  ff 15 40 c0 41 00                             call    ds:WriteProcessMemory; KERNEL32
004044C4  8d 8f c0 01 00 00                             lea     ecx, [edi+1C0h]; this
004044CA  e8 cd 61 01 00                                call    ?DestroyMenu@CMenu@@QAEHXZ; CMenu::DestroyMenu(void)
004044CF  5e                                            pop     esi
004044D0  8b 54 24 10                                   mov     edx, [esp+8+arg_4]
004044D4  8b cf                                         mov     ecx, edi; this
004044D6  52                                            push    edx; int
004044D7  53                                            push    ebx; unsigned int
004044D8  e8 51 60 01 00                                call    ?OnCommand@CWnd@@MAEHIJ@Z; CWnd::OnCommand(uint,long)
004044DD  5f                                            pop     edi
004044DE  5b                                            pop     ebx
004044DF  c2 08 00                                      retn    8
