; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00427FE4; baseline game VA=0x0049EA1B; size=4
; Relative branch annotations use the baseline game destination.
0049EA1B [00427FE4] 00 e6                                        add     dh, ah
0049EA1D [00427FE6] 49                                           dec     ecx
0049EA1E [00427FE7] 00    db 0x00
