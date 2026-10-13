; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00424D88; baseline game VA=0x000A4D00; size=63
; Relative branch annotations use the baseline game destination.
000A4D00 [00424D88] b8 10 76 4b 00                               mov     eax, 4B7610h
000A4D05 [00424D8D] ff d0                                        call    eax
000A4D07 [00424D8F] 85 c0                                        test    eax, eax
000A4D09 [00424D91] 75 01                                        jnz     short near ptr unk_424D94 ; game-relative-target=0x000A4D0C
000A4D0B [00424D93] c3                                           retn
000A4D0C [00424D94] 8b 4e 38                                     mov     ecx, [esi+38h]
000A4D0F [00424D97] b8 c3 4c 0a 00                               mov     eax, 0A4CC3h
000A4D14 [00424D9C] ff d0                                        call    eax
000A4D16 [00424D9E] 85 c0                                        test    eax, eax
000A4D18 [00424DA0] 75 01                                        jnz     short near ptr unk_424DA3 ; game-relative-target=0x000A4D1B
000A4D1A [00424DA2] c3                                           retn
000A4D1B [00424DA3] 53                                           push    ebx
000A4D1C [00424DA4] 33 db                                        xor     ebx, ebx
000A4D1E [00424DA6] 53                                           push    ebx
000A4D1F [00424DA7] b8 00 71 47 00                               mov     eax, 477100h
000A4D24 [00424DAC] ff d0                                        call    eax
000A4D26 [00424DAE] 85 c0                                        test    eax, eax
000A4D28 [00424DB0] 74 04                                        jz      short near ptr unk_424DB6 ; game-relative-target=0x000A4D2E
000A4D2A [00424DB2] 80 60 0f 01                                  and     byte ptr [eax+0Fh], 1
000A4D2E [00424DB6] 43                                           inc     ebx
000A4D2F [00424DB7] 81 fb fa 00 00 00                            cmp     ebx, 0FAh
000A4D35 [00424DBD] 7c e7                                        jl      short near ptr unk_424DA6 ; game-relative-target=0x000A4D1E
000A4D37 [00424DBF] 5b                                           pop     ebx
000A4D38 [00424DC0] c6 46 3c 19                                  mov     byte ptr [esi+3Ch], 19h
000A4D3C [00424DC4] b0 01                                        mov     al, 1
000A4D3E [00424DC6] c3                                           retn
