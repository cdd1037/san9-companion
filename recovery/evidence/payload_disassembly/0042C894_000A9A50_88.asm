; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042C894; baseline game VA=0x000A9A50; size=136
; Relative branch annotations use the baseline game destination.
000A9A50 [0042C894] 55                                           push    ebp
000A9A51 [0042C895] 56                                           push    esi
000A9A52 [0042C896] 53                                           push    ebx
000A9A53 [0042C897] 8b b6 98 02 00 00                            mov     esi, [esi+298h]
000A9A59 [0042C89D] 8d 5c 24 10                                  lea     ebx, [esp+10h]
000A9A5D [0042C8A1] 8b e8                                        mov     ebp, eax
000A9A5F [0042C8A3] 68 5a 04 00 00                               push    45Ah
000A9A64 [0042C8A8] 8b ce                                        mov     ecx, esi
000A9A66 [0042C8AA] b8 d0 71 5b 00                               mov     eax, 5B71D0h
000A9A6B [0042C8AF] ff d0                                        call    eax
000A9A6D [0042C8B1] 8b 0d 40 11 66 00                            mov     ecx, ds:661140h
000A9A73 [0042C8B7] 89 48 04                                     mov     [eax+4], ecx
000A9A76 [0042C8BA] 8b 45 10                                     mov     eax, [ebp+10h]
000A9A79 [0042C8BD] 05 c0 02 00 00                               add     eax, 2C0h
000A9A7E [0042C8C2] 6a 00                                        push    0
000A9A80 [0042C8C4] 50                                           push    eax
000A9A81 [0042C8C5] ba d0 6e 56 00                               mov     edx, 566ED0h
000A9A86 [0042C8CA] ff d2                                        call    edx
000A9A88 [0042C8CC] 6a 02                                        push    2
000A9A8A [0042C8CE] 50                                           push    eax
000A9A8B [0042C8CF] 8d 8e ec 05 00 00                            lea     ecx, [esi+5ECh]
000A9A91 [0042C8D5] b8 90 78 42 00                               mov     eax, 427890h
000A9A96 [0042C8DA] ff d0                                        call    eax
000A9A98 [0042C8DC] 8b cb                                        mov     ecx, ebx
000A9A9A [0042C8DE] b8 40 e3 5c 00                               mov     eax, 5CE340h
000A9A9F [0042C8E3] ff d0                                        call    eax
000A9AA1 [0042C8E5] ff 77 04                                     push    dword ptr [edi+4]
000A9AA4 [0042C8E8] ff 37                                        push    dword ptr [edi]
000A9AA6 [0042C8EA] 68 c4 63 60 00                               push    6063C4h
000A9AAB [0042C8EF] 50                                           push    eax
000A9AAC [0042C8F0] b8 c0 f6 5c 00                               mov     eax, 5CF6C0h
000A9AB1 [0042C8F5] ff d0                                        call    eax
000A9AB3 [0042C8F7] 83 c4 18                                     add     esp, 18h
000A9AB6 [0042C8FA] 6a 02                                        push    2
000A9AB8 [0042C8FC] ff 33                                        push    dword ptr [ebx]
000A9ABA [0042C8FE] 8d 8e 98 05 00 00                            lea     ecx, [esi+598h]
000A9AC0 [0042C904] b8 90 78 42 00                               mov     eax, 427890h
000A9AC5 [0042C909] ff d0                                        call    eax
000A9AC7 [0042C90B] 8b cb                                        mov     ecx, ebx
000A9AC9 [0042C90D] b8 50 e4 5c 00                               mov     eax, 5CE450h
000A9ACE [0042C912] ff d0                                        call    eax
000A9AD0 [0042C914] 8b c5                                        mov     eax, ebp
000A9AD2 [0042C916] 5b                                           pop     ebx
000A9AD3 [0042C917] 5e                                           pop     esi
000A9AD4 [0042C918] 5d                                           pop     ebp
000A9AD5 [0042C919] c2 04 00                                     retn    4
