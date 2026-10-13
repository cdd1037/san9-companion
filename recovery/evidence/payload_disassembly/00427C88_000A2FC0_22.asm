; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00427C88; baseline game VA=0x000A2FC0; size=34
; Relative branch annotations use the baseline game destination.
000A2FC0 [00427C88] 81 ff e8 03 00 00                            cmp     edi, 3E8h
000A2FC6 [00427C8E] 7c 14                                        jl      short near ptr unk_427CA4 ; game-relative-target=0x000A2FDC
000A2FC8 [00427C90] 66 3b 7c 24 34                               cmp     di, [esp+34h]
000A2FCD [00427C95] 74 0d                                        jz      short near ptr unk_427CA4 ; game-relative-target=0x000A2FDC
000A2FCF [00427C97] 80 fa 0a                                     cmp     dl, 0Ah
000A2FD2 [00427C9A] 7d 08                                        jge     short near ptr unk_427CA4 ; game-relative-target=0x000A2FDC
000A2FD4 [00427C9C] c7 44 24 08 24 9a 61 00                      mov     dword ptr [esp+8], 619A24h
000A2FDC [00427CA4] 68 c0 f6 5c 00                               push    5CF6C0h
000A2FE1 [00427CA9] c3                                           retn
