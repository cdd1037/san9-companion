00401280  6a ff                                         push    0FFFFFFFFh
00401282  68 0b ab 41 00                                push    offset SEH_401280
00401287  64 a1 00 00 00 00                             mov     eax, large fs:0
0040128D  50                                            push    eax
0040128E  64 89 25 00 00 00 00                          mov     large fs:0, esp
00401295  81 ec 5c 0e 00 00                             sub     esp, 0E5Ch
0040129B  53                                            push    ebx
0040129C  56                                            push    esi
0040129D  8b f1                                         mov     esi, ecx
0040129F  e8 80 93 01 00                                call    ?OnInitDialog@CDialog@@UAEHXZ; CDialog::OnInitDialog(void)
004012A4  8d 4c 24 08                                   lea     ecx, [esp+0E70h+lParam]; this
004012A8  e8 71 93 01 00                                call    ??0CString@@QAE@XZ; CString::CString(void)
004012AD  33 db                                         xor     ebx, ebx
004012AF  89 9c 24 6c 0e 00 00                          mov     [esp+0E70h+var_4], ebx
004012B6  e8 5d 93 01 00                                call    ?AfxGetModuleState@@YGPAVAFX_MODULE_STATE@@XZ; AfxGetModuleState(void)
004012BB  8b 40 04                                      mov     eax, [eax+4]
004012BE  8b c8                                         mov     ecx, eax
004012C0  8b 10                                         mov     edx, [eax]
004012C2  ff 52 7c                                      call    dword ptr [edx+7Ch]
004012C5  8d 88 84 13 00 00                             lea     ecx, [eax+1384h]
004012CB  89 86 c8 00 00 00                             mov     [esi+0C8h], eax
004012D1  89 8e c4 00 00 00                             mov     [esi+0C4h], ecx
004012D7  88 9e cc 00 00 00                             mov     [esi+0CCh], bl
004012DD  8b 40 70                                      mov     eax, [eax+70h]
004012E0  3b c3                                         cmp     eax, ebx
004012E2  0f 84 74 01 00 00                             jz      loc_40145C
004012E8  53                                            push    ebx; lpNumberOfBytesRead
004012E9  8d 54 24 10                                   lea     edx, [esp+0E74h+Buffer]
004012ED  68 58 0e 00 00                                push    0E58h; nSize
004012F2  52                                            push    edx; lpBuffer
004012F3  68 70 0b 50 01                                push    1500B70h; lpBaseAddress
004012F8  50                                            push    eax; hProcess
004012F9  ff 15 3c c0 41 00                             call    ds:ReadProcessMemory; KERNEL32
004012FF  3b c3                                         cmp     eax, ebx
00401301  75 11                                         jnz     short loc_401314
00401303  53                                            push    ebx; unsigned int
00401304  53                                            push    ebx; unsigned int
00401305  68 28 f5 41 00                                push    offset byte_41F528; char *
0040130A  e8 03 93 01 00                                call    ?AfxMessageBox@@YGHPBDII@Z; AfxMessageBox(char const *,uint,uint)
0040130F  e9 48 01 00 00                                jmp     loc_40145C
00401314  55                                            push    ebp
00401315  8b 2d 64 c3 41 00                             mov     ebp, ds:SendMessageA; USER32
0040131B  57                                            push    edi
0040131C  8d 7c 24 24                                   lea     edi, [esp+0E78h+MultiByteStr]
00401320  57                                            push    edi; lpMultiByteStr
00401321  e8 ea 8d 01 00                                call    sub_41A110
00401326  57                                            push    edi
00401327  53                                            push    ebx
00401328  8d 44 24 1c                                   lea     eax, [esp+0E84h+lParam]
0040132C  68 20 f5 41 00                                push    offset a02dS; "%02d %s"
00401331  50                                            push    eax; this
00401332  e8 d5 92 01 00                                call    ?Format@CString@@QAAXPBDZZ; CString::Format(char const *,...)
00401337  8b 4c 24 24                                   mov     ecx, [esp+0E8Ch+lParam]
0040133B  8b 96 80 00 00 00                             mov     edx, [esi+80h]
00401341  83 c4 14                                      add     esp, 14h
00401344  51                                            push    ecx; lParam
00401345  6a ff                                         push    0FFFFFFFFh; wParam
00401347  68 81 01 00 00                                push    181h; Msg
0040134C  52                                            push    edx; hWnd
0040134D  ff d5                                         call    ebp ; SendMessageA; USER32
0040134F  83 f8 ff                                      cmp     eax, 0FFFFFFFFh
00401352  0f 84 dc 00 00 00                             jz      loc_401434
00401358  83 f8 fe                                      cmp     eax, 0FFFFFFFEh
0040135B  0f 84 d3 00 00 00                             jz      loc_401434
00401361  8b 86 c8 00 00 00                             mov     eax, [esi+0C8h]
00401367  f6 80 82 13 00 00 03                          test    byte ptr [eax+1382h], 3
0040136E  0f 85 ae 00 00 00                             jnz     loc_401422
00401374  0f be 4f 50                                   movsx   ecx, byte ptr [edi+50h]
00401378  8b 96 c4 00 00 00                             mov     edx, [esi+0C4h]
0040137E  89 0c da                                      mov     [edx+ebx*8], ecx
00401381  8b 86 c4 00 00 00                             mov     eax, [esi+0C4h]
00401387  0f be 4f 54                                   movsx   ecx, byte ptr [edi+54h]
0040138B  8b 14 d8                                      mov     edx, [eax+ebx*8]
0040138E  8d 04 d8                                      lea     eax, [eax+ebx*8]
00401391  c1 e1 06                                      shl     ecx, 6
00401394  0b d1                                         or      edx, ecx
00401396  89 10                                         mov     [eax], edx
00401398  8b 96 c4 00 00 00                             mov     edx, [esi+0C4h]
0040139E  0f be 4f 58                                   movsx   ecx, byte ptr [edi+58h]
004013A2  8d 04 da                                      lea     eax, [edx+ebx*8]
004013A5  c1 e1 0c                                      shl     ecx, 0Ch
004013A8  8b 10                                         mov     edx, [eax]
004013AA  0b d1                                         or      edx, ecx
004013AC  89 10                                         mov     [eax], edx
004013AE  8b 96 c4 00 00 00                             mov     edx, [esi+0C4h]
004013B4  0f be 4f 5c                                   movsx   ecx, byte ptr [edi+5Ch]
004013B8  8d 04 da                                      lea     eax, [edx+ebx*8]
004013BB  c1 e1 12                                      shl     ecx, 12h
004013BE  8b 10                                         mov     edx, [eax]
004013C0  0b d1                                         or      edx, ecx
004013C2  89 10                                         mov     [eax], edx
004013C4  8b 96 c4 00 00 00                             mov     edx, [esi+0C4h]
004013CA  0f be 4f 4c                                   movsx   ecx, byte ptr [edi+4Ch]
004013CE  8d 04 da                                      lea     eax, [edx+ebx*8]
004013D1  c1 e1 18                                      shl     ecx, 18h
004013D4  8b 10                                         mov     edx, [eax]
004013D6  0b d1                                         or      edx, ecx
004013D8  89 10                                         mov     [eax], edx
004013DA  8b 96 c4 00 00 00                             mov     edx, [esi+0C4h]
004013E0  66 83 64 da 04 0f                             and     word ptr [edx+ebx*8+4], 0Fh
004013E6  66 0f be 4f 60                                movsx   cx, byte ptr [edi+60h]
004013EB  8d 44 da 04                                   lea     eax, [edx+ebx*8+4]
004013EF  8b 86 c4 00 00 00                             mov     eax, [esi+0C4h]
004013F5  c1 e1 04                                      shl     ecx, 4
004013F8  66 09 4c d8 04                                or      [eax+ebx*8+4], cx
004013FD  8b 96 c4 00 00 00                             mov     edx, [esi+0C4h]
00401403  8d 44 d8 04                                   lea     eax, [eax+ebx*8+4]
00401407  33 c9                                         xor     ecx, ecx
00401409  8a 6f 64                                      mov     ch, [edi+64h]
0040140C  8d 44 da 04                                   lea     eax, [edx+ebx*8+4]
00401410  66 09 08                                      or      [eax], cx
00401413  8b 96 c4 00 00 00                             mov     edx, [esi+0C4h]
00401419  66 8b 47 68                                   mov     ax, [edi+68h]
0040141D  66 89 44 da 06                                mov     [edx+ebx*8+6], ax
00401422  43                                            inc     ebx
00401423  81 c7 88 00 00 00                             add     edi, 88h
00401429  83 fb 1b                                      cmp     ebx, 1Bh
0040142C  0f 8c ee fe ff ff                             jl      loc_401320
00401432  eb 0e                                         jmp     short loc_401442
00401434  6a 00                                         push    0; unsigned int
00401436  6a 00                                         push    0; unsigned int
00401438  68 10 f5 41 00                                push    offset byte_41F510; char *
0040143D  e8 d0 91 01 00                                call    ?AfxMessageBox@@YGHPBDII@Z; AfxMessageBox(char const *,uint,uint)
00401442  5f                                            pop     edi
00401443  80 fb 1b                                      cmp     bl, 1Bh
00401446  88 9e cc 00 00 00                             mov     [esi+0CCh], bl
0040144C  5d                                            pop     ebp
0040144D  75 0d                                         jnz     short loc_40145C
0040144F  8b 86 c8 00 00 00                             mov     eax, [esi+0C8h]
00401455  80 88 82 13 00 00 02                          or      byte ptr [eax+1382h], 2
0040145C  8b ce                                         mov     ecx, esi; this
0040145E  c6 86 cd 00 00 00 00                          mov     byte ptr [esi+0CDh], 0
00401465  e8 36 00 00 00                                call    sub_4014A0
0040146A  8d 4c 24 08                                   lea     ecx, [esp+0E70h+lParam]; this
0040146E  c7 84 24 6c 0e 00 00 ff ff ff ff              mov     [esp+0E70h+var_4], 0FFFFFFFFh
00401479  e8 88 91 01 00                                call    ??1CString@@QAE@XZ; CString::~CString(void)
0040147E  8b 8c 24 64 0e 00 00                          mov     ecx, [esp+0E70h+var_C]
00401485  5e                                            pop     esi
00401486  b8 01 00 00 00                                mov     eax, 1
0040148B  5b                                            pop     ebx
0040148C  64 89 0d 00 00 00 00                          mov     large fs:0, ecx
00401493  81 c4 68 0e 00 00                             add     esp, 0E68h
00401499  c3                                            retn
0041AB00  8d 8d 98 f1 ff ff                             lea     ecx, [ebp-0E68h]; this
0041AB06  e9 fb fa ff ff                                jmp     ??1CString@@QAE@XZ; CString::~CString(void)
0041AB0B  b8 c8 d1 41 00                                mov     eax, offset stru_41D1C8
0041AB10  e9 07 fd ff ff                                jmp     __CxxFrameHandler
