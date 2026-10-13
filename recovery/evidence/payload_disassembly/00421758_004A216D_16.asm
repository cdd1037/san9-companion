; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00421758; baseline game VA=0x004A216D; size=22
; Relative branch annotations use the baseline game destination.
004A216D [00421758] 0f 8c 51 01 00 00                            jl      near ptr unk_4218AF ; game-relative-target=0x004A22C4
004A2173 [0042175E] 3b d9                                        cmp     ebx, ecx
004A2175 [00421760] 0f 8c 49 01 00 00                            jl      near ptr unk_4218AF ; game-relative-target=0x004A22C4
004A217B [00421766] 3b d8                                        cmp     ebx, eax
004A217D [00421768] 0f 8c 41 01 00 00                            jl      near ptr unk_4218AF ; game-relative-target=0x004A22C4
