; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004260A0; baseline game VA=0x000A5A00; size=63
; Relative branch annotations use the baseline game destination.
000A5A00 [004260A0] 53                                           push    ebx
000A5A01 [004260A1] b8 40 58 40 00                               mov     eax, 405840h
000A5A06 [004260A6] ff d0                                        call    eax
000A5A08 [004260A8] 59                                           pop     ecx
000A5A09 [004260A9] 85 c0                                        test    eax, eax
000A5A0B [004260AB] 75 01                                        jnz     short near ptr unk_4260AE ; game-relative-target=0x000A5A0E
000A5A0D [004260AD] c3                                           retn
000A5A0E [004260AE] 8b 46 64                                     mov     eax, [esi+64h]
000A5A11 [004260B1] 66 83 78 06 05                               cmp     word ptr [eax+6], 5
000A5A16 [004260B6] 75 01                                        jnz     short near ptr unk_4260B9 ; game-relative-target=0x000A5A19
000A5A18 [004260B8] c3                                           retn
000A5A19 [004260B9] 83 ec 10                                     sub     esp, 10h
000A5A1C [004260BC] 8b cc                                        mov     ecx, esp
000A5A1E [004260BE] 83 c0 10                                     add     eax, 10h
000A5A21 [004260C1] 50                                           push    eax
000A5A22 [004260C2] 8d 46 10                                     lea     eax, [esi+10h]
000A5A25 [004260C5] 50                                           push    eax
000A5A26 [004260C6] 51                                           push    ecx
000A5A27 [004260C7] ff 15 60 f3 5f 00                            call    dword ptr ds:5FF360h
000A5A2D [004260CD] 83 c4 10                                     add     esp, 10h
000A5A30 [004260D0] 85 c0                                        test    eax, eax
000A5A32 [004260D2] 75 03                                        jnz     short near ptr unk_4260D7 ; game-relative-target=0x000A5A37
000A5A34 [004260D4] b0 01                                        mov     al, 1
000A5A36 [004260D6] c3                                           retn
000A5A37 [004260D7] 68 76 42 46 00                               push    464276h
000A5A3C [004260DC] c2 08 00                                     retn    8
