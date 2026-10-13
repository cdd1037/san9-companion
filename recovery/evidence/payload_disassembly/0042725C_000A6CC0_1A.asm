; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042725C; baseline game VA=0x000A6CC0; size=26
; Relative branch annotations use the baseline game destination.
000A6CC0 [0042725C] 51                                           push    ecx
000A6CC1 [0042725D] 8b 4c 24 08                                  mov     ecx, [esp+8]
000A6CC5 [00427261] b8 60 63 0a 00                               mov     eax, 0A6360h
000A6CCA [00427266] ff d0                                        call    eax
000A6CCC [00427268] 85 c0                                        test    eax, eax
000A6CCE [0042726A] 59                                           pop     ecx
000A6CCF [0042726B] 74 06                                        jz      short near ptr unk_427273 ; game-relative-target=0x000A6CD7
000A6CD1 [0042726D] 68 60 d0 52 00                               push    52D060h
000A6CD6 [00427272] c3                                           retn
000A6CD7 [00427273] c2 0c 00                                     retn    0Ch
