; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00429174; baseline game VA=0x0050217C; size=4
; Relative branch annotations use the baseline game destination.
0050217C [00429174] 75 20                                        jnz     short near ptr unk_429196 ; game-relative-target=0x0050219E
0050217E [00429176] 50                                           push    eax
0050217F [00429177] 00    db 0x00
