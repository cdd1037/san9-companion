; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00426C20; baseline game VA=0x000A7200; size=106
; Relative branch annotations use the baseline game destination.
000A7200 [00426C20] 89 41 50                                     mov     [ecx+50h], eax
000A7203 [00426C23] 58                                           pop     eax
000A7204 [00426C24] 5a                                           pop     edx
000A7205 [00426C25] 50                                           push    eax
000A7206 [00426C26] 53                                           push    ebx
000A7207 [00426C27] b8 d0 64 0a 00                               mov     eax, 0A64D0h
000A720C [00426C2C] ff d0                                        call    eax
000A720E [00426C2E] 85 c0                                        test    eax, eax
000A7210 [00426C30] 75 02                                        jnz     short near ptr unk_426C34 ; game-relative-target=0x000A7214
000A7212 [00426C32] 5b                                           pop     ebx
000A7213 [00426C33] c3                                           retn
000A7214 [00426C34] 8b 88 bc 00 00 00                            mov     ecx, [eax+0BCh]
000A721A [00426C3A] 8d 59 10                                     lea     ebx, [ecx+10h]
000A721D [00426C3D] 8d 46 68                                     lea     eax, [esi+68h]
000A7220 [00426C40] 50                                           push    eax
000A7221 [00426C41] 8b cb                                        mov     ecx, ebx
000A7223 [00426C43] b8 20 63 0a 00                               mov     eax, 0A6320h
000A7228 [00426C48] ff d0                                        call    eax
000A722A [00426C4A] 85 c0                                        test    eax, eax
000A722C [00426C4C] 74 e4                                        jz      short near ptr unk_426C32 ; game-relative-target=0x000A7212
000A722E [00426C4E] ff 36                                        push    dword ptr [esi]
000A7230 [00426C50] b8 c0 32 45 00                               mov     eax, 4532C0h
000A7235 [00426C55] ff d0                                        call    eax
000A7237 [00426C57] 5a                                           pop     edx
000A7238 [00426C58] 80 3d 15 ff 43 00 0a                         cmp     byte ptr ds:43FF15h, 0Ah
000A723F [00426C5F] 7c 0c                                        jl      short near ptr unk_426C6D ; game-relative-target=0x000A724D
000A7241 [00426C61] 8b 40 48                                     mov     eax, [eax+48h]
000A7244 [00426C64] 85 c0                                        test    eax, eax
000A7246 [00426C66] 7e 15                                        jle     short near ptr unk_426C7D ; game-relative-target=0x000A725D
000A7248 [00426C68] 88 47 2f                                     mov     [edi+2Fh], al
000A724B [00426C6B] eb 0a                                        jmp     short near ptr unk_426C77 ; game-relative-target=0x000A7257
000A724D [00426C6D] 8a 47 2f                                     mov     al, [edi+2Fh]
000A7250 [00426C70] 84 c0                                        test    al, al
000A7252 [00426C72] 7e 09                                        jle     short near ptr unk_426C7D ; game-relative-target=0x000A725D
000A7254 [00426C74] fe 4f 2f                                     dec     byte ptr [edi+2Fh]
000A7257 [00426C77] 80 66 28 fe                                  and     byte ptr [esi+28h], 0FEh
000A725B [00426C7B] 5b                                           pop     ebx
000A725C [00426C7C] c3                                           retn
000A725D [00426C7D] b8 80 72 0a 00                               mov     eax, 0A7280h
000A7262 [00426C82] ff d0                                        call    eax
000A7264 [00426C84] 85 c0                                        test    eax, eax
000A7266 [00426C86] 74 ef                                        jz      short near ptr unk_426C77 ; game-relative-target=0x000A7257
000A7268 [00426C88] 5b                                           pop     ebx
000A7269 [00426C89] c3                                           retn
