; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00428468; baseline game VA=0x004A2F4E; size=6
; Relative branch annotations use the baseline game destination.
004A2F4E [00428468] e8 7d 45 c0 ff                               call    near ptr 2C9EAh ; game-relative-target=0x000A74D0
004A2F53 [0042846D] 90                                           nop
