; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00429C28; baseline game VA=0x004D016D; size=5
; Relative branch annotations use the baseline game destination.
004D016D [00429C28] e8 76 7f bd ff                               call    near ptr 1BA3h ; game-relative-target=0x000A80E8
