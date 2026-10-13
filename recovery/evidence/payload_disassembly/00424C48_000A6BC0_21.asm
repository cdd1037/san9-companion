; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00424C48; baseline game VA=0x000A6BC0; size=33
; Relative branch annotations use the baseline game destination.
000A6BC0 [00424C48] 8a 45 04                                     mov     al, [ebp+4]
000A6BC3 [00424C4B] 8b 55 64                                     mov     edx, [ebp+64h]
000A6BC6 [00424C4E] 3c 08                                        cmp     al, 8
000A6BC8 [00424C50] 7c 04                                        jl      short near ptr unk_424C56 ; game-relative-target=0x000A6BCE
000A6BCA [00424C52] 3c 0b                                        cmp     al, 0Bh
000A6BCC [00424C54] 7e 03                                        jle     short near ptr unk_424C59 ; game-relative-target=0x000A6BD1
000A6BCE [00424C56] d1 e2                                        shl     edx, 1
000A6BD0 [00424C58] c3                                           retn
000A6BD1 [00424C59] 8b 4c 24 1c                                  mov     ecx, [esp+1Ch]
000A6BD5 [00424C5D] 52                                           push    edx
000A6BD6 [00424C5E] b8 b0 2d 0a 00                               mov     eax, 0A2DB0h
000A6BDB [00424C63] ff d0                                        call    eax
000A6BDD [00424C65] 8b d0                                        mov     edx, eax
000A6BDF [00424C67] eb ed                                        jmp     short near ptr unk_424C56 ; game-relative-target=0x000A6BCE
