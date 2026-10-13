0041A1F0  53                                            push    ebx
0041A1F1  56                                            push    esi
0041A1F2  57                                            push    edi
0041A1F3  8b 7c 24 10                                   mov     edi, [esp+0Ch+arg_0]
0041A1F7  8b c7                                         mov     eax, edi
0041A1F9  8b f1                                         mov     esi, ecx
0041A1FB  f7 d8                                         neg     eax
0041A1FD  8b 96 f0 15 00 00                             mov     edx, [esi+15F0h]
0041A203  8b 1d 40 c0 41 00                             mov     ebx, ds:WriteProcessMemory; KERNEL32
0041A209  1b c0                                         sbb     eax, eax
0041A20B  6a 00                                         push    0; lpNumberOfBytesWritten
0041A20D  24 fa                                         and     al, 0FAh
0041A20F  6a 04                                         push    4; nSize
0041A211  83 c0 0f                                      add     eax, 0Fh
0041A214  83 c2 44                                      add     edx, 44h ; 'D'
0041A217  8d 8c 86 68 14 00 00                          lea     ecx, [esi+eax*4+1468h]
0041A21E  8b 46 70                                      mov     eax, [esi+70h]
0041A221  51                                            push    ecx; lpBuffer
0041A222  52                                            push    edx; lpBaseAddress
0041A223  50                                            push    eax; hProcess
0041A224  ff d3                                         call    ebx ; WriteProcessMemory; KERNEL32
0041A226  85 c0                                         test    eax, eax
0041A228  75 06                                         jnz     short loc_41A230
0041A22A  5f                                            pop     edi
0041A22B  5e                                            pop     esi
0041A22C  5b                                            pop     ebx
0041A22D  c2 04 00                                      retn    4
0041A230  8b 86 ac 15 00 00                             mov     eax, [esi+15ACh]
0041A236  33 c9                                         xor     ecx, ecx
0041A238  85 ff                                         test    edi, edi
0041A23A  0f 95 c1                                      setnz   cl
0041A23D  83 c1 09                                      add     ecx, 9
0041A240  6a 00                                         push    0; lpNumberOfBytesWritten
0041A242  6a 04                                         push    4; nSize
0041A244  83 c0 44                                      add     eax, 44h ; 'D'
0041A247  8d 94 8e 68 14 00 00                          lea     edx, [esi+ecx*4+1468h]
0041A24E  8b 4e 70                                      mov     ecx, [esi+70h]
0041A251  52                                            push    edx; lpBuffer
0041A252  50                                            push    eax; lpBaseAddress
0041A253  51                                            push    ecx; hProcess
0041A254  ff d3                                         call    ebx ; WriteProcessMemory; KERNEL32
0041A256  85 c0                                         test    eax, eax
0041A258  75 06                                         jnz     short loc_41A260
0041A25A  5f                                            pop     edi
0041A25B  5e                                            pop     esi
0041A25C  5b                                            pop     ebx
0041A25D  c2 04 00                                      retn    4
0041A260  8b d7                                         mov     edx, edi
0041A262  8b 8e b0 15 00 00                             mov     ecx, [esi+15B0h]
0041A268  f7 da                                         neg     edx
0041A26A  1b d2                                         sbb     edx, edx
0041A26C  6a 00                                         push    0; lpNumberOfBytesWritten
0041A26E  83 e2 03                                      and     edx, 3
0041A271  6a 04                                         push    4; nSize
0041A273  83 c2 09                                      add     edx, 9
0041A276  83 c1 44                                      add     ecx, 44h ; 'D'
0041A279  8d 84 96 68 14 00 00                          lea     eax, [esi+edx*4+1468h]
0041A280  8b 56 70                                      mov     edx, [esi+70h]
0041A283  50                                            push    eax; lpBuffer
0041A284  51                                            push    ecx; lpBaseAddress
0041A285  52                                            push    edx; hProcess
0041A286  ff d3                                         call    ebx ; WriteProcessMemory; KERNEL32
0041A288  85 c0                                         test    eax, eax
0041A28A  75 06                                         jnz     short loc_41A292
0041A28C  5f                                            pop     edi
0041A28D  5e                                            pop     esi
0041A28E  5b                                            pop     ebx
0041A28F  c2 04 00                                      retn    4
0041A292  8b c7                                         mov     eax, edi
0041A294  8b 96 e8 15 00 00                             mov     edx, [esi+15E8h]
0041A29A  f7 d8                                         neg     eax
0041A29C  1b c0                                         sbb     eax, eax
0041A29E  6a 00                                         push    0; lpNumberOfBytesWritten
0041A2A0  24 f8                                         and     al, 0F8h
0041A2A2  6a 04                                         push    4; nSize
0041A2A4  83 c0 0f                                      add     eax, 0Fh
0041A2A7  83 c2 44                                      add     edx, 44h ; 'D'
0041A2AA  8d 8c 86 68 14 00 00                          lea     ecx, [esi+eax*4+1468h]
0041A2B1  8b 46 70                                      mov     eax, [esi+70h]
0041A2B4  51                                            push    ecx; lpBuffer
0041A2B5  52                                            push    edx; lpBaseAddress
0041A2B6  50                                            push    eax; hProcess
0041A2B7  ff d3                                         call    ebx ; WriteProcessMemory; KERNEL32
0041A2B9  85 c0                                         test    eax, eax
0041A2BB  75 06                                         jnz     short loc_41A2C3
0041A2BD  5f                                            pop     edi
0041A2BE  5e                                            pop     esi
0041A2BF  5b                                            pop     ebx
0041A2C0  c2 04 00                                      retn    4
0041A2C3  8b 86 1c 16 00 00                             mov     eax, [esi+161Ch]
0041A2C9  33 c9                                         xor     ecx, ecx
0041A2CB  85 ff                                         test    edi, edi
0041A2CD  0f 95 c1                                      setnz   cl
0041A2D0  83 c1 11                                      add     ecx, 11h
0041A2D3  6a 00                                         push    0; lpNumberOfBytesWritten
0041A2D5  6a 04                                         push    4; nSize
0041A2D7  83 c0 44                                      add     eax, 44h ; 'D'
0041A2DA  8d 94 8e 68 14 00 00                          lea     edx, [esi+ecx*4+1468h]
0041A2E1  8b 4e 70                                      mov     ecx, [esi+70h]
0041A2E4  52                                            push    edx; lpBuffer
0041A2E5  50                                            push    eax; lpBaseAddress
0041A2E6  51                                            push    ecx; hProcess
0041A2E7  ff d3                                         call    ebx ; WriteProcessMemory; KERNEL32
0041A2E9  85 c0                                         test    eax, eax
0041A2EB  75 06                                         jnz     short loc_41A2F3
0041A2ED  5f                                            pop     edi
0041A2EE  5e                                            pop     esi
0041A2EF  5b                                            pop     ebx
0041A2F0  c2 04 00                                      retn    4
0041A2F3  8b d7                                         mov     edx, edi
0041A2F5  8b 8e 3c 17 00 00                             mov     ecx, [esi+173Ch]
0041A2FB  f7 da                                         neg     edx
0041A2FD  1b d2                                         sbb     edx, edx
0041A2FF  6a 00                                         push    0; lpNumberOfBytesWritten
0041A301  83 e2 f6                                      and     edx, 0FFFFFFF6h
0041A304  6a 04                                         push    4; nSize
0041A306  83 c2 2c                                      add     edx, 2Ch ; ','
0041A309  83 c1 44                                      add     ecx, 44h ; 'D'
0041A30C  8d 84 96 68 14 00 00                          lea     eax, [esi+edx*4+1468h]
0041A313  8b 56 70                                      mov     edx, [esi+70h]
0041A316  50                                            push    eax; lpBuffer
0041A317  51                                            push    ecx; lpBaseAddress
0041A318  52                                            push    edx; hProcess
0041A319  ff d3                                         call    ebx ; WriteProcessMemory; KERNEL32
0041A31B  85 c0                                         test    eax, eax
0041A31D  75 06                                         jnz     short loc_41A325
0041A31F  5f                                            pop     edi
0041A320  5e                                            pop     esi
0041A321  5b                                            pop     ebx
0041A322  c2 04 00                                      retn    4
0041A325  f7 df                                         neg     edi
0041A327  8b 8e c0 16 00 00                             mov     ecx, [esi+16C0h]
0041A32D  8b 56 70                                      mov     edx, [esi+70h]
0041A330  1b ff                                         sbb     edi, edi
0041A332  6a 00                                         push    0; lpNumberOfBytesWritten
0041A334  83 e7 02                                      and     edi, 2
0041A337  6a 04                                         push    4; nSize
0041A339  83 c7 20                                      add     edi, 20h ; ' '
0041A33C  83 c1 44                                      add     ecx, 44h ; 'D'
0041A33F  8d 84 be 68 14 00 00                          lea     eax, [esi+edi*4+1468h]
0041A346  50                                            push    eax; lpBuffer
0041A347  51                                            push    ecx; lpBaseAddress
0041A348  52                                            push    edx; hProcess
0041A349  ff d3                                         call    ebx ; WriteProcessMemory; KERNEL32
0041A34B  f7 d8                                         neg     eax
0041A34D  1b c0                                         sbb     eax, eax
0041A34F  5f                                            pop     edi
0041A350  5e                                            pop     esi
0041A351  5b                                            pop     ebx
0041A352  f7 d8                                         neg     eax
0041A354  c2 04 00                                      retn    4
