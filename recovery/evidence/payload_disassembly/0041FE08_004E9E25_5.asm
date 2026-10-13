; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0041FE08; baseline game VA=0x004E9E25; size=5
; Relative branch annotations use the baseline game destination.
004E9E25 [0041FE08] e8 fa e8 01 00                               call    near ptr 43E707h ; game-relative-target=0x00508724
