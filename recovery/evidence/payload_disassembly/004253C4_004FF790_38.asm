; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004253C4; baseline game VA=0x004FF790; size=56
; Relative branch annotations use the baseline game destination.
004FF790 [004253C4] 33 f6                                        xor     esi, esi
004FF792 [004253C6] b9 40 07 61 00                               mov     ecx, 610740h
004FF797 [004253CB] 66 8b 47 04                                  mov     ax, [edi+4]
004FF79B [004253CF] 66 8b 53 04                                  mov     dx, [ebx+4]
004FF79F [004253D3] 66 3b 01                                     cmp     ax, [ecx]
004FF7A2 [004253D6] 75 06                                        jnz     short near ptr unk_4253DE ; game-relative-target=0x004FF7AA
004FF7A4 [004253D8] 66 3b 51 02                                  cmp     dx, [ecx+2]
004FF7A8 [004253DC] 74 16                                        jz      short near ptr unk_4253F4 ; game-relative-target=0x004FF7C0
004FF7AA [004253DE] 66 3b 11                                     cmp     dx, [ecx]
004FF7AD [004253E1] 75 06                                        jnz     short near ptr unk_4253E9 ; game-relative-target=0x004FF7B5
004FF7AF [004253E3] 66 3b 41 02                                  cmp     ax, [ecx+2]
004FF7B3 [004253E7] 74 0b                                        jz      short near ptr unk_4253F4 ; game-relative-target=0x004FF7C0
004FF7B5 [004253E9] 83 c1 06                                     add     ecx, 6
004FF7B8 [004253EC] 46                                           inc     esi
004FF7B9 [004253ED] 83 fe 74                                     cmp     esi, 74h ; 't'
004FF7BC [004253F0] 7c e1                                        jl      short near ptr unk_4253D3 ; game-relative-target=0x004FF79F
004FF7BE [004253F2] eb 13                                        jmp     short near ptr unk_425407 ; game-relative-target=0x004FF7D3
004FF7C0 [004253F4] 0f b6 69 04                                  movzx   ebp, byte ptr [ecx+4]
004FF7C4 [004253F8] 5e                                           pop     esi
004FF7C5 [004253F9] 5b                                           pop     ebx
004FF7C6 [004253FA] eb 59                                        jmp     short near ptr off_425454+1 ; game-relative-target=0x004FF821
