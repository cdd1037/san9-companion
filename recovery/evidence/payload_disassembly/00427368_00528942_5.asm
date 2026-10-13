; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00427368; baseline game VA=0x00528942; size=5
; Relative branch annotations use the baseline game destination.
00528942 [00427368] 8b cf                                        mov     ecx, edi
00528944 [0042736A] ff 50 18                                     call    dword ptr [eax+18h]
