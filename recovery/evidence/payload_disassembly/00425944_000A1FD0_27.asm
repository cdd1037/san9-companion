; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00425944; baseline game VA=0x000A1FD0; size=39
; Relative branch annotations use the baseline game destination.
000A1FD0 [00425944] 5a                                           pop     edx
000A1FD1 [00425945] 80 fa 28                                     cmp     dl, 28h ; '('
000A1FD4 [00425948] 75 06                                        jnz     short near ptr unk_425950 ; game-relative-target=0x000A1FDC
000A1FD6 [0042594A] 53                                           push    ebx
000A1FD7 [0042594B] 51                                           push    ecx
000A1FD8 [0042594C] 8b ce                                        mov     ecx, esi
000A1FDA [0042594E] eb 01                                        jmp     short near ptr unk_425951 ; game-relative-target=0x000A1FDD
000A1FDC [00425950] 50                                           push    eax
000A1FDD [00425951] 52                                           push    edx
000A1FDE [00425952] b8 b1 dd 45 00                               mov     eax, 45DDB1h
000A1FE3 [00425957] ff d0                                        call    eax
000A1FE5 [00425959] 5a                                           pop     edx
000A1FE6 [0042595A] 80 fa 28                                     cmp     dl, 28h ; '('
000A1FE9 [0042595D] 75 01                                        jnz     short near ptr unk_425960 ; game-relative-target=0x000A1FEC
000A1FEB [0042595F] 59                                           pop     ecx
000A1FEC [00425960] 87 14 24                                     xchg    edx, [esp]
000A1FEF [00425963] 3b d0                                        cmp     edx, eax
000A1FF1 [00425965] b8 00 00 00 00                               mov     eax, 0
000A1FF6 [0042596A] c3                                           retn
