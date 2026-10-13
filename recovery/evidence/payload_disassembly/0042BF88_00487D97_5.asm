; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042BF88; baseline game VA=0x00487D97; size=5
; Relative branch annotations use the baseline game destination.
00487D97 [0042BF88] 8b cf                                        mov     ecx, edi
00487D99 [0042BF8A] ff 50 14                                     call    dword ptr [eax+14h]
