; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004274C8; baseline game VA=0x000A6600; size=628
; Relative branch annotations use the baseline game destination.
000A6600 [004274C8] 56                                           push    esi
000A6601 [004274C9] 57                                           push    edi
000A6602 [004274CA] 55                                           push    ebp
000A6603 [004274CB] 53                                           push    ebx
000A6604 [004274CC] 51                                           push    ecx
000A6605 [004274CD] 83 ec 20                                     sub     esp, 20h ; ' '
000A6608 [004274D0] 8b cc                                        mov     ecx, esp
000A660A [004274D2] b8 c0 3c 47 00                               mov     eax, 473CC0h
000A660F [004274D7] ff d0                                        call    eax
000A6611 [004274D9] 8b 3d 24 05 0a 00                            mov     edi, ds:0A0524h
000A6617 [004274DF] 8b 57 08                                     mov     edx, [edi+8]
000A661A [004274E2] f6 42 20 08                                  test    byte ptr [edx+20h], 8
000A661E [004274E6] 75 1c                                        jnz     short near ptr unk_427504 ; game-relative-target=0x000A663C
000A6620 [004274E8] 8b 42 74                                     mov     eax, [edx+74h]
000A6623 [004274EB] f6 40 34 05                                  test    byte ptr [eax+34h], 5
000A6627 [004274EF] 75 13                                        jnz     short near ptr unk_427504 ; game-relative-target=0x000A663C
000A6629 [004274F1] 8b 42 6c                                     mov     eax, [edx+6Ch]
000A662C [004274F4] 80 78 04 06                                  cmp     byte ptr [eax+4], 6
000A6630 [004274F8] 74 0a                                        jz      short near ptr unk_427504 ; game-relative-target=0x000A663C
000A6632 [004274FA] 8b cc                                        mov     ecx, esp
000A6634 [004274FC] 52                                           push    edx
000A6635 [004274FD] b8 70 ef 46 00                               mov     eax, 46EF70h
000A663A [00427502] ff d0                                        call    eax
000A663C [00427504] 8b 3f                                        mov     edi, [edi]
000A663E [00427506] 85 ff                                        test    edi, edi
000A6640 [00427508] 75 d5                                        jnz     short near ptr unk_4274DF ; game-relative-target=0x000A6617
000A6642 [0042750A] 83 7c 24 0c 01                               cmp     dword ptr [esp+0Ch], 1
000A6647 [0042750F] 0f 8e 15 02 00 00                            jle     near ptr unk_42772A ; game-relative-target=0x000A6862
000A664D [00427515] 8b 7c 24 04                                  mov     edi, [esp+4]
000A6651 [00427519] 8b 4f 08                                     mov     ecx, [edi+8]
000A6654 [0042751C] 8b 69 74                                     mov     ebp, [ecx+74h]
000A6657 [0042751F] 83 ec 20                                     sub     esp, 20h ; ' '
000A665A [00427522] 8b cc                                        mov     ecx, esp
000A665C [00427524] b8 c0 3c 47 00                               mov     eax, 473CC0h
000A6661 [00427529] ff d0                                        call    eax
000A6663 [0042752B] 8b 57 08                                     mov     edx, [edi+8]
000A6666 [0042752E] 39 6a 74                                     cmp     [edx+74h], ebp
000A6669 [00427531] 75 1a                                        jnz     short near ptr unk_42754D ; game-relative-target=0x000A6685
000A666B [00427533] 8b cc                                        mov     ecx, esp
000A666D [00427535] 52                                           push    edx
000A666E [00427536] b8 70 ef 46 00                               mov     eax, 46EF70h
000A6673 [0042753B] ff d0                                        call    eax
000A6675 [0042753D] 57                                           push    edi
000A6676 [0042753E] 8b 3f                                        mov     edi, [edi]
000A6678 [00427540] 8d 4c 24 24                                  lea     ecx, [esp+24h]
000A667C [00427544] b8 10 64 41 00                               mov     eax, 416410h
000A6681 [00427549] ff d0                                        call    eax
000A6683 [0042754B] eb 02                                        jmp     short near ptr unk_42754F ; game-relative-target=0x000A6687
000A6685 [0042754D] 8b 3f                                        mov     edi, [edi]
000A6687 [0042754F] 85 ff                                        test    edi, edi
000A6689 [00427551] 75 d8                                        jnz     short near ptr unk_42752B ; game-relative-target=0x000A6663
000A668B [00427553] 8b ad b8 00 00 00                            mov     ebp, [ebp+0B8h]
000A6691 [00427559] 8b 6d 70                                     mov     ebp, [ebp+70h]
000A6694 [0042755C] 33 db                                        xor     ebx, ebx
000A6696 [0042755E] 8b 7c 24 04                                  mov     edi, [esp+4]
000A669A [00427562] 8b 4f 08                                     mov     ecx, [edi+8]
000A669D [00427565] f6 41 21 10                                  test    byte ptr [ecx+21h], 10h
000A66A1 [00427569] 75 01                                        jnz     short near ptr unk_42756C ; game-relative-target=0x000A66A4
000A66A3 [0042756B] 43                                           inc     ebx
000A66A4 [0042756C] 8b 3f                                        mov     edi, [edi]
000A66A6 [0042756E] 85 ff                                        test    edi, edi
000A66A8 [00427570] 75 f0                                        jnz     short near ptr unk_427562 ; game-relative-target=0x000A669A
000A66AA [00427572] 8b 44 24 0c                                  mov     eax, [esp+0Ch]
000A66AE [00427576] 83 f8 02                                     cmp     eax, 2
000A66B1 [00427579] 7e 0f                                        jle     short near ptr unk_42758A ; game-relative-target=0x000A66C2
000A66B3 [0042757B] 6b c0 02                                     imul    eax, 2
000A66B6 [0042757E] b9 03 00 00 00                               mov     ecx, 3
000A66BB [00427583] 99                                           cdq
000A66BC [00427584] f7 f1                                        div     ecx
000A66BE [00427586] 2b d8                                        sub     ebx, eax
000A66C0 [00427588] 85 db                                        test    ebx, ebx
000A66C2 [0042758A] 0f 8e 7b 01 00 00                            jle     near ptr unk_42770B ; game-relative-target=0x000A6843
000A66C8 [00427590] 8b 7c 24 04                                  mov     edi, [esp+4]
000A66CC [00427594] 8b 4f 08                                     mov     ecx, [edi+8]
000A66CF [00427597] f6 41 21 10                                  test    byte ptr [ecx+21h], 10h
000A66D3 [0042759B] 74 0d                                        jz      short near ptr unk_4275AA ; game-relative-target=0x000A66E2
000A66D5 [0042759D] b8 00 00 00 80                               mov     eax, 80000000h
000A66DA [004275A2] 89 41 08                                     mov     [ecx+8], eax
000A66DD [004275A5] e9 95 00 00 00                               jmp     near ptr unk_42763F ; game-relative-target=0x000A6777
000A66E2 [004275AA] 6a 00                                        push    0
000A66E4 [004275AC] 6a 00                                        push    0
000A66E6 [004275AE] 6a 00                                        push    0
000A66E8 [004275B0] 6a 00                                        push    0
000A66EA [004275B2] 8b b1 88 00 00 00                            mov     esi, [ecx+88h]
000A66F0 [004275B8] 8b 56 08                                     mov     edx, [esi+8]
000A66F3 [004275BB] 8b 8a f8 00 00 00                            mov     ecx, [edx+0F8h]
000A66F9 [004275C1] 85 c9                                        test    ecx, ecx
000A66FB [004275C3] 74 51                                        jz      short near ptr unk_427616 ; game-relative-target=0x000A674E
000A66FD [004275C5] 83 79 54 03                                  cmp     dword ptr [ecx+54h], 3
000A6701 [004275C9] 7f 4b                                        jg      short near ptr unk_427616 ; game-relative-target=0x000A674E
000A6703 [004275CB] ff 71 64                                     push    dword ptr [ecx+64h]
000A6706 [004275CE] 8b 47 08                                     mov     eax, [edi+8]
000A6709 [004275D1] ff 70 6c                                     push    dword ptr [eax+6Ch]
000A670C [004275D4] b8 00 31 0a 00                               mov     eax, 0A3100h
000A6711 [004275D9] ff d0                                        call    eax
000A6713 [004275DB] 59                                           pop     ecx
000A6714 [004275DC] f7 e9                                        imul    ecx
000A6716 [004275DE] d1 e2                                        shl     edx, 1
000A6718 [004275E0] 01 14 24                                     add     [esp], edx
000A671B [004275E3] 8b 4e 08                                     mov     ecx, [esi+8]
000A671E [004275E6] 55                                           push    ebp
000A671F [004275E7] 6a 00                                        push    0
000A6721 [004275E9] b8 40 65 0a 00                               mov     eax, 0A6540h
000A6726 [004275EE] ff d0                                        call    eax
000A6728 [004275F0] 01 44 24 04                                  add     [esp+4], eax
000A672C [004275F4] 8b 4e 08                                     mov     ecx, [esi+8]
000A672F [004275F7] 55                                           push    ebp
000A6730 [004275F8] 6a 02                                        push    2
000A6732 [004275FA] b8 40 65 0a 00                               mov     eax, 0A6540h
000A6737 [004275FF] ff d0                                        call    eax
000A6739 [00427601] 01 44 24 08                                  add     [esp+8], eax
000A673D [00427605] 8b 4e 08                                     mov     ecx, [esi+8]
000A6740 [00427608] 55                                           push    ebp
000A6741 [00427609] 6a 05                                        push    5
000A6743 [0042760B] b8 40 65 0a 00                               mov     eax, 0A6540h
000A6748 [00427610] ff d0                                        call    eax
000A674A [00427612] 01 44 24 0c                                  add     [esp+0Ch], eax
000A674E [00427616] 8b 36                                        mov     esi, [esi]
000A6750 [00427618] 85 f6                                        test    esi, esi
000A6752 [0042761A] 75 9c                                        jnz     short near ptr unk_4275B8 ; game-relative-target=0x000A66F0
000A6754 [0042761C] 33 d2                                        xor     edx, edx
000A6756 [0042761E] 5e                                           pop     esi
000A6757 [0042761F] 58                                           pop     eax
000A6758 [00427620] 59                                           pop     ecx
000A6759 [00427621] 3b c1                                        cmp     eax, ecx
000A675B [00427623] 7d 04                                        jge     short near ptr unk_427629 ; game-relative-target=0x000A6761
000A675D [00427625] b2 02                                        mov     dl, 2
000A675F [00427627] 8b c1                                        mov     eax, ecx
000A6761 [00427629] 59                                           pop     ecx
000A6762 [0042762A] 3b c1                                        cmp     eax, ecx
000A6764 [0042762C] 7d 04                                        jge     short near ptr unk_427632 ; game-relative-target=0x000A676A
000A6766 [0042762E] b2 05                                        mov     dl, 5
000A6768 [00427630] 8b c1                                        mov     eax, ecx
000A676A [00427632] 2b c6                                        sub     eax, esi
000A676C [00427634] c1 e0 10                                     shl     eax, 10h
000A676F [00427637] 03 c2                                        add     eax, edx
000A6771 [00427639] 8b 4f 08                                     mov     ecx, [edi+8]
000A6774 [0042763C] 89 41 08                                     mov     [ecx+8], eax
000A6777 [0042763F] 8b 3f                                        mov     edi, [edi]
000A6779 [00427641] 85 ff                                        test    edi, edi
000A677B [00427643] 0f 85 4b ff ff ff                            jnz     near ptr unk_427594 ; game-relative-target=0x000A66CC
000A6781 [00427649] 8b cc                                        mov     ecx, esp
000A6783 [0042764B] 6a 00                                        push    0
000A6785 [0042764D] 68 60 e9 46 00                               push    46E960h
000A678A [00427652] b8 10 f6 46 00                               mov     eax, 46F610h
000A678F [00427657] ff d0                                        call    eax
000A6791 [00427659] 8b 7c 24 04                                  mov     edi, [esp+4]
000A6795 [0042765D] 53                                           push    ebx
000A6796 [0042765E] 8b 4f 08                                     mov     ecx, [edi+8]
000A6799 [00427661] 0f b7 59 08                                  movzx   ebx, word ptr [ecx+8]
000A679D [00427665] 8b b1 88 00 00 00                            mov     esi, [ecx+88h]
000A67A3 [0042766B] 8b 4e 08                                     mov     ecx, [esi+8]
000A67A6 [0042766E] 8b 81 f8 00 00 00                            mov     eax, [ecx+0F8h]
000A67AC [00427674] 85 c0                                        test    eax, eax
000A67AE [00427676] 74 1c                                        jz      short near ptr unk_427694 ; game-relative-target=0x000A67CC
000A67B0 [00427678] 83 78 54 03                                  cmp     dword ptr [eax+54h], 3
000A67B4 [0042767C] 7f 16                                        jg      short near ptr unk_427694 ; game-relative-target=0x000A67CC
000A67B6 [0042767E] 55                                           push    ebp
000A67B7 [0042767F] 53                                           push    ebx
000A67B8 [00427680] b8 40 65 0a 00                               mov     eax, 0A6540h
000A67BD [00427685] ff d0                                        call    eax
000A67BF [00427687] 8b 44 24 f8                                  mov     eax, [esp-8]
000A67C3 [0042768B] 8b 4e 08                                     mov     ecx, [esi+8]
000A67C6 [0042768E] 89 81 f8 00 00 00                            mov     [ecx+0F8h], eax
000A67CC [00427694] 8a 81 ea 00 00 00                            mov     al, [ecx+0EAh]
000A67D2 [0042769A] 24 1f                                        and     al, 1Fh
000A67D4 [0042769C] 8b 4f 08                                     mov     ecx, [edi+8]
000A67D7 [0042769F] 8b 51 6c                                     mov     edx, [ecx+6Ch]
000A67DA [004276A2] 81 c2 80 00 00 00                            add     edx, 80h
000A67E0 [004276A8] 33 c9                                        xor     ecx, ecx
000A67E2 [004276AA] 3a 02                                        cmp     al, [edx]
000A67E4 [004276AC] 74 07                                        jz      short near ptr unk_4276B5 ; game-relative-target=0x000A67ED
000A67E6 [004276AE] 42                                           inc     edx
000A67E7 [004276AF] 41                                           inc     ecx
000A67E8 [004276B0] 80 f9 05                                     cmp     cl, 5
000A67EB [004276B3] 7c f5                                        jl      short near ptr unk_4276AA ; game-relative-target=0x000A67E2
000A67ED [004276B5] 80 f9 04                                     cmp     cl, 4
000A67F0 [004276B8] 7e 07                                        jle     short near ptr unk_4276C1 ; game-relative-target=0x000A67F9
000A67F2 [004276BA] b8 09 00 00 00                               mov     eax, 9
000A67F7 [004276BF] eb 13                                        jmp     short near ptr unk_4276D4 ; game-relative-target=0x000A680C
000A67F9 [004276C1] 53                                           push    ebx
000A67FA [004276C2] b8 90 38 45 00                               mov     eax, 453890h
000A67FF [004276C7] ff d0                                        call    eax
000A6801 [004276C9] 5a                                           pop     edx
000A6802 [004276CA] 51                                           push    ecx
000A6803 [004276CB] 8b c8                                        mov     ecx, eax
000A6805 [004276CD] b8 f0 87 44 00                               mov     eax, 4487F0h
000A680A [004276D2] ff d0                                        call    eax
000A680C [004276D4] 68 00 00 1f 00                               push    1F0000h
000A6811 [004276D9] 50                                           push    eax
000A6812 [004276DA] 8b 4e 08                                     mov     ecx, [esi+8]
000A6815 [004276DD] b8 00 c9 44 00                               mov     eax, 44C900h
000A681A [004276E2] ff d0                                        call    eax
000A681C [004276E4] 8b 36                                        mov     esi, [esi]
000A681E [004276E6] 85 f6                                        test    esi, esi
000A6820 [004276E8] 75 81                                        jnz     short near ptr unk_42766B ; game-relative-target=0x000A67A3
000A6822 [004276EA] 53                                           push    ebx
000A6823 [004276EB] b8 90 38 45 00                               mov     eax, 453890h
000A6828 [004276F0] ff d0                                        call    eax
000A682A [004276F2] 5a                                           pop     edx
000A682B [004276F3] 8b 4f 08                                     mov     ecx, [edi+8]
000A682E [004276F6] 89 41 6c                                     mov     [ecx+6Ch], eax
000A6831 [004276F9] 80 49 21 10                                  or      byte ptr [ecx+21h], 10h
000A6835 [004276FD] 5b                                           pop     ebx
000A6836 [004276FE] 4b                                           dec     ebx
000A6837 [004276FF] 74 0a                                        jz      short near ptr unk_42770B ; game-relative-target=0x000A6843
000A6839 [00427701] 8b 3f                                        mov     edi, [edi]
000A683B [00427703] 85 ff                                        test    edi, edi
000A683D [00427705] 0f 85 52 ff ff ff                            jnz     near ptr unk_42765D ; game-relative-target=0x000A6795
000A6843 [0042770B] 8b 44 24 40                                  mov     eax, [esp+40h]
000A6847 [0042770F] 8b cc                                        mov     ecx, esp
000A6849 [00427711] 50                                           push    eax
000A684A [00427712] b8 40 5d 0a 00                               mov     eax, 0A5D40h
000A684F [00427717] ff d0                                        call    eax
000A6851 [00427719] 8b cc                                        mov     ecx, esp
000A6853 [0042771B] b8 e0 80 51 00                               mov     eax, 5180E0h
000A6858 [00427720] ff d0                                        call    eax
000A685A [00427722] 83 c4 20                                     add     esp, 20h ; ' '
000A685D [00427725] e9 e0 fd ff ff                               jmp     near ptr unk_42750A ; game-relative-target=0x000A6642
000A6862 [0042772A] 8b cc                                        mov     ecx, esp
000A6864 [0042772C] b8 e0 80 51 00                               mov     eax, 5180E0h
000A6869 [00427731] ff d0                                        call    eax
000A686B [00427733] 83 c4 20                                     add     esp, 20h ; ' '
000A686E [00427736] 58                                           pop     eax
000A686F [00427737] 5b                                           pop     ebx
000A6870 [00427738] 5d                                           pop     ebp
000A6871 [00427739] 5f                                           pop     edi
000A6872 [0042773A] 5e                                           pop     esi
000A6873 [0042773B] c3                                           retn
