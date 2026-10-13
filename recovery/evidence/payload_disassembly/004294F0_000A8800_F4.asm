; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004294F0; baseline game VA=0x000A8800; size=244
; Relative branch annotations use the baseline game destination.
000A8800 [004294F0] 8b 54 24 04                                  mov     edx, [esp+4]
000A8804 [004294F4] 8b 0a                                        mov     ecx, [edx]
000A8806 [004294F6] 8b 81 ea 00 00 00                            mov     eax, [ecx+0EAh]
000A880C [004294FC] 83 e0 1f                                     and     eax, 1Fh
000A880F [004294FF] c3                                           retn
000A8810 [00429500] 68 d0 6e 56 00                               push    566ED0h
000A8815 [00429505] 8d 4c 24 4c                                  lea     ecx, [esp+4Ch]
000A8819 [00429509] 8b 41 0c                                     mov     eax, [ecx+0Ch]
000A881C [0042950C] 83 e8 04                                     sub     eax, 4
000A881F [0042950F] 83 f8 01                                     cmp     eax, 1
000A8822 [00429512] 76 01                                        jbe     short near ptr unk_429515 ; game-relative-target=0x000A8825
000A8824 [00429514] c3                                           retn
000A8825 [00429515] 57                                           push    edi
000A8826 [00429516] 53                                           push    ebx
000A8827 [00429517] 55                                           push    ebp
000A8828 [00429518] 33 db                                        xor     ebx, ebx
000A882A [0042951A] 6a 01                                        push    1
000A882C [0042951C] 68 00 88 0a 00                               push    0A8800h
000A8831 [00429521] b8 10 f6 46 00                               mov     eax, 46F610h
000A8836 [00429526] ff d0                                        call    eax
000A8838 [00429528] 8b 7c 24 5c                                  mov     edi, [esp+5Ch]
000A883C [0042952C] 8b 46 04                                     mov     eax, [esi+4]
000A883F [0042952F] 25 ff 03 00 00                               and     eax, 3FFh
000A8844 [00429534] c1 e0 0d                                     shl     eax, 0Dh
000A8847 [00429537] 0f b6 6e 68                                  movzx   ebp, byte ptr [esi+68h]
000A884B [0042953B] f7 dd                                        neg     ebp
000A884D [0042953D] c1 e5 17                                     shl     ebp, 17h
000A8850 [00429540] 09 c5                                        or      ebp, eax
000A8852 [00429542] 39 77 08                                     cmp     [edi+8], esi
000A8855 [00429545] 75 62                                        jnz     short near ptr unk_4295A9 ; game-relative-target=0x000A88B9
000A8857 [00429547] 8b 4c 24 34                                  mov     ecx, [esp+34h]
000A885B [0042954B] b8 ad 8b db 68                               mov     eax, 68DB8BADh
000A8860 [00429550] f7 69 30                                     imul    dword ptr [ecx+30h]
000A8863 [00429553] c1 fa 0b                                     sar     edx, 0Bh
000A8866 [00429556] 8b c2                                        mov     eax, edx
000A8868 [00429558] c1 ea 1f                                     shr     edx, 1Fh
000A886B [0042955B] 03 d0                                        add     edx, eax
000A886D [0042955D] 4a                                           dec     edx
000A886E [0042955E] 83 fa 07                                     cmp     edx, 7
000A8871 [00429561] 76 02                                        jbe     short near ptr unk_429565 ; game-relative-target=0x000A8875
000A8873 [00429563] 33 d2                                        xor     edx, edx
000A8875 [00429565] 80 ca 08                                     or      dl, 8
000A8878 [00429568] c1 e2 0c                                     shl     edx, 0Ch
000A887B [0042956B] 8b 41 70                                     mov     eax, [ecx+70h]
000A887E [0042956E] 8a 40 04                                     mov     al, [eax+4]
000A8881 [00429571] 2c 14                                        sub     al, 14h
000A8883 [00429573] 3c 06                                        cmp     al, 6
000A8885 [00429575] 76 02                                        jbe     short near ptr unk_429579 ; game-relative-target=0x000A8889
000A8887 [00429577] 32 c0                                        xor     al, al
000A8889 [00429579] d0 e0                                        shl     al, 1
000A888B [0042957B] 08 c6                                        or      dh, al
000A888D [0042957D] 8b 49 6c                                     mov     ecx, [ecx+6Ch]
000A8890 [00429580] 8b 41 04                                     mov     eax, [ecx+4]
000A8893 [00429583] 83 e0 1f                                     and     eax, 1Fh
000A8896 [00429586] c1 e0 04                                     shl     eax, 4
000A8899 [00429589] 09 d0                                        or      eax, edx
000A889B [0042958B] 8b 54 24 5c                                  mov     edx, [esp+5Ch]
000A889F [0042958F] 8b 52 08                                     mov     edx, [edx+8]
000A88A2 [00429592] 8a 92 ea 00 00 00                            mov     dl, [edx+0EAh]
000A88A8 [00429598] 80 e2 1f                                     and     dl, 1Fh
000A88AB [0042959B] 3a 91 80 00 00 00                            cmp     dl, [ecx+80h]
000A88B1 [004295A1] 74 02                                        jz      short near ptr unk_4295A5 ; game-relative-target=0x000A88B5
000A88B3 [004295A3] 0c 08                                        or      al, 8
000A88B5 [004295A5] 33 d2                                        xor     edx, edx
000A88B7 [004295A7] eb 11                                        jmp     short near ptr unk_4295BA ; game-relative-target=0x000A88CA
000A88B9 [004295A9] 8b 46 04                                     mov     eax, [esi+4]
000A88BC [004295AC] 25 ff 03 00 00                               and     eax, 3FFh
000A88C1 [004295B1] c1 e0 04                                     shl     eax, 4
000A88C4 [004295B4] 8d 53 01                                     lea     edx, [ebx+1]
000A88C7 [004295B7] c1 e2 0a                                     shl     edx, 0Ah
000A88CA [004295BA] 8b 4f 08                                     mov     ecx, [edi+8]
000A88CD [004295BD] 81 c1 a0 00 00 00                            add     ecx, 0A0h
000A88D3 [004295C3] 09 d8                                        or      eax, ebx
000A88D5 [004295C5] 89 41 64                                     mov     [ecx+64h], eax
000A88D8 [004295C8] 8b 01                                        mov     eax, [ecx]
000A88DA [004295CA] 25 ff 03 00 00                               and     eax, 3FFh
000A88DF [004295CF] 09 d0                                        or      eax, edx
000A88E1 [004295D1] 09 e8                                        or      eax, ebp
000A88E3 [004295D3] 89 01                                        mov     [ecx], eax
000A88E5 [004295D5] 43                                           inc     ebx
000A88E6 [004295D6] 8b 3f                                        mov     edi, [edi]
000A88E8 [004295D8] 85 ff                                        test    edi, edi
000A88EA [004295DA] 0f 85 62 ff ff ff                            jnz     near ptr unk_429542 ; game-relative-target=0x000A8852
000A88F0 [004295E0] 5d                                           pop     ebp
000A88F1 [004295E1] 5b                                           pop     ebx
000A88F2 [004295E2] 5f                                           pop     edi
000A88F3 [004295E3] c3                                           retn
