; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00425530; baseline game VA=0x000A5CB0; size=80
; Relative branch annotations use the baseline game destination.
000A5CB0 [00425530] 53                                           push    ebx
000A5CB1 [00425531] bb 10 27 00 00                               mov     ebx, 2710h
000A5CB6 [00425536] 8b ce                                        mov     ecx, esi
000A5CB8 [00425538] 8b 01                                        mov     eax, [ecx]
000A5CBA [0042553A] ff 50 0c                                     call    dword ptr [eax+0Ch]
000A5CBD [0042553D] 8b b4 87 58 08 00 00                         mov     esi, [edi+eax*4+858h]
000A5CC4 [00425544] 3b f3                                        cmp     esi, ebx
000A5CC6 [00425546] 7e 34                                        jle     short near ptr unk_42557C ; game-relative-target=0x000A5CFC
000A5CC8 [00425548] 8b 8f 48 0c 00 00                            mov     ecx, [edi+0C48h]
000A5CCE [0042554E] 8b 01                                        mov     eax, [ecx]
000A5CD0 [00425550] ff 50 0c                                     call    dword ptr [eax+0Ch]
000A5CD3 [00425553] 8b 84 87 58 08 00 00                         mov     eax, [edi+eax*4+858h]
000A5CDA [0042555A] f7 d8                                        neg     eax
000A5CDC [0042555C] 3b c3                                        cmp     eax, ebx
000A5CDE [0042555E] 7f 04                                        jg      short near ptr unk_425564 ; game-relative-target=0x000A5CE4
000A5CE0 [00425560] 8b c3                                        mov     eax, ebx
000A5CE2 [00425562] eb 1a                                        jmp     short near ptr unk_42557E ; game-relative-target=0x000A5CFE
000A5CE4 [00425564] 3b c6                                        cmp     eax, esi
000A5CE6 [00425566] 7d 02                                        jge     short near ptr unk_42556A ; game-relative-target=0x000A5CEA
000A5CE8 [00425568] 8b f0                                        mov     esi, eax
000A5CEA [0042556A] 8b 44 24 1c                                  mov     eax, [esp+1Ch]
000A5CEE [0042556E] 8b 48 08                                     mov     ecx, [eax+8]
000A5CF1 [00425571] b8 00 d7 44 00                               mov     eax, 44D700h
000A5CF6 [00425576] ff d0                                        call    eax
000A5CF8 [00425578] 3b c6                                        cmp     eax, esi
000A5CFA [0042557A] 7e 02                                        jle     short near ptr unk_42557E ; game-relative-target=0x000A5CFE
000A5CFC [0042557C] 8b c6                                        mov     eax, esi
000A5CFE [0042557E] 5b                                           pop     ebx
000A5CFF [0042557F] c3                                           retn
