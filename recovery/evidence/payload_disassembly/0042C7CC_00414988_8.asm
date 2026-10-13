; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042C7CC; baseline game VA=0x00414988; size=8
; Relative branch annotations use the baseline game destination.
00414988 [0042C7CC] e8 23 a4 06 00                               call    near ptr 496BF4h ; game-relative-target=0x0047EDB0
0041498D [0042C7D1] 8d 48 68                                     lea     ecx, [eax+68h]
