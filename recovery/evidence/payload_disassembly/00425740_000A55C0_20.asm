; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00425740; baseline game VA=0x000A55C0; size=32
; Relative branch annotations use the baseline game destination.
000A55C0 [00425740] 0f b6 41 04                                  movzx   eax, byte ptr [ecx+4]
000A55C4 [00425744] 83 e8 04                                     sub     eax, 4
000A55C7 [00425747] 85 c0                                        test    eax, eax
000A55C9 [00425749] 7c 12                                        jl      short near ptr unk_42575D ; game-relative-target=0x000A55DD
000A55CB [0042574B] c1 e8 02                                     shr     eax, 2
000A55CE [0042574E] 83 f8 10                                     cmp     eax, 10h
000A55D1 [00425751] 7d 07                                        jge     short near ptr unk_42575A ; game-relative-target=0x000A55DA
000A55D3 [00425753] a8 01                                        test    al, 1
000A55D5 [00425755] 74 03                                        jz      short near ptr unk_42575A ; game-relative-target=0x000A55DA
000A55D7 [00425757] b0 02                                        mov     al, 2
000A55D9 [00425759] c3                                           retn
000A55DA [0042575A] b0 01                                        mov     al, 1
000A55DC [0042575C] c3                                           retn
000A55DD [0042575D] 33 c0                                        xor     eax, eax
000A55DF [0042575F] c3                                           retn
