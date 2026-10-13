; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00427480; baseline game VA=0x000A6520; size=30
; Relative branch annotations use the baseline game destination.
000A6520 [00427480] 85 ff                                        test    edi, edi
000A6522 [00427482] 7e 03                                        jle     short near ptr unk_427487 ; game-relative-target=0x000A6527
000A6524 [00427484] 83 ef 05                                     sub     edi, 5
000A6527 [00427487] b9 25 00 00 00                               mov     ecx, 25h ; '%'
000A652C [0042748C] 99                                           cdq
000A652D [0042748D] f7 f1                                        div     ecx
000A652F [0042748F] 83 f8 32                                     cmp     eax, 32h ; '2'
000A6532 [00427492] 7e 02                                        jle     short near ptr unk_427496 ; game-relative-target=0x000A6536
000A6534 [00427494] b0 32                                        mov     al, 32h ; '2'
000A6536 [00427496] 68 18 31 50 00                               push    503118h
000A653B [0042749B] c2 04 00                                     retn    4
