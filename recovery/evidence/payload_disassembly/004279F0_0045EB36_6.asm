; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004279F0; baseline game VA=0x0045EB36; size=6
; Relative branch annotations use the baseline game destination.
0045EB36 [004279F0] ff 90 bc 00 00 00                            call    dword ptr [eax+0BCh]
