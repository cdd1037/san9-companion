; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004216EC; baseline game VA=0x004B3456; size=6
; Relative branch annotations use the baseline game destination.
004B3456 [004216EC] e8 a5 f2 be ff                               call    near ptr 10996h ; game-relative-target=0x000A2700
004B345B [004216F1] 42                                           inc     edx
