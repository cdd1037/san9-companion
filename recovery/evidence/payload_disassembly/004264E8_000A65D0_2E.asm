; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004264E8; baseline game VA=0x000A65D0; size=46
; Relative branch annotations use the baseline game destination.
000A65D0 [004264E8] 50                                           push    eax
000A65D1 [004264E9] 8b 43 3c                                     mov     eax, [ebx+3Ch]
000A65D4 [004264EC] f6 40 20 01                                  test    byte ptr [eax+20h], 1
000A65D8 [004264F0] 75 17                                        jnz     short near ptr unk_426509 ; game-relative-target=0x000A65F1
000A65DA [004264F2] 8b 96 f8 00 00 00                            mov     edx, [esi+0F8h]
000A65E0 [004264F8] 8a 43 34                                     mov     al, [ebx+34h]
000A65E3 [004264FB] 3c 1f                                        cmp     al, 1Fh
000A65E5 [004264FD] 7c 0e                                        jl      short near ptr unk_42650D ; game-relative-target=0x000A65F5
000A65E7 [004264FF] 3c 22                                        cmp     al, 22h ; '"'
000A65E9 [00426501] 7e 0f                                        jle     short near ptr unk_426512 ; game-relative-target=0x000A65FA
000A65EB [00426503] 80 7a 04 18                                  cmp     byte ptr [edx+4], 18h
000A65EF [00426507] 74 09                                        jz      short near ptr unk_426512 ; game-relative-target=0x000A65FA
000A65F1 [00426509] b1 02                                        mov     cl, 2
000A65F3 [0042650B] 58                                           pop     eax
000A65F4 [0042650C] c3                                           retn
000A65F5 [0042650D] 38 42 04                                     cmp     [edx+4], al
000A65F8 [00426510] 75 f7                                        jnz     short near ptr unk_426509 ; game-relative-target=0x000A65F1
000A65FA [00426512] b1 01                                        mov     cl, 1
000A65FC [00426514] 58                                           pop     eax
000A65FD [00426515] c3                                           retn
