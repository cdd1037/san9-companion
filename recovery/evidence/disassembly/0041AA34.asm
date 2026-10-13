0041AA34  68 00 00 03 00                                push    30000h; Mask
0041AA39  68 00 00 01 00                                push    10000h; NewValue
0041AA3E  e8 0d 00 00 00                                call    _controlfp
0041AA43  59                                            pop     ecx
0041AA44  59                                            pop     ecx
0041AA45  c3                                            retn
