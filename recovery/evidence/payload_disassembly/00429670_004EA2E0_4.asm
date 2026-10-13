; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00429670; baseline game VA=0x004EA2E0; size=4
; Relative branch annotations use the baseline game destination.
004EA2E0 [00429670] A0    db 0xA0
004EA2E1 [00429671] 1c 47                                        sbb     al, 47h ; 'G'
004EA2E3 [00429673] 00    db 0x00
