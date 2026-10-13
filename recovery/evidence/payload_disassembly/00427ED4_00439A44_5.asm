; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00427ED4; baseline game VA=0x00439A44; size=5
; Relative branch annotations use the baseline game destination.
00439A44 [00427ED4] e8 f7 bd fc ff                               call    near ptr 3F3CD0h ; game-relative-target=0x00405840
