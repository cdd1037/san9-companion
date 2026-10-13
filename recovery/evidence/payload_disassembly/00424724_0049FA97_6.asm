; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00424724; baseline game VA=0x0049FA97; size=6
; Relative branch annotations use the baseline game destination.
0049FA97 [00424724] e8 64 53 c0 ff                               call    near ptr 29A8Dh ; game-relative-target=0x000A4E00
0049FA9C [00424729] 90                                           nop
