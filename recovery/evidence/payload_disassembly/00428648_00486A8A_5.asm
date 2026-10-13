; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00428648; baseline game VA=0x00486A8A; size=5
; Relative branch annotations use the baseline game destination.
00486A8A [00428648] 8b ce                                        mov     ecx, esi
00486A8C [0042864A] ff 50 34                                     call    dword ptr [eax+34h]
