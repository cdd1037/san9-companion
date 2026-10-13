; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00429B90; baseline game VA=0x004E06EA; size=5
; Relative branch annotations use the baseline game destination.
004E06EA [00429B90] e8 d1 1f fb ff                               call    near ptr 3DBB66h ; game-relative-target=0x004926C0
