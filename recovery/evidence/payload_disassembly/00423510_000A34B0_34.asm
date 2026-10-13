; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00423510; baseline game VA=0x000A34B0; size=52
; Relative branch annotations use the baseline game destination.
000A34B0 [00423510] 8b d8                                        mov     ebx, eax
000A34B2 [00423512] b8 d0 53 43 00                               mov     eax, 4353D0h
000A34B7 [00423517] ff d0                                        call    eax
000A34B9 [00423519] 3c 00                                        cmp     al, 0
000A34BB [0042351B] 74 04                                        jz      short near ptr unk_423521 ; game-relative-target=0x000A34C1
000A34BD [0042351D] 3c 02                                        cmp     al, 2
000A34BF [0042351F] 75 05                                        jnz     short near ptr unk_423526 ; game-relative-target=0x000A34C6
000A34C1 [00423521] 8b eb                                        mov     ebp, ebx
000A34C3 [00423523] 33 c0                                        xor     eax, eax
000A34C5 [00423525] c3                                           retn
000A34C6 [00423526] 8b cf                                        mov     ecx, edi
000A34C8 [00423528] 8b 01                                        mov     eax, [ecx]
000A34CA [0042352A] ff 50 0c                                     call    dword ptr [eax+0Ch]
000A34CD [0042352D] f6 44 85 44 80                               test    byte ptr [ebp+eax*4+44h], 80h
000A34D2 [00423532] 8b eb                                        mov     ebp, ebx
000A34D4 [00423534] 75 01                                        jnz     short near ptr unk_423537 ; game-relative-target=0x000A34D7
000A34D6 [00423536] c3                                           retn
000A34D7 [00423537] bb 00 10 00 00                               mov     ebx, 1000h
000A34DC [0042353C] 68 12 4e 4b 00                               push    4B4E12h
000A34E1 [00423541] c2 04 00                                     retn    4
