; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00428954; baseline game VA=0x000A4E40; size=96
; Relative branch annotations use the baseline game destination.
000A4E40 [00428954] 99                                           cdq
000A4E41 [00428955] f7 ee                                        imul    esi
000A4E43 [00428957] f7 f9                                        idiv    ecx
000A4E45 [00428959] 8d 49 00                                     lea     ecx, [ecx+0]
000A4E48 [0042895C] 8b 4c 24 28                                  mov     ecx, [esp+28h]
000A4E4C [00428960] ba 54 4e 0a 00                               mov     edx, 0A4E54h
000A4E51 [00428965] ff d2                                        call    edx
000A4E53 [00428967] c3                                           retn
000A4E54 [00428968] 57                                           push    edi
000A4E55 [00428969] 8b f8                                        mov     edi, eax
000A4E57 [0042896B] 8b 01                                        mov     eax, [ecx]
000A4E59 [0042896D] ff 50 30                                     call    dword ptr [eax+30h]
000A4E5C [00428970] 85 c0                                        test    eax, eax
000A4E5E [00428972] 74 3a                                        jz      short near ptr unk_4289AE ; game-relative-target=0x000A4E9A
000A4E60 [00428974] f6 40 34 01                                  test    byte ptr [eax+34h], 1
000A4E64 [00428978] 74 36                                        jz      short near ptr unk_4289B0 ; game-relative-target=0x000A4E9C
000A4E66 [0042897A] 8b c8                                        mov     ecx, eax
000A4E68 [0042897C] b8 b0 4e 0a 00                               mov     eax, 0A4EB0h
000A4E6D [00428981] ff d0                                        call    eax
000A4E6F [00428983] c1 e8 0e                                     shr     eax, 0Eh
000A4E72 [00428986] 83 f8 7f                                     cmp     eax, 7Fh
000A4E75 [00428989] 7e 02                                        jle     short near ptr unk_42898D ; game-relative-target=0x000A4E79
000A4E77 [0042898B] b0 7f                                        mov     al, 7Fh
000A4E79 [0042898D] 8b d7                                        mov     edx, edi
000A4E7B [0042898F] c1 ea 02                                     shr     edx, 2
000A4E7E [00428992] 3a 05 c6 64 0a 00                            cmp     al, ds:0A64C6h
000A4E84 [00428998] 7c 16                                        jl      short near ptr unk_4289B0 ; game-relative-target=0x000A4E9C
000A4E86 [0042899A] 2b fa                                        sub     edi, edx
000A4E88 [0042899C] 3a 05 c7 64 0a 00                            cmp     al, ds:0A64C7h
000A4E8E [004289A2] 7c 0c                                        jl      short near ptr unk_4289B0 ; game-relative-target=0x000A4E9C
000A4E90 [004289A4] 2b fa                                        sub     edi, edx
000A4E92 [004289A6] 3a 05 c8 64 0a 00                            cmp     al, ds:0A64C8h
000A4E98 [004289AC] 7c 02                                        jl      short near ptr unk_4289B0 ; game-relative-target=0x000A4E9C
000A4E9A [004289AE] d1 ef                                        shr     edi, 1
000A4E9C [004289B0] 8b c7                                        mov     eax, edi
000A4E9E [004289B2] 5f                                           pop     edi
000A4E9F [004289B3] c3                                           retn
