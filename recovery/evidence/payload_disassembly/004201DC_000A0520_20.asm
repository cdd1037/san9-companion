; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004201DC; baseline game VA=0x000A0520; size=32
; Relative branch annotations use the baseline game destination.
000A0520 [004201DC] 70 6d                                        jo      short near ptr unk_42024B ; game-relative-target=0x000A058F
000A0522 [004201DE] 60                                           pusha
000A0523 [004201DF] 00    db 0x00
000A0524 [004201E0] 00    db 0x00
000A0525 [004201E1] 00    db 0x00
000A0526 [004201E2] 00    db 0x00
000A0527 [004201E3] 00    db 0x00
000A0528 [004201E4] 00    db 0x00
000A0529 [004201E5] 00    db 0x00
000A052A [004201E6] 00    db 0x00
000A052B [004201E7] 00    db 0x00
000A052C [004201E8] 00    db 0x00
000A052D [004201E9] 00    db 0x00
000A052E [004201EA] 00    db 0x00
000A052F [004201EB] 00    db 0x00
000A0530 [004201EC] 00    db 0x00
000A0531 [004201ED] 00    db 0x00
000A0532 [004201EE] 00    db 0x00
000A0533 [004201EF] 00    db 0x00
000A0534 [004201F0] 00    db 0x00
000A0535 [004201F1] 00    db 0x00
000A0536 [004201F2] 00    db 0x00
000A0537 [004201F3] 00 0a                                        add     [edx], cl
000A0539 [004201F5] 00    db 0x00
000A053A [004201F6] 00    db 0x00
000A053B [004201F7] 00 6c 64 60                                  add     [esp+60h], ch
000A053F [004201FB] 00    db 0x00
