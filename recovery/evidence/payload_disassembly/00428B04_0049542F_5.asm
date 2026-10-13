; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00428B04; baseline game VA=0x0049542F; size=5
; Relative branch annotations use the baseline game destination.
0049542F [00428B04] 8b d1                                        mov     edx, ecx
00495431 [00428B06] c1 ea 1f                                     shr     edx, 1Fh
