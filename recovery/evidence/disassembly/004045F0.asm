004045F0  56                                            push    esi
004045F1  8b f1                                         mov     esi, ecx
004045F3  e8 18 00 00 00                                call    sub_404610
004045F8  f6 44 24 08 01                                test    [esp+4+arg_0], 1
004045FD  74 09                                         jz      short loc_404608
004045FF  56                                            push    esi; void *
00404600  e8 e3 5f 01 00                                call    ??3@YAXPAX@Z; operator delete(void *)
00404605  83 c4 04                                      add     esp, 4
00404608  8b c6                                         mov     eax, esi
0040460A  5e                                            pop     esi
0040460B  c2 04 00                                      retn    4
