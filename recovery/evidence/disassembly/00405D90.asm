00405D90  b9 50 ef 42 00                                mov     ecx, offset dword_42EF50; this
00405D95  e9 96 ff ff ff                                jmp     loc_405D30
00405D30  56                                            push    esi
00405D31  8b f1                                         mov     esi, ecx
00405D33  6a 00                                         push    0; char *
00405D35  e8 8e 4a 01 00                                call    ??0CWinApp@@QAE@PBD@Z
00405D3A  c7 06 b8 cc 41 00                             mov     dword ptr [esi], offset off_41CCB8
00405D40  8b c6                                         mov     eax, esi
00405D42  5e                                            pop     esi
00405D43  c3                                            retn
