; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0041F8B0; baseline game VA=0x00561601; size=5
; Relative branch annotations use the baseline game destination.
00561601 [0041F8B0] 8b f1                                        mov     esi, ecx
00561603 [0041F8B2] 8b 46 2c                                     mov     eax, [esi+2Ch]
