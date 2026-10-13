; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004270C8; baseline game VA=0x000A4EE0; size=28
; Relative branch annotations use the baseline game destination.
000A4EE0 [004270C8] 8b 01                                        mov     eax, [ecx]
000A4EE2 [004270CA] ff 50 0c                                     call    dword ptr [eax+0Ch]
000A4EE5 [004270CD] 69 c0 80 00 00 00                            imul    eax, 80h
000A4EEB [004270D3] 05 e4 5e 54 01                               add     eax, 1545EE4h
000A4EF0 [004270D8] 33 c9                                        xor     ecx, ecx
000A4EF2 [004270DA] f6 40 20 80                                  test    byte ptr [eax+20h], 80h
000A4EF6 [004270DE] 0f 94 c1                                     setz    cl
000A4EF9 [004270E1] 8b c1                                        mov     eax, ecx
000A4EFB [004270E3] c3                                           retn
