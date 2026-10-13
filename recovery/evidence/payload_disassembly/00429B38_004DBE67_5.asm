; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00429B38; baseline game VA=0x004DBE67; size=5
; Relative branch annotations use the baseline game destination.
004DBE67 [00429B38] e8 8c c2 bc ff                               call    near ptr 0FFFF5DC9h ; game-relative-target=0x000A80F8
