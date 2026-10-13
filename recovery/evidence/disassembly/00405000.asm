00405000  53                                            push    ebx
00405001  55                                            push    ebp
00405002  8b 6c 24 14                                   mov     ebp, [esp+8+arg_8]
00405006  8b 5c 24 0c                                   mov     ebx, [esp+8+arg_0]
0040500A  56                                            push    esi
0040500B  8b f1                                         mov     esi, ecx
0040500D  57                                            push    edi
0040500E  8d 86 a0 00 00 00                             lea     eax, [esi+0A0h]
00405014  3b e8                                         cmp     ebp, eax
00405016  75 67                                         jnz     short def_405023; jumptable 00405023 default case, case 4
00405018  8b be 48 01 00 00                             mov     edi, [esi+148h]
0040501E  83 fb 05                                      cmp     ebx, 5; switch 6 cases
00405021  77 5c                                         ja      short def_405023; jumptable 00405023 default case, case 4
00405023  ff 24 9d 94 50 40 00                          jmp     ds:jpt_405023[ebx*4]; switch jump
0040502A  4f                                            dec     edi; jumptable 00405023 cases 0,2
0040502B  79 15                                         jns     short loc_405042
0040502D  33 ff                                         xor     edi, edi
0040502F  eb 11                                         jmp     short loc_405042
00405031  47                                            inc     edi; jumptable 00405023 cases 1,3
00405032  83 ff 73                                      cmp     edi, 73h ; 's'
00405035  7e 0b                                         jle     short loc_405042
00405037  bf 73 00 00 00                                mov     edi, 73h ; 's'
0040503C  eb 04                                         jmp     short loc_405042
0040503E  8b 7c 24 18                                   mov     edi, [esp+10h+arg_4]; jumptable 00405023 case 5
00405042  8b ce                                         mov     ecx, esi
00405044  e8 37 04 00 00                                call    sub_405480
00405049  85 c0                                         test    eax, eax
0040504B  74 32                                         jz      short def_405023; jumptable 00405023 default case, case 4
0040504D  89 be 48 01 00 00                             mov     [esi+148h], edi
00405053  8b 8e c0 00 00 00                             mov     ecx, [esi+0C0h]
00405059  6a 01                                         push    1; bRedraw
0040505B  57                                            push    edi; nPos
0040505C  6a 02                                         push    2; nBar
0040505E  51                                            push    ecx; hWnd
0040505F  ff 15 18 c3 41 00                             call    ds:SetScrollPos; USER32
00405065  68 5e 04 00 00                                push    45Eh; int
0040506A  8b ce                                         mov     ecx, esi; this
0040506C  e8 49 56 01 00                                call    ?GetDlgItem@CWnd@@QBEPAV1@H@Z; CWnd::GetDlgItem(int)
00405071  8b c8                                         mov     ecx, eax; this
00405073  e8 3c 56 01 00                                call    ?SetFocus@CWnd@@QAEPAV1@XZ; CWnd::SetFocus(void)
00405078  8b ce                                         mov     ecx, esi
0040507A  e8 71 04 00 00                                call    sub_4054F0
0040507F  8b 54 24 18                                   mov     edx, [esp+10h+arg_4]; jumptable 00405023 default case, case 4
00405083  55                                            push    ebp; struct CScrollBar *
00405084  52                                            push    edx; unsigned int
00405085  53                                            push    ebx; unsigned int
00405086  8b ce                                         mov     ecx, esi; this
00405088  e8 93 56 01 00                                call    ?OnHScroll@CWnd@@IAEXIIPAVCScrollBar@@@Z; CWnd::OnHScroll(uint,uint,CScrollBar *)
0040508D  5f                                            pop     edi
0040508E  5e                                            pop     esi
0040508F  5d                                            pop     ebp
00405090  5b                                            pop     ebx
00405091  c2 0c 00                                      retn    0Ch
