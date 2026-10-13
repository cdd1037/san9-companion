; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00425600; baseline game VA=0x004B12F2; size=5
; Relative branch annotations use the baseline game destination.
004B12F2 [00425600] e8 b9 40 bf ff                               call    near ptr 196BEh ; game-relative-target=0x000A53B0
