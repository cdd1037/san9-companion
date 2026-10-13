; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042B7BC; baseline game VA=0x000A9C30; size=64
; Relative branch annotations use the baseline game destination.
000A9C30 [0042B7BC] 8b f0                                        mov     esi, eax
000A9C32 [0042B7BE] 5b                                           pop     ebx
000A9C33 [0042B7BF] b8 e0 9c 51 00                               mov     eax, 519CE0h
000A9C38 [0042B7C4] ff d0                                        call    eax
000A9C3A [0042B7C6] 53                                           push    ebx
000A9C3B [0042B7C7] 8b cf                                        mov     ecx, edi
000A9C3D [0042B7C9] b8 00 9c 0a 00                               mov     eax, 0A9C00h
000A9C42 [0042B7CE] ff d0                                        call    eax
000A9C44 [0042B7D0] a3 28 9c 0a 00                               mov     ds:0A9C28h, eax
000A9C49 [0042B7D5] 85 c0                                        test    eax, eax
000A9C4B [0042B7D7] 75 01                                        jnz     short near ptr unk_42B7DA ; game-relative-target=0x000A9C4E
000A9C4D [0042B7D9] c3                                           retn
000A9C4E [0042B7DA] 8b 46 40                                     mov     eax, [esi+40h]
000A9C51 [0042B7DD] 2b 46 38                                     sub     eax, [esi+38h]
000A9C54 [0042B7E0] d1 f8                                        sar     eax, 1
000A9C56 [0042B7E2] 8b 56 44                                     mov     edx, [esi+44h]
000A9C59 [0042B7E5] 2b 56 3c                                     sub     edx, [esi+3Ch]
000A9C5C [0042B7E8] d1 fa                                        sar     edx, 1
000A9C5E [0042B7EA] c1 e2 10                                     shl     edx, 10h
000A9C61 [0042B7ED] 66 8b d0                                     mov     dx, ax
000A9C64 [0042B7F0] 8b 0d 00 08 b4 01                            mov     ecx, ds:1B40800h
000A9C6A [0042B7F6] 68 50 86 0a 00                               push    0A8650h
000A9C6F [0042B7FB] c3                                           retn
