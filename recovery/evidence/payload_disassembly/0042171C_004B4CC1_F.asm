; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042171C; baseline game VA=0x004B4CC1; size=15
; Relative branch annotations use the baseline game destination.
004B4CC1 [0042171C] b8 10 0e 47 00                               mov     eax, 470E10h
004B4CC6 [00421721] ff d0                                        call    eax
004B4CC8 [00421723] 68 b3 22 4a 00                               push    4A22B3h
004B4CCD [00421728] c2 04 00                                     retn    4
