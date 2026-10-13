; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042B718; baseline game VA=0x000A0AC0; size=79
; Relative branch annotations use the baseline game destination.
000A0AC0 [0042B718] 5d                                           pop     ebp
000A0AC1 [0042B719] b8 50 c6 49 00                               mov     eax, 49C650h
000A0AC6 [0042B71E] ff d0                                        call    eax
000A0AC8 [0042B720] 55                                           push    ebp
000A0AC9 [0042B721] 8b 7e 40                                     mov     edi, [esi+40h]
000A0ACC [0042B724] f6 47 22 30                                  test    byte ptr [edi+22h], 30h ; '0'
000A0AD0 [0042B728] 75 3c                                        jnz     short near ptr unk_42B766 ; game-relative-target=0x000A0B0E
000A0AD2 [0042B72A] 8b 48 48                                     mov     ecx, [eax+48h]
000A0AD5 [0042B72D] c7 00 48 7e 60 00                            mov     dword ptr [eax], 607E48h
000A0ADB [0042B733] 8b 50 54                                     mov     edx, [eax+54h]
000A0ADE [0042B736] 89 97 80 00 00 00                            mov     [edi+80h], edx
000A0AE4 [0042B73C] 33 d2                                        xor     edx, edx
000A0AE6 [0042B73E] 89 50 44                                     mov     [eax+44h], edx
000A0AE9 [0042B741] 89 50 48                                     mov     [eax+48h], edx
000A0AEC [0042B744] 89 50 4c                                     mov     [eax+4Ch], edx
000A0AEF [0042B747] 89 50 50                                     mov     [eax+50h], edx
000A0AF2 [0042B74A] 80 67 23 fd                                  and     byte ptr [edi+23h], 0FDh
000A0AF6 [0042B74E] 8a 57 21                                     mov     dl, [edi+21h]
000A0AF9 [0042B751] 80 e2 20                                     and     dl, 20h ; ' '
000A0AFC [0042B754] c0 ea 05                                     shr     dl, 5
000A0AFF [0042B757] 3a d1                                        cmp     dl, cl
000A0B01 [0042B759] 74 0b                                        jz      short near ptr unk_42B766 ; game-relative-target=0x000A0B0E
000A0B03 [0042B75B] 80 4f 23 02                                  or      byte ptr [edi+23h], 2
000A0B07 [0042B75F] c7 47 6c a0 0e 50 01                         mov     dword ptr [edi+6Ch], 1500EA0h
000A0B0E [0042B766] c3                                           retn
