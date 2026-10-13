; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042B4EC; baseline game VA=0x004FA228; size=14
; Relative branch annotations use the baseline game destination.
004FA228 [0042B4EC] 8b 06                                        mov     eax, [esi]
004FA22A [0042B4EE] 8b ce                                        mov     ecx, esi
004FA22C [0042B4F0] c7 86 84 06 00 00 00 00 00 00                mov     dword ptr [esi+684h], 0
