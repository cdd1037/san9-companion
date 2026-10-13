; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004294A8; baseline game VA=0x004FFD51; size=7
; Relative branch annotations use the baseline game destination.
004FFD51 [004294A8] 83 7c 24 14 0a                               cmp     dword ptr [esp+14h], 0Ah
004FFD56 [004294AD] 7c 2b                                        jl      short near ptr dword_4294D8+2 ; game-relative-target=0x004FFD83
