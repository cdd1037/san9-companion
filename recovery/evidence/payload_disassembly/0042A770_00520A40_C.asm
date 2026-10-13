; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042A770; baseline game VA=0x00520A40; size=12
; Relative branch annotations use the baseline game destination.
00520A40 [0042A770] 6a 11                                        push    11h
00520A42 [0042A772] ff d3                                        call    ebx
00520A44 [0042A774] 25 00 80 00 00                               and     eax, 8000h
00520A49 [0042A779] 66 85 c0                                     test    ax, ax
