00409400  8b 44 24 04                                   mov     eax, [esp+arg_0]
00409404  81 c1 c8 1d 00 00                             add     ecx, 1DC8h
0040940A  51                                            push    ecx; struct CWnd *
0040940B  68 e9 03 00 00                                push    3E9h; int
00409410  50                                            push    eax; struct CDataExchange *
00409411  e8 ea 11 01 00                                call    ?DDX_Control@@YGXPAVCDataExchange@@HAAVCWnd@@@Z; DDX_Control(CDataExchange *,int,CWnd &)
00409416  c2 04 00                                      retn    4
