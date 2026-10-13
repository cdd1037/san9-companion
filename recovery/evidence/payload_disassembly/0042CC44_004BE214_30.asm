; Linear x86 decode of an injected byte-buffer candidate.
; May contain data, partial instructions, or multiple entrypoints.
; Not a verified function boundary or an assemblable source file.
; Source companion VA=0x0042CC44; baseline game VA=0x004BE214; size=48
; Relative branch annotations use the baseline game destination.
004BE214 [0042CC44] 56                                           push    esi
004BE215 [0042CC45] 8b 30                                        mov     esi, [eax]
004BE217 [0042CC47] 85 f6                                        test    esi, esi
004BE219 [0042CC49] 57                                           push    edi
004BE21A [0042CC4A] 74 1b                                        jz      short near ptr unk_42CC67 ; game-relative-target=0x004BE237
004BE21C [0042CC4C] 8b 16                                        mov     edx, [esi]
004BE21E [0042CC4E] 8b ce                                        mov     ecx, esi
004BE220 [0042CC50] ff 52 10                                     call    dword ptr [edx+10h]
004BE223 [0042CC53] 85 c0                                        test    eax, eax
004BE225 [0042CC55] 74 10                                        jz      short near ptr unk_42CC67 ; game-relative-target=0x004BE237
004BE227 [0042CC57] 68 2c 5c 60 00                               push    605C2Ch
004BE22C [0042CC5C] 8b ce                                        mov     ecx, esi
004BE22E [0042CC5E] e8 2d 0b 12 00                               call    near ptr 54D790h ; game-relative-target=0x005DED60
004BE233 [0042CC63] 85 c0                                        test    eax, eax
004BE235 [0042CC65] 75 02                                        jnz     short near ptr unk_42CC69 ; game-relative-target=0x004BE239
004BE237 [0042CC67] 33 f6                                        xor     esi, esi
004BE239 [0042CC69] 8b ce                                        mov     ecx, esi
004BE23B [0042CC6B] e8 b0 15 f8 ff                               call    near ptr 3AE220h ; game-relative-target=0x0043F7F0
004BE240 [0042CC70] 8b ce                                        mov     ecx, esi
004BE242 [0042CC72] 8b f8                                        mov     edi, eax
