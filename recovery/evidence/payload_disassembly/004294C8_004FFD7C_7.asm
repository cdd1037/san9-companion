; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004294C8; baseline game VA=0x004FFD7C; size=7
; Relative branch annotations use the baseline game destination.
004FFD7C [004294C8] 83 7c 24 14 0a                               cmp     dword ptr [esp+14h], 0Ah
004FFD81 [004294CD] 7d 5e                                        jge     short near ptr unk_42952D ; game-relative-target=0x004FFDE1
