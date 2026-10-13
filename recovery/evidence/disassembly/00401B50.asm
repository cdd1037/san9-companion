00401B50  56                                            push    esi
00401B51  8b f1                                         mov     esi, ecx
00401B53  e8 18 00 00 00                                call    sub_401B70
00401B58  f6 44 24 08 01                                test    [esp+4+arg_0], 1
00401B5D  74 09                                         jz      short loc_401B68
00401B5F  56                                            push    esi; void *
00401B60  e8 83 8a 01 00                                call    ??3@YAXPAX@Z; operator delete(void *)
00401B65  83 c4 04                                      add     esp, 4
00401B68  8b c6                                         mov     eax, esi
00401B6A  5e                                            pop     esi
00401B6B  c2 04 00                                      retn    4
