; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00422B60; baseline game VA=0x000A00F0; size=77
; Relative branch annotations use the baseline game destination.
000A00F0 [00422B60] 81 b9 88 00 00 00 40 1f 00 00                cmp     dword ptr [ecx+88h], 1F40h
000A00FA [00422B6A] 7f 09                                        jg      short near ptr unk_422B75 ; game-relative-target=0x000A0105
000A00FC [00422B6C] f6 41 7a 40                                  test    byte ptr [ecx+7Ah], 40h ; '@'
000A0100 [00422B70] 74 03                                        jz      short near ptr unk_422B75 ; game-relative-target=0x000A0105
000A0102 [00422B72] c2 04 00                                     retn    4
000A0105 [00422B75] 51                                           push    ecx
000A0106 [00422B76] b8 00 36 0a 00                               mov     eax, 0A3600h
000A010B [00422B7B] ff d0                                        call    eax
000A010D [00422B7D] 29 44 24 08                                  sub     [esp+8], eax
000A0111 [00422B81] b8 00 02 0a 00                               mov     eax, 0A0200h
000A0116 [00422B86] ff d0                                        call    eax
000A0118 [00422B88] 33 c9                                        xor     ecx, ecx
000A011A [00422B8A] 6b c0 2c                                     imul    eax, 2Ch ; ','
000A011D [00422B8D] c1 e8 06                                     shr     eax, 6
000A0120 [00422B90] 3b 44 24 04                                  cmp     eax, [esp+4]
000A0124 [00422B94] 0f 9c c1                                     setl    cl
000A0127 [00422B97] 8b c1                                        mov     eax, ecx
000A0129 [00422B99] 85 c0                                        test    eax, eax
000A012B [00422B9B] 74 0d                                        jz      short near ptr unk_422BAA ; game-relative-target=0x000A013A
000A012D [00422B9D] 8b 4c 24 fc                                  mov     ecx, [esp-4]
000A0131 [00422BA1] 50                                           push    eax
000A0132 [00422BA2] b8 00 66 0a 00                               mov     eax, 0A6600h
000A0137 [00422BA7] ff d0                                        call    eax
000A0139 [00422BA9] 58                                           pop     eax
000A013A [00422BAA] c2 04 00                                     retn    4
