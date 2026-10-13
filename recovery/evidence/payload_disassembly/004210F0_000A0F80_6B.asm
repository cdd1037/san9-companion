; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004210F0; baseline game VA=0x000A0F80; size=107
; Relative branch annotations use the baseline game destination.
000A0F80 [004210F0] 8b 4c 24 04                                  mov     ecx, [esp+4]
000A0F84 [004210F4] 8b 11                                        mov     edx, [ecx]
000A0F86 [004210F6] 83 7a 24 00                                  cmp     dword ptr [edx+24h], 0
000A0F8A [004210FA] 74 5c                                        jz      short near ptr unk_421158 ; game-relative-target=0x000A0FE8
000A0F8C [004210FC] f6 42 20 03                                  test    byte ptr [edx+20h], 3
000A0F90 [00421100] 75 56                                        jnz     short near ptr unk_421158 ; game-relative-target=0x000A0FE8
000A0F92 [00421102] 8b 49 0c                                     mov     ecx, [ecx+0Ch]
000A0F95 [00421105] 8b 41 04                                     mov     eax, [ecx+4]
000A0F98 [00421108] 83 7a 54 ff                                  cmp     dword ptr [edx+54h], 0FFFFFFFFh
000A0F9C [0042110C] 75 12                                        jnz     short near ptr unk_421120 ; game-relative-target=0x000A0FB0
000A0F9E [0042110E] 39 42 50                                     cmp     [edx+50h], eax
000A0FA1 [00421111] 0f 85 59 f6 ff ff                            jnz     near ptr unk_420770 ; game-relative-target=0x000A0600
000A0FA7 [00421117] 80 7a 58 26                                  cmp     byte ptr [edx+58h], 26h ; '&'
000A0FAB [0042111B] 75 3b                                        jnz     short near ptr unk_421158 ; game-relative-target=0x000A0FE8
000A0FAD [0042111D] b0 01                                        mov     al, 1
000A0FAF [0042111F] c3                                           retn
000A0FB0 [00421120] 39 42 54                                     cmp     [edx+54h], eax
000A0FB3 [00421123] 74 f8                                        jz      short near ptr unk_42111D ; game-relative-target=0x000A0FAD
000A0FB5 [00421125] 39 42 50                                     cmp     [edx+50h], eax
000A0FB8 [00421128] 75 2e                                        jnz     short near ptr unk_421158 ; game-relative-target=0x000A0FE8
000A0FBA [0042112A] 8a 42 56                                     mov     al, [edx+56h]
000A0FBD [0042112D] 3c 03                                        cmp     al, 3
000A0FBF [0042112F] 75 27                                        jnz     short near ptr unk_421158 ; game-relative-target=0x000A0FE8
000A0FC1 [00421131] 0f b7 42 54                                  movzx   eax, word ptr [edx+54h]
000A0FC5 [00421135] 69 c0 04 01 00 00                            imul    eax, 104h
000A0FCB [0042113B] 05 b0 93 4b 01                               add     eax, 14B93B0h
000A0FD0 [00421140] 8b 40 74                                     mov     eax, [eax+74h]
000A0FD3 [00421143] 39 81 cc 00 00 00                            cmp     [ecx+0CCh], eax
000A0FD9 [00421149] 75 0d                                        jnz     short near ptr unk_421158 ; game-relative-target=0x000A0FE8
000A0FDB [0042114B] 52                                           push    edx
000A0FDC [0042114C] b8 80 0a 0a 00                               mov     eax, 0A0A80h
000A0FE1 [00421151] ff d0                                        call    eax
000A0FE3 [00421153] 83 f8 28                                     cmp     eax, 28h ; '('
000A0FE6 [00421156] 7c 02                                        jl      short near ptr unk_42115A ; game-relative-target=0x000A0FEA
000A0FE8 [00421158] 33 c0                                        xor     eax, eax
000A0FEA [0042115A] c3                                           retn
