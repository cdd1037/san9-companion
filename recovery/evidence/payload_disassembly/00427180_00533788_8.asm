; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00427180; baseline game VA=0x00533788; size=8
; Relative branch annotations use the baseline game destination.
00533788 [00427180] eb 06                                        jmp     short near ptr dword_427188 ; game-relative-target=0x00533790
0053378A [00427182] 8d 9b 00 00 00 00                            lea     ebx, [ebx+0]
