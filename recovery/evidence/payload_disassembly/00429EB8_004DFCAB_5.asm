; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00429EB8; baseline game VA=0x004DFCAB; size=5
; Relative branch annotations use the baseline game destination.
004DFCAB [00429EB8] e8 50 85 bc ff                               call    near ptr 0FFFF240Dh ; game-relative-target=0x000A8200
