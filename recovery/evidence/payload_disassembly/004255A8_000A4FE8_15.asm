; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004255A8; baseline game VA=0x000A4FE8; size=21
; Relative branch annotations use the baseline game destination.
000A4FE8 [004255A8] c7 46 02 53 61 76 30                         mov     dword ptr [esi+2], 30766153h
000A4FEF [004255AF] c6 46 06 33                                  mov     byte ptr [esi+6], 33h ; '3'
000A4FF3 [004255B3] 80 46 07 05                                  add     byte ptr [esi+7], 5
000A4FF7 [004255B7] 68 40 46 45 00                               push    454640h
000A4FFC [004255BC] c3                                           retn
