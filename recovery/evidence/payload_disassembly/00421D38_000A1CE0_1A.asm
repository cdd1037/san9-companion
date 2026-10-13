; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00421D38; baseline game VA=0x000A1CE0; size=26
; Relative branch annotations use the baseline game destination.
000A1CE0 [00421D38] 80 7f 0c c8                                  cmp     byte ptr [edi+0Ch], 0C8h
000A1CE4 [00421D3C] 74 06                                        jz      short near ptr unk_421D44 ; game-relative-target=0x000A1CEC
000A1CE6 [00421D3E] 68 10 f6 46 00                               push    46F610h
000A1CEB [00421D43] c3                                           retn
000A1CEC [00421D44] 8b 49 04                                     mov     ecx, [ecx+4]
000A1CEF [00421D47] a1 68 fa 43 00                               mov     eax, ds:43FA68h
000A1CF4 [00421D4C] 89 41 08                                     mov     [ecx+8], eax
000A1CF7 [00421D4F] c2 08 00                                     retn    8
