; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00428130; baseline game VA=0x000A58F0; size=13
; Relative branch annotations use the baseline game destination.
000A58F0 [00428130] 33 c0                                        xor     eax, eax
000A58F2 [00428132] a3 b1 f4 43 00                               mov     ds:43F4B1h, eax
000A58F7 [00428137] 68 00 df 4f 00                               push    4FDF00h
000A58FC [0042813C] c3                                           retn
