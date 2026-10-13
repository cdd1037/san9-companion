; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00420A48; baseline game VA=0x000A0A80; size=54
; Relative branch annotations use the baseline game destination.
000A0A80 [00420A48] 8b 54 24 04                                  mov     edx, [esp+4]
000A0A84 [00420A4C] 8b 42 10                                     mov     eax, [edx+10h]
000A0A87 [00420A4F] 03 42 18                                     add     eax, [edx+18h]
000A0A8A [00420A52] 2b 41 10                                     sub     eax, [ecx+10h]
000A0A8D [00420A55] 2b 41 18                                     sub     eax, [ecx+18h]
000A0A90 [00420A58] d1 f8                                        sar     eax, 1
000A0A92 [00420A5A] 0f af c0                                     imul    eax, eax
000A0A95 [00420A5D] 50                                           push    eax
000A0A96 [00420A5E] 8b 42 14                                     mov     eax, [edx+14h]
000A0A99 [00420A61] 03 42 1c                                     add     eax, [edx+1Ch]
000A0A9C [00420A64] 2b 41 14                                     sub     eax, [ecx+14h]
000A0A9F [00420A67] 2b 41 1c                                     sub     eax, [ecx+1Ch]
000A0AA2 [00420A6A] d1 f8                                        sar     eax, 1
000A0AA4 [00420A6C] 0f af c0                                     imul    eax, eax
000A0AA7 [00420A6F] 01 04 24                                     add     [esp], eax
000A0AAA [00420A72] ff 15 1c f3 5f 00                            call    dword ptr ds:5FF31Ch
000A0AB0 [00420A78] 83 c4 04                                     add     esp, 4
000A0AB3 [00420A7B] c2 04 00                                     retn    4
