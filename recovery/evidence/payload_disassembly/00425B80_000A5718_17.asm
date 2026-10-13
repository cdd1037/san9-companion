; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00425B80; baseline game VA=0x000A5718; size=23
; Relative branch annotations use the baseline game destination.
000A5718 [00425B80] 50                                           push    eax
000A5719 [00425B81] 8b cf                                        mov     ecx, edi
000A571B [00425B83] b8 80 c0 44 00                               mov     eax, 44C080h
000A5720 [00425B88] ff d0                                        call    eax
000A5722 [00425B8A] 8b c8                                        mov     ecx, eax
000A5724 [00425B8C] b8 b1 dd 45 00                               mov     eax, 45DDB1h
000A5729 [00425B91] ff d0                                        call    eax
000A572B [00425B93] 8b f0                                        mov     esi, eax
000A572D [00425B95] 58                                           pop     eax
000A572E [00425B96] c3                                           retn
