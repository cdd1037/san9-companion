; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042A1B8; baseline game VA=0x000A8650; size=36
; Relative branch annotations use the baseline game destination.
000A8650 [0042A1B8] 56                                           push    esi
000A8651 [0042A1B9] 8b f1                                        mov     esi, ecx
000A8653 [0042A1BB] 57                                           push    edi
000A8654 [0042A1BC] 8b 3d 60 f4 5f 00                            mov     edi, ds:5FF460h
000A865A [0042A1C2] 52                                           push    edx
000A865B [0042A1C3] 52                                           push    edx
000A865C [0042A1C4] 6a 01                                        push    1
000A865E [0042A1C6] 68 01 02 00 00                               push    201h
000A8663 [0042A1CB] 56                                           push    esi
000A8664 [0042A1CC] ff d7                                        call    edi
000A8666 [0042A1CE] 6a 01                                        push    1
000A8668 [0042A1D0] 68 02 02 00 00                               push    202h
000A866D [0042A1D5] 56                                           push    esi
000A866E [0042A1D6] ff d7                                        call    edi
000A8670 [0042A1D8] 5f                                           pop     edi
000A8671 [0042A1D9] 5e                                           pop     esi
000A8672 [0042A1DA] c3                                           retn
000A8673 [0042A1DB] cc                                           int     3
