; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00428BB0; baseline game VA=0x004BDD8E; size=5
; Relative branch annotations use the baseline game destination.
004BDD8E [00428BB0] e8 3d 9a be ff                               call    near ptr 125F2h ; game-relative-target=0x000A77D0
