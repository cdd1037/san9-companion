; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042A158; baseline game VA=0x000A8320; size=52
; Relative branch annotations use the baseline game destination.
000A8320 [0042A158] a1 a6 82 0a 00                               mov     eax, ds:0A82A6h
000A8325 [0042A15D] 85 c0                                        test    eax, eax
000A8327 [0042A15F] 75 06                                        jnz     short near ptr unk_42A167 ; game-relative-target=0x000A832F
000A8329 [0042A161] 68 10 5a 48 00                               push    485A10h
000A832E [0042A166] c3                                           retn
000A832F [0042A167] 57                                           push    edi
000A8330 [0042A168] 8b 3d 04 05 0a 00                            mov     edi, ds:0A0504h
000A8336 [0042A16E] 8b 57 08                                     mov     edx, [edi+8]
000A8339 [0042A171] 89 56 40                                     mov     [esi+40h], edx
000A833C [0042A174] 8b ce                                        mov     ecx, esi
000A833E [0042A176] b8 10 5a 48 00                               mov     eax, 485A10h
000A8343 [0042A17B] ff d0                                        call    eax
000A8345 [0042A17D] 8b 3f                                        mov     edi, [edi]
000A8347 [0042A17F] 85 ff                                        test    edi, edi
000A8349 [0042A181] 75 eb                                        jnz     short near ptr unk_42A16E ; game-relative-target=0x000A8336
000A834B [0042A183] b8 90 82 0a 00                               mov     eax, 0A8290h
000A8350 [0042A188] ff d0                                        call    eax
000A8352 [0042A18A] 5f                                           pop     edi
000A8353 [0042A18B] c3                                           retn
