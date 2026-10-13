004054F0  8b 81 48 01 00 00                             mov     eax, [ecx+148h]
004054F6  8b 91 50 7b 00 00                             mov     edx, [ecx+7B50h]
004054FC  6a 00                                         push    0; int
004054FE  8d 04 40                                      lea     eax, [eax+eax*2]
00405501  8d 04 42                                      lea     eax, [edx+eax*2]
00405504  66 8b 10                                      mov     dx, [eax]
00405507  66 89 91 44 01 00 00                          mov     [ecx+144h], dx
0040550E  66 8b 50 02                                   mov     dx, [eax+2]
00405512  66 89 91 46 01 00 00                          mov     [ecx+146h], dx
00405519  66 8b 40 04                                   mov     ax, [eax+4]
0040551D  66 89 81 42 01 00 00                          mov     [ecx+142h], ax
00405524  e8 01 51 01 00                                call    ?UpdateData@CWnd@@QAEHH@Z; CWnd::UpdateData(int)
00405529  c3                                            retn
