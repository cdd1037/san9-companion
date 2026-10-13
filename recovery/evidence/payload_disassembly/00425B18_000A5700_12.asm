; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00425B18; baseline game VA=0x000A5700; size=18
; Relative branch annotations use the baseline game destination.
000A5700 [00425B18] 8b ce                                        mov     ecx, esi
000A5702 [00425B1A] b8 b1 dd 45 00                               mov     eax, 45DDB1h
000A5707 [00425B1F] ff d0                                        call    eax
000A5709 [00425B21] 80 3c 24 54                                  cmp     byte ptr [esp], 54h ; 'T'
000A570D [00425B25] 74 02                                        jz      short near ptr unk_425B29 ; game-relative-target=0x000A5711
000A570F [00425B27] 8b c8                                        mov     ecx, eax
000A5711 [00425B29] c3                                           retn
