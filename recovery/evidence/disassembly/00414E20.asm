00414E20  56                                            push    esi
00414E21  8b f1                                         mov     esi, ecx
00414E23  e8 ac 59 00 00                                call    ??1CEdit@@UAE@XZ; CEdit::~CEdit(void)
00414E28  f6 44 24 08 01                                test    [esp+4+arg_0], 1
00414E2D  74 09                                         jz      short loc_414E38
00414E2F  56                                            push    esi; void *
00414E30  e8 b3 57 00 00                                call    ??3@YAXPAX@Z; operator delete(void *)
00414E35  83 c4 04                                      add     esp, 4
00414E38  8b c6                                         mov     eax, esi
00414E3A  5e                                            pop     esi
00414E3B  c2 04 00                                      retn    4
