00405130  51                                            push    ecx
00405131  56                                            push    esi
00405132  8b f1                                         mov     esi, ecx
00405134  8b 86 58 01 00 00                             mov     eax, [esi+158h]
0040513A  8b 8e 5c 01 00 00                             mov     ecx, [esi+15Ch]
00405140  3b c1                                         cmp     eax, ecx
00405142  0f 83 98 02 00 00                             jnb     loc_4053E0
00405148  8d 04 80                                      lea     eax, [eax+eax*4]
0040514B  53                                            push    ebx
0040514C  55                                            push    ebp
0040514D  57                                            push    edi
0040514E  8d 8c 46 60 01 00 00                          lea     ecx, [esi+eax*2+160h]
00405155  8d 96 e0 00 00 00                             lea     edx, [esi+0E0h]
0040515B  51                                            push    ecx
0040515C  68 ac f7 41 00                                push    offset aS; "%s"
00405161  52                                            push    edx; this
00405162  e8 a5 54 01 00                                call    ?Format@CString@@QAAXPBDZZ; CString::Format(char const *,...)
00405167  8b 86 58 01 00 00                             mov     eax, [esi+158h]
0040516D  83 c4 0c                                      add     esp, 0Ch
00405170  0f be 8c 30 a0 20 00 00                       movsx   ecx, byte ptr [eax+esi+20A0h]
00405178  8d 14 cd 28 f7 41 00                          lea     edx, ds:41F728h[ecx*8]
0040517F  8d 8e 4c 01 00 00                             lea     ecx, [esi+14Ch]
00405185  52                                            push    edx
00405186  e8 5f 55 01 00                                call    ??4CString@@QAEABV0@PBD@Z; CString::operator=(char const *)
0040518B  8b 86 58 01 00 00                             mov     eax, [esi+158h]
00405191  8a 8c 30 c0 23 00 00                          mov     cl, [eax+esi+23C0h]
00405198  88 8e 08 01 00 00                             mov     [esi+108h], cl
0040519E  8b 86 58 01 00 00                             mov     eax, [esi+158h]
004051A4  8a 94 30 e0 26 00 00                          mov     dl, [eax+esi+26E0h]
004051AB  88 96 0a 01 00 00                             mov     [esi+10Ah], dl
004051B1  8a 8c 30 00 2a 00 00                          mov     cl, [eax+esi+2A00h]
004051B8  88 8e 09 01 00 00                             mov     [esi+109h], cl
004051BE  8a 94 30 20 2d 00 00                          mov     dl, [eax+esi+2D20h]
004051C5  88 96 0b 01 00 00                             mov     [esi+10Bh], dl
004051CB  8a 8c 46 40 30 00 00                          mov     cl, [esi+eax*2+3040h]
004051D2  83 e1 01                                      and     ecx, 1
004051D5  89 8e 0c 01 00 00                             mov     [esi+10Ch], ecx
004051DB  8a 94 46 40 30 00 00                          mov     dl, [esi+eax*2+3040h]
004051E2  d1 fa                                         sar     edx, 1
004051E4  83 e2 01                                      and     edx, 1
004051E7  89 96 24 01 00 00                             mov     [esi+124h], edx
004051ED  8a 8c 46 40 30 00 00                          mov     cl, [esi+eax*2+3040h]
004051F4  c1 f9 02                                      sar     ecx, 2
004051F7  83 e1 01                                      and     ecx, 1
004051FA  89 8e 18 01 00 00                             mov     [esi+118h], ecx
00405200  8a 94 46 40 30 00 00                          mov     dl, [esi+eax*2+3040h]
00405207  c1 fa 03                                      sar     edx, 3
0040520A  83 e2 01                                      and     edx, 1
0040520D  89 96 20 01 00 00                             mov     [esi+120h], edx
00405213  8a 8c 46 40 30 00 00                          mov     cl, [esi+eax*2+3040h]
0040521A  c1 f9 04                                      sar     ecx, 4
0040521D  83 e1 01                                      and     ecx, 1
00405220  89 8e 28 01 00 00                             mov     [esi+128h], ecx
00405226  8a 94 46 40 30 00 00                          mov     dl, [esi+eax*2+3040h]
0040522D  c1 fa 05                                      sar     edx, 5
00405230  83 e2 01                                      and     edx, 1
00405233  89 96 14 01 00 00                             mov     [esi+114h], edx
00405239  8a 8c 46 40 30 00 00                          mov     cl, [esi+eax*2+3040h]
00405240  c1 f9 06                                      sar     ecx, 6
00405243  83 e1 01                                      and     ecx, 1
00405246  89 8e 2c 01 00 00                             mov     [esi+12Ch], ecx
0040524C  8a 94 46 40 30 00 00                          mov     dl, [esi+eax*2+3040h]
00405253  c1 fa 07                                      sar     edx, 7
00405256  83 e2 01                                      and     edx, 1
00405259  89 96 1c 01 00 00                             mov     [esi+11Ch], edx
0040525F  66 8b 8c 46 40 30 00 00                       mov     cx, [esi+eax*2+3040h]
00405267  c1 f9 08                                      sar     ecx, 8
0040526A  83 e1 01                                      and     ecx, 1
0040526D  8d 14 c0                                      lea     edx, [eax+eax*8]
00405270  89 8e 10 01 00 00                             mov     [esi+110h], ecx
00405276  8d 0c 56                                      lea     ecx, [esi+edx*2]
00405279  66 8b 94 56 80 36 00 00                       mov     dx, [esi+edx*2+3680h]
00405281  66 89 96 30 01 00 00                          mov     [esi+130h], dx
00405288  66 8b 91 82 36 00 00                          mov     dx, [ecx+3682h]
0040528F  66 89 96 3c 01 00 00                          mov     [esi+13Ch], dx
00405296  66 8b 91 84 36 00 00                          mov     dx, [ecx+3684h]
0040529D  66 89 96 36 01 00 00                          mov     [esi+136h], dx
004052A4  66 8b 91 86 36 00 00                          mov     dx, [ecx+3686h]
004052AB  66 89 96 3a 01 00 00                          mov     [esi+13Ah], dx
004052B2  66 8b 91 88 36 00 00                          mov     dx, [ecx+3688h]
004052B9  66 89 96 3e 01 00 00                          mov     [esi+13Eh], dx
004052C0  66 8b 91 8a 36 00 00                          mov     dx, [ecx+368Ah]
004052C7  66 89 96 34 01 00 00                          mov     [esi+134h], dx
004052CE  66 8b 91 8c 36 00 00                          mov     dx, [ecx+368Ch]
004052D5  66 89 96 40 01 00 00                          mov     [esi+140h], dx
004052DC  66 8b 89 8e 36 00 00                          mov     cx, [ecx+368Eh]
004052E3  66 89 8e 38 01 00 00                          mov     [esi+138h], cx
004052EA  8d 94 c0 48 1b 00 00                          lea     edx, [eax+eax*8+1B48h]
004052F1  66 8b 04 56                                   mov     ax, [esi+edx*2]
004052F5  8b 2d 20 c3 41 00                             mov     ebp, ds:RedrawWindow; USER32
004052FB  66 89 86 32 01 00 00                          mov     [esi+132h], ax
00405302  bb 20 04 00 00                                mov     ebx, 420h
00405307  c7 44 24 10 01 00 00 00                       mov     [esp+14h+var_4], 1
0040530F  81 fb 23 04 00 00                             cmp     ebx, 423h
00405315  74 20                                         jz      short loc_405337
00405317  81 fb 27 04 00 00                             cmp     ebx, 427h
0040531D  74 18                                         jz      short loc_405337
0040531F  81 fb 2b 04 00 00                             cmp     ebx, 42Bh
00405325  74 10                                         jz      short loc_405337
00405327  81 fb 2f 04 00 00                             cmp     ebx, 42Fh
0040532D  74 08                                         jz      short loc_405337
0040532F  81 fb 33 04 00 00                             cmp     ebx, 433h
00405335  75 01                                         jnz     short loc_405338
00405337  43                                            inc     ebx
00405338  53                                            push    ebx; int
00405339  8b ce                                         mov     ecx, esi; this
0040533B  e8 7a 53 01 00                                call    ?GetDlgItem@CWnd@@QBEPAV1@H@Z; CWnd::GetDlgItem(int)
00405340  8b 8e 58 01 00 00                             mov     ecx, [esi+158h]
00405346  8b 54 24 10                                   mov     edx, [esp+14h+var_4]
0040534A  8b f8                                         mov     edi, eax
0040534C  8b 84 8e c0 6e 00 00                          mov     eax, [esi+ecx*4+6EC0h]
00405353  8b cf                                         mov     ecx, edi; this
00405355  85 c2                                         test    edx, eax
00405357  74 29                                         jz      short loc_405382
00405359  e8 ce 53 01 00                                call    ?GetStyle@CWnd@@QBEKXZ; CWnd::GetStyle(void)
0040535E  f6 c4 80                                      test    ah, 80h
00405361  75 48                                         jnz     short loc_4053AB
00405363  6a 00                                         push    0; unsigned int
00405365  68 00 80 00 00                                push    8000h; unsigned int
0040536A  6a 00                                         push    0; unsigned int
0040536C  8b cf                                         mov     ecx, edi; this
0040536E  e8 b3 53 01 00                                call    ?ModifyStyle@CWnd@@QAEHKKI@Z; CWnd::ModifyStyle(ulong,ulong,uint)
00405373  8b 47 20                                      mov     eax, [edi+20h]
00405376  68 05 01 00 00                                push    105h
0040537B  6a 00                                         push    0
0040537D  6a 00                                         push    0
0040537F  50                                            push    eax
00405380  eb 27                                         jmp     short loc_4053A9
00405382  e8 a5 53 01 00                                call    ?GetStyle@CWnd@@QBEKXZ; CWnd::GetStyle(void)
00405387  f6 c4 80                                      test    ah, 80h
0040538A  74 1f                                         jz      short loc_4053AB
0040538C  6a 00                                         push    0; unsigned int
0040538E  6a 00                                         push    0; unsigned int
00405390  68 00 80 00 00                                push    8000h; unsigned int
00405395  8b cf                                         mov     ecx, edi; this
00405397  e8 8a 53 01 00                                call    ?ModifyStyle@CWnd@@QAEHKKI@Z; CWnd::ModifyStyle(ulong,ulong,uint)
0040539C  8b 4f 20                                      mov     ecx, [edi+20h]
0040539F  68 05 01 00 00                                push    105h; flags
004053A4  6a 00                                         push    0; hrgnUpdate
004053A6  6a 00                                         push    0; lprcUpdate
004053A8  51                                            push    ecx; hWnd
004053A9  ff d5                                         call    ebp ; RedrawWindow; USER32
004053AB  8b 4c 24 10                                   mov     ecx, [esp+14h+var_4]
004053AF  43                                            inc     ebx
004053B0  d1 e1                                         shl     ecx, 1
004053B2  81 fb 43 04 00 00                             cmp     ebx, 443h
004053B8  89 4c 24 10                                   mov     [esp+14h+var_4], ecx
004053BC  0f 86 4d ff ff ff                             jbe     loc_40530F
004053C2  8b 96 58 01 00 00                             mov     edx, [esi+158h]
004053C8  8b 86 80 00 00 00                             mov     eax, [esi+80h]
004053CE  6a 00                                         push    0; lParam
004053D0  52                                            push    edx; wParam
004053D1  68 86 01 00 00                                push    186h; Msg
004053D6  50                                            push    eax; hWnd
004053D7  ff 15 64 c3 41 00                             call    ds:SendMessageA; USER32
004053DD  5f                                            pop     edi
004053DE  5d                                            pop     ebp
004053DF  5b                                            pop     ebx
004053E0  8b 8e 58 01 00 00                             mov     ecx, [esi+158h]
004053E6  8b 96 54 01 00 00                             mov     edx, [esi+154h]
004053EC  6a 00                                         push    0; int
004053EE  8d 04 8a                                      lea     eax, [edx+ecx*4]
004053F1  8b 0c 8a                                      mov     ecx, [edx+ecx*4]
004053F4  83 e1 03                                      and     ecx, 3
004053F7  89 8e e4 00 00 00                             mov     [esi+0E4h], ecx
004053FD  8b 10                                         mov     edx, [eax]
004053FF  c1 ea 02                                      shr     edx, 2
00405402  83 e2 03                                      and     edx, 3
00405405  89 96 e8 00 00 00                             mov     [esi+0E8h], edx
0040540B  8b 08                                         mov     ecx, [eax]
0040540D  c1 e9 04                                      shr     ecx, 4
00405410  83 e1 03                                      and     ecx, 3
00405413  89 8e ec 00 00 00                             mov     [esi+0ECh], ecx
00405419  8b 10                                         mov     edx, [eax]
0040541B  c1 ea 06                                      shr     edx, 6
0040541E  83 e2 03                                      and     edx, 3
00405421  89 96 f0 00 00 00                             mov     [esi+0F0h], edx
00405427  8b 08                                         mov     ecx, [eax]
00405429  c1 e9 08                                      shr     ecx, 8
0040542C  83 e1 03                                      and     ecx, 3
0040542F  89 8e 04 01 00 00                             mov     [esi+104h], ecx
00405435  8b 10                                         mov     edx, [eax]
00405437  c1 ea 0a                                      shr     edx, 0Ah
0040543A  83 e2 03                                      and     edx, 3
0040543D  89 96 f4 00 00 00                             mov     [esi+0F4h], edx
00405443  8b 08                                         mov     ecx, [eax]
00405445  c1 e9 0c                                      shr     ecx, 0Ch
00405448  83 e1 03                                      and     ecx, 3
0040544B  89 8e f8 00 00 00                             mov     [esi+0F8h], ecx
00405451  8b 10                                         mov     edx, [eax]
00405453  c1 ea 0e                                      shr     edx, 0Eh
00405456  83 e2 03                                      and     edx, 3
00405459  8b ce                                         mov     ecx, esi; this
0040545B  89 96 fc 00 00 00                             mov     [esi+0FCh], edx
00405461  8b 00                                         mov     eax, [eax]
00405463  c1 e8 10                                      shr     eax, 10h
00405466  83 e0 03                                      and     eax, 3
00405469  89 86 00 01 00 00                             mov     [esi+100h], eax
0040546F  e8 b6 51 01 00                                call    ?UpdateData@CWnd@@QAEHH@Z; CWnd::UpdateData(int)
00405474  5e                                            pop     esi
00405475  59                                            pop     ecx
00405476  c3                                            retn
