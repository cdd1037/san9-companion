; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004279CC; baseline game VA=0x000A1700; size=28
; Relative branch annotations use the baseline game destination.
000A1700 [004279CC] 8b 89 88 00 00 00                            mov     ecx, [ecx+88h]
000A1706 [004279D2] 85 c9                                        test    ecx, ecx
000A1708 [004279D4] 74 0f                                        jz      short near ptr unk_4279E5 ; game-relative-target=0x000A1719
000A170A [004279D6] 8b 51 08                                     mov     edx, [ecx+8]
000A170D [004279D9] 39 7a 68                                     cmp     [edx+68h], edi
000A1710 [004279DC] 7e 03                                        jle     short near ptr unk_4279E1 ; game-relative-target=0x000A1715
000A1712 [004279DE] 8b 7a 68                                     mov     edi, [edx+68h]
000A1715 [004279E1] 8b 09                                        mov     ecx, [ecx]
000A1717 [004279E3] eb ed                                        jmp     short near ptr unk_4279D2 ; game-relative-target=0x000A1706
000A1719 [004279E5] 33 c0                                        xor     eax, eax
000A171B [004279E7] c3                                           retn
