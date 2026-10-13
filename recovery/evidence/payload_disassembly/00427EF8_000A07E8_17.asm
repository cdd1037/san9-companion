; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00427EF8; baseline game VA=0x000A07E8; size=23
; Relative branch annotations use the baseline game destination.
000A07E8 [00427EF8] 0f b7 44 08 0c                               movzx   eax, word ptr [eax+ecx+0Ch]
000A07ED [00427EFD] 85 c0                                        test    eax, eax
000A07EF [00427EFF] 75 02                                        jnz     short near ptr unk_427F03 ; game-relative-target=0x000A07F3
000A07F1 [00427F01] 48                                           dec     eax
000A07F2 [00427F02] c3                                           retn
000A07F3 [00427F03] 05 23 01 00 00                               add     eax, 123h
000A07F8 [00427F08] 85 c0                                        test    eax, eax
000A07FA [00427F0A] 7d 02                                        jge     short near ptr unk_427F0E ; game-relative-target=0x000A07FE
000A07FC [00427F0C] f7 d8                                        neg     eax
000A07FE [00427F0E] c3                                           retn
