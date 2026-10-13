004026D0  56                                            push    esi
004026D1  8b f1                                         mov     esi, ecx
004026D3  e8 18 00 00 00                                call    sub_4026F0
004026D8  f6 44 24 08 01                                test    [esp+4+arg_0], 1
004026DD  74 09                                         jz      short loc_4026E8
004026DF  56                                            push    esi; void *
004026E0  e8 03 7f 01 00                                call    ??3@YAXPAX@Z; operator delete(void *)
004026E5  83 c4 04                                      add     esp, 4
004026E8  8b c6                                         mov     eax, esi
004026EA  5e                                            pop     esi
004026EB  c2 04 00                                      retn    4
