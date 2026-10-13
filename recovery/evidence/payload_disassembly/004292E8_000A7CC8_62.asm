; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004292E8; baseline game VA=0x000A7CC8; size=98
; Relative branch annotations use the baseline game destination.
000A7CC8 [004292E8] 57                                           push    edi
000A7CC9 [004292E9] 51                                           push    ecx
000A7CCA [004292EA] 8b ce                                        mov     ecx, esi
000A7CCC [004292EC] b8 d0 fd 57 00                               mov     eax, 57FDD0h
000A7CD1 [004292F1] ff d0                                        call    eax
000A7CD3 [004292F3] 33 ff                                        xor     edi, edi
000A7CD5 [004292F5] ba 10 30 44 00                               mov     edx, 443010h
000A7CDA [004292FA] 83 f8 05                                     cmp     eax, 5
000A7CDD [004292FD] 7e 06                                        jle     short near ptr unk_429305 ; game-relative-target=0x000A7CE5
000A7CDF [004292FF] 47                                           inc     edi
000A7CE0 [00429300] ba 70 31 44 00                               mov     edx, 443170h
000A7CE5 [00429305] 8b 8b b8 00 00 00                            mov     ecx, [ebx+0B8h]
000A7CEB [0042930B] ff d2                                        call    edx
000A7CED [0042930D] 8d 4f 0c                                     lea     ecx, [edi+0Ch]
000A7CF0 [00429310] d3 e8                                        shr     eax, cl
000A7CF2 [00429312] 83 f8 7f                                     cmp     eax, 7Fh
000A7CF5 [00429315] 7e 02                                        jle     short near ptr unk_429319 ; game-relative-target=0x000A7CF9
000A7CF7 [00429317] b0 7f                                        mov     al, 7Fh
000A7CF9 [00429319] 33 d2                                        xor     edx, edx
000A7CFB [0042931B] 8d 8c 7f c0 64 0a 00                         lea     ecx, [edi+edi*2+0A64C0h]
000A7D02 [00429322] 3a 04 11                                     cmp     al, [ecx+edx]
000A7D05 [00429325] 7c 06                                        jl      short near ptr unk_42932D ; game-relative-target=0x000A7D0D
000A7D07 [00429327] 42                                           inc     edx
000A7D08 [00429328] 83 fa 03                                     cmp     edx, 3
000A7D0B [0042932B] 7c f5                                        jl      short near ptr unk_429322 ; game-relative-target=0x000A7D02
000A7D0D [0042932D] 83 ea 04                                     sub     edx, 4
000A7D10 [00429330] f7 da                                        neg     edx
000A7D12 [00429332] 69 d2 a0 86 01 00                            imul    edx, 186A0h
000A7D18 [00429338] 8b cf                                        mov     ecx, edi
000A7D1A [0042933A] d3 ea                                        shr     edx, cl
000A7D1C [0042933C] 59                                           pop     ecx
000A7D1D [0042933D] 3b d1                                        cmp     edx, ecx
000A7D1F [0042933F] 7d 02                                        jge     short near ptr unk_429343 ; game-relative-target=0x000A7D23
000A7D21 [00429341] 8b ca                                        mov     ecx, edx
000A7D23 [00429343] b8 67 66 66 66                               mov     eax, 66666667h
000A7D28 [00429348] 5f                                           pop     edi
000A7D29 [00429349] c3                                           retn
