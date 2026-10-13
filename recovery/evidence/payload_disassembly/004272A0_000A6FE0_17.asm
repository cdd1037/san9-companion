; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004272A0; baseline game VA=0x000A6FE0; size=23
; Relative branch annotations use the baseline game destination.
000A6FE0 [004272A0] 8b 41 04                                     mov     eax, [ecx+4]
000A6FE3 [004272A3] 8b 48 08                                     mov     ecx, [eax+8]
000A6FE6 [004272A6] b8 60 63 0a 00                               mov     eax, 0A6360h
000A6FEB [004272AB] ff d0                                        call    eax
000A6FED [004272AD] 85 c0                                        test    eax, eax
000A6FEF [004272AF] 74 05                                        jz      short near ptr unk_4272B6 ; game-relative-target=0x000A6FF6
000A6FF1 [004272B1] 68 c0 3e 43 00                               push    433EC0h
000A6FF6 [004272B6] c3                                           retn
