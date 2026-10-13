; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00425580; baseline game VA=0x004BB6EC; size=6
; Relative branch annotations use the baseline game destination.
004BB6EC [00425580] e8 bf a5 be ff                               call    near ptr 0FB44h ; game-relative-target=0x000A5CB0
004BB6F1 [00425585] 41                                           inc     ecx
