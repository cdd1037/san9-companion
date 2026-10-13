; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004272F8; baseline game VA=0x005287AB; size=5
; Relative branch annotations use the baseline game destination.
005287AB [004272F8] e8 50 e8 b7 ff                               call    near ptr 0FFFA5B4Dh ; game-relative-target=0x000A7000
