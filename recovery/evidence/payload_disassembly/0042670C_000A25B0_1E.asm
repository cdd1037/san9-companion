; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042670C; baseline game VA=0x000A25B0; size=30
; Relative branch annotations use the baseline game destination.
000A25B0 [0042670C] 3b b3 b8 00 00 00                            cmp     esi, [ebx+0B8h]
000A25B6 [00426712] 74 02                                        jz      short near ptr dword_426714+2 ; game-relative-target=0x000A25BA
000A25B8 [00426714] 40                                           inc     eax
000A25B9 [00426715] c3                                           retn
000A25BA [00426716] 8b cf                                        mov     ecx, edi
000A25BC [00426718] b8 e0 01 44 00                               mov     eax, 4401E0h
000A25C1 [0042671D] ff d0                                        call    eax
000A25C3 [0042671F] 50                                           push    eax
000A25C4 [00426720] b8 e0 32 45 00                               mov     eax, 4532E0h
000A25C9 [00426725] ff d0                                        call    eax
000A25CB [00426727] 59                                           pop     ecx
000A25CC [00426728] c3                                           retn
000A25CD [00426729] 90                                           nop
