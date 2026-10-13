; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042CA48; baseline game VA=0x004A9B8A; size=9
; Relative branch annotations use the baseline game destination.
004A9B8A [0042CA48] 03 f8                                        add     edi, eax
004A9B8C [0042CA4A] 8b ce                                        mov     ecx, esi
004A9B8E [0042CA4C] e8 3d 9a bf ff                               call    near ptr 2648Eh ; game-relative-target=0x000A35D0
