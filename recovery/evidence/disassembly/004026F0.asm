004026F0  6a ff                                         push    0FFFFFFFFh
004026F2  68 e8 ac 41 00                                push    offset SEH_4026F0
004026F7  64 a1 00 00 00 00                             mov     eax, large fs:0
004026FD  50                                            push    eax
004026FE  64 89 25 00 00 00 00                          mov     large fs:0, esp
00402705  51                                            push    ecx
00402706  56                                            push    esi
00402707  8b f1                                         mov     esi, ecx
00402709  89 74 24 04                                   mov     [esp+14h+var_10], esi
0040270D  8d 4e 60                                      lea     ecx, [esi+60h]; this
00402710  c7 44 24 10 00 00 00 00                       mov     [esp+14h+var_4], 0
00402718  e8 d1 7e 01 00                                call    ??1CListBox@@UAE@XZ; CListBox::~CListBox(void)
0040271D  8b ce                                         mov     ecx, esi; this
0040271F  c7 44 24 10 ff ff ff ff                       mov     [esp+14h+var_4], 0FFFFFFFFh
00402727  e8 aa 7e 01 00                                call    ??1CDialog@@UAE@XZ; CDialog::~CDialog(void)
0040272C  8b 4c 24 08                                   mov     ecx, [esp+14h+var_C]
00402730  5e                                            pop     esi
00402731  64 89 0d 00 00 00 00                          mov     large fs:0, ecx
00402738  83 c4 10                                      add     esp, 10h
0040273B  c3                                            retn
0041ACE0  8b 4d f0                                      mov     ecx, [ebp-10h]; this
0041ACE3  e9 ee f8 ff ff                                jmp     ??1CDialog@@UAE@XZ; CDialog::~CDialog(void)
0041ACE8  b8 40 d4 41 00                                mov     eax, offset stru_41D440
0041ACED  e9 2a fb ff ff                                jmp     __CxxFrameHandler
