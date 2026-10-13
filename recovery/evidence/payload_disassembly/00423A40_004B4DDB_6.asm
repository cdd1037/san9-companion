; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00423A40; baseline game VA=0x004B4DDB; size=6
; Relative branch annotations use the baseline game destination.
004B4DDB [00423A40] e8 10 b7 be ff                               call    near ptr 0F155h ; game-relative-target=0x000A04F0
004B4DE0 [00423A45] 41                                           inc     ecx
