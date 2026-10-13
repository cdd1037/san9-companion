; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00425A24; baseline game VA=0x0043A4B0; size=5
; Relative branch annotations use the baseline game destination.
0043A4B0 [00425A24] e9 fc 38 02 00                               jmp     near ptr 449325h ; game-relative-target=0x0045DDB1
