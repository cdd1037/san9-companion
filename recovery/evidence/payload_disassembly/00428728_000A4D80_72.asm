; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00428728; baseline game VA=0x000A4D80; size=114
; Relative branch annotations use the baseline game destination.
000A4D80 [00428728] 51                                           push    ecx
000A4D81 [00428729] 57                                           push    edi
000A4D82 [0042872A] bf d3 4d 62 10                               mov     edi, 10624DD3h
000A4D87 [0042872F] 8b ce                                        mov     ecx, esi
000A4D89 [00428731] 8b 01                                        mov     eax, [ecx]
000A4D8B [00428733] ff 50 30                                     call    dword ptr [eax+30h]
000A4D8E [00428736] 85 c0                                        test    eax, eax
000A4D90 [00428738] 74 5b                                        jz      short near ptr unk_428795 ; game-relative-target=0x000A4DED
000A4D92 [0042873A] f6 40 34 01                                  test    byte ptr [eax+34h], 1
000A4D96 [0042873E] 75 0b                                        jnz     short near ptr unk_42874B ; game-relative-target=0x000A4DA3
000A4D98 [00428740] 80 3d 16 ff 43 00 00                         cmp     byte ptr ds:43FF16h, 0
000A4D9F [00428747] 74 02                                        jz      short near ptr unk_42874B ; game-relative-target=0x000A4DA3
000A4DA1 [00428749] d1 e7                                        shl     edi, 1
000A4DA3 [0042874B] 50                                           push    eax
000A4DA4 [0042874C] 8b c8                                        mov     ecx, eax
000A4DA6 [0042874E] b8 00 32 44 00                               mov     eax, 443200h
000A4DAB [00428753] ff d0                                        call    eax
000A4DAD [00428755] 59                                           pop     ecx
000A4DAE [00428756] 50                                           push    eax
000A4DAF [00428757] b8 70 31 44 00                               mov     eax, 443170h
000A4DB4 [0042875C] ff d0                                        call    eax
000A4DB6 [0042875E] 5a                                           pop     edx
000A4DB7 [0042875F] 2b c2                                        sub     eax, edx
000A4DB9 [00428761] 85 c0                                        test    eax, eax
000A4DBB [00428763] 7e 30                                        jle     short near ptr unk_428795 ; game-relative-target=0x000A4DED
000A4DBD [00428765] c1 e8 0d                                     shr     eax, 0Dh
000A4DC0 [00428768] 83 f8 7f                                     cmp     eax, 7Fh
000A4DC3 [0042876B] 7e 05                                        jle     short near ptr unk_428772 ; game-relative-target=0x000A4DCA
000A4DC5 [0042876D] c1 ef 02                                     shr     edi, 2
000A4DC8 [00428770] eb 23                                        jmp     short near ptr unk_428795 ; game-relative-target=0x000A4DED
000A4DCA [00428772] 8b d7                                        mov     edx, edi
000A4DCC [00428774] c1 ea 02                                     shr     edx, 2
000A4DCF [00428777] 3a 05 c3 64 0a 00                            cmp     al, ds:0A64C3h
000A4DD5 [0042877D] 7c 16                                        jl      short near ptr unk_428795 ; game-relative-target=0x000A4DED
000A4DD7 [0042877F] 2b fa                                        sub     edi, edx
000A4DD9 [00428781] 3a 05 c4 64 0a 00                            cmp     al, ds:0A64C4h
000A4DDF [00428787] 7c 0c                                        jl      short near ptr unk_428795 ; game-relative-target=0x000A4DED
000A4DE1 [00428789] 2b fa                                        sub     edi, edx
000A4DE3 [0042878B] 3a 05 c5 64 0a 00                            cmp     al, ds:0A64C5h
000A4DE9 [00428791] 7c 02                                        jl      short near ptr unk_428795 ; game-relative-target=0x000A4DED
000A4DEB [00428793] 2b fa                                        sub     edi, edx
000A4DED [00428795] 8b c7                                        mov     eax, edi
000A4DEF [00428797] 5f                                           pop     edi
000A4DF0 [00428798] 59                                           pop     ecx
000A4DF1 [00428799] c3                                           retn
