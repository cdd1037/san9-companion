; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00426AE8; baseline game VA=0x000A5380; size=48
; Relative branch annotations use the baseline game destination.
000A5380 [00426AE8] 8a 98 e0 1a 0a 00                            mov     bl, [eax+0A1AE0h]
000A5386 [00426AEE] 83 e8 08                                     sub     eax, 8
000A5389 [00426AF1] 83 f8 12                                     cmp     eax, 12h
000A538C [00426AF4] 77 0e                                        ja      short near ptr unk_426B04 ; game-relative-target=0x000A539C
000A538E [00426AF6] 8a 80 74 31 46 00                            mov     al, [eax+463174h]
000A5394 [00426AFC] 3c 03                                        cmp     al, 3
000A5396 [00426AFE] 74 0b                                        jz      short near ptr unk_426B0B ; game-relative-target=0x000A53A3
000A5398 [00426B00] 3c 02                                        cmp     al, 2
000A539A [00426B02] 74 0c                                        jz      short near ptr unk_426B10 ; game-relative-target=0x000A53A8
000A539C [00426B04] c6 44 24 14 01                               mov     byte ptr [esp+14h], 1
000A53A1 [00426B09] eb 05                                        jmp     short near ptr unk_426B10 ; game-relative-target=0x000A53A8
000A53A3 [00426B0B] c6 44 24 18 01                               mov     byte ptr [esp+18h], 1
000A53A8 [00426B10] 68 7c 30 46 00                               push    46307Ch
000A53AD [00426B15] c2 04 00                                     retn    4
