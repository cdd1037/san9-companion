; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004253FC; baseline game VA=0x000A36B8; size=52
; Relative branch annotations use the baseline game destination.
000A36B8 [004253FC] f6 46 20 01                                  test    byte ptr [esi+20h], 1
000A36BC [00425400] 74 0c                                        jz      short near ptr unk_42540E ; game-relative-target=0x000A36CA
000A36BE [00425402] 8b 4e 64                                     mov     ecx, [esi+64h]
000A36C1 [00425405] e8 0a 00 00 00                               call    near ptr unk_425414 ; game-relative-target=0x000A36D0
000A36C6 [0042540A] 89 44 24 0c                                  mov     [esp+0Ch], eax
000A36CA [0042540E] ff 25 0c f3 5f 00                            jmp     dword ptr ds:5FF30Ch
000A36D0 [00425414] b8 c0 61 43 00                               mov     eax, 4361C0h
000A36D5 [00425419] ff d0                                        call    eax
000A36D7 [0042541B] 6b c8 08                                     imul    ecx, eax, 8
000A36DA [0042541E] b8 67 66 66 66                               mov     eax, 66666667h
000A36DF [00425423] f7 e9                                        imul    ecx
000A36E1 [00425425] c1 fa 02                                     sar     edx, 2
000A36E4 [00425428] 8b c2                                        mov     eax, edx
000A36E6 [0042542A] c1 e8 1f                                     shr     eax, 1Fh
000A36E9 [0042542D] 03 c2                                        add     eax, edx
000A36EB [0042542F] c3                                           retn
