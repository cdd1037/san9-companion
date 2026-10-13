; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00429C50; baseline game VA=0x004CFB0D; size=5
; Relative branch annotations use the baseline game destination.
004CFB0D [00429C50] e8 d6 85 bd ff                               call    near ptr 222Bh ; game-relative-target=0x000A80E8
