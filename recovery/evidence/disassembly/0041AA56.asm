0041AA56  ff 74 24 10                                   push    [esp+nShowCmd]; int
0041AA5A  ff 74 24 10                                   push    [esp+4+lpCmdLine]; char *
0041AA5E  ff 74 24 10                                   push    [esp+8+hPrevInstance]; HINSTANCE
0041AA62  ff 74 24 10                                   push    [esp+0Ch+hInstance]; HINSTANCE
0041AA66  e8 43 00 00 00                                call    ?AfxWinMain@@YGHPAUHINSTANCE__@@0PADH@Z
0041AA6B  c2 10 00                                      retn    10h
