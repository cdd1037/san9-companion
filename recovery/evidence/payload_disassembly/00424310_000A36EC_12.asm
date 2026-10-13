; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00424310; baseline game VA=0x000A36EC; size=18
; Relative branch annotations use the baseline game destination.
000A36EC [00424310] 8b 85 68 08 00 00                            mov     eax, [ebp+868h]
000A36F2 [00424316] 8b 4d 38                                     mov     ecx, [ebp+38h]
000A36F5 [00424319] f6 41 34 04                                  test    byte ptr [ecx+34h], 4
000A36F9 [0042431D] 74 02                                        jz      short near ptr unk_424321 ; game-relative-target=0x000A36FD
000A36FB [0042431F] 33 c0                                        xor     eax, eax
000A36FD [00424321] c3                                           retn
