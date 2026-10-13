; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00421FF4; baseline game VA=0x004B2CC2; size=5
; Relative branch annotations use the baseline game destination.
004B2CC2 [00421FF4] e8 39 ef be ff                               call    near ptr 10F32h ; game-relative-target=0x000A1C00
