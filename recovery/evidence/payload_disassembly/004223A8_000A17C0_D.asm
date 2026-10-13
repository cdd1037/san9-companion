; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x004223A8; baseline game VA=0x000A17C0; size=13
; Relative branch annotations use the baseline game destination.
000A17C0 [004223A8] c1 e0 02                                     shl     eax, 2
000A17C3 [004223AB] ba 55 55 55 55                               mov     edx, 55555555h
000A17C8 [004223B0] f7 ea                                        imul    edx
000A17CA [004223B2] 8b c2                                        mov     eax, edx
000A17CC [004223B4] c3                                           retn
