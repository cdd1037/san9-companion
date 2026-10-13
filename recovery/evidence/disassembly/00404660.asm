00404660  6a ff                                         push    0FFFFFFFFh
00404662  68 a8 af 41 00                                push    offset SEH_404660
00404667  64 a1 00 00 00 00                             mov     eax, large fs:0
0040466D  50                                            push    eax
0040466E  64 89 25 00 00 00 00                          mov     large fs:0, esp
00404675  51                                            push    ecx
00404676  56                                            push    esi
00404677  8b f1                                         mov     esi, ecx
00404679  89 74 24 04                                   mov     [esp+14h+var_10], esi
0040467D  c7 06 ac c9 41 00                             mov     dword ptr [esi], offset off_41C9AC
00404683  c7 44 24 10 00 00 00 00                       mov     [esp+14h+var_4], 0
0040468B  e8 3c 60 01 00                                call    ?DeleteObject@CGdiObject@@QAEHXZ; CGdiObject::DeleteObject(void)
00404690  8b 4c 24 08                                   mov     ecx, [esp+14h+var_C]
00404694  c7 06 70 c5 41 00                             mov     dword ptr [esi], offset off_41C570
0040469A  5e                                            pop     esi
0040469B  64 89 0d 00 00 00 00                          mov     large fs:0, ecx
004046A2  83 c4 10                                      add     esp, 10h
004046A5  c3                                            retn
0041AFA0  8b 4d f0                                      mov     ecx, [ebp-10h]
0041AFA3  e9 f8 69 fe ff                                jmp     sub_4019A0
0041AFA8  b8 c0 d7 41 00                                mov     eax, offset stru_41D7C0
0041AFAD  e9 6a f8 ff ff                                jmp     __CxxFrameHandler
