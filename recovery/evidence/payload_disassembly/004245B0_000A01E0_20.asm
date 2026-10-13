; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004245B0; baseline game VA=0x000A01E0; size=32
; Relative branch annotations use the baseline game destination.
000A01E0 [004245B0] 81 c1 00 00 00 00                            add     ecx, 0
000A01E6 [004245B6] 85 c9                                        test    ecx, ecx
000A01E8 [004245B8] 7d 0c                                        jge     short near ptr unk_4245C6 ; game-relative-target=0x000A01F6
000A01EA [004245BA] 66 c7 02 ab 65                               mov     word ptr [edx], 65ABh
000A01EF [004245BF] 83 44 24 04 02                               add     dword ptr [esp+4], 2
000A01F4 [004245C4] f7 d9                                        neg     ecx
000A01F6 [004245C6] 89 4c 24 0c                                  mov     [esp+0Ch], ecx
000A01FA [004245CA] 68 c7 3a 5d 00                               push    5D3AC7h
000A01FF [004245CF] c3                                           retn
