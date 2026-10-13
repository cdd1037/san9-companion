; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00429110; baseline game VA=0x004F9DDF; size=5
; Relative branch annotations use the baseline game destination.
004F9DDF [00429110] e8 bc dd ba ff                               call    near ptr 0FFFD6ED1h ; game-relative-target=0x000A7BA0
