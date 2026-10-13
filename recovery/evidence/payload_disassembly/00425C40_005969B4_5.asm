; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00425C40; baseline game VA=0x005969B4; size=5
; Relative branch annotations use the baseline game destination.
005969B4 [00425C40] e8 e7 ec b0 ff                               call    near ptr 0FFF3492Ch ; game-relative-target=0x000A56A0
