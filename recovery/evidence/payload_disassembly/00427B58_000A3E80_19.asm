; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00427B58; baseline game VA=0x000A3E80; size=25
; Relative branch annotations use the baseline game destination.
000A3E80 [00427B58] 83 7c 24 20 ff                               cmp     dword ptr [esp+20h], 0FFFFFFFFh
000A3E85 [00427B5D] 75 01                                        jnz     short near ptr unk_427B60 ; game-relative-target=0x000A3E88
000A3E87 [00427B5F] c3                                           retn
000A3E88 [00427B60] 8b ce                                        mov     ecx, esi
000A3E8A [00427B62] b8 00 1b 0a 00                               mov     eax, 0A1B00h
000A3E8F [00427B67] ff d0                                        call    eax
000A3E91 [00427B69] f7 d8                                        neg     eax
000A3E93 [00427B6B] 1b c0                                        sbb     eax, eax
000A3E95 [00427B6D] 40                                           inc     eax
000A3E96 [00427B6E] 85 c0                                        test    eax, eax
000A3E98 [00427B70] c3                                           retn
