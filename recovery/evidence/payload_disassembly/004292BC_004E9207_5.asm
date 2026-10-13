; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004292BC; baseline game VA=0x004E9207; size=5
; Relative branch annotations use the baseline game destination.
004E9207 [004292BC] e8 14 ea bb ff                               call    near ptr 0FFFE7CD5h ; game-relative-target=0x000A7C20
