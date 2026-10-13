; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042388C; baseline game VA=0x0045BFB5; size=11
; Relative branch annotations use the baseline game destination.
0045BFB5 [0042388C] 0f b6 46 04                                  movzx   eax, byte ptr [esi+4]
0045BFB9 [00423890] 8a 80 b0 31 0a 00                            mov     al, [eax+0A31B0h]
0045BFBF [00423896] c3                                           retn
