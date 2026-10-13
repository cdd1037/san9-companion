; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00428600; baseline game VA=0x000A75B0; size=71
; Relative branch annotations use the baseline game destination.
000A75B0 [00428600] 8b ce                                        mov     ecx, esi
000A75B2 [00428602] ff 50 34                                     call    dword ptr [eax+34h]
000A75B5 [00428605] f6 40 34 01                                  test    byte ptr [eax+34h], 1
000A75B9 [00428609] 75 01                                        jnz     short near ptr unk_42860C ; game-relative-target=0x000A75BC
000A75BB [0042860B] c3                                           retn
000A75BC [0042860C] 80 3c 24 af                                  cmp     byte ptr [esp], 0AFh
000A75C0 [00428610] 57                                           push    edi
000A75C1 [00428611] 8b f8                                        mov     edi, eax
000A75C3 [00428613] 74 02                                        jz      short near ptr unk_428617 ; game-relative-target=0x000A75C7
000A75C5 [00428615] d1 eb                                        shr     ebx, 1
000A75C7 [00428617] 8b cf                                        mov     ecx, edi
000A75C9 [00428619] b8 00 32 44 00                               mov     eax, 443200h
000A75CE [0042861E] ff d0                                        call    eax
000A75D0 [00428620] 50                                           push    eax
000A75D1 [00428621] 8b cf                                        mov     ecx, edi
000A75D3 [00428623] b8 70 31 44 00                               mov     eax, 443170h
000A75D8 [00428628] ff d0                                        call    eax
000A75DA [0042862A] 5a                                           pop     edx
000A75DB [0042862B] 2b c2                                        sub     eax, edx
000A75DD [0042862D] 85 c0                                        test    eax, eax
000A75DF [0042862F] 7e 12                                        jle     short near ptr unk_428643 ; game-relative-target=0x000A75F3
000A75E1 [00428631] c1 e8 0d                                     shr     eax, 0Dh
000A75E4 [00428634] 83 f8 7f                                     cmp     eax, 7Fh
000A75E7 [00428637] 7f 08                                        jg      short near ptr unk_428641 ; game-relative-target=0x000A75F1
000A75E9 [00428639] 3a 05 c3 64 0a 00                            cmp     al, ds:0A64C3h
000A75EF [0042863F] 7c 02                                        jl      short near ptr unk_428643 ; game-relative-target=0x000A75F3
000A75F1 [00428641] d1 eb                                        shr     ebx, 1
000A75F3 [00428643] 8b c7                                        mov     eax, edi
000A75F5 [00428645] 5f                                           pop     edi
000A75F6 [00428646] c3                                           retn
