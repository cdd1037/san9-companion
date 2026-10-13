; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00425760; baseline game VA=0x000A53D0; size=43
; Relative branch annotations use the baseline game destination.
000A53D0 [00425760] 8b 44 24 04                                  mov     eax, [esp+4]
000A53D4 [00425764] 56                                           push    esi
000A53D5 [00425765] 8b 30                                        mov     esi, [eax]
000A53D7 [00425767] 8b ce                                        mov     ecx, esi
000A53D9 [00425769] b8 c0 55 0a 00                               mov     eax, 0A55C0h
000A53DE [0042576E] ff d0                                        call    eax
000A53E0 [00425770] 33 d2                                        xor     edx, edx
000A53E2 [00425772] 3c 01                                        cmp     al, 1
000A53E4 [00425774] 74 01                                        jz      short near ptr unk_425777 ; game-relative-target=0x000A53E7
000A53E6 [00425776] 42                                           inc     edx
000A53E7 [00425777] 89 56 08                                     mov     [esi+8], edx
000A53EA [0042577A] 33 c0                                        xor     eax, eax
000A53EC [0042577C] 85 d2                                        test    edx, edx
000A53EE [0042577E] 75 09                                        jnz     short near ptr unk_425789 ; game-relative-target=0x000A53F9
000A53F0 [00425780] 0f b6 46 04                                  movzx   eax, byte ptr [esi+4]
000A53F4 [00425784] 83 e8 4d                                     sub     eax, 4Dh ; 'M'
000A53F7 [00425787] f7 d8                                        neg     eax
000A53F9 [00425789] 5e                                           pop     esi
000A53FA [0042578A] c3                                           retn
