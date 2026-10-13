; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004243AC; baseline game VA=0x004BBBAE; size=50
; Relative branch annotations use the baseline game destination.
004BBBAE [004243AC] 83 c4 04                                     add     esp, 4
004BBBB1 [004243AF] 85 c0                                        test    eax, eax
004BBBB3 [004243B1] 74 15                                        jz      short near ptr unk_4243C8 ; game-relative-target=0x004BBBCA
004BBBB5 [004243B3] 8b ce                                        mov     ecx, esi
004BBBB7 [004243B5] e8 a4 ee f8 ff                               call    near ptr 3B325Eh ; game-relative-target=0x0044AA60
004BBBBC [004243BA] 85 c0                                        test    eax, eax
004BBBBE [004243BC] 75 0e                                        jnz     short near ptr unk_4243CC ; game-relative-target=0x004BBBCE
004BBBC0 [004243BE] 8b 86 e8 00 00 00                            mov     eax, [esi+0E8h]
004BBBC6 [004243C4] 85 c0                                        test    eax, eax
004BBBC8 [004243C6] 7f 04                                        jg      short near ptr unk_4243CC ; game-relative-target=0x004BBBCE
004BBBCA [004243C8] 33 c0                                        xor     eax, eax
004BBBCC [004243CA] 5e                                           pop     esi
004BBBCD [004243CB] c3                                           retn
004BBBCE [004243CC] b8 01 00 00 00                               mov     eax, 1
004BBBD3 [004243D1] 5e                                           pop     esi
004BBBD4 [004243D2] c3                                           retn
004BBBD5 [004243D3] 90                                           nop
004BBBD6 [004243D4] 90                                           nop
004BBBD7 [004243D5] 90                                           nop
004BBBD8 [004243D6] 90                                           nop
004BBBD9 [004243D7] 90                                           nop
004BBBDA [004243D8] 90                                           nop
004BBBDB [004243D9] 90                                           nop
004BBBDC [004243DA] 90                                           nop
004BBBDD [004243DB] 90                                           nop
004BBBDE [004243DC] 90                                           nop
004BBBDF [004243DD] 90                                           nop
