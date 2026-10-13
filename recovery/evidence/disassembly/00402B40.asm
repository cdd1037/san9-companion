00402B40  56                                            push    esi
00402B41  8b f1                                         mov     esi, ecx
00402B43  8a 86 b5 00 00 00                             mov     al, [esi+0B5h]
00402B49  8a 8e b4 00 00 00                             mov     cl, [esi+0B4h]
00402B4F  3a c1                                         cmp     al, cl
00402B51  73 4e                                         jnb     short loc_402BA1
00402B53  8b 8e ac 00 00 00                             mov     ecx, [esi+0ACh]
00402B59  25 ff 00 00 00                                and     eax, 0FFh
00402B5E  33 d2                                         xor     edx, edx
00402B60  6a 00                                         push    0; lParam
00402B62  8a 14 81                                      mov     dl, [ecx+eax*4]
00402B65  8d 0c 81                                      lea     ecx, [ecx+eax*4]
00402B68  89 96 a8 00 00 00                             mov     [esi+0A8h], edx
00402B6E  33 d2                                         xor     edx, edx
00402B70  8a 51 01                                      mov     dl, [ecx+1]
00402B73  50                                            push    eax; wParam
00402B74  89 96 a0 00 00 00                             mov     [esi+0A0h], edx
00402B7A  33 d2                                         xor     edx, edx
00402B7C  66 8b 51 02                                   mov     dx, [ecx+2]
00402B80  68 86 01 00 00                                push    186h; Msg
00402B85  89 96 a4 00 00 00                             mov     [esi+0A4h], edx
00402B8B  8b 86 80 00 00 00                             mov     eax, [esi+80h]
00402B91  50                                            push    eax; hWnd
00402B92  ff 15 64 c3 41 00                             call    ds:SendMessageA; USER32
00402B98  6a 00                                         push    0; int
00402B9A  8b ce                                         mov     ecx, esi; this
00402B9C  e8 89 7a 01 00                                call    ?UpdateData@CWnd@@QAEHH@Z; CWnd::UpdateData(int)
00402BA1  5e                                            pop     esi
00402BA2  c3                                            retn
