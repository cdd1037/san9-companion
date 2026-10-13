; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00424468; baseline game VA=0x000A17D0; size=41
; Relative branch annotations use the baseline game destination.
000A17D0 [00424468] 8b 44 24 18                                  mov     eax, [esp+18h]
000A17D4 [0042446C] 8b 4c 24 1c                                  mov     ecx, [esp+1Ch]
000A17D8 [00424470] 89 0d f7 fa 43 00                            mov     ds:43FAF7h, ecx
000A17DE [00424476] 6a 0c                                        push    0Ch
000A17E0 [00424478] 6a 0b                                        push    0Bh
000A17E2 [0042447A] 51                                           push    ecx
000A17E3 [0042447B] 50                                           push    eax
000A17E4 [0042447C] b8 80 a6 44 00                               mov     eax, 44A680h
000A17E9 [00424481] ff d0                                        call    eax
000A17EB [00424483] 83 c4 10                                     add     esp, 10h
000A17EE [00424486] 83 e8 14                                     sub     eax, 14h
000A17F1 [00424489] 6b c0 02                                     imul    eax, 2
000A17F4 [0042448C] 83 04 24 04                                  add     dword ptr [esp], 4
000A17F8 [00424490] c3                                           retn
