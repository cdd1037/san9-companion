; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00429050; baseline game VA=0x000A7B70; size=45
; Relative branch annotations use the baseline game destination.
000A7B70 [00429050] 8b 87 90 00 00 00                            mov     eax, [edi+90h]
000A7B76 [00429056] 8b d0                                        mov     edx, eax
000A7B78 [00429058] f6 47 20 01                                  test    byte ptr [edi+20h], 1
000A7B7C [0042905C] 74 18                                        jz      short near ptr unk_429076 ; game-relative-target=0x000A7B96
000A7B7E [0042905E] 50                                           push    eax
000A7B7F [0042905F] 0f b6 0d 1d ff 43 00                         movzx   ecx, byte ptr ds:43FF1Dh
000A7B86 [00429066] f7 e9                                        imul    ecx
000A7B88 [00429068] b1 0a                                        mov     cl, 0Ah
000A7B8A [0042906A] f7 f9                                        idiv    ecx
000A7B8C [0042906C] 85 d2                                        test    edx, edx
000A7B8E [0042906E] 74 01                                        jz      short near ptr unk_429071 ; game-relative-target=0x000A7B91
000A7B90 [00429070] 40                                           inc     eax
000A7B91 [00429071] 8b d0                                        mov     edx, eax
000A7B93 [00429073] 58                                           pop     eax
000A7B94 [00429074] 8b cf                                        mov     ecx, edi
000A7B96 [00429076] 89 15 d2 f3 43 00                            mov     ds:43F3D2h, edx
000A7B9C [0042907C] c3                                           retn
