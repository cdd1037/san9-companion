00402C80  6a ff                                         push    0FFFFFFFFh
00402C82  68 b6 ad 41 00                                push    offset SEH_402C80
00402C87  64 a1 00 00 00 00                             mov     eax, large fs:0
00402C8D  50                                            push    eax
00402C8E  64 89 25 00 00 00 00                          mov     large fs:0, esp
00402C95  51                                            push    ecx
00402C96  8b 44 24 14                                   mov     eax, [esp+10h+arg_0]
00402C9A  56                                            push    esi
00402C9B  8b f1                                         mov     esi, ecx
00402C9D  50                                            push    eax; struct CWnd *
00402C9E  68 83 00 00 00                                push    83h; unsigned int
00402CA3  89 74 24 0c                                   mov     [esp+1Ch+var_10], esi
00402CA7  e8 36 79 01 00                                call    ??0CDialog@@QAE@IPAVCWnd@@@Z; CDialog::CDialog(uint,CWnd *)
00402CAC  33 c0                                         xor     eax, eax
00402CAE  c7 86 c0 01 00 00 90 c9 41 00                 mov     dword ptr [esi+1C0h], offset off_41C990
00402CB8  89 44 24 10                                   mov     [esp+14h+var_4], eax
00402CBC  89 86 c4 01 00 00                             mov     [esi+1C4h], eax
00402CC2  c7 06 b8 c8 41 00                             mov     dword ptr [esi], offset off_41C8B8
00402CC8  89 46 60                                      mov     [esi+60h], eax
00402CCB  89 46 64                                      mov     [esi+64h], eax
00402CCE  89 46 68                                      mov     [esi+68h], eax
00402CD1  89 46 6c                                      mov     [esi+6Ch], eax
00402CD4  89 46 70                                      mov     [esi+70h], eax
00402CD7  89 46 74                                      mov     [esi+74h], eax
00402CDA  89 46 78                                      mov     [esi+78h], eax
00402CDD  89 46 7c                                      mov     [esi+7Ch], eax
00402CE0  89 86 80 00 00 00                             mov     [esi+80h], eax
00402CE6  89 86 84 00 00 00                             mov     [esi+84h], eax
00402CEC  89 86 88 00 00 00                             mov     [esi+88h], eax
00402CF2  89 86 8c 00 00 00                             mov     [esi+8Ch], eax
00402CF8  89 86 90 00 00 00                             mov     [esi+90h], eax
00402CFE  89 86 94 00 00 00                             mov     [esi+94h], eax
00402D04  89 86 98 00 00 00                             mov     [esi+98h], eax
00402D0A  89 86 9c 00 00 00                             mov     [esi+9Ch], eax
00402D10  89 86 a0 00 00 00                             mov     [esi+0A0h], eax
00402D16  89 86 a4 00 00 00                             mov     [esi+0A4h], eax
00402D1C  89 86 a8 00 00 00                             mov     [esi+0A8h], eax
00402D22  89 86 ac 00 00 00                             mov     [esi+0ACh], eax
00402D28  89 86 b0 00 00 00                             mov     [esi+0B0h], eax
00402D2E  89 86 b4 00 00 00                             mov     [esi+0B4h], eax
00402D34  89 86 b8 00 00 00                             mov     [esi+0B8h], eax
00402D3A  89 86 bc 00 00 00                             mov     [esi+0BCh], eax
00402D40  89 86 c0 00 00 00                             mov     [esi+0C0h], eax
00402D46  89 86 c4 00 00 00                             mov     [esi+0C4h], eax
00402D4C  89 86 c8 00 00 00                             mov     [esi+0C8h], eax
00402D52  89 86 cc 00 00 00                             mov     [esi+0CCh], eax
00402D58  89 86 d0 00 00 00                             mov     [esi+0D0h], eax
00402D5E  89 86 d4 00 00 00                             mov     [esi+0D4h], eax
00402D64  89 86 d8 00 00 00                             mov     [esi+0D8h], eax
00402D6A  89 86 dc 00 00 00                             mov     [esi+0DCh], eax
00402D70  89 86 e0 00 00 00                             mov     [esi+0E0h], eax
00402D76  89 86 e4 00 00 00                             mov     [esi+0E4h], eax
00402D7C  89 86 e8 00 00 00                             mov     [esi+0E8h], eax
00402D82  89 86 ec 00 00 00                             mov     [esi+0ECh], eax
00402D88  89 86 f0 00 00 00                             mov     [esi+0F0h], eax
00402D8E  89 86 f4 00 00 00                             mov     [esi+0F4h], eax
00402D94  89 86 f8 00 00 00                             mov     [esi+0F8h], eax
00402D9A  89 86 fc 00 00 00                             mov     [esi+0FCh], eax
00402DA0  89 86 00 01 00 00                             mov     [esi+100h], eax
00402DA6  89 86 04 01 00 00                             mov     [esi+104h], eax
00402DAC  89 86 08 01 00 00                             mov     [esi+108h], eax
00402DB2  89 86 0c 01 00 00                             mov     [esi+10Ch], eax
00402DB8  89 86 10 01 00 00                             mov     [esi+110h], eax
00402DBE  89 86 14 01 00 00                             mov     [esi+114h], eax
00402DC4  89 86 18 01 00 00                             mov     [esi+118h], eax
00402DCA  89 86 1c 01 00 00                             mov     [esi+11Ch], eax
00402DD0  89 86 20 01 00 00                             mov     [esi+120h], eax
00402DD6  89 86 24 01 00 00                             mov     [esi+124h], eax
00402DDC  89 86 28 01 00 00                             mov     [esi+128h], eax
00402DE2  89 86 2c 01 00 00                             mov     [esi+12Ch], eax
00402DE8  89 86 30 01 00 00                             mov     [esi+130h], eax
00402DEE  89 86 34 01 00 00                             mov     [esi+134h], eax
00402DF4  89 86 38 01 00 00                             mov     [esi+138h], eax
00402DFA  89 86 3c 01 00 00                             mov     [esi+13Ch], eax
00402E00  89 86 40 01 00 00                             mov     [esi+140h], eax
00402E06  c6 44 24 10 01                                mov     byte ptr [esp+14h+var_4], 1
00402E0B  89 86 44 01 00 00                             mov     [esi+144h], eax
00402E11  89 86 48 01 00 00                             mov     [esi+148h], eax
00402E17  89 86 4c 01 00 00                             mov     [esi+14Ch], eax
00402E1D  89 86 50 01 00 00                             mov     [esi+150h], eax
00402E23  89 86 54 01 00 00                             mov     [esi+154h], eax
00402E29  89 86 58 01 00 00                             mov     [esi+158h], eax
00402E2F  89 86 5c 01 00 00                             mov     [esi+15Ch], eax
00402E35  89 86 60 01 00 00                             mov     [esi+160h], eax
00402E3B  89 86 64 01 00 00                             mov     [esi+164h], eax
00402E41  89 86 68 01 00 00                             mov     [esi+168h], eax
00402E47  89 86 6c 01 00 00                             mov     [esi+16Ch], eax
00402E4D  89 86 70 01 00 00                             mov     [esi+170h], eax
00402E53  89 86 74 01 00 00                             mov     [esi+174h], eax
00402E59  89 86 78 01 00 00                             mov     [esi+178h], eax
00402E5F  89 86 7c 01 00 00                             mov     [esi+17Ch], eax
00402E65  89 86 80 01 00 00                             mov     [esi+180h], eax
00402E6B  89 86 84 01 00 00                             mov     [esi+184h], eax
00402E71  89 86 88 01 00 00                             mov     [esi+188h], eax
00402E77  89 86 8c 01 00 00                             mov     [esi+18Ch], eax
00402E7D  89 86 90 01 00 00                             mov     [esi+190h], eax
00402E83  89 86 94 01 00 00                             mov     [esi+194h], eax
00402E89  89 86 98 01 00 00                             mov     [esi+198h], eax
00402E8F  89 86 9c 01 00 00                             mov     [esi+19Ch], eax
00402E95  89 86 a0 01 00 00                             mov     [esi+1A0h], eax
00402E9B  89 86 a4 01 00 00                             mov     [esi+1A4h], eax
00402EA1  89 86 a8 01 00 00                             mov     [esi+1A8h], eax
00402EA7  89 86 ac 01 00 00                             mov     [esi+1ACh], eax
00402EAD  89 86 b0 01 00 00                             mov     [esi+1B0h], eax
00402EB3  89 86 b4 01 00 00                             mov     [esi+1B4h], eax
00402EB9  89 86 b8 01 00 00                             mov     [esi+1B8h], eax
00402EBF  89 86 bc 01 00 00                             mov     [esi+1BCh], eax
00402EC5  e8 4e 77 01 00                                call    ?AfxGetModuleState@@YGPAVAFX_MODULE_STATE@@XZ; AfxGetModuleState(void)
00402ECA  8b 40 04                                      mov     eax, [eax+4]
00402ECD  8b c8                                         mov     ecx, eax
00402ECF  8b 10                                         mov     edx, [eax]
00402ED1  ff 52 7c                                      call    dword ptr [edx+7Ch]
00402ED4  8b 4c 24 08                                   mov     ecx, [esp+14h+var_C]
00402ED8  89 86 c8 01 00 00                             mov     [esi+1C8h], eax
00402EDE  8b c6                                         mov     eax, esi
00402EE0  5e                                            pop     esi
00402EE1  64 89 0d 00 00 00 00                          mov     large fs:0, ecx
00402EE8  83 c4 10                                      add     esp, 10h
00402EEB  c2 04 00                                      retn    4
0041ADA0  8b 4d f0                                      mov     ecx, [ebp-10h]; this
0041ADA3  e9 2e f8 ff ff                                jmp     ??1CDialog@@UAE@XZ; CDialog::~CDialog(void)
0041ADA8  8b 4d f0                                      mov     ecx, [ebp-10h]
0041ADAB  81 c1 c0 01 00 00                             add     ecx, 1C0h
0041ADB1  e9 1a 99 fe ff                                jmp     sub_4046D0
0041ADB6  b8 40 d5 41 00                                mov     eax, offset stru_41D540
0041ADBB  e9 5c fa ff ff                                jmp     __CxxFrameHandler
