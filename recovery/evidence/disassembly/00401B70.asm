00401B70  6a ff                                         push    0FFFFFFFFh
00401B72  68 08 ac 41 00                                push    offset SEH_401B70
00401B77  64 a1 00 00 00 00                             mov     eax, large fs:0
00401B7D  50                                            push    eax
00401B7E  64 89 25 00 00 00 00                          mov     large fs:0, esp
00401B85  51                                            push    ecx
00401B86  56                                            push    esi
00401B87  8b f1                                         mov     esi, ecx
00401B89  89 74 24 04                                   mov     [esp+14h+var_10], esi
00401B8D  8d 4e 60                                      lea     ecx, [esi+60h]; this
00401B90  c7 44 24 10 00 00 00 00                       mov     [esp+14h+var_4], 0
00401B98  e8 51 8a 01 00                                call    ??1CListBox@@UAE@XZ; CListBox::~CListBox(void)
00401B9D  8b ce                                         mov     ecx, esi; this
00401B9F  c7 44 24 10 ff ff ff ff                       mov     [esp+14h+var_4], 0FFFFFFFFh
00401BA7  e8 2a 8a 01 00                                call    ??1CDialog@@UAE@XZ; CDialog::~CDialog(void)
00401BAC  8b 4c 24 08                                   mov     ecx, [esp+14h+var_C]
00401BB0  5e                                            pop     esi
00401BB1  64 89 0d 00 00 00 00                          mov     large fs:0, ecx
00401BB8  83 c4 10                                      add     esp, 10h
00401BBB  c3                                            retn
0041AC00  8b 4d f0                                      mov     ecx, [ebp-10h]; this
0041AC03  e9 ce f9 ff ff                                jmp     ??1CDialog@@UAE@XZ; CDialog::~CDialog(void)
0041AC08  b8 18 d3 41 00                                mov     eax, offset stru_41D318
0041AC0D  e9 0a fc ff ff                                jmp     __CxxFrameHandler
