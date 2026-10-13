; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004290A8; baseline game VA=0x000A7AE0; size=23
; Relative branch annotations use the baseline game destination.
000A7AE0 [004290A8] 8b 44 24 5c                                  mov     eax, [esp+5Ch]
000A7AE4 [004290AC] 3b 05 d2 f3 43 00                            cmp     eax, ds:43F3D2h
000A7AEA [004290B2] 7d 06                                        jge     short near ptr unk_4290BA ; game-relative-target=0x000A7AF2
000A7AEC [004290B4] 68 b0 f3 44 00                               push    44F3B0h
000A7AF1 [004290B9] c3                                           retn
000A7AF2 [004290BA] 33 c0                                        xor     eax, eax
000A7AF4 [004290BC] c2 08 00                                     retn    8
