; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00425A50; baseline game VA=0x000A56D0; size=38
; Relative branch annotations use the baseline game destination.
000A56D0 [00425A50] 50                                           push    eax
000A56D1 [00425A51] 51                                           push    ecx
000A56D2 [00425A52] 52                                           push    edx
000A56D3 [00425A53] 8b 44 24 0c                                  mov     eax, [esp+0Ch]
000A56D7 [00425A57] 3c 7f                                        cmp     al, 7Fh
000A56D9 [00425A59] 74 0a                                        jz      short near ptr unk_425A65 ; game-relative-target=0x000A56E5
000A56DB [00425A5B] 3c 36                                        cmp     al, 36h ; '6'
000A56DD [00425A5D] 74 04                                        jz      short near ptr unk_425A63 ; game-relative-target=0x000A56E3
000A56DF [00425A5F] 8b ce                                        mov     ecx, esi
000A56E1 [00425A61] eb 02                                        jmp     short near ptr unk_425A65 ; game-relative-target=0x000A56E5
000A56E3 [00425A63] 8b cf                                        mov     ecx, edi
000A56E5 [00425A65] b8 b1 dd 45 00                               mov     eax, 45DDB1h
000A56EA [00425A6A] ff d0                                        call    eax
000A56EC [00425A6C] 5a                                           pop     edx
000A56ED [00425A6D] 59                                           pop     ecx
000A56EE [00425A6E] 87 44 24 04                                  xchg    eax, [esp+4]
000A56F2 [00425A72] 87 04 24                                     xchg    eax, [esp]
000A56F5 [00425A75] c3                                           retn
