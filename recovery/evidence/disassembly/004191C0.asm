004191C0  55                                            push    ebp
004191C1  8b ec                                         mov     ebp, esp
004191C3  6a ff                                         push    0FFFFFFFFh
004191C5  68 20 b2 41 00                                push    offset SEH_4191C0
004191CA  64 a1 00 00 00 00                             mov     eax, large fs:0
004191D0  50                                            push    eax
004191D1  64 89 25 00 00 00 00                          mov     large fs:0, esp
004191D8  83 ec 34                                      sub     esp, 34h
004191DB  53                                            push    ebx
004191DC  56                                            push    esi
004191DD  8b f1                                         mov     esi, ecx
004191DF  57                                            push    edi
004191E0  8d 4d d4                                      lea     ecx, [ebp+var_2C]; this
004191E3  89 65 f0                                      mov     [ebp+var_10], esp
004191E6  89 75 e8                                      mov     [ebp+var_18], esi
004191E9  e8 84 14 00 00                                call    ??0CStdioFile@@QAE@XZ; CStdioFile::CStdioFile(void)
004191EE  8d 4d ec                                      lea     ecx, [ebp+String]; this
004191F1  c7 45 fc 00 00 00 00                          mov     [ebp+var_4], 0
004191F8  e8 21 14 00 00                                call    ??0CString@@QAE@XZ; CString::CString(void)
004191FD  6a 00                                         push    0; struct CFileException *
004191FF  68 20 40 00 00                                push    4020h; unsigned int
00419204  68 f8 f6 41 00                                push    offset aSan9pkhardpara; "San9PKHardPara.txt"
00419209  8d 4d d4                                      lea     ecx, [ebp+var_2C]; this
0041920C  c6 45 fc 01                                   mov     byte ptr [ebp+var_4], 1
00419210  e8 45 14 00 00                                call    ?Open@CStdioFile@@UAEHPBDIPAVCFileException@@@Z; CStdioFile::Open(char const *,uint,CFileException *)
00419215  85 c0                                         test    eax, eax
00419217  0f 84 3d 08 00 00                             jz      loc_419A5A
0041921D  8d 45 ec                                      lea     eax, [ebp+String]
00419220  8d 4d d4                                      lea     ecx, [ebp+var_2C]; this
00419223  50                                            push    eax; struct CString *
00419224  c6 45 fc 02                                   mov     byte ptr [ebp+var_4], 2
00419228  e8 dd 15 00 00                                call    ?ReadString@CStdioFile@@UAEHAAVCString@@@Z; CStdioFile::ReadString(CString &)
0041922D  85 c0                                         test    eax, eax
0041922F  75 23                                         jnz     short loc_419254
00419231  8b 1d fc c2 41 00                             mov     ebx, ds:atoi; MSVCRT
00419237  50                                            push    eax; unsigned int
00419238  50                                            push    eax; unsigned int
00419239  68 30 ee 42 00                                push    offset byte_42EE30; char *
0041923E  c6 45 fc 01                                   mov     byte ptr [ebp+var_4], 1
00419242  e8 cb 13 00 00                                call    ?AfxMessageBox@@YGHPBDII@Z; AfxMessageBox(char const *,uint,uint)
00419247  8d 4d d4                                      lea     ecx, [ebp+var_2C]; this
0041924A  e8 ff 13 00 00                                call    ?Close@CStdioFile@@UAEXXZ; CStdioFile::Close(void)
0041924F  e9 0c 08 00 00                                jmp     loc_419A60
00419254  8b 4d ec                                      mov     ecx, [ebp+String]
00419257  8b 1d fc c2 41 00                             mov     ebx, ds:atoi; MSVCRT
0041925D  51                                            push    ecx; String
0041925E  ff d3                                         call    ebx ; atoi; MSVCRT
00419260  83 c4 04                                      add     esp, 4
00419263  8d 55 ec                                      lea     edx, [ebp+String]
00419266  8d 4d d4                                      lea     ecx, [ebp+var_2C]; this
00419269  89 86 74 01 00 00                             mov     [esi+174h], eax
0041926F  52                                            push    edx; struct CString *
00419270  e8 95 15 00 00                                call    ?ReadString@CStdioFile@@UAEHAAVCString@@@Z; CStdioFile::ReadString(CString &)
00419275  85 c0                                         test    eax, eax
00419277  0f 84 44 07 00 00                             jz      loc_4199C1
0041927D  8b 45 ec                                      mov     eax, [ebp+String]
00419280  50                                            push    eax; String
00419281  ff d3                                         call    ebx ; atoi; MSVCRT
00419283  83 c4 04                                      add     esp, 4
00419286  8d 4d ec                                      lea     ecx, [ebp+String]
00419289  89 86 78 01 00 00                             mov     [esi+178h], eax
0041928F  51                                            push    ecx; struct CString *
00419290  8d 4d d4                                      lea     ecx, [ebp+var_2C]; this
00419293  e8 72 15 00 00                                call    ?ReadString@CStdioFile@@UAEHAAVCString@@@Z; CStdioFile::ReadString(CString &)
00419298  85 c0                                         test    eax, eax
0041929A  0f 84 21 07 00 00                             jz      loc_4199C1
004192A0  8b 55 ec                                      mov     edx, [ebp+String]
004192A3  52                                            push    edx; String
004192A4  ff d3                                         call    ebx ; atoi; MSVCRT
004192A6  83 c4 04                                      add     esp, 4
004192A9  89 86 7c 01 00 00                             mov     [esi+17Ch], eax
004192AF  8d 45 ec                                      lea     eax, [ebp+String]
004192B2  8d 4d d4                                      lea     ecx, [ebp+var_2C]; this
004192B5  50                                            push    eax; struct CString *
004192B6  e8 4f 15 00 00                                call    ?ReadString@CStdioFile@@UAEHAAVCString@@@Z; CStdioFile::ReadString(CString &)
004192BB  85 c0                                         test    eax, eax
004192BD  0f 84 fe 06 00 00                             jz      loc_4199C1
004192C3  8b 4d ec                                      mov     ecx, [ebp+String]
004192C6  51                                            push    ecx; String
004192C7  ff d3                                         call    ebx ; atoi; MSVCRT
004192C9  83 c4 04                                      add     esp, 4
004192CC  8d 55 ec                                      lea     edx, [ebp+String]
004192CF  8d 4d d4                                      lea     ecx, [ebp+var_2C]; this
004192D2  89 86 80 01 00 00                             mov     [esi+180h], eax
004192D8  52                                            push    edx; struct CString *
004192D9  e8 2c 15 00 00                                call    ?ReadString@CStdioFile@@UAEHAAVCString@@@Z; CStdioFile::ReadString(CString &)
004192DE  85 c0                                         test    eax, eax
004192E0  0f 84 db 06 00 00                             jz      loc_4199C1
004192E6  8b 45 ec                                      mov     eax, [ebp+String]
004192E9  50                                            push    eax; String
004192EA  ff d3                                         call    ebx ; atoi; MSVCRT
004192EC  83 c4 04                                      add     esp, 4
004192EF  8d 4d ec                                      lea     ecx, [ebp+String]
004192F2  89 86 84 01 00 00                             mov     [esi+184h], eax
004192F8  51                                            push    ecx; struct CString *
004192F9  8d 4d d4                                      lea     ecx, [ebp+var_2C]; this
004192FC  e8 09 15 00 00                                call    ?ReadString@CStdioFile@@UAEHAAVCString@@@Z; CStdioFile::ReadString(CString &)
00419301  85 c0                                         test    eax, eax
00419303  0f 84 b8 06 00 00                             jz      loc_4199C1
00419309  8b 55 ec                                      mov     edx, [ebp+String]
0041930C  52                                            push    edx; String
0041930D  ff d3                                         call    ebx ; atoi; MSVCRT
0041930F  83 c4 04                                      add     esp, 4
00419312  89 86 88 01 00 00                             mov     [esi+188h], eax
00419318  8d 45 ec                                      lea     eax, [ebp+String]
0041931B  8d 4d d4                                      lea     ecx, [ebp+var_2C]; this
0041931E  50                                            push    eax; struct CString *
0041931F  e8 e6 14 00 00                                call    ?ReadString@CStdioFile@@UAEHAAVCString@@@Z; CStdioFile::ReadString(CString &)
00419324  85 c0                                         test    eax, eax
00419326  0f 84 95 06 00 00                             jz      loc_4199C1
0041932C  8b 4d ec                                      mov     ecx, [ebp+String]
0041932F  51                                            push    ecx; String
00419330  ff d3                                         call    ebx ; atoi; MSVCRT
00419332  83 c4 04                                      add     esp, 4
00419335  8d 55 ec                                      lea     edx, [ebp+String]
00419338  8d 4d d4                                      lea     ecx, [ebp+var_2C]; this
0041933B  89 86 8c 01 00 00                             mov     [esi+18Ch], eax
00419341  52                                            push    edx; struct CString *
00419342  e8 c3 14 00 00                                call    ?ReadString@CStdioFile@@UAEHAAVCString@@@Z; CStdioFile::ReadString(CString &)
00419347  85 c0                                         test    eax, eax
00419349  0f 84 72 06 00 00                             jz      loc_4199C1
0041934F  8b 45 ec                                      mov     eax, [ebp+String]
00419352  50                                            push    eax; String
00419353  ff d3                                         call    ebx ; atoi; MSVCRT
00419355  83 c4 04                                      add     esp, 4
00419358  8d 4d ec                                      lea     ecx, [ebp+String]
0041935B  89 86 90 01 00 00                             mov     [esi+190h], eax
00419361  51                                            push    ecx; struct CString *
00419362  8d 4d d4                                      lea     ecx, [ebp+var_2C]; this
00419365  e8 a0 14 00 00                                call    ?ReadString@CStdioFile@@UAEHAAVCString@@@Z; CStdioFile::ReadString(CString &)
0041936A  85 c0                                         test    eax, eax
0041936C  0f 84 4f 06 00 00                             jz      loc_4199C1
00419372  8b 55 ec                                      mov     edx, [ebp+String]
00419375  52                                            push    edx; String
00419376  ff d3                                         call    ebx ; atoi; MSVCRT
00419378  83 c4 04                                      add     esp, 4
0041937B  89 86 94 01 00 00                             mov     [esi+194h], eax
00419381  8d 45 ec                                      lea     eax, [ebp+String]
00419384  8d 4d d4                                      lea     ecx, [ebp+var_2C]; this
00419387  50                                            push    eax; struct CString *
00419388  e8 7d 14 00 00                                call    ?ReadString@CStdioFile@@UAEHAAVCString@@@Z; CStdioFile::ReadString(CString &)
0041938D  85 c0                                         test    eax, eax
0041938F  0f 84 2c 06 00 00                             jz      loc_4199C1
00419395  8b 4d ec                                      mov     ecx, [ebp+String]
00419398  51                                            push    ecx; String
00419399  ff d3                                         call    ebx ; atoi; MSVCRT
0041939B  83 c4 04                                      add     esp, 4
0041939E  8d 55 ec                                      lea     edx, [ebp+String]
004193A1  8d 4d d4                                      lea     ecx, [ebp+var_2C]; this
004193A4  89 86 e0 01 00 00                             mov     [esi+1E0h], eax
004193AA  52                                            push    edx; struct CString *
004193AB  e8 5a 14 00 00                                call    ?ReadString@CStdioFile@@UAEHAAVCString@@@Z; CStdioFile::ReadString(CString &)
004193B0  85 c0                                         test    eax, eax
004193B2  0f 84 09 06 00 00                             jz      loc_4199C1
004193B8  8b 45 ec                                      mov     eax, [ebp+String]
004193BB  50                                            push    eax; String
004193BC  ff d3                                         call    ebx ; atoi; MSVCRT
004193BE  83 c4 04                                      add     esp, 4
004193C1  8d 4d ec                                      lea     ecx, [ebp+String]
004193C4  89 86 e4 01 00 00                             mov     [esi+1E4h], eax
004193CA  51                                            push    ecx; struct CString *
004193CB  8d 4d d4                                      lea     ecx, [ebp+var_2C]; this
004193CE  e8 37 14 00 00                                call    ?ReadString@CStdioFile@@UAEHAAVCString@@@Z; CStdioFile::ReadString(CString &)
004193D3  85 c0                                         test    eax, eax
004193D5  0f 84 e6 05 00 00                             jz      loc_4199C1
004193DB  8b 55 ec                                      mov     edx, [ebp+String]
004193DE  52                                            push    edx; String
004193DF  ff d3                                         call    ebx ; atoi; MSVCRT
004193E1  83 c4 04                                      add     esp, 4
004193E4  89 86 e8 01 00 00                             mov     [esi+1E8h], eax
004193EA  8d 45 ec                                      lea     eax, [ebp+String]
004193ED  8d 4d d4                                      lea     ecx, [ebp+var_2C]; this
004193F0  50                                            push    eax; struct CString *
004193F1  e8 14 14 00 00                                call    ?ReadString@CStdioFile@@UAEHAAVCString@@@Z; CStdioFile::ReadString(CString &)
004193F6  85 c0                                         test    eax, eax
004193F8  0f 84 c3 05 00 00                             jz      loc_4199C1
004193FE  8b 4d ec                                      mov     ecx, [ebp+String]
00419401  51                                            push    ecx; String
00419402  ff d3                                         call    ebx ; atoi; MSVCRT
00419404  83 c4 04                                      add     esp, 4
00419407  8d 55 ec                                      lea     edx, [ebp+String]
0041940A  8d 4d d4                                      lea     ecx, [ebp+var_2C]; this
0041940D  89 86 ec 01 00 00                             mov     [esi+1ECh], eax
00419413  52                                            push    edx; struct CString *
00419414  e8 f1 13 00 00                                call    ?ReadString@CStdioFile@@UAEHAAVCString@@@Z; CStdioFile::ReadString(CString &)
00419419  85 c0                                         test    eax, eax
0041941B  0f 84 a0 05 00 00                             jz      loc_4199C1
00419421  8b 45 ec                                      mov     eax, [ebp+String]
00419424  50                                            push    eax; String
00419425  ff d3                                         call    ebx ; atoi; MSVCRT
00419427  83 c4 04                                      add     esp, 4
0041942A  8d 4d ec                                      lea     ecx, [ebp+String]
0041942D  89 86 f0 01 00 00                             mov     [esi+1F0h], eax
00419433  51                                            push    ecx; struct CString *
00419434  8d 4d d4                                      lea     ecx, [ebp+var_2C]; this
00419437  e8 ce 13 00 00                                call    ?ReadString@CStdioFile@@UAEHAAVCString@@@Z; CStdioFile::ReadString(CString &)
0041943C  85 c0                                         test    eax, eax
0041943E  0f 84 7d 05 00 00                             jz      loc_4199C1
00419444  8b 55 ec                                      mov     edx, [ebp+String]
00419447  52                                            push    edx; String
00419448  ff d3                                         call    ebx ; atoi; MSVCRT
0041944A  8b c8                                         mov     ecx, eax
0041944C  8b d0                                         mov     edx, eax
0041944E  83 e1 01                                      and     ecx, 1
00419451  83 c4 04                                      add     esp, 4
00419454  89 8e 94 00 00 00                             mov     [esi+94h], ecx
0041945A  8b c8                                         mov     ecx, eax
0041945C  d1 ea                                         shr     edx, 1
0041945E  83 e2 01                                      and     edx, 1
00419461  c1 e9 02                                      shr     ecx, 2
00419464  89 96 44 01 00 00                             mov     [esi+144h], edx
0041946A  83 e1 01                                      and     ecx, 1
0041946D  8b d0                                         mov     edx, eax
0041946F  89 8e 98 00 00 00                             mov     [esi+98h], ecx
00419475  c1 ea 03                                      shr     edx, 3
00419478  8b c8                                         mov     ecx, eax
0041947A  83 e2 01                                      and     edx, 1
0041947D  c1 e9 04                                      shr     ecx, 4
00419480  89 96 9c 00 00 00                             mov     [esi+9Ch], edx
00419486  83 e1 01                                      and     ecx, 1
00419489  8b d0                                         mov     edx, eax
0041948B  89 8e a0 00 00 00                             mov     [esi+0A0h], ecx
00419491  c1 ea 05                                      shr     edx, 5
00419494  8b c8                                         mov     ecx, eax
00419496  83 e2 01                                      and     edx, 1
00419499  c1 e9 06                                      shr     ecx, 6
0041949C  89 96 a4 00 00 00                             mov     [esi+0A4h], edx
004194A2  83 e1 01                                      and     ecx, 1
004194A5  8b d0                                         mov     edx, eax
004194A7  89 8e a8 00 00 00                             mov     [esi+0A8h], ecx
004194AD  c1 ea 07                                      shr     edx, 7
004194B0  8b c8                                         mov     ecx, eax
004194B2  83 e2 01                                      and     edx, 1
004194B5  c1 e9 08                                      shr     ecx, 8
004194B8  89 96 ac 00 00 00                             mov     [esi+0ACh], edx
004194BE  83 e1 01                                      and     ecx, 1
004194C1  8b d0                                         mov     edx, eax
004194C3  89 8e b0 00 00 00                             mov     [esi+0B0h], ecx
004194C9  c1 ea 09                                      shr     edx, 9
004194CC  8b c8                                         mov     ecx, eax
004194CE  83 e2 01                                      and     edx, 1
004194D1  c1 e9 0a                                      shr     ecx, 0Ah
004194D4  89 96 14 01 00 00                             mov     [esi+114h], edx
004194DA  83 e1 01                                      and     ecx, 1
004194DD  8b d0                                         mov     edx, eax
004194DF  89 8e b4 00 00 00                             mov     [esi+0B4h], ecx
004194E5  c1 ea 0b                                      shr     edx, 0Bh
004194E8  8b c8                                         mov     ecx, eax
004194EA  83 e2 01                                      and     edx, 1
004194ED  c1 e9 0c                                      shr     ecx, 0Ch
004194F0  89 96 b8 00 00 00                             mov     [esi+0B8h], edx
004194F6  83 e1 01                                      and     ecx, 1
004194F9  8b d0                                         mov     edx, eax
004194FB  89 8e bc 00 00 00                             mov     [esi+0BCh], ecx
00419501  c1 ea 0d                                      shr     edx, 0Dh
00419504  8b c8                                         mov     ecx, eax
00419506  83 e2 01                                      and     edx, 1
00419509  c1 e9 0e                                      shr     ecx, 0Eh
0041950C  89 96 c0 00 00 00                             mov     [esi+0C0h], edx
00419512  83 e1 01                                      and     ecx, 1
00419515  8b d0                                         mov     edx, eax
00419517  89 8e c4 00 00 00                             mov     [esi+0C4h], ecx
0041951D  c1 ea 0f                                      shr     edx, 0Fh
00419520  8b c8                                         mov     ecx, eax
00419522  83 e2 01                                      and     edx, 1
00419525  c1 e9 10                                      shr     ecx, 10h
00419528  89 96 c8 00 00 00                             mov     [esi+0C8h], edx
0041952E  83 e1 01                                      and     ecx, 1
00419531  8b d0                                         mov     edx, eax
00419533  89 8e cc 00 00 00                             mov     [esi+0CCh], ecx
00419539  c1 ea 11                                      shr     edx, 11h
0041953C  8b c8                                         mov     ecx, eax
0041953E  83 e2 01                                      and     edx, 1
00419541  c1 e9 12                                      shr     ecx, 12h
00419544  89 96 54 01 00 00                             mov     [esi+154h], edx
0041954A  83 e1 01                                      and     ecx, 1
0041954D  8b d0                                         mov     edx, eax
0041954F  89 8e 58 01 00 00                             mov     [esi+158h], ecx
00419555  c1 ea 13                                      shr     edx, 13h
00419558  83 e2 01                                      and     edx, 1
0041955B  8b c8                                         mov     ecx, eax
0041955D  89 96 5c 01 00 00                             mov     [esi+15Ch], edx
00419563  8b d0                                         mov     edx, eax
00419565  c1 e9 14                                      shr     ecx, 14h
00419568  c1 ea 15                                      shr     edx, 15h
0041956B  83 e1 01                                      and     ecx, 1
0041956E  83 e2 01                                      and     edx, 1
00419571  89 8e 60 01 00 00                             mov     [esi+160h], ecx
00419577  89 96 64 01 00 00                             mov     [esi+164h], edx
0041957D  8b c8                                         mov     ecx, eax
0041957F  8b d0                                         mov     edx, eax
00419581  c1 e9 16                                      shr     ecx, 16h
00419584  c1 ea 17                                      shr     edx, 17h
00419587  83 e1 01                                      and     ecx, 1
0041958A  83 e2 01                                      and     edx, 1
0041958D  c1 e8 18                                      shr     eax, 18h
00419590  89 8e 68 01 00 00                             mov     [esi+168h], ecx
00419596  83 e0 01                                      and     eax, 1
00419599  89 96 6c 01 00 00                             mov     [esi+16Ch], edx
0041959F  89 86 70 01 00 00                             mov     [esi+170h], eax
004195A5  8d 45 ec                                      lea     eax, [ebp+String]
004195A8  8d 4d d4                                      lea     ecx, [ebp+var_2C]; this
004195AB  50                                            push    eax; struct CString *
004195AC  e8 59 12 00 00                                call    ?ReadString@CStdioFile@@UAEHAAVCString@@@Z; CStdioFile::ReadString(CString &)
004195B1  85 c0                                         test    eax, eax
004195B3  0f 84 08 04 00 00                             jz      loc_4199C1
004195B9  8b 4d ec                                      mov     ecx, [ebp+String]
004195BC  51                                            push    ecx; String
004195BD  ff d3                                         call    ebx ; atoi; MSVCRT
004195BF  8b d0                                         mov     edx, eax
004195C1  8b c8                                         mov     ecx, eax
004195C3  83 e2 01                                      and     edx, 1
004195C6  83 c4 04                                      add     esp, 4
004195C9  89 96 34 01 00 00                             mov     [esi+134h], edx
004195CF  8b d0                                         mov     edx, eax
004195D1  d1 e9                                         shr     ecx, 1
004195D3  83 e1 01                                      and     ecx, 1
004195D6  c1 ea 02                                      shr     edx, 2
004195D9  89 8e d0 00 00 00                             mov     [esi+0D0h], ecx
004195DF  83 e2 01                                      and     edx, 1
004195E2  8b c8                                         mov     ecx, eax
004195E4  89 96 d4 00 00 00                             mov     [esi+0D4h], edx
004195EA  c1 e9 03                                      shr     ecx, 3
004195ED  8b d0                                         mov     edx, eax
004195EF  83 e1 01                                      and     ecx, 1
004195F2  c1 ea 04                                      shr     edx, 4
004195F5  89 8e d8 00 00 00                             mov     [esi+0D8h], ecx
004195FB  83 e2 01                                      and     edx, 1
004195FE  8b c8                                         mov     ecx, eax
00419600  89 96 dc 00 00 00                             mov     [esi+0DCh], edx
00419606  c1 e9 05                                      shr     ecx, 5
00419609  8b d0                                         mov     edx, eax
0041960B  83 e1 01                                      and     ecx, 1
0041960E  c1 ea 06                                      shr     edx, 6
00419611  89 8e e0 00 00 00                             mov     [esi+0E0h], ecx
00419617  83 e2 01                                      and     edx, 1
0041961A  8b c8                                         mov     ecx, eax
0041961C  89 96 e4 00 00 00                             mov     [esi+0E4h], edx
00419622  c1 e9 07                                      shr     ecx, 7
00419625  8b d0                                         mov     edx, eax
00419627  83 e1 01                                      and     ecx, 1
0041962A  c1 ea 08                                      shr     edx, 8
0041962D  89 8e e8 00 00 00                             mov     [esi+0E8h], ecx
00419633  83 e2 01                                      and     edx, 1
00419636  8b c8                                         mov     ecx, eax
00419638  89 96 ec 00 00 00                             mov     [esi+0ECh], edx
0041963E  c1 e9 09                                      shr     ecx, 9
00419641  8b d0                                         mov     edx, eax
00419643  83 e1 01                                      and     ecx, 1
00419646  c1 ea 0a                                      shr     edx, 0Ah
00419649  89 8e f0 00 00 00                             mov     [esi+0F0h], ecx
0041964F  83 e2 01                                      and     edx, 1
00419652  8b c8                                         mov     ecx, eax
00419654  89 96 f4 00 00 00                             mov     [esi+0F4h], edx
0041965A  c1 e9 0b                                      shr     ecx, 0Bh
0041965D  8b d0                                         mov     edx, eax
0041965F  83 e1 01                                      and     ecx, 1
00419662  c1 ea 0c                                      shr     edx, 0Ch
00419665  89 8e f8 00 00 00                             mov     [esi+0F8h], ecx
0041966B  83 e2 01                                      and     edx, 1
0041966E  8b c8                                         mov     ecx, eax
00419670  89 96 fc 00 00 00                             mov     [esi+0FCh], edx
00419676  c1 e9 0d                                      shr     ecx, 0Dh
00419679  8b d0                                         mov     edx, eax
0041967B  83 e1 01                                      and     ecx, 1
0041967E  c1 ea 0e                                      shr     edx, 0Eh
00419681  89 8e 00 01 00 00                             mov     [esi+100h], ecx
00419687  83 e2 01                                      and     edx, 1
0041968A  8b c8                                         mov     ecx, eax
0041968C  89 96 04 01 00 00                             mov     [esi+104h], edx
00419692  c1 e9 0f                                      shr     ecx, 0Fh
00419695  8b d0                                         mov     edx, eax
00419697  83 e1 01                                      and     ecx, 1
0041969A  c1 ea 10                                      shr     edx, 10h
0041969D  89 8e 08 01 00 00                             mov     [esi+108h], ecx
004196A3  83 e2 01                                      and     edx, 1
004196A6  8b c8                                         mov     ecx, eax
004196A8  89 96 0c 01 00 00                             mov     [esi+10Ch], edx
004196AE  c1 e9 11                                      shr     ecx, 11h
004196B1  8b d0                                         mov     edx, eax
004196B3  83 e1 01                                      and     ecx, 1
004196B6  c1 ea 12                                      shr     edx, 12h
004196B9  89 8e 10 01 00 00                             mov     [esi+110h], ecx
004196BF  83 e2 01                                      and     edx, 1
004196C2  8b c8                                         mov     ecx, eax
004196C4  89 96 18 01 00 00                             mov     [esi+118h], edx
004196CA  c1 e9 13                                      shr     ecx, 13h
004196CD  83 e1 01                                      and     ecx, 1
004196D0  8b d0                                         mov     edx, eax
004196D2  89 8e 1c 01 00 00                             mov     [esi+11Ch], ecx
004196D8  8b c8                                         mov     ecx, eax
004196DA  c1 ea 14                                      shr     edx, 14h
004196DD  83 e2 01                                      and     edx, 1
004196E0  c1 e9 15                                      shr     ecx, 15h
004196E3  89 96 20 01 00 00                             mov     [esi+120h], edx
004196E9  83 e1 01                                      and     ecx, 1
004196EC  8b d0                                         mov     edx, eax
004196EE  89 8e 24 01 00 00                             mov     [esi+124h], ecx
004196F4  c1 ea 16                                      shr     edx, 16h
004196F7  8b c8                                         mov     ecx, eax
004196F9  83 e2 01                                      and     edx, 1
004196FC  c1 e9 17                                      shr     ecx, 17h
004196FF  89 96 28 01 00 00                             mov     [esi+128h], edx
00419705  83 e1 01                                      and     ecx, 1
00419708  8b d0                                         mov     edx, eax
0041970A  89 8e 2c 01 00 00                             mov     [esi+12Ch], ecx
00419710  c1 ea 18                                      shr     edx, 18h
00419713  8b c8                                         mov     ecx, eax
00419715  83 e2 01                                      and     edx, 1
00419718  c1 e9 19                                      shr     ecx, 19h
0041971B  89 96 30 01 00 00                             mov     [esi+130h], edx
00419721  83 e1 01                                      and     ecx, 1
00419724  8b d0                                         mov     edx, eax
00419726  89 8e 38 01 00 00                             mov     [esi+138h], ecx
0041972C  c1 ea 1a                                      shr     edx, 1Ah
0041972F  8b c8                                         mov     ecx, eax
00419731  83 e2 01                                      and     edx, 1
00419734  c1 e9 1b                                      shr     ecx, 1Bh
00419737  89 96 3c 01 00 00                             mov     [esi+13Ch], edx
0041973D  83 e1 01                                      and     ecx, 1
00419740  8b d0                                         mov     edx, eax
00419742  89 8e 40 01 00 00                             mov     [esi+140h], ecx
00419748  c1 ea 1c                                      shr     edx, 1Ch
0041974B  8b c8                                         mov     ecx, eax
0041974D  83 e2 01                                      and     edx, 1
00419750  c1 e9 1d                                      shr     ecx, 1Dh
00419753  89 96 48 01 00 00                             mov     [esi+148h], edx
00419759  83 e1 01                                      and     ecx, 1
0041975C  c1 e8 1e                                      shr     eax, 1Eh
0041975F  8d 55 ec                                      lea     edx, [ebp+String]
00419762  89 8e 4c 01 00 00                             mov     [esi+14Ch], ecx
00419768  83 e0 01                                      and     eax, 1
0041976B  52                                            push    edx; struct CString *
0041976C  8d 4d d4                                      lea     ecx, [ebp+var_2C]; this
0041976F  89 86 50 01 00 00                             mov     [esi+150h], eax
00419775  e8 90 10 00 00                                call    ?ReadString@CStdioFile@@UAEHAAVCString@@@Z; CStdioFile::ReadString(CString &)
0041977A  85 c0                                         test    eax, eax
0041977C  0f 84 3f 02 00 00                             jz      loc_4199C1
00419782  8b 45 ec                                      mov     eax, [ebp+String]
00419785  50                                            push    eax; String
00419786  ff d3                                         call    ebx ; atoi; MSVCRT
00419788  83 c4 04                                      add     esp, 4
0041978B  8d 4d ec                                      lea     ecx, [ebp+String]
0041978E  89 86 98 01 00 00                             mov     [esi+198h], eax
00419794  51                                            push    ecx; struct CString *
00419795  8d 4d d4                                      lea     ecx, [ebp+var_2C]; this
00419798  e8 6d 10 00 00                                call    ?ReadString@CStdioFile@@UAEHAAVCString@@@Z; CStdioFile::ReadString(CString &)
0041979D  85 c0                                         test    eax, eax
0041979F  0f 84 1c 02 00 00                             jz      loc_4199C1
004197A5  8b 55 ec                                      mov     edx, [ebp+String]
004197A8  52                                            push    edx; String
004197A9  ff d3                                         call    ebx ; atoi; MSVCRT
004197AB  83 c4 04                                      add     esp, 4
004197AE  89 86 9c 01 00 00                             mov     [esi+19Ch], eax
004197B4  8d 45 ec                                      lea     eax, [ebp+String]
004197B7  8d 4d d4                                      lea     ecx, [ebp+var_2C]; this
004197BA  50                                            push    eax; struct CString *
004197BB  e8 4a 10 00 00                                call    ?ReadString@CStdioFile@@UAEHAAVCString@@@Z; CStdioFile::ReadString(CString &)
004197C0  85 c0                                         test    eax, eax
004197C2  0f 84 f9 01 00 00                             jz      loc_4199C1
004197C8  8b 4d ec                                      mov     ecx, [ebp+String]
004197CB  51                                            push    ecx; String
004197CC  ff d3                                         call    ebx ; atoi; MSVCRT
004197CE  83 c4 04                                      add     esp, 4
004197D1  8d 55 ec                                      lea     edx, [ebp+String]
004197D4  8d 4d d4                                      lea     ecx, [ebp+var_2C]; this
004197D7  89 86 a0 01 00 00                             mov     [esi+1A0h], eax
004197DD  52                                            push    edx; struct CString *
004197DE  e8 27 10 00 00                                call    ?ReadString@CStdioFile@@UAEHAAVCString@@@Z; CStdioFile::ReadString(CString &)
004197E3  85 c0                                         test    eax, eax
004197E5  0f 84 d6 01 00 00                             jz      loc_4199C1
004197EB  8b 45 ec                                      mov     eax, [ebp+String]
004197EE  50                                            push    eax; String
004197EF  ff d3                                         call    ebx ; atoi; MSVCRT
004197F1  83 c4 04                                      add     esp, 4
004197F4  8d 4d ec                                      lea     ecx, [ebp+String]
004197F7  89 86 a4 01 00 00                             mov     [esi+1A4h], eax
004197FD  51                                            push    ecx; struct CString *
004197FE  8d 4d d4                                      lea     ecx, [ebp+var_2C]; this
00419801  e8 04 10 00 00                                call    ?ReadString@CStdioFile@@UAEHAAVCString@@@Z; CStdioFile::ReadString(CString &)
00419806  85 c0                                         test    eax, eax
00419808  0f 84 b3 01 00 00                             jz      loc_4199C1
0041980E  8b 55 ec                                      mov     edx, [ebp+String]
00419811  52                                            push    edx; String
00419812  ff d3                                         call    ebx ; atoi; MSVCRT
00419814  83 c4 04                                      add     esp, 4
00419817  89 86 a8 01 00 00                             mov     [esi+1A8h], eax
0041981D  8d 45 ec                                      lea     eax, [ebp+String]
00419820  8d 4d d4                                      lea     ecx, [ebp+var_2C]; this
00419823  50                                            push    eax; struct CString *
00419824  e8 e1 0f 00 00                                call    ?ReadString@CStdioFile@@UAEHAAVCString@@@Z; CStdioFile::ReadString(CString &)
00419829  85 c0                                         test    eax, eax
0041982B  0f 84 90 01 00 00                             jz      loc_4199C1
00419831  8b 4d ec                                      mov     ecx, [ebp+String]
00419834  51                                            push    ecx; String
00419835  ff d3                                         call    ebx ; atoi; MSVCRT
00419837  83 c4 04                                      add     esp, 4
0041983A  8d 55 ec                                      lea     edx, [ebp+String]
0041983D  8d 4d d4                                      lea     ecx, [ebp+var_2C]; this
00419840  89 86 ac 01 00 00                             mov     [esi+1ACh], eax
00419846  52                                            push    edx; struct CString *
00419847  e8 be 0f 00 00                                call    ?ReadString@CStdioFile@@UAEHAAVCString@@@Z; CStdioFile::ReadString(CString &)
0041984C  85 c0                                         test    eax, eax
0041984E  0f 84 6d 01 00 00                             jz      loc_4199C1
00419854  8b 45 ec                                      mov     eax, [ebp+String]
00419857  50                                            push    eax; String
00419858  ff d3                                         call    ebx ; atoi; MSVCRT
0041985A  83 c4 04                                      add     esp, 4
0041985D  8d 4d ec                                      lea     ecx, [ebp+String]
00419860  89 86 b0 01 00 00                             mov     [esi+1B0h], eax
00419866  51                                            push    ecx; struct CString *
00419867  8d 4d d4                                      lea     ecx, [ebp+var_2C]; this
0041986A  e8 9b 0f 00 00                                call    ?ReadString@CStdioFile@@UAEHAAVCString@@@Z; CStdioFile::ReadString(CString &)
0041986F  85 c0                                         test    eax, eax
00419871  0f 84 4a 01 00 00                             jz      loc_4199C1
00419877  8b 55 ec                                      mov     edx, [ebp+String]
0041987A  52                                            push    edx; String
0041987B  ff d3                                         call    ebx ; atoi; MSVCRT
0041987D  83 c4 04                                      add     esp, 4
00419880  89 86 b4 01 00 00                             mov     [esi+1B4h], eax
00419886  8d 45 ec                                      lea     eax, [ebp+String]
00419889  8d 4d d4                                      lea     ecx, [ebp+var_2C]; this
0041988C  50                                            push    eax; struct CString *
0041988D  e8 78 0f 00 00                                call    ?ReadString@CStdioFile@@UAEHAAVCString@@@Z; CStdioFile::ReadString(CString &)
00419892  85 c0                                         test    eax, eax
00419894  0f 84 27 01 00 00                             jz      loc_4199C1
0041989A  8b 4d ec                                      mov     ecx, [ebp+String]
0041989D  51                                            push    ecx; String
0041989E  ff d3                                         call    ebx ; atoi; MSVCRT
004198A0  83 c4 04                                      add     esp, 4
004198A3  8d 55 ec                                      lea     edx, [ebp+String]
004198A6  8d 4d d4                                      lea     ecx, [ebp+var_2C]; this
004198A9  89 86 b8 01 00 00                             mov     [esi+1B8h], eax
004198AF  52                                            push    edx; struct CString *
004198B0  e8 55 0f 00 00                                call    ?ReadString@CStdioFile@@UAEHAAVCString@@@Z; CStdioFile::ReadString(CString &)
004198B5  85 c0                                         test    eax, eax
004198B7  0f 84 04 01 00 00                             jz      loc_4199C1
004198BD  8b 45 ec                                      mov     eax, [ebp+String]
004198C0  50                                            push    eax; String
004198C1  ff d3                                         call    ebx ; atoi; MSVCRT
004198C3  83 c4 04                                      add     esp, 4
004198C6  8d 4d ec                                      lea     ecx, [ebp+String]
004198C9  89 86 bc 01 00 00                             mov     [esi+1BCh], eax
004198CF  51                                            push    ecx; struct CString *
004198D0  8d 4d d4                                      lea     ecx, [ebp+var_2C]; this
004198D3  e8 32 0f 00 00                                call    ?ReadString@CStdioFile@@UAEHAAVCString@@@Z; CStdioFile::ReadString(CString &)
004198D8  85 c0                                         test    eax, eax
004198DA  0f 84 e1 00 00 00                             jz      loc_4199C1
004198E0  8b 55 ec                                      mov     edx, [ebp+String]
004198E3  52                                            push    edx; String
004198E4  ff d3                                         call    ebx ; atoi; MSVCRT
004198E6  83 c4 04                                      add     esp, 4
004198E9  89 86 c0 01 00 00                             mov     [esi+1C0h], eax
004198EF  8d 45 ec                                      lea     eax, [ebp+String]
004198F2  8d 4d d4                                      lea     ecx, [ebp+var_2C]; this
004198F5  50                                            push    eax; struct CString *
004198F6  e8 0f 0f 00 00                                call    ?ReadString@CStdioFile@@UAEHAAVCString@@@Z; CStdioFile::ReadString(CString &)
004198FB  85 c0                                         test    eax, eax
004198FD  0f 84 be 00 00 00                             jz      loc_4199C1
00419903  8b 4d ec                                      mov     ecx, [ebp+String]
00419906  51                                            push    ecx; String
00419907  ff d3                                         call    ebx ; atoi; MSVCRT
00419909  83 c4 04                                      add     esp, 4
0041990C  8d 55 ec                                      lea     edx, [ebp+String]
0041990F  8d 4d d4                                      lea     ecx, [ebp+var_2C]; this
00419912  89 86 c4 01 00 00                             mov     [esi+1C4h], eax
00419918  52                                            push    edx; struct CString *
00419919  e8 ec 0e 00 00                                call    ?ReadString@CStdioFile@@UAEHAAVCString@@@Z; CStdioFile::ReadString(CString &)
0041991E  85 c0                                         test    eax, eax
00419920  0f 84 9b 00 00 00                             jz      loc_4199C1
00419926  8b 45 ec                                      mov     eax, [ebp+String]
00419929  50                                            push    eax; String
0041992A  ff d3                                         call    ebx ; atoi; MSVCRT
0041992C  83 c4 04                                      add     esp, 4
0041992F  8d 4d ec                                      lea     ecx, [ebp+String]
00419932  89 86 c8 01 00 00                             mov     [esi+1C8h], eax
00419938  51                                            push    ecx; struct CString *
00419939  8d 4d d4                                      lea     ecx, [ebp+var_2C]; this
0041993C  e8 c9 0e 00 00                                call    ?ReadString@CStdioFile@@UAEHAAVCString@@@Z; CStdioFile::ReadString(CString &)
00419941  85 c0                                         test    eax, eax
00419943  74 7c                                         jz      short loc_4199C1
00419945  8b 55 ec                                      mov     edx, [ebp+String]
00419948  52                                            push    edx; String
00419949  ff d3                                         call    ebx ; atoi; MSVCRT
0041994B  83 c4 04                                      add     esp, 4
0041994E  89 86 cc 01 00 00                             mov     [esi+1CCh], eax
00419954  8d 45 ec                                      lea     eax, [ebp+String]
00419957  8d 4d d4                                      lea     ecx, [ebp+var_2C]; this
0041995A  50                                            push    eax; struct CString *
0041995B  e8 aa 0e 00 00                                call    ?ReadString@CStdioFile@@UAEHAAVCString@@@Z; CStdioFile::ReadString(CString &)
00419960  85 c0                                         test    eax, eax
00419962  74 5d                                         jz      short loc_4199C1
00419964  8b 4d ec                                      mov     ecx, [ebp+String]
00419967  51                                            push    ecx; String
00419968  ff d3                                         call    ebx ; atoi; MSVCRT
0041996A  83 c4 04                                      add     esp, 4
0041996D  8d 55 ec                                      lea     edx, [ebp+String]
00419970  8d 4d d4                                      lea     ecx, [ebp+var_2C]; this
00419973  89 86 d0 01 00 00                             mov     [esi+1D0h], eax
00419979  52                                            push    edx; struct CString *
0041997A  e8 8b 0e 00 00                                call    ?ReadString@CStdioFile@@UAEHAAVCString@@@Z; CStdioFile::ReadString(CString &)
0041997F  85 c0                                         test    eax, eax
00419981  74 3e                                         jz      short loc_4199C1
00419983  8b 45 ec                                      mov     eax, [ebp+String]
00419986  50                                            push    eax; String
00419987  ff d3                                         call    ebx ; atoi; MSVCRT
00419989  83 c4 04                                      add     esp, 4
0041998C  8d 4d ec                                      lea     ecx, [ebp+String]
0041998F  89 86 d8 01 00 00                             mov     [esi+1D8h], eax
00419995  51                                            push    ecx; struct CString *
00419996  8d 4d d4                                      lea     ecx, [ebp+var_2C]; this
00419999  e8 6c 0e 00 00                                call    ?ReadString@CStdioFile@@UAEHAAVCString@@@Z; CStdioFile::ReadString(CString &)
0041999E  85 c0                                         test    eax, eax
004199A0  74 1f                                         jz      short loc_4199C1
004199A2  8b 55 ec                                      mov     edx, [ebp+String]
004199A5  52                                            push    edx; String
004199A6  ff d3                                         call    ebx ; atoi; MSVCRT
004199A8  83 c4 04                                      add     esp, 4
004199AB  89 86 dc 01 00 00                             mov     [esi+1DCh], eax
004199B1  8d 45 ec                                      lea     eax, [ebp+String]
004199B4  8d 4d d4                                      lea     ecx, [ebp+var_2C]; this
004199B7  50                                            push    eax; struct CString *
004199B8  e8 4d 0e 00 00                                call    ?ReadString@CStdioFile@@UAEHAAVCString@@@Z; CStdioFile::ReadString(CString &)
004199BD  85 c0                                         test    eax, eax
004199BF  75 1f                                         jnz     short loc_4199E0
004199C1  6a 00                                         push    0; unsigned int
004199C3  6a 00                                         push    0; unsigned int
004199C5  68 30 ee 42 00                                push    offset byte_42EE30; char *
004199CA  c6 45 fc 01                                   mov     byte ptr [ebp+var_4], 1
004199CE  e8 3f 0c 00 00                                call    ?AfxMessageBox@@YGHPBDII@Z; AfxMessageBox(char const *,uint,uint)
004199D3  8d 4d d4                                      lea     ecx, [ebp+var_2C]; this
004199D6  e8 73 0c 00 00                                call    ?Close@CStdioFile@@UAEXXZ; CStdioFile::Close(void)
004199DB  e9 80 00 00 00                                jmp     loc_419A60
004199E0  8b 4d ec                                      mov     ecx, [ebp+String]
004199E3  51                                            push    ecx; String
004199E4  ff d3                                         call    ebx ; atoi; MSVCRT
004199E6  83 c4 04                                      add     esp, 4
004199E9  8d 4d d4                                      lea     ecx, [ebp+var_2C]; this
004199EC  89 86 d4 01 00 00                             mov     [esi+1D4h], eax
004199F2  c7 45 fc 01 00 00 00                          mov     [ebp+var_4], 1
004199F9  e8 50 0c 00 00                                call    ?Close@CStdioFile@@UAEXXZ; CStdioFile::Close(void)
004199FE  eb 60                                         jmp     short loc_419A60
00419A00  8b 55 cc                                      mov     edx, [ebp+var_34]
00419A03  8b 45 c8                                      mov     eax, [ebp+var_38]
00419A06  52                                            push    edx
00419A07  50                                            push    eax
00419A08  8d 4d ec                                      lea     ecx, [ebp+String]
00419A0B  68 14 ee 42 00                                push    offset byte_42EE14; char *
00419A10  51                                            push    ecx; this
00419A11  c6 45 fc 04                                   mov     byte ptr [ebp+var_4], 4
00419A15  e8 f2 0b 00 00                                call    ?Format@CString@@QAAXPBDZZ; CString::Format(char const *,...)
00419A1A  8b 55 ec                                      mov     edx, [ebp+String]
00419A1D  83 c4 10                                      add     esp, 10h
00419A20  6a 00                                         push    0; unsigned int
00419A22  6a 00                                         push    0; unsigned int
00419A24  52                                            push    edx; char *
00419A25  e8 e8 0b 00 00                                call    ?AfxMessageBox@@YGHPBDII@Z; AfxMessageBox(char const *,uint,uint)
00419A2A  c7 45 c0 84 c5 41 00                          mov     [ebp+var_40], offset off_41C584
00419A31  8d 4d d0                                      lea     ecx, [ebp+var_30]; this
00419A34  c6 45 fc 05                                   mov     byte ptr [ebp+var_4], 5
00419A38  e8 c9 0b 00 00                                call    ??1CString@@QAE@XZ; CString::~CString(void)
00419A3D  c6 45 fc 03                                   mov     byte ptr [ebp+var_4], 3
00419A41  b8 47 9a 41 00                                mov     eax, offset loc_419A47
00419A46  c3                                            retn
00419A47  8b 75 e8                                      mov     esi, [ebp+var_18]
00419A4A  8b 1d fc c2 41 00                             mov     ebx, ds:atoi; MSVCRT
00419A50  8d 4d d4                                      lea     ecx, [ebp+var_2C]; this
00419A53  e8 f6 0b 00 00                                call    ?Close@CStdioFile@@UAEXXZ; CStdioFile::Close(void)
00419A58  eb 06                                         jmp     short loc_419A60
00419A5A  8b 1d fc c2 41 00                             mov     ebx, ds:atoi; MSVCRT
00419A60  6a 00                                         push    0; struct CFileException *
00419A62  68 20 40 00 00                                push    4020h; unsigned int
00419A67  68 e8 f7 41 00                                push    offset aSan9pkhardpers; "San9PKHardPerson.txt"
00419A6C  8d 4d d4                                      lea     ecx, [ebp+var_2C]; this
00419A6F  e8 e6 0b 00 00                                call    ?Open@CStdioFile@@UAEHPBDIPAVCFileException@@@Z; CStdioFile::Open(char const *,uint,CFileException *)
00419A74  85 c0                                         test    eax, eax
00419A76  0f 84 1b 01 00 00                             jz      loc_419B97
00419A7C  c6 45 fc 06                                   mov     byte ptr [ebp+var_4], 6
00419A80  33 ff                                         xor     edi, edi
00419A82  81 ff 20 03 00 00                             cmp     edi, 320h
00419A88  7d 23                                         jge     short loc_419AAD
00419A8A  8d 45 ec                                      lea     eax, [ebp+String]
00419A8D  8d 4d d4                                      lea     ecx, [ebp+var_2C]; this
00419A90  50                                            push    eax; struct CString *
00419A91  e8 74 0d 00 00                                call    ?ReadString@CStdioFile@@UAEHAAVCString@@@Z; CStdioFile::ReadString(CString &)
00419A96  85 c0                                         test    eax, eax
00419A98  74 77                                         jz      short loc_419B11
00419A9A  8b 4d ec                                      mov     ecx, [ebp+String]
00419A9D  51                                            push    ecx; String
00419A9E  ff d3                                         call    ebx ; atoi; MSVCRT
00419AA0  83 c4 04                                      add     esp, 4
00419AA3  89 84 be f4 01 00 00                          mov     [esi+edi*4+1F4h], eax
00419AAA  47                                            inc     edi
00419AAB  eb d5                                         jmp     short loc_419A82
00419AAD  33 ff                                         xor     edi, edi
00419AAF  8d 55 ec                                      lea     edx, [ebp+String]
00419AB2  83 ff 74                                      cmp     edi, 74h ; 't'
00419AB5  52                                            push    edx; struct CString *
00419AB6  8d 4d d4                                      lea     ecx, [ebp+var_2C]; this
00419AB9  7d 4d                                         jge     short loc_419B08
00419ABB  e8 4a 0d 00 00                                call    ?ReadString@CStdioFile@@UAEHAAVCString@@@Z; CStdioFile::ReadString(CString &)
00419AC0  85 c0                                         test    eax, eax
00419AC2  74 4d                                         jz      short loc_419B11
00419AC4  8b 45 ec                                      mov     eax, [ebp+String]
00419AC7  50                                            push    eax; String
00419AC8  ff d3                                         call    ebx ; atoi; MSVCRT
00419ACA  8d 0c 7f                                      lea     ecx, [edi+edi*2]
00419ACD  8b d0                                         mov     edx, eax
00419ACF  81 e2 ff 03 00 00                             and     edx, 3FFh
00419AD5  83 c4 04                                      add     esp, 4
00419AD8  8d 0c 4e                                      lea     ecx, [esi+ecx*2]
00419ADB  66 89 91 78 0e 00 00                          mov     [ecx+0E78h], dx
00419AE2  8b d0                                         mov     edx, eax
00419AE4  c1 fa 0a                                      sar     edx, 0Ah
00419AE7  81 e2 ff 03 00 00                             and     edx, 3FFh
00419AED  66 89 91 7a 0e 00 00                          mov     [ecx+0E7Ah], dx
00419AF4  8d 8c 7f 3e 07 00 00                          lea     ecx, [edi+edi*2+73Eh]
00419AFB  c1 f8 14                                      sar     eax, 14h
00419AFE  83 e0 3f                                      and     eax, 3Fh
00419B01  47                                            inc     edi
00419B02  66 89 04 4e                                   mov     [esi+ecx*2], ax
00419B06  eb a7                                         jmp     short loc_419AAF
00419B08  e8 fd 0c 00 00                                call    ?ReadString@CStdioFile@@UAEHAAVCString@@@Z; CStdioFile::ReadString(CString &)
00419B0D  85 c0                                         test    eax, eax
00419B0F  75 14                                         jnz     short loc_419B25
00419B11  6a 00                                         push    0; unsigned int
00419B13  6a 00                                         push    0; unsigned int
00419B15  68 00 ee 42 00                                push    offset byte_42EE00; char *
00419B1A  c6 45 fc 01                                   mov     byte ptr [ebp+var_4], 1
00419B1E  e8 ef 0a 00 00                                call    ?AfxMessageBox@@YGHPBDII@Z; AfxMessageBox(char const *,uint,uint)
00419B23  eb 6a                                         jmp     short loc_419B8F
00419B25  8b 45 ec                                      mov     eax, [ebp+String]
00419B28  50                                            push    eax; String
00419B29  ff d3                                         call    ebx ; atoi; MSVCRT
00419B2B  83 c4 04                                      add     esp, 4
00419B2E  66 89 86 38 11 00 00                          mov     [esi+1138h], ax
00419B35  c7 45 fc 01 00 00 00                          mov     [ebp+var_4], 1
00419B3C  eb 51                                         jmp     short loc_419B8F
00419B3E  8b 4d cc                                      mov     ecx, [ebp+var_34]
00419B41  8b 55 c8                                      mov     edx, [ebp+var_38]
00419B44  51                                            push    ecx
00419B45  52                                            push    edx
00419B46  8d 45 ec                                      lea     eax, [ebp+String]
00419B49  68 e4 ed 42 00                                push    offset byte_42EDE4; char *
00419B4E  50                                            push    eax; this
00419B4F  c6 45 fc 08                                   mov     byte ptr [ebp+var_4], 8
00419B53  e8 b4 0a 00 00                                call    ?Format@CString@@QAAXPBDZZ; CString::Format(char const *,...)
00419B58  8b 4d ec                                      mov     ecx, [ebp+String]
00419B5B  83 c4 10                                      add     esp, 10h
00419B5E  6a 00                                         push    0; unsigned int
00419B60  6a 00                                         push    0; unsigned int
00419B62  51                                            push    ecx; char *
00419B63  e8 aa 0a 00 00                                call    ?AfxMessageBox@@YGHPBDII@Z; AfxMessageBox(char const *,uint,uint)
00419B68  c7 45 c0 84 c5 41 00                          mov     [ebp+var_40], offset off_41C584
00419B6F  8d 4d d0                                      lea     ecx, [ebp+var_30]; this
00419B72  c6 45 fc 09                                   mov     byte ptr [ebp+var_4], 9
00419B76  e8 8b 0a 00 00                                call    ??1CString@@QAE@XZ; CString::~CString(void)
00419B7B  c6 45 fc 07                                   mov     byte ptr [ebp+var_4], 7
00419B7F  c7 45 c0 70 c5 41 00                          mov     [ebp+var_40], offset off_41C570
00419B86  b8 8c 9b 41 00                                mov     eax, offset loc_419B8C
00419B8B  c3                                            retn
00419B8C  8b 75 e8                                      mov     esi, [ebp+var_18]
00419B8F  8d 4d d4                                      lea     ecx, [ebp+var_2C]; this
00419B92  e8 b7 0a 00 00                                call    ?Close@CStdioFile@@UAEXXZ; CStdioFile::Close(void)
00419B97  6a 00                                         push    0; char
00419B99  8b ce                                         mov     ecx, esi; struct CWnd *
00419B9B  e8 40 00 00 00                                call    sub_419BE0
00419BA0  8b ce                                         mov     ecx, esi
00419BA2  e8 c9 02 00 00                                call    sub_419E70
00419BA7  8b ce                                         mov     ecx, esi
00419BA9  e8 02 04 00 00                                call    sub_419FB0
00419BAE  8d 4d ec                                      lea     ecx, [ebp+String]; this
00419BB1  c6 45 fc 00                                   mov     byte ptr [ebp+var_4], 0
00419BB5  e8 4c 0a 00 00                                call    ??1CString@@QAE@XZ; CString::~CString(void)
00419BBA  8d 4d d4                                      lea     ecx, [ebp+var_2C]; this
00419BBD  c7 45 fc ff ff ff ff                          mov     [ebp+var_4], 0FFFFFFFFh
00419BC4  e8 7f 0a 00 00                                call    ??1CStdioFile@@UAE@XZ; CStdioFile::~CStdioFile(void)
00419BC9  8b 4d f4                                      mov     ecx, [ebp+var_C]
00419BCC  5f                                            pop     edi
00419BCD  5e                                            pop     esi
00419BCE  64 89 0d 00 00 00 00                          mov     large fs:0, ecx
00419BD5  5b                                            pop     ebx
00419BD6  8b e5                                         mov     esp, ebp
00419BD8  5d                                            pop     ebp
00419BD9  c3                                            retn
0041B1F0  8d 4d d4                                      lea     ecx, [ebp+var_2C]; this
0041B1F3  e9 50 f4 ff ff                                jmp     ??1CStdioFile@@UAE@XZ; CStdioFile::~CStdioFile(void)
0041B1F8  8d 4d ec                                      lea     ecx, [ebp+String]; this
0041B1FB  e9 06 f4 ff ff                                jmp     ??1CString@@QAE@XZ; CString::~CString(void)
0041B200  8d 4d c0                                      lea     ecx, [ebp+var_40]
0041B203  e9 c8 67 fe ff                                jmp     sub_4019D0
0041B208  8d 4d c0                                      lea     ecx, [ebp+var_40]
0041B20B  e9 90 67 fe ff                                jmp     sub_4019A0
0041B210  8d 4d c0                                      lea     ecx, [ebp+var_40]
0041B213  e9 b8 67 fe ff                                jmp     sub_4019D0
0041B218  8d 4d c0                                      lea     ecx, [ebp+var_40]
0041B21B  e9 80 67 fe ff                                jmp     sub_4019A0
0041B220  b8 90 da 41 00                                mov     eax, offset stru_41DA90
0041B225  e9 f2 f5 ff ff                                jmp     __CxxFrameHandler
