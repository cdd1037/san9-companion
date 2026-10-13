; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004278D0; baseline game VA=0x0050577D; size=10
; Relative branch annotations use the baseline game destination.
0050577D [004278D0] e8 2e 0e ba ff                               call    near ptr 0FFFC8703h ; game-relative-target=0x000A65B0
00505782 [004278D5] 40                                           inc     eax
00505783 [004278D6] 40                                           inc     eax
00505784 [004278D7] 40                                           inc     eax
00505785 [004278D8] 40                                           inc     eax
00505786 [004278D9] 40                                           inc     eax
