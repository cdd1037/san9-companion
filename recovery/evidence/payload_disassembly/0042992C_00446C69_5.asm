; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042992C; baseline game VA=0x00446C69; size=5
; Relative branch annotations use the baseline game destination.
00446C69 [0042992C] e8 f2 9d c5 ff                               call    near ptr 83723h ; game-relative-target=0x000A0A60
