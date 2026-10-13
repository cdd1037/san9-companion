00402EF0  56                                            push    esi
00402EF1  8b f1                                         mov     esi, ecx
00402EF3  e8 18 00 00 00                                call    sub_402F10
00402EF8  f6 44 24 08 01                                test    [esp+4+arg_0], 1
00402EFD  74 09                                         jz      short loc_402F08
00402EFF  56                                            push    esi; void *
00402F00  e8 e3 76 01 00                                call    ??3@YAXPAX@Z; operator delete(void *)
00402F05  83 c4 04                                      add     esp, 4
00402F08  8b c6                                         mov     eax, esi
00402F0A  5e                                            pop     esi
00402F0B  c2 04 00                                      retn    4
