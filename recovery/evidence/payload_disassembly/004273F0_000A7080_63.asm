; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004273F0; baseline game VA=0x000A7080; size=99
; Relative branch annotations use the baseline game destination.
000A7080 [004273F0] 51                                           push    ecx
000A7081 [004273F1] 57                                           push    edi
000A7082 [004273F2] b8 60 eb 46 00                               mov     eax, 46EB60h
000A7087 [004273F7] ff d0                                        call    eax
000A7089 [004273F9] 85 c0                                        test    eax, eax
000A708B [004273FB] 74 04                                        jz      short near ptr unk_427401 ; game-relative-target=0x000A7091
000A708D [004273FD] 59                                           pop     ecx
000A708E [004273FE] c2 04 00                                     retn    4
000A7091 [00427401] b8 d0 64 0a 00                               mov     eax, 0A64D0h
000A7096 [00427406] ff d0                                        call    eax
000A7098 [00427408] 85 c0                                        test    eax, eax
000A709A [0042740A] 74 f1                                        jz      short near ptr unk_4273FD ; game-relative-target=0x000A708D
000A709C [0042740C] 50                                           push    eax
000A709D [0042740D] 8b ce                                        mov     ecx, esi
000A709F [0042740F] b8 40 57 43 00                               mov     eax, 435740h
000A70A4 [00427414] ff d0                                        call    eax
000A70A6 [00427416] 85 c0                                        test    eax, eax
000A70A8 [00427418] 74 e3                                        jz      short near ptr unk_4273FD ; game-relative-target=0x000A708D
000A70AA [0042741A] ff 74 24 2c                                  push    dword ptr [esp+2Ch]
000A70AE [0042741E] b8 80 8c 50 00                               mov     eax, 508C80h
000A70B3 [00427423] ff d0                                        call    eax
000A70B5 [00427425] 59                                           pop     ecx
000A70B6 [00427426] 0f b6 15 8f f8 43 00                         movzx   edx, byte ptr ds:43F88Fh
000A70BD [0042742D] f7 ea                                        imul    edx
000A70BF [0042742F] 99                                           cdq
000A70C0 [00427430] 6a 06                                        push    6
000A70C2 [00427432] 59                                           pop     ecx
000A70C3 [00427433] f7 f9                                        idiv    ecx
000A70C5 [00427435] 50                                           push    eax
000A70C6 [00427436] b8 f0 ef 4a 00                               mov     eax, 4AEFF0h
000A70CB [0042743B] ff d0                                        call    eax
000A70CD [0042743D] 85 c0                                        test    eax, eax
000A70CF [0042743F] 74 04                                        jz      short near ptr unk_427445 ; game-relative-target=0x000A70D5
000A70D1 [00427441] 33 c0                                        xor     eax, eax
000A70D3 [00427443] eb b8                                        jmp     short near ptr unk_4273FD ; game-relative-target=0x000A708D
000A70D5 [00427445] 59                                           pop     ecx
000A70D6 [00427446] 57                                           push    edi
000A70D7 [00427447] b8 70 ef 46 00                               mov     eax, 46EF70h
000A70DC [0042744C] ff d0                                        call    eax
000A70DE [0042744E] b0 01                                        mov     al, 1
000A70E0 [00427450] c2 04 00                                     retn    4
