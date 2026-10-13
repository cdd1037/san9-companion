0041A87F  83 3d 24 f8 42 00 ff                          cmp     dword_42F824, 0FFFFFFFFh
0041A886  75 0c                                         jnz     short loc_41A894
0041A888  ff 74 24 04                                   push    [esp+Func]; Func
0041A88C  ff 15 f0 c2 41 00                             call    ds:_onexit; MSVCRT
0041A892  59                                            pop     ecx
0041A893  c3                                            retn
0041A894  68 20 f8 42 00                                push    offset dword_42F820
0041A899  68 24 f8 42 00                                push    offset dword_42F824
0041A89E  ff 74 24 0c                                   push    [esp+8+Func]
0041A8A2  e8 7b 01 00 00                                call    __dllonexit
0041A8A7  83 c4 0c                                      add     esp, 0Ch
0041A8AA  c3                                            retn
