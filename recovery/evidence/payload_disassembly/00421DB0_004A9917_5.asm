; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00421DB0; baseline game VA=0x004A9917; size=5
; Relative branch annotations use the baseline game destination.
004A9917 [00421DB0] e8 4a ef fb ff                               call    near ptr 3E0CFFh ; game-relative-target=0x00468866
