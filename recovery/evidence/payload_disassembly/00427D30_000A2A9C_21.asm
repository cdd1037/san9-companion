; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00427D30; baseline game VA=0x000A2A9C; size=33
; Relative branch annotations use the baseline game destination.
000A2A9C [00427D30] f6 41 4e 01                                  test    byte ptr [ecx+4Eh], 1
000A2AA0 [00427D34] 75 18                                        jnz     short near ptr unk_427D4E ; game-relative-target=0x000A2ABA
000A2AA2 [00427D36] 85 db                                        test    ebx, ebx
000A2AA4 [00427D38] 74 12                                        jz      short near ptr unk_427D4C ; game-relative-target=0x000A2AB8
000A2AA6 [00427D3A] ff 76 34                                     push    dword ptr [esi+34h]
000A2AA9 [00427D3D] ff 76 40                                     push    dword ptr [esi+40h]
000A2AAC [00427D40] ff 76 3c                                     push    dword ptr [esi+3Ch]
000A2AAF [00427D43] 8b ce                                        mov     ecx, esi
000A2AB1 [00427D45] b8 60 88 50 00                               mov     eax, 508860h
000A2AB6 [00427D4A] ff d0                                        call    eax
000A2AB8 [00427D4C] 33 c0                                        xor     eax, eax
000A2ABA [00427D4E] c2 04 00                                     retn    4
