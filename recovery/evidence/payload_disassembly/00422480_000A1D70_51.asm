; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00422480; baseline game VA=0x000A1D70; size=81
; Relative branch annotations use the baseline game destination.
000A1D70 [00422480] 8b 4c 24 04                                  mov     ecx, [esp+4]
000A1D74 [00422484] 8b 41 0c                                     mov     eax, [ecx+0Ch]
000A1D77 [00422487] 8b 90 b8 00 00 00                            mov     edx, [eax+0B8h]
000A1D7D [0042248D] f6 42 34 01                                  test    byte ptr [edx+34h], 1
000A1D81 [00422491] 74 06                                        jz      short near ptr unk_422499 ; game-relative-target=0x000A1D89
000A1D83 [00422493] 68 10 68 4b 00                               push    4B6810h
000A1D88 [00422498] c3                                           retn
000A1D89 [00422499] 8b 09                                        mov     ecx, [ecx]
000A1D8B [0042249B] 8b 81 48 01 00 00                            mov     eax, [ecx+148h]
000A1D91 [004224A1] 85 c0                                        test    eax, eax
000A1D93 [004224A3] 74 00                                        jz      short $+2 ; game-relative-target=0x000A1D95
000A1D95 [004224A5] c3                                           retn
000A1D96 [004224A6] 83 ec 20                                     sub     esp, 20h ; ' '
000A1D99 [004224A9] 6a 00                                        push    0
000A1D9B [004224AB] 51                                           push    ecx
000A1D9C [004224AC] 8d 4c 24 08                                  lea     ecx, [esp+8]
000A1DA0 [004224B0] b8 00 fc 46 00                               mov     eax, 46FC00h
000A1DA5 [004224B5] ff d0                                        call    eax
000A1DA7 [004224B7] 50                                           push    eax
000A1DA8 [004224B8] b8 50 2f 45 00                               mov     eax, 452F50h
000A1DAD [004224BD] ff d0                                        call    eax
000A1DAF [004224BF] 83 c4 0c                                     add     esp, 0Ch
000A1DB2 [004224C2] 8b cc                                        mov     ecx, esp
000A1DB4 [004224C4] 50                                           push    eax
000A1DB5 [004224C5] b8 20 fc 46 00                               mov     eax, 46FC20h
000A1DBA [004224CA] ff d0                                        call    eax
000A1DBC [004224CC] 58                                           pop     eax
000A1DBD [004224CD] 83 c4 20                                     add     esp, 20h ; ' '
000A1DC0 [004224D0] c3                                           retn
