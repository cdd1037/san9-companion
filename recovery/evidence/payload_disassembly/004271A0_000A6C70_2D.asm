; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004271A0; baseline game VA=0x000A6C70; size=45
; Relative branch annotations use the baseline game destination.
000A6C70 [004271A0] 50                                           push    eax
000A6C71 [004271A1] b8 a0 02 51 00                               mov     eax, 5102A0h
000A6C76 [004271A6] ff d0                                        call    eax
000A6C78 [004271A8] 50                                           push    eax
000A6C79 [004271A9] b8 d0 64 0a 00                               mov     eax, 0A64D0h
000A6C7E [004271AE] ff d0                                        call    eax
000A6C80 [004271B0] 85 c0                                        test    eax, eax
000A6C82 [004271B2] 74 15                                        jz      short near ptr unk_4271C9 ; game-relative-target=0x000A6C99
000A6C84 [004271B4] ff 76 38                                     push    dword ptr [esi+38h]
000A6C87 [004271B7] 8b c8                                        mov     ecx, eax
000A6C89 [004271B9] b8 b0 e1 45 00                               mov     eax, 45E1B0h
000A6C8E [004271BE] ff d0                                        call    eax
000A6C90 [004271C0] 85 c0                                        test    eax, eax
000A6C92 [004271C2] 75 05                                        jnz     short near ptr unk_4271C9 ; game-relative-target=0x000A6C99
000A6C94 [004271C4] 58                                           pop     eax
000A6C95 [004271C5] b0 0f                                        mov     al, 0Fh
000A6C97 [004271C7] eb 01                                        jmp     short near ptr unk_4271CA ; game-relative-target=0x000A6C9A
000A6C99 [004271C9] 58                                           pop     eax
000A6C9A [004271CA] c2 04 00                                     retn    4
