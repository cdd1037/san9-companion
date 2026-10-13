; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00423D60; baseline game VA=0x000A3060; size=42
; Relative branch annotations use the baseline game destination.
000A3060 [00423D60] 8b 89 00 01 00 00                            mov     ecx, [ecx+100h]
000A3066 [00423D66] 0b 0d f3 fa 43 00                            or      ecx, ds:43FAF3h
000A306C [00423D6C] 8b 44 24 04                                  mov     eax, [esp+4]
000A3070 [00423D70] 0f b7 14 45 a8 2f 0a 00                      movzx   edx, word ptr ds:0A2FA8h[eax*2]
000A3078 [00423D78] 23 ca                                        and     ecx, edx
000A307A [00423D7A] 85 c9                                        test    ecx, ecx
000A307C [00423D7C] 75 01                                        jnz     short near ptr unk_423D7F ; game-relative-target=0x000A307F
000A307E [00423D7E] c3                                           retn
000A307F [00423D7F] 33 c0                                        xor     eax, eax
000A3081 [00423D81] 48                                           dec     eax
000A3082 [00423D82] 40                                           inc     eax
000A3083 [00423D83] d1 e9                                        shr     ecx, 1
000A3085 [00423D85] 85 c9                                        test    ecx, ecx
000A3087 [00423D87] 75 f9                                        jnz     short near ptr unk_423D82 ; game-relative-target=0x000A3082
000A3089 [00423D89] c3                                           retn
