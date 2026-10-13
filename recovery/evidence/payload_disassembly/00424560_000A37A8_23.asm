; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00424560; baseline game VA=0x000A37A8; size=35
; Relative branch annotations use the baseline game destination.
000A37A8 [00424560] 80 7f 06 05                                  cmp     byte ptr [edi+6], 5
000A37AC [00424564] 74 11                                        jz      short near ptr unk_424577 ; game-relative-target=0x000A37BF
000A37AE [00424566] 80 bf 90 00 00 00 5c                         cmp     byte ptr [edi+90h], 5Ch ; '\'
000A37B5 [0042456D] 7d 08                                        jge     short near ptr unk_424577 ; game-relative-target=0x000A37BF
000A37B7 [0042456F] c7 44 24 08 c5 37 0a 00                      mov     dword ptr [esp+8], 0A37C5h
000A37BF [00424577] 68 80 32 47 00                               push    473280h
000A37C4 [0042457C] c3                                           retn
000A37C5 [0042457D] b8 64 00 00 00                               mov     eax, 64h ; 'd'
000A37CA [00424582] c3                                           retn
