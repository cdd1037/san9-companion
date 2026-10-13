; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00424C98; baseline game VA=0x000A30E8; size=22
; Relative branch annotations use the baseline game destination.
000A30E8 [00424C98] 83 fa 0b                                     cmp     edx, 0Bh
000A30EB [00424C9B] 7e 0e                                        jle     short near ptr unk_424CAB ; game-relative-target=0x000A30FB
000A30ED [00424C9D] 83 fa 1f                                     cmp     edx, 1Fh
000A30F0 [00424CA0] 7d 06                                        jge     short near ptr unk_424CA8 ; game-relative-target=0x000A30F8
000A30F2 [00424CA2] 83 c0 11                                     add     eax, 11h
000A30F5 [00424CA5] 8b f0                                        mov     esi, eax
000A30F7 [00424CA7] c3                                           retn
000A30F8 [00424CA8] 83 ea 13                                     sub     edx, 13h
000A30FB [00424CAB] 8b f2                                        mov     esi, edx
000A30FD [00424CAD] c3                                           retn
