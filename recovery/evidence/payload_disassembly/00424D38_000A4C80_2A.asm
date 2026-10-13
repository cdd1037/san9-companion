; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00424D38; baseline game VA=0x000A4C80; size=42
; Relative branch annotations use the baseline game destination.
000A4C80 [00424D38] 8b 44 24 04                                  mov     eax, [esp+4]
000A4C84 [00424D3C] 8b 08                                        mov     ecx, [eax]
000A4C86 [00424D3E] 83 79 24 00                                  cmp     dword ptr [ecx+24h], 0
000A4C8A [00424D42] 74 06                                        jz      short near ptr unk_424D4A ; game-relative-target=0x000A4C92
000A4C8C [00424D44] f6 41 20 03                                  test    byte ptr [ecx+20h], 3
000A4C90 [00424D48] 74 03                                        jz      short near ptr unk_424D4D ; game-relative-target=0x000A4C95
000A4C92 [00424D4A] 33 c0                                        xor     eax, eax
000A4C94 [00424D4C] c3                                           retn
000A4C95 [00424D4D] 8b 50 0c                                     mov     edx, [eax+0Ch]
000A4C98 [00424D50] 8b 41 74                                     mov     eax, [ecx+74h]
000A4C9B [00424D53] 8b 80 b8 00 00 00                            mov     eax, [eax+0B8h]
000A4CA1 [00424D59] 3b 82 b8 00 00 00                            cmp     eax, [edx+0B8h]
000A4CA7 [00424D5F] 75 e9                                        jnz     short near ptr unk_424D4A ; game-relative-target=0x000A4C92
000A4CA9 [00424D61] c3                                           retn
