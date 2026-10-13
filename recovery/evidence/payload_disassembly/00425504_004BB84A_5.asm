; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00425504; baseline game VA=0x004BB84A; size=5
; Relative branch annotations use the baseline game destination.
004BB84A [00425504] e8 b1 9b be ff                               call    near ptr 0F0BAh ; game-relative-target=0x000A5400
