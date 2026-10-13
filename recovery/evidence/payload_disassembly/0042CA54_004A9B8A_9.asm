; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042CA54; baseline game VA=0x004A9B8A; size=9
; Relative branch annotations use the baseline game destination.
004A9B8A [0042CA54] 85 c0                                        test    eax, eax
004A9B8C [0042CA56] 74 34                                        jz      short near ptr unk_42CA8C ; game-relative-target=0x004A9BC2
004A9B8E [0042CA58] bf 02 00 00 00                               mov     edi, 2
