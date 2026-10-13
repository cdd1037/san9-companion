; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00425F88; baseline game VA=0x000A6960; size=140
; Relative branch annotations use the baseline game destination.
000A6960 [00425F88] 8b 2f                                        mov     ebp, [edi]
000A6962 [00425F8A] 8b cb                                        mov     ecx, ebx
000A6964 [00425F8C] f6 c1 01                                     test    cl, 1
000A6967 [00425F8F] 75 7f                                        jnz     short near ptr unk_426010 ; game-relative-target=0x000A69E8
000A6969 [00425F91] d0 e9                                        shr     cl, 1
000A696B [00425F93] 80 f9 31                                     cmp     cl, 31h ; '1'
000A696E [00425F96] 7c 78                                        jl      short near ptr unk_426010 ; game-relative-target=0x000A69E8
000A6970 [00425F98] 80 f9 39                                     cmp     cl, 39h ; '9'
000A6973 [00425F9B] 7f 73                                        jg      short near ptr unk_426010 ; game-relative-target=0x000A69E8
000A6975 [00425F9D] 80 7c 24 2c 38                               cmp     byte ptr [esp+2Ch], 38h ; '8'
000A697A [00425FA2] 75 6c                                        jnz     short near ptr unk_426010 ; game-relative-target=0x000A69E8
000A697C [00425FA4] 80 44 24 5c 04                               add     byte ptr [esp+5Ch], 4
000A6981 [00425FA9] bf 20 20 20 20                               mov     edi, 20202020h
000A6986 [00425FAE] 80 e9 2e                                     sub     cl, 2Eh ; '.'
000A6989 [00425FB1] 8b 86 e8 00 00 00                            mov     eax, [esi+0E8h]
000A698F [00425FB7] d3 e8                                        shr     eax, cl
000A6991 [00425FB9] 24 01                                        and     al, 1
000A6993 [00425FBB] 74 05                                        jz      short near ptr unk_425FC2 ; game-relative-target=0x000A699A
000A6995 [00425FBD] bf a1 b8 20 20                               mov     edi, 2020B8A1h
000A699A [00425FC2] 80 e9 03                                     sub     cl, 3
000A699D [00425FC5] 80 f9 04                                     cmp     cl, 4
000A69A0 [00425FC8] 7f 21                                        jg      short near ptr unk_425FEB ; game-relative-target=0x000A69C3
000A69A2 [00425FCA] 0f b7 46 04                                  movzx   eax, word ptr [esi+4]
000A69A6 [00425FCE] 3d 20 03 00 00                               cmp     eax, 320h
000A69AB [00425FD3] 7d 16                                        jge     short near ptr unk_425FEB ; game-relative-target=0x000A69C3
000A69AD [00425FD5] 8b 04 85 00 40 0a 00                         mov     eax, ds:0A4000h[eax*4]
000A69B4 [00425FDC] d0 e1                                        shl     cl, 1
000A69B6 [00425FDE] d3 e8                                        shr     eax, cl
000A69B8 [00425FE0] 24 03                                        and     al, 3
000A69BA [00425FE2] 3c 03                                        cmp     al, 3
000A69BC [00425FE4] 75 05                                        jnz     short near ptr unk_425FEB ; game-relative-target=0x000A69C3
000A69BE [00425FE6] bf a1 b7 20 20                               mov     edi, 2020B7A1h
000A69C3 [00425FEB] 8b 45 00                                     mov     eax, [ebp+0]
000A69C6 [00425FEE] 89 7d 00                                     mov     [ebp+0], edi
000A69C9 [00425FF1] 8b 4d f8                                     mov     ecx, [ebp-8]
000A69CC [00425FF4] 83 e9 04                                     sub     ecx, 4
000A69CF [00425FF7] f7 d9                                        neg     ecx
000A69D1 [00425FF9] 85 c9                                        test    ecx, ecx
000A69D3 [00425FFB] 7e 08                                        jle     short near ptr unk_426005 ; game-relative-target=0x000A69DD
000A69D5 [00425FFD] c1 e0 08                                     shl     eax, 8
000A69D8 [00426000] b0 20                                        mov     al, 20h ; ' '
000A69DA [00426002] 49                                           dec     ecx
000A69DB [00426003] eb f4                                        jmp     short near ptr unk_425FF9 ; game-relative-target=0x000A69D1
000A69DD [00426005] 89 45 04                                     mov     [ebp+4], eax
000A69E0 [00426008] c6 45 08 00                                  mov     byte ptr [ebp+8], 0
000A69E4 [0042600C] c6 45 f8 08                                  mov     byte ptr [ebp-8], 8
000A69E8 [00426010] 8b 45 f8                                     mov     eax, [ebp-8]
000A69EB [00426013] c3                                           retn
