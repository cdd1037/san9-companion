; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004239F8; baseline game VA=0x000A04E0; size=16
; Relative branch annotations use the baseline game destination.
000A04E0 [004239F8] 8b ce                                        mov     ecx, esi
000A04E2 [004239FA] 8b 01                                        mov     eax, [ecx]
000A04E4 [004239FC] ff 50 0c                                     call    dword ptr [eax+0Ch]
000A04E7 [004239FF] 0f b7 44 83 46                               movzx   eax, word ptr [ebx+eax*4+46h]
000A04EC [00423A04] c1 e0 04                                     shl     eax, 4
000A04EF [00423A07] c3                                           retn
