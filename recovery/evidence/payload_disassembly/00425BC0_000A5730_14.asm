; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00425BC0; baseline game VA=0x000A5730; size=20
; Relative branch annotations use the baseline game destination.
000A5730 [00425BC0] 50                                           push    eax
000A5731 [00425BC1] 51                                           push    ecx
000A5732 [00425BC2] 52                                           push    edx
000A5733 [00425BC3] b8 c0 61 43 00                               mov     eax, 4361C0h
000A5738 [00425BC8] ff d0                                        call    eax
000A573A [00425BCA] 5a                                           pop     edx
000A573B [00425BCB] 59                                           pop     ecx
000A573C [00425BCC] 87 44 24 04                                  xchg    eax, [esp+4]
000A5740 [00425BD0] 87 04 24                                     xchg    eax, [esp]
000A5743 [00425BD3] c3                                           retn
