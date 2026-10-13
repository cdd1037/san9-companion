; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00427940; baseline game VA=0x000A5C60; size=58
; Relative branch annotations use the baseline game destination.
000A5C60 [00427940] b0 19                                        mov     al, 19h
000A5C62 [00427942] 83 f9 04                                     cmp     ecx, 4
000A5C65 [00427945] 7d 2d                                        jge     short near ptr unk_427974 ; game-relative-target=0x000A5C94
000A5C67 [00427947] 8b 4c 24 20                                  mov     ecx, [esp+20h]
000A5C6B [0042794B] 85 c9                                        test    ecx, ecx
000A5C6D [0042794D] 74 0b                                        jz      short near ptr unk_42795A ; game-relative-target=0x000A5C7A
000A5C6F [0042794F] 8b 41 08                                     mov     eax, [ecx+8]
000A5C72 [00427952] 80 48 0c 80                                  or      byte ptr [eax+0Ch], 80h
000A5C76 [00427956] 8b 09                                        mov     ecx, [ecx]
000A5C78 [00427958] eb f1                                        jmp     short near ptr unk_42794B ; game-relative-target=0x000A5C6B
000A5C7A [0042795A] 8b 8c 24 80 00 00 00                         mov     ecx, [esp+80h]
000A5C81 [00427961] 85 c9                                        test    ecx, ecx
000A5C83 [00427963] 74 0b                                        jz      short near ptr unk_427970 ; game-relative-target=0x000A5C90
000A5C85 [00427965] 8b 41 08                                     mov     eax, [ecx+8]
000A5C88 [00427968] 80 48 0c 80                                  or      byte ptr [eax+0Ch], 80h
000A5C8C [0042796C] 8b 09                                        mov     ecx, [ecx]
000A5C8E [0042796E] eb f1                                        jmp     short near ptr unk_427961 ; game-relative-target=0x000A5C81
000A5C90 [00427970] b0 0a                                        mov     al, 0Ah
000A5C92 [00427972] 3c 60                                        cmp     al, 60h ; '`'
000A5C94 [00427974] a2 c7 59 0a 00                               mov     ds:0A59C7h, al
000A5C99 [00427979] c3                                           retn
