; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042BFA8; baseline game VA=0x000AA700; size=160
; Relative branch annotations use the baseline game destination.
000AA700 [0042BFA8] 8b 6c 24 44                                  mov     ebp, [esp+44h]
000AA704 [0042BFAC] f6 45 34 01                                  test    byte ptr [ebp+34h], 1
000AA708 [0042BFB0] 74 07                                        jz      short near ptr unk_42BFB9 ; game-relative-target=0x000AA711
000AA70A [0042BFB2] 5a                                           pop     edx
000AA70B [0042BFB3] ff 74 24 54                                  push    dword ptr [esp+54h]
000AA70F [0042BFB7] ff e2                                        jmp     edx
000AA711 [0042BFB9] 8b 74 24 08                                  mov     esi, [esp+8]
000AA715 [0042BFBD] 68 7c 3b 5d 00                               push    5D3B7Ch
000AA71A [0042BFC2] 68 40 f5 43 00                               push    43F540h
000AA71F [0042BFC7] 68 d0 f2 43 00                               push    43F2D0h
000AA724 [0042BFCC] 68 80 f1 43 00                               push    43F180h
000AA729 [0042BFD1] 83 ec 10                                     sub     esp, 10h
000AA72C [0042BFD4] 8b cd                                        mov     ecx, ebp
000AA72E [0042BFD6] ff 54 24 10                                  call    dword ptr [esp+10h]
000AA732 [0042BFDA] 89 04 24                                     mov     [esp], eax
000AA735 [0042BFDD] 8b cd                                        mov     ecx, ebp
000AA737 [0042BFDF] ff 54 24 14                                  call    dword ptr [esp+14h]
000AA73B [0042BFE3] 01 04 24                                     add     [esp], eax
000AA73E [0042BFE6] 8b cd                                        mov     ecx, ebp
000AA740 [0042BFE8] ff 54 24 18                                  call    dword ptr [esp+18h]
000AA744 [0042BFEC] 89 44 24 04                                  mov     [esp+4], eax
000AA748 [0042BFF0] 8b cf                                        mov     ecx, edi
000AA74A [0042BFF2] ff 54 24 10                                  call    dword ptr [esp+10h]
000AA74E [0042BFF6] 89 44 24 08                                  mov     [esp+8], eax
000AA752 [0042BFFA] 01 04 24                                     add     [esp], eax
000AA755 [0042BFFD] 8b cf                                        mov     ecx, edi
000AA757 [0042BFFF] ff 54 24 14                                  call    dword ptr [esp+14h]
000AA75B [0042C003] 01 44 24 08                                  add     [esp+8], eax
000AA75F [0042C007] 01 04 24                                     add     [esp], eax
000AA762 [0042C00A] 8b cf                                        mov     ecx, edi
000AA764 [0042C00C] ff 54 24 18                                  call    dword ptr [esp+18h]
000AA768 [0042C010] 89 44 24 0c                                  mov     [esp+0Ch], eax
000AA76C [0042C014] 01 44 24 04                                  add     [esp+4], eax
000AA770 [0042C018] db 45 18                                     fild    dword ptr [ebp+18h]
000AA773 [0042C01B] da 4c 24 08                                  fimul   dword ptr [esp+8]
000AA777 [0042C01F] da 34 24                                     fidiv   dword ptr [esp]
000AA77A [0042C022] ff 54 24 1c                                  call    dword ptr [esp+1Ch]
000AA77E [0042C026] 89 46 74                                     mov     [esi+74h], eax
000AA781 [0042C029] 89 44 24 7c                                  mov     [esp+7Ch], eax
000AA785 [0042C02D] db 45 14                                     fild    dword ptr [ebp+14h]
000AA788 [0042C030] da 4c 24 0c                                  fimul   dword ptr [esp+0Ch]
000AA78C [0042C034] da 74 24 04                                  fidiv   dword ptr [esp+4]
000AA790 [0042C038] ff 54 24 1c                                  call    dword ptr [esp+1Ch]
000AA794 [0042C03C] 89 46 70                                     mov     [esi+70h], eax
000AA797 [0042C03F] 87 44 24 20                                  xchg    eax, [esp+20h]
000AA79B [0042C043] 83 c4 20                                     add     esp, 20h ; ' '
000AA79E [0042C046] ff e0                                        jmp     eax
