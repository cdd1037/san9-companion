; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00424400; baseline game VA=0x004BC361; size=7
; Relative branch annotations use the baseline game destination.
004BC361 [00424400] ff 52 10                                     call    dword ptr [edx+10h]
004BC364 [00424403] 85 c0                                        test    eax, eax
004BC366 [00424405] 74 14                                        jz      short near ptr dword_424418+3 ; game-relative-target=0x004BC37C
