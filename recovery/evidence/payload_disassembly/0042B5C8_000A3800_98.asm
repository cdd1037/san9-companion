; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042B5C8; baseline game VA=0x000A3800; size=152
; Relative branch annotations use the baseline game destination.
000A3800 [0042B5C8] 8b 94 24 2c 01 00 00                         mov     edx, [esp+12Ch]
000A3807 [0042B5CF] eb 07                                        jmp     short near ptr unk_42B5D8 ; game-relative-target=0x000A3810
000A3809 [0042B5D1] 8b 94 24 28 01 00 00                         mov     edx, [esp+128h]
000A3810 [0042B5D8] 56                                           push    esi
000A3811 [0042B5D9] 57                                           push    edi
000A3812 [0042B5DA] 53                                           push    ebx
000A3813 [0042B5DB] 33 db                                        xor     ebx, ebx
000A3815 [0042B5DD] 8b f9                                        mov     edi, ecx
000A3817 [0042B5DF] 8b f2                                        mov     esi, edx
000A3819 [0042B5E1] 83 ec 30                                     sub     esp, 30h ; '0'
000A381C [0042B5E4] 8b cc                                        mov     ecx, esp
000A381E [0042B5E6] b8 b0 34 47 00                               mov     eax, 4734B0h
000A3823 [0042B5EB] ff d0                                        call    eax
000A3825 [0042B5ED] 8b 97 d0 00 00 00                            mov     edx, [edi+0D0h]
000A382B [0042B5F3] 8b ce                                        mov     ecx, esi
000A382D [0042B5F5] 52                                           push    edx
000A382E [0042B5F6] 50                                           push    eax
000A382F [0042B5F7] b8 70 ed 45 00                               mov     eax, 45ED70h
000A3834 [0042B5FC] ff d0                                        call    eax
000A3836 [0042B5FE] 8b cf                                        mov     ecx, edi
000A3838 [0042B600] 8d 74 24 20                                  lea     esi, [esp+20h]
000A383C [0042B604] 56                                           push    esi
000A383D [0042B605] b8 40 a9 44 00                               mov     eax, 44A940h
000A3842 [0042B60A] ff d0                                        call    eax
000A3844 [0042B60C] 6a 02                                        push    2
000A3846 [0042B60E] 6a 02                                        push    2
000A3848 [0042B610] 56                                           push    esi
000A3849 [0042B611] ff 15 78 f3 5f 00                            call    dword ptr ds:5FF378h
000A384F [0042B617] 8b 7c 24 08                                  mov     edi, [esp+8]
000A3853 [0042B61B] 85 ff                                        test    edi, edi
000A3855 [0042B61D] 74 2f                                        jz      short near ptr unk_42B64E ; game-relative-target=0x000A3886
000A3857 [0042B61F] 8b 4f 08                                     mov     ecx, [edi+8]
000A385A [0042B622] 0f b7 41 04                                  movzx   eax, word ptr [ecx+4]
000A385E [0042B626] b9 c8 00 00 00                               mov     ecx, 0C8h
000A3863 [0042B62B] 99                                           cdq
000A3864 [0042B62C] f7 f9                                        idiv    ecx
000A3866 [0042B62E] 50                                           push    eax
000A3867 [0042B62F] 52                                           push    edx
000A3868 [0042B630] 56                                           push    esi
000A3869 [0042B631] ff 15 6c f3 5f 00                            call    dword ptr ds:5FF36Ch
000A386F [0042B637] 85 c0                                        test    eax, eax
000A3871 [0042B639] 74 13                                        jz      short near ptr unk_42B64E ; game-relative-target=0x000A3886
000A3873 [0042B63B] 8b 4f 08                                     mov     ecx, [edi+8]
000A3876 [0042B63E] b8 40 cc 45 00                               mov     eax, 45CC40h
000A387B [0042B643] ff d0                                        call    eax
000A387D [0042B645] 8b 7f 04                                     mov     edi, [edi+4]
000A3880 [0042B648] 85 c0                                        test    eax, eax
000A3882 [0042B64A] 74 cf                                        jz      short near ptr unk_42B61B ; game-relative-target=0x000A3853
000A3884 [0042B64C] 8b d8                                        mov     ebx, eax
000A3886 [0042B64E] 8b cc                                        mov     ecx, esp
000A3888 [0042B650] b8 d0 34 47 00                               mov     eax, 4734D0h
000A388D [0042B655] ff d0                                        call    eax
000A388F [0042B657] 83 c4 30                                     add     esp, 30h ; '0'
000A3892 [0042B65A] 8b c3                                        mov     eax, ebx
000A3894 [0042B65C] 5b                                           pop     ebx
000A3895 [0042B65D] 5f                                           pop     edi
000A3896 [0042B65E] 5e                                           pop     esi
000A3897 [0042B65F] c3                                           retn
