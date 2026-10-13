; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00425D18; baseline game VA=0x000A5570; size=70
; Relative branch annotations use the baseline game destination.
000A5570 [00425D18] eb 06                                        jmp     short near ptr unk_425D20 ; game-relative-target=0x000A5578
000A5572 [00425D1A] ff 25 f0 f2 5f 00                            jmp     dword ptr ds:5FF2F0h
000A5578 [00425D20] ff 74 24 30                                  push    dword ptr [esp+30h]
000A557C [00425D24] b8 a0 d2 44 00                               mov     eax, 44D2A0h
000A5581 [00425D29] ff d0                                        call    eax
000A5583 [00425D2B] 83 e8 23                                     sub     eax, 23h ; '#'
000A5586 [00425D2E] 85 c0                                        test    eax, eax
000A5588 [00425D30] 7d 02                                        jge     short near ptr unk_425D34 ; game-relative-target=0x000A558C
000A558A [00425D32] 33 c0                                        xor     eax, eax
000A558C [00425D34] 99                                           cdq
000A558D [00425D35] b9 0f 00 00 00                               mov     ecx, 0Fh
000A5592 [00425D3A] f7 f1                                        div     ecx
000A5594 [00425D3C] 83 e8 05                                     sub     eax, 5
000A5597 [00425D3F] f7 d8                                        neg     eax
000A5599 [00425D41] 85 c0                                        test    eax, eax
000A559B [00425D43] 7f 05                                        jg      short near ptr unk_425D4A ; game-relative-target=0x000A55A2
000A559D [00425D45] b8 01 00 00 00                               mov     eax, 1
000A55A2 [00425D4A] 50                                           push    eax
000A55A3 [00425D4B] 8b ce                                        mov     ecx, esi
000A55A5 [00425D4D] 8b 01                                        mov     eax, [ecx]
000A55A7 [00425D4F] ff 50 3c                                     call    dword ptr [eax+3Ch]
000A55AA [00425D52] 85 c0                                        test    eax, eax
000A55AC [00425D54] 58                                           pop     eax
000A55AD [00425D55] 75 01                                        jnz     short near ptr unk_425D58 ; game-relative-target=0x000A55B0
000A55AF [00425D57] 40                                           inc     eax
000A55B0 [00425D58] 89 44 24 04                                  mov     [esp+4], eax
000A55B4 [00425D5C] eb bc                                        jmp     short near ptr unk_425D1A ; game-relative-target=0x000A5572
