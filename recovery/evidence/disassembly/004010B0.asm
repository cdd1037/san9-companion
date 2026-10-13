004010B0  56                                            push    esi
004010B1  8b f1                                         mov     esi, ecx
004010B3  e8 18 00 00 00                                call    sub_4010D0
004010B8  f6 44 24 08 01                                test    [esp+4+arg_0], 1
004010BD  74 09                                         jz      short loc_4010C8
004010BF  56                                            push    esi; void *
004010C0  e8 23 95 01 00                                call    ??3@YAXPAX@Z; operator delete(void *)
004010C5  83 c4 04                                      add     esp, 4
004010C8  8b c6                                         mov     eax, esi
004010CA  5e                                            pop     esi
004010CB  c2 04 00                                      retn    4
