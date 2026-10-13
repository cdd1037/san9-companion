; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00429798; baseline game VA=0x000A7F00; size=244
; Relative branch annotations use the baseline game destination.
000A7F00 [00429798] 57                                           push    edi
000A7F01 [00429799] 8b 7c 24 08                                  mov     edi, [esp+8]
000A7F05 [0042979D] 8b 0f                                        mov     ecx, [edi]
000A7F07 [0042979F] 8b 91 f4 00 00 00                            mov     edx, [ecx+0F4h]
000A7F0D [004297A5] 33 c0                                        xor     eax, eax
000A7F0F [004297A7] f6 42 20 08                                  test    byte ptr [edx+20h], 8
000A7F13 [004297AB] 75 11                                        jnz     short near ptr unk_4297BE ; game-relative-target=0x000A7F26
000A7F15 [004297AD] b8 70 7e 0a 00                               mov     eax, 0A7E70h
000A7F1A [004297B2] ff d0                                        call    eax
000A7F1C [004297B4] 33 d2                                        xor     edx, edx
000A7F1E [004297B6] 3b 47 04                                     cmp     eax, [edi+4]
000A7F21 [004297B9] 0f 94 c2                                     setz    dl
000A7F24 [004297BC] 8b c2                                        mov     eax, edx
000A7F26 [004297BE] 5f                                           pop     edi
000A7F27 [004297BF] c3                                           retn
000A7F28 [004297C0] 68 40 e2 44 00                               push    44E240h
000A7F2D [004297C5] b8 70 7e 0a 00                               mov     eax, 0A7E70h
000A7F32 [004297CA] ff d0                                        call    eax
000A7F34 [004297CC] 85 c0                                        test    eax, eax
000A7F36 [004297CE] 7d 01                                        jge     short near ptr unk_4297D1 ; game-relative-target=0x000A7F39
000A7F38 [004297D0] c3                                           retn
000A7F39 [004297D1] 53                                           push    ebx
000A7F3A [004297D2] 55                                           push    ebp
000A7F3B [004297D3] 8b d8                                        mov     ebx, eax
000A7F3D [004297D5] 8b 01                                        mov     eax, [ecx]
000A7F3F [004297D7] ff 50 3c                                     call    dword ptr [eax+3Ch]
000A7F42 [004297DA] 85 c0                                        test    eax, eax
000A7F44 [004297DC] 74 6d                                        jz      short near ptr unk_42984B ; game-relative-target=0x000A7FB3
000A7F46 [004297DE] 80 be 84 00 00 00 04                         cmp     byte ptr [esi+84h], 4
000A7F4D [004297E5] 73 64                                        jnb     short near ptr unk_42984B ; game-relative-target=0x000A7FB3
000A7F4F [004297E7] 8b 86 f4 00 00 00                            mov     eax, [esi+0F4h]
000A7F55 [004297ED] f6 40 20 08                                  test    byte ptr [eax+20h], 8
000A7F59 [004297F1] 75 6b                                        jnz     short near ptr unk_42985E ; game-relative-target=0x000A7FC6
000A7F5B [004297F3] 8b 68 64                                     mov     ebp, [eax+64h]
000A7F5E [004297F6] 83 ec 40                                     sub     esp, 40h ; '@'
000A7F61 [004297F9] 8b cc                                        mov     ecx, esp
000A7F63 [004297FB] b8 f0 0d 47 00                               mov     eax, 470DF0h
000A7F68 [00429800] ff d0                                        call    eax
000A7F6A [00429802] 8d 4c 24 20                                  lea     ecx, [esp+20h]
000A7F6E [00429806] b8 f0 0d 47 00                               mov     eax, 470DF0h
000A7F73 [0042980B] ff d0                                        call    eax
000A7F75 [0042980D] 8b cd                                        mov     ecx, ebp
000A7F77 [0042980F] 54                                           push    esp
000A7F78 [00429810] b8 20 6c 43 00                               mov     eax, 436C20h
000A7F7D [00429815] ff d0                                        call    eax
000A7F7F [00429817] 8b d4                                        mov     edx, esp
000A7F81 [00429819] 6a 00                                        push    0
000A7F83 [0042981B] 53                                           push    ebx
000A7F84 [0042981C] 68 00 7f 0a 00                               push    0A7F00h
000A7F89 [00429821] 52                                           push    edx
000A7F8A [00429822] 8d 4c 24 30                                  lea     ecx, [esp+30h]
000A7F8E [00429826] b8 f0 f3 46 00                               mov     eax, 46F3F0h
000A7F93 [0042982B] ff d0                                        call    eax
000A7F95 [0042982D] 8b e8                                        mov     ebp, eax
000A7F97 [0042982F] 8d 4c 24 20                                  lea     ecx, [esp+20h]
000A7F9B [00429833] b8 10 0e 47 00                               mov     eax, 470E10h
000A7FA0 [00429838] ff d0                                        call    eax
000A7FA2 [0042983A] 8b cc                                        mov     ecx, esp
000A7FA4 [0042983C] b8 10 0e 47 00                               mov     eax, 470E10h
000A7FA9 [00429841] ff d0                                        call    eax
000A7FAB [00429843] 83 c4 40                                     add     esp, 40h ; '@'
000A7FAE [00429846] 83 fd 03                                     cmp     ebp, 3
000A7FB1 [00429849] 7d 13                                        jge     short near ptr unk_42985E ; game-relative-target=0x000A7FC6
000A7FB3 [0042984B] 33 c0                                        xor     eax, eax
000A7FB5 [0042984D] 8d 8e a0 00 00 00                            lea     ecx, [esi+0A0h]
000A7FBB [00429853] 89 41 64                                     mov     [ecx+64h], eax
000A7FBE [00429856] 81 21 ff 03 00 00                            and     dword ptr [ecx], 3FFh
000A7FC4 [0042985C] eb 29                                        jmp     short near ptr unk_429887 ; game-relative-target=0x000A7FEF
000A7FC6 [0042985E] 53                                           push    ebx
000A7FC7 [0042985F] b8 b0 31 45 00                               mov     eax, 4531B0h
000A7FCC [00429864] ff d0                                        call    eax
000A7FCE [00429866] 83 c4 04                                     add     esp, 4
000A7FD1 [00429869] 85 c0                                        test    eax, eax
000A7FD3 [0042986B] 74 1a                                        jz      short near ptr unk_429887 ; game-relative-target=0x000A7FEF
000A7FD5 [0042986D] 0f b6 50 68                                  movzx   edx, byte ptr [eax+68h]
000A7FD9 [00429871] f7 da                                        neg     edx
000A7FDB [00429873] c1 e2 17                                     shl     edx, 17h
000A7FDE [00429876] 8d 8e a0 00 00 00                            lea     ecx, [esi+0A0h]
000A7FE4 [0042987C] 8b 01                                        mov     eax, [ecx]
000A7FE6 [0042987E] 25 ff ff 7f 00                               and     eax, 7FFFFFh
000A7FEB [00429883] 09 d0                                        or      eax, edx
000A7FED [00429885] 89 01                                        mov     [ecx], eax
000A7FEF [00429887] 5d                                           pop     ebp
000A7FF0 [00429888] 5b                                           pop     ebx
000A7FF1 [00429889] 8b ce                                        mov     ecx, esi
000A7FF3 [0042988B] c3                                           retn
