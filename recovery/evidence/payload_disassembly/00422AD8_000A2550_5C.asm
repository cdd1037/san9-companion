; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00422AD8; baseline game VA=0x000A2550; size=92
; Relative branch annotations use the baseline game destination.
000A2550 [00422AD8] 56                                           push    esi
000A2551 [00422AD9] 8b 74 24 08                                  mov     esi, [esp+8]
000A2555 [00422ADD] 83 ec 20                                     sub     esp, 20h ; ' '
000A2558 [00422AE0] 8b cc                                        mov     ecx, esp
000A255A [00422AE2] b8 c0 3c 47 00                               mov     eax, 473CC0h
000A255F [00422AE7] ff d0                                        call    eax
000A2561 [00422AE9] 6a 00                                        push    0
000A2563 [00422AEB] 50                                           push    eax
000A2564 [00422AEC] 8b ce                                        mov     ecx, esi
000A2566 [00422AEE] b8 20 6a 43 00                               mov     eax, 436A20h
000A256B [00422AF3] ff d0                                        call    eax
000A256D [00422AF5] 8b cc                                        mov     ecx, esp
000A256F [00422AF7] 68 60 45 47 00                               push    474560h
000A2574 [00422AFC] b8 80 17 0a 00                               mov     eax, 0A1780h
000A2579 [00422B01] ff d0                                        call    eax
000A257B [00422B03] 8b cc                                        mov     ecx, esp
000A257D [00422B05] 50                                           push    eax
000A257E [00422B06] b8 e0 80 51 00                               mov     eax, 5180E0h
000A2583 [00422B0B] ff d0                                        call    eax
000A2585 [00422B0D] c6 05 d2 19 0a 00 eb                         mov     byte ptr ds:0A19D2h, 0EBh
000A258C [00422B14] 8b ce                                        mov     ecx, esi
000A258E [00422B16] b8 90 19 0a 00                               mov     eax, 0A1990h
000A2593 [00422B1B] ff d0                                        call    eax
000A2595 [00422B1D] c6 05 d2 19 0a 00 7e                         mov     byte ptr ds:0A19D2h, 7Eh ; '~'
000A259C [00422B24] 59                                           pop     ecx
000A259D [00422B25] 03 c1                                        add     eax, ecx
000A259F [00422B27] 03 86 88 00 00 00                            add     eax, [esi+88h]
000A25A5 [00422B2D] 83 c4 20                                     add     esp, 20h ; ' '
000A25A8 [00422B30] 5e                                           pop     esi
000A25A9 [00422B31] c2 04 00                                     retn    4
