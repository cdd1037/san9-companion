; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00422898; baseline game VA=0x000A2480; size=38
; Relative branch annotations use the baseline game destination.
000A2480 [00422898] b8 15 00 00 00                               mov     eax, 15h
000A2485 [0042289D] 80 3c 24 8d                                  cmp     byte ptr [esp], 8Dh
000A2489 [004228A1] 74 01                                        jz      short near ptr unk_4228A4 ; game-relative-target=0x000A248C
000A248B [004228A3] 40                                           inc     eax
000A248C [004228A4] 51                                           push    ecx
000A248D [004228A5] 50                                           push    eax
000A248E [004228A6] 8b 4e 40                                     mov     ecx, [esi+40h]
000A2491 [004228A9] b8 90 2a 46 00                               mov     eax, 462A90h
000A2496 [004228AE] ff d0                                        call    eax
000A2498 [004228B0] 59                                           pop     ecx
000A2499 [004228B1] 85 c0                                        test    eax, eax
000A249B [004228B3] 74 03                                        jz      short near ptr unk_4228B8 ; game-relative-target=0x000A24A0
000A249D [004228B5] 83 e9 56                                     sub     ecx, 56h ; 'V'
000A24A0 [004228B8] b8 78 77 77 77                               mov     eax, 77777778h
000A24A5 [004228BD] c3                                           retn
