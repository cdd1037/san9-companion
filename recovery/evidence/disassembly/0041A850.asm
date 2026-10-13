0041A850  51                                            push    ecx
0041A851  3d 00 10 00 00                                cmp     eax, 1000h
0041A856  8d 4c 24 08                                   lea     ecx, [esp+4+arg_0]
0041A85A  72 14                                         jb      short lastpage
0041A85C  81 e9 00 10 00 00                             sub     ecx, 1000h
0041A862  2d 00 10 00 00                                sub     eax, 1000h
0041A867  85 01                                         test    [ecx], eax
0041A869  3d 00 10 00 00                                cmp     eax, 1000h
0041A86E  73 ec                                         jnb     short probepages
0041A870  2b c8                                         sub     ecx, eax
0041A872  8b c4                                         mov     eax, esp
0041A874  85 01                                         test    [ecx], eax
0041A876  8b e1                                         mov     esp, ecx
0041A878  8b 08                                         mov     ecx, [eax]
0041A87A  8b 40 04                                      mov     eax, [eax+4]
0041A87D  50                                            push    eax
0041A87E  c3                                            retn
