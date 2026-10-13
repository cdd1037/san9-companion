; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00424C74; baseline game VA=0x0049A487; size=6
; Relative branch annotations use the baseline game destination.
0049A487 [00424C74] 8b 45 64                                     mov     eax, [ebp+64h]
0049A48A [00424C77] 8d 14 00                                     lea     edx, [eax+eax]
