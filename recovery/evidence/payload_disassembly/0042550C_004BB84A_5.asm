; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042550C; baseline game VA=0x004BB84A; size=5
; Relative branch annotations use the baseline game destination.
004BB84A [0042550C] e8 51 10 fa ff                               call    near ptr 3C6562h ; game-relative-target=0x0045C8A0
