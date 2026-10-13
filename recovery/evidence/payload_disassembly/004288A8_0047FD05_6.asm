; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004288A8; baseline game VA=0x0047FD05; size=6
; Relative branch annotations use the baseline game destination.
0047FD05 [004288A8] 99                                           cdq
0047FD06 [004288A9] 0f af 44 24 18                               imul    eax, [esp+18h]
