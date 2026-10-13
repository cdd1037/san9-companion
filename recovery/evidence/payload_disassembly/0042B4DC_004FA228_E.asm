; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042B4DC; baseline game VA=0x004FA228; size=14
; Relative branch annotations use the baseline game destination.
004FA228 [0042B4DC] b8 c0 f4 48 00                               mov     eax, 48F4C0h
004FA22D [0042B4E1] e8 ce f1 ba ff                               call    near ptr 0FFFDA6B4h ; game-relative-target=0x000A9400
004FA232 [0042B4E6] 8b 06                                        mov     eax, [esi]
004FA234 [0042B4E8] 8b ce                                        mov     ecx, esi
