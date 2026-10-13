; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00429F08; baseline game VA=0x004EDFAB; size=5
; Relative branch annotations use the baseline game destination.
004EDFAB [00429F08] e8 50 a2 bb ff                               call    near ptr 0FFFE415Dh ; game-relative-target=0x000A8200
