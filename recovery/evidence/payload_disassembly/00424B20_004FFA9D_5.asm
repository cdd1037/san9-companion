; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00424B20; baseline game VA=0x004FFA9D; size=5
; Relative branch annotations use the baseline game destination.
004FFA9D [00424B20] e8 46 2f ba ff                               call    near ptr 0FFFC7A6Bh ; game-relative-target=0x000A29E8
