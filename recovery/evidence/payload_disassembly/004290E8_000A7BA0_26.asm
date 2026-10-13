; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004290E8; baseline game VA=0x000A7BA0; size=38
; Relative branch annotations use the baseline game destination.
000A7BA0 [004290E8] ff b1 b8 11 00 00                            push    dword ptr [ecx+11B8h]
000A7BA6 [004290EE] ff b1 b4 11 00 00                            push    dword ptr [ecx+11B4h]
000A7BAC [004290F4] ff b1 b0 11 00 00                            push    dword ptr [ecx+11B0h]
000A7BB2 [004290FA] b8 70 f5 48 00                               mov     eax, 48F570h
000A7BB7 [004290FF] ff d0                                        call    eax
000A7BB9 [00429101] 83 c4 0c                                     add     esp, 0Ch
000A7BBC [00429104] 89 44 24 30                                  mov     [esp+30h], eax
000A7BC0 [00429108] 68 90 b7 4c 00                               push    4CB790h
000A7BC5 [0042910D] c3                                           retn
