00409DF0  8b 44 24 04                                   mov     eax, [esp+arg_0]
00409DF4  56                                            push    esi
00409DF5  8b f1                                         mov     esi, ecx
00409DF7  3b 46 68                                      cmp     eax, [esi+68h]
00409DFA  75 09                                         jnz     short loc_409E05
00409DFC  6a 01                                         push    1
00409DFE  8b ce                                         mov     ecx, esi
00409E00  e8 0b 00 00 00                                call    sub_409E10
00409E05  8b ce                                         mov     ecx, esi; this
00409E07  e8 e0 09 01 00                                call    ?Default@CWnd@@IAEJXZ; CWnd::Default(void)
00409E0C  5e                                            pop     esi
00409E0D  c2 04 00                                      retn    4
