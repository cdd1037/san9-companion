00409840  51                                            push    ecx
00409841  56                                            push    esi
00409842  8b f1                                         mov     esi, ecx
00409844  57                                            push    edi
00409845  8b 3d 3c c0 41 00                             mov     edi, ds:ReadProcessMemory; KERNEL32
0040984B  8b 8e 2c 19 00 00                             mov     ecx, [esi+192Ch]
00409851  8b 96 30 19 00 00                             mov     edx, [esi+1930h]
00409857  6a 00                                         push    0; lpNumberOfBytesRead
00409859  8d 44 24 0c                                   lea     eax, [esp+10h+Buffer]
0040985D  6a 04                                         push    4; nSize
0040985F  03 ca                                         add     ecx, edx
00409861  8b 56 70                                      mov     edx, [esi+70h]
00409864  50                                            push    eax; lpBuffer
00409865  51                                            push    ecx; lpBaseAddress
00409866  52                                            push    edx; hProcess
00409867  ff d7                                         call    edi ; ReadProcessMemory; KERNEL32
00409869  85 c0                                         test    eax, eax
0040986B  0f 84 9a 04 00 00                             jz      loc_409D0B
00409871  81 7c 24 08 bd 04 ef fe                       cmp     [esp+0Ch+Buffer], 0FEEF04BDh
00409879  0f 85 8c 04 00 00                             jnz     loc_409D0B
0040987F  8b 8e 2c 19 00 00                             mov     ecx, [esi+192Ch]
00409885  8b 96 30 19 00 00                             mov     edx, [esi+1930h]
0040988B  6a 00                                         push    0; lpNumberOfBytesRead
0040988D  8d 44 24 0c                                   lea     eax, [esp+10h+Buffer]
00409891  6a 04                                         push    4; nSize
00409893  50                                            push    eax; lpBuffer
00409894  8d 44 11 08                                   lea     eax, [ecx+edx+8]
00409898  8b 4e 70                                      mov     ecx, [esi+70h]
0040989B  50                                            push    eax; lpBaseAddress
0040989C  51                                            push    ecx; hProcess
0040989D  ff d7                                         call    edi ; ReadProcessMemory; KERNEL32
0040989F  85 c0                                         test    eax, eax
004098A1  0f 84 64 04 00 00                             jz      loc_409D0B
004098A7  81 7c 24 08 00 00 01 00                       cmp     [esp+0Ch+Buffer], 10000h
004098AF  0f 85 56 04 00 00                             jnz     loc_409D0B
004098B5  8b 86 2c 19 00 00                             mov     eax, [esi+192Ch]
004098BB  8b 8e 30 19 00 00                             mov     ecx, [esi+1930h]
004098C1  6a 00                                         push    0; lpNumberOfBytesRead
004098C3  8d 54 24 0c                                   lea     edx, [esp+10h+Buffer]
004098C7  6a 04                                         push    4; nSize
004098C9  52                                            push    edx; lpBuffer
004098CA  8d 54 08 0c                                   lea     edx, [eax+ecx+0Ch]
004098CE  8b 46 70                                      mov     eax, [esi+70h]
004098D1  52                                            push    edx; lpBaseAddress
004098D2  50                                            push    eax; hProcess
004098D3  ff d7                                         call    edi ; ReadProcessMemory; KERNEL32
004098D5  85 c0                                         test    eax, eax
004098D7  0f 84 2e 04 00 00                             jz      loc_409D0B
004098DD  8b 44 24 08                                   mov     eax, [esp+0Ch+Buffer]
004098E1  85 c0                                         test    eax, eax
004098E3  0f 84 22 04 00 00                             jz      loc_409D0B
004098E9  3d 00 00 01 00                                cmp     eax, 10000h
004098EE  0f 85 17 04 00 00                             jnz     loc_409D0B
004098F4  c7 86 68 14 00 00 58 db 24 01                 mov     dword ptr [esi+1468h], 124DB58h
004098FE  8d 86 6c 14 00 00                             lea     eax, [esi+146Ch]
00409904  b9 31 00 00 00                                mov     ecx, 31h ; '1'
00409909  8b 50 fc                                      mov     edx, [eax-4]
0040990C  83 c0 04                                      add     eax, 4
0040990F  81 c2 f0 01 00 00                             add     edx, 1F0h
00409915  49                                            dec     ecx
00409916  89 50 fc                                      mov     [eax-4], edx
00409919  75 ee                                         jnz     short loc_409909
0040991B  c7 86 30 15 00 00 78 80 23 01                 mov     dword ptr [esi+1530h], 1238078h
00409925  8d 86 34 15 00 00                             lea     eax, [esi+1534h]
0040992B  b9 c7 00 00 00                                mov     ecx, 0C7h
00409930  8b 50 fc                                      mov     edx, [eax-4]
00409933  83 c0 04                                      add     eax, 4
00409936  81 c2 bc 01 00 00                             add     edx, 1BCh
0040993C  49                                            dec     ecx
0040993D  89 50 fc                                      mov     [eax-4], edx
00409940  75 ee                                         jnz     short loc_409930
00409942  ba c8 04 42 00                                mov     edx, offset unk_4204C8
00409947  b8 04 f7 42 00                                mov     eax, offset unk_42F704
0040994C  33 c9                                         xor     ecx, ecx
0040994E  8b b1 b8 04 42 00                             mov     esi, dword_4204B8[ecx]
00409954  83 c1 04                                      add     ecx, 4
00409957  89 70 fc                                      mov     [eax-4], esi
0040995A  8b b1 bc 04 42 00                             mov     esi, dword_4204BC[ecx]
00409960  89 30                                         mov     [eax], esi
00409962  89 50 04                                      mov     [eax+4], edx
00409965  83 c2 10                                      add     edx, 10h
00409968  83 c0 0c                                      add     eax, 0Ch
0040996B  81 fa e8 04 42 00                             cmp     edx, offset byte_4204E8
00409971  7c db                                         jl      short loc_40994E
00409973  ba b0 f9 41 00                                mov     edx, offset unk_41F9B0
00409978  b8 84 f5 42 00                                mov     eax, offset unk_42F584
0040997D  33 c9                                         xor     ecx, ecx
0040997F  8b b1 a0 f9 41 00                             mov     esi, dword_41F9A0[ecx]
00409985  83 c1 04                                      add     ecx, 4
00409988  89 70 fc                                      mov     [eax-4], esi
0040998B  8b b1 a4 f9 41 00                             mov     esi, dword_41F9A4[ecx]
00409991  89 30                                         mov     [eax], esi
00409993  89 50 04                                      mov     [eax+4], edx
00409996  83 c2 10                                      add     edx, 10h
00409999  83 c0 0c                                      add     eax, 0Ch
0040999C  81 fa d0 f9 41 00                             cmp     edx, offset byte_41F9D0
004099A2  7c db                                         jl      short loc_40997F
004099A4  ba a8 10 42 00                                mov     edx, offset unk_4210A8
004099A9  b8 bc f7 42 00                                mov     eax, offset dword_42F7BC
004099AE  33 c9                                         xor     ecx, ecx
004099B0  8b b1 98 10 42 00                             mov     esi, dword_421098[ecx]
004099B6  83 c1 04                                      add     ecx, 4
004099B9  89 70 fc                                      mov     [eax-4], esi
004099BC  8b b1 9c 10 42 00                             mov     esi, dword_42109C[ecx]
004099C2  89 30                                         mov     [eax], esi
004099C4  89 50 04                                      mov     [eax+4], edx
004099C7  83 c2 10                                      add     edx, 10h
004099CA  83 c0 0c                                      add     eax, 0Ch
004099CD  81 fa c8 10 42 00                             cmp     edx, offset byte_4210C8
004099D3  7c db                                         jl      short loc_4099B0
004099D5  b8 9c f5 42 00                                mov     eax, offset unk_42F59C
004099DA  ba 44 fb 41 00                                mov     edx, offset unk_41FB44
004099DF  33 c9                                         xor     ecx, ecx
004099E1  be 05 00 00 00                                mov     esi, 5
004099E6  8b b9 ec fa 41 00                             mov     edi, dword_41FAEC[ecx]
004099EC  83 e9 04                                      sub     ecx, 4
004099EF  89 78 fc                                      mov     [eax-4], edi
004099F2  8b b9 04 fb 41 00                             mov     edi, dword_41FB04[ecx]
004099F8  89 38                                         mov     [eax], edi
004099FA  89 50 04                                      mov     [eax+4], edx
004099FD  83 ea 10                                      sub     edx, 10h
00409A00  83 c0 0c                                      add     eax, 0Ch
00409A03  4e                                            dec     esi
00409A04  75 e0                                         jnz     short loc_4099E6
00409A06  ba 30 ff 41 00                                mov     edx, offset unk_41FF30
00409A0B  b8 c4 f6 42 00                                mov     eax, offset unk_42F6C4
00409A10  33 c9                                         xor     ecx, ecx
00409A12  8b b1 18 ff 41 00                             mov     esi, dword_41FF18[ecx]
00409A18  83 c1 04                                      add     ecx, 4
00409A1B  89 70 fc                                      mov     [eax-4], esi
00409A1E  8b b1 20 ff 41 00                             mov     esi, dword_41FF20[ecx]
00409A24  89 30                                         mov     [eax], esi
00409A26  89 50 04                                      mov     [eax+4], edx
00409A29  83 c2 10                                      add     edx, 10h
00409A2C  83 c0 0c                                      add     eax, 0Ch
00409A2F  81 fa 60 ff 41 00                             cmp     edx, offset byte_41FF60
00409A35  7c db                                         jl      short loc_409A12
00409A37  ba b8 1e 42 00                                mov     edx, offset unk_421EB8
00409A3C  b8 ec f7 42 00                                mov     eax, offset unk_42F7EC
00409A41  33 c9                                         xor     ecx, ecx
00409A43  8b b1 a8 1e 42 00                             mov     esi, dword_421EA8[ecx]
00409A49  83 c1 04                                      add     ecx, 4
00409A4C  89 70 fc                                      mov     [eax-4], esi
00409A4F  8b b1 ac 1e 42 00                             mov     esi, dword_421EAC[ecx]
00409A55  89 30                                         mov     [eax], esi
00409A57  89 50 04                                      mov     [eax+4], edx
00409A5A  83 c2 10                                      add     edx, 10h
00409A5D  83 c0 0c                                      add     eax, 0Ch
00409A60  81 fa d8 1e 42 00                             cmp     edx, offset byte_421ED8
00409A66  7c db                                         jl      short loc_409A43
00409A68  ba 40 fe 41 00                                mov     edx, offset unk_41FE40
00409A6D  b8 7c f6 42 00                                mov     eax, offset unk_42F67C
00409A72  33 c9                                         xor     ecx, ecx
00409A74  8b b1 30 fe 41 00                             mov     esi, dword_41FE30[ecx]
00409A7A  83 c1 04                                      add     ecx, 4
00409A7D  89 70 fc                                      mov     [eax-4], esi
00409A80  8b b1 34 fe 41 00                             mov     esi, dword_41FE34[ecx]
00409A86  89 30                                         mov     [eax], esi
00409A88  89 50 04                                      mov     [eax+4], edx
00409A8B  83 c2 10                                      add     edx, 10h
00409A8E  83 c0 0c                                      add     eax, 0Ch
00409A91  81 fa 60 fe 41 00                             cmp     edx, offset byte_41FE60
00409A97  7c db                                         jl      short loc_409A74
00409A99  ba a0 0f 42 00                                mov     edx, offset unk_420FA0
00409A9E  b8 94 f7 42 00                                mov     eax, offset dword_42F794
00409AA3  33 c9                                         xor     ecx, ecx
00409AA5  8b b1 88 0f 42 00                             mov     esi, dword_420F88[ecx]
00409AAB  83 c1 04                                      add     ecx, 4
00409AAE  89 70 fc                                      mov     [eax-4], esi
00409AB1  8b b1 90 0f 42 00                             mov     esi, dword_420F90[ecx]
00409AB7  89 30                                         mov     [eax], esi
00409AB9  89 50 04                                      mov     [eax+4], edx
00409ABC  83 c2 10                                      add     edx, 10h
00409ABF  83 c0 0c                                      add     eax, 0Ch
00409AC2  81 fa d0 0f 42 00                             cmp     edx, offset byte_420FD0
00409AC8  7c db                                         jl      short loc_409AA5
00409ACA  a1 80 fb 41 00                                mov     eax, dword_41FB80
00409ACF  8b 0d 84 fb 41 00                             mov     ecx, dword_41FB84
00409AD5  a3 d8 f5 42 00                                mov     dword_42F5D8, eax
00409ADA  89 0d dc f5 42 00                             mov     dword_42F5DC, ecx
00409AE0  c7 05 e0 f5 42 00 88 fb 41 00                 mov     dword_42F5E0, offset unk_41FB88
00409AEA  ba c0 ff 41 00                                mov     edx, offset unk_41FFC0
00409AEF  b8 ec f6 42 00                                mov     eax, offset dword_42F6EC
00409AF4  33 c9                                         xor     ecx, ecx
00409AF6  8b b1 b0 ff 41 00                             mov     esi, dword_41FFB0[ecx]
00409AFC  83 c1 04                                      add     ecx, 4
00409AFF  89 70 fc                                      mov     [eax-4], esi
00409B02  8b b1 b4 ff 41 00                             mov     esi, dword_41FFB4[ecx]
00409B08  89 30                                         mov     [eax], esi
00409B0A  89 50 04                                      mov     [eax+4], edx
00409B0D  83 c2 10                                      add     edx, 10h
00409B10  83 c0 0c                                      add     eax, 0Ch
00409B13  81 fa e0 ff 41 00                             cmp     edx, offset byte_41FFE0
00409B19  7c db                                         jl      short loc_409AF6
00409B1B  8b 15 e8 fb 41 00                             mov     edx, dword_41FBE8
00409B21  a1 ec fb 41 00                                mov     eax, dword_41FBEC
00409B26  89 15 e8 f5 42 00                             mov     dword_42F5E8, edx
00409B2C  a3 ec f5 42 00                                mov     dword_42F5EC, eax
00409B31  c7 05 f0 f5 42 00 f0 fb 41 00                 mov     dword_42F5F0, offset unk_41FBF0
00409B3B  ba a8 fe 41 00                                mov     edx, offset unk_41FEA8
00409B40  b8 94 f6 42 00                                mov     eax, offset unk_42F694
00409B45  33 c9                                         xor     ecx, ecx
00409B47  8b b1 88 fe 41 00                             mov     esi, dword_41FE88[ecx]
00409B4D  83 c1 04                                      add     ecx, 4
00409B50  89 70 fc                                      mov     [eax-4], esi
00409B53  8b b1 94 fe 41 00                             mov     esi, dword_41FE94[ecx]
00409B59  89 30                                         mov     [eax], esi
00409B5B  89 50 04                                      mov     [eax+4], edx
00409B5E  83 c2 10                                      add     edx, 10h
00409B61  83 c0 0c                                      add     eax, 0Ch
00409B64  81 fa e8 fe 41 00                             cmp     edx, offset byte_41FEE8
00409B6A  7c db                                         jl      short loc_409B47
00409B6C  ba 60 05 42 00                                mov     edx, offset unk_420560
00409B71  b8 1c f7 42 00                                mov     eax, offset unk_42F71C
00409B76  33 c9                                         xor     ecx, ecx
00409B78  8b b1 48 05 42 00                             mov     esi, dword_420548[ecx]
00409B7E  83 c1 04                                      add     ecx, 4
00409B81  89 70 fc                                      mov     [eax-4], esi
00409B84  8b b1 50 05 42 00                             mov     esi, dword_420550[ecx]
00409B8A  89 30                                         mov     [eax], esi
00409B8C  89 50 04                                      mov     [eax+4], edx
00409B8F  83 c2 10                                      add     edx, 10h
00409B92  83 c0 0c                                      add     eax, 0Ch
00409B95  81 fa 90 05 42 00                             cmp     edx, offset byte_420590
00409B9B  7c db                                         jl      short loc_409B78
00409B9D  ba b8 0c 42 00                                mov     edx, offset unk_420CB8
00409BA2  b8 6c f7 42 00                                mov     eax, offset dword_42F76C
00409BA7  33 c9                                         xor     ecx, ecx
00409BA9  8b b1 a0 0c 42 00                             mov     esi, dword_420CA0[ecx]
00409BAF  83 c1 04                                      add     ecx, 4
00409BB2  89 70 fc                                      mov     [eax-4], esi
00409BB5  8b b1 a8 0c 42 00                             mov     esi, dword_420CA8[ecx]
00409BBB  89 30                                         mov     [eax], esi
00409BBD  89 50 04                                      mov     [eax+4], edx
00409BC0  83 c2 10                                      add     edx, 10h
00409BC3  83 c0 0c                                      add     eax, 0Ch
00409BC6  81 fa e8 0c 42 00                             cmp     edx, offset byte_420CE8
00409BCC  7c db                                         jl      short loc_409BA9
00409BCE  8b 0d 28 fc 41 00                             mov     ecx, dword_41FC28
00409BD4  8b 15 2c fc 41 00                             mov     edx, dword_41FC2C
00409BDA  a1 68 fc 41 00                                mov     eax, dword_41FC68
00409BDF  89 0d f8 f5 42 00                             mov     dword_42F5F8, ecx
00409BE5  8b 0d 6c fc 41 00                             mov     ecx, dword_41FC6C
00409BEB  89 15 fc f5 42 00                             mov     dword_42F5FC, edx
00409BF1  a3 08 f6 42 00                                mov     dword_42F608, eax
00409BF6  89 0d 0c f6 42 00                             mov     dword_42F60C, ecx
00409BFC  c7 05 00 f6 42 00 30 fc 41 00                 mov     dword_42F600, offset unk_41FC30
00409C06  c7 05 10 f6 42 00 70 fc 41 00                 mov     dword_42F610, offset unk_41FC70
00409C10  ba c8 fc 41 00                                mov     edx, offset unk_41FCC8
00409C15  b8 1c f6 42 00                                mov     eax, offset dword_42F61C
00409C1A  33 c9                                         xor     ecx, ecx
00409C1C  8b b1 a8 fc 41 00                             mov     esi, dword_41FCA8[ecx]
00409C22  83 c1 04                                      add     ecx, 4
00409C25  89 70 fc                                      mov     [eax-4], esi
00409C28  8b b1 b4 fc 41 00                             mov     esi, dword_41FCB4[ecx]
00409C2E  89 30                                         mov     [eax], esi
00409C30  89 50 04                                      mov     [eax+4], edx
00409C33  83 c2 10                                      add     edx, 10h
00409C36  83 c0 0c                                      add     eax, 0Ch
00409C39  81 fa 08 fd 41 00                             cmp     edx, offset byte_41FD08
00409C3F  7c db                                         jl      short loc_409C1C
00409C41  ba 90 1d 42 00                                mov     edx, offset unk_421D90
00409C46  b8 d4 f7 42 00                                mov     eax, offset unk_42F7D4
00409C4B  33 c9                                         xor     ecx, ecx
00409C4D  8b b1 80 1d 42 00                             mov     esi, dword_421D80[ecx]
00409C53  83 c1 04                                      add     ecx, 4
00409C56  89 70 fc                                      mov     [eax-4], esi
00409C59  8b b1 84 1d 42 00                             mov     esi, dword_421D84[ecx]
00409C5F  89 30                                         mov     [eax], esi
00409C61  89 50 04                                      mov     [eax+4], edx
00409C64  83 c2 10                                      add     edx, 10h
00409C67  83 c0 0c                                      add     eax, 0Ch
00409C6A  81 fa b0 1d 42 00                             cmp     edx, offset byte_421DB0
00409C70  7c db                                         jl      short loc_409C4D
00409C72  ba e8 fd 41 00                                mov     edx, offset unk_41FDE8
00409C77  b8 64 f6 42 00                                mov     eax, offset unk_42F664
00409C7C  33 c9                                         xor     ecx, ecx
00409C7E  8b b1 d8 fd 41 00                             mov     esi, dword_41FDD8[ecx]
00409C84  83 c1 04                                      add     ecx, 4
00409C87  89 70 fc                                      mov     [eax-4], esi
00409C8A  8b b1 dc fd 41 00                             mov     esi, dword_41FDDC[ecx]
00409C90  89 30                                         mov     [eax], esi
00409C92  89 50 04                                      mov     [eax+4], edx
00409C95  83 c2 10                                      add     edx, 10h
00409C98  83 c0 0c                                      add     eax, 0Ch
00409C9B  81 fa 08 fe 41 00                             cmp     edx, offset byte_41FE08
00409CA1  7c db                                         jl      short loc_409C7E
00409CA3  ba 40 fd 41 00                                mov     edx, offset unk_41FD40
00409CA8  b8 4c f6 42 00                                mov     eax, offset unk_42F64C
00409CAD  33 c9                                         xor     ecx, ecx
00409CAF  8b b1 30 fd 41 00                             mov     esi, dword_41FD30[ecx]
00409CB5  83 c1 04                                      add     ecx, 4
00409CB8  89 70 fc                                      mov     [eax-4], esi
00409CBB  8b b1 34 fd 41 00                             mov     esi, dword_41FD34[ecx]
00409CC1  89 30                                         mov     [eax], esi
00409CC3  89 50 04                                      mov     [eax+4], edx
00409CC6  83 c2 10                                      add     edx, 10h
00409CC9  83 c0 0c                                      add     eax, 0Ch
00409CCC  81 fa 60 fd 41 00                             cmp     edx, offset byte_41FD60
00409CD2  7c db                                         jl      short loc_409CAF
00409CD4  ba 28 0b 42 00                                mov     edx, offset unk_420B28
00409CD9  b8 44 f7 42 00                                mov     eax, offset dword_42F744
00409CDE  33 c9                                         xor     ecx, ecx
00409CE0  8b b1 10 0b 42 00                             mov     esi, dword_420B10[ecx]
00409CE6  83 c1 04                                      add     ecx, 4
00409CE9  89 70 fc                                      mov     [eax-4], esi
00409CEC  8b b1 18 0b 42 00                             mov     esi, dword_420B18[ecx]
00409CF2  89 30                                         mov     [eax], esi
00409CF4  89 50 04                                      mov     [eax+4], edx
00409CF7  83 c2 10                                      add     edx, 10h
00409CFA  83 c0 0c                                      add     eax, 0Ch
00409CFD  81 fa 58 0b 42 00                             cmp     edx, offset byte_420B58
00409D03  7c db                                         jl      short loc_409CE0
00409D05  5f                                            pop     edi
00409D06  b0 01                                         mov     al, 1
00409D08  5e                                            pop     esi
00409D09  59                                            pop     ecx
00409D0A  c3                                            retn
00409D0B  5f                                            pop     edi
00409D0C  32 c0                                         xor     al, al
00409D0E  5e                                            pop     esi
00409D0F  59                                            pop     ecx
00409D10  c3                                            retn
