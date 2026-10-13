004093E0  56                                            push    esi
004093E1  8b f1                                         mov     esi, ecx
004093E3  e8 98 ca ff ff                                call    sub_405E80
004093E8  f6 44 24 08 01                                test    [esp+4+arg_0], 1
004093ED  74 09                                         jz      short loc_4093F8
004093EF  56                                            push    esi; void *
004093F0  e8 f3 11 01 00                                call    ??3@YAXPAX@Z; operator delete(void *)
004093F5  83 c4 04                                      add     esp, 4
004093F8  8b c6                                         mov     eax, esi
004093FA  5e                                            pop     esi
004093FB  c2 04 00                                      retn    4
