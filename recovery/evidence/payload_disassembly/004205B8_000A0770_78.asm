; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004205B8; baseline game VA=0x000A0770; size=120
; Relative branch annotations use the baseline game destination.
000A0770 [004205B8] 8b ce                                        mov     ecx, esi
000A0772 [004205BA] b8 90 e3 45 00                               mov     eax, 45E390h
000A0777 [004205BF] ff d0                                        call    eax
000A0779 [004205C1] 85 c0                                        test    eax, eax
000A077B [004205C3] ba 11 00 00 00                               mov     edx, 11h
000A0780 [004205C8] 75 1a                                        jnz     short near ptr unk_4205E4 ; game-relative-target=0x000A079C
000A0782 [004205CA] 8b 4e 6c                                     mov     ecx, [esi+6Ch]
000A0785 [004205CD] 8a 41 04                                     mov     al, [ecx+4]
000A0788 [004205D0] 3c 0a                                        cmp     al, 0Ah
000A078A [004205D2] 74 29                                        jz      short near ptr unk_4205FD ; game-relative-target=0x000A07B5
000A078C [004205D4] 3c 02                                        cmp     al, 2
000A078E [004205D6] 74 2e                                        jz      short near ptr unk_420606 ; game-relative-target=0x000A07BE
000A0790 [004205D8] 3c 06                                        cmp     al, 6
000A0792 [004205DA] 75 04                                        jnz     short near ptr unk_4205E0 ; game-relative-target=0x000A0798
000A0794 [004205DC] b2 08                                        mov     dl, 8
000A0796 [004205DE] eb 1d                                        jmp     short near ptr unk_4205FD ; game-relative-target=0x000A07B5
000A0798 [004205E0] 3c 03                                        cmp     al, 3
000A079A [004205E2] 7e f8                                        jle     short near ptr unk_4205DC ; game-relative-target=0x000A0794
000A079C [004205E4] 8b 46 30                                     mov     eax, [esi+30h]
000A079F [004205E7] 3d 00 20 00 00                               cmp     eax, 2000h
000A07A4 [004205EC] 7d 0f                                        jge     short near ptr unk_4205FD ; game-relative-target=0x000A07B5
000A07A6 [004205EE] 81 7e 34 00 10 00 00                         cmp     dword ptr [esi+34h], 1000h
000A07AD [004205F5] 7d 06                                        jge     short near ptr unk_4205FD ; game-relative-target=0x000A07B5
000A07AF [004205F7] 0f af d0                                     imul    edx, eax
000A07B2 [004205FA] c1 ea 0d                                     shr     edx, 0Dh
000A07B5 [004205FD] 3b fa                                        cmp     edi, edx
000A07B7 [004205FF] 7e 04                                        jle     short near ptr unk_420605 ; game-relative-target=0x000A07BD
000A07B9 [00420601] c6 04 24 6d                                  mov     byte ptr [esp], 6Dh ; 'm'
000A07BD [00420605] c3                                           retn
000A07BE [00420606] b2 08                                        mov     dl, 8
000A07C0 [00420608] 8b 8e 88 00 00 00                            mov     ecx, [esi+88h]
000A07C6 [0042060E] 8b 41 08                                     mov     eax, [ecx+8]
000A07C9 [00420611] 8b 09                                        mov     ecx, [ecx]
000A07CB [00420613] 8b 80 f8 00 00 00                            mov     eax, [eax+0F8h]
000A07D1 [00420619] 85 c0                                        test    eax, eax
000A07D3 [0042061B] 74 0d                                        jz      short near ptr unk_42062A ; game-relative-target=0x000A07E2
000A07D5 [0042061D] 8a 40 04                                     mov     al, [eax+4]
000A07D8 [00420620] 3c 06                                        cmp     al, 6
000A07DA [00420622] 7c 06                                        jl      short near ptr unk_42062A ; game-relative-target=0x000A07E2
000A07DC [00420624] 3c 08                                        cmp     al, 8
000A07DE [00420626] 7f 02                                        jg      short near ptr unk_42062A ; game-relative-target=0x000A07E2
000A07E0 [00420628] 42                                           inc     edx
000A07E1 [00420629] 42                                           inc     edx
000A07E2 [0042062A] 85 c9                                        test    ecx, ecx
000A07E4 [0042062C] 75 e0                                        jnz     short near ptr unk_42060E ; game-relative-target=0x000A07C6
000A07E6 [0042062E] eb b4                                        jmp     short near ptr unk_4205E4 ; game-relative-target=0x000A079C
