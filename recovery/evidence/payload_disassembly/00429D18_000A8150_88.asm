; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00429D18; baseline game VA=0x000A8150; size=136
; Relative branch annotations use the baseline game destination.
000A8150 [00429D18] 8d 85 b8 06 00 00                            lea     eax, [ebp+6B8h]
000A8156 [00429D1E] 50                                           push    eax
000A8157 [00429D1F] 8d 85 08 13 00 00                            lea     eax, [ebp+1308h]
000A815D [00429D25] 50                                           push    eax
000A815E [00429D26] 55                                           push    ebp
000A815F [00429D27] 68 f0 37 49 00                               push    4937F0h
000A8164 [00429D2C] 55                                           push    ebp
000A8165 [00429D2D] 8b ec                                        mov     ebp, esp
000A8167 [00429D2F] 56                                           push    esi
000A8168 [00429D30] 57                                           push    edi
000A8169 [00429D31] 53                                           push    ebx
000A816A [00429D32] 8b d9                                        mov     ebx, ecx
000A816C [00429D34] 8b 4d 10                                     mov     ecx, [ebp+10h]
000A816F [00429D37] 8b 71 04                                     mov     esi, [ecx+4]
000A8172 [00429D3A] bf 00 05 0a 00                               mov     edi, 0A0500h
000A8177 [00429D3F] 8b cf                                        mov     ecx, edi
000A8179 [00429D41] b8 90 82 0a 00                               mov     eax, 0A8290h
000A817E [00429D46] ff d0                                        call    eax
000A8180 [00429D48] ff 75 24                                     push    dword ptr [ebp+24h]
000A8183 [00429D4B] ff 75 20                                     push    dword ptr [ebp+20h]
000A8186 [00429D4E] ff 76 08                                     push    dword ptr [esi+8]
000A8189 [00429D51] 6a 00                                        push    0
000A818B [00429D53] 8b cb                                        mov     ecx, ebx
000A818D [00429D55] ff 55 04                                     call    dword ptr [ebp+4]
000A8190 [00429D58] 8b cb                                        mov     ecx, ebx
000A8192 [00429D5A] b8 80 64 48 00                               mov     eax, 486480h
000A8197 [00429D5F] ff d0                                        call    eax
000A8199 [00429D61] 3c 03                                        cmp     al, 3
000A819B [00429D63] 74 0c                                        jz      short loc_429D71 ; game-relative-target=0x000A81A9
000A819D [00429D65] ff 76 08                                     push    dword ptr [esi+8]
000A81A0 [00429D68] 8b cf                                        mov     ecx, edi
000A81A2 [00429D6A] b8 70 ef 46 00                               mov     eax, 46EF70h
000A81A7 [00429D6F] ff d0                                        call    eax
000A81A9 [00429D71] 8b 36                                        mov     esi, [esi]
000A81AB [00429D73] 85 f6                                        test    esi, esi
000A81AD [00429D75] 75 d1                                        jnz     short loc_429D48 ; game-relative-target=0x000A8180
000A81AF [00429D77] 39 77 0c                                     cmp     [edi+0Ch], esi
000A81B2 [00429D7A] 74 1b                                        jz      short loc_429D97 ; game-relative-target=0x000A81CF
000A81B4 [00429D7C] 8b 4f 04                                     mov     ecx, [edi+4]
000A81B7 [00429D7F] 8b 41 08                                     mov     eax, [ecx+8]
000A81BA [00429D82] 8b 55 0c                                     mov     edx, [ebp+0Ch]
000A81BD [00429D85] 89 02                                        mov     [edx], eax
000A81BF [00429D87] 89 45 1c                                     mov     [ebp+1Ch], eax
000A81C2 [00429D8A] 8b 4d 08                                     mov     ecx, [ebp+8]
000A81C5 [00429D8D] 8b 01                                        mov     eax, [ecx]
000A81C7 [00429D8F] 6a 01                                        push    1
000A81C9 [00429D91] ff 90 ec 00 00 00                            call    dword ptr [eax+0ECh]
000A81CF [00429D97] 8b cb                                        mov     ecx, ebx
000A81D1 [00429D99] 5b                                           pop     ebx
000A81D2 [00429D9A] 5f                                           pop     edi
000A81D3 [00429D9B] 5e                                           pop     esi
000A81D4 [00429D9C] 5d                                           pop     ebp
000A81D5 [00429D9D] c2 0c 00                                     retn    0Ch
