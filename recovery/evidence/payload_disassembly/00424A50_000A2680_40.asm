; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00424A50; baseline game VA=0x000A2680; size=64
; Relative branch annotations use the baseline game destination.
000A2680 [00424A50] 0f b7 51 04                                  movzx   edx, word ptr [ecx+4]
000A2684 [00424A54] 81 fa 20 03 00 00                            cmp     edx, 320h
000A268A [00424A5A] 7c 06                                        jl      short near ptr unk_424A62 ; game-relative-target=0x000A2692
000A268C [00424A5C] 68 40 c9 44 00                               push    44C940h
000A2691 [00424A61] c3                                           retn
000A2692 [00424A62] 8b 14 95 00 40 0a 00                         mov     edx, ds:0A4000h[edx*4]
000A2699 [00424A69] 8b c8                                        mov     ecx, eax
000A269B [00424A6B] d1 e1                                        shl     ecx, 1
000A269D [00424A6D] d3 ea                                        shr     edx, cl
000A269F [00424A6F] 83 e2 03                                     and     edx, 3
000A26A2 [00424A72] 52                                           push    edx
000A26A3 [00424A73] 0f b6 46 04                                  movzx   eax, byte ptr [esi+4]
000A26A7 [00424A77] 3c 0f                                        cmp     al, 0Fh
000A26A9 [00424A79] 7d 04                                        jge     short near ptr unk_424A7F ; game-relative-target=0x000A26AF
000A26AB [00424A7B] b1 03                                        mov     cl, 3
000A26AD [00424A7D] eb 04                                        jmp     short near ptr unk_424A83 ; game-relative-target=0x000A26B3
000A26AF [00424A7F] 2c 0f                                        sub     al, 0Fh
000A26B1 [00424A81] b1 04                                        mov     cl, 4
000A26B3 [00424A83] 99                                           cdq
000A26B4 [00424A84] f7 f1                                        div     ecx
000A26B6 [00424A86] 58                                           pop     eax
000A26B7 [00424A87] 3a d0                                        cmp     dl, al
000A26B9 [00424A89] 8b cf                                        mov     ecx, edi
000A26BB [00424A8B] 7e cf                                        jle     short near ptr unk_424A5C ; game-relative-target=0x000A268C
000A26BD [00424A8D] c2 04 00                                     retn    4
