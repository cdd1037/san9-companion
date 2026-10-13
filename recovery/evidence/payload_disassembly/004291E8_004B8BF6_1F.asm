; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004291E8; baseline game VA=0x004B8BF6; size=31
; Relative branch annotations use the baseline game destination.
004B8BF6 [004291E8] 85 ed                                        test    ebp, ebp
004B8BF8 [004291EA] 74 07                                        jz      short near ptr unk_4291F3 ; game-relative-target=0x004B8C01
004B8BFA [004291EC] bf 17 00 00 00                               mov     edi, 17h
004B8BFF [004291F1] eb 14                                        jmp     short near ptr unk_429207 ; game-relative-target=0x004B8C15
004B8C01 [004291F3] 85 db                                        test    ebx, ebx
004B8C03 [004291F5] 74 07                                        jz      short near ptr unk_4291FE ; game-relative-target=0x004B8C0C
004B8C05 [004291F7] bf 16 00 00 00                               mov     edi, 16h
004B8C0A [004291FC] eb 09                                        jmp     short near ptr unk_429207 ; game-relative-target=0x004B8C15
004B8C0C [004291FE] 85 f6                                        test    esi, esi
004B8C0E [00429200] 74 05                                        jz      short near ptr unk_429207 ; game-relative-target=0x004B8C15
004B8C10 [00429202] bf 15 00 00 00                               mov     edi, 15h
