; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004240CC; baseline game VA=0x00464B74; size=5
; Relative branch annotations use the baseline game destination.
00464B74 [004240CC] e8 2f e7 c3 ff                               call    near ptr 62800h ; game-relative-target=0x000A32A8
