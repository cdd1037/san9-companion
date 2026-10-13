; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00422090; baseline game VA=0x004B2E0D; size=5
; Relative branch annotations use the baseline game destination.
004B2E0D [00422090] e8 8e ee be ff                               call    near ptr 10F23h ; game-relative-target=0x000A1CA0
