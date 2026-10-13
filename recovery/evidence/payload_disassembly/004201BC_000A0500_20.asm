; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004201BC; baseline game VA=0x000A0500; size=32
; Relative branch annotations use the baseline game destination.
000A0500 [004201BC] 8c 6c 60 00                                  mov     word ptr [eax+0], gs
000A0504 [004201C0] 00    db 0x00
000A0505 [004201C1] 00    db 0x00
000A0506 [004201C2] 00    db 0x00
000A0507 [004201C3] 00    db 0x00
000A0508 [004201C4] 00    db 0x00
000A0509 [004201C5] 00    db 0x00
000A050A [004201C6] 00    db 0x00
000A050B [004201C7] 00    db 0x00
000A050C [004201C8] 00    db 0x00
000A050D [004201C9] 00    db 0x00
000A050E [004201CA] 00    db 0x00
000A050F [004201CB] 00    db 0x00
000A0510 [004201CC] 00    db 0x00
000A0511 [004201CD] 00    db 0x00
000A0512 [004201CE] 00    db 0x00
000A0513 [004201CF] 00    db 0x00
000A0514 [004201D0] 00    db 0x00
000A0515 [004201D1] 00    db 0x00
000A0516 [004201D2] 00    db 0x00
000A0517 [004201D3] 00 0a                                        add     [edx], cl
000A0519 [004201D5] 00    db 0x00
000A051A [004201D6] 00    db 0x00
000A051B [004201D7] 00 e8                                        add     al, ch
000A051D [004201D9] 60                                           pusha
000A051E [004201DA] 60                                           pusha
000A051F [004201DB] 00    db 0x00
