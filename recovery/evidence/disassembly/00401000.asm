00401000  6a ff                                         push    0FFFFFFFFh
00401002  68 c8 aa 41 00                                push    offset SEH_401000
00401007  64 a1 00 00 00 00                             mov     eax, large fs:0
0040100D  50                                            push    eax
0040100E  64 89 25 00 00 00 00                          mov     large fs:0, esp
00401015  51                                            push    ecx
00401016  8b 44 24 14                                   mov     eax, [esp+10h+arg_0]
0040101A  56                                            push    esi
0040101B  57                                            push    edi
0040101C  8b f1                                         mov     esi, ecx
0040101E  50                                            push    eax; struct CWnd *
0040101F  68 87 00 00 00                                push    87h; unsigned int
00401024  89 74 24 10                                   mov     [esp+20h+var_10], esi
00401028  e8 b5 95 01 00                                call    ??0CDialog@@QAE@IPAVCWnd@@@Z; CDialog::CDialog(uint,CWnd *)
0040102D  8d 7e 60                                      lea     edi, [esi+60h]
00401030  c7 44 24 14 00 00 00 00                       mov     [esp+18h+var_4], 0
00401038  8b cf                                         mov     ecx, edi; this
0040103A  e8 9d 95 01 00                                call    ??0CWnd@@QAE@XZ; CWnd::CWnd(void)
0040103F  8b 4c 24 0c                                   mov     ecx, [esp+18h+var_C]
00401043  b8 0a 00 00 00                                mov     eax, 0Ah
00401048  c7 07 98 c4 41 00                             mov     dword ptr [edi], offset off_41C498
0040104E  89 86 a4 00 00 00                             mov     [esi+0A4h], eax
00401054  89 86 ac 00 00 00                             mov     [esi+0ACh], eax
0040105A  89 86 b0 00 00 00                             mov     [esi+0B0h], eax
00401060  89 86 b4 00 00 00                             mov     [esi+0B4h], eax
00401066  89 86 b8 00 00 00                             mov     [esi+0B8h], eax
0040106C  b8 01 00 00 00                                mov     eax, 1
00401071  c7 06 c0 c3 41 00                             mov     dword ptr [esi], offset off_41C3C0
00401077  89 86 bc 00 00 00                             mov     [esi+0BCh], eax
0040107D  89 86 c0 00 00 00                             mov     [esi+0C0h], eax
00401083  c7 86 a0 00 00 00 02 00 00 00                 mov     dword ptr [esi+0A0h], 2
0040108D  c7 86 a8 00 00 00 00 00 00 00                 mov     dword ptr [esi+0A8h], 0
00401097  8b c6                                         mov     eax, esi
00401099  5f                                            pop     edi
0040109A  5e                                            pop     esi
0040109B  64 89 0d 00 00 00 00                          mov     large fs:0, ecx
004010A2  83 c4 10                                      add     esp, 10h
004010A5  c2 04 00                                      retn    4
0041AAC0  8b 4d f0                                      mov     ecx, [ebp-10h]; this
0041AAC3  e9 0e fb ff ff                                jmp     ??1CDialog@@UAE@XZ; CDialog::~CDialog(void)
0041AAC8  b8 78 d1 41 00                                mov     eax, offset stru_41D178
0041AACD  e9 4a fd ff ff                                jmp     __CxxFrameHandler
