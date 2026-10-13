; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00425C28; baseline game VA=0x000A56A0; size=24
; Relative branch annotations use the baseline game destination.
000A56A0 [00425C28] ff 34 24                                     push    dword ptr [esp]
000A56A3 [00425C2B] 50                                           push    eax
000A56A4 [00425C2C] 8b 8e 70 2a 00 00                            mov     ecx, [esi+2A70h]
000A56AA [00425C32] b8 c0 61 43 00                               mov     eax, 4361C0h
000A56AF [00425C37] ff d0                                        call    eax
000A56B1 [00425C39] 89 44 24 08                                  mov     [esp+8], eax
000A56B5 [00425C3D] 58                                           pop     eax
000A56B6 [00425C3E] c3                                           retn
000A56B7 [00425C3F] 90                                           nop
