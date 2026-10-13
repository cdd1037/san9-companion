; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042B1C8; baseline game VA=0x000A9200; size=158
; Relative branch annotations use the baseline game destination.
000A9200 [0042B1C8] 00    db 0x00
000A9201 [0042B1C9] 00    db 0x00
000A9202 [0042B1CA] 00    db 0x00
000A9203 [0042B1CB] 00 20                                        add     [eax], ah
000A9205 [0042B1CD] 00    db 0x00
000A9206 [0042B1CE] 00    db 0x00
000A9207 [0042B1CF] 00 41 53                                     add     [ecx+53h], al
000A920A [0042B1D2] 44                                           inc     esp
000A920B [0042B1D3] 51                                           push    ecx
000A920C [0042B1D4] 57                                           push    edi
000A920D [0042B1D5] 45                                           inc     ebp
000A920E [0042B1D6] 52                                           push    edx
000A920F [0042B1D7] 54                                           push    esp
000A9210 [0042B1D8] 59                                           pop     ecx
000A9211 [0042B1D9] 55                                           push    ebp
000A9212 [0042B1DA] 49                                           dec     ecx
000A9213 [0042B1DB] 46                                           inc     esi
000A9214 [0042B1DC] 47                                           inc     edi
000A9215 [0042B1DD] 48                                           dec     eax
000A9216 [0042B1DE] 4a                                           dec     edx
000A9217 [0042B1DF] 39 30                                        cmp     [eax], esi
000A9219 [0042B1E1] 6f                                           outsd
000A921A [0042B1E2] 50                                           push    eax
000A921B [0042B1E3] 58                                           pop     eax
000A921C [0042B1E4] 43                                           inc     ebx
000A921D [0042B1E5] 56                                           push    esi
000A921E [0042B1E6] 42                                           inc     edx
000A921F [0042B1E7] 4e                                           dec     esi
000A9220 [0042B1E8] 4d                                           dec     ebp
000A9221 [0042B1E9] 4b                                           dec     ebx
000A9222 [0042B1EA] 4c                                           dec     esp
000A9223 [0042B1EB] 90                                           nop
000A9224 [0042B1EC] 57                                           push    edi
000A9225 [0042B1ED] bf 00 92 0a 00                               mov     edi, 0A9200h
000A922A [0042B1F2] 89 17                                        mov     [edi], edx
000A922C [0042B1F4] 49                                           dec     ecx
000A922D [0042B1F5] 7d 05                                        jge     short near ptr unk_42B1FC ; game-relative-target=0x000A9234
000A922F [0042B1F7] 83 c0 31                                     add     eax, 31h ; '1'
000A9232 [0042B1FA] eb 15                                        jmp     short near ptr unk_42B211 ; game-relative-target=0x000A9249
000A9234 [0042B1FC] 6b c9 06                                     imul    ecx, 6
000A9237 [0042B1FF] ba c0 70 3c 13                               mov     edx, 133C70C0h
000A923C [0042B204] d3 ea                                        shr     edx, cl
000A923E [0042B206] 83 e2 1f                                     and     edx, 1Fh
000A9241 [0042B209] 03 c2                                        add     eax, edx
000A9243 [0042B20B] 8a 80 08 92 0a 00                            mov     al, [eax+0A9208h]
000A9249 [0042B211] 88 47 05                                     mov     [edi+5], al
000A924C [0042B214] c6 47 06 00                                  mov     byte ptr [edi+6], 0
000A9250 [0042B218] 8b c7                                        mov     eax, edi
000A9252 [0042B21A] 5f                                           pop     edi
000A9253 [0042B21B] c3                                           retn
000A9254 [0042B21C] 81 3b 38 a2 60 00                            cmp     dword ptr [ebx], 60A238h
000A925A [0042B222] 75 14                                        jnz     short near ptr unk_42B238 ; game-relative-target=0x000A9270
000A925C [0042B224] 8b 11                                        mov     edx, [ecx]
000A925E [0042B226] 8b c5                                        mov     eax, ebp
000A9260 [0042B228] 8b 8c 24 9c 00 00 00                         mov     ecx, [esp+9Ch]
000A9267 [0042B22F] e8 b8 ff ff ff                               call    near ptr unk_42B1EC ; game-relative-target=0x000A9224
000A926C [0042B234] 89 44 24 08                                  mov     [esp+8], eax
000A9270 [0042B238] 68 60 85 42 00                               push    428560h
000A9275 [0042B23D] c3                                           retn
000A9276 [0042B23E] 81 3b 38 a2 60 00                            cmp     dword ptr [ebx], 60A238h
000A927C [0042B244] 75 1a                                        jnz     short near ptr unk_42B260 ; game-relative-target=0x000A9298
000A927E [0042B246] 8b 10                                        mov     edx, [eax]
000A9280 [0042B248] 8b c6                                        mov     eax, esi
000A9282 [0042B24A] 2d e9 07 00 00                               sub     eax, 7E9h
000A9287 [0042B24F] 8b 8b b8 01 00 00                            mov     ecx, [ebx+1B8h]
000A928D [0042B255] e8 92 ff ff ff                               call    near ptr unk_42B1EC ; game-relative-target=0x000A9224
000A9292 [0042B25A] 89 44 24 04                                  mov     [esp+4], eax
000A9296 [0042B25E] 8b cd                                        mov     ecx, ebp
000A9298 [0042B260] 68 70 8c 42 00                               push    428C70h
000A929D [0042B265] c3                                           retn
