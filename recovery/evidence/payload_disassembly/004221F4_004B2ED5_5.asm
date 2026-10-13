; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004221F4; baseline game VA=0x004B2ED5; size=5
; Relative branch annotations use the baseline game destination.
004B2ED5 [004221F4] e8 26 ea be ff                               call    near ptr 10C1Fh ; game-relative-target=0x000A1900
