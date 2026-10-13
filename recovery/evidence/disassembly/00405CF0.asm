00405CF0  56                                            push    esi
00405CF1  8b f1                                         mov     esi, ecx
00405CF3  e8 ce 49 01 00                                call    ??1CScrollBar@@UAE@XZ; CScrollBar::~CScrollBar(void)
00405CF8  f6 44 24 08 01                                test    [esp+4+arg_0], 1
00405CFD  74 09                                         jz      short loc_405D08
00405CFF  56                                            push    esi; void *
00405D00  e8 e3 48 01 00                                call    ??3@YAXPAX@Z; operator delete(void *)
00405D05  83 c4 04                                      add     esp, 4
00405D08  8b c6                                         mov     eax, esi
00405D0A  5e                                            pop     esi
00405D0B  c2 04 00                                      retn    4
