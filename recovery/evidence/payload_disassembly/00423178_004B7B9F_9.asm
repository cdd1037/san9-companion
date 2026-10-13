; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00423178; baseline game VA=0x004B7B9F; size=9
; Relative branch annotations use the baseline game destination.
004B7B9F [00423178] e8 7c 9c be ff                               call    near ptr 0CDF9h ; game-relative-target=0x000A1820
004B7BA4 [0042317D] 8b 74 24 58                                  mov     esi, [esp+58h]
