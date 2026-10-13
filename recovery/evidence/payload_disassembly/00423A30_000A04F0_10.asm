; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00423A30; baseline game VA=0x000A04F0; size=16
; Relative branch annotations use the baseline game destination.
000A04F0 [00423A30] 8b cf                                        mov     ecx, edi
000A04F2 [00423A32] 8b 01                                        mov     eax, [ecx]
000A04F4 [00423A34] ff 50 0c                                     call    dword ptr [eax+0Ch]
000A04F7 [00423A37] 0f b7 44 85 46                               movzx   eax, word ptr [ebp+eax*4+46h]
000A04FC [00423A3C] c1 e0 04                                     shl     eax, 4
000A04FF [00423A3F] c3                                           retn
