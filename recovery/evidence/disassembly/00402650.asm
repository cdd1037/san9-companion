00402650  6a ff                                         push    0FFFFFFFFh
00402652  68 c8 ac 41 00                                push    offset SEH_402650
00402657  64 a1 00 00 00 00                             mov     eax, large fs:0
0040265D  50                                            push    eax
0040265E  64 89 25 00 00 00 00                          mov     large fs:0, esp
00402665  51                                            push    ecx
00402666  8b 44 24 14                                   mov     eax, [esp+10h+arg_0]
0040266A  56                                            push    esi
0040266B  57                                            push    edi
0040266C  8b f1                                         mov     esi, ecx
0040266E  50                                            push    eax; struct CWnd *
0040266F  68 86 00 00 00                                push    86h; unsigned int
00402674  89 74 24 10                                   mov     [esp+20h+var_10], esi
00402678  e8 65 7f 01 00                                call    ??0CDialog@@QAE@IPAVCWnd@@@Z; CDialog::CDialog(uint,CWnd *)
0040267D  8d 7e 60                                      lea     edi, [esi+60h]
00402680  c7 44 24 14 00 00 00 00                       mov     [esp+18h+var_4], 0
00402688  8b cf                                         mov     ecx, edi; this
0040268A  e8 4d 7f 01 00                                call    ??0CWnd@@QAE@XZ; CWnd::CWnd(void)
0040268F  8b 4c 24 0c                                   mov     ecx, [esp+18h+var_C]
00402693  c7 07 98 c4 41 00                             mov     dword ptr [edi], offset off_41C498
00402699  c7 06 30 c7 41 00                             mov     dword ptr [esi], offset off_41C730
0040269F  c7 86 a0 00 00 00 09 00 00 00                 mov     dword ptr [esi+0A0h], 9
004026A9  c7 86 a4 00 00 00 64 00 00 00                 mov     dword ptr [esi+0A4h], 64h ; 'd'
004026B3  c7 86 a8 00 00 00 0a 00 00 00                 mov     dword ptr [esi+0A8h], 0Ah
004026BD  8b c6                                         mov     eax, esi
004026BF  5f                                            pop     edi
004026C0  5e                                            pop     esi
004026C1  64 89 0d 00 00 00 00                          mov     large fs:0, ecx
004026C8  83 c4 10                                      add     esp, 10h
004026CB  c2 04 00                                      retn    4
0041ACC0  8b 4d f0                                      mov     ecx, [ebp-10h]; this
0041ACC3  e9 0e f9 ff ff                                jmp     ??1CDialog@@UAE@XZ; CDialog::~CDialog(void)
0041ACC8  b8 18 d4 41 00                                mov     eax, offset stru_41D418
0041ACCD  e9 4a fb ff ff                                jmp     __CxxFrameHandler
