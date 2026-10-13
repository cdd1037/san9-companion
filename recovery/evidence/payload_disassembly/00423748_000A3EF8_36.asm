; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00423748; baseline game VA=0x000A3EF8; size=54
; Relative branch annotations use the baseline game destination.
000A3EF8 [00423748] 8b f8                                        mov     edi, eax
000A3EFA [0042374A] 8b cb                                        mov     ecx, ebx
000A3EFC [0042374C] 8b 01                                        mov     eax, [ecx]
000A3EFE [0042374E] ff 50 3c                                     call    dword ptr [eax+3Ch]
000A3F01 [00423751] 85 c0                                        test    eax, eax
000A3F03 [00423753] 74 23                                        jz      short near ptr unk_423778 ; game-relative-target=0x000A3F28
000A3F05 [00423755] f6 05 c8 f4 43 00 01                         test    byte ptr ds:43F4C8h, 1
000A3F0C [0042375C] 74 0a                                        jz      short near ptr unk_423768 ; game-relative-target=0x000A3F18
000A3F0E [0042375E] 8b 54 24 1c                                  mov     edx, [esp+1Ch]
000A3F12 [00423762] 8b ba 28 04 00 00                            mov     edi, [edx+428h]
000A3F18 [00423768] c1 ef 02                                     shr     edi, 2
000A3F1B [0042376B] b0 06                                        mov     al, 6
000A3F1D [0042376D] f6 41 34 40                                  test    byte ptr [ecx+34h], 40h ; '@'
000A3F21 [00423771] 74 02                                        jz      short near ptr unk_423775 ; game-relative-target=0x000A3F25
000A3F23 [00423773] b0 05                                        mov     al, 5
000A3F25 [00423775] 0f af f8                                     imul    edi, eax
000A3F28 [00423778] 8d 14 3f                                     lea     edx, [edi+edi]
000A3F2B [0042377B] 33 c0                                        xor     eax, eax
000A3F2D [0042377D] c3                                           retn
