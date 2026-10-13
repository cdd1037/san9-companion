; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00424810; baseline game VA=0x004ABCD1; size=5
; Relative branch annotations use the baseline game destination.
004ABCD1 [00424810] e8 3a 51 fc ff                               call    near ptr 3E994Fh ; game-relative-target=0x00470E10
