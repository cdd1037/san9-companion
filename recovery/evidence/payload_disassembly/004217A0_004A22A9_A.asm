; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004217A0; baseline game VA=0x004A22A9; size=10
; Relative branch annotations use the baseline game destination.
004A22A9 [004217A0] 7c c9                                        jl      short near ptr unk_42176B ; game-relative-target=0x004A2274
004A22AB [004217A2] 3b cb                                        cmp     ecx, ebx
004A22AD [004217A4] 7c c5                                        jl      short near ptr unk_42176B ; game-relative-target=0x004A2274
004A22AF [004217A6] 3b c8                                        cmp     ecx, eax
004A22B1 [004217A8] 7c c1                                        jl      short near ptr unk_42176B ; game-relative-target=0x004A2274
