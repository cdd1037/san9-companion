; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00429378; baseline game VA=0x000A7D30; size=40
; Relative branch annotations use the baseline game destination.
000A7D30 [00429378] b8 10 0e 47 00                               mov     eax, 470E10h
000A7D35 [0042937D] ff d0                                        call    eax
000A7D37 [0042937F] 8b 44 24 28                                  mov     eax, [esp+28h]
000A7D3B [00429383] 85 c0                                        test    eax, eax
000A7D3D [00429385] 74 18                                        jz      short near ptr unk_42939F ; game-relative-target=0x000A7D57
000A7D3F [00429387] 83 f8 0a                                     cmp     eax, 0Ah
000A7D42 [0042938A] 74 0f                                        jz      short near ptr unk_42939B ; game-relative-target=0x000A7D53
000A7D44 [0042938C] 8b 4e 3c                                     mov     ecx, [esi+3Ch]
000A7D47 [0042938F] 8b 11                                        mov     edx, [ecx]
000A7D49 [00429391] ff 92 bc 00 00 00                            call    dword ptr [edx+0BCh]
000A7D4F [00429397] 89 44 24 14                                  mov     [esp+14h], eax
000A7D53 [0042939B] 83 04 24 07                                  add     dword ptr [esp], 7
000A7D57 [0042939F] c3                                           retn
