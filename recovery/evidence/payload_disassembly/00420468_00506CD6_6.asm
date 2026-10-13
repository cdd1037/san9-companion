; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00420468; baseline game VA=0x00506CD6; size=6
; Relative branch annotations use the baseline game destination.
00506CD6 [00420468] e8 d5 95 b9 ff                               call    near ptr 0FFFB9A42h ; game-relative-target=0x000A02B0
00506CDB [0042046D] 41                                           inc     ecx
