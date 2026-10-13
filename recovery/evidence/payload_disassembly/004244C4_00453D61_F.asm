; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004244C4; baseline game VA=0x00453D61; size=15
; Relative branch annotations use the baseline game destination.
00453D61 [004244C4] a1 f7 fa 43 00                               mov     eax, ds:43FAF7h
00453D66 [004244C9] 89 44 24 08                                  mov     [esp+8], eax
00453D6A [004244CD] 68 90 30 47 00                               push    473090h
00453D6F [004244D2] c3                                           retn
