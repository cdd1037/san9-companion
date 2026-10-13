00404240  6a ff                                         push    0FFFFFFFFh
00404242  68 36 af 41 00                                push    offset SEH_404240
00404247  64 a1 00 00 00 00                             mov     eax, large fs:0
0040424D  50                                            push    eax
0040424E  64 89 25 00 00 00 00                          mov     large fs:0, esp
00404255  81 ec f8 00 00 00                             sub     esp, 0F8h
0040425B  6a 00                                         push    0; struct CWnd *
0040425D  8d 4c 24 04                                   lea     ecx, [esp+108h+var_104]
00404261  e8 0a d8 ff ff                                call    sub_401A70
00404266  8d 4c 24 00                                   lea     ecx, [esp+104h+var_104]; this
0040426A  c7 84 24 00 01 00 00 00 00 00 00              mov     [esp+104h+var_4], 0
00404275  e8 66 62 01 00                                call    ?DoModal@CDialog@@UAEHXZ; CDialog::DoModal(void)
0040427A  8d 4c 24 60                                   lea     ecx, [esp+104h+var_A4]; this
0040427E  c7 84 24 00 01 00 00 01 00 00 00              mov     [esp+104h+var_4], 1
00404289  e8 60 63 01 00                                call    ??1CListBox@@UAE@XZ; CListBox::~CListBox(void)
0040428E  8d 4c 24 00                                   lea     ecx, [esp+104h+var_104]; this
00404292  c7 84 24 00 01 00 00 ff ff ff ff              mov     [esp+104h+var_4], 0FFFFFFFFh
0040429D  e8 34 63 01 00                                call    ??1CDialog@@UAE@XZ; CDialog::~CDialog(void)
004042A2  8b 8c 24 f8 00 00 00                          mov     ecx, [esp+104h+var_C]
004042A9  64 89 0d 00 00 00 00                          mov     large fs:0, ecx
004042B0  81 c4 04 01 00 00                             add     esp, 104h
004042B6  c3                                            retn
0041AF20  8d 8d fc fe ff ff                             lea     ecx, [ebp-104h]; this
0041AF26  e9 45 6c fe ff                                jmp     sub_401B70
0041AF2B  8d 8d fc fe ff ff                             lea     ecx, [ebp-104h]; this
0041AF31  e9 a0 f6 ff ff                                jmp     ??1CDialog@@UAE@XZ; CDialog::~CDialog(void)
0041AF36  b8 08 d7 41 00                                mov     eax, offset stru_41D708
0041AF3B  e9 dc f8 ff ff                                jmp     __CxxFrameHandler
