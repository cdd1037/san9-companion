; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042342C; baseline game VA=0x000A3D90; size=62
; Relative branch annotations use the baseline game destination.
000A3D90 [0042342C] c6 05 c8 f4 43 00 01                         mov     byte ptr ds:43F4C8h, 1
000A3D97 [00423433] b8 d0 53 43 00                               mov     eax, 4353D0h
000A3D9C [00423438] ff d0                                        call    eax
000A3D9E [0042343A] 3c 00                                        cmp     al, 0
000A3DA0 [0042343C] 74 04                                        jz      short near ptr unk_423442 ; game-relative-target=0x000A3DA6
000A3DA2 [0042343E] 3c 02                                        cmp     al, 2
000A3DA4 [00423440] 75 03                                        jnz     short near ptr unk_423445 ; game-relative-target=0x000A3DA9
000A3DA6 [00423442] b0 01                                        mov     al, 1
000A3DA8 [00423444] c3                                           retn
000A3DA9 [00423445] 8b ce                                        mov     ecx, esi
000A3DAB [00423447] b8 00 3d 0a 00                               mov     eax, 0A3D00h
000A3DB0 [0042344C] ff d0                                        call    eax
000A3DB2 [0042344E] 3c 01                                        cmp     al, 1
000A3DB4 [00423450] eb 01                                        jmp     short near ptr unk_423453 ; game-relative-target=0x000A3DB7
000A3DB6 [00423452] c3                                           retn
000A3DB7 [00423453] 8b ce                                        mov     ecx, esi
000A3DB9 [00423455] 8b 01                                        mov     eax, [ecx]
000A3DBB [00423457] ff 50 0c                                     call    dword ptr [eax+0Ch]
000A3DBE [0042345A] 80 4c 85 44 80                               or      byte ptr [ebp+eax*4+44h], 80h
000A3DC3 [0042345F] c7 44 24 20 00 10 00 00                      mov     dword ptr [esp+20h], 1000h
000A3DCB [00423467] 33 c0                                        xor     eax, eax
000A3DCD [00423469] c3                                           retn
