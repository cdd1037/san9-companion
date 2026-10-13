; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00421B88; baseline game VA=0x000A2520; size=46
; Relative branch annotations use the baseline game destination.
000A2520 [00421B88] 8b cf                                        mov     ecx, edi
000A2522 [00421B8A] b8 c0 61 43 00                               mov     eax, 4361C0h
000A2527 [00421B8F] ff d0                                        call    eax
000A2529 [00421B91] bd 10 27 00 00                               mov     ebp, 2710h
000A252E [00421B96] 2b c5                                        sub     eax, ebp
000A2530 [00421B98] 3b c6                                        cmp     eax, esi
000A2532 [00421B9A] 7d 02                                        jge     short near ptr unk_421B9E ; game-relative-target=0x000A2536
000A2534 [00421B9C] 8b f0                                        mov     esi, eax
000A2536 [00421B9E] 57                                           push    edi
000A2537 [00421B9F] b8 50 25 0a 00                               mov     eax, 0A2550h
000A253C [00421BA4] ff d0                                        call    eax
000A253E [00421BA6] 3d 40 1f 00 00                               cmp     eax, 1F40h
000A2543 [00421BAB] 7d 06                                        jge     short near ptr unk_421BB3 ; game-relative-target=0x000A254B
000A2545 [00421BAD] 3b f5                                        cmp     esi, ebp
000A2547 [00421BAF] 7d 02                                        jge     short near ptr unk_421BB3 ; game-relative-target=0x000A254B
000A2549 [00421BB1] 8b f5                                        mov     esi, ebp
000A254B [00421BB3] c2 04 00                                     retn    4
