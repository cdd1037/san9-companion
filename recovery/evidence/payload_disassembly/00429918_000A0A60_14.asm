; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00429918; baseline game VA=0x000A0A60; size=20
; Relative branch annotations use the baseline game destination.
000A0A60 [00429918] 8b 46 0c                                     mov     eax, [esi+0Ch]
000A0A63 [0042991B] 83 f8 09                                     cmp     eax, 9
000A0A66 [0042991E] 74 06                                        jz      short near ptr unk_429926 ; game-relative-target=0x000A0A6E
000A0A68 [00429920] 68 30 7a 56 00                               push    567A30h
000A0A6D [00429925] c3                                           retn
000A0A6E [00429926] 68 b0 7a 56 00                               push    567AB0h
000A0A73 [0042992B] c3                                           retn
