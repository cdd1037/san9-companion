; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004279A8; baseline game VA=0x000A1B00; size=36
; Relative branch annotations use the baseline game destination.
000A1B00 [004279A8] 56                                           push    esi
000A1B01 [004279A9] 8b f1                                        mov     esi, ecx
000A1B03 [004279AB] b8 90 e3 45 00                               mov     eax, 45E390h
000A1B08 [004279B0] ff d0                                        call    eax
000A1B0A [004279B2] 85 c0                                        test    eax, eax
000A1B0C [004279B4] 75 0c                                        jnz     short near ptr unk_4279C2 ; game-relative-target=0x000A1B1A
000A1B0E [004279B6] 8b 4e 6c                                     mov     ecx, [esi+6Ch]
000A1B11 [004279B9] 8a 41 04                                     mov     al, [ecx+4]
000A1B14 [004279BC] 3c 0a                                        cmp     al, 0Ah
000A1B16 [004279BE] 74 0a                                        jz      short near ptr unk_4279CA ; game-relative-target=0x000A1B22
000A1B18 [004279C0] eb 06                                        jmp     short near ptr unk_4279C8 ; game-relative-target=0x000A1B20
000A1B1A [004279C2] 8b 4e 70                                     mov     ecx, [esi+70h]
000A1B1D [004279C5] 8a 41 04                                     mov     al, [ecx+4]
000A1B20 [004279C8] 33 c0                                        xor     eax, eax
000A1B22 [004279CA] 5e                                           pop     esi
000A1B23 [004279CB] c3                                           retn
