; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004215E0; baseline game VA=0x004A1BB9; size=6
; Relative branch annotations use the baseline game destination.
004A1BB9 [004215E0] e8 53 1d fb ff                               call    near ptr 3D3338h ; game-relative-target=0x00453911
004A1BBE [004215E5] 40                                           inc     eax
