; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004203A4; baseline game VA=0x000A02B0; size=73
; Relative branch annotations use the baseline game destination.
000A02B0 [004203A4] f6 05 c7 f4 43 00 01                         test    byte ptr ds:43F4C7h, 1
000A02B7 [004203AB] 74 38                                        jz      short near ptr unk_4203E5 ; game-relative-target=0x000A02F1
000A02B9 [004203AD] 81 3c 24 79 e1 4f 00                         cmp     dword ptr [esp], 4FE179h
000A02C0 [004203B4] 75 07                                        jnz     short near ptr unk_4203BD ; game-relative-target=0x000A02C9
000A02C2 [004203B6] c6 05 c7 f4 43 00 00                         mov     byte ptr ds:43F4C7h, 0
000A02C9 [004203BD] 33 c0                                        xor     eax, eax
000A02CB [004203BF] 51                                           push    ecx
000A02CC [004203C0] 8b 91 88 00 00 00                            mov     edx, [ecx+88h]
000A02D2 [004203C6] 85 d2                                        test    edx, edx
000A02D4 [004203C8] 74 13                                        jz      short near ptr unk_4203DD ; game-relative-target=0x000A02E9
000A02D6 [004203CA] 8b 4a 08                                     mov     ecx, [edx+8]
000A02D9 [004203CD] 8b 12                                        mov     edx, [edx]
000A02DB [004203CF] 81 b9 f8 00 00 00 d8 e6 4f 01                cmp     dword ptr [ecx+0F8h], 14FE6D8h
000A02E5 [004203D9] 75 eb                                        jnz     short near ptr unk_4203C6 ; game-relative-target=0x000A02D2
000A02E7 [004203DB] 8b c1                                        mov     eax, ecx
000A02E9 [004203DD] 59                                           pop     ecx
000A02EA [004203DE] 85 c0                                        test    eax, eax
000A02EC [004203E0] 74 03                                        jz      short near ptr unk_4203E5 ; game-relative-target=0x000A02F1
000A02EE [004203E2] c2 0c 00                                     retn    0Ch
000A02F1 [004203E5] 8b 11                                        mov     edx, [ecx]
000A02F3 [004203E7] ff a2 c4 00 00 00                            jmp     dword ptr [edx+0C4h]
