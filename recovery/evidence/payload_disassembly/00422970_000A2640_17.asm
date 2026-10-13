; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00422970; baseline game VA=0x000A2640; size=23
; Relative branch annotations use the baseline game destination.
000A2640 [00422970] 8b 03                                        mov     eax, [ebx]
000A2642 [00422972] 8b cb                                        mov     ecx, ebx
000A2644 [00422974] ff 50 64                                     call    dword ptr [eax+64h]
000A2647 [00422977] 8b 40 38                                     mov     eax, [eax+38h]
000A264A [0042297A] 83 e8 50                                     sub     eax, 50h ; 'P'
000A264D [0042297D] 01 44 24 04                                  add     [esp+4], eax
000A2651 [00422981] ff 25 f0 f2 5f 00                            jmp     dword ptr ds:5FF2F0h
