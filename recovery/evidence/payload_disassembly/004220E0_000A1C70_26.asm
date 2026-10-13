; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004220E0; baseline game VA=0x000A1C70; size=38
; Relative branch annotations use the baseline game destination.
000A1C70 [004220E0] 68 ff 7f 00 00                               push    7FFFh
000A1C75 [004220E5] 68 00 05 0a 00                               push    0A0500h
000A1C7A [004220EA] 8d 4b 44                                     lea     ecx, [ebx+44h]
000A1C7D [004220ED] b8 80 ef 46 00                               mov     eax, 46EF80h
000A1C82 [004220F2] ff d0                                        call    eax
000A1C84 [004220F4] b9 00 05 0a 00                               mov     ecx, 0A0500h
000A1C89 [004220F9] b8 e0 80 51 00                               mov     eax, 5180E0h
000A1C8E [004220FE] ff d0                                        call    eax
000A1C90 [00422100] b8 ff ff ff ff                               mov     eax, 0FFFFFFFFh
000A1C95 [00422105] c3                                           retn
