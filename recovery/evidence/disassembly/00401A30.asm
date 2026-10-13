00401A30  8b 41 20                                      mov     eax, [ecx+20h]
00401A33  6a 01                                         push    1; bEnable
00401A35  50                                            push    eax; hWnd
00401A36  ff 15 60 c3 41 00                             call    ds:EnableWindow; USER32
00401A3C  c3                                            retn
