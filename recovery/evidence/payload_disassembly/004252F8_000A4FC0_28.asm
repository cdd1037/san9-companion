; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004252F8; baseline game VA=0x000A4FC0; size=40
; Relative branch annotations use the baseline game destination.
000A4FC0 [004252F8] 8b 44 24 04                                  mov     eax, [esp+4]
000A4FC4 [004252FC] 8b 08                                        mov     ecx, [eax]
000A4FC6 [004252FE] 8b 41 08                                     mov     eax, [ecx+8]
000A4FC9 [00425301] ba 90 d0 03 00                               mov     edx, 3D090h
000A4FCE [00425306] f6 41 0f 08                                  test    byte ptr [ecx+0Fh], 8
000A4FD2 [0042530A] 74 03                                        jz      short near ptr unk_42530F ; game-relative-target=0x000A4FD7
000A4FD4 [0042530C] 8d 04 90                                     lea     eax, [eax+edx*4]
000A4FD7 [0042530F] 80 79 06 05                                  cmp     byte ptr [ecx+6], 5
000A4FDB [00425313] 74 02                                        jz      short near ptr unk_425317 ; game-relative-target=0x000A4FDF
000A4FDD [00425315] 03 c2                                        add     eax, edx
000A4FDF [00425317] f6 41 0f 40                                  test    byte ptr [ecx+0Fh], 40h ; '@'
000A4FE3 [0042531B] 75 02                                        jnz     short near ptr unk_42531F ; game-relative-target=0x000A4FE7
000A4FE5 [0042531D] 03 c2                                        add     eax, edx
000A4FE7 [0042531F] c3                                           retn
