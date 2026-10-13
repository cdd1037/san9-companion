; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042472C; baseline game VA=0x0049FA97; size=6
; Relative branch annotations use the baseline game destination.
0049FA97 [0042472C] 8b 44 24 1c                                  mov     eax, [esp+1Ch]
0049FA9B [00424730] 85 c0                                        test    eax, eax
