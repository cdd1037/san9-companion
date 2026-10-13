; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00423978; baseline game VA=0x004B59BC; size=20
; Relative branch annotations use the baseline game destination.
004B59BC [00423978] 3d 88 13 00 00                               cmp     eax, 1388h
004B59C1 [0042397D] 7e 17                                        jle     short near ptr unk_423996 ; game-relative-target=0x004B59DA
004B59C3 [0042397F] 8b 4c 24 34                                  mov     ecx, [esp+34h]
004B59C7 [00423983] 8b d6                                        mov     edx, esi
004B59C9 [00423985] e8 2a e2 be ff                               call    near ptr 11BB4h ; game-relative-target=0x000A3BF8
004B59CE [0042398A] 8b e8                                        mov     ebp, eax
