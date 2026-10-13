; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00427DC8; baseline game VA=0x000A3FE0; size=31
; Relative branch annotations use the baseline game destination.
000A3FE0 [00427DC8] 52                                           push    edx
000A3FE1 [00427DC9] b8 01 00 00 00                               mov     eax, 1
000A3FE6 [00427DCE] 8b c8                                        mov     ecx, eax
000A3FE8 [00427DD0] 33 d2                                        xor     edx, edx
000A3FEA [00427DD2] 3b c3                                        cmp     eax, ebx
000A3FEC [00427DD4] 7d 07                                        jge     short near ptr unk_427DDD ; game-relative-target=0x000A3FF5
000A3FEE [00427DD6] 03 d1                                        add     edx, ecx
000A3FF0 [00427DD8] 41                                           inc     ecx
000A3FF1 [00427DD9] 03 c1                                        add     eax, ecx
000A3FF3 [00427DDB] eb f5                                        jmp     short near ptr unk_427DD2 ; game-relative-target=0x000A3FEA
000A3FF5 [00427DDD] 58                                           pop     eax
000A3FF6 [00427DDE] 03 d3                                        add     edx, ebx
000A3FF8 [00427DE0] f7 ea                                        imul    edx
000A3FFA [00427DE2] f7 f1                                        div     ecx
000A3FFC [00427DE4] 8b f0                                        mov     esi, eax
000A3FFE [00427DE6] c3                                           retn
