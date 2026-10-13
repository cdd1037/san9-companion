; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00429480; baseline game VA=0x004FE0CD; size=7
; Relative branch annotations use the baseline game destination.
004FE0CD [00429480] 83 7c 24 18 0a                               cmp     dword ptr [esp+18h], 0Ah
004FE0D2 [00429485] 7c 3b                                        jl      short near ptr dword_4294C0+2 ; game-relative-target=0x004FE10F
