; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004200B8; baseline game VA=0x00467B8D; size=5
; Relative branch annotations use the baseline game destination.
00467B8D [004200B8] e8 2e bf c3 ff                               call    near ptr 5BFEBh ; game-relative-target=0x000A3AC0
