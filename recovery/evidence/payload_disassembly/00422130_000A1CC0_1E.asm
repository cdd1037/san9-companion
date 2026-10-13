; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00422130; baseline game VA=0x000A1CC0; size=30
; Relative branch annotations use the baseline game destination.
000A1CC0 [00422130] 56                                           push    esi
000A1CC1 [00422131] 8b 74 24 08                                  mov     esi, [esp+8]
000A1CC5 [00422135] 8b 0e                                        mov     ecx, [esi]
000A1CC7 [00422137] 6a 02                                        push    2
000A1CC9 [00422139] b8 90 d4 44 00                               mov     eax, 44D490h
000A1CCE [0042213E] ff d0                                        call    eax
000A1CD0 [00422140] 03 44 24 f0                                  add     eax, [esp-10h]
000A1CD4 [00422144] 8b 0e                                        mov     ecx, [esi]
000A1CD6 [00422146] 03 41 54                                     add     eax, [ecx+54h]
000A1CD9 [00422149] 03 41 5c                                     add     eax, [ecx+5Ch]
000A1CDC [0042214C] 5e                                           pop     esi
000A1CDD [0042214D] c3                                           retn
