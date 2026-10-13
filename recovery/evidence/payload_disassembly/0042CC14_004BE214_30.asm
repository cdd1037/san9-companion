; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042CC14; baseline game VA=0x004BE214; size=48
; Relative branch annotations use the baseline game destination.
004BE214 [0042CC14] 83 e8 08                                     sub     eax, 8
004BE217 [0042CC17] e8 c1 c8 fa ff                               call    near ptr 3D94DDh ; game-relative-target=0x0046AADD
004BE21C [0042CC1C] 85 c0                                        test    eax, eax
004BE21E [0042CC1E] 75 01                                        jnz     short near ptr unk_42CC21 ; game-relative-target=0x004BE221
004BE220 [0042CC20] c3                                           retn
004BE221 [0042CC21] 56                                           push    esi
004BE222 [0042CC22] 57                                           push    edi
004BE223 [0042CC23] 8b f0                                        mov     esi, eax
004BE225 [0042CC25] 8b ce                                        mov     ecx, esi
004BE227 [0042CC27] e8 d4 94 be ff                               call    near ptr 16100h ; game-relative-target=0x000A7700
004BE22C [0042CC2C] b9 88 13 00 00                               mov     ecx, 1388h
004BE231 [0042CC31] 99                                           cdq
004BE232 [0042CC32] f7 f9                                        idiv    ecx
004BE234 [0042CC34] 8b f8                                        mov     edi, eax
004BE236 [0042CC36] 8b ce                                        mov     ecx, esi
004BE238 [0042CC38] e8 b3 15 f8 ff                               call    near ptr 3AE1F0h ; game-relative-target=0x0043F7F0
004BE23D [0042CC3D] 03 f8                                        add     edi, eax
004BE23F [0042CC3F] 8d 49 00                                     lea     ecx, [ecx+0]
004BE242 [0042CC42] 8b ce                                        mov     ecx, esi
