; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00428E90; baseline game VA=0x000A0700; size=46
; Relative branch annotations use the baseline game destination.
000A0700 [00428E90] b8 40 d3 44 00                               mov     eax, 44D340h
000A0705 [00428E95] ff d0                                        call    eax
000A0707 [00428E97] 99                                           cdq
000A0708 [00428E98] 6a 0c                                        push    0Ch
000A070A [00428E9A] 59                                           pop     ecx
000A070B [00428E9B] f7 f9                                        idiv    ecx
000A070D [00428E9D] 3c 02                                        cmp     al, 2
000A070F [00428E9F] 7d 02                                        jge     short near ptr unk_428EA3 ; game-relative-target=0x000A0713
000A0711 [00428EA1] b0 02                                        mov     al, 2
000A0713 [00428EA3] 50                                           push    eax
000A0714 [00428EA4] 8b cb                                        mov     ecx, ebx
000A0716 [00428EA6] b8 d0 da 43 00                               mov     eax, 43DAD0h
000A071B [00428EAB] ff d0                                        call    eax
000A071D [00428EAD] 6a 01                                        push    1
000A071F [00428EAF] 8b cb                                        mov     ecx, ebx
000A0721 [00428EB1] b8 d0 32 44 00                               mov     eax, 4432D0h
000A0726 [00428EB6] ff d0                                        call    eax
000A0728 [00428EB8] 68 d0 6e 56 00                               push    566ED0h
000A072D [00428EBD] c3                                           retn
