; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00424D64; baseline game VA=0x004BBF98; size=4
; Relative branch annotations use the baseline game destination.
004BBF98 [00424D64] 80    db 0x80
004BBF99 [00424D65] 4c                                           dec     esp
004BBF9A [00424D66] 0a 00                                        or      al, [eax]
