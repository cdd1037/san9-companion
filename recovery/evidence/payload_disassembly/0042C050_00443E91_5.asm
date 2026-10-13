; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042C050; baseline game VA=0x00443E91; size=5
; Relative branch annotations use the baseline game destination.
00443E91 [0042C050] 8b 44 24 54                                  mov     eax, [esp+54h]
00443E95 [0042C054] 50                                           push    eax
