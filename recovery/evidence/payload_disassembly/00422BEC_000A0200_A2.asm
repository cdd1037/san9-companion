; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00422BEC; baseline game VA=0x000A0200; size=162
; Relative branch annotations use the baseline game destination.
000A0200 [00422BEC] 56                                           push    esi
000A0201 [00422BED] 53                                           push    ebx
000A0202 [00422BEE] 33 db                                        xor     ebx, ebx
000A0204 [00422BF0] be b0 93 4b 01                               mov     esi, 14B93B0h
000A0209 [00422BF5] 8a 46 56                                     mov     al, [esi+56h]
000A020C [00422BF8] 3c ff                                        cmp     al, 0FFh
000A020E [00422BFA] 74 26                                        jz      short near ptr unk_422C22 ; game-relative-target=0x000A0236
000A0210 [00422BFC] 3c 03                                        cmp     al, 3
000A0212 [00422BFE] 75 62                                        jnz     short near ptr unk_422C62 ; game-relative-target=0x000A0276
000A0214 [00422C00] 0f b7 46 54                                  movzx   eax, word ptr [esi+54h]
000A0218 [00422C04] 69 c0 04 01 00 00                            imul    eax, 104h
000A021E [00422C0A] 05 b0 93 4b 01                               add     eax, 14B93B0h
000A0223 [00422C0F] 50                                           push    eax
000A0224 [00422C10] b9 20 05 0a 00                               mov     ecx, 0A0520h
000A0229 [00422C15] b8 60 eb 46 00                               mov     eax, 46EB60h
000A022E [00422C1A] ff d0                                        call    eax
000A0230 [00422C1C] 85 c0                                        test    eax, eax
000A0232 [00422C1E] 75 3f                                        jnz     short near ptr unk_422C5F ; game-relative-target=0x000A0273
000A0234 [00422C20] eb 40                                        jmp     short near ptr unk_422C62 ; game-relative-target=0x000A0276
000A0236 [00422C22] 80 7e 58 26                                  cmp     byte ptr [esi+58h], 26h ; '&'
000A023A [00422C26] 75 3a                                        jnz     short near ptr unk_422C62 ; game-relative-target=0x000A0276
000A023C [00422C28] 80 7e 52 03                                  cmp     byte ptr [esi+52h], 3
000A0240 [00422C2C] 75 34                                        jnz     short near ptr unk_422C62 ; game-relative-target=0x000A0276
000A0242 [00422C2E] 0f b7 46 50                                  movzx   eax, word ptr [esi+50h]
000A0246 [00422C32] 69 c0 04 01 00 00                            imul    eax, 104h
000A024C [00422C38] 05 b0 93 4b 01                               add     eax, 14B93B0h
000A0251 [00422C3D] 50                                           push    eax
000A0252 [00422C3E] 50                                           push    eax
000A0253 [00422C3F] b9 20 05 0a 00                               mov     ecx, 0A0520h
000A0258 [00422C44] b8 60 eb 46 00                               mov     eax, 46EB60h
000A025D [00422C49] ff d0                                        call    eax
000A025F [00422C4B] 85 c0                                        test    eax, eax
000A0261 [00422C4D] 59                                           pop     ecx
000A0262 [00422C4E] 74 12                                        jz      short near ptr unk_422C62 ; game-relative-target=0x000A0276
000A0264 [00422C50] 56                                           push    esi
000A0265 [00422C51] b8 80 0a 0a 00                               mov     eax, 0A0A80h
000A026A [00422C56] ff d0                                        call    eax
000A026C [00422C58] 3d 32 00 00 00                               cmp     eax, 32h ; '2'
000A0271 [00422C5D] 7f 03                                        jg      short near ptr unk_422C62 ; game-relative-target=0x000A0276
000A0273 [00422C5F] 03 5e 30                                     add     ebx, [esi+30h]
000A0276 [00422C62] 81 c6 04 01 00 00                            add     esi, 104h
000A027C [00422C68] 66 81 7e 04 51 03                            cmp     word ptr [esi+4], 351h
000A0282 [00422C6E] 7c 85                                        jl      short near ptr unk_422BF5 ; game-relative-target=0x000A0209
000A0284 [00422C70] 8b c3                                        mov     eax, ebx
000A0286 [00422C72] 5b                                           pop     ebx
000A0287 [00422C73] 5e                                           pop     esi
000A0288 [00422C74] 8b 4c 24 04                                  mov     ecx, [esp+4]
000A028C [00422C78] 50                                           push    eax
000A028D [00422C79] 51                                           push    ecx
000A028E [00422C7A] b8 90 19 0a 00                               mov     eax, 0A1990h
000A0293 [00422C7F] ff d0                                        call    eax
000A0295 [00422C81] 59                                           pop     ecx
000A0296 [00422C82] 5a                                           pop     edx
000A0297 [00422C83] 03 c2                                        add     eax, edx
000A0299 [00422C85] 03 81 88 00 00 00                            add     eax, [ecx+88h]
000A029F [00422C8B] c2 04 00                                     retn    4
