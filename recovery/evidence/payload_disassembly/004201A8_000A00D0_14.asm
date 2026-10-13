; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004201A8; baseline game VA=0x000A00D0; size=20
; Relative branch annotations use the baseline game destination.
000A00D0 [004201A8] 33 c0                                        xor     eax, eax
000A00D2 [004201AA] 89 41 7c                                     mov     [ecx+7Ch], eax
000A00D5 [004201AD] b0 34                                        mov     al, 34h ; '4'
000A00D7 [004201AF] 89 41 58                                     mov     [ecx+58h], eax
000A00DA [004201B2] 8b 41 64                                     mov     eax, [ecx+64h]
000A00DD [004201B5] 8b 50 04                                     mov     edx, [eax+4]
000A00E0 [004201B8] 89 51 50                                     mov     [ecx+50h], edx
000A00E3 [004201BB] c3                                           retn
