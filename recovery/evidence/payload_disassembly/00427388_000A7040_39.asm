; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00427388; baseline game VA=0x000A7040; size=57
; Relative branch annotations use the baseline game destination.
000A7040 [00427388] ff 15 dc f2 5f 00                            call    dword ptr ds:5FF2DCh
000A7046 [0042738E] 33 d2                                        xor     edx, edx
000A7048 [00427390] b9 20 03 00 00                               mov     ecx, 320h
000A704D [00427395] f7 f9                                        idiv    ecx
000A704F [00427397] 69 d2 04 01 00 00                            imul    edx, 104h
000A7055 [0042739D] 03 d7                                        add     edx, edi
000A7057 [0042739F] 83 7a 24 00                                  cmp     dword ptr [edx+24h], 0
000A705B [004273A3] 74 19                                        jz      short near ptr unk_4273BE ; game-relative-target=0x000A7076
000A705D [004273A5] 81 c2 04 01 00 00                            add     edx, 104h
000A7063 [004273AB] 81 fa 2c bf 4e 01                            cmp     edx, 14EBF2Ch
000A7069 [004273B1] 7e 02                                        jle     short near ptr unk_4273B5 ; game-relative-target=0x000A706D
000A706B [004273B3] 8b d7                                        mov     edx, edi
000A706D [004273B5] 46                                           inc     esi
000A706E [004273B6] 81 fe 20 03 00 00                            cmp     esi, 320h
000A7074 [004273BC] 7c e1                                        jl      short near ptr unk_42739F ; game-relative-target=0x000A7057
000A7076 [004273BE] 8b fa                                        mov     edi, edx
000A7078 [004273C0] c3                                           retn
