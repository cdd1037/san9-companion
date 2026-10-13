; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00425CD8; baseline game VA=0x000A5748; size=17
; Relative branch annotations use the baseline game destination.
000A5748 [00425CD8] 8b ce                                        mov     ecx, esi
000A574A [00425CDA] b8 c0 61 43 00                               mov     eax, 4361C0h
000A574F [00425CDF] ff d0                                        call    eax
000A5751 [00425CE1] 3b f8                                        cmp     edi, eax
000A5753 [00425CE3] b8 00 00 00 00                               mov     eax, 0
000A5758 [00425CE8] c3                                           retn
