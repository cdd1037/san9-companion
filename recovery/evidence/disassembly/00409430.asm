00409430  53                                            push    ebx
00409431  56                                            push    esi
00409432  57                                            push    edi
00409433  8b f1                                         mov     esi, ecx
00409435  e8 ea 11 01 00                                call    ?OnInitDialog@CDialog@@UAEHXZ; CDialog::OnInitDialog(void)
0040943A  8b 86 08 1e 00 00                             mov     eax, [esi+1E08h]
00409440  8b 4e 20                                      mov     ecx, [esi+20h]
00409443  8b 3d 64 c3 41 00                             mov     edi, ds:SendMessageA; USER32
00409449  50                                            push    eax; lParam
0040944A  6a 01                                         push    1; wParam
0040944C  68 80 00 00 00                                push    80h; Msg
00409451  51                                            push    ecx; hWnd
00409452  ff d7                                         call    edi ; SendMessageA; USER32
00409454  8b 96 08 1e 00 00                             mov     edx, [esi+1E08h]
0040945A  8b 46 20                                      mov     eax, [esi+20h]
0040945D  33 db                                         xor     ebx, ebx
0040945F  52                                            push    edx; lParam
00409460  53                                            push    ebx; wParam
00409461  68 80 00 00 00                                push    80h; Msg
00409466  50                                            push    eax; hWnd
00409467  ff d7                                         call    edi ; SendMessageA; USER32
00409469  89 5e 6c                                      mov     [esi+6Ch], ebx
0040946C  89 5e 70                                      mov     [esi+70h], ebx
0040946F  89 5e 74                                      mov     [esi+74h], ebx
00409472  89 9e 84 00 00 00                             mov     [esi+84h], ebx
00409478  8b 4e 20                                      mov     ecx, [esi+20h]
0040947B  68 30 ed 42 00                                push    offset String; "San9PKHard"
00409480  89 4e 78                                      mov     [esi+78h], ecx
00409483  ff 15 3c c3 41 00                             call    ds:RegisterWindowMessageA; USER32
00409489  89 46 7c                                      mov     [esi+7Ch], eax
0040948C  c7 86 80 00 00 00 c3 c3 c3 c3                 mov     dword ptr [esi+80h], 0C3C3C3C3h
00409496  89 9e 88 00 00 00                             mov     [esi+88h], ebx
0040949C  89 9e 8c 00 00 00                             mov     [esi+8Ch], ebx
004094A2  89 9e 90 00 00 00                             mov     [esi+90h], ebx
004094A8  89 9e 9c 00 00 00                             mov     [esi+9Ch], ebx
004094AE  89 9e 98 00 00 00                             mov     [esi+98h], ebx
004094B4  89 9e 94 00 00 00                             mov     [esi+94h], ebx
004094BA  89 9e ac 00 00 00                             mov     [esi+0ACh], ebx
004094C0  89 9e a8 00 00 00                             mov     [esi+0A8h], ebx
004094C6  89 9e a4 00 00 00                             mov     [esi+0A4h], ebx
004094CC  89 9e a0 00 00 00                             mov     [esi+0A0h], ebx
004094D2  89 9e bc 00 00 00                             mov     [esi+0BCh], ebx
004094D8  89 9e b8 00 00 00                             mov     [esi+0B8h], ebx
004094DE  89 9e b4 00 00 00                             mov     [esi+0B4h], ebx
004094E4  89 9e 14 01 00 00                             mov     [esi+114h], ebx
004094EA  89 9e b0 00 00 00                             mov     [esi+0B0h], ebx
004094F0  89 9e cc 00 00 00                             mov     [esi+0CCh], ebx
004094F6  89 9e c8 00 00 00                             mov     [esi+0C8h], ebx
004094FC  89 9e c4 00 00 00                             mov     [esi+0C4h], ebx
00409502  89 9e c0 00 00 00                             mov     [esi+0C0h], ebx
00409508  89 9e 60 01 00 00                             mov     [esi+160h], ebx
0040950E  89 9e 5c 01 00 00                             mov     [esi+15Ch], ebx
00409514  89 9e 58 01 00 00                             mov     [esi+158h], ebx
0040951A  89 9e 54 01 00 00                             mov     [esi+154h], ebx
00409520  89 9e 70 01 00 00                             mov     [esi+170h], ebx
00409526  89 9e 6c 01 00 00                             mov     [esi+16Ch], ebx
0040952C  89 9e 68 01 00 00                             mov     [esi+168h], ebx
00409532  89 9e 64 01 00 00                             mov     [esi+164h], ebx
00409538  89 9e dc 00 00 00                             mov     [esi+0DCh], ebx
0040953E  89 9e d8 00 00 00                             mov     [esi+0D8h], ebx
00409544  89 9e d4 00 00 00                             mov     [esi+0D4h], ebx
0040954A  89 9e 4c 01 00 00                             mov     [esi+14Ch], ebx
00409550  89 9e d0 00 00 00                             mov     [esi+0D0h], ebx
00409556  89 9e f0 00 00 00                             mov     [esi+0F0h], ebx
0040955C  89 9e ec 00 00 00                             mov     [esi+0ECh], ebx
00409562  89 9e e8 00 00 00                             mov     [esi+0E8h], ebx
00409568  89 9e e4 00 00 00                             mov     [esi+0E4h], ebx
0040956E  89 9e e0 00 00 00                             mov     [esi+0E0h], ebx
00409574  89 9e 04 01 00 00                             mov     [esi+104h], ebx
0040957A  89 9e 00 01 00 00                             mov     [esi+100h], ebx
00409580  89 9e fc 00 00 00                             mov     [esi+0FCh], ebx
00409586  89 9e f8 00 00 00                             mov     [esi+0F8h], ebx
0040958C  89 9e f4 00 00 00                             mov     [esi+0F4h], ebx
00409592  89 9e 18 01 00 00                             mov     [esi+118h], ebx
00409598  89 9e 10 01 00 00                             mov     [esi+110h], ebx
0040959E  89 9e 0c 01 00 00                             mov     [esi+10Ch], ebx
004095A4  89 9e 08 01 00 00                             mov     [esi+108h], ebx
004095AA  89 9e 28 01 00 00                             mov     [esi+128h], ebx
004095B0  89 9e 24 01 00 00                             mov     [esi+124h], ebx
004095B6  89 9e 20 01 00 00                             mov     [esi+120h], ebx
004095BC  89 9e 1c 01 00 00                             mov     [esi+11Ch], ebx
004095C2  89 9e 38 01 00 00                             mov     [esi+138h], ebx
004095C8  b8 31 00 00 00                                mov     eax, 31h ; '1'
004095CD  89 9e 34 01 00 00                             mov     [esi+134h], ebx
004095D3  89 9e 30 01 00 00                             mov     [esi+130h], ebx
004095D9  89 86 7c 01 00 00                             mov     [esi+17Ch], eax
004095DF  89 86 84 01 00 00                             mov     [esi+184h], eax
004095E5  89 86 94 01 00 00                             mov     [esi+194h], eax
004095EB  89 9e 2c 01 00 00                             mov     [esi+12Ch], ebx
004095F1  b9 18 00 00 00                                mov     ecx, 18h
004095F6  bf 09 00 00 00                                mov     edi, 9
004095FB  ba 0a 00 00 00                                mov     edx, 0Ah
00409600  b8 05 00 00 00                                mov     eax, 5
00409605  89 9e 48 01 00 00                             mov     [esi+148h], ebx
0040960B  89 9e 44 01 00 00                             mov     [esi+144h], ebx
00409611  89 9e 40 01 00 00                             mov     [esi+140h], ebx
00409617  89 9e 3c 01 00 00                             mov     [esi+13Ch], ebx
0040961D  89 9e 50 01 00 00                             mov     [esi+150h], ebx
00409623  c7 86 74 01 00 00 0c 00 00 00                 mov     dword ptr [esi+174h], 0Ch
0040962D  89 8e 78 01 00 00                             mov     [esi+178h], ecx
00409633  89 8e 80 01 00 00                             mov     [esi+180h], ecx
00409639  c7 86 88 01 00 00 62 00 00 00                 mov     dword ptr [esi+188h], 62h ; 'b'
00409643  89 be 8c 01 00 00                             mov     [esi+18Ch], edi
00409649  89 8e 90 01 00 00                             mov     [esi+190h], ecx
0040964F  89 9e 98 01 00 00                             mov     [esi+198h], ebx
00409655  89 96 9c 01 00 00                             mov     [esi+19Ch], edx
0040965B  89 9e a0 01 00 00                             mov     [esi+1A0h], ebx
00409661  c7 86 a4 01 00 00 01 00 00 00                 mov     dword ptr [esi+1A4h], 1
0040966B  89 86 a8 01 00 00                             mov     [esi+1A8h], eax
00409671  89 9e ac 01 00 00                             mov     [esi+1ACh], ebx
00409677  89 9e b0 01 00 00                             mov     [esi+1B0h], ebx
0040967D  c7 86 b4 01 00 00 14 00 00 00                 mov     dword ptr [esi+1B4h], 14h
00409687  c7 86 b8 01 00 00 0e 00 00 00                 mov     dword ptr [esi+1B8h], 0Eh
00409691  89 96 bc 01 00 00                             mov     [esi+1BCh], edx
00409697  89 be c0 01 00 00                             mov     [esi+1C0h], edi
0040969D  c7 86 c4 01 00 00 08 00 00 00                 mov     dword ptr [esi+1C4h], 8
004096A7  89 9e c8 01 00 00                             mov     [esi+1C8h], ebx
004096AD  c7 86 cc 01 00 00 24 00 00 00                 mov     dword ptr [esi+1CCh], 24h ; '$'
004096B7  89 9e d0 01 00 00                             mov     [esi+1D0h], ebx
004096BD  89 96 d4 01 00 00                             mov     [esi+1D4h], edx
004096C3  c7 86 e0 01 00 00 50 00 00 00                 mov     dword ptr [esi+1E0h], 50h ; 'P'
004096CD  c7 86 e4 01 00 00 3c 00 00 00                 mov     dword ptr [esi+1E4h], 3Ch ; '<'
004096D7  c7 86 e8 01 00 00 28 00 00 00                 mov     dword ptr [esi+1E8h], 28h ; '('
004096E1  c7 86 ec 01 00 00 32 00 00 00                 mov     dword ptr [esi+1ECh], 32h ; '2'
004096EB  89 86 f0 01 00 00                             mov     [esi+1F0h], eax
004096F1  8d be f4 01 00 00                             lea     edi, [esi+1F4h]
004096F7  b9 20 03 00 00                                mov     ecx, 320h
004096FC  b8 aa fe 03 00                                mov     eax, 3FEAAh
00409701  c7 86 74 0e 00 00 00 40 0a 00                 mov     dword ptr [esi+0E74h], 0A4000h
0040970B  f3 ab                                         rep stosd
0040970D  66 c7 86 38 11 00 00 dc 05                    mov     word ptr [esi+1138h], 5DCh
00409716  c7 86 30 11 00 00 40 07 61 00                 mov     dword ptr [esi+1130h], 610740h
00409720  b8 2a db 42 00                                mov     eax, offset unk_42DB2A
00409725  8d 8e 7a 0e 00 00                             lea     ecx, [esi+0E7Ah]
0040972B  66 8b 78 fe                                   mov     di, [eax-2]
0040972F  83 c0 06                                      add     eax, 6
00409732  66 89 79 fe                                   mov     [ecx-2], di
00409736  66 8b 78 fa                                   mov     di, [eax-6]
0040973A  66 89 39                                      mov     [ecx], di
0040973D  66 8b 78 fc                                   mov     di, [eax-4]
00409741  66 89 79 02                                   mov     [ecx+2], di
00409745  83 c1 06                                      add     ecx, 6
00409748  3d 86 dc 42 00                                cmp     eax, offset word_42DC86
0040974D  7c dc                                         jl      short loc_40972B
0040974F  b8 86 dc 42 00                                mov     eax, offset word_42DC86
00409754  8d 8e d6 0f 00 00                             lea     ecx, [esi+0FD6h]
0040975A  66 89 59 02                                   mov     [ecx+2], bx
0040975E  66 89 19                                      mov     [ecx], bx
00409761  66 89 59 fe                                   mov     [ecx-2], bx
00409765  66 89 58 02                                   mov     [eax+2], bx
00409769  66 89 18                                      mov     [eax], bx
0040976C  66 89 58 fe                                   mov     [eax-2], bx
00409770  83 c0 06                                      add     eax, 6
00409773  83 c1 06                                      add     ecx, 6
00409776  3d e2 dd 42 00                                cmp     eax, offset word_42DDE2
0040977B  7c dd                                         jl      short loc_40975A
0040977D  89 9e 3c 11 00 00                             mov     [esi+113Ch], ebx
00409783  89 9e 40 11 00 00                             mov     [esi+1140h], ebx
00409789  b9 56 ed ff ff                                mov     ecx, 0FFFFED56h
0040978E  c7 86 70 12 00 00 62 56 0a 00                 mov     dword ptr [esi+1270h], 0A5662h
00409798  c7 86 74 12 00 00 30 56 0a 00                 mov     dword ptr [esi+1274h], 0A5630h
004097A2  8d 86 aa 12 00 00                             lea     eax, [esi+12AAh]
004097A8  2b ce                                         sub     ecx, esi
004097AA  c6 40 ce 32                                   mov     byte ptr [eax-32h], 32h ; '2'
004097AE  88 10                                         mov     [eax], dl
004097B0  40                                            inc     eax
004097B1  8d 3c 01                                      lea     edi, [ecx+eax]
004097B4  83 ff 32                                      cmp     edi, 32h ; '2'
004097B7  7c f1                                         jl      short loc_4097AA
004097B9  c7 86 dc 12 00 00 00 6e 0a 00                 mov     dword ptr [esi+12DCh], 0A6E00h
004097C3  c7 86 e0 12 00 00 c0 3c 0a 00                 mov     dword ptr [esi+12E0h], 0A3CC0h
004097CD  33 c0                                         xor     eax, eax
004097CF  b1 02                                         mov     cl, 2
004097D1  8a 90 d8 da 42 00                             mov     dl, byte_42DAD8[eax]
004097D7  02 d1                                         add     dl, cl
004097D9  88 90 d8 da 42 00                             mov     byte_42DAD8[eax], dl
004097DF  40                                            inc     eax
004097E0  83 f8 32                                      cmp     eax, 32h ; '2'
004097E3  7c ec                                         jl      short loc_4097D1
004097E5  88 9e e4 12 00 00                             mov     [esi+12E4h], bl
004097EB  88 9e 82 13 00 00                             mov     [esi+1382h], bl
004097F1  c7 86 5c 14 00 00 e0 1a 0a 00                 mov     dword ptr [esi+145Ch], 0A1AE0h
004097FB  89 9e d8 01 00 00                             mov     [esi+1D8h], ebx
00409801  c7 86 dc 01 00 00 23 00 00 00                 mov     dword ptr [esi+1DCh], 23h ; '#'
0040980B  8b 56 20                                      mov     edx, [esi+20h]
0040980E  53                                            push    ebx; lpTimerFunc
0040980F  68 e8 03 00 00                                push    3E8h; uElapse
00409814  6a 27                                         push    27h ; '''; nIDEvent
00409816  52                                            push    edx; hWnd
00409817  ff 15 38 c3 41 00                             call    ds:SetTimer; USER32
0040981D  3b c3                                         cmp     eax, ebx
0040981F  89 46 68                                      mov     [esi+68h], eax
00409822  75 0c                                         jnz     short loc_409830
00409824  53                                            push    ebx; unsigned int
00409825  53                                            push    ebx; unsigned int
00409826  68 1c ed 42 00                                push    offset byte_42ED1C; char *
0040982B  e8 e2 0d 01 00                                call    ?AfxMessageBox@@YGHPBDII@Z; AfxMessageBox(char const *,uint,uint)
00409830  8b ce                                         mov     ecx, esi; struct CWnd *
00409832  e8 89 f9 00 00                                call    sub_4191C0
00409837  5f                                            pop     edi
00409838  5e                                            pop     esi
00409839  b8 01 00 00 00                                mov     eax, 1
0040983E  5b                                            pop     ebx
0040983F  c3                                            retn
