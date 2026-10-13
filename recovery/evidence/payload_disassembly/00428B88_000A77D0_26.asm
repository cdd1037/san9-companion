; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00428B88; baseline game VA=0x000A77D0; size=38
; Relative branch annotations use the baseline game destination.
000A77D0 [00428B88] f6 41 72 08                                  test    byte ptr [ecx+72h], 8
000A77D4 [00428B8C] 74 06                                        jz      short near ptr unk_428B94 ; game-relative-target=0x000A77DC
000A77D6 [00428B8E] 80 7e 44 00                                  cmp     byte ptr [esi+44h], 0
000A77DA [00428B92] 74 06                                        jz      short near ptr unk_428B9A ; game-relative-target=0x000A77E2
000A77DC [00428B94] 68 10 e5 43 00                               push    43E510h
000A77E1 [00428B99] c3                                           retn
000A77E2 [00428B9A] c7 46 3c 6c 77 65 00                         mov     dword ptr [esi+3Ch], 65776Ch
000A77E9 [00428BA1] c6 46 40 07                                  mov     byte ptr [esi+40h], 7
000A77ED [00428BA5] c6 46 44 02                                  mov     byte ptr [esi+44h], 2
000A77F1 [00428BA9] c6 04 24 d7                                  mov     byte ptr [esp], 0D7h
000A77F5 [00428BAD] c3                                           retn
