; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00426E80; baseline game VA=0x000A5D20; size=27
; Relative branch annotations use the baseline game destination.
000A5D20 [00426E80] 0f b7 41 04                                  movzx   eax, word ptr [ecx+4]
000A5D24 [00426E84] 69 c0 90 00 00 00                            imul    eax, 90h
000A5D2A [00426E8A] 05 e4 db 54 01                               add     eax, 154DBE4h
000A5D2F [00426E8F] 33 c9                                        xor     ecx, ecx
000A5D31 [00426E91] f6 40 20 01                                  test    byte ptr [eax+20h], 1
000A5D35 [00426E95] 0f 95 c1                                     setnz   cl
000A5D38 [00426E98] 8b c1                                        mov     eax, ecx
000A5D3A [00426E9A] c3                                           retn
