; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00424230; baseline game VA=0x004FEB44; size=6
; Relative branch annotations use the baseline game destination.
004FEB44 [00424230] 2c 04                                        sub     al, 4
004FEB46 [00424232] 2b c7                                        sub     eax, edi
004FEB48 [00424234] 42                                           inc     edx
004FEB49 [00424235] 5f                                           pop     edi
