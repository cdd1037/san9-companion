; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00429A94; baseline game VA=0x004EC3D8; size=5
; Relative branch annotations use the baseline game destination.
004EC3D8 [00429A94] e8 ab bc bb ff                               call    near ptr 0FFFE5744h ; game-relative-target=0x000A8088
