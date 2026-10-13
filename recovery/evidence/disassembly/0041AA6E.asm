0041AA6E  e8 a5 fb ff ff                                call    ?AfxGetModuleState@@YGPAVAFX_MODULE_STATE@@XZ
0041AA73  8b 4c 24 04                                   mov     ecx, [esp+arg_0]
0041AA77  8b 54 24 08                                   mov     edx, [esp+arg_4]
0041AA7B  85 c9                                         test    ecx, ecx
0041AA7D  88 48 14                                      mov     [eax+14h], cl
0041AA80  89 90 40 10 00 00                             mov     [eax+1040h], edx
0041AA86  75 09                                         jnz     short loc_41AA91
0041AA88  6a fd                                         push    0FFFFFFFDh; CodePage
0041AA8A  ff 15 00 c3 41 00                             call    ds:_setmbcp; MSVCRT
0041AA90  59                                            pop     ecx
0041AA91  6a 01                                         push    1
0041AA93  58                                            pop     eax
0041AA94  c2 08 00                                      retn    8
