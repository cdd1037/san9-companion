; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00423FD8; baseline game VA=0x000A3550; size=96
; Relative branch annotations use the baseline game destination.
000A3550 [00423FD8] 8b 8c 24 e0 00 00 00                         mov     ecx, [esp+0E0h]
000A3557 [00423FDF] b8 e0 2d 0a 00                               mov     eax, 0A2DE0h
000A355C [00423FE4] ff d0                                        call    eax
000A355E [00423FE6] 3c 02                                        cmp     al, 2
000A3560 [00423FE8] 74 0d                                        jz      short near ptr unk_423FF7 ; game-relative-target=0x000A356F
000A3562 [00423FEA] 3c 01                                        cmp     al, 1
000A3564 [00423FEC] 74 06                                        jz      short near ptr unk_423FF4 ; game-relative-target=0x000A356C
000A3566 [00423FEE] 58                                           pop     eax
000A3567 [00423FEF] 68 78 1d 4a 00                               push    4A1D78h
000A356C [00423FF4] c2 04 00                                     retn    4
000A356F [00423FF7] 8b 8c 24 e4 00 00 00                         mov     ecx, [esp+0E4h]
000A3576 [00423FFE] 68 38 eb 4f 01                               push    14FEB38h
000A357B [00424003] b8 00 0d 46 00                               mov     eax, 460D00h
000A3580 [00424008] ff d0                                        call    eax
000A3582 [0042400A] 85 c0                                        test    eax, eax
000A3584 [0042400C] 75 e6                                        jnz     short near ptr unk_423FF4 ; game-relative-target=0x000A356C
000A3586 [0042400E] 8b 8c 24 e4 00 00 00                         mov     ecx, [esp+0E4h]
000A358D [00424015] 68 08 e9 4f 01                               push    14FE908h
000A3592 [0042401A] b8 00 0d 46 00                               mov     eax, 460D00h
000A3597 [0042401F] ff d0                                        call    eax
000A3599 [00424021] 85 c0                                        test    eax, eax
000A359B [00424023] 75 cf                                        jnz     short near ptr unk_423FF4 ; game-relative-target=0x000A356C
000A359D [00424025] f6 44 24 58 01                               test    byte ptr [esp+58h], 1
000A35A2 [0042402A] 75 c2                                        jnz     short near ptr unk_423FEE ; game-relative-target=0x000A3566
000A35A4 [0042402C] f6 44 24 60 01                               test    byte ptr [esp+60h], 1
000A35A9 [00424031] 75 bb                                        jnz     short near ptr unk_423FEE ; game-relative-target=0x000A3566
000A35AB [00424033] b0 01                                        mov     al, 1
000A35AD [00424035] c2 04 00                                     retn    4
