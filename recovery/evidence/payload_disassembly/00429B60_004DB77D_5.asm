; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00429B60; baseline game VA=0x004DB77D; size=5
; Relative branch annotations use the baseline game destination.
004DB77D [00429B60] e8 76 c9 bc ff                               call    near ptr 0FFFF64DBh ; game-relative-target=0x000A80F8
