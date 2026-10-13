; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004257F0; baseline game VA=0x000A5600; size=47
; Relative branch annotations use the baseline game destination.
000A5600 [004257F0] 8b 44 24 04                                  mov     eax, [esp+4]
000A5604 [004257F4] 56                                           push    esi
000A5605 [004257F5] 8b 30                                        mov     esi, [eax]
000A5607 [004257F7] 8b ce                                        mov     ecx, esi
000A5609 [004257F9] b8 c0 55 0a 00                               mov     eax, 0A55C0h
000A560E [004257FE] ff d0                                        call    eax
000A5610 [00425800] ba 10 27 00 00                               mov     edx, 2710h
000A5615 [00425805] 3c 02                                        cmp     al, 2
000A5617 [00425807] 74 01                                        jz      short near ptr unk_42580A ; game-relative-target=0x000A561A
000A5619 [00425809] 42                                           inc     edx
000A561A [0042580A] 89 56 08                                     mov     [esi+8], edx
000A561D [0042580D] 33 c0                                        xor     eax, eax
000A561F [0042580F] f6 c2 01                                     test    dl, 1
000A5622 [00425812] 75 09                                        jnz     short near ptr unk_42581D ; game-relative-target=0x000A562D
000A5624 [00425814] 0f b6 46 04                                  movzx   eax, byte ptr [esi+4]
000A5628 [00425818] 83 e8 4d                                     sub     eax, 4Dh ; 'M'
000A562B [0042581B] f7 d8                                        neg     eax
000A562D [0042581D] 5e                                           pop     esi
000A562E [0042581E] c3                                           retn
