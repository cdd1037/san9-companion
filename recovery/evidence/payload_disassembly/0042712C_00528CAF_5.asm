; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042712C; baseline game VA=0x00528CAF; size=5
; Relative branch annotations use the baseline game destination.
00528CAF [0042712C] e8 ac e0 f0 ff                               call    near ptr 3351DDh ; game-relative-target=0x00436D60
