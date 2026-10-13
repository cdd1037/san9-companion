; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00425790; baseline game VA=0x004B2CCD; size=4
; Relative branch annotations use the baseline game destination.
004B2CCD [00425790] d0 29                                        shr     byte ptr [ecx], 1
004B2CCF [00425792] 4b                                           dec     ebx
004B2CD0 [00425793] 00    db 0x00
