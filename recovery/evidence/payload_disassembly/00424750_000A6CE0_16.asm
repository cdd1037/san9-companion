; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00424750; baseline game VA=0x000A6CE0; size=22
; Relative branch annotations use the baseline game destination.
000A6CE0 [00424750] b8 10 0e 47 00                               mov     eax, 470E10h
000A6CE5 [00424755] ff d0                                        call    eax
000A6CE7 [00424757] 83 7e 50 00                                  cmp     dword ptr [esi+50h], 0
000A6CEB [0042475B] 75 01                                        jnz     short near ptr unk_42475E ; game-relative-target=0x000A6CEE
000A6CED [0042475D] c3                                           retn
000A6CEE [0042475E] 58                                           pop     eax
000A6CEF [0042475F] 05 91 ff ff ff                               add     eax, 0FFFFFF91h
000A6CF4 [00424764] 50                                           push    eax
000A6CF5 [00424765] c3                                           retn
