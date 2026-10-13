; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00424C6C; baseline game VA=0x0049A487; size=6
; Relative branch annotations use the baseline game destination.
0049A487 [00424C6C] e8 34 c7 c0 ff                               call    near ptr 313A5h ; game-relative-target=0x000A6BC0
0049A48C [00424C71] 40                                           inc     eax
