; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042AEF0; baseline game VA=0x000A8360; size=156
; Relative branch annotations use the baseline game destination.
000A8360 [0042AEF0] 8b 06                                        mov     eax, [esi]
000A8362 [0042AEF2] 8b d3                                        mov     edx, ebx
000A8364 [0042AEF4] 81 fd 00 01 00 00                            cmp     ebp, 100h
000A836A [0042AEFA] 75 30                                        jnz     short near ptr unk_42AF2C ; game-relative-target=0x000A839C
000A836C [0042AEFC] 3d 58 ce 60 00                               cmp     eax, 60CE58h
000A8371 [0042AF01] 75 09                                        jnz     short near ptr unk_42AF0C ; game-relative-target=0x000A837C
000A8373 [0042AF03] b8 00 89 0a 00                               mov     eax, 0A8900h
000A8378 [0042AF08] ff d0                                        call    eax
000A837A [0042AF0A] eb 54                                        jmp     short near ptr unk_42AF60 ; game-relative-target=0x000A83D0
000A837C [0042AF0C] 3d a8 cf 60 00                               cmp     eax, 60CFA8h
000A8381 [0042AF11] 75 09                                        jnz     short near ptr unk_42AF1C ; game-relative-target=0x000A838C
000A8383 [0042AF13] b8 60 93 0a 00                               mov     eax, 0A9360h
000A8388 [0042AF18] ff d0                                        call    eax
000A838A [0042AF1A] eb 44                                        jmp     short near ptr unk_42AF60 ; game-relative-target=0x000A83D0
000A838C [0042AF1C] 3d 30 c2 60 00                               cmp     eax, 60C230h
000A8391 [0042AF21] 75 3d                                        jnz     short near ptr unk_42AF60 ; game-relative-target=0x000A83D0
000A8393 [0042AF23] b8 e0 93 0a 00                               mov     eax, 0A93E0h
000A8398 [0042AF28] ff d0                                        call    eax
000A839A [0042AF2A] eb 34                                        jmp     short near ptr unk_42AF60 ; game-relative-target=0x000A83D0
000A839C [0042AF2C] 81 fd 01 01 00 00                            cmp     ebp, 101h
000A83A2 [0042AF32] 75 2c                                        jnz     short near ptr unk_42AF60 ; game-relative-target=0x000A83D0
000A83A4 [0042AF34] 3d 38 a2 60 00                               cmp     eax, 60A238h
000A83A9 [0042AF39] 75 09                                        jnz     short near ptr unk_42AF44 ; game-relative-target=0x000A83B4
000A83AB [0042AF3B] b8 00 90 0a 00                               mov     eax, 0A9000h
000A83B0 [0042AF40] ff d0                                        call    eax
000A83B2 [0042AF42] eb 1c                                        jmp     short near ptr unk_42AF60 ; game-relative-target=0x000A83D0
000A83B4 [0042AF44] 3d f8 fc 5f 00                               cmp     eax, 5FFCF8h
000A83B9 [0042AF49] 74 15                                        jz      short near ptr unk_42AF60 ; game-relative-target=0x000A83D0
000A83BB [0042AF4B] 3d e8 5b 61 00                               cmp     eax, 615BE8h
000A83C0 [0042AF50] 74 0e                                        jz      short near ptr unk_42AF60 ; game-relative-target=0x000A83D0
000A83C2 [0042AF52] 8d a4 24 00 00 00 00                         lea     esp, [esp+0]
000A83C9 [0042AF59] b8 d8 83 0a 00                               mov     eax, 0A83D8h
000A83CE [0042AF5E] ff d0                                        call    eax
000A83D0 [0042AF60] 8b ce                                        mov     ecx, esi
000A83D2 [0042AF62] 68 10 da 5c 00                               push    5CDA10h
000A83D7 [0042AF67] c3                                           retn
000A83D8 [0042AF68] 8d 42 b9                                     lea     eax, [edx-47h]
000A83DB [0042AF6B] 83 f8 01                                     cmp     eax, 1
000A83DE [0042AF6E] 77 08                                        ja      short near ptr unk_42AF78 ; game-relative-target=0x000A83E8
000A83E0 [0042AF70] 8d 90 b9 0b 00 00                            lea     edx, [eax+0BB9h]
000A83E6 [0042AF76] eb 0e                                        jmp     short near ptr unk_42AF86 ; game-relative-target=0x000A83F6
000A83E8 [0042AF78] 8d 52 90                                     lea     edx, [edx-70h]
000A83EB [0042AF7B] 83 fa 06                                     cmp     edx, 6
000A83EE [0042AF7E] 77 0b                                        ja      short near ptr unk_42AF8B ; game-relative-target=0x000A83FB
000A83F0 [0042AF80] 81 c2 e8 03 00 00                            add     edx, 3E8h
000A83F6 [0042AF86] 68 00 84 0a 00                               push    0A8400h
000A83FB [0042AF8B] c3                                           retn
