; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042C7D4; baseline game VA=0x000A9990; size=190
; Relative branch annotations use the baseline game destination.
000A9990 [0042C7D4] 8b 44 24 04                                  mov     eax, [esp+4]
000A9994 [0042C7D8] 8b 10                                        mov     edx, [eax]
000A9996 [0042C7DA] 33 c0                                        xor     eax, eax
000A9998 [0042C7DC] f6 42 34 01                                  test    byte ptr [edx+34h], 1
000A999C [0042C7E0] 0f 94 c0                                     setz    al
000A999F [0042C7E3] c3                                           retn
000A99A0 [0042C7E4] 8b 44 24 04                                  mov     eax, [esp+4]
000A99A4 [0042C7E8] 8b 10                                        mov     edx, [eax]
000A99A6 [0042C7EA] 33 c0                                        xor     eax, eax
000A99A8 [0042C7EC] f7 42 34 fe 01 00 00                         test    dword ptr [edx+34h], 1FEh
000A99AF [0042C7F3] 0f 94 c0                                     setz    al
000A99B2 [0042C7F6] c3                                           retn
000A99B3 [0042C7F7] 90                                           nop
000A99B4 [0042C7F8] 8b 96 98 02 00 00                            mov     edx, [esi+298h]
000A99BA [0042C7FE] 8b 92 6c 13 00 00                            mov     edx, [edx+136Ch]
000A99C0 [0042C804] 85 d2                                        test    edx, edx
000A99C2 [0042C806] 75 01                                        jnz     short near ptr dword_42C7D4+35h ; game-relative-target=0x000A99C5
000A99C4 [0042C808] c3                                           retn
000A99C5 [0042C809] 85 c0                                        test    eax, eax
000A99C7 [0042C80B] 75 2f                                        jnz     short near ptr dword_42C7D4+68h ; game-relative-target=0x000A99F8
000A99C9 [0042C80D] 8d 8e c4 01 00 00                            lea     ecx, [esi+1C4h]
000A99CF [0042C813] 8b 41 0c                                     mov     eax, [ecx+0Ch]
000A99D2 [0042C816] 85 c0                                        test    eax, eax
000A99D4 [0042C818] 74 0a                                        jz      short near ptr dword_42C7D4+50h ; game-relative-target=0x000A99E0
000A99D6 [0042C81A] 8b ce                                        mov     ecx, esi
000A99D8 [0042C81C] b8 b0 d8 51 00                               mov     eax, 51D8B0h
000A99DD [0042C821] ff d0                                        call    eax
000A99DF [0042C823] c3                                           retn
000A99E0 [0042C824] 6a 00                                        push    0
000A99E2 [0042C826] 68 a0 99 0a 00                               push    0A99A0h
000A99E7 [0042C82B] b8 00 f3 46 00                               mov     eax, 46F300h
000A99EC [0042C830] ff d0                                        call    eax
000A99EE [0042C832] 8b ce                                        mov     ecx, esi
000A99F0 [0042C834] b8 40 f2 51 00                               mov     eax, 51F240h
000A99F5 [0042C839] ff d0                                        call    eax
000A99F7 [0042C83B] c3                                           retn
000A99F8 [0042C83C] 8d 8e a4 01 00 00                            lea     ecx, [esi+1A4h]
000A99FE [0042C842] 8b 41 0c                                     mov     eax, [ecx+0Ch]
000A9A01 [0042C845] 85 c0                                        test    eax, eax
000A9A03 [0042C847] 74 0a                                        jz      short near ptr dword_42C7D4+7Fh ; game-relative-target=0x000A9A0F
000A9A05 [0042C849] 8b ce                                        mov     ecx, esi
000A9A07 [0042C84B] b8 20 d8 51 00                               mov     eax, 51D820h
000A9A0C [0042C850] ff d0                                        call    eax
000A9A0E [0042C852] c3                                           retn
000A9A0F [0042C853] 57                                           push    edi
000A9A10 [0042C854] 8b f9                                        mov     edi, ecx
000A9A12 [0042C856] 6a 00                                        push    0
000A9A14 [0042C858] 68 90 99 0a 00                               push    0A9990h
000A9A19 [0042C85D] b8 00 f3 46 00                               mov     eax, 46F300h
000A9A1E [0042C862] ff d0                                        call    eax
000A9A20 [0042C864] 85 c0                                        test    eax, eax
000A9A22 [0042C866] 74 1b                                        jz      short near ptr dword_42C7D4+0AFh ; game-relative-target=0x000A9A3F
000A9A24 [0042C868] 8b 96 8c 02 00 00                            mov     edx, [esi+28Ch]
000A9A2A [0042C86E] 33 c0                                        xor     eax, eax
000A9A2C [0042C870] 8b 7f 04                                     mov     edi, [edi+4]
000A9A2F [0042C873] 8b 4f 08                                     mov     ecx, [edi+8]
000A9A32 [0042C876] 0f b7 49 04                                  movzx   ecx, word ptr [ecx+4]
000A9A36 [0042C87A] 89 04 8a                                     mov     [edx+ecx*4], eax
000A9A39 [0042C87D] 8b 3f                                        mov     edi, [edi+0]
000A9A3B [0042C87F] 85 ff                                        test    edi, edi
000A9A3D [0042C881] 75 f0                                        jnz     short near ptr dword_42C7D4+9Fh ; game-relative-target=0x000A9A2F
000A9A3F [0042C883] 8d 56 38                                     lea     edx, [esi+38h]
000A9A42 [0042C886] 8b ce                                        mov     ecx, esi
000A9A44 [0042C888] 52                                           push    edx
000A9A45 [0042C889] b8 40 f1 51 00                               mov     eax, 51F140h
000A9A4A [0042C88E] ff d0                                        call    eax
000A9A4C [0042C890] 5f                                           pop     edi
000A9A4D [0042C891] c3                                           retn
