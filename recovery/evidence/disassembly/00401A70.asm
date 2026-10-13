00401A70  6a ff                                         push    0FFFFFFFFh
00401A72  68 e8 ab 41 00                                push    offset SEH_401A70
00401A77  64 a1 00 00 00 00                             mov     eax, large fs:0
00401A7D  50                                            push    eax
00401A7E  64 89 25 00 00 00 00                          mov     large fs:0, esp
00401A85  51                                            push    ecx
00401A86  8b 44 24 14                                   mov     eax, [esp+10h+arg_0]
00401A8A  53                                            push    ebx
00401A8B  56                                            push    esi
00401A8C  57                                            push    edi
00401A8D  8b f1                                         mov     esi, ecx
00401A8F  50                                            push    eax; struct CWnd *
00401A90  68 85 00 00 00                                push    85h; unsigned int
00401A95  89 74 24 14                                   mov     [esp+24h+var_10], esi
00401A99  e8 44 8b 01 00                                call    ??0CDialog@@QAE@IPAVCWnd@@@Z; CDialog::CDialog(uint,CWnd *)
00401A9E  8d 7e 60                                      lea     edi, [esi+60h]
00401AA1  33 db                                         xor     ebx, ebx
00401AA3  8b cf                                         mov     ecx, edi; this
00401AA5  89 5c 24 18                                   mov     [esp+1Ch+var_4], ebx
00401AA9  e8 2e 8b 01 00                                call    ??0CWnd@@QAE@XZ; CWnd::CWnd(void)
00401AAE  8b 4c 24 10                                   mov     ecx, [esp+1Ch+var_C]
00401AB2  b8 07 00 00 00                                mov     eax, 7
00401AB7  c7 07 98 c4 41 00                             mov     dword ptr [edi], offset off_41C498
00401ABD  89 86 b0 00 00 00                             mov     [esi+0B0h], eax
00401AC3  89 86 b4 00 00 00                             mov     [esi+0B4h], eax
00401AC9  89 86 b8 00 00 00                             mov     [esi+0B8h], eax
00401ACF  b8 32 00 00 00                                mov     eax, 32h ; '2'
00401AD4  c7 06 08 c6 41 00                             mov     dword ptr [esi], offset off_41C608
00401ADA  89 86 c0 00 00 00                             mov     [esi+0C0h], eax
00401AE0  89 86 c8 00 00 00                             mov     [esi+0C8h], eax
00401AE6  89 86 cc 00 00 00                             mov     [esi+0CCh], eax
00401AEC  89 86 d0 00 00 00                             mov     [esi+0D0h], eax
00401AF2  89 86 d4 00 00 00                             mov     [esi+0D4h], eax
00401AF8  89 86 d8 00 00 00                             mov     [esi+0D8h], eax
00401AFE  89 86 dc 00 00 00                             mov     [esi+0DCh], eax
00401B04  89 86 e0 00 00 00                             mov     [esi+0E0h], eax
00401B0A  89 86 e4 00 00 00                             mov     [esi+0E4h], eax
00401B10  89 86 e8 00 00 00                             mov     [esi+0E8h], eax
00401B16  89 9e a0 00 00 00                             mov     [esi+0A0h], ebx
00401B1C  89 9e a4 00 00 00                             mov     [esi+0A4h], ebx
00401B22  89 9e a8 00 00 00                             mov     [esi+0A8h], ebx
00401B28  89 9e ac 00 00 00                             mov     [esi+0ACh], ebx
00401B2E  c7 86 bc 00 00 00 0a 00 00 00                 mov     dword ptr [esi+0BCh], 0Ah
00401B38  89 9e c4 00 00 00                             mov     [esi+0C4h], ebx
00401B3E  8b c6                                         mov     eax, esi
00401B40  5f                                            pop     edi
00401B41  5e                                            pop     esi
00401B42  5b                                            pop     ebx
00401B43  64 89 0d 00 00 00 00                          mov     large fs:0, ecx
00401B4A  83 c4 10                                      add     esp, 10h
00401B4D  c2 04 00                                      retn    4
0041ABE0  8b 4d f0                                      mov     ecx, [ebp-10h]; this
0041ABE3  e9 ee f9 ff ff                                jmp     ??1CDialog@@UAE@XZ; CDialog::~CDialog(void)
0041ABE8  b8 f0 d2 41 00                                mov     eax, offset stru_41D2F0
0041ABED  e9 2a fc ff ff                                jmp     __CxxFrameHandler
