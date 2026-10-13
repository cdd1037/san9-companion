; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00422D64; baseline game VA=0x0045CCE5; size=11
; Relative branch annotations use the baseline game destination.
0045CCE5 [00422D64] 8b 84 24 c0 00 00 00                         mov     eax, [esp+0C0h]
0045CCEC [00422D6B] 8b 40 08                                     mov     eax, [eax+8]
0045CCEF [00422D6E] c3                                           retn
