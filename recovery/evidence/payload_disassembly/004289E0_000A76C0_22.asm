; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004289E0; baseline game VA=0x000A76C0; size=34
; Relative branch annotations use the baseline game destination.
000A76C0 [004289E0] ba 54 4e 0a 00                               mov     edx, 0A4E54h
000A76C5 [004289E5] ff d2                                        call    edx
000A76C7 [004289E7] 57                                           push    edi
000A76C8 [004289E8] 8d be c0 01 00 00                            lea     edi, [esi+1C0h]
000A76CE [004289EE] 03 07                                        add     eax, [edi]
000A76D0 [004289F0] ba 20 a1 07 00                               mov     edx, 7A120h
000A76D5 [004289F5] 3b c2                                        cmp     eax, edx
000A76D7 [004289F7] 7e 02                                        jle     short near ptr unk_4289FB ; game-relative-target=0x000A76DB
000A76D9 [004289F9] 8b c2                                        mov     eax, edx
000A76DB [004289FB] 89 07                                        mov     [edi], eax
000A76DD [004289FD] 5f                                           pop     edi
000A76DE [004289FE] c2 04 00                                     retn    4
000A76E1 [00428A01] 90                                           nop
