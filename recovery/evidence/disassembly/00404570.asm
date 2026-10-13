00404570  6a ff                                         push    0FFFFFFFFh
00404572  68 76 af 41 00                                push    offset SEH_404570
00404577  64 a1 00 00 00 00                             mov     eax, large fs:0
0040457D  50                                            push    eax
0040457E  64 89 25 00 00 00 00                          mov     large fs:0, esp
00404585  81 ec d0 00 00 00                             sub     esp, 0D0h
0040458B  6a 00                                         push    0; struct CWnd *
0040458D  8d 4c 24 04                                   lea     ecx, [esp+0E0h+var_DC]
00404591  e8 6a ca ff ff                                call    sub_401000
00404596  8d 4c 24 00                                   lea     ecx, [esp+0DCh+var_DC]; this
0040459A  c7 84 24 d8 00 00 00 00 00 00 00              mov     [esp+0DCh+var_4], 0
004045A5  e8 36 5f 01 00                                call    ?DoModal@CDialog@@UAEHXZ; CDialog::DoModal(void)
004045AA  8d 4c 24 60                                   lea     ecx, [esp+0DCh+var_7C]; this
004045AE  c7 84 24 d8 00 00 00 01 00 00 00              mov     [esp+0DCh+var_4], 1
004045B9  e8 30 60 01 00                                call    ??1CListBox@@UAE@XZ; CListBox::~CListBox(void)
004045BE  8d 4c 24 00                                   lea     ecx, [esp+0DCh+var_DC]; this
004045C2  c7 84 24 d8 00 00 00 ff ff ff ff              mov     [esp+0DCh+var_4], 0FFFFFFFFh
004045CD  e8 04 60 01 00                                call    ??1CDialog@@UAE@XZ; CDialog::~CDialog(void)
004045D2  8b 8c 24 d0 00 00 00                          mov     ecx, [esp+0DCh+var_C]
004045D9  64 89 0d 00 00 00 00                          mov     large fs:0, ecx
004045E0  81 c4 dc 00 00 00                             add     esp, 0DCh
004045E6  c3                                            retn
0041AF60  8d 8d 24 ff ff ff                             lea     ecx, [ebp-0DCh]; this
0041AF66  e9 65 61 fe ff                                jmp     sub_4010D0
0041AF6B  8d 8d 24 ff ff ff                             lea     ecx, [ebp-0DCh]; this
0041AF71  e9 60 f6 ff ff                                jmp     ??1CDialog@@UAE@XZ; CDialog::~CDialog(void)
0041AF76  b8 68 d7 41 00                                mov     eax, offset stru_41D768
0041AF7B  e9 9c f8 ff ff                                jmp     __CxxFrameHandler
