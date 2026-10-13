; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004238C0; baseline game VA=0x000A3BD0; size=38
; Relative branch annotations use the baseline game destination.
000A3BD0 [004238C0] 85 ff                                        test    edi, edi
000A3BD2 [004238C2] 74 09                                        jz      short near ptr unk_4238CD ; game-relative-target=0x000A3BDD
000A3BD4 [004238C4] 8a 5f 04                                     mov     bl, [edi+4]
000A3BD7 [004238C7] 8a 9b b0 31 0a 00                            mov     bl, [ebx+0A31B0h]
000A3BDD [004238CD] 33 c0                                        xor     eax, eax
000A3BDF [004238CF] 85 ed                                        test    ebp, ebp
000A3BE1 [004238D1] 74 09                                        jz      short near ptr unk_4238DC ; game-relative-target=0x000A3BEC
000A3BE3 [004238D3] 8a 45 04                                     mov     al, [ebp+4]
000A3BE6 [004238D6] 8a 80 b0 31 0a 00                            mov     al, [eax+0A31B0h]
000A3BEC [004238DC] 8b f8                                        mov     edi, eax
000A3BEE [004238DE] 68 20 af 48 00                               push    48AF20h
000A3BF3 [004238E3] c2 08 00                                     retn    8
