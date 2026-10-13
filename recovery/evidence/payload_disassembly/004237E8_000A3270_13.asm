; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004237E8; baseline game VA=0x000A3270; size=19
; Relative branch annotations use the baseline game destination.
000A3270 [004237E8] 56                                           push    esi
000A3271 [004237E9] b8 80 57 43 00                               mov     eax, 435780h
000A3276 [004237EE] ff d0                                        call    eax
000A3278 [004237F0] f6 46 3d 80                                  test    byte ptr [esi+3Dh], 80h
000A327C [004237F4] 74 02                                        jz      short near ptr unk_4237F8 ; game-relative-target=0x000A3280
000A327E [004237F6] 34 01                                        xor     al, 1
000A3280 [004237F8] c2 04 00                                     retn    4
