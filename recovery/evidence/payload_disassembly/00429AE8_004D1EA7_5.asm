; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00429AE8; baseline game VA=0x004D1EA7; size=5
; Relative branch annotations use the baseline game destination.
004D1EA7 [00429AE8] e8 44 62 bd ff                               call    near ptr 0FFFFFD31h ; game-relative-target=0x000A80F0
