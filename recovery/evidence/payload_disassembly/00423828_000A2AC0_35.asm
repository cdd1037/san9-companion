; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00423828; baseline game VA=0x000A2AC0; size=53
; Relative branch annotations use the baseline game destination.
000A2AC0 [00423828] 51                                           push    ecx
000A2AC1 [00423829] b8 b0 fa 46 00                               mov     eax, 46FAB0h
000A2AC6 [0042382E] ff d0                                        call    eax
000A2AC8 [00423830] 59                                           pop     ecx
000A2AC9 [00423831] 83 7c 24 18 00                               cmp     dword ptr [esp+18h], 0
000A2ACE [00423836] 74 10                                        jz      short near ptr unk_423848 ; game-relative-target=0x000A2AE0
000A2AD0 [00423838] ff 74 24 40                                  push    dword ptr [esp+40h]
000A2AD4 [0042383C] b8 70 ef 46 00                               mov     eax, 46EF70h
000A2AD9 [00423841] ff d0                                        call    eax
000A2ADB [00423843] 83 04 24 36                                  add     dword ptr [esp], 36h ; '6'
000A2ADF [00423847] c3                                           retn
000A2AE0 [00423848] 85 ff                                        test    edi, edi
000A2AE2 [0042384A] 75 01                                        jnz     short near ptr unk_42384D ; game-relative-target=0x000A2AE5
000A2AE4 [0042384C] c3                                           retn
000A2AE5 [0042384D] ff 74 24 58                                  push    dword ptr [esp+58h]
000A2AE9 [00423851] b8 70 ef 46 00                               mov     eax, 46EF70h
000A2AEE [00423856] ff d0                                        call    eax
000A2AF0 [00423858] 83 04 24 1d                                  add     dword ptr [esp], 1Dh
000A2AF4 [0042385C] c3                                           retn
