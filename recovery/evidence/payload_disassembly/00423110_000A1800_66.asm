; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00423110; baseline game VA=0x000A1800; size=102
; Relative branch annotations use the baseline game destination.
000A1800 [00423110] b8 00 d7 44 00                               mov     eax, 44D700h
000A1805 [00423115] ff d0                                        call    eax
000A1807 [00423117] b9 10 27 00 00                               mov     ecx, 2710h
000A180C [0042311C] 99                                           cdq
000A180D [0042311D] f7 f1                                        div     ecx
000A180F [0042311F] 48                                           dec     eax
000A1810 [00423120] 7d 03                                        jge     short near ptr unk_423125 ; game-relative-target=0x000A1815
000A1812 [00423122] 33 c0                                        xor     eax, eax
000A1814 [00423124] c3                                           retn
000A1815 [00423125] 83 f8 04                                     cmp     eax, 4
000A1818 [00423128] 7e 05                                        jle     short near ptr unk_42312F ; game-relative-target=0x000A181F
000A181A [0042312A] b8 04 00 00 00                               mov     eax, 4
000A181F [0042312F] c3                                           retn
000A1820 [00423130] 55                                           push    ebp
000A1821 [00423131] 53                                           push    ebx
000A1822 [00423132] 33 ed                                        xor     ebp, ebp
000A1824 [00423134] 33 db                                        xor     ebx, ebx
000A1826 [00423136] 8b 74 24 14                                  mov     esi, [esp+14h]
000A182A [0042313A] 85 f6                                        test    esi, esi
000A182C [0042313C] 74 13                                        jz      short near ptr unk_423151 ; game-relative-target=0x000A1841
000A182E [0042313E] 8b 4e 08                                     mov     ecx, [esi+8]
000A1831 [00423141] 8b 36                                        mov     esi, [esi]
000A1833 [00423143] e8 c8 ff ff ff                               call    near ptr unk_423110 ; game-relative-target=0x000A1800
000A1838 [00423148] 85 c0                                        test    eax, eax
000A183A [0042314A] 74 ee                                        jz      short near ptr unk_42313A ; game-relative-target=0x000A182A
000A183C [0042314C] 03 e8                                        add     ebp, eax
000A183E [0042314E] 43                                           inc     ebx
000A183F [0042314F] eb e9                                        jmp     short near ptr unk_42313A ; game-relative-target=0x000A182A
000A1841 [00423151] 8b 44 24 1c                                  mov     eax, [esp+1Ch]
000A1845 [00423155] 8d 50 ff                                     lea     edx, [eax-1]
000A1848 [00423158] 3b c3                                        cmp     eax, ebx
000A184A [0042315A] 7e 17                                        jle     short near ptr unk_423173 ; game-relative-target=0x000A1863
000A184C [0042315C] 33 f6                                        xor     esi, esi
000A184E [0042315E] 85 db                                        test    ebx, ebx
000A1850 [00423160] 74 08                                        jz      short near ptr unk_42316A ; game-relative-target=0x000A185A
000A1852 [00423162] 2b c3                                        sub     eax, ebx
000A1854 [00423164] 2b c5                                        sub     eax, ebp
000A1856 [00423166] 7e 0b                                        jle     short near ptr unk_423173 ; game-relative-target=0x000A1863
000A1858 [00423168] 8b f3                                        mov     esi, ebx
000A185A [0042316A] b9 9a 99 99 99                               mov     ecx, 9999999Ah
000A185F [0042316F] f7 e1                                        mul     ecx
000A1861 [00423171] 03 d6                                        add     edx, esi
000A1863 [00423173] 5b                                           pop     ebx
000A1864 [00423174] 5d                                           pop     ebp
000A1865 [00423175] c3                                           retn
