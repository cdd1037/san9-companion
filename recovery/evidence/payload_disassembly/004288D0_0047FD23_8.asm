; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004288D0; baseline game VA=0x0047FD23; size=8
; Relative branch annotations use the baseline game destination.
0047FD23 [004288D0] 8b c7                                        mov     eax, edi
0047FD25 [004288D2] 99                                           cdq
0047FD26 [004288D3] 0f af 44 24 1c                               imul    eax, [esp+1Ch]
