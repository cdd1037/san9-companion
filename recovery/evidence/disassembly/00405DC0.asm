00405DC0  64 a1 00 00 00 00                             mov     eax, large fs:0
00405DC6  6a ff                                         push    0FFFFFFFFh
00405DC8  68 36 b1 41 00                                push    offset SEH_405DC0
00405DCD  50                                            push    eax
00405DCE  b8 0c 1e 00 00                                mov     eax, 1E0Ch
00405DD3  64 89 25 00 00 00 00                          mov     large fs:0, esp
00405DDA  e8 71 4a 01 00                                call    __alloca_probe
00405DDF  56                                            push    esi
00405DE0  57                                            push    edi
00405DE1  8b f1                                         mov     esi, ecx
00405DE3  e8 f2 49 01 00                                call    ?Enable3dControls@CWinApp@@IAEHXZ; CWinApp::Enable3dControls(void)
00405DE8  68 00 f8 41 00                                push    offset WindowName; lpWindowName
00405DED  6a 00                                         push    0; lpClassName
00405DEF  ff 15 30 c3 41 00                             call    ds:FindWindowA; USER32
00405DF5  8b f8                                         mov     edi, eax
00405DF7  85 ff                                         test    edi, edi
00405DF9  74 12                                         jz      short loc_405E0D
00405DFB  57                                            push    edi; hWnd
00405DFC  ff 15 2c c3 41 00                             call    ds:SetForegroundWindow; USER32
00405E02  6a 09                                         push    9; nCmdShow
00405E04  57                                            push    edi; hWnd
00405E05  ff 15 28 c3 41 00                             call    ds:ShowWindow; USER32
00405E0B  eb 51                                         jmp     short loc_405E5E
00405E0D  6a 00                                         push    0; struct CWnd *
00405E0F  8d 4c 24 0c                                   lea     ecx, [esp+1E24h+var_1E18]
00405E13  e8 58 28 00 00                                call    sub_408670
00405E18  8d 44 24 08                                   lea     eax, [esp+1E20h+var_1E18]
00405E1C  8d 4c 24 08                                   lea     ecx, [esp+1E20h+var_1E18]; this
00405E20  c7 84 24 1c 1e 00 00 00 00 00 00              mov     [esp+1E20h+var_4], 0
00405E2B  89 46 20                                      mov     [esi+20h], eax
00405E2E  e8 ad 46 01 00                                call    ?DoModal@CDialog@@UAEHXZ; CDialog::DoModal(void)
00405E33  8d 8c 24 d0 1d 00 00                          lea     ecx, [esp+1E20h+var_50]; this
00405E3A  c7 84 24 1c 1e 00 00 01 00 00 00              mov     [esp+1E20h+var_4], 1
00405E45  e8 8a 49 01 00                                call    ??1CEdit@@UAE@XZ; CEdit::~CEdit(void)
00405E4A  8d 4c 24 08                                   lea     ecx, [esp+1E20h+var_1E18]; this
00405E4E  c7 84 24 1c 1e 00 00 ff ff ff ff              mov     [esp+1E20h+var_4], 0FFFFFFFFh
00405E59  e8 78 47 01 00                                call    ??1CDialog@@UAE@XZ; CDialog::~CDialog(void)
00405E5E  8b 8c 24 14 1e 00 00                          mov     ecx, [esp+1E20h+var_C]
00405E65  5f                                            pop     edi
00405E66  33 c0                                         xor     eax, eax
00405E68  5e                                            pop     esi
00405E69  64 89 0d 00 00 00 00                          mov     large fs:0, ecx
00405E70  81 c4 18 1e 00 00                             add     esp, 1E18h
00405E76  c3                                            retn
0041B120  8d 8d e8 e1 ff ff                             lea     ecx, [ebp-1E18h]; this
0041B126  e9 55 ad fe ff                                jmp     sub_405E80
0041B12B  8d 8d e8 e1 ff ff                             lea     ecx, [ebp-1E18h]; this
0041B131  e9 a0 f4 ff ff                                jmp     ??1CDialog@@UAE@XZ; CDialog::~CDialog(void)
0041B136  b8 80 d9 41 00                                mov     eax, offset stru_41D980
0041B13B  e9 dc f6 ff ff                                jmp     __CxxFrameHandler
