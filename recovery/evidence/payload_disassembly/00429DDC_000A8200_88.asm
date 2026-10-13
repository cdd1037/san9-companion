; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00429DDC; baseline game VA=0x000A8200; size=136
; Relative branch annotations use the baseline game destination.
000A8200 [00429DDC] 56                                           push    esi
000A8201 [00429DDD] 57                                           push    edi
000A8202 [00429DDE] 55                                           push    ebp
000A8203 [00429DDF] 53                                           push    ebx
000A8204 [00429DE0] 8b 74 24 18                                  mov     esi, [esp+18h]
000A8208 [00429DE4] bf 00 05 0a 00                               mov     edi, 0A0500h
000A820D [00429DE9] 8b 5c 24 14                                  mov     ebx, [esp+14h]
000A8211 [00429DED] 8b 6e 0c                                     mov     ebp, [esi+0Ch]
000A8214 [00429DF0] 6a 00                                        push    0
000A8216 [00429DF2] 68 e0 81 0a 00                               push    0A81E0h
000A821B [00429DF7] 8b ce                                        mov     ecx, esi
000A821D [00429DF9] b8 10 f6 46 00                               mov     eax, 46F610h
000A8222 [00429DFE] ff d0                                        call    eax
000A8224 [00429E00] 8b 44 24 10                                  mov     eax, [esp+10h]
000A8228 [00429E04] 3d b0 fc 4d 00                               cmp     eax, 4DFCB0h
000A822D [00429E09] 75 24                                        jnz     short near ptr unk_429E2F ; game-relative-target=0x000A8253
000A822F [00429E0B] 8b 0d 74 24 23 01                            mov     ecx, ds:1232474h
000A8235 [00429E11] 8b 81 88 00 00 00                            mov     eax, [ecx+88h]
000A823B [00429E17] 99                                           cdq
000A823C [00429E18] b9 b8 0b 00 00                               mov     ecx, 0BB8h
000A8241 [00429E1D] f7 f1                                        div     ecx
000A8243 [00429E1F] 3b c5                                        cmp     eax, ebp
000A8245 [00429E21] 7d 0c                                        jge     short near ptr unk_429E2F ; game-relative-target=0x000A8253
000A8247 [00429E23] 8b e8                                        mov     ebp, eax
000A8249 [00429E25] 55                                           push    ebp
000A824A [00429E26] 8b cf                                        mov     ecx, edi
000A824C [00429E28] b8 b0 ee 46 00                               mov     eax, 46EEB0h
000A8251 [00429E2D] ff d0                                        call    eax
000A8253 [00429E2F] 8b 44 24 20                                  mov     eax, [esp+20h]
000A8257 [00429E33] 8b 54 24 1c                                  mov     edx, [esp+1Ch]
000A825B [00429E37] 6a 00                                        push    0
000A825D [00429E39] 6a 01                                        push    1
000A825F [00429E3B] 50                                           push    eax
000A8260 [00429E3C] 52                                           push    edx
000A8261 [00429E3D] 55                                           push    ebp
000A8262 [00429E3E] 56                                           push    esi
000A8263 [00429E3F] 57                                           push    edi
000A8264 [00429E40] b8 00 05 57 00                               mov     eax, 570500h
000A8269 [00429E45] ff d0                                        call    eax
000A826B [00429E47] 83 c4 1c                                     add     esp, 1Ch
000A826E [00429E4A] 85 c0                                        test    eax, eax
000A8270 [00429E4C] 8b 57 0c                                     mov     edx, [edi+0Ch]
000A8273 [00429E4F] 89 15 a6 82 0a 00                            mov     ds:0A82A6h, edx
000A8279 [00429E55] 74 08                                        jz      short near ptr unk_429E5F ; game-relative-target=0x000A8283
000A827B [00429E57] 8b 4f 04                                     mov     ecx, [edi+4]
000A827E [00429E5A] 8b 41 08                                     mov     eax, [ecx+8]
000A8281 [00429E5D] 89 03                                        mov     [ebx], eax
000A8283 [00429E5F] 5b                                           pop     ebx
000A8284 [00429E60] 5d                                           pop     ebp
000A8285 [00429E61] 5f                                           pop     edi
000A8286 [00429E62] 5e                                           pop     esi
000A8287 [00429E63] c3                                           retn
