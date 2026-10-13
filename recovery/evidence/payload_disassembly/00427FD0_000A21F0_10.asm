; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00427FD0; baseline game VA=0x000A21F0; size=16
; Relative branch annotations use the baseline game destination.
000A21F0 [00427FD0] 8b 44 24 04                                  mov     eax, [esp+4]
000A21F4 [00427FD4] 8b 08                                        mov     ecx, [eax]
000A21F6 [00427FD6] 51                                           push    ecx
000A21F7 [00427FD7] b8 10 f2 4a 00                               mov     eax, 4AF210h
000A21FC [00427FDC] ff d0                                        call    eax
000A21FE [00427FDE] 59                                           pop     ecx
000A21FF [00427FDF] c3                                           retn
