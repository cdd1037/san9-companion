004019B0  56                                            push    esi
004019B1  8b f1                                         mov     esi, ecx
004019B3  e8 18 00 00 00                                call    sub_4019D0
004019B8  f6 44 24 08 01                                test    [esp+4+arg_0], 1
004019BD  74 09                                         jz      short loc_4019C8
004019BF  56                                            push    esi; void *
004019C0  e8 23 8c 01 00                                call    ??3@YAXPAX@Z; operator delete(void *)
004019C5  83 c4 04                                      add     esp, 4
004019C8  8b c6                                         mov     eax, esi
004019CA  5e                                            pop     esi
004019CB  c2 04 00                                      retn    4
