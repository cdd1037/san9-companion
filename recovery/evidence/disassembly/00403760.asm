00403760  56                                            push    esi
00403761  8b f1                                         mov     esi, ecx
00403763  e8 88 08 00 00                                call    sub_403FF0
00403768  84 c0                                         test    al, al
0040376A  74 09                                         jz      short loc_403775
0040376C  6a 01                                         push    1; int
0040376E  8b ce                                         mov     ecx, esi; this
00403770  e8 39 6f 01 00                                call    ?EndDialog@CDialog@@QAEXH@Z; CDialog::EndDialog(int)
00403775  5e                                            pop     esi
00403776  c3                                            retn
