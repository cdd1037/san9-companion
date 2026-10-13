; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004239B8; baseline game VA=0x000A2FE8; size=22
; Relative branch annotations use the baseline game destination.
000A2FE8 [004239B8] 8b 4c 24 38                                  mov     ecx, [esp+38h]
000A2FEC [004239BC] 8b 01                                        mov     eax, [ecx]
000A2FEE [004239BE] ff 50 0c                                     call    dword ptr [eax+0Ch]
000A2FF1 [004239C1] 8b d3                                        mov     edx, ebx
000A2FF3 [004239C3] c1 ea 04                                     shr     edx, 4
000A2FF6 [004239C6] 66 89 54 85 46                               mov     [ebp+eax*4+46h], dx
000A2FFB [004239CB] 8b c3                                        mov     eax, ebx
000A2FFD [004239CD] c3                                           retn
