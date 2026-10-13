; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00423910; baseline game VA=0x000A3BF8; size=104
; Relative branch annotations use the baseline game destination.
000A3BF8 [00423910] 56                                           push    esi
000A3BF9 [00423911] 57                                           push    edi
000A3BFA [00423912] 55                                           push    ebp
000A3BFB [00423913] 53                                           push    ebx
000A3BFC [00423914] 8b f1                                        mov     esi, ecx
000A3BFE [00423916] 8b fa                                        mov     edi, edx
000A3C00 [00423918] 33 c0                                        xor     eax, eax
000A3C02 [0042391A] 83 c2 58                                     add     edx, 58h ; 'X'
000A3C05 [0042391D] 8b 5a 74                                     mov     ebx, [edx+74h]
000A3C08 [00423920] 85 db                                        test    ebx, ebx
000A3C0A [00423922] 74 4f                                        jz      short near ptr unk_423973 ; game-relative-target=0x000A3C5B
000A3C0C [00423924] 8b 6a 30                                     mov     ebp, [edx+30h]
000A3C0F [00423927] 81 fd 88 13 00 00                            cmp     ebp, 1388h
000A3C15 [0042392D] 7e 44                                        jle     short near ptr unk_423973 ; game-relative-target=0x000A3C5B
000A3C17 [0042392F] 56                                           push    esi
000A3C18 [00423930] 53                                           push    ebx
000A3C19 [00423931] b8 00 07 4b 00                               mov     eax, 4B0700h
000A3C1E [00423936] ff d0                                        call    eax
000A3C20 [00423938] 83 c4 08                                     add     esp, 8
000A3C23 [0042393B] 85 c0                                        test    eax, eax
000A3C25 [0042393D] 74 34                                        jz      short near ptr unk_423973 ; game-relative-target=0x000A3C5B
000A3C27 [0042393F] f6 43 34 04                                  test    byte ptr [ebx+34h], 4
000A3C2B [00423943] 74 07                                        jz      short near ptr unk_42394C ; game-relative-target=0x000A3C34
000A3C2D [00423945] b8 30 75 00 00                               mov     eax, 7530h
000A3C32 [0042394A] eb 27                                        jmp     short near ptr unk_423973 ; game-relative-target=0x000A3C5B
000A3C34 [0042394C] 6a 0c                                        push    0Ch
000A3C36 [0042394E] 6a 0b                                        push    0Bh
000A3C38 [00423950] 56                                           push    esi
000A3C39 [00423951] 57                                           push    edi
000A3C3A [00423952] b8 80 a6 44 00                               mov     eax, 44A680h
000A3C3F [00423957] ff d0                                        call    eax
000A3C41 [00423959] 83 c4 10                                     add     esp, 10h
000A3C44 [0042395C] b9 32 00 00 00                               mov     ecx, 32h ; '2'
000A3C49 [00423961] 3b c1                                        cmp     eax, ecx
000A3C4B [00423963] 7e 02                                        jle     short near ptr unk_423967 ; game-relative-target=0x000A3C4F
000A3C4D [00423965] 8b c1                                        mov     eax, ecx
000A3C4F [00423967] 83 e8 46                                     sub     eax, 46h ; 'F'
000A3C52 [0042396A] f7 d8                                        neg     eax
000A3C54 [0042396C] f7 ed                                        imul    ebp
000A3C56 [0042396E] b1 32                                        mov     cl, 32h ; '2'
000A3C58 [00423970] 99                                           cdq
000A3C59 [00423971] f7 f1                                        div     ecx
000A3C5B [00423973] 5b                                           pop     ebx
000A3C5C [00423974] 5d                                           pop     ebp
000A3C5D [00423975] 5f                                           pop     edi
000A3C5E [00423976] 5e                                           pop     esi
000A3C5F [00423977] c3                                           retn
