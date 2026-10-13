; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004229B0; baseline game VA=0x000A2630; size=16
; Relative branch annotations use the baseline game destination.
000A2630 [004229B0] 8b 4e 38                                     mov     ecx, [esi+38h]
000A2633 [004229B3] 8b 91 84 00 00 00                            mov     edx, [ecx+84h]
000A2639 [004229B9] 42                                           inc     edx
000A263A [004229BA] c1 e2 0a                                     shl     edx, 0Ah
000A263D [004229BD] 03 c2                                        add     eax, edx
000A263F [004229BF] c3                                           retn
