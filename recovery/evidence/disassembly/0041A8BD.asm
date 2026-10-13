0041A8BD  55                                            push    ebp
0041A8BE  8b ec                                         mov     ebp, esp
0041A8C0  6a ff                                         push    0FFFFFFFFh
0041A8C2  68 20 d1 41 00                                push    offset stru_41D120
0041A8C7  68 4a aa 41 00                                push    offset _except_handler3
0041A8CC  64 a1 00 00 00 00                             mov     eax, large fs:0
0041A8D2  50                                            push    eax
0041A8D3  64 89 25 00 00 00 00                          mov     large fs:0, esp
0041A8DA  83 ec 68                                      sub     esp, 68h
0041A8DD  53                                            push    ebx
0041A8DE  56                                            push    esi
0041A8DF  57                                            push    edi
0041A8E0  89 65 e8                                      mov     [ebp+ms_exc.old_esp], esp
0041A8E3  33 db                                         xor     ebx, ebx
0041A8E5  89 5d fc                                      mov     [ebp+ms_exc.registration.TryLevel], ebx
0041A8E8  6a 02                                         push    2; Type
0041A8EA  ff 15 c4 c2 41 00                             call    ds:__set_app_type; MSVCRT
0041A8F0  59                                            pop     ecx
0041A8F1  83 0d 20 f8 42 00 ff                          or      dword_42F820, 0FFFFFFFFh
0041A8F8  83 0d 24 f8 42 00 ff                          or      dword_42F824, 0FFFFFFFFh
0041A8FF  ff 15 c8 c2 41 00                             call    ds:__p__fmode; MSVCRT
0041A905  8b 0d 14 f8 42 00                             mov     ecx, dword_42F814
0041A90B  89 08                                         mov     [eax], ecx
0041A90D  ff 15 cc c2 41 00                             call    ds:__p__commode; MSVCRT
0041A913  8b 0d 10 f8 42 00                             mov     ecx, dword_42F810
0041A919  89 08                                         mov     [eax], ecx
0041A91B  a1 d0 c2 41 00                                mov     eax, ds:_adjust_fdiv; MSVCRT
0041A920  8b 00                                         mov     eax, [eax]
0041A922  a3 1c f8 42 00                                mov     dword_42F81C, eax
0041A927  e8 1d 01 00 00                                call    nullsub_1
0041A92C  39 1d 40 ef 42 00                             cmp     dword_42EF40, ebx
0041A932  75 0c                                         jnz     short loc_41A940
0041A934  68 46 aa 41 00                                push    offset UserMathErrorFunction; UserMathErrorFunction
0041A939  ff 15 d4 c2 41 00                             call    ds:__setusermatherr; MSVCRT
0041A93F  59                                            pop     ecx
0041A940  e8 ef 00 00 00                                call    __setdefaultprecision
0041A945  68 08 f5 41 00                                push    offset Last; Last
0041A94A  68 04 f5 41 00                                push    offset First; First
0041A94F  e8 da 00 00 00                                call    _initterm
0041A954  a1 0c f8 42 00                                mov     eax, dword_42F80C
0041A959  89 45 94                                      mov     [ebp+var_6C], eax
0041A95C  8d 45 94                                      lea     eax, [ebp+var_6C]
0041A95F  50                                            push    eax
0041A960  ff 35 08 f8 42 00                             push    dword_42F808
0041A966  8d 45 9c                                      lea     eax, [ebp+var_64]
0041A969  50                                            push    eax
0041A96A  8d 45 90                                      lea     eax, [ebp+var_70]
0041A96D  50                                            push    eax
0041A96E  8d 45 a0                                      lea     eax, [ebp+var_60]
0041A971  50                                            push    eax
0041A972  ff 15 dc c2 41 00                             call    ds:__getmainargs; MSVCRT
0041A978  68 00 f5 41 00                                push    offset dword_41F500; Last
0041A97D  68 00 f0 41 00                                push    offset dword_41F000; First
0041A982  e8 a7 00 00 00                                call    _initterm
0041A987  83 c4 24                                      add     esp, 24h
0041A98A  a1 e0 c2 41 00                                mov     eax, ds:_acmdln; MSVCRT
0041A98F  8b 30                                         mov     esi, [eax]
0041A991  89 75 8c                                      mov     [ebp+var_74], esi
0041A994  80 3e 22                                      cmp     byte ptr [esi], 22h ; '"'
0041A997  75 3a                                         jnz     short loc_41A9D3
0041A999  46                                            inc     esi
0041A99A  89 75 8c                                      mov     [ebp+var_74], esi
0041A99D  8a 06                                         mov     al, [esi]
0041A99F  3a c3                                         cmp     al, bl
0041A9A1  74 04                                         jz      short loc_41A9A7
0041A9A3  3c 22                                         cmp     al, 22h ; '"'
0041A9A5  75 f2                                         jnz     short loc_41A999
0041A9A7  80 3e 22                                      cmp     byte ptr [esi], 22h ; '"'
0041A9AA  75 04                                         jnz     short loc_41A9B0
0041A9AC  46                                            inc     esi
0041A9AD  89 75 8c                                      mov     [ebp+var_74], esi
0041A9B0  8a 06                                         mov     al, [esi]
0041A9B2  3a c3                                         cmp     al, bl
0041A9B4  74 04                                         jz      short loc_41A9BA
0041A9B6  3c 20                                         cmp     al, 20h ; ' '
0041A9B8  76 f2                                         jbe     short loc_41A9AC
0041A9BA  89 5d d0                                      mov     [ebp+StartupInfo.dwFlags], ebx
0041A9BD  8d 45 a4                                      lea     eax, [ebp+StartupInfo]
0041A9C0  50                                            push    eax; lpStartupInfo
0041A9C1  ff 15 30 c0 41 00                             call    ds:GetStartupInfoA; KERNEL32
0041A9C7  f6 45 d0 01                                   test    byte ptr [ebp+StartupInfo.dwFlags], 1
0041A9CB  74 11                                         jz      short loc_41A9DE
0041A9CD  0f b7 45 d4                                   movzx   eax, [ebp+StartupInfo.wShowWindow]
0041A9D1  eb 0e                                         jmp     short loc_41A9E1
0041A9D3  80 3e 20                                      cmp     byte ptr [esi], 20h ; ' '
0041A9D6  76 d8                                         jbe     short loc_41A9B0
0041A9D8  46                                            inc     esi
0041A9D9  89 75 8c                                      mov     [ebp+var_74], esi
0041A9DC  eb f5                                         jmp     short loc_41A9D3
0041A9DE  6a 0a                                         push    0Ah
0041A9E0  58                                            pop     eax
0041A9E1  50                                            push    eax; nShowCmd
0041A9E2  56                                            push    esi; lpCmdLine
0041A9E3  53                                            push    ebx; hPrevInstance
0041A9E4  53                                            push    ebx; lpModuleName
0041A9E5  ff 15 2c c0 41 00                             call    ds:GetModuleHandleA; KERNEL32
0041A9EB  50                                            push    eax; hInstance
0041A9EC  e8 65 00 00 00                                call    _WinMain@16
0041A9F1  89 45 98                                      mov     [ebp+var_68], eax
0041A9F4  50                                            push    eax; Code
0041A9F5  ff 15 e4 c2 41 00                             call    ds:exit; MSVCRT
0041A9FB  8b 45 ec                                      mov     eax, [ebp+ms_exc.exc_ptr]
0041A9FE  8b 08                                         mov     ecx, [eax]
0041AA00  8b 09                                         mov     ecx, [ecx]
0041AA02  89 4d 88                                      mov     [ebp+Code], ecx
0041AA05  50                                            push    eax
0041AA06  51                                            push    ecx
0041AA07  e8 1c 00 00 00                                call    _XcptFilter
0041AA0C  59                                            pop     ecx
0041AA0D  59                                            pop     ecx
0041AA0E  c3                                            retn
0041AA0F  8b 65 e8                                      mov     esp, [ebp+ms_exc.old_esp]
0041AA12  ff 75 88                                      push    [ebp+Code]; Code
0041AA15  ff 15 ec c2 41 00                             call    ds:_exit; MSVCRT
