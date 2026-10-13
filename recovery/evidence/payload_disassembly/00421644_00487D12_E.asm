; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00421644; baseline game VA=0x00487D12; size=14
; Relative branch annotations use the baseline game destination.
00487D12 [00421644] c7 44 24 04 38 eb 4f 01                      mov     dword ptr [esp+4], 14FEB38h
00487D1A [0042164C] 68 00 0d 46 00                               push    460D00h
00487D1F [00421651] c3                                           retn
