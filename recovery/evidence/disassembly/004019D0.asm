004019D0  6a ff                                         push    0FFFFFFFFh
004019D2  68 c8 ab 41 00                                push    offset SEH_4019D0
004019D7  64 a1 00 00 00 00                             mov     eax, large fs:0
004019DD  50                                            push    eax
004019DE  64 89 25 00 00 00 00                          mov     large fs:0, esp
004019E5  51                                            push    ecx
004019E6  56                                            push    esi
004019E7  8b f1                                         mov     esi, ecx
004019E9  89 74 24 04                                   mov     [esp+14h+var_10], esi
004019ED  c7 06 84 c5 41 00                             mov     dword ptr [esi], offset off_41C584
004019F3  8d 4e 10                                      lea     ecx, [esi+10h]; this
004019F6  c7 44 24 10 00 00 00 00                       mov     [esp+14h+var_4], 0
004019FE  e8 03 8c 01 00                                call    ??1CString@@QAE@XZ; CString::~CString(void)
00401A03  8b 4c 24 08                                   mov     ecx, [esp+14h+var_C]
00401A07  c7 06 70 c5 41 00                             mov     dword ptr [esi], offset off_41C570
00401A0D  5e                                            pop     esi
00401A0E  64 89 0d 00 00 00 00                          mov     large fs:0, ecx
00401A15  83 c4 10                                      add     esp, 10h
00401A18  c3                                            retn
0041ABC0  8b 4d f0                                      mov     ecx, [ebp-10h]
0041ABC3  e9 d8 6d fe ff                                jmp     sub_4019A0
0041ABC8  b8 c8 d2 41 00                                mov     eax, offset stru_41D2C8
0041ABCD  e9 4a fc ff ff                                jmp     __CxxFrameHandler
