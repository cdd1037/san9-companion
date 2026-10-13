; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042578C; baseline game VA=0x004B2CCD; size=4
; Relative branch annotations use the baseline game destination.
004B2CCD [0042578C] d0 53 0a                                     rcl     byte ptr [ebx+0Ah], 1
004B2CD0 [0042578F] 00    db 0x00
