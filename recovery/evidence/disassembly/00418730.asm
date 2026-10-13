00418730  6a ff                                         push    0FFFFFFFFh
00418732  68 a8 b1 41 00                                push    offset SEH_418730
00418737  64 a1 00 00 00 00                             mov     eax, large fs:0
0041873D  50                                            push    eax
0041873E  64 89 25 00 00 00 00                          mov     large fs:0, esp
00418745  51                                            push    ecx
00418746  55                                            push    ebp
00418747  56                                            push    esi
00418748  8b f1                                         mov     esi, ecx
0041874A  57                                            push    edi
0041874B  8d 4c 24 0c                                   lea     ecx, [esp+1Ch+var_10]; this
0041874F  e8 ca 1e 00 00                                call    ??0CString@@QAE@XZ; CString::CString(void)
00418754  8b 6c 24 20                                   mov     ebp, [esp+1Ch+arg_0]
00418758  8b 46 7c                                      mov     eax, [esi+7Ch]
0041875B  8b 7c 24 28                                   mov     edi, [esp+1Ch+arg_8]
0041875F  3b e8                                         cmp     ebp, eax
00418761  c7 44 24 18 00 00 00 00                       mov     [esp+1Ch+var_4], 0
00418769  75 62                                         jnz     short loc_4187CD
0041876B  8b 86 84 00 00 00                             mov     eax, [esi+84h]
00418771  85 c0                                         test    eax, eax
00418773  75 2d                                         jnz     short loc_4187A2
00418775  8b 44 24 24                                   mov     eax, [esp+1Ch+arg_4]
00418779  48                                            dec     eax
0041877A  74 17                                         jz      short loc_418793
0041877C  48                                            dec     eax
0041877D  75 4e                                         jnz     short loc_4187CD
0041877F  81 ff fc 03 00 00                             cmp     edi, 3FCh
00418785  75 46                                         jnz     short loc_4187CD
00418787  c7 86 84 00 00 00 01 00 00 00                 mov     dword ptr [esi+84h], 1
00418791  eb 3a                                         jmp     short loc_4187CD
00418793  85 ff                                         test    edi, edi
00418795  74 36                                         jz      short loc_4187CD
00418797  6a 02                                         push    2
00418799  8b ce                                         mov     ecx, esi
0041879B  e8 70 16 ff ff                                call    sub_409E10
004187A0  eb 2b                                         jmp     short loc_4187CD
004187A2  83 f8 01                                      cmp     eax, 1
004187A5  75 26                                         jnz     short loc_4187CD
004187A7  83 7c 24 24 02                                cmp     [esp+1Ch+arg_4], 2
004187AC  75 1f                                         jnz     short loc_4187CD
004187AE  81 ff eb 03 00 00                             cmp     edi, 3EBh
004187B4  74 0d                                         jz      short loc_4187C3
004187B6  85 ff                                         test    edi, edi
004187B8  75 13                                         jnz     short loc_4187CD
004187BA  6a 03                                         push    3
004187BC  8b ce                                         mov     ecx, esi
004187BE  e8 4d 16 ff ff                                call    sub_409E10
004187C3  c7 86 84 00 00 00 00 00 00 00                 mov     dword ptr [esi+84h], 0
004187CD  8b 44 24 24                                   mov     eax, [esp+1Ch+arg_4]
004187D1  57                                            push    edi; int
004187D2  50                                            push    eax; unsigned int
004187D3  55                                            push    ebp; unsigned int
004187D4  8b ce                                         mov     ecx, esi; this
004187D6  e8 35 1d 00 00                                call    ?WindowProc@CWnd@@MAEJIIJ@Z; CWnd::WindowProc(uint,uint,long)
004187DB  8d 4c 24 0c                                   lea     ecx, [esp+1Ch+var_10]; this
004187DF  8b f0                                         mov     esi, eax
004187E1  c7 44 24 18 ff ff ff ff                       mov     [esp+1Ch+var_4], 0FFFFFFFFh
004187E9  e8 18 1e 00 00                                call    ??1CString@@QAE@XZ; CString::~CString(void)
004187EE  8b 4c 24 10                                   mov     ecx, [esp+1Ch+var_C]
004187F2  8b c6                                         mov     eax, esi
004187F4  5f                                            pop     edi
004187F5  5e                                            pop     esi
004187F6  5d                                            pop     ebp
004187F7  64 89 0d 00 00 00 00                          mov     large fs:0, ecx
004187FE  83 c4 10                                      add     esp, 10h
00418801  c2 0c 00                                      retn    0Ch
0041B1A0  8d 4d f0                                      lea     ecx, [ebp-10h]; this
0041B1A3  e9 5e f4 ff ff                                jmp     ??1CString@@QAE@XZ; CString::~CString(void)
0041B1A8  b8 30 da 41 00                                mov     eax, offset stru_41DA30
0041B1AD  e9 6a f6 ff ff                                jmp     __CxxFrameHandler
