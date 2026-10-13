; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00429E64; baseline game VA=0x004EC414; size=5
; Relative branch annotations use the baseline game destination.
004EC414 [00429E64] e8 e7 bd bb ff                               call    near ptr 0FFFE5C50h ; game-relative-target=0x000A8200
