; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004202B0; baseline game VA=0x000A0600; size=244
; Relative branch annotations use the baseline game destination.
000A0600 [004202B0] 56                                           push    esi
000A0601 [004202B1] 57                                           push    edi
000A0602 [004202B2] 8b f2                                        mov     esi, edx
000A0604 [004202B4] 8b f9                                        mov     edi, ecx
000A0606 [004202B6] b8 20 54 43 00                               mov     eax, 435420h
000A060B [004202BB] ff d0                                        call    eax
000A060D [004202BD] 85 c0                                        test    eax, eax
000A060F [004202BF] 74 3b                                        jz      short near ptr unk_4202FC ; game-relative-target=0x000A064C
000A0611 [004202C1] 8b 4e 74                                     mov     ecx, [esi+74h]
000A0614 [004202C4] f6 41 34 01                                  test    byte ptr [ecx+34h], 1
000A0618 [004202C8] 74 32                                        jz      short near ptr unk_4202FC ; game-relative-target=0x000A064C
000A061A [004202CA] 8b 97 cc 00 00 00                            mov     edx, [edi+0CCh]
000A0620 [004202D0] 85 d2                                        test    edx, edx
000A0622 [004202D2] 74 28                                        jz      short near ptr unk_4202FC ; game-relative-target=0x000A064C
000A0624 [004202D4] 51                                           push    ecx
000A0625 [004202D5] 52                                           push    edx
000A0626 [004202D6] b8 70 06 4b 00                               mov     eax, 4B0670h
000A062B [004202DB] ff d0                                        call    eax
000A062D [004202DD] 83 c4 08                                     add     esp, 8
000A0630 [004202E0] 85 c0                                        test    eax, eax
000A0632 [004202E2] 74 18                                        jz      short near ptr unk_4202FC ; game-relative-target=0x000A064C
000A0634 [004202E4] 56                                           push    esi
000A0635 [004202E5] 8b cf                                        mov     ecx, edi
000A0637 [004202E7] b8 80 0a 0a 00                               mov     eax, 0A0A80h
000A063C [004202EC] ff d0                                        call    eax
000A063E [004202EE] 83 f8 1e                                     cmp     eax, 1Eh
000A0641 [004202F1] 7f 04                                        jg      short near ptr unk_4202F7 ; game-relative-target=0x000A0647
000A0643 [004202F3] b0 01                                        mov     al, 1
000A0645 [004202F5] eb 67                                        jmp     short near ptr unk_42035E ; game-relative-target=0x000A06AE
000A0647 [004202F7] 83 f8 3c                                     cmp     eax, 3Ch ; '<'
000A064A [004202FA] 7e 04                                        jle     short near ptr unk_420300 ; game-relative-target=0x000A0650
000A064C [004202FC] 33 c0                                        xor     eax, eax
000A064E [004202FE] eb 5e                                        jmp     short near ptr unk_42035E ; game-relative-target=0x000A06AE
000A0650 [00420300] 81 bf 88 00 00 00 10 27 00 00                cmp     dword ptr [edi+88h], 2710h
000A065A [0042030A] 7d 07                                        jge     short near ptr unk_420313 ; game-relative-target=0x000A0663
000A065C [0042030C] ba 0c 00 00 00                               mov     edx, 0Ch
000A0661 [00420311] eb 36                                        jmp     short near ptr unk_420349 ; game-relative-target=0x000A0699
000A0663 [00420313] 8b 4e 6c                                     mov     ecx, [esi+6Ch]
000A0666 [00420316] 8a 41 04                                     mov     al, [ecx+4]
000A0669 [00420319] 3c 0d                                        cmp     al, 0Dh
000A066B [0042031B] 74 df                                        jz      short near ptr unk_4202FC ; game-relative-target=0x000A064C
000A066D [0042031D] 3c 0e                                        cmp     al, 0Eh
000A066F [0042031F] 74 00                                        jz      short $+2 ; game-relative-target=0x000A0671
000A0671 [00420321] 50                                           push    eax
000A0672 [00420322] 8b ce                                        mov     ecx, esi
000A0674 [00420324] b8 90 e3 45 00                               mov     eax, 45E390h
000A0679 [00420329] ff d0                                        call    eax
000A067B [0042032B] 85 c0                                        test    eax, eax
000A067D [0042032D] 58                                           pop     eax
000A067E [0042032E] ba 08 00 00 00                               mov     edx, 8
000A0683 [00420333] 74 2c                                        jz      short near ptr unk_420361 ; game-relative-target=0x000A06B1
000A0685 [00420335] b2 0a                                        mov     dl, 0Ah
000A0687 [00420337] 8b 4e 70                                     mov     ecx, [esi+70h]
000A068A [0042033A] 8a 41 04                                     mov     al, [ecx+4]
000A068D [0042033D] 3c 16                                        cmp     al, 16h
000A068F [0042033F] 75 02                                        jnz     short near ptr unk_420343 ; game-relative-target=0x000A0693
000A0691 [00420341] b2 0d                                        mov     dl, 0Dh
000A0693 [00420343] 3c 17                                        cmp     al, 17h
000A0695 [00420345] 75 02                                        jnz     short near ptr unk_420349 ; game-relative-target=0x000A0699
000A0697 [00420347] b2 0c                                        mov     dl, 0Ch
000A0699 [00420349] 52                                           push    edx
000A069A [0042034A] 57                                           push    edi
000A069B [0042034B] 8b ce                                        mov     ecx, esi
000A069D [0042034D] b8 40 0c 0a 00                               mov     eax, 0A0C40h
000A06A2 [00420352] ff d0                                        call    eax
000A06A4 [00420354] 5a                                           pop     edx
000A06A5 [00420355] 33 c9                                        xor     ecx, ecx
000A06A7 [00420357] 3b c2                                        cmp     eax, edx
000A06A9 [00420359] 0f 9e c1                                     setle   cl
000A06AC [0042035C] 8b c1                                        mov     eax, ecx
000A06AE [0042035E] 5f                                           pop     edi
000A06AF [0042035F] 5e                                           pop     esi
000A06B0 [00420360] c3                                           retn
000A06B1 [00420361] 3c 08                                        cmp     al, 8
000A06B3 [00420363] 75 02                                        jnz     short near ptr unk_420367 ; game-relative-target=0x000A06B7
000A06B5 [00420365] b2 0f                                        mov     dl, 0Fh
000A06B7 [00420367] 3c 0a                                        cmp     al, 0Ah
000A06B9 [00420369] 75 02                                        jnz     short near ptr unk_42036D ; game-relative-target=0x000A06BD
000A06BB [0042036B] b2 0c                                        mov     dl, 0Ch
000A06BD [0042036D] 3c 04                                        cmp     al, 4
000A06BF [0042036F] 74 04                                        jz      short near ptr unk_420375 ; game-relative-target=0x000A06C5
000A06C1 [00420371] 3c 05                                        cmp     al, 5
000A06C3 [00420373] 75 02                                        jnz     short near ptr unk_420377 ; game-relative-target=0x000A06C7
000A06C5 [00420375] b2 0a                                        mov     dl, 0Ah
000A06C7 [00420377] 3c 02                                        cmp     al, 2
000A06C9 [00420379] 75 ce                                        jnz     short near ptr unk_420349 ; game-relative-target=0x000A0699
000A06CB [0042037B] 8b 8e 88 00 00 00                            mov     ecx, [esi+88h]
000A06D1 [00420381] 8b 41 08                                     mov     eax, [ecx+8]
000A06D4 [00420384] 8b 09                                        mov     ecx, [ecx]
000A06D6 [00420386] 8b 80 f8 00 00 00                            mov     eax, [eax+0F8h]
000A06DC [0042038C] 85 c0                                        test    eax, eax
000A06DE [0042038E] 74 0e                                        jz      short near ptr unk_42039E ; game-relative-target=0x000A06EE
000A06E0 [00420390] 80 78 04 06                                  cmp     byte ptr [eax+4], 6
000A06E4 [00420394] 7c 08                                        jl      short near ptr unk_42039E ; game-relative-target=0x000A06EE
000A06E6 [00420396] 80 78 04 08                                  cmp     byte ptr [eax+4], 8
000A06EA [0042039A] 7f 02                                        jg      short near ptr unk_42039E ; game-relative-target=0x000A06EE
000A06EC [0042039C] 42                                           inc     edx
000A06ED [0042039D] 90                                           nop
000A06EE [0042039E] 85 c9                                        test    ecx, ecx
000A06F0 [004203A0] 75 df                                        jnz     short near ptr unk_420381 ; game-relative-target=0x000A06D1
000A06F2 [004203A2] eb a5                                        jmp     short near ptr unk_420349 ; game-relative-target=0x000A0699
