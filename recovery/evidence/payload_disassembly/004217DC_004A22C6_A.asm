; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004217DC; baseline game VA=0x004A22C6; size=10
; Relative branch annotations use the baseline game destination.
004A22C6 [004217DC] 7c 2a                                        jl      short near ptr unk_421808 ; game-relative-target=0x004A22F2
004A22C8 [004217DE] 3b e9                                        cmp     ebp, ecx
004A22CA [004217E0] 7c 26                                        jl      short near ptr unk_421808 ; game-relative-target=0x004A22F2
004A22CC [004217E2] 3b e8                                        cmp     ebp, eax
004A22CE [004217E4] 7c 22                                        jl      short near ptr unk_421808 ; game-relative-target=0x004A22F2
