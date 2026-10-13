; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042B6DC; baseline game VA=0x004C4775; size=16
; Relative branch annotations use the baseline game destination.
004C4775 [0042B6DC] 83 f9 03                                     cmp     ecx, 3
004C4778 [0042B6DF] 7c 14                                        jl      short near ptr unk_42B6F5 ; game-relative-target=0x004C478E
004C477A [0042B6E1] 83 f9 05                                     cmp     ecx, 5
004C477D [0042B6E4] 7f 0f                                        jg      short near ptr unk_42B6F5 ; game-relative-target=0x004C478E
004C477F [0042B6E6] 50                                           push    eax
004C4780 [0042B6E7] e8 3b f0 f8 ff                               call    near ptr 3BA727h ; game-relative-target=0x004537C0
