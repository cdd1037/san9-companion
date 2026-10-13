; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00424DC8; baseline game VA=0x004BC1F3; size=5
; Relative branch annotations use the baseline game destination.
004BC1F3 [00424DC8] e8 08 8b be ff                               call    near ptr 0D8D5h ; game-relative-target=0x000A4D00
