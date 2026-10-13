; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004293D0; baseline game VA=0x000A7D58; size=19
; Relative branch annotations use the baseline game destination.
000A7D58 [004293D0] c6 44 24 08 01                               mov     byte ptr [esp+8], 1
000A7D5D [004293D5] 8b 54 24 44                                  mov     edx, [esp+44h]
000A7D61 [004293D9] 89 54 24 10                                  mov     [esp+10h], edx
000A7D65 [004293DD] 68 a0 ee 47 00                               push    47EEA0h
000A7D6A [004293E2] c3                                           retn
