; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004288B0; baseline game VA=0x0047FD05; size=6
; Relative branch annotations use the baseline game destination.
0047FD05 [004288B0] 0f af 44 24 18                               imul    eax, [esp+18h]
0047FD0A [004288B5] 99                                           cdq
