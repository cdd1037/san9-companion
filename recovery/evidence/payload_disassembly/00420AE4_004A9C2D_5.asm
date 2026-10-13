; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00420AE4; baseline game VA=0x004A9C2D; size=5
; Relative branch annotations use the baseline game destination.
004A9C2D [00420AE4] e8 ee 6e bf ff                               call    near ptr 179D7h ; game-relative-target=0x000A0B20
