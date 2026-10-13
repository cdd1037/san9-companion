00401A40  56                                            push    esi
00401A41  8b f1                                         mov     esi, ecx
00401A43  e8 a6 8b 01 00                                call    ??1CListBox@@UAE@XZ; CListBox::~CListBox(void)
00401A48  f6 44 24 08 01                                test    [esp+4+arg_0], 1
00401A4D  74 09                                         jz      short loc_401A58
00401A4F  56                                            push    esi; void *
00401A50  e8 93 8b 01 00                                call    ??3@YAXPAX@Z; operator delete(void *)
00401A55  83 c4 04                                      add     esp, 4
00401A58  8b c6                                         mov     eax, esi
00401A5A  5e                                            pop     esi
00401A5B  c2 04 00                                      retn    4
