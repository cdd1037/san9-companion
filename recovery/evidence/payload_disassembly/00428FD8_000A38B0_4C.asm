; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00428FD8; baseline game VA=0x000A38B0; size=76
; Relative branch annotations use the baseline game destination.
000A38B0 [00428FD8] 53                                           push    ebx
000A38B1 [00428FD9] 8b d9                                        mov     ebx, ecx
000A38B3 [00428FDB] 83 fb 05                                     cmp     ebx, 5
000A38B6 [00428FDE] 7e 03                                        jle     short near ptr unk_428FE3 ; game-relative-target=0x000A38BB
000A38B8 [00428FE0] 6a 05                                        push    5
000A38BA [00428FE2] 5b                                           pop     ebx
000A38BB [00428FE3] 8b 4e 30                                     mov     ecx, [esi+30h]
000A38BE [00428FE6] 8b 91 f8 00 00 00                            mov     edx, [ecx+0F8h]
000A38C4 [00428FEC] 83 7a 54 06                                  cmp     dword ptr [edx+54h], 6
000A38C8 [00428FF0] 7d 05                                        jge     short near ptr unk_428FF7 ; game-relative-target=0x000A38CF
000A38CA [00428FF2] ff 71 68                                     push    dword ptr [ecx+68h]
000A38CD [00428FF5] eb 03                                        jmp     short near ptr unk_428FFA ; game-relative-target=0x000A38D2
000A38CF [00428FF7] ff 71 58                                     push    dword ptr [ecx+58h]
000A38D2 [00428FFA] b8 00 d3 41 00                               mov     eax, 41D300h
000A38D7 [00428FFF] ff d0                                        call    eax
000A38D9 [00429001] 5a                                           pop     edx
000A38DA [00429002] 83 c0 3c                                     add     eax, 3Ch ; '<'
000A38DD [00429005] 3d 96 00 00 00                               cmp     eax, 96h
000A38E2 [0042900A] 7e 05                                        jle     short near ptr unk_429011 ; game-relative-target=0x000A38E9
000A38E4 [0042900C] b8 96 00 00 00                               mov     eax, 96h
000A38E9 [00429011] f7 6c 9c 14                                  imul    dword ptr [esp+ebx*4+14h]
000A38ED [00429015] b9 64 00 00 00                               mov     ecx, 64h ; 'd'
000A38F2 [0042901A] f7 f9                                        idiv    ecx
000A38F4 [0042901C] 89 44 9c 14                                  mov     [esp+ebx*4+14h], eax
000A38F8 [00429020] 8b c3                                        mov     eax, ebx
000A38FA [00429022] 5b                                           pop     ebx
000A38FB [00429023] c3                                           retn
