00404720  6a ff                                         push    0FFFFFFFFh
00404722  68 39 b0 41 00                                push    offset SEH_404720
00404727  64 a1 00 00 00 00                             mov     eax, large fs:0
0040472D  50                                            push    eax
0040472E  64 89 25 00 00 00 00                          mov     large fs:0, esp
00404735  51                                            push    ecx
00404736  8b 44 24 14                                   mov     eax, [esp+10h+arg_0]
0040473A  53                                            push    ebx
0040473B  55                                            push    ebp
0040473C  56                                            push    esi
0040473D  57                                            push    edi
0040473E  8b f1                                         mov     esi, ecx
00404740  50                                            push    eax; struct CWnd *
00404741  68 84 00 00 00                                push    84h; unsigned int
00404746  89 74 24 18                                   mov     [esp+28h+var_10], esi
0040474A  e8 93 5e 01 00                                call    ??0CDialog@@QAE@IPAVCWnd@@@Z; CDialog::CDialog(uint,CWnd *)
0040474F  8d 7e 60                                      lea     edi, [esi+60h]
00404752  33 db                                         xor     ebx, ebx
00404754  8b cf                                         mov     ecx, edi; this
00404756  89 5c 24 1c                                   mov     [esp+20h+var_4], ebx
0040475A  e8 7d 5e 01 00                                call    ??0CWnd@@QAE@XZ; CWnd::CWnd(void)
0040475F  c7 07 98 c4 41 00                             mov     dword ptr [edi], offset off_41C498
00404765  8d be a0 00 00 00                             lea     edi, [esi+0A0h]
0040476B  c6 44 24 1c 01                                mov     byte ptr [esp+20h+var_4], 1
00404770  8b cf                                         mov     ecx, edi; this
00404772  e8 65 5e 01 00                                call    ??0CWnd@@QAE@XZ; CWnd::CWnd(void)
00404777  c7 07 d4 cb 41 00                             mov     dword ptr [edi], offset off_41CBD4
0040477D  8d be e0 00 00 00                             lea     edi, [esi+0E0h]
00404783  c6 44 24 1c 02                                mov     byte ptr [esp+20h+var_4], 2
00404788  8b cf                                         mov     ecx, edi; this
0040478A  e8 8f 5e 01 00                                call    ??0CString@@QAE@XZ; CString::CString(void)
0040478F  8d ae 4c 01 00 00                             lea     ebp, [esi+14Ch]
00404795  c6 44 24 1c 03                                mov     byte ptr [esp+20h+var_4], 3
0040479A  8b cd                                         mov     ecx, ebp; this
0040479C  e8 7d 5e 01 00                                call    ??0CString@@QAE@XZ; CString::CString(void)
004047A1  89 9e 44 7b 00 00                             mov     [esi+7B44h], ebx
004047A7  c7 86 40 7b 00 00 c0 cb 41 00                 mov     dword ptr [esi+7B40h], offset off_41CBC0
004047B1  8d 8e 48 7b 00 00                             lea     ecx, [esi+7B48h]; this
004047B7  c6 44 24 1c 05                                mov     byte ptr [esp+20h+var_4], 5
004047BC  e8 5d 5e 01 00                                call    ??0CString@@QAE@XZ; CString::CString(void)
004047C1  68 48 ef 42 00                                push    offset Str2
004047C6  8b cf                                         mov     ecx, edi
004047C8  c6 44 24 20 06                                mov     byte ptr [esp+24h+var_4], 6
004047CD  c7 06 e8 ca 41 00                             mov     dword ptr [esi], offset off_41CAE8
004047D3  e8 12 5f 01 00                                call    ??4CString@@QAEABV0@PBD@Z; CString::operator=(char const *)
004047D8  83 c8 ff                                      or      eax, 0FFFFFFFFh
004047DB  88 9e 08 01 00 00                             mov     [esi+108h], bl
004047E1  89 86 e4 00 00 00                             mov     [esi+0E4h], eax
004047E7  89 86 e8 00 00 00                             mov     [esi+0E8h], eax
004047ED  89 86 ec 00 00 00                             mov     [esi+0ECh], eax
004047F3  89 86 f0 00 00 00                             mov     [esi+0F0h], eax
004047F9  89 86 f4 00 00 00                             mov     [esi+0F4h], eax
004047FF  89 86 f8 00 00 00                             mov     [esi+0F8h], eax
00404805  89 86 fc 00 00 00                             mov     [esi+0FCh], eax
0040480B  89 86 00 01 00 00                             mov     [esi+100h], eax
00404811  89 86 04 01 00 00                             mov     [esi+104h], eax
00404817  88 9e 09 01 00 00                             mov     [esi+109h], bl
0040481D  88 9e 0a 01 00 00                             mov     [esi+10Ah], bl
00404823  88 9e 0b 01 00 00                             mov     [esi+10Bh], bl
00404829  89 9e 0c 01 00 00                             mov     [esi+10Ch], ebx
0040482F  89 9e 10 01 00 00                             mov     [esi+110h], ebx
00404835  89 9e 14 01 00 00                             mov     [esi+114h], ebx
0040483B  89 9e 18 01 00 00                             mov     [esi+118h], ebx
00404841  89 9e 1c 01 00 00                             mov     [esi+11Ch], ebx
00404847  89 9e 20 01 00 00                             mov     [esi+120h], ebx
0040484D  89 9e 24 01 00 00                             mov     [esi+124h], ebx
00404853  89 9e 28 01 00 00                             mov     [esi+128h], ebx
00404859  89 9e 2c 01 00 00                             mov     [esi+12Ch], ebx
0040485F  66 89 9e 30 01 00 00                          mov     [esi+130h], bx
00404866  66 89 9e 32 01 00 00                          mov     [esi+132h], bx
0040486D  66 89 9e 34 01 00 00                          mov     [esi+134h], bx
00404874  66 89 9e 36 01 00 00                          mov     [esi+136h], bx
0040487B  66 89 9e 38 01 00 00                          mov     [esi+138h], bx
00404882  66 89 9e 3a 01 00 00                          mov     [esi+13Ah], bx
00404889  66 89 9e 3c 01 00 00                          mov     [esi+13Ch], bx
00404890  66 89 9e 3e 01 00 00                          mov     [esi+13Eh], bx
00404897  66 89 9e 40 01 00 00                          mov     [esi+140h], bx
0040489E  66 89 9e 42 01 00 00                          mov     [esi+142h], bx
004048A5  66 89 9e 44 01 00 00                          mov     [esi+144h], bx
004048AC  66 89 9e 46 01 00 00                          mov     [esi+146h], bx
004048B3  68 48 ef 42 00                                push    offset Str2
004048B8  8b cd                                         mov     ecx, ebp
004048BA  89 9e 48 01 00 00                             mov     [esi+148h], ebx
004048C0  e8 25 5e 01 00                                call    ??4CString@@QAEABV0@PBD@Z; CString::operator=(char const *)
004048C5  8b 4c 24 14                                   mov     ecx, [esp+20h+var_C]
004048C9  89 9e 50 01 00 00                             mov     [esi+150h], ebx
004048CF  8b c6                                         mov     eax, esi
004048D1  5f                                            pop     edi
004048D2  5e                                            pop     esi
004048D3  5d                                            pop     ebp
004048D4  5b                                            pop     ebx
004048D5  64 89 0d 00 00 00 00                          mov     large fs:0, ecx
004048DC  83 c4 10                                      add     esp, 10h
004048DF  c2 04 00                                      retn    4
0041AFE0  8b 4d f0                                      mov     ecx, [ebp-10h]; this
0041AFE3  e9 ee f5 ff ff                                jmp     ??1CDialog@@UAE@XZ; CDialog::~CDialog(void)
0041AFE8  8b 4d f0                                      mov     ecx, [ebp-10h]
0041AFEB  83 c1 60                                      add     ecx, 60h ; '`'; this
0041AFEE  e9 fb f5 ff ff                                jmp     ??1CListBox@@UAE@XZ; CListBox::~CListBox(void)
0041AFF3  8b 4d f0                                      mov     ecx, [ebp-10h]
0041AFF6  81 c1 a0 00 00 00                             add     ecx, 0A0h; this
0041AFFC  e9 c5 f6 ff ff                                jmp     ??1CScrollBar@@UAE@XZ; CScrollBar::~CScrollBar(void)
0041B001  8b 4d f0                                      mov     ecx, [ebp-10h]
0041B004  81 c1 e0 00 00 00                             add     ecx, 0E0h; this
0041B00A  e9 f7 f5 ff ff                                jmp     ??1CString@@QAE@XZ; CString::~CString(void)
0041B00F  8b 4d f0                                      mov     ecx, [ebp-10h]
0041B012  81 c1 4c 01 00 00                             add     ecx, 14Ch; this
0041B018  e9 e9 f5 ff ff                                jmp     ??1CString@@QAE@XZ; CString::~CString(void)
0041B01D  8b 4d f0                                      mov     ecx, [ebp-10h]
0041B020  81 c1 40 7b 00 00                             add     ecx, 7B40h
0041B026  e9 35 96 fe ff                                jmp     sub_404660
0041B02B  8b 4d f0                                      mov     ecx, [ebp-10h]
0041B02E  81 c1 48 7b 00 00                             add     ecx, 7B48h; this
0041B034  e9 cd f5 ff ff                                jmp     ??1CString@@QAE@XZ; CString::~CString(void)
0041B039  b8 10 d8 41 00                                mov     eax, offset stru_41D810
0041B03E  e9 d9 f7 ff ff                                jmp     __CxxFrameHandler
