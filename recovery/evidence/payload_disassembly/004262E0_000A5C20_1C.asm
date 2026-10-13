; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004262E0; baseline game VA=0x000A5C20; size=28
; Relative branch annotations use the baseline game destination.
000A5C20 [004262E0] 80 79 58 26                                  cmp     byte ptr [ecx+58h], 26h ; '&'
000A5C24 [004262E4] 75 0e                                        jnz     short near ptr unk_4262F4 ; game-relative-target=0x000A5C34
000A5C26 [004262E6] 80 79 52 03                                  cmp     byte ptr [ecx+52h], 3
000A5C2A [004262EA] 74 08                                        jz      short near ptr unk_4262F4 ; game-relative-target=0x000A5C34
000A5C2C [004262EC] b8 60 5b 0a 00                               mov     eax, 0A5B60h
000A5C31 [004262F1] ff d0                                        call    eax
000A5C33 [004262F3] c3                                           retn
000A5C34 [004262F4] b8 b0 42 46 00                               mov     eax, 4642B0h
000A5C39 [004262F9] ff d0                                        call    eax
000A5C3B [004262FB] c3                                           retn
