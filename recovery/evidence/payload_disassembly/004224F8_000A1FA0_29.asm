; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004224F8; baseline game VA=0x000A1FA0; size=41
; Relative branch annotations use the baseline game destination.
000A1FA0 [004224F8] 58                                           pop     eax
000A1FA1 [004224F9] ff 15 f0 f2 5f 00                            call    dword ptr ds:5FF2F0h
000A1FA7 [004224FF] 8b 4e 40                                     mov     ecx, [esi+40h]
000A1FAA [00422502] 8b 89 b8 00 00 00                            mov     ecx, [ecx+0B8h]
000A1FB0 [00422508] f7 41 34 01 00 00 00                         test    dword ptr [ecx+34h], 1
000A1FB7 [0042250F] 75 0a                                        jnz     short near ptr unk_42251B ; game-relative-target=0x000A1FC3
000A1FB9 [00422511] 85 c0                                        test    eax, eax
000A1FBB [00422513] 75 06                                        jnz     short near ptr unk_42251B ; game-relative-target=0x000A1FC3
000A1FBD [00422515] 33 d2                                        xor     edx, edx
000A1FBF [00422517] 89 54 24 1c                                  mov     [esp+1Ch], edx
000A1FC3 [0042251B] 68 ec 46 49 00                               push    4946ECh
000A1FC8 [00422520] c3                                           retn
