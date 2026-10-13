; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0041FD60; baseline game VA=0x00508C80; size=47
; Relative branch annotations use the baseline game destination.
00508C80 [0041FD60] 8b 54 24 04                                  mov     edx, [esp+4]
00508C84 [0041FD64] 8b 8a f4 00 00 00                            mov     ecx, [edx+0F4h]
00508C8A [0041FD6A] 8b 41 74                                     mov     eax, [ecx+74h]
00508C8D [0041FD6D] 8b 88 b8 00 00 00                            mov     ecx, [eax+0B8h]
00508C93 [0041FD73] f6 41 34 01                                  test    byte ptr [ecx+'4'], 1
00508C97 [0041FD77] 8b 42 58                                     mov     eax, [edx+58h]
00508C9A [0041FD7A] 75 02                                        jnz     short near ptr byte_41FD60+1Eh ; game-relative-target=0x00508C9E
00508C9C [0041FD7C] 04 08                                        add     al, 8
00508C9E [0041FD7E] 3c 5a                                        cmp     al, 5Ah ; 'Z'
00508CA0 [0041FD80] 0f 8e 7e f3 ff ff                            jle     near ptr off_41F104 ; game-relative-target=0x00508024
00508CA6 [0041FD86] 3c 5f                                        cmp     al, 5Fh ; '_'
00508CA8 [0041FD88] 0f 8f e4 f4 ff ff                            jg      near ptr off_41F270+2 ; game-relative-target=0x00508192
00508CAE [0041FD8E] c3                                           retn
