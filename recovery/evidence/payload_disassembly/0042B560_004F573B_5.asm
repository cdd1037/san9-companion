; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042B560; baseline game VA=0x004F573B; size=5
; Relative branch annotations use the baseline game destination.
004F573B [0042B560] 8b cf                                        mov     ecx, edi
004F573D [0042B562] E8    db 0xE8
004F573E [0042B563] 5e                                           pop     esi
004F573F [0042B564] 71    db 0x71
