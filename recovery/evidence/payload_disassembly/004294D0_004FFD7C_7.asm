; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004294D0; baseline game VA=0x004FFD7C; size=7
; Relative branch annotations use the baseline game destination.
004FFD7C [004294D0] 5f                                           pop     edi
004FFD7D [004294D1] 5e                                           pop     esi
004FFD7E [004294D2] 5d                                           pop     ebp
004FFD7F [004294D3] 5b                                           pop     ebx
004FFD80 [004294D4] c2 08 00                                     retn    8
