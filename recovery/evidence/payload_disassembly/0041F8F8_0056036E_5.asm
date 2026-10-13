; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0041F8F8; baseline game VA=0x0056036E; size=5
; Relative branch annotations use the baseline game destination.
0056036E [0041F8F8] e8 ef f4 ed ff                               call    near ptr 2FEDECh ; game-relative-target=0x0043F862
