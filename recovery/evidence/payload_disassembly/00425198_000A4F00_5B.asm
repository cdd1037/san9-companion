; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00425198; baseline game VA=0x000A4F00; size=91
; Relative branch annotations use the baseline game destination.
000A4F00 [00425198] 33 c0                                        xor     eax, eax
000A4F02 [0042519A] 8b 54 24 04                                  mov     edx, [esp+4]
000A4F06 [0042519E] 85 d2                                        test    edx, edx
000A4F08 [004251A0] 75 05                                        jnz     short near ptr unk_4251A7 ; game-relative-target=0x000A4F0F
000A4F0A [004251A2] b0 04                                        mov     al, 4
000A4F0C [004251A4] c2 04 00                                     retn    4
000A4F0F [004251A7] 8b 92 b8 00 00 00                            mov     edx, [edx+0B8h]
000A4F15 [004251AD] 8b 89 b8 00 00 00                            mov     ecx, [ecx+0B8h]
000A4F1B [004251B3] 3b d1                                        cmp     edx, ecx
000A4F1D [004251B5] 74 ed                                        jz      short near ptr unk_4251A4 ; game-relative-target=0x000A4F0C
000A4F1F [004251B7] f6 42 34 04                                  test    byte ptr [edx+34h], 4
000A4F23 [004251BB] 74 04                                        jz      short near ptr unk_4251C1 ; game-relative-target=0x000A4F29
000A4F25 [004251BD] b0 05                                        mov     al, 5
000A4F27 [004251BF] eb e3                                        jmp     short near ptr unk_4251A4 ; game-relative-target=0x000A4F0C
000A4F29 [004251C1] f6 42 34 01                                  test    byte ptr [edx+34h], 1
000A4F2D [004251C5] 74 04                                        jz      short near ptr unk_4251CB ; game-relative-target=0x000A4F33
000A4F2F [004251C7] b0 03                                        mov     al, 3
000A4F31 [004251C9] eb d9                                        jmp     short near ptr unk_4251A4 ; game-relative-target=0x000A4F0C
000A4F33 [004251CB] 0f b6 42 04                                  movzx   eax, byte ptr [edx+4]
000A4F37 [004251CF] 8a 44 01 38                                  mov     al, [ecx+eax+38h]
000A4F3B [004251D3] 3c 46                                        cmp     al, 46h ; 'F'
000A4F3D [004251D5] 7f 17                                        jg      short near ptr unk_4251EE ; game-relative-target=0x000A4F56
000A4F3F [004251D7] b0 02                                        mov     al, 2
000A4F41 [004251D9] f6 41 34 30                                  test    byte ptr [ecx+34h], 30h ; '0'
000A4F45 [004251DD] 74 11                                        jz      short near ptr unk_4251F0 ; game-relative-target=0x000A4F58
000A4F47 [004251DF] f6 42 34 30                                  test    byte ptr [edx+34h], 30h ; '0'
000A4F4B [004251E3] 74 0b                                        jz      short near ptr unk_4251F0 ; game-relative-target=0x000A4F58
000A4F4D [004251E5] 83 3d 90 24 23 01 07                         cmp     dword ptr ds:1232490h, 7
000A4F54 [004251EC] 7e 02                                        jle     short near ptr unk_4251F0 ; game-relative-target=0x000A4F58
000A4F56 [004251EE] 33 c0                                        xor     eax, eax
000A4F58 [004251F0] c2 04 00                                     retn    4
