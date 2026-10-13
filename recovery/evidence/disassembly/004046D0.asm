004046D0  6a ff                                         push    0FFFFFFFFh
004046D2  68 c8 af 41 00                                push    offset SEH_4046D0
004046D7  64 a1 00 00 00 00                             mov     eax, large fs:0
004046DD  50                                            push    eax
004046DE  64 89 25 00 00 00 00                          mov     large fs:0, esp
004046E5  51                                            push    ecx
004046E6  56                                            push    esi
004046E7  8b f1                                         mov     esi, ecx
004046E9  89 74 24 04                                   mov     [esp+14h+var_10], esi
004046ED  c7 06 90 c9 41 00                             mov     dword ptr [esi], offset off_41C990
004046F3  c7 44 24 10 00 00 00 00                       mov     [esp+14h+var_4], 0
004046FB  e8 9c 5f 01 00                                call    ?DestroyMenu@CMenu@@QAEHXZ; CMenu::DestroyMenu(void)
00404700  8b 4c 24 08                                   mov     ecx, [esp+14h+var_C]
00404704  c7 06 70 c5 41 00                             mov     dword ptr [esi], offset off_41C570
0040470A  5e                                            pop     esi
0040470B  64 89 0d 00 00 00 00                          mov     large fs:0, ecx
00404712  83 c4 10                                      add     esp, 10h
00404715  c3                                            retn
0041AFC0  8b 4d f0                                      mov     ecx, [ebp-10h]
0041AFC3  e9 d8 69 fe ff                                jmp     sub_4019A0
0041AFC8  b8 e8 d7 41 00                                mov     eax, offset stru_41D7E8
0041AFCD  e9 4a f8 ff ff                                jmp     __CxxFrameHandler
