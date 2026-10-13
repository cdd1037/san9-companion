00408670  6a ff                                         push    0FFFFFFFFh
00408672  68 76 b1 41 00                                push    offset SEH_408670
00408677  64 a1 00 00 00 00                             mov     eax, large fs:0
0040867D  50                                            push    eax
0040867E  64 89 25 00 00 00 00                          mov     large fs:0, esp
00408685  51                                            push    ecx
00408686  8b 44 24 14                                   mov     eax, [esp+10h+arg_0]
0040868A  53                                            push    ebx
0040868B  55                                            push    ebp
0040868C  56                                            push    esi
0040868D  57                                            push    edi
0040868E  8b f1                                         mov     esi, ecx
00408690  50                                            push    eax; struct CWnd *
00408691  6a 66                                         push    66h ; 'f'; unsigned int
00408693  89 74 24 18                                   mov     [esp+28h+var_10], esi
00408697  e8 46 1f 01 00                                call    ??0CDialog@@QAE@IPAVCWnd@@@Z; CDialog::CDialog(uint,CWnd *)
0040869C  c7 86 34 11 00 00 de ff 43 00                 mov     dword ptr [esi+1134h], 43FFDEh
004086A6  c7 86 60 14 00 00 c4 4a 45 00                 mov     dword ptr [esi+1460h], 454AC4h
004086B0  c7 86 64 14 00 00 4d 00 00 00                 mov     dword ptr [esi+1464h], 4Dh ; 'M'
004086BA  c7 86 50 18 00 00 ef ca 40 00                 mov     dword ptr [esi+1850h], (offset loc_40CAEB+4)
004086C4  bd 32 00 00 00                                mov     ebp, 32h ; '2'
004086C9  c7 86 54 18 00 00 25 bf 40 00                 mov     dword ptr [esi+1854h], (offset loc_40BF1F+6)
004086D3  89 ae 58 18 00 00                             mov     [esi+1858h], ebp
004086D9  c7 86 5c 18 00 00 87 67 4b 00                 mov     dword ptr [esi+185Ch], 4B6787h
004086E3  c7 86 60 18 00 00 23 00 00 00                 mov     dword ptr [esi+1860h], 23h ; '#'
004086ED  c7 86 64 18 00 00 2d 00 00 00                 mov     dword ptr [esi+1864h], 2Dh ; '-'
004086F7  c7 86 68 18 00 00 b0 b0 50 00                 mov     dword ptr [esi+1868h], 50B0B0h
00408701  c7 86 6c 18 00 00 54 00 00 00                 mov     dword ptr [esi+186Ch], 54h ; 'T'
0040870B  c7 86 70 18 00 00 50 00 00 00                 mov     dword ptr [esi+1870h], 50h ; 'P'
00408715  bf ff 00 00 00                                mov     edi, 0FFh
0040871A  c7 86 74 18 00 00 40 b0 50 00                 mov     dword ptr [esi+1874h], 50B040h
00408724  bb 04 00 00 00                                mov     ebx, 4
00408729  89 be 78 18 00 00                             mov     [esi+1878h], edi
0040872F  89 9e 7c 18 00 00                             mov     [esi+187Ch], ebx
00408735  ba eb 14 6a 07                                mov     edx, 76A14EBh
0040873A  c7 86 80 18 00 00 63 6a 49 00                 mov     dword ptr [esi+1880h], 496A63h
00408744  b9 6a 02 6a 07                                mov     ecx, 76A026Ah
00408749  89 96 84 18 00 00                             mov     [esi+1884h], edx
0040874F  89 8e 88 18 00 00                             mov     [esi+1888h], ecx
00408755  c7 86 8c 18 00 00 f7 df 48 00                 mov     dword ptr [esi+188Ch], 48DFF7h
0040875F  89 96 90 18 00 00                             mov     [esi+1890h], edx
00408765  89 8e 94 18 00 00                             mov     [esi+1894h], ecx
0040876B  c7 86 98 18 00 00 29 2e 49 00                 mov     dword ptr [esi+1898h], 492E29h
00408775  89 96 9c 18 00 00                             mov     [esi+189Ch], edx
0040877B  89 8e a0 18 00 00                             mov     [esi+18A0h], ecx
00408781  c7 86 a4 18 00 00 b8 a2 48 00                 mov     dword ptr [esi+18A4h], 48A2B8h
0040878B  c7 86 a8 18 00 00 eb 35 6a 00                 mov     dword ptr [esi+18A8h], 6A35EBh
00408795  c7 86 ac 18 00 00 6a 01 6a 00                 mov     dword ptr [esi+18ACh], 6A016Ah
0040879F  c7 86 b0 18 00 00 c8 95 48 00                 mov     dword ptr [esi+18B0h], 4895C8h
004087A9  c7 86 b4 18 00 00 eb 14 6a 06                 mov     dword ptr [esi+18B4h], 66A14EBh
004087B3  c7 86 b8 18 00 00 6a 01 6a 06                 mov     dword ptr [esi+18B8h], 66A016Ah
004087BD  c7 86 bc 18 00 00 f2 c3 49 00                 mov     dword ptr [esi+18BCh], 49C3F2h
004087C7  89 be c0 18 00 00                             mov     [esi+18C0h], edi
004087CD  bf 06 00 00 00                                mov     edi, 6
004087D2  89 be c4 18 00 00                             mov     [esi+18C4h], edi
004087D8  c7 86 c8 18 00 00 91 37 49 00                 mov     dword ptr [esi+18C8h], 493791h
004087E2  b9 07 00 00 00                                mov     ecx, 7
004087E7  89 be cc 18 00 00                             mov     [esi+18CCh], edi
004087ED  89 8e d0 18 00 00                             mov     [esi+18D0h], ecx
004087F3  c7 86 d4 18 00 00 4f 3e 49 00                 mov     dword ptr [esi+18D4h], 493E4Fh
004087FD  89 be d8 18 00 00                             mov     [esi+18D8h], edi
00408803  89 8e dc 18 00 00                             mov     [esi+18DCh], ecx
00408809  c7 86 e0 18 00 00 81 e9 48 00                 mov     dword ptr [esi+18E0h], 48E981h
00408813  89 be e4 18 00 00                             mov     [esi+18E4h], edi
00408819  89 8e e8 18 00 00                             mov     [esi+18E8h], ecx
0040881F  c7 86 ec 18 00 00 d5 ef 48 00                 mov     dword ptr [esi+18ECh], 48EFD5h
00408829  b9 08 00 00 00                                mov     ecx, 8
0040882E  89 be f0 18 00 00                             mov     [esi+18F0h], edi
00408834  89 8e f4 18 00 00                             mov     [esi+18F4h], ecx
0040883A  c7 86 f8 18 00 00 f5 0e 49 00                 mov     dword ptr [esi+18F8h], 490EF5h
00408844  89 be fc 18 00 00                             mov     [esi+18FCh], edi
0040884A  89 8e 00 19 00 00                             mov     [esi+1900h], ecx
00408850  c7 86 04 19 00 00 3d 2a 49 00                 mov     dword ptr [esi+1904h], 492A3Dh
0040885A  89 ae 08 19 00 00                             mov     [esi+1908h], ebp
00408860  c7 86 0c 19 00 00 1e 00 00 00                 mov     dword ptr [esi+190Ch], 1Eh
0040886A  c7 86 10 19 00 00 8f 9b 4b 00                 mov     dword ptr [esi+1910h], 4B9B8Fh
00408874  c7 86 14 19 00 00 0e 00 00 00                 mov     dword ptr [esi+1914h], 0Eh
0040887E  89 be 18 19 00 00                             mov     [esi+1918h], edi
00408884  c7 86 1c 19 00 00 b6 9b 4b 00                 mov     dword ptr [esi+191Ch], 4B9BB6h
0040888E  c7 86 20 19 00 00 19 00 00 00                 mov     dword ptr [esi+1920h], 19h
00408898  c7 86 24 19 00 00 14 00 00 00                 mov     dword ptr [esi+1924h], 14h
004088A2  33 c0                                         xor     eax, eax
004088A4  c7 86 28 19 00 00 ca f4 43 00                 mov     dword ptr [esi+1928h], 43F4CAh
004088AE  c7 86 2c 19 00 00 00 40 b4 01                 mov     dword ptr [esi+192Ch], 1B44000h
004088B8  89 44 24 1c                                   mov     [esp+20h+var_4], eax
004088BC  c7 86 30 19 00 00 c8 18 00 00                 mov     dword ptr [esi+1930h], 18C8h
004088C6  c7 86 34 19 00 00 8a 4f 50 00                 mov     dword ptr [esi+1934h], 504F8Ah
004088D0  c7 86 38 19 00 00 da 40 a7 0d                 mov     dword ptr [esi+1938h], 0DA740DAh
004088DA  c7 86 3c 19 00 00 d3 4d 62 10                 mov     dword ptr [esi+193Ch], 10624DD3h
004088E4  bd 03 00 00 00                                mov     ebp, 3
004088E9  ba 33 00 00 00                                mov     edx, 33h ; '3'
004088EE  b9 85 00 00 00                                mov     ecx, 85h
004088F3  c7 86 40 19 00 00 fa ec 4f 00                 mov     dword ptr [esi+1940h], 4FECFAh
004088FD  c7 86 44 19 00 00 0e ee 4f 00                 mov     dword ptr [esi+1944h], 4FEE0Eh
00408907  c7 86 48 19 00 00 05 00 00 00                 mov     dword ptr [esi+1948h], 5
00408911  89 ae 4c 19 00 00                             mov     [esi+194Ch], ebp
00408917  c7 86 50 19 00 00 c0 eb 4f 00                 mov     dword ptr [esi+1950h], 4FEBC0h
00408921  c7 86 54 19 00 00 c0 00 00 00                 mov     dword ptr [esi+1954h], 0C0h
0040892B  c7 86 58 19 00 00 c3 00 00 00                 mov     dword ptr [esi+1958h], 0C3h
00408935  c7 86 5c 19 00 00 d7 33 4a 00                 mov     dword ptr [esi+195Ch], 4A33D7h
0040893F  c7 86 60 19 00 00 00 30 00 00                 mov     dword ptr [esi+1960h], 3000h
00408949  c7 86 64 19 00 00 20 4e 00 00                 mov     dword ptr [esi+1964h], 4E20h
00408953  c7 86 68 19 00 00 00 3d 4a 00                 mov     dword ptr [esi+1968h], 4A3D00h
0040895D  c7 86 6c 19 00 00 58 58 eb 01                 mov     dword ptr [esi+196Ch], 1EB5858h
00408967  c7 86 70 19 00 00 e8 7b b2 fc                 mov     dword ptr [esi+1970h], 0FCB27BE8h
00408971  c7 86 74 19 00 00 f1 3d 4a 00                 mov     dword ptr [esi+1974h], 4A3DF1h
0040897B  c7 86 78 19 00 00 70 17 00 00                 mov     dword ptr [esi+1978h], 1770h
00408985  c7 86 7c 19 00 00 40 1f 00 00                 mov     dword ptr [esi+197Ch], 1F40h
0040898F  c7 86 80 19 00 00 b1 06 4b 00                 mov     dword ptr [esi+1980h], 4B06B1h
00408999  89 86 84 19 00 00                             mov     [esi+1984h], eax
0040899F  c7 86 88 19 00 00 e4 00 00 00                 mov     dword ptr [esi+1988h], 0E4h
004089A9  c7 86 8c 19 00 00 ea 35 49 00                 mov     dword ptr [esi+198Ch], 4935EAh
004089B3  c7 86 90 19 00 00 eb 00 00 00                 mov     dword ptr [esi+1990h], 0EBh
004089BD  c7 86 94 19 00 00 74 00 00 00                 mov     dword ptr [esi+1994h], 74h ; 't'
004089C7  c7 86 98 19 00 00 49 2d 4b 00                 mov     dword ptr [esi+1998h], 4B2D49h
004089D1  c7 86 9c 19 00 00 64 00 00 00                 mov     dword ptr [esi+199Ch], 64h ; 'd'
004089DB  c7 86 a0 19 00 00 68 00 00 00                 mov     dword ptr [esi+19A0h], 68h ; 'h'
004089E5  c7 86 a4 19 00 00 37 2e 4b 00                 mov     dword ptr [esi+19A4h], 4B2E37h
004089EF  c7 86 a8 19 00 00 54 8b 4e 5c                 mov     dword ptr [esi+19A8h], 5C4E8B54h
004089F9  c7 86 ac 19 00 00 58 8b 4e 60                 mov     dword ptr [esi+19ACh], 604E8B58h
00408A03  c7 86 b0 19 00 00 19 b4 57 00                 mov     dword ptr [esi+19B0h], 57B419h
00408A0D  89 9e b4 19 00 00                             mov     [esi+19B4h], ebx
00408A13  c7 86 b8 19 00 00 76 1b 48 00                 mov     dword ptr [esi+19B8h], 481B76h
00408A1D  89 96 bc 19 00 00                             mov     [esi+19BCh], edx
00408A23  89 8e c0 19 00 00                             mov     [esi+19C0h], ecx
00408A29  c7 86 c4 19 00 00 64 26 50 00                 mov     dword ptr [esi+19C4h], 502664h
00408A33  c7 86 c8 19 00 00 66 24 45 00                 mov     dword ptr [esi+19C8h], 452466h
00408A3D  c7 86 cc 19 00 00 94 25 45 00                 mov     dword ptr [esi+19CCh], 452594h
00408A47  c7 86 d0 19 00 00 79 00 00 00                 mov     dword ptr [esi+19D0h], 79h ; 'y'
00408A51  c7 86 d4 19 00 00 50 00 00 00                 mov     dword ptr [esi+19D4h], 50h ; 'P'
00408A5B  c7 86 d8 19 00 00 58 26 50 00                 mov     dword ptr [esi+19D8h], 502658h
00408A65  c7 86 dc 19 00 00 49 24 45 00                 mov     dword ptr [esi+19DCh], 452449h
00408A6F  c7 86 e0 19 00 00 84 25 45 00                 mov     dword ptr [esi+19E0h], 452584h
00408A79  89 86 e4 19 00 00                             mov     [esi+19E4h], eax
00408A7F  89 9e e8 19 00 00                             mov     [esi+19E8h], ebx
00408A85  c7 86 ec 19 00 00 87 67 4b 00                 mov     dword ptr [esi+19ECh], 4B6787h
00408A8F  c7 86 f0 19 00 00 3c 00 00 00                 mov     dword ptr [esi+19F0h], 3Ch ; '<'
00408A99  c7 86 f4 19 00 00 23 00 00 00                 mov     dword ptr [esi+19F4h], 23h ; '#'
00408AA3  c7 86 f8 19 00 00 14 9e 58 00                 mov     dword ptr [esi+19F8h], 589E14h
00408AAD  89 86 fc 19 00 00                             mov     [esi+19FCh], eax
00408AB3  c7 86 00 1a 00 00 14 00 00 00                 mov     dword ptr [esi+1A00h], 14h
00408ABD  c7 86 04 1a 00 00 2a 49 49 00                 mov     dword ptr [esi+1A04h], 49492Ah
00408AC7  89 86 08 1a 00 00                             mov     [esi+1A08h], eax
00408ACD  c7 86 0c 1a 00 00 26 00 00 00                 mov     dword ptr [esi+1A0Ch], 26h ; '&'
00408AD7  c7 86 10 1a 00 00 30 eb 4f 00                 mov     dword ptr [esi+1A10h], 4FEB30h
00408AE1  c7 86 14 1a 00 00 3c 01 7f 19                 mov     dword ptr [esi+1A14h], 197F013Ch
00408AEB  c7 86 18 1a 00 00 85 ff 75 19                 mov     dword ptr [esi+1A18h], 1975FF85h
00408AF5  c7 86 1c 1a 00 00 2e 49 4a 00                 mov     dword ptr [esi+1A1Ch], 4A492Eh
00408AFF  c7 86 20 1a 00 00 46 00 00 00                 mov     dword ptr [esi+1A20h], 46h ; 'F'
00408B09  c7 86 24 1a 00 00 50 00 00 00                 mov     dword ptr [esi+1A24h], 50h ; 'P'
00408B13  c7 86 28 1a 00 00 77 f1 43 00                 mov     dword ptr [esi+1A28h], 43F177h
00408B1D  c7 86 2c 1a 00 00 ab d1 44 00                 mov     dword ptr [esi+1A2Ch], 44D1ABh
00408B27  c7 86 30 1a 00 00 7d 00 00 00                 mov     dword ptr [esi+1A30h], 7Dh ; '}'
00408B31  c7 86 34 1a 00 00 64 00 00 00                 mov     dword ptr [esi+1A34h], 64h ; 'd'
00408B3B  c7 86 38 1a 00 00 b1 8f 58 00                 mov     dword ptr [esi+1A38h], 588FB1h
00408B45  c7 86 3c 1a 00 00 30 71 46 00                 mov     dword ptr [esi+1A3Ch], 467130h
00408B4F  c7 86 40 1a 00 00 0d 00 00 00                 mov     dword ptr [esi+1A40h], 0Dh
00408B59  c7 86 44 1a 00 00 0a 00 00 00                 mov     dword ptr [esi+1A44h], 0Ah
00408B63  c7 86 48 1a 00 00 34 9b 43 00                 mov     dword ptr [esi+1A48h], 439B34h
00408B6D  c7 86 4c 1a 00 00 0c 00 00 00                 mov     dword ptr [esi+1A4Ch], 0Ch
00408B77  c7 86 50 1a 00 00 0a 00 00 00                 mov     dword ptr [esi+1A50h], 0Ah
00408B81  c7 86 54 1a 00 00 bc 3d 49 00                 mov     dword ptr [esi+1A54h], 493DBCh
00408B8B  c7 86 58 1a 00 00 eb 00 00 00                 mov     dword ptr [esi+1A58h], 0EBh
00408B95  c7 86 5c 1a 00 00 74 00 00 00                 mov     dword ptr [esi+1A5Ch], 74h ; 't'
00408B9F  c7 86 60 1a 00 00 ed 3c 49 00                 mov     dword ptr [esi+1A60h], 493CEDh
00408BA9  c7 86 64 1a 00 00 eb 00 00 00                 mov     dword ptr [esi+1A64h], 0EBh
00408BB3  c7 86 68 1a 00 00 74 00 00 00                 mov     dword ptr [esi+1A68h], 74h ; 't'
00408BBD  c7 86 6c 1a 00 00 24 62 4b 00                 mov     dword ptr [esi+1A6Ch], 4B6224h
00408BC7  c7 86 70 1a 00 00 98 fe ff ff                 mov     dword ptr [esi+1A70h], 0FFFFFE98h
00408BD1  c7 86 74 1a 00 00 78 d9 ff ff                 mov     dword ptr [esi+1A74h], 0FFFFD978h
00408BDB  c7 86 78 1a 00 00 39 58 4b 00                 mov     dword ptr [esi+1A78h], 4B5839h
00408BE5  c7 86 7c 1a 00 00 eb 00 00 00                 mov     dword ptr [esi+1A7Ch], 0EBh
00408BEF  c7 86 80 1a 00 00 75 00 00 00                 mov     dword ptr [esi+1A80h], 75h ; 'u'
00408BF9  c7 86 84 1a 00 00 0b 52 4b 00                 mov     dword ptr [esi+1A84h], 4B520Bh
00408C03  c7 86 88 1a 00 00 eb 18 00 00                 mov     dword ptr [esi+1A88h], 18EBh
00408C0D  c7 86 8c 1a 00 00 6a 01 00 00                 mov     dword ptr [esi+1A8Ch], 16Ah
00408C17  c7 86 90 1a 00 00 20 4f 46 00                 mov     dword ptr [esi+1A90h], 464F20h
00408C21  c7 86 94 1a 00 00 1e 00 00 00                 mov     dword ptr [esi+1A94h], 1Eh
00408C2B  c7 86 98 1a 00 00 19 00 00 00                 mov     dword ptr [esi+1A98h], 19h
00408C35  c7 86 9c 1a 00 00 95 82 4b 00                 mov     dword ptr [esi+1A9Ch], 4B8295h
00408C3F  89 86 a0 1a 00 00                             mov     [esi+1AA0h], eax
00408C45  c7 86 a4 1a 00 00 25 00 00 00                 mov     dword ptr [esi+1AA4h], 25h ; '%'
00408C4F  c7 86 a8 1a 00 00 eb 87 4b 00                 mov     dword ptr [esi+1AA8h], 4B87EBh
00408C59  89 96 ac 1a 00 00                             mov     [esi+1AACh], edx
00408C5F  89 8e b0 1a 00 00                             mov     [esi+1AB0h], ecx
00408C65  c7 86 b4 1a 00 00 26 48 4b 00                 mov     dword ptr [esi+1AB4h], 4B4826h
00408C6F  c7 86 b8 1a 00 00 95 42 4b 00                 mov     dword ptr [esi+1AB8h], 4B4295h
00408C79  c7 86 bc 1a 00 00 b0 00 00 00                 mov     dword ptr [esi+1ABCh], 0B0h
00408C83  c7 86 c0 1a 00 00 60 00 00 00                 mov     dword ptr [esi+1AC0h], 60h ; '`'
00408C8D  c7 86 c4 1a 00 00 20 aa 4a 00                 mov     dword ptr [esi+1AC4h], 4AAA20h
00408C97  89 96 c8 1a 00 00                             mov     [esi+1AC8h], edx
00408C9D  89 8e cc 1a 00 00                             mov     [esi+1ACCh], ecx
00408CA3  c7 86 d0 1a 00 00 1d 80 4b 00                 mov     dword ptr [esi+1AD0h], 4B801Dh
00408CAD  c7 86 d4 1a 00 00 eb 00 00 00                 mov     dword ptr [esi+1AD4h], 0EBh
00408CB7  c7 86 d8 1a 00 00 74 00 00 00                 mov     dword ptr [esi+1AD8h], 74h ; 't'
00408CC1  c7 86 dc 1a 00 00 38 77 65 00                 mov     dword ptr [esi+1ADCh], 657738h
00408CCB  89 9e e0 1a 00 00                             mov     [esi+1AE0h], ebx
00408CD1  c7 86 e4 1a 00 00 05 00 00 00                 mov     dword ptr [esi+1AE4h], 5
00408CDB  c7 86 e8 1a 00 00 83 68 49 00                 mov     dword ptr [esi+1AE8h], 496883h
00408CE5  c7 86 ec 1a 00 00 3c 00 00 00                 mov     dword ptr [esi+1AECh], 3Ch ; '<'
00408CEF  89 ae f0 1a 00 00                             mov     [esi+1AF0h], ebp
00408CF5  c7 86 f4 1a 00 00 be 68 49 00                 mov     dword ptr [esi+1AF4h], 4968BEh
00408CFF  c7 86 f8 1a 00 00 28 00 00 00                 mov     dword ptr [esi+1AF8h], 28h ; '('
00408D09  c7 86 fc 1a 00 00 10 00 00 00                 mov     dword ptr [esi+1AFCh], 10h
00408D13  c7 86 00 1b 00 00 ee 67 49 00                 mov     dword ptr [esi+1B00h], 4967EEh
00408D1D  89 ae 04 1b 00 00                             mov     [esi+1B04h], ebp
00408D23  c7 86 08 1b 00 00 02 00 00 00                 mov     dword ptr [esi+1B08h], 2
00408D2D  c7 86 0c 1b 00 00 a0 a8 4b 00                 mov     dword ptr [esi+1B0Ch], 4BA8A0h
00408D37  c7 86 10 1b 00 00 a3 79 4a 00                 mov     dword ptr [esi+1B10h], 4A79A3h
00408D41  c7 86 14 1b 00 00 19 00 00 00                 mov     dword ptr [esi+1B14h], 19h
00408D4B  c7 86 18 1b 00 00 32 00 00 00                 mov     dword ptr [esi+1B18h], 32h ; '2'
00408D55  c7 86 1c 1b 00 00 23 f3 49 00                 mov     dword ptr [esi+1B1Ch], 49F323h
00408D5F  c7 86 20 1b 00 00 19 00 00 00                 mov     dword ptr [esi+1B20h], 19h
00408D69  c7 86 24 1b 00 00 0a 00 00 00                 mov     dword ptr [esi+1B24h], 0Ah
00408D73  c7 86 28 1b 00 00 46 a4 49 00                 mov     dword ptr [esi+1B28h], 49A446h
00408D7D  89 ae 2c 1b 00 00                             mov     [esi+1B2Ch], ebp
00408D83  c7 86 30 1b 00 00 02 00 00 00                 mov     dword ptr [esi+1B30h], 2
00408D8D  c7 86 34 1b 00 00 96 fd 4a 00                 mov     dword ptr [esi+1B34h], 4AFD96h
00408D97  c7 86 38 1b 00 00 26 35 fa ff                 mov     dword ptr [esi+1B38h], 0FFFA3526h
00408DA1  c7 86 3c 1b 00 00 96 35 fa ff                 mov     dword ptr [esi+1B3Ch], 0FFFA3596h
00408DAB  c7 86 40 1b 00 00 6d ba 49 00                 mov     dword ptr [esi+1B40h], 49BA6Dh
00408DB5  c7 86 44 1b 00 00 9c 00 00 00                 mov     dword ptr [esi+1B44h], 9Ch
00408DBF  c7 86 48 1b 00 00 98 00 00 00                 mov     dword ptr [esi+1B48h], 98h
00408DC9  c7 86 4c 1b 00 00 03 f8 4f 00                 mov     dword ptr [esi+1B4Ch], 4FF803h
00408DD3  c7 86 50 1b 00 00 40 07 61 00                 mov     dword ptr [esi+1B50h], 610740h
00408DDD  c7 86 54 1b 00 00 f8 08 61 00                 mov     dword ptr [esi+1B54h], 6108F8h
00408DE7  c7 86 58 1b 00 00 38 c0 4b 00                 mov     dword ptr [esi+1B58h], 4BC038h
00408DF1  c7 86 5c 1b 00 00 0e 00 00 00                 mov     dword ptr [esi+1B5Ch], 0Eh
00408DFB  89 9e 60 1b 00 00                             mov     [esi+1B60h], ebx
00408E01  c7 86 64 1b 00 00 59 57 4a 00                 mov     dword ptr [esi+1B64h], 4A5759h
00408E0B  c7 86 68 1b 00 00 2a c7 4a 00                 mov     dword ptr [esi+1B68h], 4AC72Ah
00408E15  c7 86 6c 1b 00 00 80 52 4a 00                 mov     dword ptr [esi+1B6Ch], 4A5280h
00408E1F  c7 86 70 1b 00 00 b0 c4 4a 00                 mov     dword ptr [esi+1B70h], 4AC4B0h
00408E29  c7 86 74 1b 00 00 2f aa 50 00                 mov     dword ptr [esi+1B74h], 50AA2Fh
00408E33  89 86 78 1b 00 00                             mov     [esi+1B78h], eax
00408E39  c7 86 7c 1b 00 00 44 00 00 00                 mov     dword ptr [esi+1B7Ch], 44h ; 'D'
00408E43  c7 86 80 1b 00 00 2f 5f 49 00                 mov     dword ptr [esi+1B80h], 495F2Fh
00408E4D  c7 86 84 1b 00 00 53 00 00 00                 mov     dword ptr [esi+1B84h], 53h ; 'S'
00408E57  c7 86 88 1b 00 00 55 00 00 00                 mov     dword ptr [esi+1B88h], 55h ; 'U'
00408E61  c7 86 8c 1b 00 00 bc 5e 49 00                 mov     dword ptr [esi+1B8Ch], 495EBCh
00408E6B  c7 86 90 1b 00 00 2d 00 00 00                 mov     dword ptr [esi+1B90h], 2Dh ; '-'
00408E75  c7 86 94 1b 00 00 4b 00 00 00                 mov     dword ptr [esi+1B94h], 4Bh ; 'K'
00408E7F  c7 86 98 1b 00 00 10 2d 4b 00                 mov     dword ptr [esi+1B98h], 4B2D10h
00408E89  c7 86 9c 1b 00 00 08 00 00 00                 mov     dword ptr [esi+1B9Ch], 8
00408E93  c7 86 a0 1b 00 00 3c 00 00 00                 mov     dword ptr [esi+1BA0h], 3Ch ; '<'
00408E9D  c7 86 a4 1b 00 00 f4 2d 4b 00                 mov     dword ptr [esi+1BA4h], 4B2DF4h
00408EA7  c7 86 a8 1b 00 00 08 00 00 00                 mov     dword ptr [esi+1BA8h], 8
00408EB1  c7 86 ac 1b 00 00 34 00 00 00                 mov     dword ptr [esi+1BACh], 34h ; '4'
00408EBB  c7 86 b0 1b 00 00 da 68 43 00                 mov     dword ptr [esi+1BB0h], 4368DAh
00408EC5  89 86 b4 1b 00 00                             mov     [esi+1BB4h], eax
00408ECB  c7 86 b8 1b 00 00 01 01 01 00                 mov     dword ptr [esi+1BB8h], 10101h
00408ED5  c7 86 bc 1b 00 00 6d 26 50 00                 mov     dword ptr [esi+1BBCh], 50266Dh
00408EDF  c7 86 c0 1b 00 00 50 00 00 00                 mov     dword ptr [esi+1BC0h], 50h ; 'P'
00408EE9  c7 86 c4 1b 00 00 c4 5a 4b 00                 mov     dword ptr [esi+1BC4h], 4B5AC4h
00408EF3  89 9e c8 1b 00 00                             mov     [esi+1BC8h], ebx
00408EF9  c7 86 cc 1b 00 00 3c 00 00 00                 mov     dword ptr [esi+1BCCh], 3Ch ; '<'
00408F03  c7 86 d0 1b 00 00 3c 23 50 00                 mov     dword ptr [esi+1BD0h], 50233Ch
00408F0D  89 86 d4 1b 00 00                             mov     [esi+1BD4h], eax
00408F13  c7 86 d8 1b 00 00 f6 00 00 00                 mov     dword ptr [esi+1BD8h], 0F6h
00408F1D  c7 86 dc 1b 00 00 cf 40 4b 00                 mov     dword ptr [esi+1BDCh], 4B40CFh
00408F27  c7 86 e0 1b 00 00 20 eb 49 00                 mov     dword ptr [esi+1BE0h], 49EB20h
00408F31  c7 86 e4 1b 00 00 70 07 4b 00                 mov     dword ptr [esi+1BE4h], 4B0770h
00408F3B  c7 86 e8 1b 00 00 db db 4b 00                 mov     dword ptr [esi+1BE8h], 4BDBDBh
00408F45  c7 86 ec 1b 00 00 c3 00 00 00                 mov     dword ptr [esi+1BECh], 0C3h
00408F4F  c7 86 f0 1b 00 00 e9 00 00 00                 mov     dword ptr [esi+1BF0h], 0E9h
00408F59  c7 86 f4 1b 00 00 81 2a 58 00                 mov     dword ptr [esi+1BF4h], 582A81h
00408F63  89 96 f8 1b 00 00                             mov     [esi+1BF8h], edx
00408F69  89 8e fc 1b 00 00                             mov     [esi+1BFCh], ecx
00408F6F  c7 86 00 1c 00 00 53 01 43 00                 mov     dword ptr [esi+1C00h], 430153h
00408F79  c7 86 04 1c 00 00 8c 00 00 00                 mov     dword ptr [esi+1C04h], 8Ch
00408F83  c7 86 08 1c 00 00 84 00 00 00                 mov     dword ptr [esi+1C08h], 84h
00408F8D  c7 86 0c 1c 00 00 3e fc 45 00                 mov     dword ptr [esi+1C0Ch], 45FC3Eh
00408F97  c7 86 10 1c 00 00 1e b1 00 00                 mov     dword ptr [esi+1C10h], 0B11Eh
00408FA1  c7 86 14 1c 00 00 de c7 00 00                 mov     dword ptr [esi+1C14h], 0C7DEh
00408FAB  c7 86 18 1c 00 00 10 5b 4a 00                 mov     dword ptr [esi+1C18h], 4A5B10h
00408FB5  c7 86 1c 1c 00 00 01 00 00 00                 mov     dword ptr [esi+1C1Ch], 1
00408FBF  c7 86 20 1c 00 00 05 00 00 00                 mov     dword ptr [esi+1C20h], 5
00408FC9  c7 86 24 1c 00 00 3e 55 50 00                 mov     dword ptr [esi+1C24h], 50553Eh
00408FD3  c7 86 28 1c 00 00 6c 40 46 00                 mov     dword ptr [esi+1C28h], 46406Ch
00408FDD  89 86 2c 1c 00 00                             mov     [esi+1C2Ch], eax
00408FE3  c7 86 30 1c 00 00 01 00 00 00                 mov     dword ptr [esi+1C30h], 1
00408FED  c7 86 34 1c 00 00 7f ce 4f 00                 mov     dword ptr [esi+1C34h], 4FCE7Fh
00408FF7  89 86 38 1c 00 00                             mov     [esi+1C38h], eax
00408FFD  c7 86 3c 1c 00 00 e5 00 00 00                 mov     dword ptr [esi+1C3Ch], 0E5h
00409007  c7 86 40 1c 00 00 a5 59 4f 00                 mov     dword ptr [esi+1C40h], 4F59A5h
00409011  c7 86 44 1c 00 00 c0 00 00 00                 mov     dword ptr [esi+1C44h], 0C0h
0040901B  c7 86 48 1c 00 00 c3 00 00 00                 mov     dword ptr [esi+1C48h], 0C3h
00409025  c7 86 4c 1c 00 00 11 1c 45 00                 mov     dword ptr [esi+1C4Ch], 451C11h
0040902F  89 86 50 1c 00 00                             mov     [esi+1C50h], eax
00409035  b8 07 00 00 00                                mov     eax, 7
0040903A  89 86 54 1c 00 00                             mov     [esi+1C54h], eax
00409040  c7 86 58 1c 00 00 20 44 49 00                 mov     dword ptr [esi+1C58h], 494420h
0040904A  89 96 5c 1c 00 00                             mov     [esi+1C5Ch], edx
00409050  89 8e 60 1c 00 00                             mov     [esi+1C60h], ecx
00409056  c7 86 64 1c 00 00 25 2f 4a 00                 mov     dword ptr [esi+1C64h], 4A2F25h
00409060  c7 86 68 1c 00 00 f0 00 00 00                 mov     dword ptr [esi+1C68h], 0F0h
0040906A  c7 86 6c 1c 00 00 50 00 00 00                 mov     dword ptr [esi+1C6Ch], 50h ; 'P'
00409074  c7 86 70 1c 00 00 c0 2e 4a 00                 mov     dword ptr [esi+1C70h], 4A2EC0h
0040907E  c7 86 74 1c 00 00 19 00 00 00                 mov     dword ptr [esi+1C74h], 19h
00409088  c7 86 78 1c 00 00 14 00 00 00                 mov     dword ptr [esi+1C78h], 14h
00409092  c7 86 7c 1c 00 00 c8 03 48 00                 mov     dword ptr [esi+1C7Ch], 4803C8h
0040909C  c7 86 80 1c 00 00 ff ff ff 7f                 mov     dword ptr [esi+1C80h], 7FFFFFFFh
004090A6  c7 86 84 1c 00 00 5e 01 00 00                 mov     dword ptr [esi+1C84h], 15Eh
004090B0  c7 86 88 1c 00 00 c7 d0 43 00                 mov     dword ptr [esi+1C88h], 43D0C7h
004090BA  89 86 8c 1c 00 00                             mov     [esi+1C8Ch], eax
004090C0  89 be 90 1c 00 00                             mov     [esi+1C90h], edi
004090C6  c7 86 94 1c 00 00 1b 81 4a 00                 mov     dword ptr [esi+1C94h], 4A811Bh
004090D0  c7 86 98 1c 00 00 eb 00 00 00                 mov     dword ptr [esi+1C98h], 0EBh
004090DA  c7 86 9c 1c 00 00 7e 00 00 00                 mov     dword ptr [esi+1C9Ch], 7Eh ; '~'
004090E4  c7 86 a0 1c 00 00 e9 82 4a 00                 mov     dword ptr [esi+1CA0h], 4A82E9h
004090EE  c7 86 a4 1c 00 00 0c 00 00 00                 mov     dword ptr [esi+1CA4h], 0Ch
004090F8  c7 86 a8 1c 00 00 08 00 00 00                 mov     dword ptr [esi+1CA8h], 8
00409102  c7 86 ac 1c 00 00 6f c0 57 00                 mov     dword ptr [esi+1CACh], 57C06Fh
0040910C  c7 86 b0 1c 00 00 24 00 00 00                 mov     dword ptr [esi+1CB0h], 24h ; '$'
00409116  c7 86 b4 1c 00 00 01 6e 4a 00                 mov     dword ptr [esi+1CB4h], 4A6E01h
00409120  89 96 b8 1c 00 00                             mov     [esi+1CB8h], edx
00409126  89 8e bc 1c 00 00                             mov     [esi+1CBCh], ecx
0040912C  c7 86 c0 1c 00 00 7b ea 4f 00                 mov     dword ptr [esi+1CC0h], 4FEA7Bh
00409136  c7 86 c4 1c 00 00 7d 8c 40 00                 mov     dword ptr [esi+1CC4h], 408C7Dh
00409140  c7 86 c8 1c 00 00 23 00 00 00                 mov     dword ptr [esi+1CC8h], 23h ; '#'
0040914A  c7 86 cc 1c 00 00 93 0f 4c 00                 mov     dword ptr [esi+1CCCh], 4C0F93h
00409154  89 96 d0 1c 00 00                             mov     [esi+1CD0h], edx
0040915A  89 8e d4 1c 00 00                             mov     [esi+1CD4h], ecx
00409160  c7 86 d8 1c 00 00 fc 7e 4c 00                 mov     dword ptr [esi+1CD8h], 4C7EFCh
0040916A  c7 86 dc 1c 00 00 ea 30 50 00                 mov     dword ptr [esi+1CDCh], 5030EAh
00409174  b8 05 00 00 00                                mov     eax, 5
00409179  89 9e e0 1c 00 00                             mov     [esi+1CE0h], ebx
0040917F  89 86 e4 1c 00 00                             mov     [esi+1CE4h], eax
00409185  c7 86 e8 1c 00 00 c0 8d 43 00                 mov     dword ptr [esi+1CE8h], 438DC0h
0040918F  c7 86 ec 1c 00 00 4f 22 44 00                 mov     dword ptr [esi+1CECh], 44224Fh
00409199  c7 86 f0 1c 00 00 c8 26 45 00                 mov     dword ptr [esi+1CF0h], 4526C8h
004091A3  89 96 f4 1c 00 00                             mov     [esi+1CF4h], edx
004091A9  89 8e f8 1c 00 00                             mov     [esi+1CF8h], ecx
004091AF  c7 86 fc 1c 00 00 30 fe 48 00                 mov     dword ptr [esi+1CFCh], 48FE30h
004091B9  c7 86 00 1d 00 00 43 fe 48 00                 mov     dword ptr [esi+1D00h], 48FE43h
004091C3  89 96 04 1d 00 00                             mov     [esi+1D04h], edx
004091C9  89 8e 08 1d 00 00                             mov     [esi+1D08h], ecx
004091CF  c7 86 0c 1d 00 00 2b 36 51 00                 mov     dword ptr [esi+1D0Ch], 51362Bh
004091D9  c7 86 10 1d 00 00 0f 00 00 00                 mov     dword ptr [esi+1D10h], 0Fh
004091E3  89 ae 14 1d 00 00                             mov     [esi+1D14h], ebp
004091E9  c7 86 18 1d 00 00 00 f0 43 00                 mov     dword ptr [esi+1D18h], 43F000h
004091F3  c7 86 1c 1d 00 00 00 c0 61 00                 mov     dword ptr [esi+1D1Ch], 61C000h
004091FD  c7 86 20 1d 00 00 00 00 61 00                 mov     dword ptr [esi+1D20h], 610000h
00409207  c7 86 24 1d 00 00 00 c0 4e 00                 mov     dword ptr [esi+1D24h], 4EC000h
00409211  c7 86 28 1d 00 00 00 50 48 00                 mov     dword ptr [esi+1D28h], 485000h
0040921B  c7 86 2c 1d 00 00 00 00 4b 00                 mov     dword ptr [esi+1D2Ch], 4B0000h
00409225  c7 86 30 1d 00 00 00 10 00 00                 mov     dword ptr [esi+1D30h], 1000h
0040922F  c7 86 34 1d 00 00 0b 00 00 00                 mov     dword ptr [esi+1D34h], 0Bh
00409239  c7 86 38 1d 00 00 56 d9 51 00                 mov     dword ptr [esi+1D38h], 51D956h
00409243  c7 86 3c 1d 00 00 80 00 00 00                 mov     dword ptr [esi+1D3Ch], 80h
0040924D  c7 86 40 1d 00 00 a0 00 00 00                 mov     dword ptr [esi+1D40h], 0A0h
00409257  c7 86 44 1d 00 00 43 73 45 00                 mov     dword ptr [esi+1D44h], 457343h
00409261  c7 86 48 1d 00 00 e8 73 45 00                 mov     dword ptr [esi+1D48h], 4573E8h
0040926B  c7 86 4c 1d 00 00 e9 7c 55 00                 mov     dword ptr [esi+1D4Ch], 557CE9h
00409275  c7 86 50 1d 00 00 1e 00 00 00                 mov     dword ptr [esi+1D50h], 1Eh
0040927F  c7 86 54 1d 00 00 13 00 00 00                 mov     dword ptr [esi+1D54h], 13h
00409289  89 96 58 1d 00 00                             mov     [esi+1D58h], edx
0040928F  89 8e 5c 1d 00 00                             mov     [esi+1D5Ch], ecx
00409295  c7 86 60 1d 00 00 67 65 4b 00                 mov     dword ptr [esi+1D60h], 4B6567h
0040929F  c7 86 64 1d 00 00 0a 00 00 00                 mov     dword ptr [esi+1D64h], 0Ah
004092A9  89 86 68 1d 00 00                             mov     [esi+1D68h], eax
004092AF  c7 86 6c 1d 00 00 c8 7a 65 00                 mov     dword ptr [esi+1D6Ch], 657AC8h
004092B9  b8 02 00 00 00                                mov     eax, 2
004092BE  89 ae 70 1d 00 00                             mov     [esi+1D70h], ebp
004092C4  89 86 74 1d 00 00                             mov     [esi+1D74h], eax
004092CA  c7 86 78 1d 00 00 dc 7a 65 00                 mov     dword ptr [esi+1D78h], 657ADCh
004092D4  c7 86 7c 1d 00 00 90 7a 65 00                 mov     dword ptr [esi+1D7Ch], 657A90h
004092DE  c7 86 80 1d 00 00 98 7a 65 00                 mov     dword ptr [esi+1D80h], 657A98h
004092E8  c7 86 84 1d 00 00 e0 7a 65 00                 mov     dword ptr [esi+1D84h], 657AE0h
004092F2  89 86 88 1d 00 00                             mov     [esi+1D88h], eax
004092F8  b8 01 00 00 00                                mov     eax, 1
004092FD  89 86 8c 1d 00 00                             mov     [esi+1D8Ch], eax
00409303  c7 86 90 1d 00 00 36 3a 48 00                 mov     dword ptr [esi+1D90h], 483A36h
0040930D  c7 86 94 1d 00 00 90 e9 00 00                 mov     dword ptr [esi+1D94h], 0E990h
00409317  c7 86 98 1d 00 00 0f 84 00 00                 mov     dword ptr [esi+1D98h], 840Fh
00409321  c7 86 9c 1d 00 00 92 75 65 00                 mov     dword ptr [esi+1D9Ch], 657592h
0040932B  89 ae a0 1d 00 00                             mov     [esi+1DA0h], ebp
00409331  89 86 a4 1d 00 00                             mov     [esi+1DA4h], eax
00409337  c7 86 a8 1d 00 00 dd a6 41 00                 mov     dword ptr [esi+1DA8h], 41A6DDh
00409341  c7 86 ac 1d 00 00 f4 01 00 00                 mov     dword ptr [esi+1DACh], 1F4h
0040934B  c7 86 b0 1d 00 00 d0 07 00 00                 mov     dword ptr [esi+1DB0h], 7D0h
00409355  c7 86 b4 1d 00 00 e5 a6 41 00                 mov     dword ptr [esi+1DB4h], 41A6E5h
0040935F  c7 86 b8 1d 00 00 dc 05 00 00                 mov     dword ptr [esi+1DB8h], 5DCh
00409369  8d be c8 1d 00 00                             lea     edi, [esi+1DC8h]
0040936F  c7 86 bc 1d 00 00 a0 0f 00 00                 mov     dword ptr [esi+1DBCh], 0FA0h
00409379  c7 86 c0 1d 00 00 98 07 50 01                 mov     dword ptr [esi+1DC0h], 1500798h
00409383  8b cf                                         mov     ecx, edi; this
00409385  c7 86 c4 1d 00 00 b0 31 0a 00                 mov     dword ptr [esi+1DC4h], 0A31B0h
0040938F  e8 48 12 01 00                                call    ??0CWnd@@QAE@XZ; CWnd::CWnd(void)
00409394  c7 07 58 d0 41 00                             mov     dword ptr [edi], offset off_41D058
0040939A  c6 44 24 1c 01                                mov     byte ptr [esp+20h+var_4], 1
0040939F  c7 06 80 cf 41 00                             mov     dword ptr [esi], offset off_41CF80
004093A5  e8 6e 12 01 00                                call    ?AfxGetModuleState@@YGPAVAFX_MODULE_STATE@@XZ; AfxGetModuleState(void)
004093AA  68 80 00 00 00                                push    80h; lpIconName
004093AF  6a 0e                                         push    0Eh; char *
004093B1  68 80 00 00 00                                push    80h; char *
004093B6  e8 2b 14 01 00                                call    ?AfxFindResourceHandle@@YGPAUHINSTANCE__@@PBD0@Z; AfxFindResourceHandle(char const *,char const *)
004093BB  50                                            push    eax; hInstance
004093BC  ff 15 34 c3 41 00                             call    ds:LoadIconA; USER32
004093C2  8b 4c 24 14                                   mov     ecx, [esp+20h+var_C]
004093C6  89 86 08 1e 00 00                             mov     [esi+1E08h], eax
004093CC  8b c6                                         mov     eax, esi
004093CE  5f                                            pop     edi
004093CF  5e                                            pop     esi
004093D0  5d                                            pop     ebp
004093D1  5b                                            pop     ebx
004093D2  64 89 0d 00 00 00 00                          mov     large fs:0, ecx
004093D9  83 c4 10                                      add     esp, 10h
004093DC  c2 04 00                                      retn    4
0041B160  8b 4d f0                                      mov     ecx, [ebp-10h]; this
0041B163  e9 6e f4 ff ff                                jmp     ??1CDialog@@UAE@XZ; CDialog::~CDialog(void)
0041B168  8b 4d f0                                      mov     ecx, [ebp-10h]
0041B16B  81 c1 c8 1d 00 00                             add     ecx, 1DC8h; this
0041B171  e9 5e f6 ff ff                                jmp     ??1CEdit@@UAE@XZ; CEdit::~CEdit(void)
0041B176  b8 d8 d9 41 00                                mov     eax, offset stru_41D9D8
0041B17B  e9 9c f6 ff ff                                jmp     __CxxFrameHandler
