; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00425628; baseline game VA=0x000A5500; size=104
; Relative branch annotations use the baseline game destination.
000A5500 [00425628] 51                                           push    ecx
000A5501 [00425629] 55                                           push    ebp
000A5502 [0042562A] 8b 6f 04                                     mov     ebp, [edi+4]
000A5505 [0042562D] 8b 4d 08                                     mov     ecx, [ebp+8]
000A5508 [00425630] 80 b9 84 00 00 00 04                         cmp     byte ptr [ecx+84h], 4
000A550F [00425637] 75 48                                        jnz     short near ptr unk_425681 ; game-relative-target=0x000A5559
000A5511 [00425639] 8b 01                                        mov     eax, [ecx]
000A5513 [0042563B] ff 50 3c                                     call    dword ptr [eax+3Ch]
000A5516 [0042563E] 85 c0                                        test    eax, eax
000A5518 [00425640] 74 3f                                        jz      short near ptr unk_425681 ; game-relative-target=0x000A5559
000A551A [00425642] 8b 45 08                                     mov     eax, [ebp+8]
000A551D [00425645] b9 b2 ef 46 00                               mov     ecx, 46EFB2h
000A5522 [0042564A] ff d1                                        call    ecx
000A5524 [0042564C] 85 c0                                        test    eax, eax
000A5526 [0042564E] 74 31                                        jz      short near ptr unk_425681 ; game-relative-target=0x000A5559
000A5528 [00425650] 8b 4e 38                                     mov     ecx, [esi+38h]
000A552B [00425653] b8 e0 fd 43 00                               mov     eax, 43FDE0h
000A5530 [00425658] ff d0                                        call    eax
000A5532 [0042565A] 50                                           push    eax
000A5533 [0042565B] 8b 4d 08                                     mov     ecx, [ebp+8]
000A5536 [0042565E] b8 c0 ce 44 00                               mov     eax, 44CEC0h
000A553B [00425663] ff d0                                        call    eax
000A553D [00425665] 3c 14                                        cmp     al, 14h
000A553F [00425667] 7d 18                                        jge     short near ptr unk_425681 ; game-relative-target=0x000A5559
000A5541 [00425669] 8b 45 08                                     mov     eax, [ebp+8]
000A5544 [0042566C] 5d                                           pop     ebp
000A5545 [0042566D] 59                                           pop     ecx
000A5546 [0042566E] 89 44 24 1c                                  mov     [esp+1Ch], eax
000A554A [00425672] 8b 4b 04                                     mov     ecx, [ebx+4]
000A554D [00425675] 8b 41 08                                     mov     eax, [ecx+8]
000A5550 [00425678] 89 44 24 18                                  mov     [esp+18h], eax
000A5554 [0042567C] 83 04 24 14                                  add     dword ptr [esp], 14h
000A5558 [00425680] c3                                           retn
000A5559 [00425681] 8b 6d 00                                     mov     ebp, [ebp+0]
000A555C [00425684] 85 ed                                        test    ebp, ebp
000A555E [00425686] 75 a5                                        jnz     short near ptr unk_42562D ; game-relative-target=0x000A5505
000A5560 [00425688] 5d                                           pop     ebp
000A5561 [00425689] 59                                           pop     ecx
000A5562 [0042568A] 68 e0 6f 4b 00                               push    4B6FE0h
000A5567 [0042568F] c3                                           retn
