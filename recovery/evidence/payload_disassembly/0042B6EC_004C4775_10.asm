; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042B6EC; baseline game VA=0x004C4775; size=16
; Relative branch annotations use the baseline game destination.
004C4775 [0042B6EC] 83 f9 04                                     cmp     ecx, 4
004C4778 [0042B6EF] 74 05                                        jz      short near ptr unk_42B6F6 ; game-relative-target=0x004C477F
004C477A [0042B6F1] 83 f9 05                                     cmp     ecx, 5
004C477D [0042B6F4] 75 0f                                        jnz     short near ptr nSize+1 ; game-relative-target=0x004C478E
004C477F [0042B6F6] 50                                           push    eax
004C4780 [0042B6F7] e8 eb 06 f9 ff                               call    near ptr 3BBDE7h ; game-relative-target=0x00454E70
