; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004247E0; baseline game VA=0x004AAEC1; size=5
; Relative branch annotations use the baseline game destination.
004AAEC1 [004247E0] e8 1a be bf ff                               call    near ptr 205FFh ; game-relative-target=0x000A6CE0
