; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004293A0; baseline game VA=0x00505393; size=12
; Relative branch annotations use the baseline game destination.
00505393 [004293A0] e8 98 29 ba ff                               call    near ptr 0FFFCBD3Dh ; game-relative-target=0x000A7D30
00505398 [004293A5] eb 33                                        jmp     short near ptr unk_4293DA ; game-relative-target=0x005053CD
0050539A [004293A7] e9 2e 00 00 00                               jmp     near ptr unk_4293DA ; game-relative-target=0x005053CD
