; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00422CAC; baseline game VA=0x004B5DC6; size=5
; Relative branch annotations use the baseline game destination.
004B5DC6 [00422CAC] e8 dd cd be ff                               call    near ptr 0FA8Eh ; game-relative-target=0x000A2BA8
