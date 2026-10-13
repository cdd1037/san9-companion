; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004200E0; baseline game VA=0x000A0030; size=155
; Relative branch annotations use the baseline game destination.
000A0030 [004200E0] 57                                           push    edi
000A0031 [004200E1] 8b 41 74                                     mov     eax, [ecx+74h]
000A0034 [004200E4] f6 40 34 01                                  test    byte ptr [eax+34h], 1
000A0038 [004200E8] 75 06                                        jnz     short near ptr unk_4200F0 ; game-relative-target=0x000A0040
000A003A [004200EA] 80 79 52 03                                  cmp     byte ptr [ecx+52h], 3
000A003E [004200EE] 74 09                                        jz      short near ptr unk_4200F9 ; game-relative-target=0x000A0049
000A0040 [004200F0] 5f                                           pop     edi
000A0041 [004200F1] 8b ce                                        mov     ecx, esi
000A0043 [004200F3] 68 70 0e 46 00                               push    460E70h
000A0048 [004200F8] c3                                           retn
000A0049 [004200F9] 8a 41 56                                     mov     al, [ecx+56h]
000A004C [004200FC] 3c ff                                        cmp     al, 0FFh
000A004E [004200FE] 74 11                                        jz      short near ptr unk_420111 ; game-relative-target=0x000A0061
000A0050 [00420100] 3c 03                                        cmp     al, 3
000A0052 [00420102] 74 0d                                        jz      short near ptr unk_420111 ; game-relative-target=0x000A0061
000A0054 [00420104] 8b ce                                        mov     ecx, esi
000A0056 [00420106] b8 d0 00 0a 00                               mov     eax, 0A00D0h
000A005B [0042010B] ff d0                                        call    eax
000A005D [0042010D] 5f                                           pop     edi
000A005E [0042010E] c2 04 00                                     retn    4
000A0061 [00420111] ff 71 50                                     push    dword ptr [ecx+50h]
000A0064 [00420114] b8 c0 37 45 00                               mov     eax, 4537C0h
000A0069 [00420119] ff d0                                        call    eax
000A006B [0042011B] 5a                                           pop     edx
000A006C [0042011C] 8b f8                                        mov     edi, eax
000A006E [0042011E] 8a 47 58                                     mov     al, [edi+58h]
000A0071 [00420121] 3c 28                                        cmp     al, 28h ; '('
000A0073 [00420123] 7c 04                                        jl      short near ptr unk_420129 ; game-relative-target=0x000A0079
000A0075 [00420125] 3c 32                                        cmp     al, 32h ; '2'
000A0077 [00420127] 7e 3a                                        jle     short near ptr unk_420163 ; game-relative-target=0x000A00B3
000A0079 [00420129] 8b 47 6c                                     mov     eax, [edi+6Ch]
000A007C [0042012C] 80 78 04 0d                                  cmp     byte ptr [eax+4], 0Dh
000A0080 [00420130] 74 d2                                        jz      short near ptr unk_420104 ; game-relative-target=0x000A0054
000A0082 [00420132] 8b 7e 64                                     mov     edi, [esi+64h]
000A0085 [00420135] 57                                           push    edi
000A0086 [00420136] 8b ce                                        mov     ecx, esi
000A0088 [00420138] b8 80 0a 0a 00                               mov     eax, 0A0A80h
000A008D [0042013D] ff d0                                        call    eax
000A008F [0042013F] 83 f8 1e                                     cmp     eax, 1Eh
000A0092 [00420142] 7e ac                                        jle     short near ptr unk_4200F0 ; game-relative-target=0x000A0040
000A0094 [00420144] 83 f8 3c                                     cmp     eax, 3Ch ; '<'
000A0097 [00420147] 7f bb                                        jg      short near ptr unk_420104 ; game-relative-target=0x000A0054
000A0099 [00420149] 57                                           push    edi
000A009A [0042014A] 8b ce                                        mov     ecx, esi
000A009C [0042014C] b8 70 88 46 00                               mov     eax, 468870h
000A00A1 [00420151] ff d0                                        call    eax
000A00A3 [00420153] 6a 06                                        push    6
000A00A5 [00420155] 5a                                           pop     edx
000A00A6 [00420156] 80 7f 06 05                                  cmp     byte ptr [edi+6], 5
000A00AA [0042015A] 74 01                                        jz      short near ptr unk_42015D ; game-relative-target=0x000A00AD
000A00AC [0042015C] 4a                                           dec     edx
000A00AD [0042015D] 3b c2                                        cmp     eax, edx
000A00AF [0042015F] 7e e1                                        jle     short near ptr unk_420142 ; game-relative-target=0x000A0092
000A00B1 [00420161] eb a1                                        jmp     short near ptr unk_420104 ; game-relative-target=0x000A0054
000A00B3 [00420163] 8b 47 74                                     mov     eax, [edi+74h]
000A00B6 [00420166] f6 40 34 01                                  test    byte ptr [eax+34h], 1
000A00BA [0042016A] 74 f3                                        jz      short near ptr unk_42015F ; game-relative-target=0x000A00AF
000A00BC [0042016C] 8b 46 74                                     mov     eax, [esi+74h]
000A00BF [0042016F] f6 40 0d 01                                  test    byte ptr [eax+0Dh], 1
000A00C3 [00420173] 75 f1                                        jnz     short near ptr unk_420166 ; game-relative-target=0x000A00B6
000A00C5 [00420175] 68 00 76 0a 00                               push    0A7600h
000A00CA [0042017A] c3                                           retn
