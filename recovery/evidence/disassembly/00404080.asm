00404080  64 a1 00 00 00 00                             mov     eax, large fs:0
00404086  6a ff                                         push    0FFFFFFFFh
00404088  68 b5 ae 41 00                                push    offset SEH_404080
0040408D  50                                            push    eax
0040408E  b8 5c 7b 00 00                                mov     eax, 7B5Ch
00404093  64 89 25 00 00 00 00                          mov     large fs:0, esp
0040409A  e8 b1 67 01 00                                call    __alloca_probe
0040409F  6a 00                                         push    0; struct CWnd *
004040A1  8d 4c 24 08                                   lea     ecx, [esp+7B6Ch+var_7B64]
004040A5  e8 76 06 00 00                                call    sub_404720
004040AA  8d 4c 24 04                                   lea     ecx, [esp+7B68h+var_7B64]; this
004040AE  c7 84 24 64 7b 00 00 00 00 00 00              mov     [esp+7B68h+var_4], 0
004040B9  e8 22 64 01 00                                call    ?DoModal@CDialog@@UAEHXZ; CDialog::DoModal(void)
004040BE  8d 8c 24 4c 7b 00 00                          lea     ecx, [esp+7B68h+var_1C]; this
004040C5  c7 84 24 64 7b 00 00 06 00 00 00              mov     [esp+7B68h+var_4], 6
004040D0  e8 31 65 01 00                                call    ??1CString@@QAE@XZ; CString::~CString(void)
004040D5  8d 84 24 44 7b 00 00                          lea     eax, [esp+7B68h+var_24]
004040DC  c7 84 24 44 7b 00 00 ac c9 41 00              mov     [esp+7B68h+var_24], offset off_41C9AC
004040E7  89 44 24 00                                   mov     [esp+7B68h+var_7B68], eax
004040EB  8d 8c 24 44 7b 00 00                          lea     ecx, [esp+7B68h+var_24]; this
004040F2  c6 84 24 64 7b 00 00 07                       mov     byte ptr [esp+7B68h+var_4], 7
004040FA  e8 cd 65 01 00                                call    ?DeleteObject@CGdiObject@@QAEHXZ; CGdiObject::DeleteObject(void)
004040FF  8d 8c 24 50 01 00 00                          lea     ecx, [esp+7B68h+var_7A18]; this
00404106  c7 84 24 44 7b 00 00 70 c5 41 00              mov     [esp+7B68h+var_24], offset off_41C570
00404111  c6 84 24 64 7b 00 00 04                       mov     byte ptr [esp+7B68h+var_4], 4
00404119  e8 e8 64 01 00                                call    ??1CString@@QAE@XZ; CString::~CString(void)
0040411E  8d 8c 24 e4 00 00 00                          lea     ecx, [esp+7B68h+var_7A84]; this
00404125  c6 84 24 64 7b 00 00 03                       mov     byte ptr [esp+7B68h+var_4], 3
0040412D  e8 d4 64 01 00                                call    ??1CString@@QAE@XZ; CString::~CString(void)
00404132  8d 8c 24 a4 00 00 00                          lea     ecx, [esp+7B68h+var_7AC4]; this
00404139  c6 84 24 64 7b 00 00 02                       mov     byte ptr [esp+7B68h+var_4], 2
00404141  e8 80 65 01 00                                call    ??1CScrollBar@@UAE@XZ; CScrollBar::~CScrollBar(void)
00404146  8d 4c 24 64                                   lea     ecx, [esp+7B68h+var_7B04]; this
0040414A  c6 84 24 64 7b 00 00 01                       mov     byte ptr [esp+7B68h+var_4], 1
00404152  e8 97 64 01 00                                call    ??1CListBox@@UAE@XZ; CListBox::~CListBox(void)
00404157  8d 4c 24 04                                   lea     ecx, [esp+7B68h+var_7B64]; this
0040415B  c7 84 24 64 7b 00 00 ff ff ff ff              mov     [esp+7B68h+var_4], 0FFFFFFFFh
00404166  e8 6b 64 01 00                                call    ??1CDialog@@UAE@XZ; CDialog::~CDialog(void)
0040416B  8b 8c 24 5c 7b 00 00                          mov     ecx, [esp+7B68h+var_C]
00404172  64 89 0d 00 00 00 00                          mov     large fs:0, ecx
00404179  81 c4 68 7b 00 00                             add     esp, 7B68h
0040417F  c3                                            retn
0041AE60  8d 8d 9c 84 ff ff                             lea     ecx, [ebp-7B64h]; this
0041AE66  e9 15 93 fe ff                                jmp     sub_404180
0041AE6B  8d 8d 9c 84 ff ff                             lea     ecx, [ebp-7B64h]; this
0041AE71  e9 60 f7 ff ff                                jmp     ??1CDialog@@UAE@XZ; CDialog::~CDialog(void)
0041AE76  8d 8d fc 84 ff ff                             lea     ecx, [ebp-7B04h]; this
0041AE7C  e9 6d f7 ff ff                                jmp     ??1CListBox@@UAE@XZ; CListBox::~CListBox(void)
0041AE81  8d 8d 3c 85 ff ff                             lea     ecx, [ebp-7AC4h]; this
0041AE87  e9 3a f8 ff ff                                jmp     ??1CScrollBar@@UAE@XZ; CScrollBar::~CScrollBar(void)
0041AE8C  8d 8d 7c 85 ff ff                             lea     ecx, [ebp-7A84h]; this
0041AE92  e9 6f f7 ff ff                                jmp     ??1CString@@QAE@XZ; CString::~CString(void)
0041AE97  8d 8d e8 85 ff ff                             lea     ecx, [ebp-7A18h]; this
0041AE9D  e9 64 f7 ff ff                                jmp     ??1CString@@QAE@XZ; CString::~CString(void)
0041AEA2  8d 4d dc                                      lea     ecx, [ebp-24h]
0041AEA5  e9 b6 97 fe ff                                jmp     sub_404660
0041AEAA  8b 8d 98 84 ff ff                             mov     ecx, [ebp-7B68h]
0041AEB0  e9 eb 6a fe ff                                jmp     sub_4019A0
0041AEB5  b8 50 d6 41 00                                mov     eax, offset stru_41D650
0041AEBA  e9 5d f9 ff ff                                jmp     __CxxFrameHandler
