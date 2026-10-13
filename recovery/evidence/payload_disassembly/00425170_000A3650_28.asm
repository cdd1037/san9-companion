; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00425170; baseline game VA=0x000A3650; size=40
; Relative branch annotations use the baseline game destination.
000A3650 [00425170] 8b 89 b8 00 00 00                            mov     ecx, [ecx+0B8h]
000A3656 [00425176] 0f b6 41 04                                  movzx   eax, byte ptr [ecx+4]
000A365A [0042517A] 69 c0 ec 03 00 00                            imul    eax, 3ECh
000A3660 [00425180] 03 05 68 55 54 01                            add     eax, ds:1545568h
000A3666 [00425186] 8b 4c 24 04                                  mov     ecx, [esp+4]
000A366A [0042518A] 50                                           push    eax
000A366B [0042518B] 8b 01                                        mov     eax, [ecx]
000A366D [0042518D] ff 50 0c                                     call    dword ptr [eax+0Ch]
000A3670 [00425190] 40                                           inc     eax
000A3671 [00425191] 59                                           pop     ecx
000A3672 [00425192] 8b 04 81                                     mov     eax, [ecx+eax*4]
000A3675 [00425195] c2 04 00                                     retn    4
