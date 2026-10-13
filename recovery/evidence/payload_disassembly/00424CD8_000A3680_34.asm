; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00424CD8; baseline game VA=0x000A3680; size=52
; Relative branch annotations use the baseline game destination.
000A3680 [00424CD8] 8b f0                                        mov     esi, eax
000A3682 [00424CDA] 85 c0                                        test    eax, eax
000A3684 [00424CDC] 7e 26                                        jle     short near ptr unk_424D04 ; game-relative-target=0x000A36AC
000A3686 [00424CDE] 8b 4c 24 10                                  mov     ecx, [esp+10h]
000A368A [00424CE2] 51                                           push    ecx
000A368B [00424CE3] 8b 01                                        mov     eax, [ecx]
000A368D [00424CE5] ff 50 30                                     call    dword ptr [eax+30h]
000A3690 [00424CE8] 59                                           pop     ecx
000A3691 [00424CE9] ff b0 bc 00 00 00                            push    dword ptr [eax+0BCh]
000A3697 [00424CEF] b8 c0 ce 44 00                               mov     eax, 44CEC0h
000A369C [00424CF4] ff d0                                        call    eax
000A369E [00424CF6] 3c 0a                                        cmp     al, 0Ah
000A36A0 [00424CF8] 7d 0a                                        jge     short near ptr unk_424D04 ; game-relative-target=0x000A36AC
000A36A2 [00424CFA] 83 e8 0a                                     sub     eax, 0Ah
000A36A5 [00424CFD] f7 d8                                        neg     eax
000A36A7 [00424CFF] 6b c0 04                                     imul    eax, 4
000A36AA [00424D02] 2b f0                                        sub     esi, eax
000A36AC [00424D04] 89 74 24 10                                  mov     [esp+10h], esi
000A36B0 [00424D08] 58                                           pop     eax
000A36B1 [00424D09] 5e                                           pop     esi
000A36B2 [00424D0A] 50                                           push    eax
000A36B3 [00424D0B] c3                                           retn
