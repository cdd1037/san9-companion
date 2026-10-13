00405480  56                                            push    esi
00405481  8b f1                                         mov     esi, ecx
00405483  6a 01                                         push    1; int
00405485  e8 a0 51 01 00                                call    ?UpdateData@CWnd@@QAEHH@Z; CWnd::UpdateData(int)
0040548A  85 c0                                         test    eax, eax
0040548C  75 02                                         jnz     short loc_405490
0040548E  5e                                            pop     esi
0040548F  c3                                            retn
00405490  8b 86 48 01 00 00                             mov     eax, [esi+148h]
00405496  8b 8e 50 7b 00 00                             mov     ecx, [esi+7B50h]
0040549C  66 8b 96 44 01 00 00                          mov     dx, [esi+144h]
004054A3  8d 04 40                                      lea     eax, [eax+eax*2]
004054A6  66 89 14 41                                   mov     [ecx+eax*2], dx
004054AA  8b 86 48 01 00 00                             mov     eax, [esi+148h]
004054B0  8b 8e 50 7b 00 00                             mov     ecx, [esi+7B50h]
004054B6  66 8b 96 46 01 00 00                          mov     dx, [esi+146h]
004054BD  8d 04 40                                      lea     eax, [eax+eax*2]
004054C0  66 89 54 41 02                                mov     [ecx+eax*2+2], dx
004054C5  8b 86 48 01 00 00                             mov     eax, [esi+148h]
004054CB  8b 8e 50 7b 00 00                             mov     ecx, [esi+7B50h]
004054D1  66 8b 96 42 01 00 00                          mov     dx, [esi+142h]
004054D8  8d 04 40                                      lea     eax, [eax+eax*2]
004054DB  5e                                            pop     esi
004054DC  66 89 54 41 04                                mov     [ecx+eax*2+4], dx
004054E1  b8 01 00 00 00                                mov     eax, 1
004054E6  c3                                            retn
