; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00426078; baseline game VA=0x004B5AF4; size=5
; Relative branch annotations use the baseline game destination.
004B5AF4 [00426078] e9 c7 fe be ff                               jmp     near ptr 15F44h ; game-relative-target=0x000A59C0
