00418810  6a ff                                         push    0FFFFFFFFh
00418812  68 de b1 41 00                                push    offset SEH_418810
00418817  64 a1 00 00 00 00                             mov     eax, large fs:0
0041881D  50                                            push    eax
0041881E  64 89 25 00 00 00 00                          mov     large fs:0, esp
00418825  81 ec d0 01 00 00                             sub     esp, 1D0h
0041882B  56                                            push    esi
0041882C  8b f1                                         mov     esi, ecx
0041882E  6a 00                                         push    0; struct CWnd *
00418830  8d 4c 24 08                                   lea     ecx, [esp+1E4h+var_1DC]
00418834  e8 47 a4 fe ff                                call    sub_402C80
00418839  8b 86 74 01 00 00                             mov     eax, [esi+174h]
0041883F  8b 8e 78 01 00 00                             mov     ecx, [esi+178h]
00418845  8b 96 7c 01 00 00                             mov     edx, [esi+17Ch]
0041884B  89 44 24 7c                                   mov     [esp+1E0h+var_164], eax
0041884F  8b 86 80 01 00 00                             mov     eax, [esi+180h]
00418855  89 8c 24 80 00 00 00                          mov     [esp+1E0h+var_160], ecx
0041885C  8b 8e 84 01 00 00                             mov     ecx, [esi+184h]
00418862  89 94 24 84 00 00 00                          mov     [esp+1E0h+var_15C], edx
00418869  8b 96 88 01 00 00                             mov     edx, [esi+188h]
0041886F  89 44 24 70                                   mov     [esp+1E0h+var_170], eax
00418873  8b 86 8c 01 00 00                             mov     eax, [esi+18Ch]
00418879  89 4c 24 74                                   mov     [esp+1E0h+var_16C], ecx
0041887D  8b 8e 90 01 00 00                             mov     ecx, [esi+190h]
00418883  89 54 24 78                                   mov     [esp+1E0h+var_168], edx
00418887  8b 96 94 01 00 00                             mov     edx, [esi+194h]
0041888D  89 44 24 68                                   mov     [esp+1E0h+var_178], eax
00418891  8b 86 94 00 00 00                             mov     eax, [esi+94h]
00418897  89 4c 24 64                                   mov     [esp+1E0h+var_17C], ecx
0041889B  8b 8e 44 01 00 00                             mov     ecx, [esi+144h]
004188A1  89 54 24 6c                                   mov     [esp+1E0h+var_174], edx
004188A5  8b 96 98 00 00 00                             mov     edx, [esi+98h]
004188AB  89 84 24 84 01 00 00                          mov     [esp+1E0h+var_5C], eax
004188B2  8b 86 9c 00 00 00                             mov     eax, [esi+9Ch]
004188B8  89 8c 24 80 01 00 00                          mov     [esp+1E0h+var_60], ecx
004188BF  8b 8e a0 00 00 00                             mov     ecx, [esi+0A0h]
004188C5  89 94 24 a0 00 00 00                          mov     [esp+1E0h+var_140], edx
004188CC  8b 96 a4 00 00 00                             mov     edx, [esi+0A4h]
004188D2  89 84 24 c0 00 00 00                          mov     [esp+1E0h+var_120], eax
004188D9  8b 86 a8 00 00 00                             mov     eax, [esi+0A8h]
004188DF  89 8c 24 c4 00 00 00                          mov     [esp+1E0h+var_11C], ecx
004188E6  8b 8e ac 00 00 00                             mov     ecx, [esi+0ACh]
004188EC  89 94 24 d0 00 00 00                          mov     [esp+1E0h+var_110], edx
004188F3  8b 96 b0 00 00 00                             mov     edx, [esi+0B0h]
004188F9  89 84 24 d8 00 00 00                          mov     [esp+1E0h+var_108], eax
00418900  8b 86 14 01 00 00                             mov     eax, [esi+114h]
00418906  89 8c 24 ec 00 00 00                          mov     [esp+1E0h+var_F4], ecx
0041890D  8b 8e b4 00 00 00                             mov     ecx, [esi+0B4h]
00418913  89 94 24 f8 00 00 00                          mov     [esp+1E0h+var_E8], edx
0041891A  8b 96 b8 00 00 00                             mov     edx, [esi+0B8h]
00418920  89 84 24 f0 00 00 00                          mov     [esp+1E0h+var_F0], eax
00418927  8b 86 bc 00 00 00                             mov     eax, [esi+0BCh]
0041892D  89 8c 24 08 01 00 00                          mov     [esp+1E0h+var_D8], ecx
00418934  8b 8e c0 00 00 00                             mov     ecx, [esi+0C0h]
0041893A  89 94 24 10 01 00 00                          mov     [esp+1E0h+var_D0], edx
00418941  8b 96 c4 00 00 00                             mov     edx, [esi+0C4h]
00418947  89 84 24 48 01 00 00                          mov     [esp+1E0h+var_98], eax
0041894E  8b 86 c8 00 00 00                             mov     eax, [esi+0C8h]
00418954  89 8c 24 50 01 00 00                          mov     [esp+1E0h+var_90], ecx
0041895B  8b 8e cc 00 00 00                             mov     ecx, [esi+0CCh]
00418961  89 94 24 5c 01 00 00                          mov     [esp+1E0h+var_84], edx
00418968  8b 96 54 01 00 00                             mov     edx, [esi+154h]
0041896E  89 84 24 64 01 00 00                          mov     [esp+1E0h+var_7C], eax
00418975  8b 86 58 01 00 00                             mov     eax, [esi+158h]
0041897B  89 8c 24 94 01 00 00                          mov     [esp+1E0h+var_4C], ecx
00418982  8b 8e 5c 01 00 00                             mov     ecx, [esi+15Ch]
00418988  89 94 24 a4 01 00 00                          mov     [esp+1E0h+var_3C], edx
0041898F  8b 96 60 01 00 00                             mov     edx, [esi+160h]
00418995  89 84 24 a8 01 00 00                          mov     [esp+1E0h+var_38], eax
0041899C  8b 86 64 01 00 00                             mov     eax, [esi+164h]
004189A2  89 8c 24 ac 01 00 00                          mov     [esp+1E0h+var_34], ecx
004189A9  8b 8e 68 01 00 00                             mov     ecx, [esi+168h]
004189AF  89 94 24 b0 01 00 00                          mov     [esp+1E0h+var_30], edx
004189B6  8b 96 6c 01 00 00                             mov     edx, [esi+16Ch]
004189BC  89 84 24 b4 01 00 00                          mov     [esp+1E0h+var_2C], eax
004189C3  8b 86 70 01 00 00                             mov     eax, [esi+170h]
004189C9  89 8c 24 b8 01 00 00                          mov     [esp+1E0h+var_28], ecx
004189D0  8b 8e d0 00 00 00                             mov     ecx, [esi+0D0h]
004189D6  89 94 24 bc 01 00 00                          mov     [esp+1E0h+var_24], edx
004189DD  8b 96 d4 00 00 00                             mov     edx, [esi+0D4h]
004189E3  89 84 24 c0 01 00 00                          mov     [esp+1E0h+var_20], eax
004189EA  8b 86 4c 01 00 00                             mov     eax, [esi+14Ch]
004189F0  c7 84 24 dc 01 00 00 00 00 00 00              mov     [esp+1E0h+var_4], 0
004189FB  89 8c 24 8c 00 00 00                          mov     [esp+1E0h+var_154], ecx
00418A02  89 94 24 98 00 00 00                          mov     [esp+1E0h+var_148], edx
00418A09  89 84 24 98 01 00 00                          mov     [esp+1E0h+var_48], eax
00418A10  8b 8e d8 00 00 00                             mov     ecx, [esi+0D8h]
00418A16  8b 96 dc 00 00 00                             mov     edx, [esi+0DCh]
00418A1C  8b 86 e0 00 00 00                             mov     eax, [esi+0E0h]
00418A22  89 8c 24 90 00 00 00                          mov     [esp+1E0h+var_150], ecx
00418A29  8b 8e e4 00 00 00                             mov     ecx, [esi+0E4h]
00418A2F  89 94 24 9c 00 00 00                          mov     [esp+1E0h+var_144], edx
00418A36  8b 96 e8 00 00 00                             mov     edx, [esi+0E8h]
00418A3C  89 84 24 94 00 00 00                          mov     [esp+1E0h+var_14C], eax
00418A43  8b 86 ec 00 00 00                             mov     eax, [esi+0ECh]
00418A49  89 8c 24 d4 00 00 00                          mov     [esp+1E0h+var_10C], ecx
00418A50  8b 8e f0 00 00 00                             mov     ecx, [esi+0F0h]
00418A56  89 94 24 a4 00 00 00                          mov     [esp+1E0h+var_13C], edx
00418A5D  8b 96 f4 00 00 00                             mov     edx, [esi+0F4h]
00418A63  89 84 24 a8 00 00 00                          mov     [esp+1E0h+var_138], eax
00418A6A  8b 86 f8 00 00 00                             mov     eax, [esi+0F8h]
00418A70  89 8c 24 b0 00 00 00                          mov     [esp+1E0h+var_130], ecx
00418A77  8b 8e fc 00 00 00                             mov     ecx, [esi+0FCh]
00418A7D  89 94 24 b4 00 00 00                          mov     [esp+1E0h+var_12C], edx
00418A84  8b 96 00 01 00 00                             mov     edx, [esi+100h]
00418A8A  89 84 24 b8 00 00 00                          mov     [esp+1E0h+var_128], eax
00418A91  8b 86 04 01 00 00                             mov     eax, [esi+104h]
00418A97  89 8c 24 bc 00 00 00                          mov     [esp+1E0h+var_124], ecx
00418A9E  8b 8e 08 01 00 00                             mov     ecx, [esi+108h]
00418AA4  89 94 24 c8 00 00 00                          mov     [esp+1E0h+var_118], edx
00418AAB  8b 96 0c 01 00 00                             mov     edx, [esi+10Ch]
00418AB1  89 84 24 cc 00 00 00                          mov     [esp+1E0h+var_114], eax
00418AB8  8b 86 10 01 00 00                             mov     eax, [esi+110h]
00418ABE  89 8c 24 88 00 00 00                          mov     [esp+1E0h+var_158], ecx
00418AC5  8b 8e 18 01 00 00                             mov     ecx, [esi+118h]
00418ACB  89 94 24 e0 00 00 00                          mov     [esp+1E0h+var_100], edx
00418AD2  8b 96 1c 01 00 00                             mov     edx, [esi+11Ch]
00418AD8  89 84 24 f4 00 00 00                          mov     [esp+1E0h+var_EC], eax
00418ADF  8b 86 20 01 00 00                             mov     eax, [esi+120h]
00418AE5  89 8c 24 fc 00 00 00                          mov     [esp+1E0h+var_E4], ecx
00418AEC  8b 8e 24 01 00 00                             mov     ecx, [esi+124h]
00418AF2  89 94 24 04 01 00 00                          mov     [esp+1E0h+var_DC], edx
00418AF9  8b 96 28 01 00 00                             mov     edx, [esi+128h]
00418AFF  89 84 24 0c 01 00 00                          mov     [esp+1E0h+var_D4], eax
00418B06  8b 86 2c 01 00 00                             mov     eax, [esi+12Ch]
00418B0C  89 8c 24 3c 01 00 00                          mov     [esp+1E0h+var_A4], ecx
00418B13  8b 8e 30 01 00 00                             mov     ecx, [esi+130h]
00418B19  89 94 24 40 01 00 00                          mov     [esp+1E0h+var_A0], edx
00418B20  8b 96 34 01 00 00                             mov     edx, [esi+134h]
00418B26  89 84 24 44 01 00 00                          mov     [esp+1E0h+var_9C], eax
00418B2D  8b 86 38 01 00 00                             mov     eax, [esi+138h]
00418B33  89 8c 24 4c 01 00 00                          mov     [esp+1E0h+var_94], ecx
00418B3A  8b 8e 3c 01 00 00                             mov     ecx, [esi+13Ch]
00418B40  89 94 24 60 01 00 00                          mov     [esp+1E0h+var_80], edx
00418B47  8b 96 40 01 00 00                             mov     edx, [esi+140h]
00418B4D  89 84 24 68 01 00 00                          mov     [esp+1E0h+var_78], eax
00418B54  8b 86 48 01 00 00                             mov     eax, [esi+148h]
00418B5A  89 8c 24 78 01 00 00                          mov     [esp+1E0h+var_68], ecx
00418B61  8b 8e 50 01 00 00                             mov     ecx, [esi+150h]
00418B67  89 94 24 7c 01 00 00                          mov     [esp+1E0h+var_64], edx
00418B6E  8b 96 98 01 00 00                             mov     edx, [esi+198h]
00418B74  89 84 24 8c 01 00 00                          mov     [esp+1E0h+var_54], eax
00418B7B  8b 86 9c 01 00 00                             mov     eax, [esi+19Ch]
00418B81  89 8c 24 9c 01 00 00                          mov     [esp+1E0h+var_44], ecx
00418B88  8b 8e a0 01 00 00                             mov     ecx, [esi+1A0h]
00418B8E  89 94 24 ac 00 00 00                          mov     [esp+1E0h+var_134], edx
00418B95  8b 96 a4 01 00 00                             mov     edx, [esi+1A4h]
00418B9B  89 84 24 dc 00 00 00                          mov     [esp+1E0h+var_104], eax
00418BA2  8b 86 a8 01 00 00                             mov     eax, [esi+1A8h]
00418BA8  89 8c 24 e4 00 00 00                          mov     [esp+1E0h+var_FC], ecx
00418BAF  8b 8e ac 01 00 00                             mov     ecx, [esi+1ACh]
00418BB5  89 94 24 e8 00 00 00                          mov     [esp+1E0h+var_F8], edx
00418BBC  8b 96 b0 01 00 00                             mov     edx, [esi+1B0h]
00418BC2  89 84 24 00 01 00 00                          mov     [esp+1E0h+var_E0], eax
00418BC9  8b 86 b4 01 00 00                             mov     eax, [esi+1B4h]
00418BCF  89 8c 24 24 01 00 00                          mov     [esp+1E0h+var_BC], ecx
00418BD6  8b 8e b8 01 00 00                             mov     ecx, [esi+1B8h]
00418BDC  89 94 24 54 01 00 00                          mov     [esp+1E0h+var_8C], edx
00418BE3  8b 96 bc 01 00 00                             mov     edx, [esi+1BCh]
00418BE9  89 84 24 30 01 00 00                          mov     [esp+1E0h+var_B0], eax
00418BF0  8b 86 c0 01 00 00                             mov     eax, [esi+1C0h]
00418BF6  89 8c 24 38 01 00 00                          mov     [esp+1E0h+var_A8], ecx
00418BFD  8b 8e c4 01 00 00                             mov     ecx, [esi+1C4h]
00418C03  89 94 24 34 01 00 00                          mov     [esp+1E0h+var_AC], edx
00418C0A  8b 96 c8 01 00 00                             mov     edx, [esi+1C8h]
00418C10  89 84 24 2c 01 00 00                          mov     [esp+1E0h+var_B4], eax
00418C17  89 8c 24 28 01 00 00                          mov     [esp+1E0h+var_B8], ecx
00418C1E  8b 86 cc 01 00 00                             mov     eax, [esi+1CCh]
00418C24  8b 8e d0 01 00 00                             mov     ecx, [esi+1D0h]
00418C2A  89 94 24 6c 01 00 00                          mov     [esp+1E0h+var_74], edx
00418C31  8b 96 d8 01 00 00                             mov     edx, [esi+1D8h]
00418C37  89 84 24 70 01 00 00                          mov     [esp+1E0h+var_70], eax
00418C3E  8b 86 dc 01 00 00                             mov     eax, [esi+1DCh]
00418C44  89 8c 24 74 01 00 00                          mov     [esp+1E0h+var_6C], ecx
00418C4B  8b 8e d4 01 00 00                             mov     ecx, [esi+1D4h]
00418C51  89 94 24 88 01 00 00                          mov     [esp+1E0h+var_58], edx
00418C58  8b 96 e0 01 00 00                             mov     edx, [esi+1E0h]
00418C5E  89 84 24 90 01 00 00                          mov     [esp+1E0h+var_50], eax
00418C65  8b 86 e4 01 00 00                             mov     eax, [esi+1E4h]
00418C6B  89 8c 24 a0 01 00 00                          mov     [esp+1E0h+var_40], ecx
00418C72  8b 8e e8 01 00 00                             mov     ecx, [esi+1E8h]
00418C78  89 94 24 14 01 00 00                          mov     [esp+1E0h+var_CC], edx
00418C7F  8b 96 ec 01 00 00                             mov     edx, [esi+1ECh]
00418C85  89 84 24 18 01 00 00                          mov     [esp+1E0h+var_C8], eax
00418C8C  8b 86 f0 01 00 00                             mov     eax, [esi+1F0h]
00418C92  89 8c 24 1c 01 00 00                          mov     [esp+1E0h+var_C4], ecx
00418C99  8d 4c 24 04                                   lea     ecx, [esp+1E0h+var_1DC]; this
00418C9D  89 94 24 20 01 00 00                          mov     [esp+1E0h+var_C0], edx
00418CA4  89 84 24 58 01 00 00                          mov     [esp+1E0h+var_88], eax
00418CAB  e8 30 18 00 00                                call    ?DoModal@CDialog@@UAEHXZ; CDialog::DoModal(void)
00418CB0  83 f8 01                                      cmp     eax, 1
00418CB3  0f 85 6e 04 00 00                             jnz     loc_419127
00418CB9  8b 4c 24 7c                                   mov     ecx, [esp+1E0h+var_164]
00418CBD  8b 94 24 80 00 00 00                          mov     edx, [esp+1E0h+var_160]
00418CC4  8b 84 24 84 00 00 00                          mov     eax, [esp+1E0h+var_15C]
00418CCB  89 8e 74 01 00 00                             mov     [esi+174h], ecx
00418CD1  8b 4c 24 70                                   mov     ecx, [esp+1E0h+var_170]
00418CD5  89 96 78 01 00 00                             mov     [esi+178h], edx
00418CDB  8b 54 24 74                                   mov     edx, [esp+1E0h+var_16C]
00418CDF  89 86 7c 01 00 00                             mov     [esi+17Ch], eax
00418CE5  8b 44 24 78                                   mov     eax, [esp+1E0h+var_168]
00418CE9  89 8e 80 01 00 00                             mov     [esi+180h], ecx
00418CEF  8b 4c 24 68                                   mov     ecx, [esp+1E0h+var_178]
00418CF3  89 96 84 01 00 00                             mov     [esi+184h], edx
00418CF9  8b 54 24 64                                   mov     edx, [esp+1E0h+var_17C]
00418CFD  89 86 88 01 00 00                             mov     [esi+188h], eax
00418D03  8b 44 24 6c                                   mov     eax, [esp+1E0h+var_174]
00418D07  89 8e 8c 01 00 00                             mov     [esi+18Ch], ecx
00418D0D  8b 8c 24 84 01 00 00                          mov     ecx, [esp+1E0h+var_5C]
00418D14  89 96 90 01 00 00                             mov     [esi+190h], edx
00418D1A  8b 94 24 80 01 00 00                          mov     edx, [esp+1E0h+var_60]
00418D21  89 86 94 01 00 00                             mov     [esi+194h], eax
00418D27  8b 84 24 a0 00 00 00                          mov     eax, [esp+1E0h+var_140]
00418D2E  89 8e 94 00 00 00                             mov     [esi+94h], ecx
00418D34  8b 8c 24 c0 00 00 00                          mov     ecx, [esp+1E0h+var_120]
00418D3B  89 96 44 01 00 00                             mov     [esi+144h], edx
00418D41  8b 94 24 c4 00 00 00                          mov     edx, [esp+1E0h+var_11C]
00418D48  89 86 98 00 00 00                             mov     [esi+98h], eax
00418D4E  8b 84 24 d0 00 00 00                          mov     eax, [esp+1E0h+var_110]
00418D55  89 8e 9c 00 00 00                             mov     [esi+9Ch], ecx
00418D5B  8b 8c 24 d8 00 00 00                          mov     ecx, [esp+1E0h+var_108]
00418D62  89 96 a0 00 00 00                             mov     [esi+0A0h], edx
00418D68  8b 94 24 ec 00 00 00                          mov     edx, [esp+1E0h+var_F4]
00418D6F  89 86 a4 00 00 00                             mov     [esi+0A4h], eax
00418D75  8b 84 24 f8 00 00 00                          mov     eax, [esp+1E0h+var_E8]
00418D7C  89 8e a8 00 00 00                             mov     [esi+0A8h], ecx
00418D82  8b 8c 24 f0 00 00 00                          mov     ecx, [esp+1E0h+var_F0]
00418D89  89 96 ac 00 00 00                             mov     [esi+0ACh], edx
00418D8F  8b 94 24 08 01 00 00                          mov     edx, [esp+1E0h+var_D8]
00418D96  89 86 b0 00 00 00                             mov     [esi+0B0h], eax
00418D9C  8b 84 24 10 01 00 00                          mov     eax, [esp+1E0h+var_D0]
00418DA3  89 8e 14 01 00 00                             mov     [esi+114h], ecx
00418DA9  8b 8c 24 48 01 00 00                          mov     ecx, [esp+1E0h+var_98]
00418DB0  89 96 b4 00 00 00                             mov     [esi+0B4h], edx
00418DB6  8b 94 24 50 01 00 00                          mov     edx, [esp+1E0h+var_90]
00418DBD  89 86 b8 00 00 00                             mov     [esi+0B8h], eax
00418DC3  8b 84 24 5c 01 00 00                          mov     eax, [esp+1E0h+var_84]
00418DCA  89 8e bc 00 00 00                             mov     [esi+0BCh], ecx
00418DD0  8b 8c 24 64 01 00 00                          mov     ecx, [esp+1E0h+var_7C]
00418DD7  89 96 c0 00 00 00                             mov     [esi+0C0h], edx
00418DDD  8b 94 24 94 01 00 00                          mov     edx, [esp+1E0h+var_4C]
00418DE4  89 86 c4 00 00 00                             mov     [esi+0C4h], eax
00418DEA  8b 84 24 a4 01 00 00                          mov     eax, [esp+1E0h+var_3C]
00418DF1  89 8e c8 00 00 00                             mov     [esi+0C8h], ecx
00418DF7  8b 8c 24 a8 01 00 00                          mov     ecx, [esp+1E0h+var_38]
00418DFE  89 96 cc 00 00 00                             mov     [esi+0CCh], edx
00418E04  8b 94 24 ac 01 00 00                          mov     edx, [esp+1E0h+var_34]
00418E0B  89 86 54 01 00 00                             mov     [esi+154h], eax
00418E11  8b 84 24 b0 01 00 00                          mov     eax, [esp+1E0h+var_30]
00418E18  89 8e 58 01 00 00                             mov     [esi+158h], ecx
00418E1E  8b 8c 24 b4 01 00 00                          mov     ecx, [esp+1E0h+var_2C]
00418E25  89 96 5c 01 00 00                             mov     [esi+15Ch], edx
00418E2B  8b 94 24 b8 01 00 00                          mov     edx, [esp+1E0h+var_28]
00418E32  89 86 60 01 00 00                             mov     [esi+160h], eax
00418E38  8b 84 24 bc 01 00 00                          mov     eax, [esp+1E0h+var_24]
00418E3F  89 8e 64 01 00 00                             mov     [esi+164h], ecx
00418E45  8b 8c 24 c0 01 00 00                          mov     ecx, [esp+1E0h+var_20]
00418E4C  89 96 68 01 00 00                             mov     [esi+168h], edx
00418E52  8b 94 24 8c 00 00 00                          mov     edx, [esp+1E0h+var_154]
00418E59  89 86 6c 01 00 00                             mov     [esi+16Ch], eax
00418E5F  8b 84 24 98 00 00 00                          mov     eax, [esp+1E0h+var_148]
00418E66  89 8e 70 01 00 00                             mov     [esi+170h], ecx
00418E6C  8b 8c 24 98 01 00 00                          mov     ecx, [esp+1E0h+var_48]
00418E73  89 96 d0 00 00 00                             mov     [esi+0D0h], edx
00418E79  8b 94 24 90 00 00 00                          mov     edx, [esp+1E0h+var_150]
00418E80  89 86 d4 00 00 00                             mov     [esi+0D4h], eax
00418E86  8b 84 24 9c 00 00 00                          mov     eax, [esp+1E0h+var_144]
00418E8D  89 8e 4c 01 00 00                             mov     [esi+14Ch], ecx
00418E93  8b 8c 24 94 00 00 00                          mov     ecx, [esp+1E0h+var_14C]
00418E9A  89 96 d8 00 00 00                             mov     [esi+0D8h], edx
00418EA0  8b 94 24 d4 00 00 00                          mov     edx, [esp+1E0h+var_10C]
00418EA7  89 86 dc 00 00 00                             mov     [esi+0DCh], eax
00418EAD  89 8e e0 00 00 00                             mov     [esi+0E0h], ecx
00418EB3  8b 84 24 a4 00 00 00                          mov     eax, [esp+1E0h+var_13C]
00418EBA  8b 8c 24 a8 00 00 00                          mov     ecx, [esp+1E0h+var_138]
00418EC1  89 96 e4 00 00 00                             mov     [esi+0E4h], edx
00418EC7  8b 94 24 b0 00 00 00                          mov     edx, [esp+1E0h+var_130]
00418ECE  89 86 e8 00 00 00                             mov     [esi+0E8h], eax
00418ED4  8b 84 24 b4 00 00 00                          mov     eax, [esp+1E0h+var_12C]
00418EDB  89 8e ec 00 00 00                             mov     [esi+0ECh], ecx
00418EE1  8b 8c 24 b8 00 00 00                          mov     ecx, [esp+1E0h+var_128]
00418EE8  89 96 f0 00 00 00                             mov     [esi+0F0h], edx
00418EEE  8b 94 24 bc 00 00 00                          mov     edx, [esp+1E0h+var_124]
00418EF5  89 86 f4 00 00 00                             mov     [esi+0F4h], eax
00418EFB  8b 84 24 c8 00 00 00                          mov     eax, [esp+1E0h+var_118]
00418F02  89 8e f8 00 00 00                             mov     [esi+0F8h], ecx
00418F08  8b 8c 24 cc 00 00 00                          mov     ecx, [esp+1E0h+var_114]
00418F0F  89 96 fc 00 00 00                             mov     [esi+0FCh], edx
00418F15  8b 94 24 88 00 00 00                          mov     edx, [esp+1E0h+var_158]
00418F1C  89 86 00 01 00 00                             mov     [esi+100h], eax
00418F22  8b 84 24 e0 00 00 00                          mov     eax, [esp+1E0h+var_100]
00418F29  89 8e 04 01 00 00                             mov     [esi+104h], ecx
00418F2F  8b 8c 24 f4 00 00 00                          mov     ecx, [esp+1E0h+var_EC]
00418F36  89 96 08 01 00 00                             mov     [esi+108h], edx
00418F3C  8b 94 24 fc 00 00 00                          mov     edx, [esp+1E0h+var_E4]
00418F43  89 86 0c 01 00 00                             mov     [esi+10Ch], eax
00418F49  8b 84 24 04 01 00 00                          mov     eax, [esp+1E0h+var_DC]
00418F50  89 8e 10 01 00 00                             mov     [esi+110h], ecx
00418F56  8b 8c 24 0c 01 00 00                          mov     ecx, [esp+1E0h+var_D4]
00418F5D  89 96 18 01 00 00                             mov     [esi+118h], edx
00418F63  8b 94 24 3c 01 00 00                          mov     edx, [esp+1E0h+var_A4]
00418F6A  89 86 1c 01 00 00                             mov     [esi+11Ch], eax
00418F70  8b 84 24 40 01 00 00                          mov     eax, [esp+1E0h+var_A0]
00418F77  89 8e 20 01 00 00                             mov     [esi+120h], ecx
00418F7D  8b 8c 24 44 01 00 00                          mov     ecx, [esp+1E0h+var_9C]
00418F84  89 96 24 01 00 00                             mov     [esi+124h], edx
00418F8A  8b 94 24 4c 01 00 00                          mov     edx, [esp+1E0h+var_94]
00418F91  89 86 28 01 00 00                             mov     [esi+128h], eax
00418F97  8b 84 24 60 01 00 00                          mov     eax, [esp+1E0h+var_80]
00418F9E  89 8e 2c 01 00 00                             mov     [esi+12Ch], ecx
00418FA4  8b 8c 24 68 01 00 00                          mov     ecx, [esp+1E0h+var_78]
00418FAB  89 96 30 01 00 00                             mov     [esi+130h], edx
00418FB1  8b 94 24 78 01 00 00                          mov     edx, [esp+1E0h+var_68]
00418FB8  89 86 34 01 00 00                             mov     [esi+134h], eax
00418FBE  8b 84 24 7c 01 00 00                          mov     eax, [esp+1E0h+var_64]
00418FC5  89 8e 38 01 00 00                             mov     [esi+138h], ecx
00418FCB  8b 8c 24 8c 01 00 00                          mov     ecx, [esp+1E0h+var_54]
00418FD2  89 96 3c 01 00 00                             mov     [esi+13Ch], edx
00418FD8  8b 94 24 9c 01 00 00                          mov     edx, [esp+1E0h+var_44]
00418FDF  89 86 40 01 00 00                             mov     [esi+140h], eax
00418FE5  8b 84 24 ac 00 00 00                          mov     eax, [esp+1E0h+var_134]
00418FEC  89 8e 48 01 00 00                             mov     [esi+148h], ecx
00418FF2  8b 8c 24 dc 00 00 00                          mov     ecx, [esp+1E0h+var_104]
00418FF9  89 96 50 01 00 00                             mov     [esi+150h], edx
00418FFF  8b 94 24 e4 00 00 00                          mov     edx, [esp+1E0h+var_FC]
00419006  89 86 98 01 00 00                             mov     [esi+198h], eax
0041900C  8b 84 24 e8 00 00 00                          mov     eax, [esp+1E0h+var_F8]
00419013  89 8e 9c 01 00 00                             mov     [esi+19Ch], ecx
00419019  8b 8c 24 00 01 00 00                          mov     ecx, [esp+1E0h+var_E0]
00419020  89 96 a0 01 00 00                             mov     [esi+1A0h], edx
00419026  8b 94 24 24 01 00 00                          mov     edx, [esp+1E0h+var_BC]
0041902D  89 86 a4 01 00 00                             mov     [esi+1A4h], eax
00419033  8b 84 24 54 01 00 00                          mov     eax, [esp+1E0h+var_8C]
0041903A  89 8e a8 01 00 00                             mov     [esi+1A8h], ecx
00419040  8b 8c 24 30 01 00 00                          mov     ecx, [esp+1E0h+var_B0]
00419047  89 96 ac 01 00 00                             mov     [esi+1ACh], edx
0041904D  8b 94 24 38 01 00 00                          mov     edx, [esp+1E0h+var_A8]
00419054  89 86 b0 01 00 00                             mov     [esi+1B0h], eax
0041905A  8b 84 24 34 01 00 00                          mov     eax, [esp+1E0h+var_AC]
00419061  89 8e b4 01 00 00                             mov     [esi+1B4h], ecx
00419067  8b 8c 24 2c 01 00 00                          mov     ecx, [esp+1E0h+var_B4]
0041906E  89 96 b8 01 00 00                             mov     [esi+1B8h], edx
00419074  8b 94 24 28 01 00 00                          mov     edx, [esp+1E0h+var_B8]
0041907B  89 86 bc 01 00 00                             mov     [esi+1BCh], eax
00419081  8b 84 24 6c 01 00 00                          mov     eax, [esp+1E0h+var_74]
00419088  89 8e c0 01 00 00                             mov     [esi+1C0h], ecx
0041908E  8b 8c 24 70 01 00 00                          mov     ecx, [esp+1E0h+var_70]
00419095  89 96 c4 01 00 00                             mov     [esi+1C4h], edx
0041909B  8b 94 24 74 01 00 00                          mov     edx, [esp+1E0h+var_6C]
004190A2  89 86 c8 01 00 00                             mov     [esi+1C8h], eax
004190A8  8b 84 24 88 01 00 00                          mov     eax, [esp+1E0h+var_58]
004190AF  89 8e cc 01 00 00                             mov     [esi+1CCh], ecx
004190B5  89 96 d0 01 00 00                             mov     [esi+1D0h], edx
004190BB  89 86 d8 01 00 00                             mov     [esi+1D8h], eax
004190C1  8b 8c 24 90 01 00 00                          mov     ecx, [esp+1E0h+var_50]
004190C8  8b 94 24 a0 01 00 00                          mov     edx, [esp+1E0h+var_40]
004190CF  8b 84 24 14 01 00 00                          mov     eax, [esp+1E0h+var_CC]
004190D6  89 8e dc 01 00 00                             mov     [esi+1DCh], ecx
004190DC  8b 8c 24 18 01 00 00                          mov     ecx, [esp+1E0h+var_C8]
004190E3  89 96 d4 01 00 00                             mov     [esi+1D4h], edx
004190E9  8b 94 24 1c 01 00 00                          mov     edx, [esp+1E0h+var_C4]
004190F0  89 8e e4 01 00 00                             mov     [esi+1E4h], ecx
004190F6  8b 8c 24 58 01 00 00                          mov     ecx, [esp+1E0h+var_88]
004190FD  89 86 e0 01 00 00                             mov     [esi+1E0h], eax
00419103  8b 84 24 20 01 00 00                          mov     eax, [esp+1E0h+var_C0]
0041910A  89 8e f0 01 00 00                             mov     [esi+1F0h], ecx
00419110  6a 04                                         push    4
00419112  8b ce                                         mov     ecx, esi
00419114  89 96 e8 01 00 00                             mov     [esi+1E8h], edx
0041911A  89 86 ec 01 00 00                             mov     [esi+1ECh], eax
00419120  e8 eb 0c ff ff                                call    sub_409E10
00419125  eb 28                                         jmp     short loc_41914F
00419127  8a 96 e4 12 00 00                             mov     dl, [esi+12E4h]
0041912D  8a 8e 82 13 00 00                             mov     cl, [esi+1382h]
00419133  b0 fd                                         mov     al, 0FDh
00419135  c7 86 40 11 00 00 00 00 00 00                 mov     dword ptr [esi+1140h], 0
0041913F  22 d0                                         and     dl, al
00419141  22 c8                                         and     cl, al
00419143  88 96 e4 12 00 00                             mov     [esi+12E4h], dl
00419149  88 8e 82 13 00 00                             mov     [esi+1382h], cl
0041914F  8d 94 24 c4 01 00 00                          lea     edx, [esp+1E0h+var_1C]
00419156  c7 84 24 dc 01 00 00 01 00 00 00              mov     [esp+1E0h+var_4], 1
00419161  89 94 24 d0 01 00 00                          mov     [esp+1E0h+var_10], edx
00419168  c7 84 24 c4 01 00 00 90 c9 41 00              mov     [esp+1E0h+var_1C], offset off_41C990
00419173  8d 8c 24 c4 01 00 00                          lea     ecx, [esp+1E0h+var_1C]; this
0041917A  c6 84 24 dc 01 00 00 02                       mov     byte ptr [esp+1E0h+var_4], 2
00419182  e8 15 15 00 00                                call    ?DestroyMenu@CMenu@@QAEHXZ; CMenu::DestroyMenu(void)
00419187  8d 4c 24 04                                   lea     ecx, [esp+1E0h+var_1DC]; this
0041918B  c7 84 24 c4 01 00 00 70 c5 41 00              mov     [esp+1E0h+var_1C], offset off_41C570
00419196  c7 84 24 dc 01 00 00 ff ff ff ff              mov     [esp+1E0h+var_4], 0FFFFFFFFh
004191A1  e8 30 14 00 00                                call    ??1CDialog@@UAE@XZ; CDialog::~CDialog(void)
004191A6  8b 8c 24 d4 01 00 00                          mov     ecx, [esp+1E0h+var_C]
004191AD  5e                                            pop     esi
004191AE  64 89 0d 00 00 00 00                          mov     large fs:0, ecx
004191B5  81 c4 dc 01 00 00                             add     esp, 1DCh
004191BB  c3                                            retn
0041B1C0  8d 8d 24 fe ff ff                             lea     ecx, [ebp-1DCh]; this
0041B1C6  e9 45 7d fe ff                                jmp     sub_402F10
0041B1CB  8d 8d 24 fe ff ff                             lea     ecx, [ebp-1DCh]; this
0041B1D1  e9 00 f4 ff ff                                jmp     ??1CDialog@@UAE@XZ; CDialog::~CDialog(void)
0041B1D6  8b 4d f0                                      mov     ecx, [ebp-10h]
0041B1D9  e9 c2 67 fe ff                                jmp     sub_4019A0
0041B1DE  b8 58 da 41 00                                mov     eax, offset stru_41DA58
0041B1E3  e9 34 f6 ff ff                                jmp     __CxxFrameHandler
