; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00420018; baseline game VA=0x00450923; size=13
; Relative branch annotations use the baseline game destination.
00450923 [00420018] f6 41 20 80                                  test    byte ptr [ecx+20h], 80h
00450927 [0042001C] 75 04                                        jnz     short near ptr unk_420022 ; game-relative-target=0x0045092D
00450929 [0042001E] 80 61 20 f7                                  and     byte ptr [ecx+20h], 0F7h
0045092D [00420022] c2 08 00                                     retn    8
