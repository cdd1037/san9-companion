; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042966C; baseline game VA=0x004EA2E0; size=4
; Relative branch annotations use the baseline game destination.
004EA2E0 [0042966C] 50                                           push    eax
004EA2E1 [0042966D] 7e 0a                                        jle     short near ptr dword_429678+1 ; game-relative-target=0x004EA2ED
004EA2E3 [0042966F] 00    db 0x00
