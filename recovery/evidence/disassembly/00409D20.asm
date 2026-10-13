00409D20  83 ec 64                                      sub     esp, 64h
00409D23  56                                            push    esi
00409D24  8b f1                                         mov     esi, ecx
00409D26  8b 46 20                                      mov     eax, [esi+20h]
00409D29  50                                            push    eax; hWnd
00409D2A  ff 15 4c c3 41 00                             call    ds:IsIconic; USER32
00409D30  85 c0                                         test    eax, eax
00409D32  0f 84 92 00 00 00                             jz      loc_409DCA
00409D38  53                                            push    ebx
00409D39  57                                            push    edi
00409D3A  56                                            push    esi; struct CWnd *
00409D3B  8d 4c 24 20                                   lea     ecx, [esp+74h+var_54]; this
00409D3F  e8 b4 0a 01 00                                call    ??0CPaintDC@@QAE@PAVCWnd@@@Z; CPaintDC::CPaintDC(CWnd *)
00409D44  8b 7c 24 20                                   mov     edi, [esp+70h+hDC]
00409D48  8d 44 24 1c                                   lea     eax, [esp+70h+var_54]
00409D4C  8b 4e 20                                      mov     ecx, [esi+20h]
00409D4F  6a 00                                         push    0; lParam
00409D51  f7 d8                                         neg     eax
00409D53  1b c0                                         sbb     eax, eax
00409D55  23 c7                                         and     eax, edi
00409D57  50                                            push    eax; wParam
00409D58  6a 27                                         push    27h ; '''; Msg
00409D5A  51                                            push    ecx; hWnd
00409D5B  ff 15 64 c3 41 00                             call    ds:SendMessageA; USER32
00409D61  8b 3d 48 c3 41 00                             mov     edi, ds:GetSystemMetrics; USER32
00409D67  6a 0b                                         push    0Bh; nIndex
00409D69  ff d7                                         call    edi ; GetSystemMetrics; USER32
00409D6B  6a 0c                                         push    0Ch; nIndex
00409D6D  8b d8                                         mov     ebx, eax
00409D6F  ff d7                                         call    edi ; GetSystemMetrics; USER32
00409D71  8b f8                                         mov     edi, eax
00409D73  8b 46 20                                      mov     eax, [esi+20h]
00409D76  8d 54 24 0c                                   lea     edx, [esp+70h+Rect]
00409D7A  52                                            push    edx; lpRect
00409D7B  50                                            push    eax; hWnd
00409D7C  ff 15 44 c3 41 00                             call    ds:GetClientRect; USER32
00409D82  8b 8e 08 1e 00 00                             mov     ecx, [esi+1E08h]
00409D88  8b 44 24 18                                   mov     eax, [esp+70h+Rect.bottom]
00409D8C  51                                            push    ecx; hIcon
00409D8D  8b 4c 24 14                                   mov     ecx, [esp+74h+Rect.top]
00409D91  2b c1                                         sub     eax, ecx
00409D93  2b c7                                         sub     eax, edi
00409D95  40                                            inc     eax
00409D96  99                                            cdq
00409D97  2b c2                                         sub     eax, edx
00409D99  8b 54 24 10                                   mov     edx, [esp+74h+Rect.left]
00409D9D  d1 f8                                         sar     eax, 1
00409D9F  50                                            push    eax; Y
00409DA0  8b 44 24 1c                                   mov     eax, [esp+78h+Rect.right]
00409DA4  2b c2                                         sub     eax, edx
00409DA6  2b c3                                         sub     eax, ebx
00409DA8  40                                            inc     eax
00409DA9  99                                            cdq
00409DAA  2b c2                                         sub     eax, edx
00409DAC  8b 54 24 28                                   mov     edx, [esp+78h+hDC]
00409DB0  d1 f8                                         sar     eax, 1
00409DB2  50                                            push    eax; X
00409DB3  52                                            push    edx; hDC
00409DB4  ff 15 40 c3 41 00                             call    ds:DrawIcon; USER32
00409DBA  8d 4c 24 1c                                   lea     ecx, [esp+70h+var_54]; this
00409DBE  e8 2f 0a 01 00                                call    ??1CPaintDC@@UAE@XZ; CPaintDC::~CPaintDC(void)
00409DC3  5f                                            pop     edi
00409DC4  5b                                            pop     ebx
00409DC5  5e                                            pop     esi
00409DC6  83 c4 64                                      add     esp, 64h
00409DC9  c3                                            retn
00409DCA  8b ce                                         mov     ecx, esi; this
00409DCC  e8 1b 0a 01 00                                call    ?Default@CWnd@@IAEJXZ; CWnd::Default(void)
00409DD1  5e                                            pop     esi
00409DD2  83 c4 64                                      add     esp, 64h
00409DD5  c3                                            retn
