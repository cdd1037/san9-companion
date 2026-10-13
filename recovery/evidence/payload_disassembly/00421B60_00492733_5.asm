; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00421B60; baseline game VA=0x00492733; size=5
; Relative branch annotations use the baseline game destination.
00492733 [00421B60] e8 38 00 c1 ff                               call    near ptr 31B9Dh ; game-relative-target=0x000A2770
