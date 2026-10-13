0041A360  6a ff                                         push    0FFFFFFFFh
0041A362  68 f8 b2 41 00                                push    offset SEH_41A360
0041A367  64 a1 00 00 00 00                             mov     eax, large fs:0
0041A36D  50                                            push    eax
0041A36E  64 89 25 00 00 00 00                          mov     large fs:0, esp
0041A375  51                                            push    ecx
0041A376  8d 4c 24 00                                   lea     ecx, [esp+10h+var_10]; this
0041A37A  e8 9f 02 00 00                                call    ??0CString@@QAE@XZ; CString::CString(void)
0041A37F  6a 00                                         push    0; lpWindowName
0041A381  68 d4 ed 42 00                                push    offset ClassName; "KOEI_SAN9WINDOW"
0041A386  c7 44 24 14 00 00 00 00                       mov     [esp+18h+var_4], 0
0041A38E  ff 15 30 c3 41 00                             call    ds:FindWindowA; USER32
0041A394  85 c0                                         test    eax, eax
0041A396  74 0b                                         jz      short loc_41A3A3
0041A398  6a 00                                         push    0
0041A39A  6a 00                                         push    0
0041A39C  68 14 ef 42 00                                push    offset a39; "39"
0041A3A1  eb 2e                                         jmp     short loc_41A3D1
0041A3A3  6a 05                                         push    5; uCmdShow
0041A3A5  68 08 ef 42 00                                push    offset CmdLine; "San9PK.exe"
0041A3AA  ff 15 28 c0 41 00                             call    ds:WinExec; KERNEL32
0041A3B0  83 f8 1f                                      cmp     eax, 1Fh
0041A3B3  77 21                                         ja      short loc_41A3D6
0041A3B5  50                                            push    eax
0041A3B6  8d 44 24 04                                   lea     eax, [esp+14h+var_10]
0041A3BA  68 d0 ee 42 00                                push    offset byte_42EED0; char *
0041A3BF  50                                            push    eax; this
0041A3C0  e8 47 02 00 00                                call    ?Format@CString@@QAAXPBDZZ; CString::Format(char const *,...)
0041A3C5  8b 4c 24 0c                                   mov     ecx, [esp+1Ch+var_10]
0041A3C9  83 c4 0c                                      add     esp, 0Ch
0041A3CC  6a 00                                         push    0; unsigned int
0041A3CE  6a 00                                         push    0; unsigned int
0041A3D0  51                                            push    ecx; char *
0041A3D1  e8 3c 02 00 00                                call    ?AfxMessageBox@@YGHPBDII@Z; AfxMessageBox(char const *,uint,uint)
0041A3D6  8d 4c 24 00                                   lea     ecx, [esp+10h+var_10]; this
0041A3DA  c7 44 24 0c ff ff ff ff                       mov     [esp+10h+var_4], 0FFFFFFFFh
0041A3E2  e8 1f 02 00 00                                call    ??1CString@@QAE@XZ; CString::~CString(void)
0041A3E7  8b 4c 24 04                                   mov     ecx, [esp+10h+var_C]
0041A3EB  64 89 0d 00 00 00 00                          mov     large fs:0, ecx
0041A3F2  83 c4 10                                      add     esp, 10h
0041A3F5  c3                                            retn
0041B2F0  8d 4d f0                                      lea     ecx, [ebp-10h]; this
0041B2F3  e9 0e f3 ff ff                                jmp     ??1CString@@QAE@XZ; CString::~CString(void)
0041B2F8  b8 d8 dc 41 00                                mov     eax, offset stru_41DCD8
0041B2FD  e9 1a f5 ff ff                                jmp     __CxxFrameHandler
