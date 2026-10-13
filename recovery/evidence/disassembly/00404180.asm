00404180  6a ff                                         push    0FFFFFFFFh
00404182  68 13 af 41 00                                push    offset SEH_404180
00404187  64 a1 00 00 00 00                             mov     eax, large fs:0
0040418D  50                                            push    eax
0040418E  64 89 25 00 00 00 00                          mov     large fs:0, esp
00404195  83 ec 08                                      sub     esp, 8
00404198  56                                            push    esi
00404199  8b f1                                         mov     esi, ecx
0040419B  57                                            push    edi
0040419C  89 74 24 08                                   mov     [esp+1Ch+var_14], esi
004041A0  8d 8e 48 7b 00 00                             lea     ecx, [esi+7B48h]; this
004041A6  c7 44 24 18 05 00 00 00                       mov     [esp+1Ch+var_4], 5
004041AE  e8 53 64 01 00                                call    ??1CString@@QAE@XZ; CString::~CString(void)
004041B3  8d be 40 7b 00 00                             lea     edi, [esi+7B40h]
004041B9  89 7c 24 0c                                   mov     [esp+1Ch+var_10], edi
004041BD  c7 07 ac c9 41 00                             mov     dword ptr [edi], offset off_41C9AC
004041C3  8b cf                                         mov     ecx, edi; this
004041C5  c6 44 24 18 06                                mov     byte ptr [esp+1Ch+var_4], 6
004041CA  e8 fd 64 01 00                                call    ?DeleteObject@CGdiObject@@QAEHXZ; CGdiObject::DeleteObject(void)
004041CF  8d 8e 4c 01 00 00                             lea     ecx, [esi+14Ch]; this
004041D5  c7 07 70 c5 41 00                             mov     dword ptr [edi], offset off_41C570
004041DB  c6 44 24 18 03                                mov     byte ptr [esp+1Ch+var_4], 3
004041E0  e8 21 64 01 00                                call    ??1CString@@QAE@XZ; CString::~CString(void)
004041E5  8d 8e e0 00 00 00                             lea     ecx, [esi+0E0h]; this
004041EB  c6 44 24 18 02                                mov     byte ptr [esp+1Ch+var_4], 2
004041F0  e8 11 64 01 00                                call    ??1CString@@QAE@XZ; CString::~CString(void)
004041F5  8d 8e a0 00 00 00                             lea     ecx, [esi+0A0h]; this
004041FB  c6 44 24 18 01                                mov     byte ptr [esp+1Ch+var_4], 1
00404200  e8 c1 64 01 00                                call    ??1CScrollBar@@UAE@XZ; CScrollBar::~CScrollBar(void)
00404205  8d 4e 60                                      lea     ecx, [esi+60h]; this
00404208  c6 44 24 18 00                                mov     byte ptr [esp+1Ch+var_4], 0
0040420D  e8 dc 63 01 00                                call    ??1CListBox@@UAE@XZ; CListBox::~CListBox(void)
00404212  8b ce                                         mov     ecx, esi; this
00404214  c7 44 24 18 ff ff ff ff                       mov     [esp+1Ch+var_4], 0FFFFFFFFh
0040421C  e8 b5 63 01 00                                call    ??1CDialog@@UAE@XZ; CDialog::~CDialog(void)
00404221  8b 4c 24 10                                   mov     ecx, [esp+1Ch+var_C]
00404225  5f                                            pop     edi
00404226  5e                                            pop     esi
00404227  64 89 0d 00 00 00 00                          mov     large fs:0, ecx
0040422E  83 c4 14                                      add     esp, 14h
00404231  c3                                            retn
0041AEC0  8b 4d ec                                      mov     ecx, [ebp-14h]; this
0041AEC3  e9 0e f7 ff ff                                jmp     ??1CDialog@@UAE@XZ; CDialog::~CDialog(void)
0041AEC8  8b 4d ec                                      mov     ecx, [ebp-14h]
0041AECB  83 c1 60                                      add     ecx, 60h ; '`'; this
0041AECE  e9 1b f7 ff ff                                jmp     ??1CListBox@@UAE@XZ; CListBox::~CListBox(void)
0041AED3  8b 4d ec                                      mov     ecx, [ebp-14h]
0041AED6  81 c1 a0 00 00 00                             add     ecx, 0A0h; this
0041AEDC  e9 e5 f7 ff ff                                jmp     ??1CScrollBar@@UAE@XZ; CScrollBar::~CScrollBar(void)
0041AEE1  8b 4d ec                                      mov     ecx, [ebp-14h]
0041AEE4  81 c1 e0 00 00 00                             add     ecx, 0E0h; this
0041AEEA  e9 17 f7 ff ff                                jmp     ??1CString@@QAE@XZ; CString::~CString(void)
0041AEEF  8b 4d ec                                      mov     ecx, [ebp-14h]
0041AEF2  81 c1 4c 01 00 00                             add     ecx, 14Ch; this
0041AEF8  e9 09 f7 ff ff                                jmp     ??1CString@@QAE@XZ; CString::~CString(void)
0041AEFD  8b 4d ec                                      mov     ecx, [ebp-14h]
0041AF00  81 c1 40 7b 00 00                             add     ecx, 7B40h
0041AF06  e9 55 97 fe ff                                jmp     sub_404660
0041AF0B  8b 4d f0                                      mov     ecx, [ebp-10h]
0041AF0E  e9 8d 6a fe ff                                jmp     sub_4019A0
0041AF13  b8 b0 d6 41 00                                mov     eax, offset stru_41D6B0
0041AF18  e9 ff f8 ff ff                                jmp     __CxxFrameHandler
