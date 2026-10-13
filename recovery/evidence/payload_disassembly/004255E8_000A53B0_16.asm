; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004255E8; baseline game VA=0x000A53B0; size=22
; Relative branch annotations use the baseline game destination.
000A53B0 [004255E8] 8b ca                                        mov     ecx, edx
000A53B2 [004255EA] 8b 01                                        mov     eax, [ecx]
000A53B4 [004255EC] ff 50 3c                                     call    dword ptr [eax+3Ch]
000A53B7 [004255EF] 85 c0                                        test    eax, eax
000A53B9 [004255F1] 74 03                                        jz      short near ptr unk_4255F6 ; game-relative-target=0x000A53BE
000A53BB [004255F3] c2 04 00                                     retn    4
000A53BE [004255F6] 8b cf                                        mov     ecx, edi
000A53C0 [004255F8] 68 50 ee 46 00                               push    46EE50h
000A53C5 [004255FD] c3                                           retn
