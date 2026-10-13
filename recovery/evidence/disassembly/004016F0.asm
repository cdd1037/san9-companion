004016F0  55                                            push    ebp
004016F1  8b ec                                         mov     ebp, esp
004016F3  6a ff                                         push    0FFFFFFFFh
004016F5  68 8a ab 41 00                                push    offset SEH_4016F0
004016FA  64 a1 00 00 00 00                             mov     eax, large fs:0
00401700  50                                            push    eax
00401701  64 89 25 00 00 00 00                          mov     large fs:0, esp
00401708  81 ec 60 02 00 00                             sub     esp, 260h
0040170E  53                                            push    ebx
0040170F  56                                            push    esi
00401710  8b d9                                         mov     ebx, ecx
00401712  57                                            push    edi
00401713  8d 4d d8                                      lea     ecx, [ebp+var_28]; this
00401716  89 65 f0                                      mov     [ebp+var_10], esp
00401719  e8 54 8f 01 00                                call    ??0CStdioFile@@QAE@XZ; CStdioFile::CStdioFile(void)
0040171E  8d 4d ec                                      lea     ecx, [ebp+var_14]; this
00401721  c7 45 fc 00 00 00 00                          mov     [ebp+var_4], 0
00401728  e8 f1 8e 01 00                                call    ??0CString@@QAE@XZ; CString::CString(void)
0040172D  b9 0b 00 00 00                                mov     ecx, 0Bh
00401732  be b0 f5 41 00                                mov     esi, offset aTextFilesTxtTx; "Text Files (*.txt)|*.txt|All Files (*.*"...
00401737  8d 7d 90                                      lea     edi, [ebp+var_70]
0040173A  8d 45 90                                      lea     eax, [ebp+var_70]
0040173D  f3 a5                                         rep movsd
0040173F  53                                            push    ebx; struct CWnd *
00401740  50                                            push    eax; char *
00401741  66 a5                                         movsw
00401743  6a 06                                         push    6; unsigned int
00401745  68 9c f5 41 00                                push    offset aSan9pkhardarra; "San9PKHardArray.txt"
0040174A  6a 00                                         push    0; char *
0040174C  6a 00                                         push    0; int
0040174E  8d 8d 94 fd ff ff                             lea     ecx, [ebp+var_26C]; this
00401754  c6 45 fc 01                                   mov     byte ptr [ebp+var_4], 1
00401758  a4                                            movsb
00401759  e8 0e 8f 01 00                                call    ??0CFileDialog@@QAE@HPBD0K0PAVCWnd@@@Z; CFileDialog::CFileDialog(int,char const *,char const *,ulong,char const *,CWnd *)
0040175E  8b cb                                         mov     ecx, ebx
00401760  c6 45 fc 02                                   mov     byte ptr [ebp+var_4], 2
00401764  e8 07 fe ff ff                                call    sub_401570
00401769  85 c0                                         test    eax, eax
0040176B  75 09                                         jnz     short loc_401776
0040176D  c6 45 fc 03                                   mov     byte ptr [ebp+var_4], 3
00401771  e9 31 01 00 00                                jmp     loc_4018A7
00401776  8d 8d 94 fd ff ff                             lea     ecx, [ebp+var_26C]; this
0040177C  e8 e5 8e 01 00                                call    ?DoModal@CFileDialog@@UAEHXZ; CFileDialog::DoModal(void)
00401781  83 f8 01                                      cmp     eax, 1
00401784  74 09                                         jz      short loc_40178F
00401786  c6 45 fc 04                                   mov     byte ptr [ebp+var_4], 4
0040178A  e9 18 01 00 00                                jmp     loc_4018A7
0040178F  8d 4d d4                                      lea     ecx, [ebp+var_2C]
00401792  51                                            push    ecx
00401793  8d 8d 94 fd ff ff                             lea     ecx, [ebp+var_26C]
00401799  e8 c2 8e 01 00                                call    ?GetPathName@CFileDialog@@QBE?AVCString@@XZ; CFileDialog::GetPathName(void)
0040179E  8b 00                                         mov     eax, [eax]
004017A0  6a 00                                         push    0; struct CFileException *
004017A2  68 11 50 00 00                                push    5011h; unsigned int
004017A7  50                                            push    eax; char *
004017A8  8d 4d d8                                      lea     ecx, [ebp+var_28]; this
004017AB  c6 45 fc 05                                   mov     byte ptr [ebp+var_4], 5
004017AF  e8 a6 8e 01 00                                call    ?Open@CStdioFile@@UAEHPBDIPAVCFileException@@@Z; CStdioFile::Open(char const *,uint,CFileException *)
004017B4  8d 4d d4                                      lea     ecx, [ebp+var_2C]; this
004017B7  8b f0                                         mov     esi, eax
004017B9  c6 45 fc 02                                   mov     byte ptr [ebp+var_4], 2
004017BD  e8 44 8e 01 00                                call    ??1CString@@QAE@XZ; CString::~CString(void)
004017C2  85 f6                                         test    esi, esi
004017C4  75 15                                         jnz     short loc_4017DB
004017C6  56                                            push    esi; unsigned int
004017C7  56                                            push    esi; unsigned int
004017C8  68 84 f5 41 00                                push    offset byte_41F584; char *
004017CD  e8 40 8e 01 00                                call    ?AfxMessageBox@@YGHPBDII@Z; AfxMessageBox(char const *,uint,uint)
004017D2  c6 45 fc 06                                   mov     byte ptr [ebp+var_4], 6
004017D6  e9 cc 00 00 00                                jmp     loc_4018A7
004017DB  c6 45 fc 07                                   mov     byte ptr [ebp+var_4], 7
004017DF  33 f6                                         xor     esi, esi
004017E1  83 fe 1b                                      cmp     esi, 1Bh
004017E4  0f 8d aa 00 00 00                             jge     loc_401894
004017EA  8b 93 c4 00 00 00                             mov     edx, [ebx+0C4h]
004017F0  8d 4d ec                                      lea     ecx, [ebp+var_14]
004017F3  8b 04 f2                                      mov     eax, [edx+esi*8]
004017F6  50                                            push    eax
004017F7  68 80 f5 41 00                                push    offset aD; "%d\n"
004017FC  51                                            push    ecx; this
004017FD  e8 0a 8e 01 00                                call    ?Format@CString@@QAAXPBDZZ; CString::Format(char const *,...)
00401802  8b 55 ec                                      mov     edx, [ebp+var_14]
00401805  83 c4 0c                                      add     esp, 0Ch
00401808  8d 4d d8                                      lea     ecx, [ebp+var_28]; this
0040180B  52                                            push    edx; char *
0040180C  e8 43 8e 01 00                                call    ?WriteString@CStdioFile@@UAEXPBD@Z; CStdioFile::WriteString(char const *)
00401811  8b 83 c4 00 00 00                             mov     eax, [ebx+0C4h]
00401817  8d 55 ec                                      lea     edx, [ebp+var_14]
0040181A  8b 4c f0 04                                   mov     ecx, [eax+esi*8+4]
0040181E  51                                            push    ecx
0040181F  68 80 f5 41 00                                push    offset aD; "%d\n"
00401824  52                                            push    edx; this
00401825  e8 e2 8d 01 00                                call    ?Format@CString@@QAAXPBDZZ; CString::Format(char const *,...)
0040182A  8b 45 ec                                      mov     eax, [ebp+var_14]
0040182D  83 c4 0c                                      add     esp, 0Ch
00401830  8d 4d d8                                      lea     ecx, [ebp+var_28]; this
00401833  50                                            push    eax; char *
00401834  e8 1b 8e 01 00                                call    ?WriteString@CStdioFile@@UAEXPBD@Z; CStdioFile::WriteString(char const *)
00401839  46                                            inc     esi
0040183A  eb a5                                         jmp     short loc_4017E1
0040183C  8b 4d cc                                      mov     ecx, [ebp+var_34]
0040183F  8b 55 c8                                      mov     edx, [ebp+var_38]
00401842  51                                            push    ecx
00401843  52                                            push    edx
00401844  8d 45 ec                                      lea     eax, [ebp+var_14]
00401847  68 60 f5 41 00                                push    offset byte_41F560; char *
0040184C  50                                            push    eax; this
0040184D  c6 45 fc 09                                   mov     byte ptr [ebp+var_4], 9
00401851  e8 b6 8d 01 00                                call    ?Format@CString@@QAAXPBDZZ; CString::Format(char const *,...)
00401856  8b 4d ec                                      mov     ecx, [ebp+var_14]
00401859  83 c4 10                                      add     esp, 10h
0040185C  6a 00                                         push    0; unsigned int
0040185E  6a 00                                         push    0; unsigned int
00401860  51                                            push    ecx; char *
00401861  e8 ac 8d 01 00                                call    ?AfxMessageBox@@YGHPBDII@Z; AfxMessageBox(char const *,uint,uint)
00401866  8d 4d d8                                      lea     ecx, [ebp+var_28]; this
00401869  e8 e0 8d 01 00                                call    ?Close@CStdioFile@@UAEXXZ; CStdioFile::Close(void)
0040186E  c7 45 c0 84 c5 41 00                          mov     [ebp+var_40], offset off_41C584
00401875  8d 4d d0                                      lea     ecx, [ebp+var_30]; this
00401878  c6 45 fc 0a                                   mov     byte ptr [ebp+var_4], 0Ah
0040187C  e8 85 8d 01 00                                call    ??1CString@@QAE@XZ; CString::~CString(void)
00401881  c7 45 c0 70 c5 41 00                          mov     [ebp+var_40], offset off_41C570
00401888  b8 8e 18 40 00                                mov     eax, offset loc_40188E
0040188D  c3                                            retn
0040188E  c6 45 fc 0b                                   mov     byte ptr [ebp+var_4], 0Bh
00401892  eb 13                                         jmp     short loc_4018A7
00401894  8d 4d d8                                      lea     ecx, [ebp+var_28]; this
00401897  c7 45 fc 02 00 00 00                          mov     [ebp+var_4], 2
0040189E  e8 ab 8d 01 00                                call    ?Close@CStdioFile@@UAEXXZ; CStdioFile::Close(void)
004018A3  c6 45 fc 0c                                   mov     byte ptr [ebp+var_4], 0Ch
004018A7  8d 8d 44 fe ff ff                             lea     ecx, [ebp+var_1BC]; this
004018AD  e8 54 8d 01 00                                call    ??1CString@@QAE@XZ; CString::~CString(void)
004018B2  8d 8d 94 fd ff ff                             lea     ecx, [ebp+var_26C]; this
004018B8  c6 45 fc 01                                   mov     byte ptr [ebp+var_4], 1
004018BC  e8 15 8d 01 00                                call    ??1CDialog@@UAE@XZ; CDialog::~CDialog(void)
004018C1  8d 4d ec                                      lea     ecx, [ebp+var_14]; this
004018C4  c6 45 fc 00                                   mov     byte ptr [ebp+var_4], 0
004018C8  e8 39 8d 01 00                                call    ??1CString@@QAE@XZ; CString::~CString(void)
004018CD  8d 4d d8                                      lea     ecx, [ebp+var_28]; this
004018D0  c7 45 fc ff ff ff ff                          mov     [ebp+var_4], 0FFFFFFFFh
004018D7  e8 6c 8d 01 00                                call    ??1CStdioFile@@UAE@XZ; CStdioFile::~CStdioFile(void)
004018DC  8b 4d f4                                      mov     ecx, [ebp+var_C]
004018DF  5f                                            pop     edi
004018E0  5e                                            pop     esi
004018E1  64 89 0d 00 00 00 00                          mov     large fs:0, ecx
004018E8  5b                                            pop     ebx
004018E9  8b e5                                         mov     esp, ebp
004018EB  5d                                            pop     ebp
004018EC  c3                                            retn
0041AB20  8d 4d d8                                      lea     ecx, [ebp+var_28]; this
0041AB23  e9 20 fb ff ff                                jmp     ??1CStdioFile@@UAE@XZ; CStdioFile::~CStdioFile(void)
0041AB28  8d 4d ec                                      lea     ecx, [ebp+var_14]; this
0041AB2B  e9 d6 fa ff ff                                jmp     ??1CString@@QAE@XZ; CString::~CString(void)
0041AB30  8d 8d 94 fd ff ff                             lea     ecx, [ebp+var_26C]; this
0041AB36  e9 b5 6d fe ff                                jmp     sub_4018F0
0041AB3B  8d 8d 94 fd ff ff                             lea     ecx, [ebp+var_26C]; this
0041AB41  e9 1a 6f fe ff                                jmp     j_??1CDialog@@UAE@XZ; CDialog::~CDialog(void)
0041AB46  8d 8d 94 fd ff ff                             lea     ecx, [ebp+var_26C]; this
0041AB4C  e9 0f 6f fe ff                                jmp     j_??1CDialog@@UAE@XZ; CDialog::~CDialog(void)
0041AB51  8d 4d d4                                      lea     ecx, [ebp+var_2C]; this
0041AB54  e9 ad fa ff ff                                jmp     ??1CString@@QAE@XZ; CString::~CString(void)
0041AB59  8d 8d 94 fd ff ff                             lea     ecx, [ebp+var_26C]; this
0041AB5F  e9 fc 6e fe ff                                jmp     j_??1CDialog@@UAE@XZ; CDialog::~CDialog(void)
0041AB64  8d 4d c0                                      lea     ecx, [ebp+var_40]
0041AB67  e9 64 6e fe ff                                jmp     sub_4019D0
0041AB6C  8d 4d c0                                      lea     ecx, [ebp+var_40]
0041AB6F  e9 2c 6e fe ff                                jmp     sub_4019A0
0041AB74  8d 8d 94 fd ff ff                             lea     ecx, [ebp+var_26C]; this
0041AB7A  e9 e1 6e fe ff                                jmp     j_??1CDialog@@UAE@XZ; CDialog::~CDialog(void)
0041AB7F  8d 8d 94 fd ff ff                             lea     ecx, [ebp+var_26C]; this
0041AB85  e9 d6 6e fe ff                                jmp     j_??1CDialog@@UAE@XZ; CDialog::~CDialog(void)
0041AB8A  b8 f0 d1 41 00                                mov     eax, offset stru_41D1F0
0041AB8F  e9 88 fc ff ff                                jmp     __CxxFrameHandler
