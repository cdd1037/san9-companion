; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00429478; baseline game VA=0x004FE0CD; size=7
; Relative branch annotations use the baseline game destination.
004FE0CD [00429478] b8 70 7d 0a 00                               mov     eax, 0A7D70h
004FE0D2 [0042947D] ff d0                                        call    eax
