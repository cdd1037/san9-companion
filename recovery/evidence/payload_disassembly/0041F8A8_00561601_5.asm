; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0041F8A8; baseline game VA=0x00561601; size=5
; Relative branch annotations use the baseline game destination.
00561601 [0041F8A8] e8 a1 e1 ed ff                               call    near ptr 2FDA4Eh ; game-relative-target=0x0043F7A7
