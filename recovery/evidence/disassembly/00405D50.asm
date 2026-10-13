00405D50  56                                            push    esi
00405D51  8b f1                                         mov     esi, ecx
00405D53  e8 18 00 00 00                                call    j_??1CWinApp@@UAE@XZ; CWinApp::~CWinApp(void)
00405D58  f6 44 24 08 01                                test    [esp+4+arg_0], 1
00405D5D  74 09                                         jz      short loc_405D68
00405D5F  56                                            push    esi; void *
00405D60  e8 83 48 01 00                                call    ??3@YAXPAX@Z; operator delete(void *)
00405D65  83 c4 04                                      add     esp, 4
00405D68  8b c6                                         mov     eax, esi
00405D6A  5e                                            pop     esi
00405D6B  c2 04 00                                      retn    4
