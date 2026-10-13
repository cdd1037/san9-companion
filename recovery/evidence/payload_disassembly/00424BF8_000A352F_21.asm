; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00424BF8; baseline game VA=0x000A352F; size=33
; Relative branch annotations use the baseline game destination.
000A352F [00424BF8] 8a 50 04                                     mov     dl, [eax+4]
000A3532 [00424BFB] 8b 40 68                                     mov     eax, [eax+68h]
000A3535 [00424BFE] 80 fa 08                                     cmp     dl, 8
000A3538 [00424C01] 7c 05                                        jl      short near ptr unk_424C08 ; game-relative-target=0x000A353F
000A353A [00424C03] 80 fa 0b                                     cmp     dl, 0Bh
000A353D [00424C06] 7e 05                                        jle     short near ptr unk_424C0D ; game-relative-target=0x000A3544
000A353F [00424C08] 8b 4c 24 2c                                  mov     ecx, [esp+2Ch]
000A3543 [00424C0C] c3                                           retn
000A3544 [00424C0D] 50                                           push    eax
000A3545 [00424C0E] 8b ce                                        mov     ecx, esi
000A3547 [00424C10] b8 b0 2d 0a 00                               mov     eax, 0A2DB0h
000A354C [00424C15] ff d0                                        call    eax
000A354E [00424C17] eb ef                                        jmp     short near ptr unk_424C08 ; game-relative-target=0x000A353F
