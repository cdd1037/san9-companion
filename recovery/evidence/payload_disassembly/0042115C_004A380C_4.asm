; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042115C; baseline game VA=0x004A380C; size=4
; Relative branch annotations use the baseline game destination.
004A380C [0042115C] 80 0f 0a                                     or      byte ptr [edi], 0Ah
004A380F [0042115F] 00    db 0x00
