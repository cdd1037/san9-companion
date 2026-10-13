; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042000C; baseline game VA=0x0045D8E7; size=8
; Relative branch annotations use the baseline game destination.
0045D8E7 [0042000C] 07                                           pop     es
0045D8E8 [0042000D] 0c 0a                                        or      al, 0Ah
0045D8EA [0042000F] 0f 05                                        syscall
0045D8EC [00420011] 05    db 0x05
0045D8ED [00420012] 0c 0f                                        or      al, 0Fh
