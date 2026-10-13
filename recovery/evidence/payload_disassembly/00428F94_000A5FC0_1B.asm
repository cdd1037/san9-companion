; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00428F94; baseline game VA=0x000A5FC0; size=27
; Relative branch annotations use the baseline game destination.
000A5FC0 [00428F94] f6 40 6c 01                                  test    byte ptr [eax+6Ch], 1
000A5FC4 [00428F98] 75 0f                                        jnz     short near ptr unk_428FA9 ; game-relative-target=0x000A5FD5
000A5FC6 [00428F9A] f6 40 70 01                                  test    byte ptr [eax+70h], 1
000A5FCA [00428F9E] 74 09                                        jz      short near ptr unk_428FA9 ; game-relative-target=0x000A5FD5
000A5FCC [00428FA0] 8b 00                                        mov     eax, [eax]
000A5FCE [00428FA2] c7 40 6c a0 0e 50 01                         mov     dword ptr [eax+6Ch], 1500EA0h
000A5FD5 [00428FA9] 68 80 9c 48 00                               push    489C80h
000A5FDA [00428FAE] c3                                           retn
