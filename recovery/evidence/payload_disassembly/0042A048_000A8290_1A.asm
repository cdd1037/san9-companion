; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042A048; baseline game VA=0x000A8290; size=26
; Relative branch annotations use the baseline game destination.
000A8290 [0042A048] 51                                           push    ecx
000A8291 [0042A049] b9 00 05 0a 00                               mov     ecx, 0A0500h
000A8296 [0042A04E] b8 e0 80 51 00                               mov     eax, 5180E0h
000A829B [0042A053] ff d0                                        call    eax
000A829D [0042A055] 33 c0                                        xor     eax, eax
000A829F [0042A057] a3 a6 82 0a 00                               mov     ds:0A82A6h, eax
000A82A4 [0042A05C] 59                                           pop     ecx
000A82A5 [0042A05D] c3                                           retn
000A82A6 [0042A05E] 00    db 0x00
000A82A7 [0042A05F] 00    db 0x00
000A82A8 [0042A060] 00    db 0x00
000A82A9 [0042A061] 00    db 0x00
