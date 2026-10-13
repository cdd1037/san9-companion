; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00425C80; baseline game VA=0x000A56B8; size=18
; Relative branch annotations use the baseline game destination.
000A56B8 [00425C80] ff 34 24                                     push    dword ptr [esp]
000A56BB [00425C83] 51                                           push    ecx
000A56BC [00425C84] b8 d0 36 0a 00                               mov     eax, 0A36D0h
000A56C1 [00425C89] ff d0                                        call    eax
000A56C3 [00425C8B] 89 44 24 08                                  mov     [esp+8], eax
000A56C7 [00425C8F] 59                                           pop     ecx
000A56C8 [00425C90] c3                                           retn
000A56C9 [00425C91] 90                                           nop
