; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00429190; baseline game VA=0x000A7C10; size=16
; Relative branch annotations use the baseline game destination.
000A7C10 [00429190] 83 f8 17                                     cmp     eax, 17h
000A7C13 [00429193] 74 06                                        jz      short near ptr unk_42919B ; game-relative-target=0x000A7C1B
000A7C15 [00429195] 83 f8 15                                     cmp     eax, 15h
000A7C18 [00429198] 74 01                                        jz      short near ptr unk_42919B ; game-relative-target=0x000A7C1B
000A7C1A [0042919A] c3                                           retn
000A7C1B [0042919B] 80 04 24 04                                  add     byte ptr [esp], 4
000A7C1F [0042919F] c3                                           retn
