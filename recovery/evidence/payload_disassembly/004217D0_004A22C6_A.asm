; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004217D0; baseline game VA=0x004A22C6; size=10
; Relative branch annotations use the baseline game destination.
004A22C6 [004217D0] 7c df                                        jl      short near ptr unk_4217B1 ; game-relative-target=0x004A22A7
004A22C8 [004217D2] 3b e9                                        cmp     ebp, ecx
004A22CA [004217D4] 7c db                                        jl      short near ptr unk_4217B1 ; game-relative-target=0x004A22A7
004A22CC [004217D6] 3b e8                                        cmp     ebp, eax
004A22CE [004217D8] 7c d7                                        jl      short near ptr unk_4217B1 ; game-relative-target=0x004A22A7
