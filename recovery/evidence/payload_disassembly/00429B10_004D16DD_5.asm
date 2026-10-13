; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00429B10; baseline game VA=0x004D16DD; size=5
; Relative branch annotations use the baseline game destination.
004D16DD [00429B10] e8 0e 6a bd ff                               call    near ptr 523h ; game-relative-target=0x000A80F0
