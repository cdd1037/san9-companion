00404610  6a ff                                         push    0FFFFFFFFh
00404612  68 88 af 41 00                                push    offset SEH_404610
00404617  64 a1 00 00 00 00                             mov     eax, large fs:0
0040461D  50                                            push    eax
0040461E  64 89 25 00 00 00 00                          mov     large fs:0, esp
00404625  51                                            push    ecx
00404626  56                                            push    esi
00404627  8b f1                                         mov     esi, ecx
00404629  89 74 24 04                                   mov     [esp+14h+var_10], esi
0040462D  c7 06 ac c9 41 00                             mov     dword ptr [esi], offset off_41C9AC
00404633  c7 44 24 10 00 00 00 00                       mov     [esp+14h+var_4], 0
0040463B  e8 8c 60 01 00                                call    ?DeleteObject@CGdiObject@@QAEHXZ; CGdiObject::DeleteObject(void)
00404640  8b 4c 24 08                                   mov     ecx, [esp+14h+var_C]
00404644  c7 06 70 c5 41 00                             mov     dword ptr [esi], offset off_41C570
0040464A  5e                                            pop     esi
0040464B  64 89 0d 00 00 00 00                          mov     large fs:0, ecx
00404652  83 c4 10                                      add     esp, 10h
00404655  c3                                            retn
0041AF80  8b 4d f0                                      mov     ecx, [ebp-10h]
0041AF83  e9 18 6a fe ff                                jmp     sub_4019A0
0041AF88  b8 98 d7 41 00                                mov     eax, offset stru_41D798
0041AF8D  e9 8a f8 ff ff                                jmp     __CxxFrameHandler
