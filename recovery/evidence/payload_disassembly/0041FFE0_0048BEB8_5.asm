; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0041FFE0; baseline game VA=0x0048BEB8; size=5
; Relative branch annotations use the baseline game destination.
0048BEB8 [0041FFE0] e8 98 13 fe ff                               call    near ptr loc_401378+5 ; game-relative-target=0x0046D255
