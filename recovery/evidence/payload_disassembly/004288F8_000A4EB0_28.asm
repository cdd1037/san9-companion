; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004288F8; baseline game VA=0x000A4EB0; size=40
; Relative branch annotations use the baseline game destination.
000A4EB0 [004288F8] 56                                           push    esi
000A4EB1 [004288F9] 57                                           push    edi
000A4EB2 [004288FA] 8b f1                                        mov     esi, ecx
000A4EB4 [004288FC] b8 d0 f0 43 00                               mov     eax, 43F0D0h
000A4EB9 [00428901] ff d0                                        call    eax
000A4EBB [00428903] 8b f8                                        mov     edi, eax
000A4EBD [00428905] 8b ce                                        mov     ecx, esi
000A4EBF [00428907] b8 30 f2 43 00                               mov     eax, 43F230h
000A4EC4 [0042890C] ff d0                                        call    eax
000A4EC6 [0042890E] 03 f8                                        add     edi, eax
000A4EC8 [00428910] 8b ce                                        mov     ecx, esi
000A4ECA [00428912] b8 20 0f 44 00                               mov     eax, 440F20h
000A4ECF [00428917] ff d0                                        call    eax
000A4ED1 [00428919] 03 f8                                        add     edi, eax
000A4ED3 [0042891B] 8b c7                                        mov     eax, edi
000A4ED5 [0042891D] 5f                                           pop     edi
000A4ED6 [0042891E] 5e                                           pop     esi
000A4ED7 [0042891F] c3                                           retn
