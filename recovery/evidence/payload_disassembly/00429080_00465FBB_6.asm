; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00429080; baseline game VA=0x00465FBB; size=6
; Relative branch annotations use the baseline game destination.
00465FBB [00429080] e8 b0 1b c4 ff                               call    near ptr 6AC35h ; game-relative-target=0x000A7B70
00465FC0 [00429085] 90                                           nop
