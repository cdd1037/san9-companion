; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00428920; baseline game VA=0x000A7700; size=50
; Relative branch annotations use the baseline game destination.
000A7700 [00428920] 56                                           push    esi
000A7701 [00428921] 57                                           push    edi
000A7702 [00428922] 8b f1                                        mov     esi, ecx
000A7704 [00428924] b8 b0 4e 0a 00                               mov     eax, 0A4EB0h
000A7709 [00428929] ff d0                                        call    eax
000A770B [0042892B] 8b f8                                        mov     edi, eax
000A770D [0042892D] 8b ce                                        mov     ecx, esi
000A770F [0042892F] b8 e0 f3 43 00                               mov     eax, 43F3E0h
000A7714 [00428934] ff d0                                        call    eax
000A7716 [00428936] 69 c0 20 4e 00 00                            imul    eax, 4E20h
000A771C [0042893C] 03 f8                                        add     edi, eax
000A771E [0042893E] 8b ce                                        mov     ecx, esi
000A7720 [00428940] b8 50 f4 43 00                               mov     eax, 43F450h
000A7725 [00428945] ff d0                                        call    eax
000A7727 [00428947] 69 c0 88 13 00 00                            imul    eax, 1388h
000A772D [0042894D] 03 c7                                        add     eax, edi
000A772F [0042894F] 5f                                           pop     edi
000A7730 [00428950] 5e                                           pop     esi
000A7731 [00428951] c3                                           retn
