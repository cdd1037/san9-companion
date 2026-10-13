; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042C924; baseline game VA=0x0051FA13; size=7
; Relative branch annotations use the baseline game destination.
0051FA13 [0042C924] 83 c4 04                                     add     esp, 4
0051FA16 [0042C927] f6 40 35 04                                  test    byte ptr [eax+35h], 4
