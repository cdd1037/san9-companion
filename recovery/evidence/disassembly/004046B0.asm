004046B0  56                                            push    esi
004046B1  8b f1                                         mov     esi, ecx
004046B3  e8 18 00 00 00                                call    sub_4046D0
004046B8  f6 44 24 08 01                                test    [esp+4+arg_0], 1
004046BD  74 09                                         jz      short loc_4046C8
004046BF  56                                            push    esi; void *
004046C0  e8 23 5f 01 00                                call    ??3@YAXPAX@Z; operator delete(void *)
004046C5  83 c4 04                                      add     esp, 4
004046C8  8b c6                                         mov     eax, esi
004046CA  5e                                            pop     esi
004046CB  c2 04 00                                      retn    4
