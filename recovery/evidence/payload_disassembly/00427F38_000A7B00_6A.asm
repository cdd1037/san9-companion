; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00427F38; baseline game VA=0x000A7B00; size=106
; Relative branch annotations use the baseline game destination.
000A7B00 [00427F38] 8b 73 74                                     mov     esi, [ebx+74h]
000A7B03 [00427F3B] 8b ce                                        mov     ecx, esi
000A7B05 [00427F3D] b8 20 f7 43 00                               mov     eax, 43F720h
000A7B0A [00427F42] ff d0                                        call    eax
000A7B0C [00427F44] 85 c0                                        test    eax, eax
000A7B0E [00427F46] 7e 1e                                        jle     short near ptr unk_427F66 ; game-relative-target=0x000A7B2E
000A7B10 [00427F48] 80 3d 1c ff 43 00 00                         cmp     byte ptr ds:43FF1Ch, 0
000A7B17 [00427F4F] 74 15                                        jz      short near ptr unk_427F66 ; game-relative-target=0x000A7B2E
000A7B19 [00427F51] f6 47 34 01                                  test    byte ptr [edi+34h], 1
000A7B1D [00427F55] 74 0f                                        jz      short near ptr unk_427F66 ; game-relative-target=0x000A7B2E
000A7B1F [00427F57] f6 43 20 01                                  test    byte ptr [ebx+20h], 1
000A7B23 [00427F5B] 74 09                                        jz      short near ptr unk_427F66 ; game-relative-target=0x000A7B2E
000A7B25 [00427F5D] 8b 4b 64                                     mov     ecx, [ebx+64h]
000A7B28 [00427F60] 80 79 06 05                                  cmp     byte ptr [ecx+6], 5
000A7B2C [00427F64] 74 01                                        jz      short near ptr unk_427F67 ; game-relative-target=0x000A7B2F
000A7B2E [00427F66] c3                                           retn
000A7B2F [00427F67] 50                                           push    eax
000A7B30 [00427F68] 8b cf                                        mov     ecx, edi
000A7B32 [00427F6A] b8 b0 4e 0a 00                               mov     eax, 0A4EB0h
000A7B37 [00427F6F] ff d0                                        call    eax
000A7B39 [00427F71] 59                                           pop     ecx
000A7B3A [00427F72] c1 e8 0e                                     shr     eax, 0Eh
000A7B3D [00427F75] 83 f8 7f                                     cmp     eax, 7Fh
000A7B40 [00427F78] 7e 05                                        jle     short near ptr unk_427F7F ; game-relative-target=0x000A7B47
000A7B42 [00427F7A] c1 e1 02                                     shl     ecx, 2
000A7B45 [00427F7D] eb 20                                        jmp     short near ptr unk_427F9F ; game-relative-target=0x000A7B67
000A7B47 [00427F7F] 8b d1                                        mov     edx, ecx
000A7B49 [00427F81] 3a 05 c6 64 0a 00                            cmp     al, ds:0A64C6h
000A7B4F [00427F87] 7c 16                                        jl      short near ptr unk_427F9F ; game-relative-target=0x000A7B67
000A7B51 [00427F89] 03 ca                                        add     ecx, edx
000A7B53 [00427F8B] 3a 05 c7 64 0a 00                            cmp     al, ds:0A64C7h
000A7B59 [00427F91] 7c 0c                                        jl      short near ptr unk_427F9F ; game-relative-target=0x000A7B67
000A7B5B [00427F93] 03 ca                                        add     ecx, edx
000A7B5D [00427F95] 3a 05 c8 64 0a 00                            cmp     al, ds:0A64C8h
000A7B63 [00427F9B] 7c 02                                        jl      short near ptr unk_427F9F ; game-relative-target=0x000A7B67
000A7B65 [00427F9D] 03 ca                                        add     ecx, edx
000A7B67 [00427F9F] 8b c1                                        mov     eax, ecx
000A7B69 [00427FA1] c3                                           retn
