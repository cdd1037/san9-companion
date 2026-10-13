; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00421E80; baseline game VA=0x004B2FB0; size=5
; Relative branch annotations use the baseline game destination.
004B2FB0 [00421E80] e8 8b eb be ff                               call    near ptr 10A10h ; game-relative-target=0x000A1B40
