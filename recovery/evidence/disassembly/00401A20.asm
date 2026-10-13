00401A20  8b 41 20                                      mov     eax, [ecx+20h]
00401A23  6a 00                                         push    0; bEnable
00401A25  50                                            push    eax; hWnd
00401A26  ff 15 60 c3 41 00                             call    ds:EnableWindow; USER32
00401A2C  c3                                            retn
