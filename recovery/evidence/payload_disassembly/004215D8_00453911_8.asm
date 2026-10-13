; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004215D8; baseline game VA=0x00453911; size=8
; Relative branch annotations use the baseline game destination.
00453911 [004215D8] c1 e0 03                                     shl     eax, 3
00453914 [004215DB] 89 44 24 40                                  mov     [esp+40h], eax
00453918 [004215DF] c3                                           retn
