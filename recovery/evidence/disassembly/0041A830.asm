0041A830  56                                            push    esi
0041A831  8b f1                                         mov     esi, ecx
0041A833  e8 e4 01 00 00                                call    ??1type_info@@UAE@XZ; type_info::~type_info(void)
0041A838  f6 44 24 08 01                                test    [esp+4+arg_0], 1
0041A83D  74 07                                         jz      short loc_41A846
0041A83F  56                                            push    esi; void *
0041A840  e8 a3 fd ff ff                                call    ??3@YAXPAX@Z; operator delete(void *)
0041A845  59                                            pop     ecx
0041A846  8b c6                                         mov     eax, esi
0041A848  5e                                            pop     esi
0041A849  c2 04 00                                      retn    4
