; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042A098; baseline game VA=0x000A82B0; size=110
; Relative branch annotations use the baseline game destination.
000A82B0 [0042A098] a1 a6 82 0a 00                               mov     eax, ds:0A82A6h
000A82B5 [0042A09D] 83 f8 01                                     cmp     eax, 1
000A82B8 [0042A0A0] 7f 0d                                        jg      short near ptr unk_42A0AF ; game-relative-target=0x000A82C7
000A82BA [0042A0A2] b8 90 82 0a 00                               mov     eax, 0A8290h
000A82BF [0042A0A7] ff d0                                        call    eax
000A82C1 [0042A0A9] 68 00 5a 48 00                               push    485A00h
000A82C6 [0042A0AE] c3                                           retn
000A82C7 [0042A0AF] 55                                           push    ebp
000A82C8 [0042A0B0] 57                                           push    edi
000A82C9 [0042A0B1] 53                                           push    ebx
000A82CA [0042A0B2] bd ac 55 54 01                               mov     ebp, 15455ACh
000A82CF [0042A0B7] 8b 3d 04 05 0a 00                            mov     edi, ds:0A0504h
000A82D5 [0042A0BD] 8b 4f 08                                     mov     ecx, [edi+8]
000A82D8 [0042A0C0] 8b 01                                        mov     eax, [ecx]
000A82DA [0042A0C2] ff 50 34                                     call    dword ptr [eax+34h]
000A82DD [0042A0C5] 8d 58 34                                     lea     ebx, [eax+34h]
000A82E0 [0042A0C8] 8b cd                                        mov     ecx, ebp
000A82E2 [0042A0CA] b8 e0 80 51 00                               mov     eax, 5180E0h
000A82E7 [0042A0CF] ff d0                                        call    eax
000A82E9 [0042A0D1] 8b 57 08                                     mov     edx, [edi+8]
000A82EC [0042A0D4] 52                                           push    edx
000A82ED [0042A0D5] 8b cd                                        mov     ecx, ebp
000A82EF [0042A0D7] b8 70 ef 46 00                               mov     eax, 46EF70h
000A82F4 [0042A0DC] ff d0                                        call    eax
000A82F6 [0042A0DE] 8b ce                                        mov     ecx, esi
000A82F8 [0042A0E0] 8b 06                                        mov     eax, [esi]
000A82FA [0042A0E2] ff 50 2c                                     call    dword ptr [eax+2Ch]
000A82FD [0042A0E5] 3b 3d 04 05 0a 00                            cmp     edi, ds:0A0504h
000A8303 [0042A0EB] 75 05                                        jnz     short near ptr unk_42A0F2 ; game-relative-target=0x000A830A
000A8305 [0042A0ED] ff 33                                        push    dword ptr [ebx]
000A8307 [0042A0EF] 80 23 fe                                     and     byte ptr [ebx], 0FEh
000A830A [0042A0F2] 8b 3f                                        mov     edi, [edi]
000A830C [0042A0F4] 85 ff                                        test    edi, edi
000A830E [0042A0F6] 75 d0                                        jnz     short near ptr unk_42A0C8 ; game-relative-target=0x000A82E0
000A8310 [0042A0F8] 58                                           pop     eax
000A8311 [0042A0F9] 24 01                                        and     al, 1
000A8313 [0042A0FB] 08 03                                        or      [ebx], al
000A8315 [0042A0FD] 5b                                           pop     ebx
000A8316 [0042A0FE] 5f                                           pop     edi
000A8317 [0042A0FF] 5d                                           pop     ebp
000A8318 [0042A100] 68 90 82 0a 00                               push    0A8290h
000A831D [0042A105] c3                                           retn
