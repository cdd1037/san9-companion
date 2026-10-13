; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042A1DC; baseline game VA=0x000A8400; size=52
; Relative branch annotations use the baseline game destination.
000A8400 [0042A1DC] 56                                           push    esi
000A8401 [0042A1DD] 57                                           push    edi
000A8402 [0042A1DE] 8b fa                                        mov     edi, edx
000A8404 [0042A1E0] 52                                           push    edx
000A8405 [0042A1E1] 8b f1                                        mov     esi, ecx
000A8407 [0042A1E3] 8b 01                                        mov     eax, [ecx]
000A8409 [0042A1E5] ff 90 8c 00 00 00                            call    dword ptr [eax+8Ch]
000A840F [0042A1EB] 85 c0                                        test    eax, eax
000A8411 [0042A1ED] 74 1e                                        jz      short near ptr unk_42A20D ; game-relative-target=0x000A8431
000A8413 [0042A1EF] 57                                           push    edi
000A8414 [0042A1F0] 8b ce                                        mov     ecx, esi
000A8416 [0042A1F2] b8 30 72 5b 00                               mov     eax, 5B7230h
000A841B [0042A1F7] ff d0                                        call    eax
000A841D [0042A1F9] 8b 46 78                                     mov     eax, [esi+78h]
000A8420 [0042A1FC] 89 86 84 00 00 00                            mov     [esi+84h], eax
000A8426 [0042A202] 6a 01                                        push    1
000A8428 [0042A204] 8b ce                                        mov     ecx, esi
000A842A [0042A206] b8 00 7a 5b 00                               mov     eax, 5B7A00h
000A842F [0042A20B] ff d0                                        call    eax
000A8431 [0042A20D] 5f                                           pop     edi
000A8432 [0042A20E] 5e                                           pop     esi
000A8433 [0042A20F] c3                                           retn
