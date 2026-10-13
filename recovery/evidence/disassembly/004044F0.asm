004044F0  6a ff                                         push    0FFFFFFFFh
004044F2  68 56 af 41 00                                push    offset SEH_4044F0
004044F7  64 a1 00 00 00 00                             mov     eax, large fs:0
004044FD  50                                            push    eax
004044FE  64 89 25 00 00 00 00                          mov     large fs:0, esp
00404505  81 ec b8 00 00 00                             sub     esp, 0B8h
0040450B  6a 00                                         push    0; struct CWnd *
0040450D  8d 4c 24 04                                   lea     ecx, [esp+0C8h+var_C4]
00404511  e8 3a e1 ff ff                                call    sub_402650
00404516  8d 4c 24 00                                   lea     ecx, [esp+0C4h+var_C4]; this
0040451A  c7 84 24 c0 00 00 00 00 00 00 00              mov     [esp+0C4h+var_4], 0
00404525  e8 b6 5f 01 00                                call    ?DoModal@CDialog@@UAEHXZ; CDialog::DoModal(void)
0040452A  8d 4c 24 60                                   lea     ecx, [esp+0C4h+var_64]; this
0040452E  c7 84 24 c0 00 00 00 01 00 00 00              mov     [esp+0C4h+var_4], 1
00404539  e8 b0 60 01 00                                call    ??1CListBox@@UAE@XZ; CListBox::~CListBox(void)
0040453E  8d 4c 24 00                                   lea     ecx, [esp+0C4h+var_C4]; this
00404542  c7 84 24 c0 00 00 00 ff ff ff ff              mov     [esp+0C4h+var_4], 0FFFFFFFFh
0040454D  e8 84 60 01 00                                call    ??1CDialog@@UAE@XZ; CDialog::~CDialog(void)
00404552  8b 8c 24 b8 00 00 00                          mov     ecx, [esp+0C4h+var_C]
00404559  64 89 0d 00 00 00 00                          mov     large fs:0, ecx
00404560  81 c4 c4 00 00 00                             add     esp, 0C4h
00404566  c3                                            retn
0041AF40  8d 8d 3c ff ff ff                             lea     ecx, [ebp-0C4h]; this
0041AF46  e9 a5 77 fe ff                                jmp     sub_4026F0
0041AF4B  8d 8d 3c ff ff ff                             lea     ecx, [ebp-0C4h]; this
0041AF51  e9 80 f6 ff ff                                jmp     ??1CDialog@@UAE@XZ; CDialog::~CDialog(void)
0041AF56  b8 38 d7 41 00                                mov     eax, offset stru_41D738
0041AF5B  e9 bc f8 ff ff                                jmp     __CxxFrameHandler
