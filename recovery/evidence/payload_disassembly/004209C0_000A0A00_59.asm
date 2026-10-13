; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004209C0; baseline game VA=0x000A0A00; size=89
; Relative branch annotations use the baseline game destination.
000A0A00 [004209C0] 85 c0                                        test    eax, eax
000A0A02 [004209C2] 75 06                                        jnz     short near ptr unk_4209CA ; game-relative-target=0x000A0A0A
000A0A04 [004209C4] 8b 4e 0c                                     mov     ecx, [esi+0Ch]
000A0A07 [004209C7] 33 c0                                        xor     eax, eax
000A0A09 [004209C9] c3                                           retn
000A0A0A [004209CA] 57                                           push    edi
000A0A0B [004209CB] 55                                           push    ebp
000A0A0C [004209CC] 8b 7e 04                                     mov     edi, [esi+4]
000A0A0F [004209CF] 8b ab f4 00 00 00                            mov     ebp, [ebx+0F4h]
000A0A15 [004209D5] f7 45 20 01 00 00 00                         test    dword ptr [ebp+20h], 1
000A0A1C [004209DC] 74 03                                        jz      short near ptr unk_4209E1 ; game-relative-target=0x000A0A21
000A0A1E [004209DE] 8b 6d 64                                     mov     ebp, [ebp+64h]
000A0A21 [004209E1] 8b 4f 08                                     mov     ecx, [edi+8]
000A0A24 [004209E4] 8b 89 f4 00 00 00                            mov     ecx, [ecx+0F4h]
000A0A2A [004209EA] ff 71 64                                     push    dword ptr [ecx+64h]
000A0A2D [004209ED] 8b cd                                        mov     ecx, ebp
000A0A2F [004209EF] b8 80 0a 0a 00                               mov     eax, 0A0A80h
000A0A34 [004209F4] ff d0                                        call    eax
000A0A36 [004209F6] 83 c0 1d                                     add     eax, 1Dh
000A0A39 [004209F9] 99                                           cdq
000A0A3A [004209FA] b9 1e 00 00 00                               mov     ecx, 1Eh
000A0A3F [004209FF] f7 f1                                        div     ecx
000A0A41 [00420A01] 83 f8 0f                                     cmp     eax, 0Fh
000A0A44 [00420A04] 7e 0f                                        jle     short near ptr unk_420A15 ; game-relative-target=0x000A0A55
000A0A46 [00420A06] 8b 3f                                        mov     edi, [edi]
000A0A48 [00420A08] 8b ce                                        mov     ecx, esi
000A0A4A [00420A0A] b8 10 82 51 00                               mov     eax, 518210h
000A0A4F [00420A0F] ff d0                                        call    eax
000A0A51 [00420A11] 85 ff                                        test    edi, edi
000A0A53 [00420A13] 75 cc                                        jnz     short near ptr unk_4209E1 ; game-relative-target=0x000A0A21
000A0A55 [00420A15] 5d                                           pop     ebp
000A0A56 [00420A16] 5f                                           pop     edi
000A0A57 [00420A17] eb ab                                        jmp     short near ptr unk_4209C4 ; game-relative-target=0x000A0A04
