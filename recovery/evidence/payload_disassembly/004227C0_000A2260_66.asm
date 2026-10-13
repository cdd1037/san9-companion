; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004227C0; baseline game VA=0x000A2260; size=102
; Relative branch annotations use the baseline game destination.
000A2260 [004227C0] 51                                           push    ecx
000A2261 [004227C1] 6a 01                                        push    1
000A2263 [004227C3] 6a 0b                                        push    0Bh
000A2265 [004227C5] 6a 02                                        push    2
000A2267 [004227C7] ff 15 18 f3 5f 00                            call    dword ptr ds:5FF318h
000A226D [004227CD] 83 c4 0c                                     add     esp, 0Ch
000A2270 [004227D0] 85 c0                                        test    eax, eax
000A2272 [004227D2] 74 07                                        jz      short near ptr unk_4227DB ; game-relative-target=0x000A227B
000A2274 [004227D4] 59                                           pop     ecx
000A2275 [004227D5] 68 00 e9 46 00                               push    46E900h
000A227A [004227DA] c3                                           retn
000A227B [004227DB] 59                                           pop     ecx
000A227C [004227DC] 51                                           push    ecx
000A227D [004227DD] 8b 51 04                                     mov     edx, [ecx+4]
000A2280 [004227E0] 8b 4a 08                                     mov     ecx, [edx+8]
000A2283 [004227E3] 8b 81 cc 00 00 00                            mov     eax, [ecx+0CCh]
000A2289 [004227E9] 85 c0                                        test    eax, eax
000A228B [004227EB] 74 0c                                        jz      short near ptr unk_4227F9 ; game-relative-target=0x000A2299
000A228D [004227ED] 8b 80 b8 00 00 00                            mov     eax, [eax+0B8h]
000A2293 [004227F3] f6 40 34 01                                  test    byte ptr [eax+34h], 1
000A2297 [004227F7] 74 29                                        jz      short near ptr unk_422822 ; game-relative-target=0x000A22C2
000A2299 [004227F9] 8b 12                                        mov     edx, [edx]
000A229B [004227FB] 85 d2                                        test    edx, edx
000A229D [004227FD] 75 e1                                        jnz     short near ptr unk_4227E0 ; game-relative-target=0x000A2280
000A229F [004227FF] 8b 86 f4 00 00 00                            mov     eax, [esi+0F4h]
000A22A5 [00422805] 8b 48 64                                     mov     ecx, [eax+64h]
000A22A8 [00422808] 85 c9                                        test    ecx, ecx
000A22AA [0042280A] 74 c8                                        jz      short near ptr unk_4227D4 ; game-relative-target=0x000A2274
000A22AC [0042280C] 8b 81 cc 00 00 00                            mov     eax, [ecx+0CCh]
000A22B2 [00422812] 85 c0                                        test    eax, eax
000A22B4 [00422814] 74 be                                        jz      short near ptr unk_4227D4 ; game-relative-target=0x000A2274
000A22B6 [00422816] 8b 80 b8 00 00 00                            mov     eax, [eax+0B8h]
000A22BC [0042281C] f6 40 34 01                                  test    byte ptr [eax+34h], 1
000A22C0 [00422820] 75 b2                                        jnz     short near ptr unk_4227D4 ; game-relative-target=0x000A2274
000A22C2 [00422822] 58                                           pop     eax
000A22C3 [00422823] 8b c1                                        mov     eax, ecx
000A22C5 [00422825] c3                                           retn
