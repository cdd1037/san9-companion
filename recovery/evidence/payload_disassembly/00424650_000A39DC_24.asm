; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00424650; baseline game VA=0x000A39DC; size=36
; Relative branch annotations use the baseline game destination.
000A39DC [00424650] 80 79 54 04                                  cmp     byte ptr [ecx+54h], 4
000A39E0 [00424654] 74 18                                        jz      short near ptr unk_42466E ; game-relative-target=0x000A39FA
000A39E2 [00424656] 8b 45 3c                                     mov     eax, [ebp+3Ch]
000A39E5 [00424659] f6 40 20 01                                  test    byte ptr [eax+20h], 1
000A39E9 [0042465D] 75 0f                                        jnz     short near ptr unk_42466E ; game-relative-target=0x000A39FA
000A39EB [0042465F] 8b 8f f8 00 00 00                            mov     ecx, [edi+0F8h]
000A39F1 [00424665] 83 79 54 06                                  cmp     dword ptr [ecx+54h], 6
000A39F5 [00424669] 7d 03                                        jge     short near ptr unk_42466E ; game-relative-target=0x000A39FA
000A39F7 [0042466B] 8b 59 64                                     mov     ebx, [ecx+64h]
000A39FA [0042466E] 68 00 d3 41 00                               push    41D300h
000A39FF [00424673] c3                                           retn
