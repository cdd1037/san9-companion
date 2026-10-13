; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00424B08; baseline game VA=0x000A29E8; size=22
; Relative branch annotations use the baseline game destination.
000A29E8 [00424B08] 80 7f 54 04                                  cmp     byte ptr [edi+54h], 4
000A29EC [00424B0C] 74 0a                                        jz      short near ptr unk_424B18 ; game-relative-target=0x000A29F8
000A29EE [00424B0E] 8b 80 f8 00 00 00                            mov     eax, [eax+0F8h]
000A29F4 [00424B14] 89 44 24 10                                  mov     [esp+10h], eax
000A29F8 [00424B18] 68 d0 6e 56 00                               push    566ED0h
000A29FD [00424B1D] c3                                           retn
