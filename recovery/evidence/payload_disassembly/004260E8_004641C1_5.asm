; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004260E8; baseline game VA=0x004641C1; size=5
; Relative branch annotations use the baseline game destination.
004641C1 [004260E8] e8 7a 16 fa ff                               call    near ptr 3C7767h ; game-relative-target=0x00405840
