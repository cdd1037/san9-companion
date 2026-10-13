0041A400  8b 51 60                                      mov     edx, [ecx+60h]
0041A403  a1 50 00 42 00                                mov     eax, lpAddress
0041A408  2b d0                                         sub     edx, eax
0041A40A  75 03                                         jnz     short loc_41A40F
0041A40C  33 c0                                         xor     eax, eax
0041A40E  c3                                            retn
0041A40F  8d 81 c4 1d 00 00                             lea     eax, [ecx+1DC4h]
0041A415  56                                            push    esi
0041A416  a3 f8 dd 42 00                                mov     dword_42DDF8, eax
0041A41B  8d 81 74 0e 00 00                             lea     eax, [ecx+0E74h]
0041A421  a3 fc dd 42 00                                mov     dword_42DDFC, eax
0041A426  8d 81 70 12 00 00                             lea     eax, [ecx+1270h]
0041A42C  a3 00 de 42 00                                mov     dword_42DE00, eax
0041A431  8d 81 74 12 00 00                             lea     eax, [ecx+1274h]
0041A437  a3 04 de 42 00                                mov     dword_42DE04, eax
0041A43C  8d 81 dc 12 00 00                             lea     eax, [ecx+12DCh]
0041A442  a3 08 de 42 00                                mov     dword_42DE08, eax
0041A447  8d 81 e0 12 00 00                             lea     eax, [ecx+12E0h]
0041A44D  81 c1 5c 14 00 00                             add     ecx, 145Ch
0041A453  a3 0c de 42 00                                mov     dword_42DE0C, eax
0041A458  89 0d 10 de 42 00                             mov     dword_42DE10, ecx
0041A45E  b8 f8 dd 42 00                                mov     eax, offset dword_42DDF8
0041A463  8b 08                                         mov     ecx, [eax]
0041A465  83 c0 04                                      add     eax, 4
0041A468  8b 31                                         mov     esi, [ecx]
0041A46A  03 f2                                         add     esi, edx
0041A46C  3d 1c ed 42 00                                cmp     eax, offset byte_42ED1C
0041A471  89 31                                         mov     [ecx], esi
0041A473  7c ee                                         jl      short loc_41A463
0041A475  b8 01 00 00 00                                mov     eax, 1
0041A47A  5e                                            pop     esi
0041A47B  c3                                            retn
