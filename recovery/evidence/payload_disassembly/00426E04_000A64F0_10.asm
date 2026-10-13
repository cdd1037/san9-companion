; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00426E04; baseline game VA=0x000A64F0; size=16
; Relative branch annotations use the baseline game destination.
000A64F0 [00426E04] 50                                           push    eax
000A64F1 [00426E05] 8b 4c 24 14                                  mov     ecx, [esp+14h]
000A64F5 [00426E09] b8 60 63 0a 00                               mov     eax, 0A6360h
000A64FA [00426E0E] ff d0                                        call    eax
000A64FC [00426E10] 8b c8                                        mov     ecx, eax
000A64FE [00426E12] 58                                           pop     eax
000A64FF [00426E13] c3                                           retn
