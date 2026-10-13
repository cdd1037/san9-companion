; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004271F8; baseline game VA=0x000A6CA0; size=26
; Relative branch annotations use the baseline game destination.
000A6CA0 [004271F8] 51                                           push    ecx
000A6CA1 [004271F9] 8b 4c 24 0c                                  mov     ecx, [esp+0Ch]
000A6CA5 [004271FD] b8 60 63 0a 00                               mov     eax, 0A6360h
000A6CAA [00427202] ff d0                                        call    eax
000A6CAC [00427204] 59                                           pop     ecx
000A6CAD [00427205] 85 c0                                        test    eax, eax
000A6CAF [00427207] 75 03                                        jnz     short near ptr unk_42720C ; game-relative-target=0x000A6CB4
000A6CB1 [00427209] c2 20 00                                     retn    20h ; ' '
000A6CB4 [0042720C] 68 80 d8 52 00                               push    52D880h
000A6CB9 [00427211] c3                                           retn
