; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042C948; baseline game VA=0x0052BC4A; size=54
; Relative branch annotations use the baseline game destination.
0052BC4A [0042C948] 8b f8                                        mov     edi, eax
0052BC4C [0042C94A] 6a 11                                        push    11h
0052BC4E [0042C94C] ff 15 5c f3 5f 00                            call    dword ptr ds:5FF35Ch
0052BC54 [0042C952] 8b b7 18 01 00 00                            mov     esi, [edi+118h]
0052BC5A [0042C958] 84 e4                                        test    ah, ah
0052BC5C [0042C95A] 79 19                                        jns     short near ptr unk_42C975 ; game-relative-target=0x0052BC77
0052BC5E [0042C95C] 8b 15 fc 9b 0a 00                            mov     edx, ds:0A9BFCh
0052BC64 [0042C962] 3b f2                                        cmp     esi, edx
0052BC66 [0042C964] 74 0f                                        jz      short near ptr unk_42C975 ; game-relative-target=0x0052BC77
0052BC68 [0042C966] 89 35 fc 9b 0a 00                            mov     ds:0A9BFCh, esi
0052BC6E [0042C96C] 8d 56 10                                     lea     edx, [esi+10h]
0052BC71 [0042C96F] 52                                           push    edx
0052BC72 [0042C970] e8 11 8d ee ff                               call    near ptr 315686h ; game-relative-target=0x00414988
0052BC77 [0042C975] 83 e6 01                                     and     esi, 1
0052BC7A [0042C978] 83 f6 01                                     xor     esi, 1
0052BC7D [0042C97B] 56                                           push    esi
0052BC7E [0042C97C] 8b cf                                        mov     ecx, edi
