; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00422A88; baseline game VA=0x000A0C40; size=20
; Relative branch annotations use the baseline game destination.
000A0C40 [00422A88] 83 79 30 00                                  cmp     dword ptr [ecx+30h], 0
000A0C44 [00422A8C] 74 06                                        jz      short near ptr unk_422A94 ; game-relative-target=0x000A0C4C
000A0C46 [00422A8E] 68 70 88 46 00                               push    468870h
000A0C4B [00422A93] c3                                           retn
000A0C4C [00422A94] b8 64 00 00 00                               mov     eax, 64h ; 'd'
000A0C51 [00422A99] c2 04 00                                     retn    4
