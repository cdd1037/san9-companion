; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004293AC; baseline game VA=0x00505393; size=12
; Relative branch annotations use the baseline game destination.
00505393 [004293AC] e8 78 ba f6 ff                               call    near ptr 394E29h ; game-relative-target=0x00470E10
00505398 [004293B1] eb 33                                        jmp     short near ptr unk_4293E6 ; game-relative-target=0x005053CD
0050539A [004293B3] 83 ff 0a                                     cmp     edi, 0Ah
0050539D [004293B6] 75 2e                                        jnz     short near ptr unk_4293E6 ; game-relative-target=0x005053CD
