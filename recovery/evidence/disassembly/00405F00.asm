00405F00  a1 50 00 42 00                                mov     eax, lpAddress
00405F05  83 c0 30                                      add     eax, 30h ; '0'
00405F08  a3 74 f5 42 00                                mov     dword_42F574, eax
00405F0D  c3                                            retn
