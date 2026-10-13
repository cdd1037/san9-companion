; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004259E8; baseline game VA=0x004AAE0F; size=5
; Relative branch annotations use the baseline game destination.
004AAE0F [004259E8] e8 bc 71 bf ff                               call    near ptr 1CBA9h ; game-relative-target=0x000A1FD0
