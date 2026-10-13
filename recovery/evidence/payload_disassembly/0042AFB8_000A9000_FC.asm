; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042AFB8; baseline game VA=0x000A9000; size=252
; Relative branch annotations use the baseline game destination.
000A9000 [0042AFB8] 53                                           push    ebx
000A9001 [0042AFB9] 56                                           push    esi
000A9002 [0042AFBA] 8b da                                        mov     ebx, edx
000A9004 [0042AFBC] 8b f1                                        mov     esi, ecx
000A9006 [0042AFBE] 8b 8e 6c 26 00 00                            mov     ecx, [esi+266Ch]
000A900C [0042AFC4] 8a 41 06                                     mov     al, [ecx+6]
000A900F [0042AFC7] 3c 03                                        cmp     al, 3
000A9011 [0042AFC9] 75 19                                        jnz     short near ptr unk_42AFE4 ; game-relative-target=0x000A902C
000A9013 [0042AFCB] 33 c0                                        xor     eax, eax
000A9015 [0042AFCD] ba 41 53 44 46                               mov     edx, 46445341h
000A901A [0042AFD2] 0f b6 ca                                     movzx   ecx, dl
000A901D [0042AFD5] 3b cb                                        cmp     ecx, ebx
000A901F [0042AFD7] 74 13                                        jz      short near ptr unk_42AFEC ; game-relative-target=0x000A9034
000A9021 [0042AFD9] c1 ea 08                                     shr     edx, 8
000A9024 [0042AFDC] 40                                           inc     eax
000A9025 [0042AFDD] 83 f8 04                                     cmp     eax, 4
000A9028 [0042AFE0] 7c f0                                        jl      short near ptr unk_42AFD2 ; game-relative-target=0x000A901A
000A902A [0042AFE2] eb 40                                        jmp     short near ptr unk_42B024 ; game-relative-target=0x000A906C
000A902C [0042AFE4] 8d 43 90                                     lea     eax, [ebx-70h]
000A902F [0042AFE7] 83 f8 05                                     cmp     eax, 5
000A9032 [0042AFEA] 77 3b                                        ja      short near ptr unk_42B027 ; game-relative-target=0x000A906F
000A9034 [0042AFEC] 3b 86 60 01 00 00                            cmp     eax, [esi+160h]
000A903A [0042AFF2] 7d 30                                        jge     short near ptr unk_42B024 ; game-relative-target=0x000A906C
000A903C [0042AFF4] 8b 8c 86 68 01 00 00                         mov     ecx, [esi+eax*4+168h]
000A9043 [0042AFFB] 85 c9                                        test    ecx, ecx
000A9045 [0042AFFD] 74 25                                        jz      short near ptr unk_42B024 ; game-relative-target=0x000A906C
000A9047 [0042AFFF] 8b 51 08                                     mov     edx, [ecx+8]
000A904A [0042B002] 85 d2                                        test    edx, edx
000A904C [0042B004] 75 07                                        jnz     short near ptr unk_42B00D ; game-relative-target=0x000A9055
000A904E [0042B006] 83 c1 0c                                     add     ecx, 0Ch
000A9051 [0042B009] 8b c2                                        mov     eax, edx
000A9053 [0042B00B] eb 6a                                        jmp     short near ptr unk_42B077 ; game-relative-target=0x000A90BF
000A9055 [0042B00D] 8b 51 04                                     mov     edx, [ecx+4]
000A9058 [0042B010] 8b 89 48 01 00 00                            mov     ecx, [ecx+148h]
000A905E [0042B016] 85 c9                                        test    ecx, ecx
000A9060 [0042B018] 7e 6a                                        jle     short near ptr unk_42B084 ; game-relative-target=0x000A90CC
000A9062 [0042B01A] 50                                           push    eax
000A9063 [0042B01B] 8b ce                                        mov     ecx, esi
000A9065 [0042B01D] b8 d0 90 41 00                               mov     eax, 4190D0h
000A906A [0042B022] ff d0                                        call    eax
000A906C [0042B024] 5e                                           pop     esi
000A906D [0042B025] 5b                                           pop     ebx
000A906E [0042B026] c3                                           retn
000A906F [0042B027] 8d 43 d0                                     lea     eax, [ebx-30h]
000A9072 [0042B02A] 83 f8 09                                     cmp     eax, 9
000A9075 [0042B02D] 76 0b                                        jbe     short near ptr unk_42B03A ; game-relative-target=0x000A9082
000A9077 [0042B02F] 8d 43 bf                                     lea     eax, [ebx-41h]
000A907A [0042B032] 83 f8 18                                     cmp     eax, 18h
000A907D [0042B035] 8d 40 0a                                     lea     eax, [eax+0Ah]
000A9080 [0042B038] 77 ea                                        ja      short near ptr unk_42B024 ; game-relative-target=0x000A906C
000A9082 [0042B03A] 0f b6 80 d8 90 0a 00                         movzx   eax, byte ptr [eax+0A90D8h]
000A9089 [0042B041] 8b d0                                        mov     edx, eax
000A908B [0042B043] 83 e0 0f                                     and     eax, 0Fh
000A908E [0042B046] c1 ea 04                                     shr     edx, 4
000A9091 [0042B049] 83 e2 0f                                     and     edx, 0Fh
000A9094 [0042B04C] 8b 8c 96 68 01 00 00                         mov     ecx, [esi+edx*4+168h]
000A909B [0042B053] 85 c9                                        test    ecx, ecx
000A909D [0042B055] 74 cd                                        jz      short near ptr unk_42B024 ; game-relative-target=0x000A906C
000A909F [0042B057] 3b 81 48 01 00 00                            cmp     eax, [ecx+148h]
000A90A5 [0042B05D] 7d c5                                        jge     short near ptr unk_42B024 ; game-relative-target=0x000A906C
000A90A7 [0042B05F] 8b 8c 81 10 01 00 00                         mov     ecx, [ecx+eax*4+110h]
000A90AE [0042B066] 85 c9                                        test    ecx, ecx
000A90B0 [0042B068] 74 ba                                        jz      short near ptr unk_42B024 ; game-relative-target=0x000A906C
000A90B2 [0042B06A] 8b 51 0c                                     mov     edx, [ecx+0Ch]
000A90B5 [0042B06D] 8b 41 10                                     mov     eax, [ecx+10h]
000A90B8 [0042B070] 85 c0                                        test    eax, eax
000A90BA [0042B072] 75 10                                        jnz     short near ptr unk_42B084 ; game-relative-target=0x000A90CC
000A90BC [0042B074] 83 c1 14                                     add     ecx, 14h
000A90BF [0042B077] 50                                           push    eax
000A90C0 [0042B078] 51                                           push    ecx
000A90C1 [0042B079] 8b ce                                        mov     ecx, esi
000A90C3 [0042B07B] b8 e0 7e 41 00                               mov     eax, 417EE0h
000A90C8 [0042B080] ff d0                                        call    eax
000A90CA [0042B082] eb a0                                        jmp     short near ptr unk_42B024 ; game-relative-target=0x000A906C
000A90CC [0042B084] 52                                           push    edx
000A90CD [0042B085] 8b ce                                        mov     ecx, esi
000A90CF [0042B087] b8 c0 e1 5c 00                               mov     eax, 5CE1C0h
000A90D4 [0042B08C] ff d0                                        call    eax
000A90D6 [0042B08E] eb 94                                        jmp     short near ptr unk_42B024 ; game-relative-target=0x000A906C
000A90D8 [0042B090] 41                                           inc     ecx
000A90D9 [0042B091] 00 01                                        add     [ecx], al
000A90DB [0042B093] 02 03                                        add     al, [ebx]
000A90DD [0042B095] 04 05                                        add     al, 5
000A90DF [0042B097] 06                                           push    es
000A90E0 [0042B098] 07                                           pop     es
000A90E1 [0042B099] 40                                           inc     eax
000A90E2 [0042B09A] 10 53 51                                     adc     [ebx+51h], dl
000A90E5 [0042B09D] 12 22                                        adc     ah, [edx]
000A90E7 [0042B09F] 34 35                                        xor     al, 35h ; '5'
000A90E9 [0042B0A1] 36 33 37                                     xor     esi, ss:[edi]
000A90EC [0042B0A4] 56                                           push    esi
000A90ED [0042B0A5] 57                                           push    edi
000A90EE [0042B0A6] 55                                           push    ebp
000A90EF [0042B0A7] 54                                           push    esp
000A90F0 [0042B0A8] 42                                           inc     edx
000A90F1 [0042B0A9] 43                                           inc     ebx
000A90F2 [0042B0AA] 20 23                                        and     [ebx], ah
000A90F4 [0042B0AC] 11 30                                        adc     [eax], esi
000A90F6 [0042B0AE] 32 52 21                                     xor     dl, [edx+21h]
000A90F9 [0042B0B1] 50                                           push    eax
000A90FA [0042B0B2] 31 08                                        xor     [eax], ecx
