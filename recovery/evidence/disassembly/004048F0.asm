004048F0  56                                            push    esi
004048F1  8b f1                                         mov     esi, ecx
004048F3  e8 88 f8 ff ff                                call    sub_404180
004048F8  f6 44 24 08 01                                test    [esp+4+arg_0], 1
004048FD  74 09                                         jz      short loc_404908
004048FF  56                                            push    esi; void *
00404900  e8 e3 5c 01 00                                call    ??3@YAXPAX@Z; operator delete(void *)
00404905  83 c4 04                                      add     esp, 4
00404908  8b c6                                         mov     eax, esi
0040490A  5e                                            pop     esi
0040490B  c2 04 00                                      retn    4
