; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00429F10; baseline game VA=0x004EDFAB; size=5
; Relative branch annotations use the baseline game destination.
004EDFAB [00429F10] e8 d0 23 08 00                               call    near ptr 4AC2E5h ; game-relative-target=0x00570380
