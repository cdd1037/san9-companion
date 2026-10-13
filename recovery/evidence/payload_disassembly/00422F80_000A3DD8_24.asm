; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00422F80; baseline game VA=0x000A3DD8; size=36
; Relative branch annotations use the baseline game destination.
000A3DD8 [00422F80] c6 05 c8 f4 43 00 00                         mov     byte ptr ds:43F4C8h, 0
000A3DDF [00422F87] 89 3d 0c fc 43 00                            mov     ds:43FC0Ch, edi
000A3DE5 [00422F8D] 3b c7                                        cmp     eax, edi
000A3DE7 [00422F8F] 75 0d                                        jnz     short near ptr unk_422F9E ; game-relative-target=0x000A3DF6
000A3DE9 [00422F91] 8b 80 cc 00 00 00                            mov     eax, [eax+0CCh]
000A3DEF [00422F97] 3b 46 38                                     cmp     eax, [esi+38h]
000A3DF2 [00422F9A] 74 02                                        jz      short near ptr unk_422F9E ; game-relative-target=0x000A3DF6
000A3DF4 [00422F9C] 33 ff                                        xor     edi, edi
000A3DF6 [00422F9E] 68 40 58 40 00                               push    405840h
000A3DFB [00422FA3] c3                                           retn
