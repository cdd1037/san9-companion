; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00422C90; baseline game VA=0x000A2BA8; size=25
; Relative branch annotations use the baseline game destination.
000A2BA8 [00422C90] 56                                           push    esi
000A2BA9 [00422C91] 8b c8                                        mov     ecx, eax
000A2BAB [00422C93] b8 80 57 43 00                               mov     eax, 435780h
000A2BB0 [00422C98] ff d0                                        call    eax
000A2BB2 [00422C9A] 85 c0                                        test    eax, eax
000A2BB4 [00422C9C] 74 06                                        jz      short near ptr unk_422CA4 ; game-relative-target=0x000A2BBC
000A2BB6 [00422C9E] 68 40 5a 0a 00                               push    0A5A40h
000A2BBB [00422CA3] c3                                           retn
000A2BBC [00422CA4] 33 c0                                        xor     eax, eax
000A2BBE [00422CA6] c2 04 00                                     retn    4
