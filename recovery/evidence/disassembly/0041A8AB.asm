0041A8AB  ff 74 24 04                                   push    [esp+Func]; Func
0041A8AF  e8 cb ff ff ff                                call    __onexit
0041A8B4  f7 d8                                         neg     eax
0041A8B6  1b c0                                         sbb     eax, eax
0041A8B8  59                                            pop     ecx
0041A8B9  f7 d8                                         neg     eax
0041A8BB  48                                            dec     eax
0041A8BC  c3                                            retn
