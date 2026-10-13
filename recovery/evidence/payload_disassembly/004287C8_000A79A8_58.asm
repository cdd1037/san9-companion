; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004287C8; baseline game VA=0x000A79A8; size=88
; Relative branch annotations use the baseline game destination.
000A79A8 [004287C8] 8b 81 c4 01 00 00                            mov     eax, [ecx+1C4h]
000A79AE [004287CE] 0f b6 49 04                                  movzx   ecx, byte ptr [ecx+4]
000A79B2 [004287D2] 0f b6 89 ce 79 0a 00                         movzx   ecx, byte ptr [ecx+0A79CEh]
000A79B9 [004287D9] 0f af c8                                     imul    ecx, eax
000A79BC [004287DC] b8 1f 85 eb 51                               mov     eax, 51EB851Fh
000A79C1 [004287E1] f7 e9                                        imul    ecx
000A79C3 [004287E3] c1 fa 05                                     sar     edx, 5
000A79C6 [004287E6] 8b c2                                        mov     eax, edx
000A79C8 [004287E8] c1 e8 1f                                     shr     eax, 1Fh
000A79CB [004287EB] 03 c2                                        add     eax, edx
000A79CD [004287ED] c3                                           retn
000A79CE [004287EE] 41                                           inc     ecx
000A79CF [004287EF] 41                                           inc     ecx
000A79D0 [004287F0] 64 74 64                                     jz      short near ptr dword_428854+3 ; game-relative-target=0x000A7A37
000A79D3 [004287F3] 96                                           xchg    eax, esi
000A79D4 [004287F4] 64 64 74 74                                  jz      short near ptr unk_42886C ; game-relative-target=0x000A7A4C
000A79D8 [004287F8] 74 96                                        jz      short near ptr unk_428790 ; game-relative-target=0x000A7970
000A79DA [004287FA] 64 74 74                                     jz      short near ptr dword_428870+1 ; game-relative-target=0x000A7A51
000A79DD [004287FD] c8 c8 41 41                                  enter   41C8h, 41h ; 'A'
000A79E1 [00428801] 41                                           inc     ecx
000A79E2 [00428802] 41                                           inc     ecx
000A79E3 [00428803] 74 64                                        jz      short near ptr unk_428869 ; game-relative-target=0x000A7A49
000A79E5 [00428805] 96                                           xchg    eax, esi
000A79E6 [00428806] 64 41                                        inc     ecx
000A79E8 [00428808] 74 74                                        jz      short near ptr dword_42887C+2 ; game-relative-target=0x000A7A5E
000A79EA [0042880A] 41                                           inc     ecx
000A79EB [0042880B] 96                                           xchg    eax, esi
000A79EC [0042880C] 74 64                                        jz      short near ptr dword_428870+2 ; game-relative-target=0x000A7A52
000A79EE [0042880E] 74 41                                        jz      short near ptr dword_428850+1 ; game-relative-target=0x000A7A31
000A79F0 [00428810] 41                                           inc     ecx
000A79F1 [00428811] 41                                           inc     ecx
000A79F2 [00428812] 41                                           inc     ecx
000A79F3 [00428813] 41                                           inc     ecx
000A79F4 [00428814] 74 41                                        jz      short near ptr dword_428854+3 ; game-relative-target=0x000A7A37
000A79F6 [00428816] 96                                           xchg    eax, esi
000A79F7 [00428817] 64 41                                        inc     ecx
000A79F9 [00428819] 41                                           inc     ecx
000A79FA [0042881A] 74 64                                        jz      short near ptr dword_428880 ; game-relative-target=0x000A7A60
000A79FC [0042881C] 41                                           inc     ecx
000A79FD [0042881D] 41                                           inc     ecx
000A79FE [0042881E] 41                                           inc     ecx
000A79FF [0042881F] 41                                           inc     ecx
