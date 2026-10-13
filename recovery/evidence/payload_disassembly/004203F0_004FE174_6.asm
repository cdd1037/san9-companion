; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004203F0; baseline game VA=0x004FE174; size=6
; Relative branch annotations use the baseline game destination.
004FE174 [004203F0] e8 37 21 ba ff                               call    near ptr 0FFFC252Ch ; game-relative-target=0x000A02B0
004FE179 [004203F5] 41                                           inc     ecx
