00404C70  53                                            push    ebx
00404C71  56                                            push    esi
00404C72  8b 74 24 0c                                   mov     esi, [esp+8+arg_0]
00404C76  57                                            push    edi
00404C77  8b f9                                         mov     edi, ecx
00404C79  8d 47 60                                      lea     eax, [edi+60h]
00404C7C  50                                            push    eax; struct CWnd *
00404C7D  68 5f 04 00 00                                push    45Fh; int
00404C82  56                                            push    esi; struct CDataExchange *
00404C83  e8 78 59 01 00                                call    ?DDX_Control@@YGXPAVCDataExchange@@HAAVCWnd@@@Z; DDX_Control(CDataExchange *,int,CWnd &)
00404C88  8d 8f a0 00 00 00                             lea     ecx, [edi+0A0h]
00404C8E  51                                            push    ecx; struct CWnd *
00404C8F  68 5b 04 00 00                                push    45Bh; int
00404C94  56                                            push    esi; struct CDataExchange *
00404C95  e8 66 59 01 00                                call    ?DDX_Control@@YGXPAVCDataExchange@@HAAVCWnd@@@Z; DDX_Control(CDataExchange *,int,CWnd &)
00404C9A  8d 9f e0 00 00 00                             lea     ebx, [edi+0E0h]
00404CA0  53                                            push    ebx; struct CString *
00404CA1  68 13 04 00 00                                push    413h; int
00404CA6  56                                            push    esi; struct CDataExchange *
00404CA7  e8 6e 5a 01 00                                call    ?DDX_Text@@YGXPAVCDataExchange@@HAAVCString@@@Z; DDX_Text(CDataExchange *,int,CString &)
00404CAC  6a 08                                         push    8; int
00404CAE  53                                            push    ebx; struct CString *
00404CAF  56                                            push    esi; struct CDataExchange *
00404CB0  e8 5f 5a 01 00                                call    ?DDV_MaxChars@@YGXPAVCDataExchange@@ABVCString@@H@Z; DDV_MaxChars(CDataExchange *,CString const &,int)
00404CB5  8d 97 e4 00 00 00                             lea     edx, [edi+0E4h]
00404CBB  52                                            push    edx; int *
00404CBC  68 20 04 00 00                                push    420h; int
00404CC1  56                                            push    esi; struct CDataExchange *
00404CC2  e8 47 5a 01 00                                call    ?DDX_Radio@@YGXPAVCDataExchange@@HAAH@Z; DDX_Radio(CDataExchange *,int,int &)
00404CC7  8d 87 e8 00 00 00                             lea     eax, [edi+0E8h]
00404CCD  50                                            push    eax; int *
00404CCE  68 24 04 00 00                                push    424h; int
00404CD3  56                                            push    esi; struct CDataExchange *
00404CD4  e8 35 5a 01 00                                call    ?DDX_Radio@@YGXPAVCDataExchange@@HAAH@Z; DDX_Radio(CDataExchange *,int,int &)
00404CD9  8d 8f ec 00 00 00                             lea     ecx, [edi+0ECh]
00404CDF  51                                            push    ecx; int *
00404CE0  68 28 04 00 00                                push    428h; int
00404CE5  56                                            push    esi; struct CDataExchange *
00404CE6  e8 23 5a 01 00                                call    ?DDX_Radio@@YGXPAVCDataExchange@@HAAH@Z; DDX_Radio(CDataExchange *,int,int &)
00404CEB  8d 97 f0 00 00 00                             lea     edx, [edi+0F0h]
00404CF1  52                                            push    edx; int *
00404CF2  68 2c 04 00 00                                push    42Ch; int
00404CF7  56                                            push    esi; struct CDataExchange *
00404CF8  e8 11 5a 01 00                                call    ?DDX_Radio@@YGXPAVCDataExchange@@HAAH@Z; DDX_Radio(CDataExchange *,int,int &)
00404CFD  8d 87 f4 00 00 00                             lea     eax, [edi+0F4h]
00404D03  50                                            push    eax; int *
00404D04  68 34 04 00 00                                push    434h; int
00404D09  56                                            push    esi; struct CDataExchange *
00404D0A  e8 ff 59 01 00                                call    ?DDX_Radio@@YGXPAVCDataExchange@@HAAH@Z; DDX_Radio(CDataExchange *,int,int &)
00404D0F  8d 8f f8 00 00 00                             lea     ecx, [edi+0F8h]
00404D15  51                                            push    ecx; int *
00404D16  68 38 04 00 00                                push    438h; int
00404D1B  56                                            push    esi; struct CDataExchange *
00404D1C  e8 ed 59 01 00                                call    ?DDX_Radio@@YGXPAVCDataExchange@@HAAH@Z; DDX_Radio(CDataExchange *,int,int &)
00404D21  8d 97 fc 00 00 00                             lea     edx, [edi+0FCh]
00404D27  52                                            push    edx; int *
00404D28  68 3c 04 00 00                                push    43Ch; int
00404D2D  56                                            push    esi; struct CDataExchange *
00404D2E  e8 db 59 01 00                                call    ?DDX_Radio@@YGXPAVCDataExchange@@HAAH@Z; DDX_Radio(CDataExchange *,int,int &)
00404D33  8d 87 00 01 00 00                             lea     eax, [edi+100h]
00404D39  50                                            push    eax; int *
00404D3A  68 40 04 00 00                                push    440h; int
00404D3F  56                                            push    esi; struct CDataExchange *
00404D40  e8 c9 59 01 00                                call    ?DDX_Radio@@YGXPAVCDataExchange@@HAAH@Z; DDX_Radio(CDataExchange *,int,int &)
00404D45  8d 8f 04 01 00 00                             lea     ecx, [edi+104h]
00404D4B  51                                            push    ecx; int *
00404D4C  68 30 04 00 00                                push    430h; int
00404D51  56                                            push    esi; struct CDataExchange *
00404D52  e8 b7 59 01 00                                call    ?DDX_Radio@@YGXPAVCDataExchange@@HAAH@Z; DDX_Radio(CDataExchange *,int,int &)
00404D57  8d 9f 08 01 00 00                             lea     ebx, [edi+108h]
00404D5D  53                                            push    ebx; unsigned __int8 *
00404D5E  68 44 04 00 00                                push    444h; int
00404D63  56                                            push    esi; struct CDataExchange *
00404D64  e8 9f 59 01 00                                call    ?DDX_Text@@YGXPAVCDataExchange@@HAAE@Z; DDX_Text(CDataExchange *,int,uchar &)
00404D69  8a 13                                         mov     dl, [ebx]
00404D6B  6a 73                                         push    73h ; 's'; unsigned __int8
00404D6D  6a 00                                         push    0; unsigned __int8
00404D6F  52                                            push    edx; unsigned __int8
00404D70  56                                            push    esi; struct CDataExchange *
00404D71  e8 8c 59 01 00                                call    ?DDV_MinMaxByte@@YGXPAVCDataExchange@@EEE@Z; DDV_MinMaxByte(CDataExchange *,uchar,uchar,uchar)
00404D76  8d 9f 09 01 00 00                             lea     ebx, [edi+109h]
00404D7C  53                                            push    ebx; unsigned __int8 *
00404D7D  68 46 04 00 00                                push    446h; int
00404D82  56                                            push    esi; struct CDataExchange *
00404D83  e8 80 59 01 00                                call    ?DDX_Text@@YGXPAVCDataExchange@@HAAE@Z; DDX_Text(CDataExchange *,int,uchar &)
00404D88  8a 03                                         mov     al, [ebx]
00404D8A  6a 73                                         push    73h ; 's'; unsigned __int8
00404D8C  6a 00                                         push    0; unsigned __int8
00404D8E  50                                            push    eax; unsigned __int8
00404D8F  56                                            push    esi; struct CDataExchange *
00404D90  e8 6d 59 01 00                                call    ?DDV_MinMaxByte@@YGXPAVCDataExchange@@EEE@Z; DDV_MinMaxByte(CDataExchange *,uchar,uchar,uchar)
00404D95  8d 9f 0a 01 00 00                             lea     ebx, [edi+10Ah]
00404D9B  53                                            push    ebx; unsigned __int8 *
00404D9C  68 45 04 00 00                                push    445h; int
00404DA1  56                                            push    esi; struct CDataExchange *
00404DA2  e8 61 59 01 00                                call    ?DDX_Text@@YGXPAVCDataExchange@@HAAE@Z; DDX_Text(CDataExchange *,int,uchar &)
00404DA7  8a 0b                                         mov     cl, [ebx]
00404DA9  6a 73                                         push    73h ; 's'; unsigned __int8
00404DAB  6a 00                                         push    0; unsigned __int8
00404DAD  51                                            push    ecx; unsigned __int8
00404DAE  56                                            push    esi; struct CDataExchange *
00404DAF  e8 4e 59 01 00                                call    ?DDV_MinMaxByte@@YGXPAVCDataExchange@@EEE@Z; DDV_MinMaxByte(CDataExchange *,uchar,uchar,uchar)
00404DB4  8d 9f 0b 01 00 00                             lea     ebx, [edi+10Bh]
00404DBA  53                                            push    ebx; unsigned __int8 *
00404DBB  68 47 04 00 00                                push    447h; int
00404DC0  56                                            push    esi; struct CDataExchange *
00404DC1  e8 42 59 01 00                                call    ?DDX_Text@@YGXPAVCDataExchange@@HAAE@Z; DDX_Text(CDataExchange *,int,uchar &)
00404DC6  8a 13                                         mov     dl, [ebx]
00404DC8  6a 73                                         push    73h ; 's'; unsigned __int8
00404DCA  6a 00                                         push    0; unsigned __int8
00404DCC  52                                            push    edx; unsigned __int8
00404DCD  56                                            push    esi; struct CDataExchange *
00404DCE  e8 2f 59 01 00                                call    ?DDV_MinMaxByte@@YGXPAVCDataExchange@@EEE@Z; DDV_MinMaxByte(CDataExchange *,uchar,uchar,uchar)
00404DD3  8d 87 0c 01 00 00                             lea     eax, [edi+10Ch]
00404DD9  50                                            push    eax; int *
00404DDA  68 48 04 00 00                                push    448h; int
00404DDF  56                                            push    esi; struct CDataExchange *
00404DE0  e8 99 58 01 00                                call    ?DDX_Check@@YGXPAVCDataExchange@@HAAH@Z; DDX_Check(CDataExchange *,int,int &)
00404DE5  8d 8f 10 01 00 00                             lea     ecx, [edi+110h]
00404DEB  51                                            push    ecx; int *
00404DEC  68 50 04 00 00                                push    450h; int
00404DF1  56                                            push    esi; struct CDataExchange *
00404DF2  e8 87 58 01 00                                call    ?DDX_Check@@YGXPAVCDataExchange@@HAAH@Z; DDX_Check(CDataExchange *,int,int &)
00404DF7  8d 97 14 01 00 00                             lea     edx, [edi+114h]
00404DFD  52                                            push    edx; int *
00404DFE  68 4d 04 00 00                                push    44Dh; int
00404E03  56                                            push    esi; struct CDataExchange *
00404E04  e8 75 58 01 00                                call    ?DDX_Check@@YGXPAVCDataExchange@@HAAH@Z; DDX_Check(CDataExchange *,int,int &)
00404E09  8d 87 18 01 00 00                             lea     eax, [edi+118h]
00404E0F  50                                            push    eax; int *
00404E10  68 4a 04 00 00                                push    44Ah; int
00404E15  56                                            push    esi; struct CDataExchange *
00404E16  e8 63 58 01 00                                call    ?DDX_Check@@YGXPAVCDataExchange@@HAAH@Z; DDX_Check(CDataExchange *,int,int &)
00404E1B  8d 8f 1c 01 00 00                             lea     ecx, [edi+11Ch]
00404E21  51                                            push    ecx; int *
00404E22  68 4f 04 00 00                                push    44Fh; int
00404E27  56                                            push    esi; struct CDataExchange *
00404E28  e8 51 58 01 00                                call    ?DDX_Check@@YGXPAVCDataExchange@@HAAH@Z; DDX_Check(CDataExchange *,int,int &)
00404E2D  8d 97 20 01 00 00                             lea     edx, [edi+120h]
00404E33  52                                            push    edx; int *
00404E34  68 4b 04 00 00                                push    44Bh; int
00404E39  56                                            push    esi; struct CDataExchange *
00404E3A  e8 3f 58 01 00                                call    ?DDX_Check@@YGXPAVCDataExchange@@HAAH@Z; DDX_Check(CDataExchange *,int,int &)
00404E3F  8d 87 24 01 00 00                             lea     eax, [edi+124h]
00404E45  50                                            push    eax; int *
00404E46  68 49 04 00 00                                push    449h; int
00404E4B  56                                            push    esi; struct CDataExchange *
00404E4C  e8 2d 58 01 00                                call    ?DDX_Check@@YGXPAVCDataExchange@@HAAH@Z; DDX_Check(CDataExchange *,int,int &)
00404E51  8d 8f 28 01 00 00                             lea     ecx, [edi+128h]
00404E57  51                                            push    ecx; int *
00404E58  68 4c 04 00 00                                push    44Ch; int
00404E5D  56                                            push    esi; struct CDataExchange *
00404E5E  e8 1b 58 01 00                                call    ?DDX_Check@@YGXPAVCDataExchange@@HAAH@Z; DDX_Check(CDataExchange *,int,int &)
00404E63  8d 97 2c 01 00 00                             lea     edx, [edi+12Ch]
00404E69  52                                            push    edx; int *
00404E6A  68 4e 04 00 00                                push    44Eh; int
00404E6F  56                                            push    esi; struct CDataExchange *
00404E70  e8 09 58 01 00                                call    ?DDX_Check@@YGXPAVCDataExchange@@HAAH@Z; DDX_Check(CDataExchange *,int,int &)
00404E75  8d 87 30 01 00 00                             lea     eax, [edi+130h]
00404E7B  50                                            push    eax; __int16 *
00404E7C  68 51 04 00 00                                push    451h; int
00404E81  56                                            push    esi; struct CDataExchange *
00404E82  e8 75 58 01 00                                call    ?DDX_Text@@YGXPAVCDataExchange@@HAAF@Z; DDX_Text(CDataExchange *,int,short &)
00404E87  8d 8f 32 01 00 00                             lea     ecx, [edi+132h]
00404E8D  51                                            push    ecx; __int16 *
00404E8E  68 59 04 00 00                                push    459h; int
00404E93  56                                            push    esi; struct CDataExchange *
00404E94  e8 63 58 01 00                                call    ?DDX_Text@@YGXPAVCDataExchange@@HAAF@Z; DDX_Text(CDataExchange *,int,short &)
00404E99  8d 97 34 01 00 00                             lea     edx, [edi+134h]
00404E9F  52                                            push    edx; __int16 *
00404EA0  68 56 04 00 00                                push    456h; int
00404EA5  56                                            push    esi; struct CDataExchange *
00404EA6  e8 51 58 01 00                                call    ?DDX_Text@@YGXPAVCDataExchange@@HAAF@Z; DDX_Text(CDataExchange *,int,short &)
00404EAB  8d 87 36 01 00 00                             lea     eax, [edi+136h]
00404EB1  50                                            push    eax; __int16 *
00404EB2  68 53 04 00 00                                push    453h; int
00404EB7  56                                            push    esi; struct CDataExchange *
00404EB8  e8 3f 58 01 00                                call    ?DDX_Text@@YGXPAVCDataExchange@@HAAF@Z; DDX_Text(CDataExchange *,int,short &)
00404EBD  8d 8f 38 01 00 00                             lea     ecx, [edi+138h]
00404EC3  51                                            push    ecx; __int16 *
00404EC4  68 58 04 00 00                                push    458h; int
00404EC9  56                                            push    esi; struct CDataExchange *
00404ECA  e8 2d 58 01 00                                call    ?DDX_Text@@YGXPAVCDataExchange@@HAAF@Z; DDX_Text(CDataExchange *,int,short &)
00404ECF  8d 97 3a 01 00 00                             lea     edx, [edi+13Ah]
00404ED5  52                                            push    edx; __int16 *
00404ED6  68 54 04 00 00                                push    454h; int
00404EDB  56                                            push    esi; struct CDataExchange *
00404EDC  e8 1b 58 01 00                                call    ?DDX_Text@@YGXPAVCDataExchange@@HAAF@Z; DDX_Text(CDataExchange *,int,short &)
00404EE1  8d 87 3c 01 00 00                             lea     eax, [edi+13Ch]
00404EE7  50                                            push    eax; __int16 *
00404EE8  68 52 04 00 00                                push    452h; int
00404EED  56                                            push    esi; struct CDataExchange *
00404EEE  e8 09 58 01 00                                call    ?DDX_Text@@YGXPAVCDataExchange@@HAAF@Z; DDX_Text(CDataExchange *,int,short &)
00404EF3  8d 8f 3e 01 00 00                             lea     ecx, [edi+13Eh]
00404EF9  51                                            push    ecx; __int16 *
00404EFA  68 55 04 00 00                                push    455h; int
00404EFF  56                                            push    esi; struct CDataExchange *
00404F00  e8 f7 57 01 00                                call    ?DDX_Text@@YGXPAVCDataExchange@@HAAF@Z; DDX_Text(CDataExchange *,int,short &)
00404F05  8d 97 40 01 00 00                             lea     edx, [edi+140h]
00404F0B  52                                            push    edx; __int16 *
00404F0C  68 57 04 00 00                                push    457h; int
00404F11  56                                            push    esi; struct CDataExchange *
00404F12  e8 e5 57 01 00                                call    ?DDX_Text@@YGXPAVCDataExchange@@HAAF@Z; DDX_Text(CDataExchange *,int,short &)
00404F17  8d 9f 42 01 00 00                             lea     ebx, [edi+142h]
00404F1D  53                                            push    ebx; __int16 *
00404F1E  68 5e 04 00 00                                push    45Eh; int
00404F23  56                                            push    esi; struct CDataExchange *
00404F24  e8 d3 57 01 00                                call    ?DDX_Text@@YGXPAVCDataExchange@@HAAF@Z; DDX_Text(CDataExchange *,int,short &)
00404F29  0f bf 03                                      movsx   eax, word ptr [ebx]
00404F2C  6a 3c                                         push    3Ch ; '<'; int
00404F2E  6a 00                                         push    0; int
00404F30  50                                            push    eax; int
00404F31  56                                            push    esi; struct CDataExchange *
00404F32  e8 6b 57 01 00                                call    ?DDV_MinMaxInt@@YGXPAVCDataExchange@@HHH@Z; DDV_MinMaxInt(CDataExchange *,int,int,int)
00404F37  8d 9f 44 01 00 00                             lea     ebx, [edi+144h]
00404F3D  53                                            push    ebx; __int16 *
00404F3E  68 5c 04 00 00                                push    45Ch; int
00404F43  56                                            push    esi; struct CDataExchange *
00404F44  e8 b3 57 01 00                                call    ?DDX_Text@@YGXPAVCDataExchange@@HAAF@Z; DDX_Text(CDataExchange *,int,short &)
00404F49  0f bf 0b                                      movsx   ecx, word ptr [ebx]
00404F4C  68 1f 03 00 00                                push    31Fh; int
00404F51  6a 00                                         push    0; int
00404F53  51                                            push    ecx; int
00404F54  56                                            push    esi; struct CDataExchange *
00404F55  e8 48 57 01 00                                call    ?DDV_MinMaxInt@@YGXPAVCDataExchange@@HHH@Z; DDV_MinMaxInt(CDataExchange *,int,int,int)
00404F5A  8d 9f 46 01 00 00                             lea     ebx, [edi+146h]
00404F60  53                                            push    ebx; __int16 *
00404F61  68 5d 04 00 00                                push    45Dh; int
00404F66  56                                            push    esi; struct CDataExchange *
00404F67  e8 90 57 01 00                                call    ?DDX_Text@@YGXPAVCDataExchange@@HAAF@Z; DDX_Text(CDataExchange *,int,short &)
00404F6C  0f bf 13                                      movsx   edx, word ptr [ebx]
00404F6F  68 1f 03 00 00                                push    31Fh; int
00404F74  6a 00                                         push    0; int
00404F76  52                                            push    edx; int
00404F77  56                                            push    esi; struct CDataExchange *
00404F78  e8 25 57 01 00                                call    ?DDV_MinMaxInt@@YGXPAVCDataExchange@@HHH@Z; DDV_MinMaxInt(CDataExchange *,int,int,int)
00404F7D  8d 9f 48 01 00 00                             lea     ebx, [edi+148h]
00404F83  53                                            push    ebx; unsigned int *
00404F84  68 15 04 00 00                                push    415h; int
00404F89  56                                            push    esi; struct CDataExchange *
00404F8A  e8 6b 56 01 00                                call    ?DDX_Text@@YGXPAVCDataExchange@@HAAI@Z; DDX_Text(CDataExchange *,int,uint &)
00404F8F  6a 73                                         push    73h ; 's'; unsigned int
00404F91  6a 00                                         push    0; unsigned int
00404F93  8b 03                                         mov     eax, [ebx]
00404F95  50                                            push    eax; unsigned int
00404F96  56                                            push    esi; struct CDataExchange *
00404F97  e8 58 56 01 00                                call    ?DDV_MinMaxUInt@@YGXPAVCDataExchange@@III@Z; DDV_MinMaxUInt(CDataExchange *,uint,uint,uint)
00404F9C  8d 9f 4c 01 00 00                             lea     ebx, [edi+14Ch]
00404FA2  53                                            push    ebx; struct CString *
00404FA3  68 6f 04 00 00                                push    46Fh; int
00404FA8  56                                            push    esi; struct CDataExchange *
00404FA9  e8 6c 57 01 00                                call    ?DDX_Text@@YGXPAVCDataExchange@@HAAVCString@@@Z; DDX_Text(CDataExchange *,int,CString &)
00404FAE  6a 06                                         push    6; int
00404FB0  53                                            push    ebx; struct CString *
00404FB1  56                                            push    esi; struct CDataExchange *
00404FB2  e8 5d 57 01 00                                call    ?DDV_MaxChars@@YGXPAVCDataExchange@@ABVCString@@H@Z; DDV_MaxChars(CDataExchange *,CString const &,int)
00404FB7  81 c7 50 01 00 00                             add     edi, 150h
00404FBD  57                                            push    edi; unsigned int *
00404FBE  68 60 04 00 00                                push    460h; int
00404FC3  56                                            push    esi; struct CDataExchange *
00404FC4  e8 31 56 01 00                                call    ?DDX_Text@@YGXPAVCDataExchange@@HAAI@Z; DDX_Text(CDataExchange *,int,uint &)
00404FC9  8b 0f                                         mov     ecx, [edi]
00404FCB  68 b8 0b 00 00                                push    0BB8h; unsigned int
00404FD0  68 b0 04 00 00                                push    4B0h; unsigned int
00404FD5  51                                            push    ecx; unsigned int
00404FD6  56                                            push    esi; struct CDataExchange *
00404FD7  e8 18 56 01 00                                call    ?DDV_MinMaxUInt@@YGXPAVCDataExchange@@III@Z; DDV_MinMaxUInt(CDataExchange *,uint,uint,uint)
00404FDC  5f                                            pop     edi
00404FDD  5e                                            pop     esi
00404FDE  5b                                            pop     ebx
00404FDF  c2 04 00                                      retn    4
