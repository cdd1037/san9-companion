; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004278F8; baseline game VA=0x000A5FE0; size=29
; Relative branch annotations use the baseline game destination.
000A5FE0 [004278F8] ff 76 34                                     push    dword ptr [esi+34h]
000A5FE3 [004278FB] b8 20 37 45 00                               mov     eax, 453720h
000A5FE8 [00427900] ff d0                                        call    eax
000A5FEA [00427902] f6 80 84 00 00 00 01                         test    byte ptr [eax+84h], 1
000A5FF1 [00427909] 58                                           pop     eax
000A5FF2 [0042790A] 75 03                                        jnz     short near ptr unk_42790F ; game-relative-target=0x000A5FF7
000A5FF4 [0042790C] 33 c0                                        xor     eax, eax
000A5FF6 [0042790E] c3                                           retn
000A5FF7 [0042790F] 68 40 58 40 00                               push    405840h
000A5FFC [00427914] c3                                           retn
