; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00424D14; baseline game VA=0x004934E0; size=5
; Relative branch annotations use the baseline game destination.
004934E0 [00424D14] 5e                                           pop     esi
004934E1 [00424D15] 89 44 24 08                                  mov     [esp+8], eax
