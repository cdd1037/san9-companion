; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00425E74; baseline game VA=0x004B4C03; size=6
; Relative branch annotations use the baseline game destination.
004B4C03 [00425E74] e8 f8 0b bf ff                               call    near ptr 16A71h ; game-relative-target=0x000A5800
004B4C08 [00425E79] 41                                           inc     ecx
