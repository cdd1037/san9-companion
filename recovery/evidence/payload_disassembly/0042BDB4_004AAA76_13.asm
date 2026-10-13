; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042BDB4; baseline game VA=0x004AAA76; size=19
; Relative branch annotations use the baseline game destination.
004AAA76 [0042BDB4] 85 ff                                        test    edi, edi
004AAA78 [0042BDB6] 8b c8                                        mov     ecx, eax
004AAA7A [0042BDB8] 74 08                                        jz      short near ptr unk_42BDC2 ; game-relative-target=0x004AAA84
004AAA7C [0042BDBA] 83 f9 07                                     cmp     ecx, 7
004AAA7F [0042BDBD] 7d 2c                                        jge     short near ptr unk_42BDEB ; game-relative-target=0x004AAAAD
004AAA81 [0042BDBF] 57                                           push    edi
004AAA82 [0042BDC0] eb 69                                        jmp     short near ptr unk_42BE2B ; game-relative-target=0x004AAAED
004AAA84 [0042BDC2] 83 f9 07                                     cmp     ecx, 7
004AAA87 [0042BDC5] 7d 24                                        jge     short near ptr unk_42BDEB ; game-relative-target=0x004AAAAD
