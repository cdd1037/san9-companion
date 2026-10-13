; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00425D88; baseline game VA=0x000A5800; size=234
; Relative branch annotations use the baseline game destination.
000A5800 [00425D88] 81 fa 10 27 00 00                            cmp     edx, 2710h
000A5806 [00425D8E] 7e 31                                        jle     short near ptr unk_425DC1 ; game-relative-target=0x000A5839
000A5808 [00425D90] 2b 86 88 00 00 00                            sub     eax, [esi+88h]
000A580E [00425D96] f7 d8                                        neg     eax
000A5810 [00425D98] 3d 20 4e 00 00                               cmp     eax, 4E20h
000A5815 [00425D9D] 7c 22                                        jl      short near ptr unk_425DC1 ; game-relative-target=0x000A5839
000A5817 [00425D9F] 8b d8                                        mov     ebx, eax
000A5819 [00425DA1] 8b ce                                        mov     ecx, esi
000A581B [00425DA3] b8 d0 53 43 00                               mov     eax, 4353D0h
000A5820 [00425DA8] ff d0                                        call    eax
000A5822 [00425DAA] 8d be dc 00 00 00                            lea     edi, [esi+0DCh]
000A5828 [00425DB0] 8b 57 0c                                     mov     edx, [edi+0Ch]
000A582B [00425DB3] 3c 02                                        cmp     al, 2
000A582D [00425DB5] 7f 05                                        jg      short near ptr unk_425DBC ; game-relative-target=0x000A5834
000A582F [00425DB7] 3c 01                                        cmp     al, 1
000A5831 [00425DB9] 74 01                                        jz      short near ptr unk_425DBC ; game-relative-target=0x000A5834
000A5833 [00425DBB] 4a                                           dec     edx
000A5834 [00425DBC] 83 fa 01                                     cmp     edx, 1
000A5837 [00425DBF] 7f 06                                        jg      short near ptr unk_425DC7 ; game-relative-target=0x000A583F
000A5839 [00425DC1] ff 25 08 f3 5f 00                            jmp     dword ptr ds:5FF308h
000A583F [00425DC7] 55                                           push    ebp
000A5840 [00425DC8] 56                                           push    esi
000A5841 [00425DC9] 52                                           push    edx
000A5842 [00425DCA] 8b c3                                        mov     eax, ebx
000A5844 [00425DCC] b9 98 3a 00 00                               mov     ecx, 3A98h
000A5849 [00425DD1] 99                                           cdq
000A584A [00425DD2] f7 f1                                        div     ecx
000A584C [00425DD4] 81 fa 10 27 00 00                            cmp     edx, 2710h
000A5852 [00425DDA] 7c 01                                        jl      short near ptr unk_425DDD ; game-relative-target=0x000A5855
000A5854 [00425DDC] 40                                           inc     eax
000A5855 [00425DDD] 59                                           pop     ecx
000A5856 [00425DDE] 3b c8                                        cmp     ecx, eax
000A5858 [00425DE0] 7e 02                                        jle     short near ptr unk_425DE4 ; game-relative-target=0x000A585C
000A585A [00425DE2] 8b c8                                        mov     ecx, eax
000A585C [00425DE4] 8b c3                                        mov     eax, ebx
000A585E [00425DE6] 99                                           cdq
000A585F [00425DE7] f7 f1                                        div     ecx
000A5861 [00425DE9] 8b e8                                        mov     ebp, eax
000A5863 [00425DEB] 8b d9                                        mov     ebx, ecx
000A5865 [00425DED] 49                                           dec     ecx
000A5866 [00425DEE] 51                                           push    ecx
000A5867 [00425DEF] 8b ce                                        mov     ecx, esi
000A5869 [00425DF1] 8b 01                                        mov     eax, [ecx]
000A586B [00425DF3] ff 50 0c                                     call    dword ptr [eax+0Ch]
000A586E [00425DF6] 8b 44 84 68                                  mov     eax, [esp+eax*4+68h]
000A5872 [00425DFA] 2b d8                                        sub     ebx, eax
000A5874 [00425DFC] 85 c0                                        test    eax, eax
000A5876 [00425DFE] 75 10                                        jnz     short near ptr unk_425E10 ; game-relative-target=0x000A5888
000A5878 [00425E00] 6a 00                                        push    0
000A587A [00425E02] 68 a0 1c 47 00                               push    471CA0h
000A587F [00425E07] 8b cf                                        mov     ecx, edi
000A5881 [00425E09] b8 10 f6 46 00                               mov     eax, 46F610h
000A5886 [00425E0E] ff d0                                        call    eax
000A5888 [00425E10] 8b cf                                        mov     ecx, edi
000A588A [00425E12] b8 80 e8 46 00                               mov     eax, 46E880h
000A588F [00425E17] ff d0                                        call    eax
000A5891 [00425E19] 8b f8                                        mov     edi, eax
000A5893 [00425E1B] 8b 74 24 0c                                  mov     esi, [esp+0Ch]
000A5897 [00425E1F] 83 fb 01                                     cmp     ebx, 1
000A589A [00425E22] 7f 12                                        jg      short near ptr unk_425E36 ; game-relative-target=0x000A58AE
000A589C [00425E24] 3b 74 24 10                                  cmp     esi, [esp+10h]
000A58A0 [00425E28] 7d 04                                        jge     short near ptr unk_425E2E ; game-relative-target=0x000A58A6
000A58A2 [00425E2A] 89 74 24 10                                  mov     [esp+10h], esi
000A58A6 [00425E2E] 5e                                           pop     esi
000A58A7 [00425E2F] 5d                                           pop     ebp
000A58A8 [00425E30] ff 25 08 f3 5f 00                            jmp     dword ptr ds:5FF308h
000A58AE [00425E36] 3b 6c 24 10                                  cmp     ebp, [esp+10h]
000A58B2 [00425E3A] 7d f2                                        jge     short near ptr unk_425E2E ; game-relative-target=0x000A58A6
000A58B4 [00425E3C] 8b 4f 08                                     mov     ecx, [edi+8]
000A58B7 [00425E3F] b8 00 d7 44 00                               mov     eax, 44D700h
000A58BC [00425E44] ff d0                                        call    eax
000A58BE [00425E46] 3b c5                                        cmp     eax, ebp
000A58C0 [00425E48] 7c 06                                        jl      short near ptr unk_425E50 ; game-relative-target=0x000A58C8
000A58C2 [00425E4A] 89 6c 24 10                                  mov     [esp+10h], ebp
000A58C6 [00425E4E] eb de                                        jmp     short near ptr unk_425E2E ; game-relative-target=0x000A58A6
000A58C8 [00425E50] 2b f0                                        sub     esi, eax
000A58CA [00425E52] 4b                                           dec     ebx
000A58CB [00425E53] 83 fb 01                                     cmp     ebx, 1
000A58CE [00425E56] 74 cc                                        jz      short near ptr unk_425E24 ; game-relative-target=0x000A589C
000A58D0 [00425E58] 8b 7f 04                                     mov     edi, [edi+4]
000A58D3 [00425E5B] 8b 4f 08                                     mov     ecx, [edi+8]
000A58D6 [00425E5E] b8 00 d7 44 00                               mov     eax, 44D700h
000A58DB [00425E63] ff d0                                        call    eax
000A58DD [00425E65] 3b c5                                        cmp     eax, ebp
000A58DF [00425E67] 7e e7                                        jle     short near ptr unk_425E50 ; game-relative-target=0x000A58C8
000A58E1 [00425E69] 8b c6                                        mov     eax, esi
000A58E3 [00425E6B] 99                                           cdq
000A58E4 [00425E6C] f7 f3                                        div     ebx
000A58E6 [00425E6E] 8b e8                                        mov     ebp, eax
000A58E8 [00425E70] eb c4                                        jmp     short near ptr unk_425E36 ; game-relative-target=0x000A58AE
