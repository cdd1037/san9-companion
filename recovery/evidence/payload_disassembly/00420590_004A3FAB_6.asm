; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00420590; baseline game VA=0x004A3FAB; size=6
; Relative branch annotations use the baseline game destination.
004A3FAB [00420590] e8 13 63 0d 00                               call    near ptr 4F68A8h ; game-relative-target=0x0057A2C3
004A3FB0 [00420595] 42                                           inc     edx
