; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00422F20; baseline game VA=0x000A2A60; size=56
; Relative branch annotations use the baseline game destination.
000A2A60 [00422F20] 8b 87 88 00 00 00                            mov     eax, [edi+88h]
000A2A66 [00422F26] 3d b8 0b 00 00                               cmp     eax, 0BB8h
000A2A6B [00422F2B] 7d 23                                        jge     short near ptr unk_422F50 ; game-relative-target=0x000A2A90
000A2A6D [00422F2D] 8b 44 24 04                                  mov     eax, [esp+4]
000A2A71 [00422F31] 8b 00                                        mov     eax, [eax]
000A2A73 [00422F33] 6a 14                                        push    14h
000A2A75 [00422F35] 6a 0c                                        push    0Ch
000A2A77 [00422F37] 50                                           push    eax
000A2A78 [00422F38] 57                                           push    edi
000A2A79 [00422F39] b8 80 a6 44 00                               mov     eax, 44A680h
000A2A7E [00422F3E] ff d0                                        call    eax
000A2A80 [00422F40] 83 c4 10                                     add     esp, 10h
000A2A83 [00422F43] 83 f8 10                                     cmp     eax, 10h
000A2A86 [00422F46] 7f 08                                        jg      short near ptr unk_422F50 ; game-relative-target=0x000A2A90
000A2A88 [00422F48] 68 6c 87 4b 00                               push    4B876Ch
000A2A8D [00422F4D] c2 08 00                                     retn    8
000A2A90 [00422F50] 8b cd                                        mov     ecx, ebp
000A2A92 [00422F52] 68 60 77 4b 00                               push    4B7760h
000A2A97 [00422F57] c3                                           retn
