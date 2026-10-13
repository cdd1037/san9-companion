; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00420054; baseline game VA=0x000A3AC0; size=57
; Relative branch annotations use the baseline game destination.
000A3AC0 [00420054] 8b 41 74                                     mov     eax, [ecx+74h]
000A3AC3 [00420057] f6 40 34 05                                  test    byte ptr [eax+34h], 5
000A3AC7 [0042005B] 75 1a                                        jnz     short near ptr unk_420077 ; game-relative-target=0x000A3AE3
000A3AC9 [0042005D] 80 79 52 03                                  cmp     byte ptr [ecx+52h], 3
000A3ACD [00420061] 75 14                                        jnz     short near ptr unk_420077 ; game-relative-target=0x000A3AE3
000A3ACF [00420063] 8b 41 64                                     mov     eax, [ecx+64h]
000A3AD2 [00420066] 81 b8 88 00 00 00 10 27 00 00                cmp     dword ptr [eax+88h], 2710h
000A3ADC [00420070] 7d 02                                        jge     short near ptr unk_420074 ; game-relative-target=0x000A3AE0
000A3ADE [00420072] 33 c0                                        xor     eax, eax
000A3AE0 [00420074] c2 04 00                                     retn    4
000A3AE3 [00420077] 81 3c 24 34 52 46 00                         cmp     dword ptr [esp], 465234h
000A3AEA [0042007E] 75 07                                        jnz     short near ptr unk_420087 ; game-relative-target=0x000A3AF3
000A3AEC [00420080] 68 90 0e 46 00                               push    460E90h
000A3AF1 [00420085] eb 05                                        jmp     short near ptr unk_42008C ; game-relative-target=0x000A3AF8
000A3AF3 [00420087] 68 b0 0e 46 00                               push    460EB0h
000A3AF8 [0042008C] c3                                           retn
