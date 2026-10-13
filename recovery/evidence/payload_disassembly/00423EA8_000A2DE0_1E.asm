; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00423EA8; baseline game VA=0x000A2DE0; size=30
; Relative branch annotations use the baseline game destination.
000A2DE0 [00423EA8] 8b 51 4c                                     mov     edx, [ecx+4Ch]
000A2DE3 [00423EAB] 8b 41 54                                     mov     eax, [ecx+54h]
000A2DE6 [00423EAE] 2b d0                                        sub     edx, eax
000A2DE8 [00423EB0] 83 fa f8                                     cmp     edx, 0FFFFFFF8h
000A2DEB [00423EB3] 7e 03                                        jle     short near ptr unk_423EB8 ; game-relative-target=0x000A2DF0
000A2DED [00423EB5] 33 c0                                        xor     eax, eax
000A2DEF [00423EB7] c3                                           retn
000A2DF0 [00423EB8] 3c 5a                                        cmp     al, 5Ah ; 'Z'
000A2DF2 [00423EBA] 7d f9                                        jge     short near ptr unk_423EB5 ; game-relative-target=0x000A2DED
000A2DF4 [00423EBC] 3c 50                                        cmp     al, 50h ; 'P'
000A2DF6 [00423EBE] 7c 03                                        jl      short near ptr unk_423EC3 ; game-relative-target=0x000A2DFB
000A2DF8 [00423EC0] b0 02                                        mov     al, 2
000A2DFA [00423EC2] c3                                           retn
000A2DFB [00423EC3] b0 01                                        mov     al, 1
000A2DFD [00423EC5] c3                                           retn
