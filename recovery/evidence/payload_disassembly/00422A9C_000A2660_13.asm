; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00422A9C; baseline game VA=0x000A2660; size=19
; Relative branch annotations use the baseline game destination.
000A2660 [00422A9C] 8b 01                                        mov     eax, [ecx]
000A2662 [00422A9E] ff 50 3c                                     call    dword ptr [eax+3Ch]
000A2665 [00422AA1] 85 c0                                        test    eax, eax
000A2667 [00422AA3] 74 01                                        jz      short near ptr unk_422AA6 ; game-relative-target=0x000A266A
000A2669 [00422AA5] c3                                           retn
000A266A [00422AA6] 8b 4e 40                                     mov     ecx, [esi+40h]
000A266D [00422AA9] 8b 01                                        mov     eax, [ecx]
000A266F [00422AAB] ff 50 3c                                     call    dword ptr [eax+3Ch]
000A2672 [00422AAE] c3                                           retn
