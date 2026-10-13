; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042CC90; baseline game VA=0x000A2400; size=114
; Relative branch annotations use the baseline game destination.
000A2400 [0042CC90] 85 f6                                        test    esi, esi
000A2402 [0042CC92] 7e 27                                        jle     short near ptr unk_42CCBB ; game-relative-target=0x000A242B
000A2404 [0042CC94] ff 74 24 40                                  push    dword ptr [esp+40h]
000A2408 [0042CC98] 68 f4 5f 60 00                               push    605FF4h
000A240D [0042CC9D] b8 80 68 40 00                               mov     eax, 406880h
000A2412 [0042CCA2] ff d0                                        call    eax
000A2414 [0042CCA4] 83 c4 08                                     add     esp, 8
000A2417 [0042CCA7] 85 c0                                        test    eax, eax
000A2419 [0042CCA9] 74 10                                        jz      short near ptr unk_42CCBB ; game-relative-target=0x000A242B
000A241B [0042CCAB] 8b d0                                        mov     edx, eax
000A241D [0042CCAD] 8b c8                                        mov     ecx, eax
000A241F [0042CCAF] 8b 02                                        mov     eax, [edx]
000A2421 [0042CCB1] ff 90 b8 00 00 00                            call    dword ptr [eax+0B8h]
000A2427 [0042CCB7] 3b c7                                        cmp     eax, edi
000A2429 [0042CCB9] 74 01                                        jz      short near ptr unk_42CCBC ; game-relative-target=0x000A242C
000A242B [0042CCBB] c3                                           retn
000A242C [0042CCBC] 53                                           push    ebx
000A242D [0042CCBD] 55                                           push    ebp
000A242E [0042CCBE] 8b ea                                        mov     ebp, edx
000A2430 [0042CCC0] 8b 5c 24 18                                  mov     ebx, [esp+18h]
000A2434 [0042CCC4] 85 db                                        test    ebx, ebx
000A2436 [0042CCC6] 74 33                                        jz      short near ptr unk_42CCFB ; game-relative-target=0x000A246B
000A2438 [0042CCC8] 8b 4b 08                                     mov     ecx, [ebx+8]
000A243B [0042CCCB] 8b 1b                                        mov     ebx, [ebx]
000A243D [0042CCCD] b8 70 d0 45 00                               mov     eax, 45D070h
000A2442 [0042CCD2] ff d0                                        call    eax
000A2444 [0042CCD4] 85 c0                                        test    eax, eax
000A2446 [0042CCD6] 74 ec                                        jz      short near ptr unk_42CCC4 ; game-relative-target=0x000A2434
000A2448 [0042CCD8] 8b f8                                        mov     edi, eax
000A244A [0042CCDA] 8b c8                                        mov     ecx, eax
000A244C [0042CCDC] b8 40 54 43 00                               mov     eax, 435440h
000A2451 [0042CCE1] ff d0                                        call    eax
000A2453 [0042CCE3] 85 c0                                        test    eax, eax
000A2455 [0042CCE5] 75 0e                                        jnz     short near ptr unk_42CCF5 ; game-relative-target=0x000A2465
000A2457 [0042CCE7] 57                                           push    edi
000A2458 [0042CCE8] 8b cd                                        mov     ecx, ebp
000A245A [0042CCEA] b8 80 e1 45 00                               mov     eax, 45E180h
000A245F [0042CCEF] ff d0                                        call    eax
000A2461 [0042CCF1] 85 c0                                        test    eax, eax
000A2463 [0042CCF3] 74 cf                                        jz      short near ptr unk_42CCC4 ; game-relative-target=0x000A2434
000A2465 [0042CCF5] 81 ce 00 00 02 00                            or      esi, 20000h
000A246B [0042CCFB] c1 e6 0c                                     shl     esi, 0Ch
000A246E [0042CCFE] 5d                                           pop     ebp
000A246F [0042CCFF] 5b                                           pop     ebx
000A2470 [0042CD00] c3                                           retn
000A2471 [0042CD01] 90                                           nop
