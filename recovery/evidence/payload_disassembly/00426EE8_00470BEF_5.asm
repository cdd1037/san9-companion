; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00426EE8; baseline game VA=0x00470BEF; size=5
; Relative branch annotations use the baseline game destination.
00470BEF [00426EE8] e8 ec 5e c3 ff                               call    near ptr 5CDD9h ; game-relative-target=0x000A6AE0
