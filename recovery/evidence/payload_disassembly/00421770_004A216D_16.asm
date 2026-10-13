; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00421770; baseline game VA=0x004A216D; size=22
; Relative branch annotations use the baseline game destination.
004A216D [00421770] 0f 8c f5 00 00 00                            jl      near ptr dword_421868+3 ; game-relative-target=0x004A2268
004A2173 [00421776] 3b d9                                        cmp     ebx, ecx
004A2175 [00421778] 0f 8c ed 00 00 00                            jl      near ptr dword_421868+3 ; game-relative-target=0x004A2268
004A217B [0042177E] 3b d8                                        cmp     ebx, eax
004A217D [00421780] 0f 8c e5 00 00 00                            jl      near ptr dword_421868+3 ; game-relative-target=0x004A2268
