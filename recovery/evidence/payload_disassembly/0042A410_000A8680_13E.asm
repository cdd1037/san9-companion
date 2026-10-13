; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042A410; baseline game VA=0x000A8680; size=318
; Relative branch annotations use the baseline game destination.
000A8680 [0042A410] 68 70 0e 5d 00                               push    5D0E70h
000A8685 [0042A415] 8b 8e 98 02 00 00                            mov     ecx, [esi+298h]
000A868B [0042A41B] 85 c9                                        test    ecx, ecx
000A868D [0042A41D] 74 1e                                        jz      short near ptr unk_42A43D ; game-relative-target=0x000A86AD
000A868F [0042A41F] 56                                           push    esi
000A8690 [0042A420] 8b f1                                        mov     esi, ecx
000A8692 [0042A422] 8b 81 60 13 00 00                            mov     eax, [ecx+1360h]
000A8698 [0042A428] 50                                           push    eax
000A8699 [0042A429] b8 20 58 40 00                               mov     eax, 405820h
000A869E [0042A42E] ff d0                                        call    eax
000A86A0 [0042A430] 83 c4 04                                     add     esp, 4
000A86A3 [0042A433] 85 c0                                        test    eax, eax
000A86A5 [0042A435] 74 05                                        jz      short near ptr unk_42A43C ; game-relative-target=0x000A86AC
000A86A7 [0042A437] e8 04 00 00 00                               call    near ptr unk_42A440 ; game-relative-target=0x000A86B0
000A86AC [0042A43C] 5e                                           pop     esi
000A86AD [0042A43D] 8b ce                                        mov     ecx, esi
000A86AF [0042A43F] c3                                           retn
000A86B0 [0042A440] 8b 54 24 10                                  mov     edx, [esp+10h]
000A86B4 [0042A444] 81 fa c0 00 00 00                            cmp     edx, 0C0h
000A86BA [0042A44A] 75 0c                                        jnz     short near ptr unk_42A458 ; game-relative-target=0x000A86C8
000A86BC [0042A44C] 8a 86 84 35 00 00                            mov     al, [esi+3584h]
000A86C2 [0042A452] 34 01                                        xor     al, 1
000A86C4 [0042A454] 04 01                                        add     al, 1
000A86C6 [0042A456] eb 7c                                        jmp     short near ptr unk_42A4D4 ; game-relative-target=0x000A8744
000A86C8 [0042A458] 83 fa 70                                     cmp     edx, 70h ; 'p'
000A86CB [0042A45B] 75 04                                        jnz     short near ptr unk_42A461 ; game-relative-target=0x000A86D1
000A86CD [0042A45D] b0 0f                                        mov     al, 0Fh
000A86CF [0042A45F] eb 73                                        jmp     short near ptr unk_42A4D4 ; game-relative-target=0x000A8744
000A86D1 [0042A461] 83 fa 71                                     cmp     edx, 71h ; 'q'
000A86D4 [0042A464] 75 04                                        jnz     short near ptr unk_42A46A ; game-relative-target=0x000A86DA
000A86D6 [0042A466] b0 0d                                        mov     al, 0Dh
000A86D8 [0042A468] eb 6a                                        jmp     short near ptr unk_42A4D4 ; game-relative-target=0x000A8744
000A86DA [0042A46A] 83 fa 72                                     cmp     edx, 72h ; 'r'
000A86DD [0042A46D] 75 04                                        jnz     short near ptr unk_42A473 ; game-relative-target=0x000A86E3
000A86DF [0042A46F] b0 10                                        mov     al, 10h
000A86E1 [0042A471] eb 61                                        jmp     short near ptr unk_42A4D4 ; game-relative-target=0x000A8744
000A86E3 [0042A473] 83 fa 73                                     cmp     edx, 73h ; 's'
000A86E6 [0042A476] 75 04                                        jnz     short near ptr unk_42A47C ; game-relative-target=0x000A86EC
000A86E8 [0042A478] b0 0e                                        mov     al, 0Eh
000A86EA [0042A47A] eb 58                                        jmp     short near ptr unk_42A4D4 ; game-relative-target=0x000A8744
000A86EC [0042A47C] 83 fa 74                                     cmp     edx, 74h ; 't'
000A86EF [0042A47F] 75 04                                        jnz     short near ptr unk_42A485 ; game-relative-target=0x000A86F5
000A86F1 [0042A481] b0 12                                        mov     al, 12h
000A86F3 [0042A483] eb 4f                                        jmp     short near ptr unk_42A4D4 ; game-relative-target=0x000A8744
000A86F5 [0042A485] 83 fa 75                                     cmp     edx, 75h ; 'u'
000A86F8 [0042A488] 75 04                                        jnz     short near ptr unk_42A48E ; game-relative-target=0x000A86FE
000A86FA [0042A48A] b0 0c                                        mov     al, 0Ch
000A86FC [0042A48C] eb 46                                        jmp     short near ptr unk_42A4D4 ; game-relative-target=0x000A8744
000A86FE [0042A48E] 83 fa 76                                     cmp     edx, 76h ; 'v'
000A8701 [0042A491] 75 04                                        jnz     short near ptr unk_42A497 ; game-relative-target=0x000A8707
000A8703 [0042A493] b0 13                                        mov     al, 13h
000A8705 [0042A495] eb 3d                                        jmp     short near ptr unk_42A4D4 ; game-relative-target=0x000A8744
000A8707 [0042A497] 83 fa 1b                                     cmp     edx, 1Bh
000A870A [0042A49A] 75 04                                        jnz     short near ptr unk_42A4A0 ; game-relative-target=0x000A8710
000A870C [0042A49C] b0 14                                        mov     al, 14h
000A870E [0042A49E] eb 34                                        jmp     short near ptr unk_42A4D4 ; game-relative-target=0x000A8744
000A8710 [0042A4A0] 83 fa 4b                                     cmp     edx, 4Bh ; 'K'
000A8713 [0042A4A3] 75 04                                        jnz     short near ptr unk_42A4A9 ; game-relative-target=0x000A8719
000A8715 [0042A4A5] b0 fb                                        mov     al, 0FBh
000A8717 [0042A4A7] eb 2b                                        jmp     short near ptr unk_42A4D4 ; game-relative-target=0x000A8744
000A8719 [0042A4A9] 83 fa 4c                                     cmp     edx, 4Ch ; 'L'
000A871C [0042A4AC] 75 04                                        jnz     short near ptr unk_42A4B2 ; game-relative-target=0x000A8722
000A871E [0042A4AE] b0 fc                                        mov     al, 0FCh
000A8720 [0042A4B0] eb 22                                        jmp     short near ptr unk_42A4D4 ; game-relative-target=0x000A8744
000A8722 [0042A4B2] 83 fa 4f                                     cmp     edx, 4Fh ; 'O'
000A8725 [0042A4B5] 75 04                                        jnz     short near ptr unk_42A4BB ; game-relative-target=0x000A872B
000A8727 [0042A4B7] b0 fd                                        mov     al, 0FDh
000A8729 [0042A4B9] eb 19                                        jmp     short near ptr unk_42A4D4 ; game-relative-target=0x000A8744
000A872B [0042A4BB] 83 fa 50                                     cmp     edx, 50h ; 'P'
000A872E [0042A4BE] 75 04                                        jnz     short near ptr unk_42A4C4 ; game-relative-target=0x000A8734
000A8730 [0042A4C0] b0 04                                        mov     al, 4
000A8732 [0042A4C2] eb 10                                        jmp     short near ptr unk_42A4D4 ; game-relative-target=0x000A8744
000A8734 [0042A4C4] 83 fa 48                                     cmp     edx, 48h ; 'H'
000A8737 [0042A4C7] 75 04                                        jnz     short near ptr unk_42A4CD ; game-relative-target=0x000A873D
000A8739 [0042A4C9] b0 fe                                        mov     al, 0FEh
000A873B [0042A4CB] eb 07                                        jmp     short near ptr unk_42A4D4 ; game-relative-target=0x000A8744
000A873D [0042A4CD] 83 fa 4a                                     cmp     edx, 4Ah ; 'J'
000A8740 [0042A4D0] 75 19                                        jnz     short near ptr unk_42A4EB ; game-relative-target=0x000A875B
000A8742 [0042A4D2] b0 ff                                        mov     al, 0FFh
000A8744 [0042A4D4] 0f b6 c0                                     movzx   eax, al
000A8747 [0042A4D7] a8 80                                        test    al, 80h
000A8749 [0042A4D9] 0f 94 c4                                     setz    ah
000A874C [0042A4DC] 80 c4 2a                                     add     ah, 2Ah ; '*'
000A874F [0042A4DF] 50                                           push    eax
000A8750 [0042A4E0] 8b 4e 18                                     mov     ecx, [esi+18h]
000A8753 [0042A4E3] b8 b0 45 43 00                               mov     eax, 4345B0h
000A8758 [0042A4E8] ff d0                                        call    eax
000A875A [0042A4EA] c3                                           retn
000A875B [0042A4EB] 83 fa 47                                     cmp     edx, 47h ; 'G'
000A875E [0042A4EE] 75 04                                        jnz     short near ptr unk_42A4F4 ; game-relative-target=0x000A8764
000A8760 [0042A4F0] b0 00                                        mov     al, 0
000A8762 [0042A4F2] eb e0                                        jmp     short near ptr unk_42A4D4 ; game-relative-target=0x000A8744
000A8764 [0042A4F4] 83 fa 46                                     cmp     edx, 46h ; 'F'
000A8767 [0042A4F7] 75 1f                                        jnz     short near ptr unk_42A518 ; game-relative-target=0x000A8788
000A8769 [0042A4F9] 8b 86 30 24 00 00                            mov     eax, [esi+2430h]
000A876F [0042A4FF] 83 e8 08                                     sub     eax, 8
000A8772 [0042A502] 40                                           inc     eax
000A8773 [0042A503] 83 f8 02                                     cmp     eax, 2
000A8776 [0042A506] 76 02                                        jbe     short near ptr unk_42A50A ; game-relative-target=0x000A877A
000A8778 [0042A508] 33 c0                                        xor     eax, eax
000A877A [0042A50A] 8d 90 f0 03 00 00                            lea     edx, [eax+3F0h]
000A8780 [0042A510] 8b ce                                        mov     ecx, esi
000A8782 [0042A512] 68 00 84 0a 00                               push    0A8400h
000A8787 [0042A517] c3                                           retn
000A8788 [0042A518] 83 fa 42                                     cmp     edx, 42h ; 'B'
000A878B [0042A51B] 75 06                                        jnz     short near ptr unk_42A523 ; game-relative-target=0x000A8793
000A878D [0042A51D] 68 40 84 0a 00                               push    0A8440h
000A8792 [0042A522] c3                                           retn
000A8793 [0042A523] 83 fa 20                                     cmp     edx, 20h ; ' '
000A8796 [0042A526] 74 0d                                        jz      short near ptr unk_42A535 ; game-relative-target=0x000A87A5
000A8798 [0042A528] 83 fa 2d                                     cmp     edx, 2Dh ; '-'
000A879B [0042A52B] 74 01                                        jz      short near ptr unk_42A52E ; game-relative-target=0x000A879E
000A879D [0042A52D] c3                                           retn
000A879E [0042A52E] b8 30 85 0a 00                               mov     eax, 0A8530h
000A87A3 [0042A533] ff d0                                        call    eax
000A87A5 [0042A535] 56                                           push    esi
000A87A6 [0042A536] 8b 4e 18                                     mov     ecx, [esi+18h]
000A87A9 [0042A539] 8b 89 8c 00 00 00                            mov     ecx, [ecx+8Ch]
000A87AF [0042A53F] b8 d0 e3 47 00                               mov     eax, 47E3D0h
000A87B4 [0042A544] ff d0                                        call    eax
000A87B6 [0042A546] 8b f0                                        mov     esi, eax
000A87B8 [0042A548] 68 55 04 51 00                               push    510455h
000A87BD [0042A54D] c3                                           retn
