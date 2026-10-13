; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042259C; baseline game VA=0x0043CF67; size=9
; Relative branch annotations use the baseline game destination.
0043CF67 [0042259C] 83 c6 06                                     add     esi, 6
0043CF6A [0042259F] b8 1f 85 eb 51                               mov     eax, 51EB851Fh
0043CF6F [004225A4] c3                                           retn
