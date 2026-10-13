00405E80  6a ff                                         push    0FFFFFFFFh
00405E82  68 48 b1 41 00                                push    offset SEH_405E80
00405E87  64 a1 00 00 00 00                             mov     eax, large fs:0
00405E8D  50                                            push    eax
00405E8E  64 89 25 00 00 00 00                          mov     large fs:0, esp
00405E95  51                                            push    ecx
00405E96  56                                            push    esi
00405E97  8b f1                                         mov     esi, ecx
00405E99  89 74 24 04                                   mov     [esp+14h+var_10], esi
00405E9D  8d 8e c8 1d 00 00                             lea     ecx, [esi+1DC8h]; this
00405EA3  c7 44 24 10 00 00 00 00                       mov     [esp+14h+var_4], 0
00405EAB  e8 24 49 01 00                                call    ??1CEdit@@UAE@XZ; CEdit::~CEdit(void)
00405EB0  8b ce                                         mov     ecx, esi; this
00405EB2  c7 44 24 10 ff ff ff ff                       mov     [esp+14h+var_4], 0FFFFFFFFh
00405EBA  e8 17 47 01 00                                call    ??1CDialog@@UAE@XZ; CDialog::~CDialog(void)
00405EBF  8b 4c 24 08                                   mov     ecx, [esp+14h+var_C]
00405EC3  5e                                            pop     esi
00405EC4  64 89 0d 00 00 00 00                          mov     large fs:0, ecx
00405ECB  83 c4 10                                      add     esp, 10h
00405ECE  c3                                            retn
0041B140  8b 4d f0                                      mov     ecx, [ebp-10h]; this
0041B143  e9 8e f4 ff ff                                jmp     ??1CDialog@@UAE@XZ; CDialog::~CDialog(void)
0041B148  b8 b0 d9 41 00                                mov     eax, offset stru_41D9B0
0041B14D  e9 ca f6 ff ff                                jmp     __CxxFrameHandler
