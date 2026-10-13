00429958  55                                            push    ebp
00429959  8b ec                                         mov     ebp, esp
0042995B  56                                            push    esi
0042995C  57                                            push    edi
0042995D  53                                            push    ebx
0042995E  8b d9                                         mov     ebx, ecx
00429960  8b 4d 0c                                      mov     ecx, [ebp+arg_4]
00429963  8b 71 04                                      mov     esi, [ecx+4]
00429966  bf 00 05 0a 00                                mov     edi, 0A0500h
0042996B  8b cf                                         mov     ecx, edi
0042996D  b8 90 82 0a 00                                mov     eax, 0A8290h
00429972  ff d0                                         call    eax
00429974  ff 75 20                                      push    [ebp+arg_18]
00429977  ff 76 08                                      push    dword ptr [esi+8]
0042997A  6a 00                                         push    0
0042997C  8b cb                                         mov     ecx, ebx
0042997E  ff 55 10                                      call    [ebp+arg_8]
00429981  8b cb                                         mov     ecx, ebx
00429983  b8 80 64 48 00                                mov     eax, 486480h
00429988  ff d0                                         call    eax
0042998A  3c 03                                         cmp     al, 3
0042998C  74 0c                                         jz      short loc_42999A
0042998E  ff 76 08                                      push    dword ptr [esi+8]
00429991  8b cf                                         mov     ecx, edi
00429993  b8 70 ef 46 00                                mov     eax, 46EF70h
00429998  ff d0                                         call    eax
0042999A  8b 36                                         mov     esi, [esi]
0042999C  85 f6                                         test    esi, esi
0042999E  75 d4                                         jnz     short loc_429974
004299A0  39 77 0c                                      cmp     [edi+0Ch], esi
004299A3  74 29                                         jz      short loc_4299CE
004299A5  8b 47 04                                      mov     eax, [edi+4]
004299A8  8b 53 34                                      mov     edx, [ebx+34h]
004299AB  83 ea 19                                      sub     edx, 19h
004299AE  83 fa 02                                      cmp     edx, 2
004299B1  77 03                                         ja      short loc_4299B6
004299B3  8b 47 08                                      mov     eax, [edi+8]
004299B6  8b 40 08                                      mov     eax, [eax+8]
004299B9  8b 55 08                                      mov     edx, [ebp+arg_0]
004299BC  89 02                                         mov     [edx], eax
004299BE  89 45 1c                                      mov     [ebp+arg_14], eax
004299C1  8b 4d 04                                      mov     ecx, [ebp+4]
004299C4  8b 01                                         mov     eax, [ecx]
004299C6  6a 01                                         push    1
004299C8  ff 90 ec 00 00 00                             call    dword ptr [eax+0ECh]
004299CE  8b cb                                         mov     ecx, ebx
004299D0  5b                                            pop     ebx
004299D1  5f                                            pop     edi
004299D2  5e                                            pop     esi
004299D3  5d                                            pop     ebp
004299D4  83 c4 0c                                      add     esp, 0Ch
004299D7  c3                                            retn
