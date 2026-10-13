; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00420658; baseline game VA=0x000A0000; size=35
; Relative branch annotations use the baseline game destination.
000A0000 [00420658] 8b 8c 24 9c 00 00 00                         mov     ecx, [esp+9Ch]
000A0007 [0042065F] 8d 44 24 0c                                  lea     eax, [esp+0Ch]
000A000B [00420663] 50                                           push    eax
000A000C [00420664] b8 00 60 0a 00                               mov     eax, 0A6000h
000A0011 [00420669] ff d0                                        call    eax
000A0013 [0042066B] 8b f0                                        mov     esi, eax
000A0015 [0042066D] 81 ee 70 17 00 00                            sub     esi, 1770h
000A001B [00420673] 68 c2 e5 49 00                               push    49E5C2h
000A0020 [00420678] c2 04 00                                     retn    4
