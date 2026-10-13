; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00428F48; baseline game VA=0x000A0190; size=76
; Relative branch annotations use the baseline game destination.
000A0190 [00428F48] 56                                           push    esi
000A0191 [00428F49] 53                                           push    ebx
000A0192 [00428F4A] b8 e0 ed 43 00                               mov     eax, 43EDE0h
000A0197 [00428F4F] f6 41 34 04                                  test    byte ptr [ecx+34h], 4
000A019B [00428F53] 75 3c                                        jnz     short near ptr unk_428F91 ; game-relative-target=0x000A01D9
000A019D [00428F55] 8b f1                                        mov     esi, ecx
000A019F [00428F57] 6a 01                                        push    1
000A01A1 [00428F59] ff d0                                        call    eax
000A01A3 [00428F5B] 8b d8                                        mov     ebx, eax
000A01A5 [00428F5D] b8 90 4b 45 00                               mov     eax, 454B90h
000A01AA [00428F62] ff d0                                        call    eax
000A01AC [00428F64] 05 96 00 00 00                               add     eax, 96h
000A01B1 [00428F69] f7 eb                                        imul    ebx
000A01B3 [00428F6B] 39 46 18                                     cmp     [esi+18h], eax
000A01B6 [00428F6E] 7c 1f                                        jl      short near ptr unk_428F8F ; game-relative-target=0x000A01D7
000A01B8 [00428F70] 50                                           push    eax
000A01B9 [00428F71] 68 68 01 00 00                               push    168h
000A01BE [00428F76] 8b ce                                        mov     ecx, esi
000A01C0 [00428F78] b8 80 da 43 00                               mov     eax, 43DA80h
000A01C5 [00428F7D] ff d0                                        call    eax
000A01C7 [00428F7F] 5a                                           pop     edx
000A01C8 [00428F80] 69 db 68 01 00 00                            imul    ebx, 168h
000A01CE [00428F86] 03 d3                                        add     edx, ebx
000A01D0 [00428F88] 2b d0                                        sub     edx, eax
000A01D2 [00428F8A] 39 56 18                                     cmp     [esi+18h], edx
000A01D5 [00428F8D] 7d 02                                        jge     short near ptr unk_428F91 ; game-relative-target=0x000A01D9
000A01D7 [00428F8F] 33 c0                                        xor     eax, eax
000A01D9 [00428F91] 5b                                           pop     ebx
000A01DA [00428F92] 5e                                           pop     esi
000A01DB [00428F93] c3                                           retn
