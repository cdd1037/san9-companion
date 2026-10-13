; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042B598; baseline game VA=0x004B4C88; size=23
; Relative branch annotations use the baseline game destination.
004B4C88 [0042B598] 8b 42 0c                                     mov     eax, [edx+0Ch]
004B4C8B [0042B59B] 33 c9                                        xor     ecx, ecx
004B4C8D [0042B59D] 85 c0                                        test    eax, eax
004B4C8F [0042B59F] 0f 9f c1                                     setnle  cl
004B4C92 [0042B5A2] c7 84 24 34 04 00 00 ff ff ff ff             mov     dword ptr [esp+434h], 0FFFFFFFFh
004B4C9D [0042B5AD] 8b f1                                        mov     esi, ecx
