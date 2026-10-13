; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00426D30; baseline game VA=0x000A6320; size=53
; Relative branch annotations use the baseline game destination.
000A6320 [00426D30] 56                                           push    esi
000A6321 [00426D31] 53                                           push    ebx
000A6322 [00426D32] 33 db                                        xor     ebx, ebx
000A6324 [00426D34] 8b 74 24 0c                                  mov     esi, [esp+0Ch]
000A6328 [00426D38] 8a 06                                        mov     al, [esi]
000A632A [00426D3A] 8a 11                                        mov     dl, [ecx]
000A632C [00426D3C] 80 fa 00                                     cmp     dl, 0
000A632F [00426D3F] 75 09                                        jnz     short near ptr unk_426D4A ; game-relative-target=0x000A633A
000A6331 [00426D41] 80 fb 05                                     cmp     bl, 5
000A6334 [00426D44] 7d 04                                        jge     short near ptr unk_426D4A ; game-relative-target=0x000A633A
000A6336 [00426D46] 41                                           inc     ecx
000A6337 [00426D47] 43                                           inc     ebx
000A6338 [00426D48] eb f0                                        jmp     short near ptr unk_426D3A ; game-relative-target=0x000A632A
000A633A [00426D4A] 3a c2                                        cmp     al, dl
000A633C [00426D4C] 75 10                                        jnz     short near ptr unk_426D5E ; game-relative-target=0x000A634E
000A633E [00426D4E] 3c 00                                        cmp     al, 0
000A6340 [00426D50] 74 08                                        jz      short near ptr unk_426D5A ; game-relative-target=0x000A634A
000A6342 [00426D52] 46                                           inc     esi
000A6343 [00426D53] 41                                           inc     ecx
000A6344 [00426D54] 43                                           inc     ebx
000A6345 [00426D55] 80 fb 09                                     cmp     bl, 9
000A6348 [00426D58] 7c de                                        jl      short near ptr unk_426D38 ; game-relative-target=0x000A6328
000A634A [00426D5A] 33 c0                                        xor     eax, eax
000A634C [00426D5C] eb 02                                        jmp     short near ptr unk_426D60 ; game-relative-target=0x000A6350
000A634E [00426D5E] b0 01                                        mov     al, 1
000A6350 [00426D60] 5b                                           pop     ebx
000A6351 [00426D61] 5e                                           pop     esi
000A6352 [00426D62] c2 04 00                                     retn    4
