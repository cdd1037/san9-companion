00401570  56                                            push    esi
00401571  8b f1                                         mov     esi, ecx
00401573  6a 01                                         push    1; int
00401575  e8 b0 90 01 00                                call    ?UpdateData@CWnd@@QAEHH@Z; CWnd::UpdateData(int)
0040157A  85 c0                                         test    eax, eax
0040157C  75 02                                         jnz     short loc_401580
0040157E  5e                                            pop     esi
0040157F  c3                                            retn
00401580  8b 8e c4 00 00 00                             mov     ecx, [esi+0C4h]
00401586  8b 96 b8 00 00 00                             mov     edx, [esi+0B8h]
0040158C  33 c0                                         xor     eax, eax
0040158E  8a 86 cd 00 00 00                             mov     al, [esi+0CDh]
00401594  89 14 c1                                      mov     [ecx+eax*8], edx
00401597  8b 8e c4 00 00 00                             mov     ecx, [esi+0C4h]
0040159D  8b 96 b4 00 00 00                             mov     edx, [esi+0B4h]
004015A3  33 c0                                         xor     eax, eax
004015A5  8a 86 cd 00 00 00                             mov     al, [esi+0CDh]
004015AB  c1 e2 06                                      shl     edx, 6
004015AE  8d 04 c1                                      lea     eax, [ecx+eax*8]
004015B1  8b 08                                         mov     ecx, [eax]
004015B3  0b ca                                         or      ecx, edx
004015B5  89 08                                         mov     [eax], ecx
004015B7  8b 8e c4 00 00 00                             mov     ecx, [esi+0C4h]
004015BD  8b 96 b0 00 00 00                             mov     edx, [esi+0B0h]
004015C3  33 c0                                         xor     eax, eax
004015C5  8a 86 cd 00 00 00                             mov     al, [esi+0CDh]
004015CB  c1 e2 0c                                      shl     edx, 0Ch
004015CE  8d 04 c1                                      lea     eax, [ecx+eax*8]
004015D1  8b 08                                         mov     ecx, [eax]
004015D3  0b ca                                         or      ecx, edx
004015D5  89 08                                         mov     [eax], ecx
004015D7  8b 8e c4 00 00 00                             mov     ecx, [esi+0C4h]
004015DD  8b 96 a4 00 00 00                             mov     edx, [esi+0A4h]
004015E3  33 c0                                         xor     eax, eax
004015E5  8a 86 cd 00 00 00                             mov     al, [esi+0CDh]
004015EB  c1 e2 12                                      shl     edx, 12h
004015EE  8d 04 c1                                      lea     eax, [ecx+eax*8]
004015F1  8b 08                                         mov     ecx, [eax]
004015F3  0b ca                                         or      ecx, edx
004015F5  89 08                                         mov     [eax], ecx
004015F7  8b 8e c4 00 00 00                             mov     ecx, [esi+0C4h]
004015FD  8b 96 ac 00 00 00                             mov     edx, [esi+0ACh]
00401603  33 c0                                         xor     eax, eax
00401605  8a 86 cd 00 00 00                             mov     al, [esi+0CDh]
0040160B  c1 e2 18                                      shl     edx, 18h
0040160E  8d 04 c1                                      lea     eax, [ecx+eax*8]
00401611  8b 08                                         mov     ecx, [eax]
00401613  0b ca                                         or      ecx, edx
00401615  89 08                                         mov     [eax], ecx
00401617  8b 8e c4 00 00 00                             mov     ecx, [esi+0C4h]
0040161D  66 8b 96 a0 00 00 00                          mov     dx, [esi+0A0h]
00401624  33 c0                                         xor     eax, eax
00401626  8a 86 cd 00 00 00                             mov     al, [esi+0CDh]
0040162C  66 89 54 c1 04                                mov     [ecx+eax*8+4], dx
00401631  8b 8e c4 00 00 00                             mov     ecx, [esi+0C4h]
00401637  66 8b 96 c0 00 00 00                          mov     dx, [esi+0C0h]
0040163E  33 c0                                         xor     eax, eax
00401640  8a 86 cd 00 00 00                             mov     al, [esi+0CDh]
00401646  66 c1 e2 04                                   shl     dx, 4
0040164A  66 09 54 c1 04                                or      [ecx+eax*8+4], dx
0040164F  8d 44 c1 04                                   lea     eax, [ecx+eax*8+4]
00401653  8b 8e c4 00 00 00                             mov     ecx, [esi+0C4h]
00401659  33 c0                                         xor     eax, eax
0040165B  8a 86 cd 00 00 00                             mov     al, [esi+0CDh]
00401661  33 d2                                         xor     edx, edx
00401663  8a b6 bc 00 00 00                             mov     dh, [esi+0BCh]
00401669  66 09 54 c1 04                                or      [ecx+eax*8+4], dx
0040166E  66 8b 96 a8 00 00 00                          mov     dx, [esi+0A8h]
00401675  8d 44 c1 04                                   lea     eax, [ecx+eax*8+4]
00401679  8b 8e c4 00 00 00                             mov     ecx, [esi+0C4h]
0040167F  33 c0                                         xor     eax, eax
00401681  8a 86 cd 00 00 00                             mov     al, [esi+0CDh]
00401687  5e                                            pop     esi
00401688  66 89 54 c1 06                                mov     [ecx+eax*8+6], dx
0040168D  b8 01 00 00 00                                mov     eax, 1
00401692  c3                                            retn
