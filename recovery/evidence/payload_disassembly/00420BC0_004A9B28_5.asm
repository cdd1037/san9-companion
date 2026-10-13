; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00420BC0; baseline game VA=0x004A9B28; size=5
; Relative branch annotations use the baseline game destination.
004A9B28 [00420BC0] e8 d3 70 bf ff                               call    near ptr 17C98h ; game-relative-target=0x000A0C00
