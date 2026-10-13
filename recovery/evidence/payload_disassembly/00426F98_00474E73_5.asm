; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00426F98; baseline game VA=0x00474E73; size=5
; Relative branch annotations use the baseline game destination.
00474E73 [00426F98] e8 48 1c c3 ff                               call    near ptr 58BE5h ; game-relative-target=0x000A6AC0
