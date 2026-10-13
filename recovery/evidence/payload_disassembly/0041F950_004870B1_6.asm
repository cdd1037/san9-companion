; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0041F950; baseline game VA=0x004870B1; size=6
; Relative branch annotations use the baseline game destination.
004870B1 [0041F950] e8 5b f3 ff ff                               call    near ptr algn_41E4B9+7F7h ; game-relative-target=0x00486411
004870B6 [0041F955] 90                                           nop
