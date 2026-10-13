; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042C980; baseline game VA=0x0052BC4A; size=54
; Relative branch annotations use the baseline game destination.
0052BC4A [0042C980] 8b c8                                        mov     ecx, eax
0052BC4C [0042C982] e8 1f 81 00 00                               call    near ptr 434AA6h ; game-relative-target=0x00533D70
0052BC51 [0042C987] 8b c8                                        mov     ecx, eax
0052BC53 [0042C989] 83 e9 00                                     sub     ecx, 0
0052BC56 [0042C98C] 74 19                                        jz      short near ptr unk_42C9A7 ; game-relative-target=0x0052BC71
0052BC58 [0042C98E] 49                                           dec     ecx
0052BC59 [0042C98F] 75 1b                                        jnz     short near ptr unk_42C9AC ; game-relative-target=0x0052BC76
0052BC5B [0042C991] 33 c0                                        xor     eax, eax
0052BC5D [0042C993] 50                                           push    eax
0052BC5E [0042C994] 8b ce                                        mov     ecx, esi
0052BC60 [0042C996] e8 7b 9e ff ff                               call    near ptr unk_426816 ; game-relative-target=0x00525AE0
0052BC65 [0042C99B] 8b c8                                        mov     ecx, eax
0052BC67 [0042C99D] e8 d4 5c ff ff                               call    near ptr unk_422676 ; game-relative-target=0x00521940
0052BC6C [0042C9A2] e9 56 02 00 00                               jmp     near ptr unk_42CBFD ; game-relative-target=0x0052BEC7
0052BC71 [0042C9A7] b8 01 00 00 00                               mov     eax, 1
0052BC76 [0042C9AC] 50                                           push    eax
0052BC77 [0042C9AD] 8b ce                                        mov     ecx, esi
0052BC79 [0042C9AF] e8 62 9e ff ff                               call    near ptr unk_426816 ; game-relative-target=0x00525AE0
0052BC7E [0042C9B4] 8b c8                                        mov     ecx, eax
