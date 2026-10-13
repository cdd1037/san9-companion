; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00422318; baseline game VA=0x000A1D30; size=60
; Relative branch annotations use the baseline game destination.
000A1D30 [00422318] b8 03 00 00 00                               mov     eax, 3
000A1D35 [0042231D] 8b 51 74                                     mov     edx, [ecx+74h]
000A1D38 [00422320] 8b 92 b8 00 00 00                            mov     edx, [edx+0B8h]
000A1D3E [00422326] f6 42 34 01                                  test    byte ptr [edx+34h], 1
000A1D42 [0042232A] 75 01                                        jnz     short near ptr unk_42232D ; game-relative-target=0x000A1D45
000A1D44 [0042232C] 40                                           inc     eax
000A1D45 [0042232D] 50                                           push    eax
000A1D46 [0042232E] 50                                           push    eax
000A1D47 [0042232F] 57                                           push    edi
000A1D48 [00422330] b8 c0 0d 46 00                               mov     eax, 460DC0h
000A1D4D [00422335] ff d0                                        call    eax
000A1D4F [00422337] 6a 02                                        push    2
000A1D51 [00422339] 57                                           push    edi
000A1D52 [0042233A] 8d 4e c8                                     lea     ecx, [esi-38h]
000A1D55 [0042233D] b8 c0 0d 46 00                               mov     eax, 460DC0h
000A1D5A [00422342] ff d0                                        call    eax
000A1D5C [00422344] 58                                           pop     eax
000A1D5D [00422345] 50                                           push    eax
000A1D5E [00422346] 57                                           push    edi
000A1D5F [00422347] 8b 4e 30                                     mov     ecx, [esi+30h]
000A1D62 [0042234A] b8 80 dc 44 00                               mov     eax, 44DC80h
000A1D67 [0042234F] ff d0                                        call    eax
000A1D69 [00422351] c2 08 00                                     retn    8
