; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004225D0; baseline game VA=0x000A1880; size=47
; Relative branch annotations use the baseline game destination.
000A1880 [004225D0] 50                                           push    eax
000A1881 [004225D1] 8d 4c 24 0c                                  lea     ecx, [esp+0Ch]
000A1885 [004225D5] b8 30 3f 0a 00                               mov     eax, 0A3F30h
000A188A [004225DA] ff d0                                        call    eax
000A188C [004225DC] 8d 4c 24 0c                                  lea     ecx, [esp+0Ch]
000A1890 [004225E0] b8 90 3f 0a 00                               mov     eax, 0A3F90h
000A1895 [004225E5] ff d0                                        call    eax
000A1897 [004225E7] 8b 44 24 0c                                  mov     eax, [esp+0Ch]
000A189B [004225EB] 6b c0 0a                                     imul    eax, 0Ah
000A189E [004225EE] 99                                           cdq
000A189F [004225EF] b9 0a 00 00 00                               mov     ecx, 0Ah
000A18A4 [004225F4] f7 f1                                        div     ecx
000A18A6 [004225F6] 89 44 24 0c                                  mov     [esp+0Ch], eax
000A18AA [004225FA] 58                                           pop     eax
000A18AB [004225FB] 83 f8 06                                     cmp     eax, 6
000A18AE [004225FE] c3                                           retn
