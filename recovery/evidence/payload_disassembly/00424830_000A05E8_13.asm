; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00424830; baseline game VA=0x000A05E8; size=19
; Relative branch annotations use the baseline game destination.
000A05E8 [00424830] b8 90 01 0a 00                               mov     eax, 0A0190h
000A05ED [00424835] ff d0                                        call    eax
000A05EF [00424837] 85 c0                                        test    eax, eax
000A05F1 [00424839] 8b c6                                        mov     eax, esi
000A05F3 [0042483B] 75 01                                        jnz     short near ptr unk_42483E ; game-relative-target=0x000A05F6
000A05F5 [0042483D] 40                                           inc     eax
000A05F6 [0042483E] c6 04 24 32                                  mov     byte ptr [esp], 32h ; '2'
000A05FA [00424842] c3                                           retn
