00401960  8a 44 24 04                                   mov     al, [esp+arg_0]
00401964  56                                            push    esi
00401965  8b f1                                         mov     esi, ecx
00401967  a8 01                                         test    al, 1
00401969  c7 06 70 c5 41 00                             mov     dword ptr [esi], offset off_41C570
0040196F  74 09                                         jz      short loc_40197A
00401971  56                                            push    esi; void *
00401972  e8 71 8c 01 00                                call    ??3@YAXPAX@Z
00401977  83 c4 04                                      add     esp, 4
0040197A  8b c6                                         mov     eax, esi
0040197C  5e                                            pop     esi
0040197D  c2 04 00                                      retn    4
