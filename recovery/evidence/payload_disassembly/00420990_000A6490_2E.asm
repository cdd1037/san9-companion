; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00420990; baseline game VA=0x000A6490; size=46
; Relative branch annotations use the baseline game destination.
000A6490 [00420990] 33 c0                                        xor     eax, eax
000A6492 [00420992] 83 79 58 50                                  cmp     dword ptr [ecx+58h], 50h ; 'P'
000A6496 [00420996] 7e 02                                        jle     short near ptr unk_42099A ; game-relative-target=0x000A649A
000A6498 [00420998] 0c 04                                        or      al, 4
000A649A [0042099A] 8b 51 54                                     mov     edx, [ecx+54h]
000A649D [0042099D] 2b 51 4c                                     sub     edx, [ecx+4Ch]
000A64A0 [004209A0] 83 fa 08                                     cmp     edx, 8
000A64A3 [004209A3] 7d 01                                        jge     short near ptr unk_4209A6 ; game-relative-target=0x000A64A6
000A64A5 [004209A5] c3                                           retn
000A64A6 [004209A6] 83 79 58 46                                  cmp     dword ptr [ecx+58h], 46h ; 'F'
000A64AA [004209AA] 7c 02                                        jl      short near ptr unk_4209AE ; game-relative-target=0x000A64AE
000A64AC [004209AC] 0c 01                                        or      al, 1
000A64AE [004209AE] 50                                           push    eax
000A64AF [004209AF] 6a 16                                        push    16h
000A64B1 [004209B1] b8 70 f7 44 00                               mov     eax, 44F770h
000A64B6 [004209B6] ff d0                                        call    eax
000A64B8 [004209B8] 59                                           pop     ecx
000A64B9 [004209B9] d0 e0                                        shl     al, 1
000A64BB [004209BB] 08 c8                                        or      al, cl
000A64BD [004209BD] c3                                           retn
