; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00429B88; baseline game VA=0x004E06EA; size=5
; Relative branch annotations use the baseline game destination.
004E06EA [00429B88] e8 19 7a bc ff                               call    near ptr 0FFFF15A6h ; game-relative-target=0x000A8108
