; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004270E4; baseline game VA=0x000A6F90; size=62
; Relative branch annotations use the baseline game destination.
000A6F90 [004270E4] 51                                           push    ecx
000A6F91 [004270E5] b8 d0 64 0a 00                               mov     eax, 0A64D0h
000A6F96 [004270EA] ff d0                                        call    eax
000A6F98 [004270EC] 85 c0                                        test    eax, eax
000A6F9A [004270EE] 59                                           pop     ecx
000A6F9B [004270EF] 74 2b                                        jz      short near ptr unk_42711C ; game-relative-target=0x000A6FC8
000A6F9D [004270F1] 51                                           push    ecx
000A6F9E [004270F2] 50                                           push    eax
000A6F9F [004270F3] b8 40 57 43 00                               mov     eax, 435740h
000A6FA4 [004270F8] ff d0                                        call    eax
000A6FA6 [004270FA] 85 c0                                        test    eax, eax
000A6FA8 [004270FC] 59                                           pop     ecx
000A6FA9 [004270FD] 75 1d                                        jnz     short near ptr unk_42711C ; game-relative-target=0x000A6FC8
000A6FAB [004270FF] 8b 01                                        mov     eax, [ecx]
000A6FAD [00427101] ff 50 0c                                     call    dword ptr [eax+0Ch]
000A6FB0 [00427104] 69 c0 80 00 00 00                            imul    eax, 80h
000A6FB6 [0042710A] 05 e4 5e 54 01                               add     eax, 1545EE4h
000A6FBB [0042710F] 8b 40 7c                                     mov     eax, [eax+7Ch]
000A6FBE [00427112] 8b 4c 24 04                                  mov     ecx, [esp+4]
000A6FC2 [00427116] 89 41 0c                                     mov     [ecx+0Ch], eax
000A6FC5 [00427119] c2 0c 00                                     retn    0Ch
000A6FC8 [0042711C] 68 60 6d 43 00                               push    436D60h
000A6FCD [00427121] c3                                           retn
