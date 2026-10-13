00403780  55                                            push    ebp
00403781  8b ec                                         mov     ebp, esp
00403783  6a ff                                         push    0FFFFFFFFh
00403785  68 4a ae 41 00                                push    offset SEH_403780
0040378A  64 a1 00 00 00 00                             mov     eax, large fs:0
00403790  50                                            push    eax
00403791  64 89 25 00 00 00 00                          mov     large fs:0, esp
00403798  81 ec 60 02 00 00                             sub     esp, 260h
0040379E  53                                            push    ebx
0040379F  56                                            push    esi
004037A0  8b d9                                         mov     ebx, ecx
004037A2  57                                            push    edi
004037A3  8d 4d d8                                      lea     ecx, [ebp+var_28]; this
004037A6  89 65 f0                                      mov     [ebp+var_10], esp
004037A9  e8 c4 6e 01 00                                call    ??0CStdioFile@@QAE@XZ; CStdioFile::CStdioFile(void)
004037AE  8d 4d ec                                      lea     ecx, [ebp+var_14]; this
004037B1  c7 45 fc 00 00 00 00                          mov     [ebp+var_4], 0
004037B8  e8 61 6e 01 00                                call    ??0CString@@QAE@XZ; CString::CString(void)
004037BD  b9 0b 00 00 00                                mov     ecx, 0Bh
004037C2  be b0 f5 41 00                                mov     esi, offset aTextFilesTxtTx; "Text Files (*.txt)|*.txt|All Files (*.*"...
004037C7  8d 7d 90                                      lea     edi, [ebp+var_70]
004037CA  8d 45 90                                      lea     eax, [ebp+var_70]
004037CD  f3 a5                                         rep movsd
004037CF  53                                            push    ebx; struct CWnd *
004037D0  50                                            push    eax; char *
004037D1  66 a5                                         movsw
004037D3  6a 06                                         push    6; unsigned int
004037D5  68 f8 f6 41 00                                push    offset aSan9pkhardpara; "San9PKHardPara.txt"
004037DA  6a 00                                         push    0; char *
004037DC  6a 00                                         push    0; int
004037DE  8d 8d 94 fd ff ff                             lea     ecx, [ebp+var_26C]; this
004037E4  c6 45 fc 01                                   mov     byte ptr [ebp+var_4], 1
004037E8  a4                                            movsb
004037E9  e8 7e 6e 01 00                                call    ??0CFileDialog@@QAE@HPBD0K0PAVCWnd@@@Z; CFileDialog::CFileDialog(int,char const *,char const *,ulong,char const *,CWnd *)
004037EE  8b cb                                         mov     ecx, ebx; this
004037F0  c6 45 fc 02                                   mov     byte ptr [ebp+var_4], 2
004037F4  e8 f7 07 00 00                                call    sub_403FF0
004037F9  84 c0                                         test    al, al
004037FB  75 09                                         jnz     short loc_403806
004037FD  c6 45 fc 03                                   mov     byte ptr [ebp+var_4], 3
00403801  e9 a0 07 00 00                                jmp     loc_403FA6
00403806  8d 8d 94 fd ff ff                             lea     ecx, [ebp+var_26C]; this
0040380C  e8 55 6e 01 00                                call    ?DoModal@CFileDialog@@UAEHXZ; CFileDialog::DoModal(void)
00403811  83 f8 01                                      cmp     eax, 1
00403814  74 09                                         jz      short loc_40381F
00403816  c6 45 fc 04                                   mov     byte ptr [ebp+var_4], 4
0040381A  e9 87 07 00 00                                jmp     loc_403FA6
0040381F  8d 4d d4                                      lea     ecx, [ebp+var_2C]
00403822  51                                            push    ecx
00403823  8d 8d 94 fd ff ff                             lea     ecx, [ebp+var_26C]
00403829  e8 32 6e 01 00                                call    ?GetPathName@CFileDialog@@QBE?AVCString@@XZ; CFileDialog::GetPathName(void)
0040382E  8b 00                                         mov     eax, [eax]
00403830  6a 00                                         push    0; struct CFileException *
00403832  68 11 50 00 00                                push    5011h; unsigned int
00403837  50                                            push    eax; char *
00403838  8d 4d d8                                      lea     ecx, [ebp+var_28]; this
0040383B  c6 45 fc 05                                   mov     byte ptr [ebp+var_4], 5
0040383F  e8 16 6e 01 00                                call    ?Open@CStdioFile@@UAEHPBDIPAVCFileException@@@Z; CStdioFile::Open(char const *,uint,CFileException *)
00403844  8d 4d d4                                      lea     ecx, [ebp+var_2C]; this
00403847  8b f0                                         mov     esi, eax
00403849  c6 45 fc 02                                   mov     byte ptr [ebp+var_4], 2
0040384D  e8 b4 6d 01 00                                call    ??1CString@@QAE@XZ; CString::~CString(void)
00403852  85 f6                                         test    esi, esi
00403854  75 15                                         jnz     short loc_40386B
00403856  56                                            push    esi; unsigned int
00403857  56                                            push    esi; unsigned int
00403858  68 e0 f6 41 00                                push    offset byte_41F6E0; char *
0040385D  e8 b0 6d 01 00                                call    ?AfxMessageBox@@YGHPBDII@Z; AfxMessageBox(char const *,uint,uint)
00403862  c6 45 fc 06                                   mov     byte ptr [ebp+var_4], 6
00403866  e9 3b 07 00 00                                jmp     loc_403FA6
0040386B  8b 53 78                                      mov     edx, [ebx+78h]
0040386E  8d 45 ec                                      lea     eax, [ebp+var_14]
00403871  52                                            push    edx
00403872  68 80 f5 41 00                                push    offset aD; "%d\n"
00403877  50                                            push    eax; this
00403878  c6 45 fc 07                                   mov     byte ptr [ebp+var_4], 7
0040387C  e8 8b 6d 01 00                                call    ?Format@CString@@QAAXPBDZZ; CString::Format(char const *,...)
00403881  8b 4d ec                                      mov     ecx, [ebp+var_14]
00403884  83 c4 0c                                      add     esp, 0Ch
00403887  51                                            push    ecx; char *
00403888  8d 4d d8                                      lea     ecx, [ebp+var_28]; this
0040388B  e8 c4 6d 01 00                                call    ?WriteString@CStdioFile@@UAEXPBD@Z; CStdioFile::WriteString(char const *)
00403890  8b 53 7c                                      mov     edx, [ebx+7Ch]
00403893  8d 45 ec                                      lea     eax, [ebp+var_14]
00403896  52                                            push    edx
00403897  68 80 f5 41 00                                push    offset aD; "%d\n"
0040389C  50                                            push    eax; this
0040389D  e8 6a 6d 01 00                                call    ?Format@CString@@QAAXPBDZZ; CString::Format(char const *,...)
004038A2  8b 4d ec                                      mov     ecx, [ebp+var_14]
004038A5  83 c4 0c                                      add     esp, 0Ch
004038A8  51                                            push    ecx; char *
004038A9  8d 4d d8                                      lea     ecx, [ebp+var_28]; this
004038AC  e8 a3 6d 01 00                                call    ?WriteString@CStdioFile@@UAEXPBD@Z; CStdioFile::WriteString(char const *)
004038B1  8b 93 80 00 00 00                             mov     edx, [ebx+80h]
004038B7  8d 45 ec                                      lea     eax, [ebp+var_14]
004038BA  52                                            push    edx
004038BB  68 80 f5 41 00                                push    offset aD; "%d\n"
004038C0  50                                            push    eax; this
004038C1  e8 46 6d 01 00                                call    ?Format@CString@@QAAXPBDZZ; CString::Format(char const *,...)
004038C6  8b 4d ec                                      mov     ecx, [ebp+var_14]
004038C9  83 c4 0c                                      add     esp, 0Ch
004038CC  51                                            push    ecx; char *
004038CD  8d 4d d8                                      lea     ecx, [ebp+var_28]; this
004038D0  e8 7f 6d 01 00                                call    ?WriteString@CStdioFile@@UAEXPBD@Z; CStdioFile::WriteString(char const *)
004038D5  8b 53 6c                                      mov     edx, [ebx+6Ch]
004038D8  8d 45 ec                                      lea     eax, [ebp+var_14]
004038DB  52                                            push    edx
004038DC  68 80 f5 41 00                                push    offset aD; "%d\n"
004038E1  50                                            push    eax; this
004038E2  e8 25 6d 01 00                                call    ?Format@CString@@QAAXPBDZZ; CString::Format(char const *,...)
004038E7  8b 4d ec                                      mov     ecx, [ebp+var_14]
004038EA  83 c4 0c                                      add     esp, 0Ch
004038ED  51                                            push    ecx; char *
004038EE  8d 4d d8                                      lea     ecx, [ebp+var_28]; this
004038F1  e8 5e 6d 01 00                                call    ?WriteString@CStdioFile@@UAEXPBD@Z; CStdioFile::WriteString(char const *)
004038F6  8b 53 70                                      mov     edx, [ebx+70h]
004038F9  8d 45 ec                                      lea     eax, [ebp+var_14]
004038FC  52                                            push    edx
004038FD  68 80 f5 41 00                                push    offset aD; "%d\n"
00403902  50                                            push    eax; this
00403903  e8 04 6d 01 00                                call    ?Format@CString@@QAAXPBDZZ; CString::Format(char const *,...)
00403908  8b 4d ec                                      mov     ecx, [ebp+var_14]
0040390B  83 c4 0c                                      add     esp, 0Ch
0040390E  51                                            push    ecx; char *
0040390F  8d 4d d8                                      lea     ecx, [ebp+var_28]; this
00403912  e8 3d 6d 01 00                                call    ?WriteString@CStdioFile@@UAEXPBD@Z; CStdioFile::WriteString(char const *)
00403917  8b 53 74                                      mov     edx, [ebx+74h]
0040391A  8d 45 ec                                      lea     eax, [ebp+var_14]
0040391D  52                                            push    edx
0040391E  68 80 f5 41 00                                push    offset aD; "%d\n"
00403923  50                                            push    eax; this
00403924  e8 e3 6c 01 00                                call    ?Format@CString@@QAAXPBDZZ; CString::Format(char const *,...)
00403929  8b 4d ec                                      mov     ecx, [ebp+var_14]
0040392C  83 c4 0c                                      add     esp, 0Ch
0040392F  51                                            push    ecx; char *
00403930  8d 4d d8                                      lea     ecx, [ebp+var_28]; this
00403933  e8 1c 6d 01 00                                call    ?WriteString@CStdioFile@@UAEXPBD@Z; CStdioFile::WriteString(char const *)
00403938  8b 53 64                                      mov     edx, [ebx+64h]
0040393B  8d 45 ec                                      lea     eax, [ebp+var_14]
0040393E  52                                            push    edx
0040393F  68 80 f5 41 00                                push    offset aD; "%d\n"
00403944  50                                            push    eax; this
00403945  e8 c2 6c 01 00                                call    ?Format@CString@@QAAXPBDZZ; CString::Format(char const *,...)
0040394A  8b 4d ec                                      mov     ecx, [ebp+var_14]
0040394D  83 c4 0c                                      add     esp, 0Ch
00403950  51                                            push    ecx; char *
00403951  8d 4d d8                                      lea     ecx, [ebp+var_28]; this
00403954  e8 fb 6c 01 00                                call    ?WriteString@CStdioFile@@UAEXPBD@Z; CStdioFile::WriteString(char const *)
00403959  8b 53 60                                      mov     edx, [ebx+60h]
0040395C  52                                            push    edx
0040395D  68 80 f5 41 00                                push    offset aD; "%d\n"
00403962  8d 45 ec                                      lea     eax, [ebp+var_14]
00403965  50                                            push    eax; this
00403966  e8 a1 6c 01 00                                call    ?Format@CString@@QAAXPBDZZ; CString::Format(char const *,...)
0040396B  8b 4d ec                                      mov     ecx, [ebp+var_14]
0040396E  83 c4 0c                                      add     esp, 0Ch
00403971  51                                            push    ecx; char *
00403972  8d 4d d8                                      lea     ecx, [ebp+var_28]; this
00403975  e8 da 6c 01 00                                call    ?WriteString@CStdioFile@@UAEXPBD@Z; CStdioFile::WriteString(char const *)
0040397A  8b 53 68                                      mov     edx, [ebx+68h]
0040397D  8d 45 ec                                      lea     eax, [ebp+var_14]
00403980  52                                            push    edx
00403981  68 80 f5 41 00                                push    offset aD; "%d\n"
00403986  50                                            push    eax; this
00403987  e8 80 6c 01 00                                call    ?Format@CString@@QAAXPBDZZ; CString::Format(char const *,...)
0040398C  8b 4d ec                                      mov     ecx, [ebp+var_14]
0040398F  83 c4 0c                                      add     esp, 0Ch
00403992  51                                            push    ecx; char *
00403993  8d 4d d8                                      lea     ecx, [ebp+var_28]; this
00403996  e8 b9 6c 01 00                                call    ?WriteString@CStdioFile@@UAEXPBD@Z; CStdioFile::WriteString(char const *)
0040399B  8b 93 10 01 00 00                             mov     edx, [ebx+110h]
004039A1  8d 45 ec                                      lea     eax, [ebp+var_14]
004039A4  52                                            push    edx
004039A5  68 80 f5 41 00                                push    offset aD; "%d\n"
004039AA  50                                            push    eax; this
004039AB  e8 5c 6c 01 00                                call    ?Format@CString@@QAAXPBDZZ; CString::Format(char const *,...)
004039B0  8b 4d ec                                      mov     ecx, [ebp+var_14]
004039B3  83 c4 0c                                      add     esp, 0Ch
004039B6  51                                            push    ecx; char *
004039B7  8d 4d d8                                      lea     ecx, [ebp+var_28]; this
004039BA  e8 95 6c 01 00                                call    ?WriteString@CStdioFile@@UAEXPBD@Z; CStdioFile::WriteString(char const *)
004039BF  8b 93 14 01 00 00                             mov     edx, [ebx+114h]
004039C5  8d 45 ec                                      lea     eax, [ebp+var_14]
004039C8  52                                            push    edx
004039C9  68 80 f5 41 00                                push    offset aD; "%d\n"
004039CE  50                                            push    eax; this
004039CF  e8 38 6c 01 00                                call    ?Format@CString@@QAAXPBDZZ; CString::Format(char const *,...)
004039D4  8b 4d ec                                      mov     ecx, [ebp+var_14]
004039D7  83 c4 0c                                      add     esp, 0Ch
004039DA  51                                            push    ecx; char *
004039DB  8d 4d d8                                      lea     ecx, [ebp+var_28]; this
004039DE  e8 71 6c 01 00                                call    ?WriteString@CStdioFile@@UAEXPBD@Z; CStdioFile::WriteString(char const *)
004039E3  8b 93 18 01 00 00                             mov     edx, [ebx+118h]
004039E9  8d 45 ec                                      lea     eax, [ebp+var_14]
004039EC  52                                            push    edx
004039ED  68 80 f5 41 00                                push    offset aD; "%d\n"
004039F2  50                                            push    eax; this
004039F3  e8 14 6c 01 00                                call    ?Format@CString@@QAAXPBDZZ; CString::Format(char const *,...)
004039F8  8b 4d ec                                      mov     ecx, [ebp+var_14]
004039FB  83 c4 0c                                      add     esp, 0Ch
004039FE  51                                            push    ecx; char *
004039FF  8d 4d d8                                      lea     ecx, [ebp+var_28]; this
00403A02  e8 4d 6c 01 00                                call    ?WriteString@CStdioFile@@UAEXPBD@Z; CStdioFile::WriteString(char const *)
00403A07  8b 93 1c 01 00 00                             mov     edx, [ebx+11Ch]
00403A0D  8d 45 ec                                      lea     eax, [ebp+var_14]
00403A10  52                                            push    edx
00403A11  68 80 f5 41 00                                push    offset aD; "%d\n"
00403A16  50                                            push    eax; this
00403A17  e8 f0 6b 01 00                                call    ?Format@CString@@QAAXPBDZZ; CString::Format(char const *,...)
00403A1C  8b 4d ec                                      mov     ecx, [ebp+var_14]
00403A1F  83 c4 0c                                      add     esp, 0Ch
00403A22  51                                            push    ecx; char *
00403A23  8d 4d d8                                      lea     ecx, [ebp+var_28]; this
00403A26  e8 29 6c 01 00                                call    ?WriteString@CStdioFile@@UAEXPBD@Z; CStdioFile::WriteString(char const *)
00403A2B  8b 93 54 01 00 00                             mov     edx, [ebx+154h]
00403A31  8d 45 ec                                      lea     eax, [ebp+var_14]
00403A34  52                                            push    edx
00403A35  68 80 f5 41 00                                push    offset aD; "%d\n"
00403A3A  50                                            push    eax; this
00403A3B  e8 cc 6b 01 00                                call    ?Format@CString@@QAAXPBDZZ; CString::Format(char const *,...)
00403A40  8b 4d ec                                      mov     ecx, [ebp+var_14]
00403A43  83 c4 0c                                      add     esp, 0Ch
00403A46  51                                            push    ecx; char *
00403A47  8d 4d d8                                      lea     ecx, [ebp+var_28]; this
00403A4A  e8 05 6c 01 00                                call    ?WriteString@CStdioFile@@UAEXPBD@Z; CStdioFile::WriteString(char const *)
00403A4F  8b 83 bc 01 00 00                             mov     eax, [ebx+1BCh]
00403A55  8b 93 b8 01 00 00                             mov     edx, [ebx+1B8h]
00403A5B  8b bb b4 01 00 00                             mov     edi, [ebx+1B4h]
00403A61  d1 e0                                         shl     eax, 1
00403A63  0b c2                                         or      eax, edx
00403A65  d1 e0                                         shl     eax, 1
00403A67  0b c7                                         or      eax, edi
00403A69  8b 93 b0 01 00 00                             mov     edx, [ebx+1B0h]
00403A6F  8b bb ac 01 00 00                             mov     edi, [ebx+1ACh]
00403A75  d1 e0                                         shl     eax, 1
00403A77  0b c2                                         or      eax, edx
00403A79  8b 93 a8 01 00 00                             mov     edx, [ebx+1A8h]
00403A7F  d1 e0                                         shl     eax, 1
00403A81  0b c7                                         or      eax, edi
00403A83  8b bb a4 01 00 00                             mov     edi, [ebx+1A4h]
00403A89  d1 e0                                         shl     eax, 1
00403A8B  0b c2                                         or      eax, edx
00403A8D  8b 93 a0 01 00 00                             mov     edx, [ebx+1A0h]
00403A93  d1 e0                                         shl     eax, 1
00403A95  0b c7                                         or      eax, edi
00403A97  8b bb 90 01 00 00                             mov     edi, [ebx+190h]
00403A9D  d1 e0                                         shl     eax, 1
00403A9F  0b c2                                         or      eax, edx
00403AA1  8b 93 60 01 00 00                             mov     edx, [ebx+160h]
00403AA7  d1 e0                                         shl     eax, 1
00403AA9  0b c7                                         or      eax, edi
00403AAB  8b bb 58 01 00 00                             mov     edi, [ebx+158h]
00403AB1  d1 e0                                         shl     eax, 1
00403AB3  0b c2                                         or      eax, edx
00403AB5  8b 93 4c 01 00 00                             mov     edx, [ebx+14Ch]
00403ABB  d1 e0                                         shl     eax, 1
00403ABD  0b c7                                         or      eax, edi
00403ABF  8b bb 44 01 00 00                             mov     edi, [ebx+144h]
00403AC5  d1 e0                                         shl     eax, 1
00403AC7  0b c2                                         or      eax, edx
00403AC9  8b 93 0c 01 00 00                             mov     edx, [ebx+10Ch]
00403ACF  d1 e0                                         shl     eax, 1
00403AD1  0b c7                                         or      eax, edi
00403AD3  8b bb 04 01 00 00                             mov     edi, [ebx+104h]
00403AD9  d1 e0                                         shl     eax, 1
00403ADB  0b c2                                         or      eax, edx
00403ADD  8b 93 ec 00 00 00                             mov     edx, [ebx+0ECh]
00403AE3  d1 e0                                         shl     eax, 1
00403AE5  0b c7                                         or      eax, edi
00403AE7  8b bb f4 00 00 00                             mov     edi, [ebx+0F4h]
00403AED  d1 e0                                         shl     eax, 1
00403AEF  0b c2                                         or      eax, edx
00403AF1  8b 93 e8 00 00 00                             mov     edx, [ebx+0E8h]
00403AF7  d1 e0                                         shl     eax, 1
00403AF9  0b c7                                         or      eax, edi
00403AFB  8b bb d4 00 00 00                             mov     edi, [ebx+0D4h]
00403B01  d1 e0                                         shl     eax, 1
00403B03  0b c2                                         or      eax, edx
00403B05  8b 93 cc 00 00 00                             mov     edx, [ebx+0CCh]
00403B0B  d1 e0                                         shl     eax, 1
00403B0D  0b c7                                         or      eax, edi
00403B0F  8b bb c0 00 00 00                             mov     edi, [ebx+0C0h]
00403B15  d1 e0                                         shl     eax, 1
00403B17  0b c2                                         or      eax, edx
00403B19  8b 93 bc 00 00 00                             mov     edx, [ebx+0BCh]
00403B1F  d1 e0                                         shl     eax, 1
00403B21  0b c7                                         or      eax, edi
00403B23  8b bb 9c 00 00 00                             mov     edi, [ebx+9Ch]
00403B29  d1 e0                                         shl     eax, 1
00403B2B  0b c2                                         or      eax, edx
00403B2D  8b 93 7c 01 00 00                             mov     edx, [ebx+17Ch]
00403B33  d1 e0                                         shl     eax, 1
00403B35  0b c7                                         or      eax, edi
00403B37  8b bb 80 01 00 00                             mov     edi, [ebx+180h]
00403B3D  d1 e0                                         shl     eax, 1
00403B3F  0b c2                                         or      eax, edx
00403B41  8d 55 ec                                      lea     edx, [ebp+var_14]
00403B44  d1 e0                                         shl     eax, 1
00403B46  0b c7                                         or      eax, edi
00403B48  50                                            push    eax
00403B49  68 80 f5 41 00                                push    offset aD; "%d\n"
00403B4E  52                                            push    edx; this
00403B4F  e8 b8 6a 01 00                                call    ?Format@CString@@QAAXPBDZZ; CString::Format(char const *,...)
00403B54  8b 45 ec                                      mov     eax, [ebp+var_14]
00403B57  83 c4 0c                                      add     esp, 0Ch
00403B5A  8d 4d d8                                      lea     ecx, [ebp+var_28]; this
00403B5D  50                                            push    eax; char *
00403B5E  e8 f1 6a 01 00                                call    ?WriteString@CStdioFile@@UAEXPBD@Z; CStdioFile::WriteString(char const *)
00403B63  8b 83 98 01 00 00                             mov     eax, [ebx+198h]
00403B69  8b b3 94 01 00 00                             mov     esi, [ebx+194h]
00403B6F  d1 e0                                         shl     eax, 1
00403B71  0b c6                                         or      eax, esi
00403B73  d1 e0                                         shl     eax, 1
00403B75  8b 8b 88 01 00 00                             mov     ecx, [ebx+188h]
00403B7B  8b b3 78 01 00 00                             mov     esi, [ebx+178h]
00403B81  0b c1                                         or      eax, ecx
00403B83  8b 8b 74 01 00 00                             mov     ecx, [ebx+174h]
00403B89  d1 e0                                         shl     eax, 1
00403B8B  0b c6                                         or      eax, esi
00403B8D  8b b3 64 01 00 00                             mov     esi, [ebx+164h]
00403B93  d1 e0                                         shl     eax, 1
00403B95  0b c1                                         or      eax, ecx
00403B97  8b 8b 48 01 00 00                             mov     ecx, [ebx+148h]
00403B9D  d1 e0                                         shl     eax, 1
00403B9F  0b c6                                         or      eax, esi
00403BA1  8b b3 40 01 00 00                             mov     esi, [ebx+140h]
00403BA7  d1 e0                                         shl     eax, 1
00403BA9  0b c1                                         or      eax, ecx
00403BAB  8b 8b 3c 01 00 00                             mov     ecx, [ebx+13Ch]
00403BB1  d1 e0                                         shl     eax, 1
00403BB3  0b c6                                         or      eax, esi
00403BB5  8b b3 38 01 00 00                             mov     esi, [ebx+138h]
00403BBB  d1 e0                                         shl     eax, 1
00403BBD  0b c1                                         or      eax, ecx
00403BBF  8b 8b 08 01 00 00                             mov     ecx, [ebx+108h]
00403BC5  d1 e0                                         shl     eax, 1
00403BC7  0b c6                                         or      eax, esi
00403BC9  8b b3 00 01 00 00                             mov     esi, [ebx+100h]
00403BCF  d1 e0                                         shl     eax, 1
00403BD1  0b c1                                         or      eax, ecx
00403BD3  8b 8b f8 00 00 00                             mov     ecx, [ebx+0F8h]
00403BD9  d1 e0                                         shl     eax, 1
00403BDB  0b c6                                         or      eax, esi
00403BDD  8b b3 f0 00 00 00                             mov     esi, [ebx+0F0h]
00403BE3  d1 e0                                         shl     eax, 1
00403BE5  0b c1                                         or      eax, ecx
00403BE7  8b 8b dc 00 00 00                             mov     ecx, [ebx+0DCh]
00403BED  d1 e0                                         shl     eax, 1
00403BEF  0b c6                                         or      eax, esi
00403BF1  8b b3 84 00 00 00                             mov     esi, [ebx+84h]
00403BF7  d1 e0                                         shl     eax, 1
00403BF9  0b c1                                         or      eax, ecx
00403BFB  8b 8b c8 00 00 00                             mov     ecx, [ebx+0C8h]
00403C01  d1 e0                                         shl     eax, 1
00403C03  0b c6                                         or      eax, esi
00403C05  8b b3 c4 00 00 00                             mov     esi, [ebx+0C4h]
00403C0B  d1 e0                                         shl     eax, 1
00403C0D  0b c1                                         or      eax, ecx
00403C0F  8b 8b b8 00 00 00                             mov     ecx, [ebx+0B8h]
00403C15  d1 e0                                         shl     eax, 1
00403C17  0b c6                                         or      eax, esi
00403C19  8b b3 b4 00 00 00                             mov     esi, [ebx+0B4h]
00403C1F  d1 e0                                         shl     eax, 1
00403C21  0b c1                                         or      eax, ecx
00403C23  8b 8b b0 00 00 00                             mov     ecx, [ebx+0B0h]
00403C29  d1 e0                                         shl     eax, 1
00403C2B  0b c6                                         or      eax, esi
00403C2D  8b b3 ac 00 00 00                             mov     esi, [ebx+0ACh]
00403C33  d1 e0                                         shl     eax, 1
00403C35  0b c1                                         or      eax, ecx
00403C37  8b 8b a4 00 00 00                             mov     ecx, [ebx+0A4h]
00403C3D  d1 e0                                         shl     eax, 1
00403C3F  0b c6                                         or      eax, esi
00403C41  8b b3 a0 00 00 00                             mov     esi, [ebx+0A0h]
00403C47  d1 e0                                         shl     eax, 1
00403C49  0b c1                                         or      eax, ecx
00403C4B  8b 8b d0 00 00 00                             mov     ecx, [ebx+0D0h]
00403C51  d1 e0                                         shl     eax, 1
00403C53  0b c6                                         or      eax, esi
00403C55  8b b3 90 00 00 00                             mov     esi, [ebx+90h]
00403C5B  d1 e0                                         shl     eax, 1
00403C5D  0b c1                                         or      eax, ecx
00403C5F  8b 8b 98 00 00 00                             mov     ecx, [ebx+98h]
00403C65  d1 e0                                         shl     eax, 1
00403C67  0b c6                                         or      eax, esi
00403C69  8b b3 8c 00 00 00                             mov     esi, [ebx+8Ch]
00403C6F  d1 e0                                         shl     eax, 1
00403C71  0b c1                                         or      eax, ecx
00403C73  8b 8b 94 00 00 00                             mov     ecx, [ebx+94h]
00403C79  d1 e0                                         shl     eax, 1
00403C7B  0b c6                                         or      eax, esi
00403C7D  d1 e0                                         shl     eax, 1
00403C7F  0b c1                                         or      eax, ecx
00403C81  d1 e0                                         shl     eax, 1
00403C83  8b b3 88 00 00 00                             mov     esi, [ebx+88h]
00403C89  8b 8b 5c 01 00 00                             mov     ecx, [ebx+15Ch]
00403C8F  0b c6                                         or      eax, esi
00403C91  d1 e0                                         shl     eax, 1
00403C93  0b c1                                         or      eax, ecx
00403C95  8d 4d ec                                      lea     ecx, [ebp+var_14]
00403C98  50                                            push    eax
00403C99  68 80 f5 41 00                                push    offset aD; "%d\n"
00403C9E  51                                            push    ecx; this
00403C9F  e8 68 69 01 00                                call    ?Format@CString@@QAAXPBDZZ; CString::Format(char const *,...)
00403CA4  8b 55 ec                                      mov     edx, [ebp+var_14]
00403CA7  83 c4 0c                                      add     esp, 0Ch
00403CAA  8d 4d d8                                      lea     ecx, [ebp+var_28]; this
00403CAD  52                                            push    edx; char *
00403CAE  e8 a1 69 01 00                                call    ?WriteString@CStdioFile@@UAEXPBD@Z; CStdioFile::WriteString(char const *)
00403CB3  8b 83 a8 00 00 00                             mov     eax, [ebx+0A8h]
00403CB9  8d 4d ec                                      lea     ecx, [ebp+var_14]
00403CBC  50                                            push    eax
00403CBD  68 80 f5 41 00                                push    offset aD; "%d\n"
00403CC2  51                                            push    ecx; this
00403CC3  e8 44 69 01 00                                call    ?Format@CString@@QAAXPBDZZ; CString::Format(char const *,...)
00403CC8  8b 55 ec                                      mov     edx, [ebp+var_14]
00403CCB  83 c4 0c                                      add     esp, 0Ch
00403CCE  8d 4d d8                                      lea     ecx, [ebp+var_28]; this
00403CD1  52                                            push    edx; char *
00403CD2  e8 7d 69 01 00                                call    ?WriteString@CStdioFile@@UAEXPBD@Z; CStdioFile::WriteString(char const *)
00403CD7  8b 83 d8 00 00 00                             mov     eax, [ebx+0D8h]
00403CDD  8d 4d ec                                      lea     ecx, [ebp+var_14]
00403CE0  50                                            push    eax
00403CE1  68 80 f5 41 00                                push    offset aD; "%d\n"
00403CE6  51                                            push    ecx; this
00403CE7  e8 20 69 01 00                                call    ?Format@CString@@QAAXPBDZZ; CString::Format(char const *,...)
00403CEC  8b 55 ec                                      mov     edx, [ebp+var_14]
00403CEF  83 c4 0c                                      add     esp, 0Ch
00403CF2  8d 4d d8                                      lea     ecx, [ebp+var_28]; this
00403CF5  52                                            push    edx; char *
00403CF6  e8 59 69 01 00                                call    ?WriteString@CStdioFile@@UAEXPBD@Z; CStdioFile::WriteString(char const *)
00403CFB  8b 83 e0 00 00 00                             mov     eax, [ebx+0E0h]
00403D01  8d 4d ec                                      lea     ecx, [ebp+var_14]
00403D04  50                                            push    eax
00403D05  68 80 f5 41 00                                push    offset aD; "%d\n"
00403D0A  51                                            push    ecx; this
00403D0B  e8 fc 68 01 00                                call    ?Format@CString@@QAAXPBDZZ; CString::Format(char const *,...)
00403D10  8b 55 ec                                      mov     edx, [ebp+var_14]
00403D13  83 c4 0c                                      add     esp, 0Ch
00403D16  8d 4d d8                                      lea     ecx, [ebp+var_28]; this
00403D19  52                                            push    edx; char *
00403D1A  e8 35 69 01 00                                call    ?WriteString@CStdioFile@@UAEXPBD@Z; CStdioFile::WriteString(char const *)
00403D1F  8b 83 e4 00 00 00                             mov     eax, [ebx+0E4h]
00403D25  8d 4d ec                                      lea     ecx, [ebp+var_14]
00403D28  50                                            push    eax
00403D29  68 80 f5 41 00                                push    offset aD; "%d\n"
00403D2E  51                                            push    ecx; this
00403D2F  e8 d8 68 01 00                                call    ?Format@CString@@QAAXPBDZZ; CString::Format(char const *,...)
00403D34  8b 55 ec                                      mov     edx, [ebp+var_14]
00403D37  83 c4 0c                                      add     esp, 0Ch
00403D3A  8d 4d d8                                      lea     ecx, [ebp+var_28]; this
00403D3D  52                                            push    edx; char *
00403D3E  e8 11 69 01 00                                call    ?WriteString@CStdioFile@@UAEXPBD@Z; CStdioFile::WriteString(char const *)
00403D43  8b 83 fc 00 00 00                             mov     eax, [ebx+0FCh]
00403D49  8d 4d ec                                      lea     ecx, [ebp+var_14]
00403D4C  50                                            push    eax
00403D4D  68 80 f5 41 00                                push    offset aD; "%d\n"
00403D52  51                                            push    ecx; this
00403D53  e8 b4 68 01 00                                call    ?Format@CString@@QAAXPBDZZ; CString::Format(char const *,...)
00403D58  8b 55 ec                                      mov     edx, [ebp+var_14]
00403D5B  83 c4 0c                                      add     esp, 0Ch
00403D5E  8d 4d d8                                      lea     ecx, [ebp+var_28]; this
00403D61  52                                            push    edx; char *
00403D62  e8 ed 68 01 00                                call    ?WriteString@CStdioFile@@UAEXPBD@Z; CStdioFile::WriteString(char const *)
00403D67  8b 83 20 01 00 00                             mov     eax, [ebx+120h]
00403D6D  8d 4d ec                                      lea     ecx, [ebp+var_14]
00403D70  50                                            push    eax
00403D71  68 80 f5 41 00                                push    offset aD; "%d\n"
00403D76  51                                            push    ecx; this
00403D77  e8 90 68 01 00                                call    ?Format@CString@@QAAXPBDZZ; CString::Format(char const *,...)
00403D7C  8b 55 ec                                      mov     edx, [ebp+var_14]
00403D7F  83 c4 0c                                      add     esp, 0Ch
00403D82  8d 4d d8                                      lea     ecx, [ebp+var_28]; this
00403D85  52                                            push    edx; char *
00403D86  e8 c9 68 01 00                                call    ?WriteString@CStdioFile@@UAEXPBD@Z; CStdioFile::WriteString(char const *)
00403D8B  8b 83 50 01 00 00                             mov     eax, [ebx+150h]
00403D91  8d 4d ec                                      lea     ecx, [ebp+var_14]
00403D94  50                                            push    eax
00403D95  68 80 f5 41 00                                push    offset aD; "%d\n"
00403D9A  51                                            push    ecx; this
00403D9B  e8 6c 68 01 00                                call    ?Format@CString@@QAAXPBDZZ; CString::Format(char const *,...)
00403DA0  8b 55 ec                                      mov     edx, [ebp+var_14]
00403DA3  83 c4 0c                                      add     esp, 0Ch
00403DA6  8d 4d d8                                      lea     ecx, [ebp+var_28]; this
00403DA9  52                                            push    edx; char *
00403DAA  e8 a5 68 01 00                                call    ?WriteString@CStdioFile@@UAEXPBD@Z; CStdioFile::WriteString(char const *)
00403DAF  8b 83 2c 01 00 00                             mov     eax, [ebx+12Ch]
00403DB5  8d 4d ec                                      lea     ecx, [ebp+var_14]
00403DB8  50                                            push    eax
00403DB9  68 80 f5 41 00                                push    offset aD; "%d\n"
00403DBE  51                                            push    ecx; this
00403DBF  e8 48 68 01 00                                call    ?Format@CString@@QAAXPBDZZ; CString::Format(char const *,...)
00403DC4  8b 55 ec                                      mov     edx, [ebp+var_14]
00403DC7  83 c4 0c                                      add     esp, 0Ch
00403DCA  8d 4d d8                                      lea     ecx, [ebp+var_28]; this
00403DCD  52                                            push    edx; char *
00403DCE  e8 81 68 01 00                                call    ?WriteString@CStdioFile@@UAEXPBD@Z; CStdioFile::WriteString(char const *)
00403DD3  8b 83 34 01 00 00                             mov     eax, [ebx+134h]
00403DD9  8d 4d ec                                      lea     ecx, [ebp+var_14]
00403DDC  50                                            push    eax
00403DDD  68 80 f5 41 00                                push    offset aD; "%d\n"
00403DE2  51                                            push    ecx; this
00403DE3  e8 24 68 01 00                                call    ?Format@CString@@QAAXPBDZZ; CString::Format(char const *,...)
00403DE8  8b 55 ec                                      mov     edx, [ebp+var_14]
00403DEB  83 c4 0c                                      add     esp, 0Ch
00403DEE  8d 4d d8                                      lea     ecx, [ebp+var_28]; this
00403DF1  52                                            push    edx; char *
00403DF2  e8 5d 68 01 00                                call    ?WriteString@CStdioFile@@UAEXPBD@Z; CStdioFile::WriteString(char const *)
00403DF7  8b 83 30 01 00 00                             mov     eax, [ebx+130h]
00403DFD  8d 4d ec                                      lea     ecx, [ebp+var_14]
00403E00  50                                            push    eax
00403E01  68 80 f5 41 00                                push    offset aD; "%d\n"
00403E06  51                                            push    ecx; this
00403E07  e8 00 68 01 00                                call    ?Format@CString@@QAAXPBDZZ; CString::Format(char const *,...)
00403E0C  8b 55 ec                                      mov     edx, [ebp+var_14]
00403E0F  83 c4 0c                                      add     esp, 0Ch
00403E12  8d 4d d8                                      lea     ecx, [ebp+var_28]; this
00403E15  52                                            push    edx; char *
00403E16  e8 39 68 01 00                                call    ?WriteString@CStdioFile@@UAEXPBD@Z; CStdioFile::WriteString(char const *)
00403E1B  8b 83 28 01 00 00                             mov     eax, [ebx+128h]
00403E21  8d 4d ec                                      lea     ecx, [ebp+var_14]
00403E24  50                                            push    eax
00403E25  68 80 f5 41 00                                push    offset aD; "%d\n"
00403E2A  51                                            push    ecx; this
00403E2B  e8 dc 67 01 00                                call    ?Format@CString@@QAAXPBDZZ; CString::Format(char const *,...)
00403E30  8b 55 ec                                      mov     edx, [ebp+var_14]
00403E33  83 c4 0c                                      add     esp, 0Ch
00403E36  8d 4d d8                                      lea     ecx, [ebp+var_28]; this
00403E39  52                                            push    edx; char *
00403E3A  e8 15 68 01 00                                call    ?WriteString@CStdioFile@@UAEXPBD@Z; CStdioFile::WriteString(char const *)
00403E3F  8b 83 24 01 00 00                             mov     eax, [ebx+124h]
00403E45  8d 4d ec                                      lea     ecx, [ebp+var_14]
00403E48  50                                            push    eax
00403E49  68 80 f5 41 00                                push    offset aD; "%d\n"
00403E4E  51                                            push    ecx; this
00403E4F  e8 b8 67 01 00                                call    ?Format@CString@@QAAXPBDZZ; CString::Format(char const *,...)
00403E54  8b 55 ec                                      mov     edx, [ebp+var_14]
00403E57  83 c4 0c                                      add     esp, 0Ch
00403E5A  8d 4d d8                                      lea     ecx, [ebp+var_28]; this
00403E5D  52                                            push    edx; char *
00403E5E  e8 f1 67 01 00                                call    ?WriteString@CStdioFile@@UAEXPBD@Z; CStdioFile::WriteString(char const *)
00403E63  8b 83 68 01 00 00                             mov     eax, [ebx+168h]
00403E69  8d 4d ec                                      lea     ecx, [ebp+var_14]
00403E6C  50                                            push    eax
00403E6D  68 80 f5 41 00                                push    offset aD; "%d\n"
00403E72  51                                            push    ecx; this
00403E73  e8 94 67 01 00                                call    ?Format@CString@@QAAXPBDZZ; CString::Format(char const *,...)
00403E78  8b 55 ec                                      mov     edx, [ebp+var_14]
00403E7B  83 c4 0c                                      add     esp, 0Ch
00403E7E  8d 4d d8                                      lea     ecx, [ebp+var_28]; this
00403E81  52                                            push    edx; char *
00403E82  e8 cd 67 01 00                                call    ?WriteString@CStdioFile@@UAEXPBD@Z; CStdioFile::WriteString(char const *)
00403E87  8b 83 6c 01 00 00                             mov     eax, [ebx+16Ch]
00403E8D  8d 4d ec                                      lea     ecx, [ebp+var_14]
00403E90  50                                            push    eax
00403E91  68 80 f5 41 00                                push    offset aD; "%d\n"
00403E96  51                                            push    ecx; this
00403E97  e8 70 67 01 00                                call    ?Format@CString@@QAAXPBDZZ; CString::Format(char const *,...)
00403E9C  8b 55 ec                                      mov     edx, [ebp+var_14]
00403E9F  83 c4 0c                                      add     esp, 0Ch
00403EA2  8d 4d d8                                      lea     ecx, [ebp+var_28]; this
00403EA5  52                                            push    edx; char *
00403EA6  e8 a9 67 01 00                                call    ?WriteString@CStdioFile@@UAEXPBD@Z; CStdioFile::WriteString(char const *)
00403EAB  8b 83 70 01 00 00                             mov     eax, [ebx+170h]
00403EB1  8d 4d ec                                      lea     ecx, [ebp+var_14]
00403EB4  50                                            push    eax
00403EB5  68 80 f5 41 00                                push    offset aD; "%d\n"
00403EBA  51                                            push    ecx; this
00403EBB  e8 4c 67 01 00                                call    ?Format@CString@@QAAXPBDZZ; CString::Format(char const *,...)
00403EC0  8b 55 ec                                      mov     edx, [ebp+var_14]
00403EC3  83 c4 0c                                      add     esp, 0Ch
00403EC6  8d 4d d8                                      lea     ecx, [ebp+var_28]; this
00403EC9  52                                            push    edx; char *
00403ECA  e8 85 67 01 00                                call    ?WriteString@CStdioFile@@UAEXPBD@Z; CStdioFile::WriteString(char const *)
00403ECF  8b 83 84 01 00 00                             mov     eax, [ebx+184h]
00403ED5  8d 4d ec                                      lea     ecx, [ebp+var_14]
00403ED8  50                                            push    eax
00403ED9  68 80 f5 41 00                                push    offset aD; "%d\n"
00403EDE  51                                            push    ecx; this
00403EDF  e8 28 67 01 00                                call    ?Format@CString@@QAAXPBDZZ; CString::Format(char const *,...)
00403EE4  8b 55 ec                                      mov     edx, [ebp+var_14]
00403EE7  83 c4 0c                                      add     esp, 0Ch
00403EEA  8d 4d d8                                      lea     ecx, [ebp+var_28]; this
00403EED  52                                            push    edx; char *
00403EEE  e8 61 67 01 00                                call    ?WriteString@CStdioFile@@UAEXPBD@Z; CStdioFile::WriteString(char const *)
00403EF3  8b 83 8c 01 00 00                             mov     eax, [ebx+18Ch]
00403EF9  8d 4d ec                                      lea     ecx, [ebp+var_14]
00403EFC  50                                            push    eax
00403EFD  68 80 f5 41 00                                push    offset aD; "%d\n"
00403F02  51                                            push    ecx; this
00403F03  e8 04 67 01 00                                call    ?Format@CString@@QAAXPBDZZ; CString::Format(char const *,...)
00403F08  8b 55 ec                                      mov     edx, [ebp+var_14]
00403F0B  83 c4 0c                                      add     esp, 0Ch
00403F0E  8d 4d d8                                      lea     ecx, [ebp+var_28]; this
00403F11  52                                            push    edx; char *
00403F12  e8 3d 67 01 00                                call    ?WriteString@CStdioFile@@UAEXPBD@Z; CStdioFile::WriteString(char const *)
00403F17  8b 83 9c 01 00 00                             mov     eax, [ebx+19Ch]
00403F1D  8d 4d ec                                      lea     ecx, [ebp+var_14]
00403F20  50                                            push    eax
00403F21  68 80 f5 41 00                                push    offset aD; "%d\n"
00403F26  51                                            push    ecx; this
00403F27  e8 e0 66 01 00                                call    ?Format@CString@@QAAXPBDZZ; CString::Format(char const *,...)
00403F2C  8b 55 ec                                      mov     edx, [ebp+var_14]
00403F2F  83 c4 0c                                      add     esp, 0Ch
00403F32  8d 4d d8                                      lea     ecx, [ebp+var_28]; this
00403F35  52                                            push    edx; char *
00403F36  e8 19 67 01 00                                call    ?WriteString@CStdioFile@@UAEXPBD@Z; CStdioFile::WriteString(char const *)
00403F3B  8d 4d d8                                      lea     ecx, [ebp+var_28]; this
00403F3E  c7 45 fc 02 00 00 00                          mov     [ebp+var_4], 2
00403F45  e8 04 67 01 00                                call    ?Close@CStdioFile@@UAEXXZ; CStdioFile::Close(void)
00403F4A  c6 45 fc 0c                                   mov     byte ptr [ebp+var_4], 0Ch
00403F4E  eb 56                                         jmp     short loc_403FA6
00403F50  8b 45 cc                                      mov     eax, [ebp+var_34]
00403F53  8b 4d c8                                      mov     ecx, [ebp+var_38]
00403F56  50                                            push    eax
00403F57  51                                            push    ecx
00403F58  8d 55 ec                                      lea     edx, [ebp+var_14]
00403F5B  68 c0 f6 41 00                                push    offset byte_41F6C0; char *
00403F60  52                                            push    edx; this
00403F61  c6 45 fc 09                                   mov     byte ptr [ebp+var_4], 9
00403F65  e8 a2 66 01 00                                call    ?Format@CString@@QAAXPBDZZ; CString::Format(char const *,...)
00403F6A  8b 45 ec                                      mov     eax, [ebp+var_14]
00403F6D  83 c4 10                                      add     esp, 10h
00403F70  6a 00                                         push    0; unsigned int
00403F72  6a 00                                         push    0; unsigned int
00403F74  50                                            push    eax; char *
00403F75  e8 98 66 01 00                                call    ?AfxMessageBox@@YGHPBDII@Z; AfxMessageBox(char const *,uint,uint)
00403F7A  8d 4d d8                                      lea     ecx, [ebp+var_28]; this
00403F7D  e8 cc 66 01 00                                call    ?Close@CStdioFile@@UAEXXZ; CStdioFile::Close(void)
00403F82  c7 45 c0 84 c5 41 00                          mov     [ebp+var_40], offset off_41C584
00403F89  8d 4d d0                                      lea     ecx, [ebp+var_30]; this
00403F8C  c6 45 fc 0a                                   mov     byte ptr [ebp+var_4], 0Ah
00403F90  e8 71 66 01 00                                call    ??1CString@@QAE@XZ; CString::~CString(void)
00403F95  c7 45 c0 70 c5 41 00                          mov     [ebp+var_40], offset off_41C570
00403F9C  b8 a2 3f 40 00                                mov     eax, offset loc_403FA2
00403FA1  c3                                            retn
00403FA2  c6 45 fc 0b                                   mov     byte ptr [ebp+var_4], 0Bh
00403FA6  8d 8d 44 fe ff ff                             lea     ecx, [ebp+var_1BC]; this
00403FAC  e8 55 66 01 00                                call    ??1CString@@QAE@XZ; CString::~CString(void)
00403FB1  8d 8d 94 fd ff ff                             lea     ecx, [ebp+var_26C]; this
00403FB7  c6 45 fc 01                                   mov     byte ptr [ebp+var_4], 1
00403FBB  e8 16 66 01 00                                call    ??1CDialog@@UAE@XZ; CDialog::~CDialog(void)
00403FC0  8d 4d ec                                      lea     ecx, [ebp+var_14]; this
00403FC3  c6 45 fc 00                                   mov     byte ptr [ebp+var_4], 0
00403FC7  e8 3a 66 01 00                                call    ??1CString@@QAE@XZ; CString::~CString(void)
00403FCC  8d 4d d8                                      lea     ecx, [ebp+var_28]; this
00403FCF  c7 45 fc ff ff ff ff                          mov     [ebp+var_4], 0FFFFFFFFh
00403FD6  e8 6d 66 01 00                                call    ??1CStdioFile@@UAE@XZ; CStdioFile::~CStdioFile(void)
00403FDB  8b 4d f4                                      mov     ecx, [ebp+var_C]
00403FDE  5f                                            pop     edi
00403FDF  5e                                            pop     esi
00403FE0  64 89 0d 00 00 00 00                          mov     large fs:0, ecx
00403FE7  5b                                            pop     ebx
00403FE8  8b e5                                         mov     esp, ebp
00403FEA  5d                                            pop     ebp
00403FEB  c3                                            retn
0041ADE0  8d 4d d8                                      lea     ecx, [ebp+var_28]; this
0041ADE3  e9 60 f8 ff ff                                jmp     ??1CStdioFile@@UAE@XZ; CStdioFile::~CStdioFile(void)
0041ADE8  8d 4d ec                                      lea     ecx, [ebp+var_14]; this
0041ADEB  e9 16 f8 ff ff                                jmp     ??1CString@@QAE@XZ; CString::~CString(void)
0041ADF0  8d 8d 94 fd ff ff                             lea     ecx, [ebp+var_26C]; this
0041ADF6  e9 f5 6a fe ff                                jmp     sub_4018F0
0041ADFB  8d 8d 94 fd ff ff                             lea     ecx, [ebp+var_26C]; this
0041AE01  e9 5a 6c fe ff                                jmp     j_??1CDialog@@UAE@XZ; CDialog::~CDialog(void)
0041AE06  8d 8d 94 fd ff ff                             lea     ecx, [ebp+var_26C]; this
0041AE0C  e9 4f 6c fe ff                                jmp     j_??1CDialog@@UAE@XZ; CDialog::~CDialog(void)
0041AE11  8d 4d d4                                      lea     ecx, [ebp+var_2C]; this
0041AE14  e9 ed f7 ff ff                                jmp     ??1CString@@QAE@XZ; CString::~CString(void)
0041AE19  8d 8d 94 fd ff ff                             lea     ecx, [ebp+var_26C]; this
0041AE1F  e9 3c 6c fe ff                                jmp     j_??1CDialog@@UAE@XZ; CDialog::~CDialog(void)
0041AE24  8d 8d 94 fd ff ff                             lea     ecx, [ebp+var_26C]; this
0041AE2A  e9 31 6c fe ff                                jmp     j_??1CDialog@@UAE@XZ; CDialog::~CDialog(void)
0041AE2F  8d 4d c0                                      lea     ecx, [ebp+var_40]
0041AE32  e9 99 6b fe ff                                jmp     sub_4019D0
0041AE37  8d 4d c0                                      lea     ecx, [ebp+var_40]
0041AE3A  e9 61 6b fe ff                                jmp     sub_4019A0
0041AE3F  8d 8d 94 fd ff ff                             lea     ecx, [ebp+var_26C]; this
0041AE45  e9 16 6c fe ff                                jmp     j_??1CDialog@@UAE@XZ; CDialog::~CDialog(void)
0041AE4A  b8 a0 d5 41 00                                mov     eax, offset stru_41D5A0
0041AE4F  e9 c8 f9 ff ff                                jmp     __CxxFrameHandler
