; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x00420FD0; baseline game VA=0x004A26CF; size=5
; Relative branch annotations use the baseline game destination.
004A26CF [00420FD0] e8 20 9e fc ff                               call    near ptr 3EADF5h ; game-relative-target=0x0046C4F4
