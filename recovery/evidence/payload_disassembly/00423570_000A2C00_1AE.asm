; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00423570; baseline game VA=0x000A2C00; size=430
; Relative branch annotations use the baseline game destination.
000A2C00 [00423570] 8b 45 38                                     mov     eax, [ebp+38h]
000A2C03 [00423573] f6 40 34 04                                  test    byte ptr [eax+34h], 4
000A2C07 [00423577] 74 06                                        jz      short near ptr unk_42357F ; game-relative-target=0x000A2C0F
000A2C09 [00423579] 68 90 31 47 00                               push    473190h
000A2C0E [0042357E] c3                                           retn
000A2C0F [0042357F] 55                                           push    ebp
000A2C10 [00423580] 8b 8d 3c 08 00 00                            mov     ecx, [ebp+83Ch]
000A2C16 [00423586] 33 ed                                        xor     ebp, ebp
000A2C18 [00423588] 85 c9                                        test    ecx, ecx
000A2C1A [0042358A] 74 0a                                        jz      short near ptr unk_423596 ; game-relative-target=0x000A2C26
000A2C1C [0042358C] 3b 79 08                                     cmp     edi, [ecx+8]
000A2C1F [0042358F] 8b 09                                        mov     ecx, [ecx]
000A2C21 [00423591] 75 f5                                        jnz     short near ptr unk_423588 ; game-relative-target=0x000A2C18
000A2C23 [00423593] 45                                           inc     ebp
000A2C24 [00423594] eb f2                                        jmp     short near ptr unk_423588 ; game-relative-target=0x000A2C18
000A2C26 [00423596] 45                                           inc     ebp
000A2C27 [00423597] 39 8b 84 00 00 00                            cmp     [ebx+84h], ecx
000A2C2D [0042359D] 75 3c                                        jnz     short near ptr unk_4235DB ; game-relative-target=0x000A2C6B
000A2C2F [0042359F] 8b 4c 24 08                                  mov     ecx, [esp+8]
000A2C33 [004235A3] 8b 41 04                                     mov     eax, [ecx+4]
000A2C36 [004235A6] 85 c0                                        test    eax, eax
000A2C38 [004235A8] 74 31                                        jz      short near ptr unk_4235DB ; game-relative-target=0x000A2C6B
000A2C3A [004235AA] 8b 50 08                                     mov     edx, [eax+8]
000A2C3D [004235AD] 8b 42 68                                     mov     eax, [edx+68h]
000A2C40 [004235B0] 2b 43 68                                     sub     eax, [ebx+68h]
000A2C43 [004235B3] 83 f8 0a                                     cmp     eax, 0Ah
000A2C46 [004235B6] 7c 23                                        jl      short near ptr unk_4235DB ; game-relative-target=0x000A2C6B
000A2C48 [004235B8] b8 10 82 51 00                               mov     eax, 518210h
000A2C4D [004235BD] ff d0                                        call    eax
000A2C4F [004235BF] 8b d8                                        mov     ebx, eax
000A2C51 [004235C1] 8b ce                                        mov     ecx, esi
000A2C53 [004235C3] b8 e0 80 51 00                               mov     eax, 5180E0h
000A2C58 [004235C8] ff d0                                        call    eax
000A2C5A [004235CA] 53                                           push    ebx
000A2C5B [004235CB] 8b ce                                        mov     ecx, esi
000A2C5D [004235CD] b8 70 82 51 00                               mov     eax, 518270h
000A2C62 [004235D2] ff d0                                        call    eax
000A2C64 [004235D4] 8b 4c 24 10                                  mov     ecx, [esp+10h]
000A2C68 [004235D8] 89 59 0c                                     mov     [ecx+0Ch], ebx
000A2C6B [004235DB] 57                                           push    edi
000A2C6C [004235DC] 8b cf                                        mov     ecx, edi
000A2C6E [004235DE] b8 d0 53 43 00                               mov     eax, 4353D0h
000A2C73 [004235E3] ff d0                                        call    eax
000A2C75 [004235E5] 8b 4c 24 0c                                  mov     ecx, [esp+0Ch]
000A2C79 [004235E9] 8b 79 0c                                     mov     edi, [ecx+0Ch]
000A2C7C [004235EC] 3c 00                                        cmp     al, 0
000A2C7E [004235EE] 74 05                                        jz      short near ptr unk_4235F5 ; game-relative-target=0x000A2C85
000A2C80 [004235F0] 3c 02                                        cmp     al, 2
000A2C82 [004235F2] 74 01                                        jz      short near ptr unk_4235F5 ; game-relative-target=0x000A2C85
000A2C84 [004235F4] 47                                           inc     edi
000A2C85 [004235F5] 8b cb                                        mov     ecx, ebx
000A2C87 [004235F7] b8 00 18 0a 00                               mov     eax, 0A1800h
000A2C8C [004235FC] ff d0                                        call    eax
000A2C8E [004235FE] 8b c8                                        mov     ecx, eax
000A2C90 [00423600] 8b c7                                        mov     eax, edi
000A2C92 [00423602] 2b c5                                        sub     eax, ebp
000A2C94 [00423604] 0f 8e 0f 01 00 00                            jle     near ptr unk_423719 ; game-relative-target=0x000A2DA9
000A2C9A [0042360A] 99                                           cdq
000A2C9B [0042360B] f7 f5                                        div     ebp
000A2C9D [0042360D] 83 7e c4 0a                                  cmp     dword ptr [esi-3Ch], 0Ah
000A2CA1 [00423611] 75 0c                                        jnz     short near ptr unk_42361F ; game-relative-target=0x000A2CAF
000A2CA3 [00423613] 83 f8 01                                     cmp     eax, 1
000A2CA6 [00423616] 7e 20                                        jle     short near ptr unk_423638 ; game-relative-target=0x000A2CC8
000A2CA8 [00423618] b8 01 00 00 00                               mov     eax, 1
000A2CAD [0042361D] eb 19                                        jmp     short near ptr unk_423638 ; game-relative-target=0x000A2CC8
000A2CAF [0042361F] 3b c1                                        cmp     eax, ecx
000A2CB1 [00423621] 7f 05                                        jg      short near ptr unk_423628 ; game-relative-target=0x000A2CB8
000A2CB3 [00423623] 85 d2                                        test    edx, edx
000A2CB5 [00423625] 74 01                                        jz      short near ptr unk_423628 ; game-relative-target=0x000A2CB8
000A2CB7 [00423627] 40                                           inc     eax
000A2CB8 [00423628] ba 03 00 00 00                               mov     edx, 3
000A2CBD [0042362D] 3b ca                                        cmp     ecx, edx
000A2CBF [0042362F] 7e 01                                        jle     short near ptr unk_423632 ; game-relative-target=0x000A2CC2
000A2CC1 [00423631] 42                                           inc     edx
000A2CC2 [00423632] 3b c2                                        cmp     eax, edx
000A2CC4 [00423634] 7e 02                                        jle     short near ptr unk_423638 ; game-relative-target=0x000A2CC8
000A2CC6 [00423636] 8b c2                                        mov     eax, edx
000A2CC8 [00423638] 85 c0                                        test    eax, eax
000A2CCA [0042363A] 0f 8e d9 00 00 00                            jle     near ptr unk_423719 ; game-relative-target=0x000A2DA9
000A2CD0 [00423640] 56                                           push    esi
000A2CD1 [00423641] 50                                           push    eax
000A2CD2 [00423642] 55                                           push    ebp
000A2CD3 [00423643] 33 ff                                        xor     edi, edi
000A2CD5 [00423645] 8b 74 24 18                                  mov     esi, [esp+18h]
000A2CD9 [00423649] c7 44 24 1c 90 64 0a 00                      mov     dword ptr [esp+1Ch], 0A6490h
000A2CE1 [00423651] 4d                                           dec     ebp
000A2CE2 [00423652] 74 16                                        jz      short near ptr unk_42366A ; game-relative-target=0x000A2CFA
000A2CE4 [00423654] 8b ce                                        mov     ecx, esi
000A2CE6 [00423656] b8 10 82 51 00                               mov     eax, 518210h
000A2CEB [0042365B] ff d0                                        call    eax
000A2CED [0042365D] 8b c8                                        mov     ecx, eax
000A2CEF [0042365F] ff 54 24 1c                                  call    dword ptr [esp+1Ch]
000A2CF3 [00423663] 3c 02                                        cmp     al, 2
000A2CF5 [00423665] 7c ea                                        jl      short near ptr unk_423651 ; game-relative-target=0x000A2CE1
000A2CF7 [00423667] 47                                           inc     edi
000A2CF8 [00423668] eb e7                                        jmp     short near ptr unk_423651 ; game-relative-target=0x000A2CE1
000A2CFA [0042366A] 53                                           push    ebx
000A2CFB [0042366B] 8b 5e 04                                     mov     ebx, [esi+4]
000A2CFE [0042366E] 85 db                                        test    ebx, ebx
000A2D00 [00423670] 74 17                                        jz      short near ptr unk_423689 ; game-relative-target=0x000A2D19
000A2D02 [00423672] 8b 4b 08                                     mov     ecx, [ebx+8]
000A2D05 [00423675] ff 54 24 20                                  call    dword ptr [esp+20h]
000A2D09 [00423679] 8b 4b 08                                     mov     ecx, [ebx+8]
000A2D0C [0042367C] 88 41 0c                                     mov     [ecx+0Ch], al
000A2D0F [0042367F] 8b 1b                                        mov     ebx, [ebx]
000A2D11 [00423681] 85 c0                                        test    eax, eax
000A2D13 [00423683] 74 e9                                        jz      short near ptr unk_42366E ; game-relative-target=0x000A2CFE
000A2D15 [00423685] 47                                           inc     edi
000A2D16 [00423686] 45                                           inc     ebp
000A2D17 [00423687] eb e5                                        jmp     short near ptr unk_42366E ; game-relative-target=0x000A2CFE
000A2D19 [00423689] 59                                           pop     ecx
000A2D1A [0042368A] ff 54 24 1c                                  call    dword ptr [esp+1Ch]
000A2D1E [0042368E] 3c 02                                        cmp     al, 2
000A2D20 [00423690] 7c 02                                        jl      short near ptr unk_423694 ; game-relative-target=0x000A2D24
000A2D22 [00423692] 47                                           inc     edi
000A2D23 [00423693] 43                                           inc     ebx
000A2D24 [00423694] 59                                           pop     ecx
000A2D25 [00423695] 3b f9                                        cmp     edi, ecx
000A2D27 [00423697] 7c 16                                        jl      short near ptr unk_4236AF ; game-relative-target=0x000A2D3F
000A2D29 [00423699] 2b 6e 0c                                     sub     ebp, [esi+0Ch]
000A2D2C [0042369C] f7 dd                                        neg     ebp
000A2D2E [0042369E] 8b d3                                        mov     edx, ebx
000A2D30 [004236A0] 5b                                           pop     ebx
000A2D31 [004236A1] 8d 54 1a ff                                  lea     edx, [edx+ebx-1]
000A2D35 [004236A5] 3b ea                                        cmp     ebp, edx
000A2D37 [004236A7] 7e 02                                        jle     short near ptr unk_4236AB ; game-relative-target=0x000A2D3B
000A2D39 [004236A9] 8b ea                                        mov     ebp, edx
000A2D3B [004236AB] 2b dd                                        sub     ebx, ebp
000A2D3D [004236AD] eb 0e                                        jmp     short near ptr unk_4236BD ; game-relative-target=0x000A2D4D
000A2D3F [004236AF] 85 db                                        test    ebx, ebx
000A2D41 [004236B1] b3 00                                        mov     bl, 0
000A2D43 [004236B3] 75 05                                        jnz     short near ptr unk_4236BA ; game-relative-target=0x000A2D4A
000A2D45 [004236B5] 85 ed                                        test    ebp, ebp
000A2D47 [004236B7] 0f 95 c3                                     setnz   bl
000A2D4A [004236BA] 5d                                           pop     ebp
000A2D4B [004236BB] 2b eb                                        sub     ebp, ebx
000A2D4D [004236BD] 5f                                           pop     edi
000A2D4E [004236BE] 6a 01                                        push    1
000A2D50 [004236C0] ff 74 24 18                                  push    dword ptr [esp+18h]
000A2D54 [004236C4] 68 50 1c 47 00                               push    471C50h
000A2D59 [004236C9] 8b ce                                        mov     ecx, esi
000A2D5B [004236CB] b8 30 f4 46 00                               mov     eax, 46F430h
000A2D60 [004236D0] ff d0                                        call    eax
000A2D62 [004236D2] 8b 76 04                                     mov     esi, [esi+4]
000A2D65 [004236D5] eb 15                                        jmp     short near ptr unk_4236EC ; game-relative-target=0x000A2D7C
000A2D67 [004236D7] cc                                           int     3
000A2D68 [004236D8] 83 79 68 50                                  cmp     dword ptr [ecx+68h], 50h ; 'P'
000A2D6C [004236DC] 7d 35                                        jge     short near ptr unk_423713 ; game-relative-target=0x000A2DA3
000A2D6E [004236DE] b8 00 d7 44 00                               mov     eax, 44D700h
000A2D73 [004236E3] ff d0                                        call    eax
000A2D75 [004236E5] 3d 20 4e 00 00                               cmp     eax, 4E20h
000A2D7A [004236EA] 7d 27                                        jge     short near ptr unk_423713 ; game-relative-target=0x000A2DA3
000A2D7C [004236EC] 8b 4e 08                                     mov     ecx, [esi+8]
000A2D7F [004236EF] 80 79 0c 00                                  cmp     byte ptr [ecx+0Ch], 0
000A2D83 [004236F3] 74 07                                        jz      short near ptr unk_4236FC ; game-relative-target=0x000A2D8C
000A2D85 [004236F5] 85 db                                        test    ebx, ebx
000A2D87 [004236F7] 7e 12                                        jle     short near ptr unk_42370B ; game-relative-target=0x000A2D9B
000A2D89 [004236F9] 4b                                           dec     ebx
000A2D8A [004236FA] eb 05                                        jmp     short near ptr unk_423701 ; game-relative-target=0x000A2D91
000A2D8C [004236FC] 85 ed                                        test    ebp, ebp
000A2D8E [004236FE] 7e 0b                                        jle     short near ptr unk_42370B ; game-relative-target=0x000A2D9B
000A2D90 [00423700] 4d                                           dec     ebp
000A2D91 [00423701] 51                                           push    ecx
000A2D92 [00423702] 8b cf                                        mov     ecx, edi
000A2D94 [00423704] b8 70 82 51 00                               mov     eax, 518270h
000A2D99 [00423709] ff d0                                        call    eax
000A2D9B [0042370B] 85 db                                        test    ebx, ebx
000A2D9D [0042370D] 7f 04                                        jg      short near ptr unk_423713 ; game-relative-target=0x000A2DA3
000A2D9F [0042370F] 85 ed                                        test    ebp, ebp
000A2DA1 [00423711] 7e 06                                        jle     short near ptr unk_423719 ; game-relative-target=0x000A2DA9
000A2DA3 [00423713] 8b 36                                        mov     esi, [esi]
000A2DA5 [00423715] 85 f6                                        test    esi, esi
000A2DA7 [00423717] 75 bc                                        jnz     short near ptr unk_4236D5 ; game-relative-target=0x000A2D65
000A2DA9 [00423719] 5f                                           pop     edi
000A2DAA [0042371A] 5d                                           pop     ebp
000A2DAB [0042371B] c2 18 00                                     retn    18h
