; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042A550; baseline game VA=0x00520B32; size=5
; Relative branch annotations use the baseline game destination.
00520B32 [0042A550] e8 49 7b b8 ff                               call    near ptr 0FFFB209Eh ; game-relative-target=0x000A8680
