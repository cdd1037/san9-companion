; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00428BD8; baseline game VA=0x000A7840; size=188
; Relative branch annotations use the baseline game destination.
000A7840 [00428BD8] 56                                           push    esi
000A7841 [00428BD9] 57                                           push    edi
000A7842 [00428BDA] 53                                           push    ebx
000A7843 [00428BDB] 55                                           push    ebp
000A7844 [00428BDC] 80 3d 19 ff 43 00 00                         cmp     byte ptr ds:43FF19h, 0
000A784B [00428BE3] 74 4b                                        jz      short near ptr unk_428C30 ; game-relative-target=0x000A7898
000A784D [00428BE5] 33 ff                                        xor     edi, edi
000A784F [00428BE7] be 38 3c 25 01                               mov     esi, 1253C38h
000A7854 [00428BEC] f6 46 34 01                                  test    byte ptr [esi+34h], 1
000A7858 [00428BF0] 74 32                                        jz      short near ptr unk_428C24 ; game-relative-target=0x000A788C
000A785A [00428BF2] 8b ce                                        mov     ecx, esi
000A785C [00428BF4] b8 e0 f3 43 00                               mov     eax, 43F3E0h
000A7861 [00428BF9] ff d0                                        call    eax
000A7863 [00428BFB] 83 f8 02                                     cmp     eax, 2
000A7866 [00428BFE] 7c 24                                        jl      short near ptr unk_428C24 ; game-relative-target=0x000A788C
000A7868 [00428C00] 48                                           dec     eax
000A7869 [00428C01] 0f b6 15 19 ff 43 00                         movzx   edx, byte ptr ds:43FF19h
000A7870 [00428C08] f7 ea                                        imul    edx
000A7872 [00428C0A] 6b d8 05                                     imul    ebx, eax, 5
000A7875 [00428C0D] ff 15 dc f2 5f 00                            call    dword ptr ds:5FF2DCh
000A787B [00428C13] 33 d2                                        xor     edx, edx
000A787D [00428C15] b9 64 00 00 00                               mov     ecx, 64h ; 'd'
000A7882 [00428C1A] f7 f9                                        idiv    ecx
000A7884 [00428C1C] 3b d3                                        cmp     edx, ebx
000A7886 [00428C1E] 7d 04                                        jge     short near ptr unk_428C24 ; game-relative-target=0x000A788C
000A7888 [00428C20] 8b c6                                        mov     eax, esi
000A788A [00428C22] eb 6b                                        jmp     short near ptr unk_428C8F ; game-relative-target=0x000A78F7
000A788C [00428C24] 81 c6 d4 00 00 00                            add     esi, 0D4h
000A7892 [00428C2A] 47                                           inc     edi
000A7893 [00428C2B] 83 ff 32                                     cmp     edi, 32h ; '2'
000A7896 [00428C2E] 7c bc                                        jl      short near ptr unk_428BEC ; game-relative-target=0x000A7854
000A7898 [00428C30] 33 ff                                        xor     edi, edi
000A789A [00428C32] be 38 3c 25 01                               mov     esi, 1253C38h
000A789F [00428C37] 33 db                                        xor     ebx, ebx
000A78A1 [00428C39] 33 ed                                        xor     ebp, ebp
000A78A3 [00428C3B] 83 be bc 00 00 00 00                         cmp     dword ptr [esi+0BCh], 0
000A78AA [00428C42] 74 3d                                        jz      short near ptr unk_428C81 ; game-relative-target=0x000A78E9
000A78AC [00428C44] 39 b6 b8 00 00 00                            cmp     [esi+0B8h], esi
000A78B2 [00428C4A] 75 35                                        jnz     short near ptr unk_428C81 ; game-relative-target=0x000A78E9
000A78B4 [00428C4C] f6 46 34 04                                  test    byte ptr [esi+34h], 4
000A78B8 [00428C50] 75 2f                                        jnz     short near ptr unk_428C81 ; game-relative-target=0x000A78E9
000A78BA [00428C52] 8b ce                                        mov     ecx, esi
000A78BC [00428C54] b8 b0 4e 0a 00                               mov     eax, 0A4EB0h
000A78C1 [00428C59] ff d0                                        call    eax
000A78C3 [00428C5B] 3d e0 93 04 00                               cmp     eax, 493E0h
000A78C8 [00428C60] 7e 1f                                        jle     short near ptr unk_428C81 ; game-relative-target=0x000A78E9
000A78CA [00428C62] 8b ce                                        mov     ecx, esi
000A78CC [00428C64] b8 e0 f3 43 00                               mov     eax, 43F3E0h
000A78D1 [00428C69] ff d0                                        call    eax
000A78D3 [00428C6B] 83 f8 09                                     cmp     eax, 9
000A78D6 [00428C6E] 7c 11                                        jl      short near ptr unk_428C81 ; game-relative-target=0x000A78E9
000A78D8 [00428C70] 8b ce                                        mov     ecx, esi
000A78DA [00428C72] b8 00 77 0a 00                               mov     eax, 0A7700h
000A78DF [00428C77] ff d0                                        call    eax
000A78E1 [00428C79] 3b c3                                        cmp     eax, ebx
000A78E3 [00428C7B] 7e 04                                        jle     short near ptr unk_428C81 ; game-relative-target=0x000A78E9
000A78E5 [00428C7D] 8b ee                                        mov     ebp, esi
000A78E7 [00428C7F] 8b d8                                        mov     ebx, eax
000A78E9 [00428C81] 81 c6 d4 00 00 00                            add     esi, 0D4h
000A78EF [00428C87] 47                                           inc     edi
000A78F0 [00428C88] 83 ff 32                                     cmp     edi, 32h ; '2'
000A78F3 [00428C8B] 7c ae                                        jl      short near ptr unk_428C3B ; game-relative-target=0x000A78A3
000A78F5 [00428C8D] 8b c5                                        mov     eax, ebp
000A78F7 [00428C8F] 5d                                           pop     ebp
000A78F8 [00428C90] 5b                                           pop     ebx
000A78F9 [00428C91] 5f                                           pop     edi
000A78FA [00428C92] 5e                                           pop     esi
000A78FB [00428C93] c3                                           retn
