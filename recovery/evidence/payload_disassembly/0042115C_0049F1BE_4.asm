; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042115C; baseline game VA=0x0049F1BE; size=4
; Relative branch annotations use the baseline game destination.
0049F1BE [0042115C] 80 0f 0a                                     or      byte ptr [edi], 0Ah
0049F1C1 [0042115F] 00    db 0x00
