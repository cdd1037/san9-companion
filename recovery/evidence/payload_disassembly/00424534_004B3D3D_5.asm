; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00424534; baseline game VA=0x004B3D3D; size=5
; Relative branch annotations use the baseline game destination.
004B3D3D [00424534] e8 86 ee be ff                               call    near ptr 133BFh ; game-relative-target=0x000A2BC8
