; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00424258; baseline game VA=0x000A35B0; size=20
; Relative branch annotations use the baseline game destination.
000A35B0 [00424258] b8 40 e3 5c 00                               mov     eax, 5CE340h
000A35B5 [0042425D] ff d0                                        call    eax
000A35B7 [0042425F] 6a 19                                        push    19h
000A35B9 [00424261] 8b cf                                        mov     ecx, edi
000A35BB [00424263] b8 d0 da 43 00                               mov     eax, 43DAD0h
000A35C0 [00424268] ff d0                                        call    eax
000A35C2 [0042426A] c3                                           retn
000A35C3 [0042426B] 90                                           nop
