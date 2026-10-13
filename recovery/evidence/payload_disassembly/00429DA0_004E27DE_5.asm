; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00429DA0; baseline game VA=0x004E27DE; size=5
; Relative branch annotations use the baseline game destination.
004E27DE [00429DA0] e8 6d 59 bc ff                               call    near ptr 0FFFEF712h ; game-relative-target=0x000A8150
