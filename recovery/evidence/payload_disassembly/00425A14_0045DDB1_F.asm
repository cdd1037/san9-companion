; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00425A14; baseline game VA=0x0045DDB1; size=15
; Relative branch annotations use the baseline game destination.
0045DDB1 [00425A14] 0f b6 41 04                                  movzx   eax, byte ptr [ecx+4]
0045DDB5 [00425A18] 0f b6 80 30 56 0a 00                         movzx   eax, byte ptr [eax+0A5630h]
0045DDBC [00425A1F] 6b c0 64                                     imul    eax, 64h ; 'd'
0045DDBF [00425A22] c3                                           retn
