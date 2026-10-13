; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042773C; baseline game VA=0x000A6540; size=108
; Relative branch annotations use the baseline game destination.
000A6540 [0042773C] 56                                           push    esi
000A6541 [0042773D] 57                                           push    edi
000A6542 [0042773E] 53                                           push    ebx
000A6543 [0042773F] 55                                           push    ebp
000A6544 [00427740] 8b 5c 24 18                                  mov     ebx, [esp+18h]
000A6548 [00427744] 0b 99 00 01 00 00                            or      ebx, [ecx+100h]
000A654E [0042774A] 8a 44 24 14                                  mov     al, [esp+14h]
000A6552 [0042774E] 33 d2                                        xor     edx, edx
000A6554 [00427750] 33 f6                                        xor     esi, esi
000A6556 [00427752] 33 ff                                        xor     edi, edi
000A6558 [00427754] 3c 00                                        cmp     al, 0
000A655A [00427756] 75 06                                        jnz     short near ptr unk_42775E ; game-relative-target=0x000A6562
000A655C [00427758] 66 b9 00 02                                  mov     cx, 200h
000A6560 [0042775C] eb 12                                        jmp     short near ptr unk_427770 ; game-relative-target=0x000A6574
000A6562 [0042775E] 3c 02                                        cmp     al, 2
000A6564 [00427760] 75 06                                        jnz     short near ptr unk_427768 ; game-relative-target=0x000A656C
000A6566 [00427762] 66 b9 03 08                                  mov     cx, 803h
000A656A [00427766] eb 08                                        jmp     short near ptr unk_427770 ; game-relative-target=0x000A6574
000A656C [00427768] 3c 05                                        cmp     al, 5
000A656E [0042776A] 75 2f                                        jnz     short near ptr unk_42779B ; game-relative-target=0x000A659F
000A6570 [0042776C] 66 b9 06 0b                                  mov     cx, 0B06h
000A6574 [00427770] f6 c3 01                                     test    bl, 1
000A6577 [00427773] 74 1e                                        jz      short near ptr unk_427793 ; game-relative-target=0x000A6597
000A6579 [00427775] 52                                           push    edx
000A657A [00427776] b8 20 37 45 00                               mov     eax, 453720h
000A657F [0042777B] ff d0                                        call    eax
000A6581 [0042777D] 5a                                           pop     edx
000A6582 [0042777E] 8b 68 64                                     mov     ebp, [eax+64h]
000A6585 [00427781] 3a d1                                        cmp     dl, cl
000A6587 [00427783] 7c 04                                        jl      short near ptr unk_427789 ; game-relative-target=0x000A658D
000A6589 [00427785] 3a d5                                        cmp     dl, ch
000A658B [00427787] 7e 02                                        jle     short near ptr unk_42778B ; game-relative-target=0x000A658F
000A658D [00427789] d1 ed                                        shr     ebp, 1
000A658F [0042778B] 3b ee                                        cmp     ebp, esi
000A6591 [0042778D] 7c 04                                        jl      short near ptr unk_427793 ; game-relative-target=0x000A6597
000A6593 [0042778F] 8b f5                                        mov     esi, ebp
000A6595 [00427791] 8b f8                                        mov     edi, eax
000A6597 [00427793] d1 eb                                        shr     ebx, 1
000A6599 [00427795] 42                                           inc     edx
000A659A [00427796] 80 fa 0c                                     cmp     dl, 0Ch
000A659D [00427799] 7c d5                                        jl      short near ptr unk_427770 ; game-relative-target=0x000A6574
000A659F [0042779B] 89 7c 24 14                                  mov     [esp+14h], edi
000A65A3 [0042779F] 8b c6                                        mov     eax, esi
000A65A5 [004277A1] 5d                                           pop     ebp
000A65A6 [004277A2] 5b                                           pop     ebx
000A65A7 [004277A3] 5f                                           pop     edi
000A65A8 [004277A4] 5e                                           pop     esi
000A65A9 [004277A5] c2 08 00                                     retn    8
