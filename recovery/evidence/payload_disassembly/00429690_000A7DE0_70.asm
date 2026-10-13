; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00429690; baseline game VA=0x000A7DE0; size=112
; Relative branch annotations use the baseline game destination.
000A7DE0 [00429690] 57                                           push    edi
000A7DE1 [00429691] 8b 7c 24 08                                  mov     edi, [esp+8]
000A7DE5 [00429695] 8b 0f                                        mov     ecx, [edi]
000A7DE7 [00429697] b8 70 7e 0a 00                               mov     eax, 0A7E70h
000A7DEC [0042969C] ff d0                                        call    eax
000A7DEE [0042969E] 33 d2                                        xor     edx, edx
000A7DF0 [004296A0] 85 c0                                        test    eax, eax
000A7DF2 [004296A2] 78 06                                        js      short near ptr unk_4296AA ; game-relative-target=0x000A7DFA
000A7DF4 [004296A4] 3b 47 04                                     cmp     eax, [edi+4]
000A7DF7 [004296A7] 0f 94 c2                                     setz    dl
000A7DFA [004296AA] 8b c2                                        mov     eax, edx
000A7DFC [004296AC] 5f                                           pop     edi
000A7DFD [004296AD] c3                                           retn
000A7DFE [004296AE] 90                                           nop
000A7DFF [004296AF] 90                                           nop
000A7E00 [004296B0] 8b 50 0c                                     mov     edx, [eax+0Ch]
000A7E03 [004296B3] 85 d2                                        test    edx, edx
000A7E05 [004296B5] 75 43                                        jnz     short near ptr unk_4296FA ; game-relative-target=0x000A7E4A
000A7E07 [004296B7] 8b 5f 04                                     mov     ebx, [edi+4]
000A7E0A [004296BA] 8b 4b 08                                     mov     ecx, [ebx+8]
000A7E0D [004296BD] b8 70 7e 0a 00                               mov     eax, 0A7E70h
000A7E12 [004296C2] ff d0                                        call    eax
000A7E14 [004296C4] 85 c0                                        test    eax, eax
000A7E16 [004296C6] 7c 32                                        jl      short near ptr unk_4296FA ; game-relative-target=0x000A7E4A
000A7E18 [004296C8] 6a 00                                        push    0
000A7E1A [004296CA] 50                                           push    eax
000A7E1B [004296CB] 68 e0 7d 0a 00                               push    0A7DE0h
000A7E20 [004296D0] 57                                           push    edi
000A7E21 [004296D1] 8d 4f 20                                     lea     ecx, [edi+20h]
000A7E24 [004296D4] b8 f0 f3 46 00                               mov     eax, 46F3F0h
000A7E29 [004296D9] ff d0                                        call    eax
000A7E2B [004296DB] 83 f8 03                                     cmp     eax, 3
000A7E2E [004296DE] 7d 0f                                        jge     short near ptr unk_4296EF ; game-relative-target=0x000A7E3F
000A7E30 [004296E0] b8 e0 80 51 00                               mov     eax, 5180E0h
000A7E35 [004296E5] ff d0                                        call    eax
000A7E37 [004296E7] 8b 1b                                        mov     ebx, [ebx]
000A7E39 [004296E9] 85 db                                        test    ebx, ebx
000A7E3B [004296EB] 75 cd                                        jnz     short near ptr unk_4296BA ; game-relative-target=0x000A7E0A
000A7E3D [004296ED] eb 0b                                        jmp     short near ptr unk_4296FA ; game-relative-target=0x000A7E4A
000A7E3F [004296EF] ff 74 24 0c                                  push    dword ptr [esp+0Ch]
000A7E43 [004296F3] b8 b0 ee 46 00                               mov     eax, 46EEB0h
000A7E48 [004296F8] ff d0                                        call    eax
000A7E4A [004296FA] 68 00 05 57 00                               push    570500h
000A7E4F [004296FF] c3                                           retn
