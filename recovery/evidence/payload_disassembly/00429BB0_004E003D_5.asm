; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00429BB0; baseline game VA=0x004E003D; size=5
; Relative branch annotations use the baseline game destination.
004E003D [00429BB0] e8 c6 80 bc ff                               call    near ptr 0FFFF1C7Bh ; game-relative-target=0x000A8108
