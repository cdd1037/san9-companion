; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00428A30; baseline game VA=0x000A7738; size=152
; Relative branch annotations use the baseline game destination.
000A7738 [00428A30] b8 90 fe 47 00                               mov     eax, 47FE90h
000A773D [00428A35] ff d0                                        call    eax
000A773F [00428A37] 57                                           push    edi
000A7740 [00428A38] 83 ec 20                                     sub     esp, 20h ; ' '
000A7743 [00428A3B] 8b cc                                        mov     ecx, esp
000A7745 [00428A3D] b8 70 d7 46 00                               mov     eax, 46D770h
000A774A [00428A42] ff d0                                        call    eax
000A774C [00428A44] 8b cc                                        mov     ecx, esp
000A774E [00428A46] b8 30 f2 46 00                               mov     eax, 46F230h
000A7753 [00428A4B] ff d0                                        call    eax
000A7755 [00428A4D] 8b cc                                        mov     ecx, esp
000A7757 [00428A4F] 6a 00                                        push    0
000A7759 [00428A51] 6a 7b                                        push    7Bh ; '{'
000A775B [00428A53] b8 40 f6 46 00                               mov     eax, 46F640h
000A7760 [00428A58] ff d0                                        call    eax
000A7762 [00428A5A] 8b 7c 24 04                                  mov     edi, [esp+4]
000A7766 [00428A5E] 85 ff                                        test    edi, edi
000A7768 [00428A60] 74 57                                        jz      short near ptr unk_428AB9 ; game-relative-target=0x000A77C1
000A776A [00428A62] 8b 77 08                                     mov     esi, [edi+8]
000A776D [00428A65] 8b 8e cc 00 00 00                            mov     ecx, [esi+0CCh]
000A7773 [00428A6B] 85 c9                                        test    ecx, ecx
000A7775 [00428A6D] 74 44                                        jz      short near ptr unk_428AB3 ; game-relative-target=0x000A77BB
000A7777 [00428A6F] 8b 81 b8 00 00 00                            mov     eax, [ecx+0B8h]
000A777D [00428A75] f6 40 34 01                                  test    byte ptr [eax+34h], 1
000A7781 [00428A79] 75 38                                        jnz     short near ptr unk_428AB3 ; game-relative-target=0x000A77BB
000A7783 [00428A7B] b8 90 01 0a 00                               mov     eax, 0A0190h
000A7788 [00428A80] ff d0                                        call    eax
000A778A [00428A82] 85 c0                                        test    eax, eax
000A778C [00428A84] 74 2d                                        jz      short near ptr unk_428AB3 ; game-relative-target=0x000A77BB
000A778E [00428A86] 8b ce                                        mov     ecx, esi
000A7790 [00428A88] b8 c0 61 43 00                               mov     eax, 4361C0h
000A7795 [00428A8D] ff d0                                        call    eax
000A7797 [00428A8F] 8b 96 88 00 00 00                            mov     edx, [esi+88h]
000A779D [00428A95] 03 96 c0 01 00 00                            add     edx, [esi+1C0h]
000A77A3 [00428A9B] 33 c9                                        xor     ecx, ecx
000A77A5 [00428A9D] 3b d0                                        cmp     edx, eax
000A77A7 [00428A9F] 7e 06                                        jle     short near ptr unk_428AA7 ; game-relative-target=0x000A77AF
000A77A9 [00428AA1] 8b ca                                        mov     ecx, edx
000A77AB [00428AA3] 8b d0                                        mov     edx, eax
000A77AD [00428AA5] 2b c8                                        sub     ecx, eax
000A77AF [00428AA7] 89 96 88 00 00 00                            mov     [esi+88h], edx
000A77B5 [00428AAD] 89 8e c0 01 00 00                            mov     [esi+1C0h], ecx
000A77BB [00428AB3] 8b 3f                                        mov     edi, [edi]
000A77BD [00428AB5] 85 ff                                        test    edi, edi
000A77BF [00428AB7] 75 a9                                        jnz     short near ptr unk_428A62 ; game-relative-target=0x000A776A
000A77C1 [00428AB9] 8b cc                                        mov     ecx, esp
000A77C3 [00428ABB] b8 90 d7 46 00                               mov     eax, 46D790h
000A77C8 [00428AC0] ff d0                                        call    eax
000A77CA [00428AC2] 83 c4 20                                     add     esp, 20h ; ' '
000A77CD [00428AC5] 5f                                           pop     edi
000A77CE [00428AC6] 5e                                           pop     esi
000A77CF [00428AC7] c3                                           retn
