00405CD0  56                                            push    esi
00405CD1  8b f1                                         mov     esi, ecx
00405CD3  e8 88 e9 ff ff                                call    sub_404660
00405CD8  f6 44 24 08 01                                test    [esp+4+arg_0], 1
00405CDD  74 09                                         jz      short loc_405CE8
00405CDF  56                                            push    esi; void *
00405CE0  e8 03 49 01 00                                call    ??3@YAXPAX@Z; operator delete(void *)
00405CE5  83 c4 04                                      add     esp, 4
00405CE8  8b c6                                         mov     eax, esi
00405CEA  5e                                            pop     esi
00405CEB  c2 04 00                                      retn    4
