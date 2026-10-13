; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00421BB8; baseline game VA=0x004A3206; size=5
; Relative branch annotations use the baseline game destination.
004A3206 [00421BB8] e8 15 f3 bf ff                               call    near ptr 20ED2h ; game-relative-target=0x000A2520
