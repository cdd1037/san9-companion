; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00424500; baseline game VA=0x000A2BC8; size=49
; Relative branch annotations use the baseline game destination.
000A2BC8 [00424500] 51                                           push    ecx
000A2BC9 [00424501] 8b 4e 38                                     mov     ecx, [esi+38h]
000A2BCC [00424504] 51                                           push    ecx
000A2BCD [00424505] b8 b0 d9 43 00                               mov     eax, 43D9B0h
000A2BD2 [0042450A] ff d0                                        call    eax
000A2BD4 [0042450C] 59                                           pop     ecx
000A2BD5 [0042450D] 8b 17                                        mov     edx, [edi]
000A2BD7 [0042450F] 2b d0                                        sub     edx, eax
000A2BD9 [00424511] 8b 81 84 00 00 00                            mov     eax, [ecx+84h]
000A2BDF [00424517] c1 e0 0b                                     shl     eax, 0Bh
000A2BE2 [0042451A] 2b d0                                        sub     edx, eax
000A2BE4 [0042451C] 59                                           pop     ecx
000A2BE5 [0042451D] 83 fa 64                                     cmp     edx, 64h ; 'd'
000A2BE8 [00424520] 7c 0c                                        jl      short near ptr unk_42452E ; game-relative-target=0x000A2BF6
000A2BEA [00424522] 89 17                                        mov     [edi], edx
000A2BEC [00424524] 89 54 24 08                                  mov     [esp+8], edx
000A2BF0 [00424528] 68 d0 de 46 00                               push    46DED0h
000A2BF5 [0042452D] c3                                           retn
000A2BF6 [0042452E] c2 08 00                                     retn    8
