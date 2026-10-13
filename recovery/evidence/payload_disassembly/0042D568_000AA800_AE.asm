; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042D568; baseline game VA=0x000AA800; size=174
; Relative branch annotations use the baseline game destination.
000AA800 [0042D568] 56                                           push    esi
000AA801 [0042D569] 57                                           push    edi
000AA802 [0042D56A] 53                                           push    ebx
000AA803 [0042D56B] 55                                           push    ebp
000AA804 [0042D56C] 33 ed                                        xor     ebp, ebp
000AA806 [0042D56E] 8b f1                                        mov     esi, ecx
000AA808 [0042D570] 8b 01                                        mov     eax, [ecx]
000AA80A [0042D572] ff 50 30                                     call    dword ptr [eax+30h]
000AA80D [0042D575] 85 c0                                        test    eax, eax
000AA80F [0042D577] 74 48                                        jz      short near ptr dword_42D570+51h ; game-relative-target=0x000AA859
000AA811 [0042D579] 8b f8                                        mov     edi, eax
000AA813 [0042D57B] bb 78 80 23 01                               mov     ebx, 1238078h
000AA818 [0042D580] 53                                           push    ebx
000AA819 [0042D581] b8 20 58 40 00                               mov     eax, 405820h
000AA81E [0042D586] ff d0                                        call    eax
000AA820 [0042D588] 83 c4 04                                     add     esp, 4
000AA823 [0042D58B] 85 c0                                        test    eax, eax
000AA825 [0042D58D] 74 24                                        jz      short near ptr dword_42D570+43h ; game-relative-target=0x000AA84B
000AA827 [0042D58F] 39 73 44                                     cmp     [ebx+44h], esi
000AA82A [0042D592] 75 1f                                        jnz     short near ptr dword_42D570+43h ; game-relative-target=0x000AA84B
000AA82C [0042D594] f6 47 34 01                                  test    byte ptr [edi+34h], 1
000AA830 [0042D598] 74 0d                                        jz      short near ptr dword_42D570+37h ; game-relative-target=0x000AA83F
000AA832 [0042D59A] 53                                           push    ebx
000AA833 [0042D59B] b8 10 f2 4a 00                               mov     eax, 4AF210h
000AA838 [0042D5A0] ff d0                                        call    eax
000AA83A [0042D5A2] 5a                                           pop     edx
000AA83B [0042D5A3] 85 c0                                        test    eax, eax
000AA83D [0042D5A5] 74 0c                                        jz      short near ptr dword_42D570+43h ; game-relative-target=0x000AA84B
000AA83F [0042D5A7] 8b cb                                        mov     ecx, ebx
000AA841 [0042D5A9] 8b 03                                        mov     eax, [ebx]
000AA843 [0042D5AB] ff 50 30                                     call    dword ptr [eax+30h]
000AA846 [0042D5AE] 3b c7                                        cmp     eax, edi
000AA848 [0042D5B0] 75 01                                        jnz     short near ptr dword_42D570+43h ; game-relative-target=0x000AA84B
000AA84A [0042D5B2] 45                                           inc     ebp
000AA84B [0042D5B3] 81 c3 bc 01 00 00                            add     ebx, 1BCh
000AA851 [0042D5B9] 81 fb 58 db 24 01                            cmp     ebx, 124DB58h
000AA857 [0042D5BF] 7e bf                                        jle     short near ptr dword_42D570+10h ; game-relative-target=0x000AA818
000AA859 [0042D5C1] 8b c5                                        mov     eax, ebp
000AA85B [0042D5C3] 5d                                           pop     ebp
000AA85C [0042D5C4] 5b                                           pop     ebx
000AA85D [0042D5C5] 5f                                           pop     edi
000AA85E [0042D5C6] 5e                                           pop     esi
000AA85F [0042D5C7] c3                                           retn
000AA860 [0042D5C8] ff b1 cc 01 00 00                            push    dword ptr [ecx+1CCh]
000AA866 [0042D5CE] eb 06                                        jmp     short near ptr dword_42D570+66h ; game-relative-target=0x000AA86E
000AA868 [0042D5D0] ff b1 d4 01 00 00                            push    dword ptr [ecx+1D4h]
000AA86E [0042D5D6] e8 8d ff ff ff                               call    near ptr unk_42D568 ; game-relative-target=0x000AA800
000AA873 [0042D5DB] 59                                           pop     ecx
000AA874 [0042D5DC] 6b c0 32                                     imul    eax, 32h ; '2'
000AA877 [0042D5DF] 03 c1                                        add     eax, ecx
000AA879 [0042D5E1] 3d e2 04 00 00                               cmp     eax, 4E2h
000AA87E [0042D5E6] 7e 05                                        jle     short near ptr dword_42D570+7Dh ; game-relative-target=0x000AA885
000AA880 [0042D5E8] b8 e2 04 00 00                               mov     eax, 4E2h
000AA885 [0042D5ED] c3                                           retn
000AA886 [0042D5EE] 00    db 0x00
000AA887 [0042D5EF] 00 ff                                        add     bh, bh
000AA889 [0042D5F1] b1 d0                                        mov     cl, 0D0h
000AA88B [0042D5F3] 01 00                                        add     [eax], eax
000AA88D [0042D5F5] 00 eb                                        add     bl, ch
000AA88F [0042D5F7] 06                                           push    es
000AA890 [0042D5F8] ff b1 d8 01 00 00                            push    dword ptr [ecx+1D8h]
000AA896 [0042D5FE] e8 65 ff ff ff                               call    near ptr unk_42D568 ; game-relative-target=0x000AA800
000AA89B [0042D603] 59                                           pop     ecx
000AA89C [0042D604] 6b c0 32                                     imul    eax, 32h ; '2'
000AA89F [0042D607] 03 c1                                        add     eax, ecx
000AA8A1 [0042D609] 3d d0 07 00 00                               cmp     eax, 7D0h
000AA8A6 [0042D60E] 7e 05                                        jle     short near ptr dword_42D570+0A5h ; game-relative-target=0x000AA8AD
000AA8A8 [0042D610] b8 d0 07 00 00                               mov     eax, 7D0h
000AA8AD [0042D615] c3                                           retn
