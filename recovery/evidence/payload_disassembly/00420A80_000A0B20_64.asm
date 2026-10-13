; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00420A80; baseline game VA=0x000A0B20; size=100
; Relative branch annotations use the baseline game destination.
000A0B20 [00420A80] 51                                           push    ecx
000A0B21 [00420A81] 80 7e 06 04                                  cmp     byte ptr [esi+6], 4
000A0B25 [00420A85] 75 56                                        jnz     short near ptr unk_420ADD ; game-relative-target=0x000A0B7D
000A0B27 [00420A87] 8b 86 8c 00 00 00                            mov     eax, [esi+8Ch]
000A0B2D [00420A8D] d1 e8                                        shr     eax, 1
000A0B2F [00420A8F] 03 86 88 00 00 00                            add     eax, [esi+88h]
000A0B35 [00420A95] 3d a0 0f 00 00                               cmp     eax, 0FA0h
000A0B3A [00420A9A] 7d 41                                        jge     short near ptr unk_420ADD ; game-relative-target=0x000A0B7D
000A0B3C [00420A9C] 80 be e8 00 00 00 00                         cmp     byte ptr [esi+0E8h], 0
000A0B43 [00420AA3] 74 38                                        jz      short near ptr unk_420ADD ; game-relative-target=0x000A0B7D
000A0B45 [00420AA5] 8b 86 cc 00 00 00                            mov     eax, [esi+0CCh]
000A0B4B [00420AAB] 39 05 64 fa 43 00                            cmp     ds:43FA64h, eax
000A0B51 [00420AB1] 74 2a                                        jz      short near ptr unk_420ADD ; game-relative-target=0x000A0B7D
000A0B53 [00420AB3] a3 64 fa 43 00                               mov     ds:43FA64h, eax
000A0B58 [00420AB8] 89 35 68 fa 43 00                            mov     ds:43FA68h, esi
000A0B5E [00420ABE] 33 d2                                        xor     edx, edx
000A0B60 [00420AC0] 89 54 24 08                                  mov     [esp+8], edx
000A0B64 [00420AC4] 8d 48 78                                     lea     ecx, [eax+78h]
000A0B67 [00420AC7] 51                                           push    ecx
000A0B68 [00420AC8] 8b 96 d0 00 00 00                            mov     edx, [esi+0D0h]
000A0B6E [00420ACE] 52                                           push    edx
000A0B6F [00420ACF] b8 70 fc 43 00                               mov     eax, 43FC70h
000A0B74 [00420AD4] ff d0                                        call    eax
000A0B76 [00420AD6] 83 c4 08                                     add     esp, 8
000A0B79 [00420AD9] c6 40 0c c8                                  mov     byte ptr [eax+0Ch], 0C8h
000A0B7D [00420ADD] 59                                           pop     ecx
000A0B7E [00420ADE] 68 30 da 4f 00                               push    4FDA30h
000A0B83 [00420AE3] c3                                           retn
