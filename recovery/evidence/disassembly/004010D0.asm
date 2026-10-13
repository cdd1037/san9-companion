004010D0  6a ff                                         push    0FFFFFFFFh
004010D2  68 e8 aa 41 00                                push    offset SEH_4010D0
004010D7  64 a1 00 00 00 00                             mov     eax, large fs:0
004010DD  50                                            push    eax
004010DE  64 89 25 00 00 00 00                          mov     large fs:0, esp
004010E5  51                                            push    ecx
004010E6  56                                            push    esi
004010E7  8b f1                                         mov     esi, ecx
004010E9  89 74 24 04                                   mov     [esp+14h+var_10], esi
004010ED  8d 4e 60                                      lea     ecx, [esi+60h]; this
004010F0  c7 44 24 10 00 00 00 00                       mov     [esp+14h+var_4], 0
004010F8  e8 f1 94 01 00                                call    ??1CListBox@@UAE@XZ; CListBox::~CListBox(void)
004010FD  8b ce                                         mov     ecx, esi; this
004010FF  c7 44 24 10 ff ff ff ff                       mov     [esp+14h+var_4], 0FFFFFFFFh
00401107  e8 ca 94 01 00                                call    ??1CDialog@@UAE@XZ; CDialog::~CDialog(void)
0040110C  8b 4c 24 08                                   mov     ecx, [esp+14h+var_C]
00401110  5e                                            pop     esi
00401111  64 89 0d 00 00 00 00                          mov     large fs:0, ecx
00401118  83 c4 10                                      add     esp, 10h
0040111B  c3                                            retn
0041AAE0  8b 4d f0                                      mov     ecx, [ebp-10h]; this
0041AAE3  e9 ee fa ff ff                                jmp     ??1CDialog@@UAE@XZ; CDialog::~CDialog(void)
0041AAE8  b8 a0 d1 41 00                                mov     eax, offset stru_41D1A0
0041AAED  e9 2a fd ff ff                                jmp     __CxxFrameHandler
