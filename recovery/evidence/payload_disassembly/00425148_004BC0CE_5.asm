; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00425148; baseline game VA=0x004BC0CE; size=5
; Relative branch annotations use the baseline game destination.
004BC0CE [00425148] e8 2d 8f be ff                               call    near ptr 0E07Ah ; game-relative-target=0x000A5000
