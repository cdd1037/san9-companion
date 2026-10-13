; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042BDA0; baseline game VA=0x004AAA76; size=19
; Relative branch annotations use the baseline game destination.
004AAA76 [0042BDA0] 83 f8 0a                                     cmp     eax, 0Ah
004AAA79 [0042BDA3] 7c 07                                        jl      short near ptr unk_42BDAC ; game-relative-target=0x004AAA82
004AAA7B [0042BDA5] e8 80 f5 bf ff                               call    near ptr 2B32Ah ; game-relative-target=0x000AA000
004AAA80 [0042BDAA] eb 5d                                        jmp     short near ptr unk_42BE09 ; game-relative-target=0x004AAADF
004AAA82 [0042BDAC] 85 ff                                        test    edi, edi
004AAA84 [0042BDAE] 74 03                                        jz      short near ptr unk_42BDB3 ; game-relative-target=0x004AAA89
004AAA86 [0042BDB0] 57                                           push    edi
004AAA87 [0042BDB1] eb 64                                        jmp     short near ptr unk_42BE17 ; game-relative-target=0x004AAAED
