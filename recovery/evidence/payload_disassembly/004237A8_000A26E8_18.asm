; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004237A8; baseline game VA=0x000A26E8; size=24
; Relative branch annotations use the baseline game destination.
000A26E8 [004237A8] 33 c0                                        xor     eax, eax
000A26EA [004237AA] 39 46 48                                     cmp     [esi+48h], eax
000A26ED [004237AD] 74 10                                        jz      short near ptr unk_4237BF ; game-relative-target=0x000A26FF
000A26EF [004237AF] 8b c6                                        mov     eax, esi
000A26F1 [004237B1] 39 b4 24 ec 00 00 00                         cmp     [esp+0ECh], esi
000A26F8 [004237B8] 75 05                                        jnz     short near ptr unk_4237BF ; game-relative-target=0x000A26FF
000A26FA [004237BA] 68 70 d0 45 00                               push    45D070h
000A26FF [004237BF] c3                                           retn
