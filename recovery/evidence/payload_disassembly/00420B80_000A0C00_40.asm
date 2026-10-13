; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00420B80; baseline game VA=0x000A0C00; size=64
; Relative branch annotations use the baseline game destination.
000A0C00 [00420B80] b8 80 f1 43 00                               mov     eax, 43F180h
000A0C05 [00420B85] ff d0                                        call    eax
000A0C07 [00420B87] 8b 54 24 38                                  mov     edx, [esp+38h]
000A0C0B [00420B8B] 85 d2                                        test    edx, edx
000A0C0D [00420B8D] 75 01                                        jnz     short near ptr unk_420B90 ; game-relative-target=0x000A0C10
000A0C0F [00420B8F] c3                                           retn
000A0C10 [00420B90] 50                                           push    eax
000A0C11 [00420B91] 55                                           push    ebp
000A0C12 [00420B92] bd b0 93 4b 01                               mov     ebp, 14B93B0h
000A0C17 [00420B97] f6 45 20 02                                  test    byte ptr [ebp+20h], 2
000A0C1B [00420B9B] 75 12                                        jnz     short near ptr unk_420BAF ; game-relative-target=0x000A0C2F
000A0C1D [00420B9D] 39 75 74                                     cmp     [ebp+74h], esi
000A0C20 [00420BA0] 75 0d                                        jnz     short near ptr unk_420BAF ; game-relative-target=0x000A0C2F
000A0C22 [00420BA2] 55                                           push    ebp
000A0C23 [00420BA3] b9 20 05 0a 00                               mov     ecx, 0A0520h
000A0C28 [00420BA8] b8 70 ef 46 00                               mov     eax, 46EF70h
000A0C2D [00420BAD] ff d0                                        call    eax
000A0C2F [00420BAF] 81 c5 04 01 00 00                            add     ebp, 104h
000A0C35 [00420BB5] 66 81 7d 04 51 03                            cmp     word ptr [ebp+4], 351h
000A0C3B [00420BBB] 7c da                                        jl      short near ptr unk_420B97 ; game-relative-target=0x000A0C17
000A0C3D [00420BBD] 5d                                           pop     ebp
000A0C3E [00420BBE] 58                                           pop     eax
000A0C3F [00420BBF] c3                                           retn
