; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00420E80; baseline game VA=0x000A0EC0; size=39
; Relative branch annotations use the baseline game destination.
000A0EC0 [00420E80] b8 e0 11 4a 00                               mov     eax, 4A11E0h
000A0EC5 [00420E85] ff d0                                        call    eax
000A0EC7 [00420E87] 3b 1d e4 fb 43 00                            cmp     ebx, ds:43FBE4h
000A0ECD [00420E8D] 75 17                                        jnz     short near ptr unk_420EA6 ; game-relative-target=0x000A0EE6
000A0ECF [00420E8F] a1 e8 fb 43 00                               mov     eax, ds:43FBE8h
000A0ED4 [00420E94] 0f b6 50 04                                  movzx   edx, byte ptr [eax+4]
000A0ED8 [00420E98] c6 82 00 0e 0a 00 02                         mov     byte ptr [edx+0A0E00h], 2
000A0EDF [00420E9F] 33 c0                                        xor     eax, eax
000A0EE1 [00420EA1] a3 e4 fb 43 00                               mov     ds:43FBE4h, eax
000A0EE6 [00420EA6] c3                                           retn
