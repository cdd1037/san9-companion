; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00420514; baseline game VA=0x0044F093; size=9
; Relative branch annotations use the baseline game destination.
0044F093 [00420514] 8d 48 04                                     lea     ecx, [eax+4]
0044F096 [00420517] 8b c6                                        mov     eax, esi
0044F098 [00420519] 6b c0 04                                     imul    eax, 4
0044F09B [0042051C] c3                                           retn
