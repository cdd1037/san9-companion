; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00423CDC; baseline game VA=0x004B89BC; size=5
; Relative branch annotations use the baseline game destination.
004B89BC [00423CDC] e8 3f a4 be ff                               call    near ptr 0E120h ; game-relative-target=0x000A2E00
