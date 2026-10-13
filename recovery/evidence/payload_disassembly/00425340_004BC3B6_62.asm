; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00425340; baseline game VA=0x004BC3B6; size=98
; Relative branch annotations use the baseline game destination.
004BC3B6 [00425340] 8b 7e 08                                     mov     edi, [esi+8]
004BC3B9 [00425343] 8b 36                                        mov     esi, [esi]
004BC3BB [00425345] a0 c9 f4 43 00                               mov     al, ds:43F4C9h
004BC3C0 [0042534A] a8 01                                        test    al, 1
004BC3C2 [0042534C] 75 14                                        jnz     short near ptr unk_425362 ; game-relative-target=0x004BC3D8
004BC3C4 [0042534E] 8d 4c 24 54                                  lea     ecx, [esp+54h]
004BC3C8 [00425352] 50                                           push    eax
004BC3C9 [00425353] ff 77 44                                     push    dword ptr [edi+44h]
004BC3CC [00425356] b8 60 eb 46 00                               mov     eax, 46EB60h
004BC3D1 [0042535B] ff d0                                        call    eax
004BC3D3 [0042535D] 85 c0                                        test    eax, eax
004BC3D5 [0042535F] 58                                           pop     eax
004BC3D6 [00425360] 74 25                                        jz      short near ptr unk_425387 ; game-relative-target=0x004BC3FD
004BC3D8 [00425362] 33 c9                                        xor     ecx, ecx
004BC3DA [00425364] 81 7f 08 78 e8 ff ff                         cmp     dword ptr [edi+8], 0FFFFE878h
004BC3E1 [0042536B] 0f 9e c1                                     setle   cl
004BC3E4 [0042536E] d0 e8                                        shr     al, 1
004BC3E6 [00425370] 32 c1                                        xor     al, cl
004BC3E8 [00425372] a8 01                                        test    al, 1
004BC3EA [00425374] 74 11                                        jz      short near ptr unk_425387 ; game-relative-target=0x004BC3FD
004BC3EC [00425376] 57                                           push    edi
004BC3ED [00425377] 53                                           push    ebx
004BC3EE [00425378] b8 a0 b7 4b 00                               mov     eax, 4BB7A0h
004BC3F3 [0042537D] ff d0                                        call    eax
004BC3F5 [0042537F] 85 c0                                        test    eax, eax
004BC3F7 [00425381] 0f 84 9c 00 00 00                            jz      near ptr unk_425423 ; game-relative-target=0x004BC499
004BC3FD [00425387] 85 f6                                        test    esi, esi
004BC3FF [00425389] 75 b5                                        jnz     short near ptr unk_425340 ; game-relative-target=0x004BC3B6
004BC401 [0042538B] a0 c9 f4 43 00                               mov     al, ds:43F4C9h
004BC406 [00425390] 40                                           inc     eax
004BC407 [00425391] a2 c9 f4 43 00                               mov     ds:43F4C9h, al
004BC40C [00425396] 3c 04                                        cmp     al, 4
004BC40E [00425398] 7d 52                                        jge     short near ptr unk_4253EC ; game-relative-target=0x004BC462
004BC410 [0042539A] 8b b5 3c 08 00 00                            mov     esi, [ebp+83Ch]
004BC416 [004253A0] eb 9e                                        jmp     short near ptr unk_425340 ; game-relative-target=0x004BC3B6
