; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042A020; baseline game VA=0x004E642D; size=5
; Relative branch annotations use the baseline game destination.
004E642D [0042A020] e8 ce 1d bc ff                               call    near ptr 0FFFEBDF3h ; game-relative-target=0x000A8200
