; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00421FA0; baseline game VA=0x000A1C00; size=84
; Relative branch annotations use the baseline game destination.
000A1C00 [00421FA0] 58                                           pop     eax
000A1C01 [00421FA1] b8 10 f6 46 00                               mov     eax, 46F610h
000A1C06 [00421FA6] ff d0                                        call    eax
000A1C08 [00421FA8] b9 00 05 0a 00                               mov     ecx, 0A0500h
000A1C0D [00421FAD] b8 e0 80 51 00                               mov     eax, 5180E0h
000A1C12 [00421FB2] ff d0                                        call    eax
000A1C14 [00421FB4] 56                                           push    esi
000A1C15 [00421FB5] 8b 73 48                                     mov     esi, [ebx+48h]
000A1C18 [00421FB8] 8b 4e 08                                     mov     ecx, [esi+8]
000A1C1B [00421FBB] 8b 41 64                                     mov     eax, [ecx+64h]
000A1C1E [00421FBE] 83 f8 3c                                     cmp     eax, 3Ch ; '<'
000A1C21 [00421FC1] 7c 2a                                        jl      short near ptr unk_421FED ; game-relative-target=0x000A1C4D
000A1C23 [00421FC3] 2b 41 54                                     sub     eax, [ecx+54h]
000A1C26 [00421FC6] 83 f8 f8                                     cmp     eax, 0FFFFFFF8h
000A1C29 [00421FC9] 7f 1c                                        jg      short near ptr unk_421FE7 ; game-relative-target=0x000A1C47
000A1C2B [00421FCB] 51                                           push    ecx
000A1C2C [00421FCC] 8d 4b 44                                     lea     ecx, [ebx+44h]
000A1C2F [00421FCF] 56                                           push    esi
000A1C30 [00421FD0] 8b 36                                        mov     esi, [esi]
000A1C32 [00421FD2] b8 10 64 41 00                               mov     eax, 416410h
000A1C37 [00421FD7] ff d0                                        call    eax
000A1C39 [00421FD9] b9 00 05 0a 00                               mov     ecx, 0A0500h
000A1C3E [00421FDE] b8 70 ef 46 00                               mov     eax, 46EF70h
000A1C43 [00421FE3] ff d0                                        call    eax
000A1C45 [00421FE5] eb 02                                        jmp     short near ptr unk_421FE9 ; game-relative-target=0x000A1C49
000A1C47 [00421FE7] 8b 36                                        mov     esi, [esi]
000A1C49 [00421FE9] 85 f6                                        test    esi, esi
000A1C4B [00421FEB] 75 cb                                        jnz     short near ptr unk_421FB8 ; game-relative-target=0x000A1C18
000A1C4D [00421FED] 5e                                           pop     esi
000A1C4E [00421FEE] 68 c7 2c 4b 00                               push    4B2CC7h
000A1C53 [00421FF3] c3                                           retn
