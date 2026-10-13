; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00424C24; baseline game VA=0x0049A068; size=7
; Relative branch annotations use the baseline game destination.
0049A068 [00424C24] 8b 4c 24 28                                  mov     ecx, [esp+28h]
0049A06C [00424C28] 8b 40 68                                     mov     eax, [eax+68h]
