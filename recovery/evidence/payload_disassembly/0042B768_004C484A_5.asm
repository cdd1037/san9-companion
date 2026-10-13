; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042B768; baseline game VA=0x004C484A; size=5
; Relative branch annotations use the baseline game destination.
004C484A [0042B768] e8 71 c2 bd ff                               call    near ptr 79DEh ; game-relative-target=0x000A0AC0
