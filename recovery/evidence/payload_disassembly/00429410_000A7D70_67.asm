; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00429410; baseline game VA=0x000A7D70; size=103
; Relative branch annotations use the baseline game destination.
000A7D70 [00429410] 8b 44 24 1c                                  mov     eax, [esp+1Ch]
000A7D74 [00429414] 85 c0                                        test    eax, eax
000A7D76 [00429416] 75 08                                        jnz     short near ptr unk_429420 ; game-relative-target=0x000A7D80
000A7D78 [00429418] 68 0f e1 4f 00                               push    4FE10Fh
000A7D7D [0042941D] c2 04 00                                     retn    4
000A7D80 [00429420] 8b cb                                        mov     ecx, ebx
000A7D82 [00429422] 8b 01                                        mov     eax, [ecx]
000A7D84 [00429424] ff 50 3c                                     call    dword ptr [eax+3Ch]
000A7D87 [00429427] 85 c0                                        test    eax, eax
000A7D89 [00429429] 74 2f                                        jz      short near ptr unk_42945A ; game-relative-target=0x000A7DBA
000A7D8B [0042942B] 8b cf                                        mov     ecx, edi
000A7D8D [0042942D] 8b 01                                        mov     eax, [ecx]
000A7D8F [0042942F] ff 50 3c                                     call    dword ptr [eax+3Ch]
000A7D92 [00429432] 85 c0                                        test    eax, eax
000A7D94 [00429434] 75 24                                        jnz     short near ptr unk_42945A ; game-relative-target=0x000A7DBA
000A7D96 [00429436] 0f b7 0d fe 26 23 01                         movzx   ecx, word ptr ds:12326FEh
000A7D9D [0042943D] 83 c1 64                                     add     ecx, 64h ; 'd'
000A7DA0 [00429440] 0f af 4c 24 20                               imul    ecx, [esp+20h]
000A7DA5 [00429445] b8 1f 85 eb 51                               mov     eax, 51EB851Fh
000A7DAA [0042944A] f7 e9                                        imul    ecx
000A7DAC [0042944C] c1 fa 05                                     sar     edx, 5
000A7DAF [0042944F] 8b c2                                        mov     eax, edx
000A7DB1 [00429451] c1 e8 1f                                     shr     eax, 1Fh
000A7DB4 [00429454] 03 d0                                        add     edx, eax
000A7DB6 [00429456] 89 54 24 20                                  mov     [esp+20h], edx
000A7DBA [0042945A] 80 3c 24 d4                                  cmp     byte ptr [esp], 0D4h
000A7DBE [0042945E] 75 01                                        jnz     short near ptr unk_429461 ; game-relative-target=0x000A7DC1
000A7DC0 [00429460] c3                                           retn
000A7DC1 [00429461] 8b 4e 40                                     mov     ecx, [esi+40h]
000A7DC4 [00429464] 8b 11                                        mov     edx, [ecx]
000A7DC6 [00429466] ff 92 80 00 00 00                            call    dword ptr [edx+80h]
000A7DCC [0042946C] 3b 44 24 20                                  cmp     eax, [esp+20h]
000A7DD0 [00429470] 7d 04                                        jge     short near ptr unk_429476 ; game-relative-target=0x000A7DD6
000A7DD2 [00429472] 89 44 24 20                                  mov     [esp+20h], eax
000A7DD6 [00429476] c3                                           retn
