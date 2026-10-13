; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004292C4; baseline game VA=0x004E9207; size=5
; Relative branch annotations use the baseline game destination.
004E9207 [004292C4] 83 c3 08                                     add     ebx, 8
004E920A [004292C7] 85 ff                                        test    edi, edi
