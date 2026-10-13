; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00427320; baseline game VA=0x000A7020; size=23
; Relative branch annotations use the baseline game destination.
000A7020 [00427320] 8b cf                                        mov     ecx, edi
000A7022 [00427322] b8 e0 4e 0a 00                               mov     eax, 0A4EE0h
000A7027 [00427327] ff d0                                        call    eax
000A7029 [00427329] 85 c0                                        test    eax, eax
000A702B [0042732B] 75 03                                        jnz     short near ptr unk_427330 ; game-relative-target=0x000A7030
000A702D [0042732D] c2 04 00                                     retn    4
000A7030 [00427330] 8b cf                                        mov     ecx, edi
000A7032 [00427332] 8b 01                                        mov     eax, [ecx]
000A7034 [00427334] ff 60 18                                     jmp     dword ptr [eax+18h]
