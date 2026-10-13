; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042C9D0; baseline game VA=0x000A9BE0; size=32
; Relative branch annotations use the baseline game destination.
000A9BE0 [0042C9D0] a1 fc 9b 0a 00                               mov     eax, ds:0A9BFCh
000A9BE5 [0042C9D5] 85 c0                                        test    eax, eax
000A9BE7 [0042C9D7] 74 0d                                        jz      short near ptr unk_42C9E6 ; game-relative-target=0x000A9BF6
000A9BE9 [0042C9D9] 8a 44 24 10                                  mov     al, [esp+10h]
000A9BED [0042C9DD] 08 44 24 14                                  or      [esp+14h], al
000A9BF1 [0042C9E1] 80 4c 24 10 09                               or      byte ptr [esp+10h], 9
000A9BF6 [0042C9E6] 68 d0 91 51 00                               push    5191D0h
000A9BFB [0042C9EB] c3                                           retn
000A9BFC [0042C9EC] 00    db 0x00
000A9BFD [0042C9ED] 00    db 0x00
000A9BFE [0042C9EE] 00    db 0x00
000A9BFF [0042C9EF] 00    db 0x00
