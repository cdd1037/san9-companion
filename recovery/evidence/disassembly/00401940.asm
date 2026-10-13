00401940  56                                            push    esi
00401941  8b f1                                         mov     esi, ecx
00401943  e8 28 fc ff ff                                call    sub_401570
00401948  85 c0                                         test    eax, eax
0040194A  74 07                                         jz      short loc_401953
0040194C  8b ce                                         mov     ecx, esi; this
0040194E  e8 25 8d 01 00                                call    ?OnOK@CDialog@@MAEXXZ; CDialog::OnOK(void)
00401953  5e                                            pop     esi
00401954  c3                                            retn
