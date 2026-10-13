; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004217AC; baseline game VA=0x004A22A9; size=10
; Relative branch annotations use the baseline game destination.
004A22A9 [004217AC] 7c 19                                        jl      short near ptr dword_4217C4+3 ; game-relative-target=0x004A22C4
004A22AB [004217AE] 3b cb                                        cmp     ecx, ebx
004A22AD [004217B0] 7c 15                                        jl      short near ptr dword_4217C4+3 ; game-relative-target=0x004A22C4
004A22AF [004217B2] 3b c8                                        cmp     ecx, eax
004A22B1 [004217B4] 7c 11                                        jl      short near ptr dword_4217C4+3 ; game-relative-target=0x004A22C4
