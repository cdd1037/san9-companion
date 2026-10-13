004018F0  6a ff                                         push    0FFFFFFFFh
004018F2  68 a8 ab 41 00                                push    offset SEH_4018F0
004018F7  64 a1 00 00 00 00                             mov     eax, large fs:0
004018FD  50                                            push    eax
004018FE  64 89 25 00 00 00 00                          mov     large fs:0, esp
00401905  51                                            push    ecx
00401906  56                                            push    esi
00401907  8b f1                                         mov     esi, ecx
00401909  89 74 24 04                                   mov     [esp+14h+var_10], esi
0040190D  8d 8e b0 00 00 00                             lea     ecx, [esi+0B0h]; this
00401913  c7 44 24 10 00 00 00 00                       mov     [esp+14h+var_4], 0
0040191B  e8 e6 8c 01 00                                call    ??1CString@@QAE@XZ; CString::~CString(void)
00401920  8b ce                                         mov     ecx, esi; this
00401922  c7 44 24 10 ff ff ff ff                       mov     [esp+14h+var_4], 0FFFFFFFFh
0040192A  e8 a7 8c 01 00                                call    ??1CDialog@@UAE@XZ; CDialog::~CDialog(void)
0040192F  8b 4c 24 08                                   mov     ecx, [esp+14h+var_C]
00401933  5e                                            pop     esi
00401934  64 89 0d 00 00 00 00                          mov     large fs:0, ecx
0040193B  83 c4 10                                      add     esp, 10h
0040193E  c3                                            retn
0041ABA0  8b 4d f0                                      mov     ecx, [ebp-10h]; this
0041ABA3  e9 b8 6e fe ff                                jmp     j_??1CDialog@@UAE@XZ; CDialog::~CDialog(void)
0041ABA8  b8 a0 d2 41 00                                mov     eax, offset stru_41D2A0
0041ABAD  e9 6a fc ff ff                                jmp     __CxxFrameHandler
