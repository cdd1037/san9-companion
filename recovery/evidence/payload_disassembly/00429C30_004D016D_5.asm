; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00429C30; baseline game VA=0x004D016D; size=5
; Relative branch annotations use the baseline game destination.
004D016D [00429C30] e8 3e d4 fb ff                               call    near ptr 3E7073h ; game-relative-target=0x0048D5B0
