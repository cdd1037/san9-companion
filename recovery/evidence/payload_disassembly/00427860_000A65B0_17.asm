; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00427860; baseline game VA=0x000A65B0; size=23
; Relative branch annotations use the baseline game destination.
000A65B0 [00427860] 8b 4e 30                                     mov     ecx, [esi+30h]
000A65B3 [00427863] 8b 81 f8 00 00 00                            mov     eax, [ecx+0F8h]
000A65B9 [00427869] 80 78 54 07                                  cmp     byte ptr [eax+54h], 7
000A65BD [0042786D] 7c 07                                        jl      short near ptr unk_427876 ; game-relative-target=0x000A65C6
000A65BF [0042786F] c6 86 b8 00 00 00 01                         mov     byte ptr [esi+0B8h], 1
000A65C6 [00427876] c3                                           retn
