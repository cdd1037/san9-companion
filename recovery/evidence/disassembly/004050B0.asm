004050B0  56                                            push    esi
004050B1  8b f1                                         mov     esi, ecx
004050B3  6a 01                                         push    1; int
004050B5  e8 70 55 01 00                                call    ?UpdateData@CWnd@@QAEHH@Z; CWnd::UpdateData(int)
004050BA  85 c0                                         test    eax, eax
004050BC  75 02                                         jnz     short loc_4050C0
004050BE  5e                                            pop     esi
004050BF  c3                                            retn
004050C0  8b 86 00 01 00 00                             mov     eax, [esi+100h]
004050C6  8b 8e fc 00 00 00                             mov     ecx, [esi+0FCh]
004050CC  8d 14 81                                      lea     edx, [ecx+eax*4]
004050CF  8b 86 f8 00 00 00                             mov     eax, [esi+0F8h]
004050D5  8d 0c 90                                      lea     ecx, [eax+edx*4]
004050D8  8b 96 f4 00 00 00                             mov     edx, [esi+0F4h]
004050DE  8d 04 8a                                      lea     eax, [edx+ecx*4]
004050E1  8b 8e 04 01 00 00                             mov     ecx, [esi+104h]
004050E7  8d 14 81                                      lea     edx, [ecx+eax*4]
004050EA  8b 86 f0 00 00 00                             mov     eax, [esi+0F0h]
004050F0  8d 0c 90                                      lea     ecx, [eax+edx*4]
004050F3  8b 96 ec 00 00 00                             mov     edx, [esi+0ECh]
004050F9  8d 04 8a                                      lea     eax, [edx+ecx*4]
004050FC  8b 8e e8 00 00 00                             mov     ecx, [esi+0E8h]
00405102  8d 14 81                                      lea     edx, [ecx+eax*4]
00405105  8b 86 e4 00 00 00                             mov     eax, [esi+0E4h]
0040510B  8d 0c 90                                      lea     ecx, [eax+edx*4]
0040510E  8b 96 58 01 00 00                             mov     edx, [esi+158h]
00405114  8b 86 54 01 00 00                             mov     eax, [esi+154h]
0040511A  5e                                            pop     esi
0040511B  89 0c 90                                      mov     [eax+edx*4], ecx
0040511E  b8 01 00 00 00                                mov     eax, 1
00405123  c3                                            retn
