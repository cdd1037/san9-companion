; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00424AE8; baseline game VA=0x005023D5; size=6
; Relative branch annotations use the baseline game destination.
005023D5 [00424AE8] 39 44 24 1c                                  cmp     [esp+1Ch], eax
005023D9 [00424AEC] 75 7c                                        jnz     short near ptr unk_424B6A ; game-relative-target=0x00502457
