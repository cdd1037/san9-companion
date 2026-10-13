; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042C568; baseline game VA=0x000A25D0; size=46
; Relative branch annotations use the baseline game destination.
000A25D0 [0042C568] 68 b0 ed 47 00                               push    47EDB0h
000A25D5 [0042C56D] 6a 12                                        push    12h
000A25D7 [0042C56F] ff 15 5c f3 5f 00                            call    dword ptr ds:5FF35Ch
000A25DD [0042C575] 84 e4                                        test    ah, ah
000A25DF [0042C577] 79 01                                        jns     short near ptr unk_42C57A ; game-relative-target=0x000A25E2
000A25E1 [0042C579] c3                                           retn
000A25E2 [0042C57A] 57                                           push    edi
000A25E3 [0042C57B] 8b d4                                        mov     edx, esp
000A25E5 [0042C57D] 57                                           push    edi
000A25E6 [0042C57E] 57                                           push    edi
000A25E7 [0042C57F] 57                                           push    edi
000A25E8 [0042C580] 57                                           push    edi
000A25E9 [0042C581] 53                                           push    ebx
000A25EA [0042C582] 52                                           push    edx
000A25EB [0042C583] b8 40 04 57 00                               mov     eax, 570440h
000A25F0 [0042C588] ff d0                                        call    eax
000A25F2 [0042C58A] 83 c4 18                                     add     esp, 18h
000A25F5 [0042C58D] 5e                                           pop     esi
000A25F6 [0042C58E] 68 5a 86 41 00                               push    41865Ah
000A25FB [0042C593] c2 08 00                                     retn    8
