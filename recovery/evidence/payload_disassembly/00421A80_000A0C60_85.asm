; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00421A80; baseline game VA=0x000A0C60; size=133
; Relative branch annotations use the baseline game destination.
000A0C60 [00421A80] 8a 43 04                                     mov     al, [ebx+4]
000A0C63 [00421A83] 3c 07                                        cmp     al, 7
000A0C65 [00421A85] 74 4c                                        jz      short near ptr unk_421AD3 ; game-relative-target=0x000A0CB3
000A0C67 [00421A87] bf 03 00 00 00                               mov     edi, 3
000A0C6C [00421A8C] 3c 00                                        cmp     al, 0
000A0C6E [00421A8E] 75 01                                        jnz     short near ptr unk_421A91 ; game-relative-target=0x000A0C71
000A0C70 [00421A90] 47                                           inc     edi
000A0C71 [00421A91] 3c 01                                        cmp     al, 1
000A0C73 [00421A93] 75 01                                        jnz     short near ptr unk_421A96 ; game-relative-target=0x000A0C76
000A0C75 [00421A95] 4f                                           dec     edi
000A0C76 [00421A96] 39 7e 4c                                     cmp     [esi+4Ch], edi
000A0C79 [00421A99] 7e 38                                        jle     short near ptr unk_421AD3 ; game-relative-target=0x000A0CB3
000A0C7B [00421A9B] 55                                           push    ebp
000A0C7C [00421A9C] 53                                           push    ebx
000A0C7D [00421A9D] bd 01 00 00 00                               mov     ebp, 1
000A0C82 [00421AA2] 8b 5c 24 34                                  mov     ebx, [esp+34h]
000A0C86 [00421AA6] 8d 4e 40                                     lea     ecx, [esi+40h]
000A0C89 [00421AA9] 51                                           push    ecx
000A0C8A [00421AAA] ff 73 08                                     push    dword ptr [ebx+8]
000A0C8D [00421AAD] b8 50 b9 48 00                               mov     eax, 48B950h
000A0C92 [00421AB2] ff d0                                        call    eax
000A0C94 [00421AB4] 8d 4e 74                                     lea     ecx, [esi+74h]
000A0C97 [00421AB7] 8b 04 81                                     mov     eax, [ecx+eax*4]
000A0C9A [00421ABA] 85 c0                                        test    eax, eax
000A0C9C [00421ABC] 74 0c                                        jz      short near ptr unk_421ACA ; game-relative-target=0x000A0CAA
000A0C9E [00421ABE] 83 78 54 07                                  cmp     dword ptr [eax+54h], 7
000A0CA2 [00421AC2] 7c 06                                        jl      short near ptr unk_421ACA ; game-relative-target=0x000A0CAA
000A0CA4 [00421AC4] 3b ef                                        cmp     ebp, edi
000A0CA6 [00421AC6] 7e 09                                        jle     short near ptr unk_421AD1 ; game-relative-target=0x000A0CB1
000A0CA8 [00421AC8] eb 0c                                        jmp     short near ptr unk_421AD6 ; game-relative-target=0x000A0CB6
000A0CAA [00421ACA] 45                                           inc     ebp
000A0CAB [00421ACB] 8b 1b                                        mov     ebx, [ebx]
000A0CAD [00421ACD] 85 db                                        test    ebx, ebx
000A0CAF [00421ACF] 75 d5                                        jnz     short near ptr unk_421AA6 ; game-relative-target=0x000A0C86
000A0CB1 [00421AD1] 5b                                           pop     ebx
000A0CB2 [00421AD2] 5d                                           pop     ebp
000A0CB3 [00421AD3] 33 c0                                        xor     eax, eax
000A0CB5 [00421AD5] c3                                           retn
000A0CB6 [00421AD6] 4f                                           dec     edi
000A0CB7 [00421AD7] 8b 4c 24 34                                  mov     ecx, [esp+34h]
000A0CBB [00421ADB] 4f                                           dec     edi
000A0CBC [00421ADC] 75 02                                        jnz     short near ptr unk_421AE0 ; game-relative-target=0x000A0CC0
000A0CBE [00421ADE] 8b d9                                        mov     ebx, ecx
000A0CC0 [00421AE0] 4d                                           dec     ebp
000A0CC1 [00421AE1] 74 04                                        jz      short near ptr unk_421AE7 ; game-relative-target=0x000A0CC7
000A0CC3 [00421AE3] 8b 09                                        mov     ecx, [ecx]
000A0CC5 [00421AE5] eb f4                                        jmp     short near ptr unk_421ADB ; game-relative-target=0x000A0CBB
000A0CC7 [00421AE7] 8b 79 08                                     mov     edi, [ecx+8]
000A0CCA [00421AEA] 51                                           push    ecx
000A0CCB [00421AEB] 8d 4c 24 34                                  lea     ecx, [esp+34h]
000A0CCF [00421AEF] b8 10 64 41 00                               mov     eax, 416410h
000A0CD4 [00421AF4] ff d0                                        call    eax
000A0CD6 [00421AF6] 57                                           push    edi
000A0CD7 [00421AF7] 53                                           push    ebx
000A0CD8 [00421AF8] 8d 4c 24 38                                  lea     ecx, [esp+38h]
000A0CDC [00421AFC] b8 a0 82 51 00                               mov     eax, 5182A0h
000A0CE1 [00421B01] ff d0                                        call    eax
000A0CE3 [00421B03] eb cc                                        jmp     short near ptr unk_421AD1 ; game-relative-target=0x000A0CB1
