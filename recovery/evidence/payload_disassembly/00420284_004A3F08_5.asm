; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00420284; baseline game VA=0x004A3F08; size=5
; Relative branch annotations use the baseline game destination.
004A3F08 [00420284] e8 53 c6 bf ff                               call    near ptr 1C8DCh ; game-relative-target=0x000A0560
