; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00422760; baseline game VA=0x000A33C8; size=49
; Relative branch annotations use the baseline game destination.
000A33C8 [00422760] b8 00 3d 0a 00                               mov     eax, 0A3D00h
000A33CD [00422765] ff d0                                        call    eax
000A33CF [00422767] 3c 02                                        cmp     al, 2
000A33D1 [00422769] 7d 1e                                        jge     short near ptr unk_422789 ; game-relative-target=0x000A33F1
000A33D3 [0042276B] 8b cf                                        mov     ecx, edi
000A33D5 [0042276D] b8 d0 53 43 00                               mov     eax, 4353D0h
000A33DA [00422772] ff d0                                        call    eax
000A33DC [00422774] 3c 01                                        cmp     al, 1
000A33DE [00422776] 74 01                                        jz      short near ptr unk_422779 ; game-relative-target=0x000A33E1
000A33E0 [00422778] c3                                           retn
000A33E1 [00422779] 8b cd                                        mov     ecx, ebp
000A33E3 [0042277B] b8 f0 fb 43 00                               mov     eax, 43FBF0h
000A33E8 [00422780] ff d0                                        call    eax
000A33EA [00422782] 3b 44 24 20                                  cmp     eax, [esp+20h]
000A33EE [00422786] 74 01                                        jz      short near ptr unk_422789 ; game-relative-target=0x000A33F1
000A33F0 [00422788] c3                                           retn
000A33F1 [00422789] 68 8e 31 4a 00                               push    4A318Eh
000A33F6 [0042278E] c2 04 00                                     retn    4
