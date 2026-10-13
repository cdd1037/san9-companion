; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00423F54; baseline game VA=0x004B830D; size=5
; Relative branch annotations use the baseline game destination.
004B830D [00423F54] e8 ba b4 be ff                               call    near ptr 0F413h ; game-relative-target=0x000A37CC
