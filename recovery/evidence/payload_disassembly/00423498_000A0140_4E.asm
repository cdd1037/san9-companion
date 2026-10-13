; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00423498; baseline game VA=0x000A0140; size=78
; Relative branch annotations use the baseline game destination.
000A0140 [00423498] b8 d0 53 43 00                               mov     eax, 4353D0h
000A0145 [0042349D] ff d0                                        call    eax
000A0147 [0042349F] 3c 00                                        cmp     al, 0
000A0149 [004234A1] 74 04                                        jz      short near ptr unk_4234A7 ; game-relative-target=0x000A014F
000A014B [004234A3] 3c 02                                        cmp     al, 2
000A014D [004234A5] 75 03                                        jnz     short near ptr unk_4234AA ; game-relative-target=0x000A0152
000A014F [004234A7] 33 c0                                        xor     eax, eax
000A0151 [004234A9] c3                                           retn
000A0152 [004234AA] 8b ce                                        mov     ecx, esi
000A0154 [004234AC] 8b 01                                        mov     eax, [ecx]
000A0156 [004234AE] ff 50 0c                                     call    dword ptr [eax+0Ch]
000A0159 [004234B1] f6 05 c8 f4 43 00 01                         test    byte ptr ds:43F4C8h, 1
000A0160 [004234B8] 74 15                                        jz      short near ptr unk_4234CF ; game-relative-target=0x000A0177
000A0162 [004234BA] f6 44 83 44 80                               test    byte ptr [ebx+eax*4+44h], 80h
000A0167 [004234BF] 75 01                                        jnz     short near ptr unk_4234C2 ; game-relative-target=0x000A016A
000A0169 [004234C1] c3                                           retn
000A016A [004234C2] bb 00 10 00 00                               mov     ebx, 1000h
000A016F [004234C7] 68 e6 4b 4b 00                               push    4B4BE6h
000A0174 [004234CC] c2 04 00                                     retn    4
000A0177 [004234CF] 50                                           push    eax
000A0178 [004234D0] 8b ce                                        mov     ecx, esi
000A017A [004234D2] b8 00 3d 0a 00                               mov     eax, 0A3D00h
000A017F [004234D7] ff d0                                        call    eax
000A0181 [004234D9] 3c 01                                        cmp     al, 1
000A0183 [004234DB] 58                                           pop     eax
000A0184 [004234DC] eb 01                                        jmp     short near ptr unk_4234DF ; game-relative-target=0x000A0187
000A0186 [004234DE] c3                                           retn
000A0187 [004234DF] 80 4c 83 44 80                               or      byte ptr [ebx+eax*4+44h], 80h
000A018C [004234E4] eb dc                                        jmp     short near ptr unk_4234C2 ; game-relative-target=0x000A016A
