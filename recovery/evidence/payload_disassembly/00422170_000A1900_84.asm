; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00422170; baseline game VA=0x000A1900; size=132
; Relative branch annotations use the baseline game destination.
000A1900 [00422170] 56                                           push    esi
000A1901 [00422171] 8b 74 24 08                                  mov     esi, [esp+8]
000A1905 [00422175] 57                                           push    edi
000A1906 [00422176] 8b 7e 04                                     mov     edi, [esi+4]
000A1909 [00422179] 85 ff                                        test    edi, edi
000A190B [0042217B] 74 25                                        jz      short near ptr unk_4221A2 ; game-relative-target=0x000A1932
000A190D [0042217D] 8b 4f 08                                     mov     ecx, [edi+8]
000A1910 [00422180] 8b 41 08                                     mov     eax, [ecx+8]
000A1913 [00422183] 25 ff 00 00 00                               and     eax, 0FFh
000A1918 [00422188] 3b 81 8c 00 00 00                            cmp     eax, [ecx+8Ch]
000A191E [0042218E] 75 0e                                        jnz     short near ptr unk_42219E ; game-relative-target=0x000A192E
000A1920 [00422190] 57                                           push    edi
000A1921 [00422191] 8b 3f                                        mov     edi, [edi]
000A1923 [00422193] 8b ce                                        mov     ecx, esi
000A1925 [00422195] b8 10 64 41 00                               mov     eax, 416410h
000A192A [0042219A] ff d0                                        call    eax
000A192C [0042219C] eb db                                        jmp     short near ptr unk_422179 ; game-relative-target=0x000A1909
000A192E [0042219E] 8b 3f                                        mov     edi, [edi]
000A1930 [004221A0] eb d7                                        jmp     short near ptr unk_422179 ; game-relative-target=0x000A1909
000A1932 [004221A2] 8b 7b 48                                     mov     edi, [ebx+48h]
000A1935 [004221A5] 85 ff                                        test    edi, edi
000A1937 [004221A7] 74 41                                        jz      short near ptr unk_4221EA ; game-relative-target=0x000A197A
000A1939 [004221A9] 8b 4f 08                                     mov     ecx, [edi+8]
000A193C [004221AC] 8b 81 8c 00 00 00                            mov     eax, [ecx+8Ch]
000A1942 [004221B2] 83 f8 ff                                     cmp     eax, 0FFFFFFFFh
000A1945 [004221B5] 74 2f                                        jz      short near ptr unk_4221E6 ; game-relative-target=0x000A1976
000A1947 [004221B7] 50                                           push    eax
000A1948 [004221B8] b8 a0 37 45 00                               mov     eax, 4537A0h
000A194D [004221BD] ff d0                                        call    eax
000A194F [004221BF] 83 c4 04                                     add     esp, 4
000A1952 [004221C2] 50                                           push    eax
000A1953 [004221C3] 8d 4b 64                                     lea     ecx, [ebx+64h]
000A1956 [004221C6] b8 60 eb 46 00                               mov     eax, 46EB60h
000A195B [004221CB] ff d0                                        call    eax
000A195D [004221CD] 85 c0                                        test    eax, eax
000A195F [004221CF] 75 15                                        jnz     short near ptr unk_4221E6 ; game-relative-target=0x000A1976
000A1961 [004221D1] 8b 4f 08                                     mov     ecx, [edi+8]
000A1964 [004221D4] b8 4c 00 10 00                               mov     eax, 10004Ch
000A1969 [004221D9] 89 41 08                                     mov     [ecx+8], eax
000A196C [004221DC] 51                                           push    ecx
000A196D [004221DD] 8b ce                                        mov     ecx, esi
000A196F [004221DF] b8 70 ef 46 00                               mov     eax, 46EF70h
000A1974 [004221E4] ff d0                                        call    eax
000A1976 [004221E6] 8b 3f                                        mov     edi, [edi]
000A1978 [004221E8] eb bb                                        jmp     short near ptr unk_4221A5 ; game-relative-target=0x000A1935
000A197A [004221EA] 5f                                           pop     edi
000A197B [004221EB] 5e                                           pop     esi
000A197C [004221EC] 8b cb                                        mov     ecx, ebx
000A197E [004221EE] 68 50 eb 50 00                               push    50EB50h
000A1983 [004221F3] c3                                           retn
