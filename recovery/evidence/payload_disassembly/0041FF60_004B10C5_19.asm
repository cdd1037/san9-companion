; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0041FF60; baseline game VA=0x004B10C5; size=25
; Relative branch annotations use the baseline game destination.
004B10C5 [0041FF60] 83 e8 08                                     sub     eax, 8
004B10C8 [0041FF63] e8 63 fe fa ff                               call    near ptr 3CFDCBh ; game-relative-target=0x00460F30
004B10CD [0041FF68] 85 c0                                        test    eax, eax
004B10CF [0041FF6A] 74 25                                        jz      short near ptr unk_41FF91 ; game-relative-target=0x004B10F6
004B10D1 [0041FF6C] 8b f0                                        mov     esi, eax
004B10D3 [0041FF6E] e8 da de fb ff                               call    near ptr 3DDE4Dh ; game-relative-target=0x0046EFB2
004B10D8 [0041FF73] 85 c0                                        test    eax, eax
004B10DA [0041FF75] 74 1a                                        jz      short near ptr unk_41FF91 ; game-relative-target=0x004B10F6
004B10DC [0041FF77] eb 0a                                        jmp     short near ptr unk_41FF83 ; game-relative-target=0x004B10E8
