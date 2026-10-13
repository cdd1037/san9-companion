00402F10  6a ff                                         push    0FFFFFFFFh
00402F12  68 d0 ad 41 00                                push    offset SEH_402F10
00402F17  64 a1 00 00 00 00                             mov     eax, large fs:0
00402F1D  50                                            push    eax
00402F1E  64 89 25 00 00 00 00                          mov     large fs:0, esp
00402F25  83 ec 08                                      sub     esp, 8
00402F28  56                                            push    esi
00402F29  57                                            push    edi
00402F2A  8b f9                                         mov     edi, ecx
00402F2C  89 7c 24 08                                   mov     [esp+1Ch+var_14], edi
00402F30  8d b7 c0 01 00 00                             lea     esi, [edi+1C0h]
00402F36  c7 44 24 18 00 00 00 00                       mov     [esp+1Ch+var_4], 0
00402F3E  89 74 24 0c                                   mov     [esp+1Ch+var_10], esi
00402F42  c7 06 90 c9 41 00                             mov     dword ptr [esi], offset off_41C990
00402F48  8b ce                                         mov     ecx, esi; this
00402F4A  c6 44 24 18 01                                mov     byte ptr [esp+1Ch+var_4], 1
00402F4F  e8 48 77 01 00                                call    ?DestroyMenu@CMenu@@QAEHXZ; CMenu::DestroyMenu(void)
00402F54  8b cf                                         mov     ecx, edi; this
00402F56  c7 06 70 c5 41 00                             mov     dword ptr [esi], offset off_41C570
00402F5C  c7 44 24 18 ff ff ff ff                       mov     [esp+1Ch+var_4], 0FFFFFFFFh
00402F64  e8 6d 76 01 00                                call    ??1CDialog@@UAE@XZ; CDialog::~CDialog(void)
00402F69  8b 4c 24 10                                   mov     ecx, [esp+1Ch+var_C]
00402F6D  5f                                            pop     edi
00402F6E  5e                                            pop     esi
00402F6F  64 89 0d 00 00 00 00                          mov     large fs:0, ecx
00402F76  83 c4 14                                      add     esp, 14h
00402F79  c3                                            retn
0041ADC0  8b 4d ec                                      mov     ecx, [ebp-14h]; MFC 3.1-14.0 32bit
0041ADC3  e9 0e f8 ff ff                                jmp     ??1CDialog@@UAE@XZ; CDialog::~CDialog(void)
0041ADC8  8b 4d f0                                      mov     ecx, [ebp-10h]
0041ADCB  e9 d0 6b fe ff                                jmp     sub_4019A0
0041ADD0  b8 70 d5 41 00                                mov     eax, offset stru_41D570
0041ADD5  e9 42 fa ff ff                                jmp     __CxxFrameHandler
