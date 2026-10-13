; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00422550; baseline game VA=0x000A1F80; size=32
; Relative branch annotations use the baseline game destination.
000A1F80 [00422550] 8b 81 f4 00 00 00                            mov     eax, [ecx+0F4h]
000A1F86 [00422556] 83 78 58 25                                  cmp     dword ptr [eax+58h], 25h ; '%'
000A1F8A [0042255A] 74 06                                        jz      short near ptr unk_422562 ; game-relative-target=0x000A1F92
000A1F8C [0042255C] 68 c0 dc 44 00                               push    44DCC0h
000A1F91 [00422561] c3                                           retn
000A1F92 [00422562] 83 b8 90 00 00 00 02                         cmp     dword ptr [eax+90h], 2
000A1F99 [00422569] 75 f1                                        jnz     short near ptr unk_42255C ; game-relative-target=0x000A1F8C
000A1F9B [0042256B] 33 c0                                        xor     eax, eax
000A1F9D [0042256D] c2 04 00                                     retn    4
