; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004299D8; baseline game VA=0x000A8088; size=186
; Relative branch annotations use the baseline game destination.
000A8088 [004299D8] 68 a0 3e 49 00                               push    493EA0h
000A808D [004299DD] 8d 86 b4 06 00 00                            lea     eax, [esi+6B4h]
000A8093 [004299E3] 50                                           push    eax
000A8094 [004299E4] 57                                           push    edi
000A8095 [004299E5] 56                                           push    esi
000A8096 [004299E6] 68 00 80 0a 00                               push    0A8000h
000A809B [004299EB] c3                                           retn
000A809C [004299EC] 90                                           nop
000A809D [004299ED] 90                                           nop
000A809E [004299EE] 90                                           nop
000A809F [004299EF] 90                                           nop
000A80A0 [004299F0] 68 10 4f 49 00                               push    494F10h
000A80A5 [004299F5] 8d 45 e0                                     lea     eax, [ebp-20h]
000A80A8 [004299F8] 50                                           push    eax
000A80A9 [004299F9] 8d 85 00 0c 00 00                            lea     eax, [ebp+0C00h]
000A80AF [004299FF] 50                                           push    eax
000A80B0 [00429A00] 8d 95 2c f9 ff ff                            lea     edx, [ebp-6D4h]
000A80B6 [00429A06] 52                                           push    edx
000A80B7 [00429A07] 68 00 80 0a 00                               push    0A8000h
000A80BC [00429A0C] c3                                           retn
000A80BD [00429A0D] 90                                           nop
000A80BE [00429A0E] 90                                           nop
000A80BF [00429A0F] 90                                           nop
000A80C0 [00429A10] 68 d0 31 49 00                               push    4931D0h
000A80C5 [00429A15] 8d 45 e0                                     lea     eax, [ebp-20h]
000A80C8 [00429A18] 50                                           push    eax
000A80C9 [00429A19] 8d 85 34 0d 00 00                            lea     eax, [ebp+0D34h]
000A80CF [00429A1F] 50                                           push    eax
000A80D0 [00429A20] 8d 95 2c f9 ff ff                            lea     edx, [ebp-6D4h]
000A80D6 [00429A26] 52                                           push    edx
000A80D7 [00429A27] 68 00 80 0a 00                               push    0A8000h
000A80DC [00429A2C] c3                                           retn
000A80DD [00429A2D] 90                                           nop
000A80DE [00429A2E] 90                                           nop
000A80DF [00429A2F] 90                                           nop
000A80E0 [00429A30] 68 50 62 49 00                               push    496250h
000A80E5 [00429A35] eb 29                                        jmp     short near ptr unk_429A60 ; game-relative-target=0x000A8110
000A80E7 [00429A37] 90                                           nop
000A80E8 [00429A38] 68 b0 d5 48 00                               push    48D5B0h
000A80ED [00429A3D] eb 21                                        jmp     short near ptr unk_429A60 ; game-relative-target=0x000A8110
000A80EF [00429A3F] 90                                           nop
000A80F0 [00429A40] 68 b0 e9 48 00                               push    48E9B0h
000A80F5 [00429A45] eb 19                                        jmp     short near ptr unk_429A60 ; game-relative-target=0x000A8110
000A80F7 [00429A47] 90                                           nop
000A80F8 [00429A48] 68 f0 07 49 00                               push    4907F0h
000A80FD [00429A4D] eb 11                                        jmp     short near ptr unk_429A60 ; game-relative-target=0x000A8110
000A80FF [00429A4F] 90                                           nop
000A8100 [00429A50] 68 20 e4 48 00                               push    48E420h
000A8105 [00429A55] eb 09                                        jmp     short near ptr unk_429A60 ; game-relative-target=0x000A8110
000A8107 [00429A57] 90                                           nop
000A8108 [00429A58] 68 c0 26 49 00                               push    4926C0h
000A810D [00429A5D] 8d 49 00                                     lea     ecx, [ecx+0]
000A8110 [00429A60] 8d 86 b4 06 00 00                            lea     eax, [esi+6B4h]
000A8116 [00429A66] 50                                           push    eax
000A8117 [00429A67] 8d 86 f4 06 00 00                            lea     eax, [esi+6F4h]
000A811D [00429A6D] 50                                           push    eax
000A811E [00429A6E] 56                                           push    esi
000A811F [00429A6F] 68 00 80 0a 00                               push    0A8000h
000A8124 [00429A74] c3                                           retn
000A8125 [00429A75] 90                                           nop
000A8126 [00429A76] 90                                           nop
000A8127 [00429A77] 90                                           nop
000A8128 [00429A78] 68 10 0f 49 00                               push    490F10h
000A812D [00429A7D] 8d 96 0c 12 00 00                            lea     edx, [esi+120Ch]
000A8133 [00429A83] 8d 86 4c 12 00 00                            lea     eax, [esi+124Ch]
000A8139 [00429A89] 52                                           push    edx
000A813A [00429A8A] 50                                           push    eax
000A813B [00429A8B] 56                                           push    esi
000A813C [00429A8C] 68 00 80 0a 00                               push    0A8000h
000A8141 [00429A91] c3                                           retn
