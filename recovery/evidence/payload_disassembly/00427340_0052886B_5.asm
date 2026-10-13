; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00427340; baseline game VA=0x0052886B; size=5
; Relative branch annotations use the baseline game destination.
0052886B [00427340] 8b cf                                        mov     ecx, edi
0052886D [00427342] ff 52 18                                     call    dword ptr [edx+18h]
