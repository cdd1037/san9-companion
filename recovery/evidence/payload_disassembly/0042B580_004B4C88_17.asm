; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042B580; baseline game VA=0x004B4C88; size=23
; Relative branch annotations use the baseline game destination.
004B4C88 [0042B580] 8b 72 0c                                     mov     esi, [edx+0Ch]
004B4C8B [0042B583] 3b 75 00                                     cmp     esi, [ebp+0]
004B4C8E [0042B586] 76 04                                        jbe     short near ptr unk_42B58C ; game-relative-target=0x004B4C94
004B4C90 [0042B588] 89 75 00                                     mov     [ebp+0], esi
004B4C93 [0042B58B] 90                                           nop
004B4C94 [0042B58C] c7 84 24 34 04 00 00 ff ff ff ff             mov     dword ptr [esp+434h], 0FFFFFFFFh
