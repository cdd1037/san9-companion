; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042A578; baseline game VA=0x000A87C0; size=50
; Relative branch annotations use the baseline game destination.
000A87C0 [0042A578] 81 bc 24 8c 00 00 00 21 3a 51 00             cmp     dword ptr [esp+8Ch], 513A21h
000A87CB [0042A583] 74 12                                        jz      short near ptr unk_42A597 ; game-relative-target=0x000A87DF
000A87CD [0042A585] 0f b6 83 ea 87 0a 00                         movzx   eax, byte ptr [ebx+0A87EAh]
000A87D4 [0042A58C] 50                                           push    eax
000A87D5 [0042A58D] ff 15 5c f3 5f 00                            call    dword ptr ds:5FF35Ch
000A87DB [0042A593] 84 e4                                        test    ah, ah
000A87DD [0042A595] 78 06                                        js      short near ptr unk_42A59D ; game-relative-target=0x000A87E5
000A87DF [0042A597] 68 20 0d 5e 00                               push    5E0D20h
000A87E4 [0042A59C] c3                                           retn
000A87E5 [0042A59D] c6 04 24 d4                                  mov     byte ptr [esp], 0D4h
000A87E9 [0042A5A1] c3                                           retn
000A87EA [0042A5A2] 57                                           push    edi
000A87EB [0042A5A3] 44                                           inc     esp
000A87EC [0042A5A4] 53                                           push    ebx
000A87ED [0042A5A5] 41                                           inc     ecx
000A87EE [0042A5A6] 45                                           inc     ebp
000A87EF [0042A5A7] 58                                           pop     eax
000A87F0 [0042A5A8] 5a                                           pop     edx
000A87F1 [0042A5A9] 51                                           push    ecx
