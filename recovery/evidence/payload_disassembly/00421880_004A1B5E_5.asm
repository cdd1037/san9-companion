; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00421880; baseline game VA=0x004A1B5E; size=5
; Relative branch annotations use the baseline game destination.
004A1B5E [00421880] e8 3d 0c c0 ff                               call    near ptr 224C2h ; game-relative-target=0x000A27A0
