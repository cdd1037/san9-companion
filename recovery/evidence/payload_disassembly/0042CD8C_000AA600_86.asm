; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042CD8C; baseline game VA=0x000AA600; size=134
; Relative branch annotations use the baseline game destination.
000AA600 [0042CD8C] 85 c0                                        test    eax, eax
000AA602 [0042CD8E] 74 0d                                        jz      short near ptr dword_42CD94+9 ; game-relative-target=0x000AA611
000AA604 [0042CD90] 8b ce                                        mov     ecx, esi
000AA606 [0042CD92] 8b 54 24 18                                  mov     edx, [esp+18h]
000AA60A [0042CD96] e8 31 00 00 00                               call    near ptr dword_42CD94+38h ; game-relative-target=0x000AA640
000AA60F [0042CD9B] 85 c0                                        test    eax, eax
000AA611 [0042CD9D] c2 08 00                                     retn    8
000AA614 [0042CDA0] 00    db 0x00
000AA615 [0042CDA1] 00    db 0x00
000AA616 [0042CDA2] 00    db 0x00
000AA617 [0042CDA3] 00 8b 54 24 04 57                            add     [ebx+57042454h], cl
000AA61D [0042CDA9] 8d 4a f8                                     lea     ecx, [edx-8]
000AA620 [0042CDAC] 8b 7a 0c                                     mov     edi, [edx+0Ch]
000AA623 [0042CDAF] b8 90 e7 49 00                               mov     eax, 49E790h
000AA628 [0042CDB4] ff d0                                        call    eax
000AA62A [0042CDB6] 85 c0                                        test    eax, eax
000AA62C [0042CDB8] 74 0e                                        jz      short near ptr dword_42CD94+34h ; game-relative-target=0x000AA63C
000AA62E [0042CDBA] 8b c8                                        mov     ecx, eax
000AA630 [0042CDBC] 8b 10                                        mov     edx, [eax]
000AA632 [0042CDBE] ff 52 30                                     call    dword ptr [edx+30h]
000AA635 [0042CDC1] 2b c7                                        sub     eax, edi
000AA637 [0042CDC3] f7 d8                                        neg     eax
000AA639 [0042CDC5] 1b c0                                        sbb     eax, eax
000AA63B [0042CDC7] 40                                           inc     eax
000AA63C [0042CDC8] 5f                                           pop     edi
000AA63D [0042CDC9] c3                                           retn
000AA63E [0042CDCA] 00    db 0x00
000AA63F [0042CDCB] 00 56 8b                                     add     [esi-75h], dl
000AA642 [0042CDCE] f1                                           icebp
000AA643 [0042CDCF] ff b2 b8 00 00 00                            push    dword ptr [edx+0B8h]
000AA649 [0042CDD5] 68 ff ff ff 7f                               push    7FFFFFFFh
000AA64E [0042CDDA] 6a 00                                        push    0
000AA650 [0042CDDC] 6a 00                                        push    0
000AA652 [0042CDDE] 83 ec 20                                     sub     esp, 20h ; ' '
000AA655 [0042CDE1] 8b cc                                        mov     ecx, esp
000AA657 [0042CDE3] b8 70 c9 46 00                               mov     eax, 46C970h
000AA65C [0042CDE8] ff d0                                        call    eax
000AA65E [0042CDEA] 8d 54 24 20                                  lea     edx, [esp+20h]
000AA662 [0042CDEE] 6a 00                                        push    0
000AA664 [0042CDF0] 68 18 a6 0a 00                               push    0AA618h
000AA669 [0042CDF5] 52                                           push    edx
000AA66A [0042CDF6] 50                                           push    eax
000AA66B [0042CDF7] 8b ce                                        mov     ecx, esi
000AA66D [0042CDF9] b8 20 5a 43 00                               mov     eax, 435A20h
000AA672 [0042CDFE] ff d0                                        call    eax
000AA674 [0042CE00] 8b f0                                        mov     esi, eax
000AA676 [0042CE02] 8b cc                                        mov     ecx, esp
000AA678 [0042CE04] b8 90 c9 46 00                               mov     eax, 46C990h
000AA67D [0042CE09] ff d0                                        call    eax
000AA67F [0042CE0B] 83 c4 30                                     add     esp, 30h
000AA682 [0042CE0E] 8b c6                                        mov     eax, esi
000AA684 [0042CE10] 5e                                           pop     esi
000AA685 [0042CE11] c3                                           retn
