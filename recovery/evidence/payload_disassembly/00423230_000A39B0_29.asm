; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00423230; baseline game VA=0x000A39B0; size=41
; Relative branch annotations use the baseline game destination.
000A39B0 [00423230] 8b 4b 38                                     mov     ecx, [ebx+38h]
000A39B3 [00423233] 83 79 24 04                                  cmp     dword ptr [ecx+24h], 4
000A39B7 [00423237] 7c 03                                        jl      short near ptr unk_42323C ; game-relative-target=0x000A39BC
000A39B9 [00423239] 33 c0                                        xor     eax, eax
000A39BB [0042323B] c3                                           retn
000A39BC [0042323C] 56                                           push    esi
000A39BD [0042323D] 55                                           push    ebp
000A39BE [0042323E] b8 00 07 4b 00                               mov     eax, 4B0700h
000A39C3 [00423243] ff d0                                        call    eax
000A39C5 [00423245] 83 c4 08                                     add     esp, 8
000A39C8 [00423248] 85 c0                                        test    eax, eax
000A39CA [0042324A] 75 01                                        jnz     short near ptr unk_42324D ; game-relative-target=0x000A39CD
000A39CC [0042324C] c3                                           retn
000A39CD [0042324D] 8b 4b 38                                     mov     ecx, [ebx+38h]
000A39D0 [00423250] 56                                           push    esi
000A39D1 [00423251] b8 80 20 0a 00                               mov     eax, 0A2080h
000A39D6 [00423256] ff d0                                        call    eax
000A39D8 [00423258] c3                                           retn
