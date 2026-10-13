; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004288D8; baseline game VA=0x0047FD23; size=8
; Relative branch annotations use the baseline game destination.
0047FD23 [004288D8] 8b 44 24 1c                                  mov     eax, [esp+1Ch]
0047FD27 [004288DC] 0f af c7                                     imul    eax, edi
0047FD2A [004288DF] 99                                           cdq
