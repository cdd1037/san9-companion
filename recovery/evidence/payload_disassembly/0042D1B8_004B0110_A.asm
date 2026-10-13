; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042D1B8; baseline game VA=0x004B0110; size=10
; Relative branch annotations use the baseline game destination.
004B0110 [0042D1B8] 0f b6 c0                                     movzx   eax, al
004B0113 [0042D1BB] c1 e6 08                                     shl     esi, 8
004B0116 [0042D1BE] 09 f0                                        or      eax, esi
004B0118 [0042D1C0] 5e                                           pop     esi
004B0119 [0042D1C1] c3                                           retn
