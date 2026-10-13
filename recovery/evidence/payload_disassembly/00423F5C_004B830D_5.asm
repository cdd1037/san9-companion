; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00423F5C; baseline game VA=0x004B830D; size=5
; Relative branch annotations use the baseline game destination.
004B830D [00423F5C] e8 5e 6c fb ff                               call    near ptr 3DABBFh ; game-relative-target=0x0046EF70
