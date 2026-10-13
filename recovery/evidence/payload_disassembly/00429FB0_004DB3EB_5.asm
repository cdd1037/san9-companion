; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00429FB0; baseline game VA=0x004DB3EB; size=5
; Relative branch annotations use the baseline game destination.
004DB3EB [00429FB0] e8 90 4f 09 00                               call    near ptr 4BEF45h ; game-relative-target=0x00570380
