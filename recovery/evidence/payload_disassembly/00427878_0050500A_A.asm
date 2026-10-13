; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00427878; baseline game VA=0x0050500A; size=10
; Relative branch annotations use the baseline game destination.
0050500A [00427878] e8 a1 15 ba ff                               call    near ptr 0FFFC8E1Eh ; game-relative-target=0x000A65B0
0050500F [0042787D] 40                                           inc     eax
00505010 [0042787E] 40                                           inc     eax
00505011 [0042787F] 40                                           inc     eax
00505012 [00427880] 40                                           inc     eax
00505013 [00427881] 40                                           inc     eax
