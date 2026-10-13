; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00429DC8; baseline game VA=0x000A81E0; size=20
; Relative branch annotations use the baseline game destination.
000A81E0 [00429DC8] 8b 44 24 04                                  mov     eax, [esp+4]
000A81E4 [00429DCC] 8b 00                                        mov     eax, [eax]
000A81E6 [00429DCE] b9 00 05 0a 00                               mov     ecx, 0A0500h
000A81EB [00429DD3] 50                                           push    eax
000A81EC [00429DD4] b8 60 eb 46 00                               mov     eax, 46EB60h
000A81F1 [00429DD9] ff d0                                        call    eax
000A81F3 [00429DDB] c3                                           retn
