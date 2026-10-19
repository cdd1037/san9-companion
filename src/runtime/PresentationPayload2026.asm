; TC101 presentation hooks. MASM owns instruction encoding and internal branches.
; This entire section is copied as one position-independent block. No external calls,
; relocations, or return addresses into the block survive an entry's execution.
.686p
.model flat, C
option casemap:none
assume fs:nothing
.code

PUBLIC PresentationPayloadBegin, PresentationPayloadEnd
PUBLIC PresentationPeriod, PresentationEnter, PresentationExit, PresentationMotion, PresentationWait
PUBLIC PresentationRedirectBegin, PresentationRedirectEnd, PresentationNop

PresentationPayloadBegin LABEL BYTE
Rate        DWORD 1
Owner       DWORD 0
Map         DWORD 0
Clock       DWORD 0
MapVtable   DWORD 0
Paused      DWORD 0
ClockSlot   DWORD 0
SleepSlot   DWORD 0
PeriodTail  DWORD 0
EnterTail   DWORD 0
ExitTail    DWORD 0
MotionTail  DWORD 0
WaitTail    DWORD 0
WaitCallers DWORD 3 DUP(0)

; Frame: EDI=0 ESI=4 EBP=8 ESP=12 EBX=16 EDX=20 ECX=24 EAX=28 FLAGS=32 TAIL=36.
BeginHook MACRO
    LOCAL anchor
    push 0
    pushfd
    pushad
    call anchor
anchor:
    pop ebp
    sub ebp, anchor - PresentationPayloadBegin
ENDM

FinishHook MACRO target
    mov eax, [ebp + (target - PresentationPayloadBegin)]
    mov [esp + 36], eax
    popad
    popfd
    ret
ENDM

; EDX must be a live object; returns effective rate in EAX, clobbers flags.
MapRate MACRO
    LOCAL done
    mov eax, 1
    test edx, edx
    jz done
    mov ecx, [ebp + (MapVtable - PresentationPayloadBegin)]
    cmp [edx], ecx
    jne done
    cmp DWORD PTR [edx + 134h], 0 ; presentation queue running
    je done
    cmp DWORD PTR [edx + 294h], 0 ; mainmap visual updates enabled
    je done
    mov ecx, [ebp + (Paused - PresentationPayloadBegin)]
    cmp DWORD PTR [ecx], 0
    jne done
    mov ecx, [ebp + (ClockSlot - PresentationPayloadBegin)]
    mov ecx, [ecx]
    cmp ecx, [ebp + (Clock - PresentationPayloadBegin)]
    jne done
    mov eax, [ebp + (Rate - PresentationPayloadBegin)]
done:
ENDM

ScopedRate MACRO
    LOCAL other, done
    mov eax, fs:[24h] ; current thread ID; no API call
    cmp eax, [ebp + (Owner - PresentationPayloadBegin)]
    jne other
    mov edx, [ebp + (Map - PresentationPayloadBegin)]
    MapRate
    jmp done
other:
    mov eax, 1
done:
ENDM

MultiplyElapsed MACRO
    LOCAL fits
    mul ecx
    test edx, edx
    jz fits
    mov eax, 0FFFFFFFFh ; saturate long gaps rather than overflowing
fits:
ENDM

PresentationPeriod LABEL BYTE
    BeginHook
    mov edx, esi
    MapRate
    mov ecx, eax
    mov eax, [esi + 0E8h]
    xor edx, edx
    div ecx
    test eax, eax
    jnz nonzeroPeriod
    inc eax
nonzeroPeriod:
    mov [esp], eax ; displaced MOV EDI,[ESI+E8], with a scaled local period
    FinishHook PeriodTail

PresentationEnter LABEL BYTE
    push ebx ; displaced callback argument, consumed by the original virtual call
    BeginHook
    mov eax, fs:[24h]
    mov [ebp + (Owner - PresentationPayloadBegin)], eax
    mov [ebp + (Map - PresentationPayloadBegin)], esi
    mov eax, [esi]
    mov [esp + 20], eax ; displaced MOV EDX,[ESI]
    mov [esp + 24], esi ; displaced MOV ECX,ESI
    FinishHook EnterTail

PresentationExit LABEL BYTE
    push 1 ; original SleepEx alertable argument
    push 0 ; original SleepEx delay
    push 0 ; original game return address, filled below
    BeginHook
    mov DWORD PTR [ebp + (Owner - PresentationPayloadBegin)], 0
    mov DWORD PTR [ebp + (Map - PresentationPayloadBegin)], 0
    mov eax, [ebp + (ExitTail - PresentationPayloadBegin)]
    mov [esp + 40], eax
    mov eax, [ebp + (SleepSlot - PresentationPayloadBegin)]
    mov eax, [eax]
    mov [esp + 36], eax
    popad
    popfd
    ret ; tail transfer to SleepEx; its return address is in the original game

PresentationMotion LABEL BYTE
    BeginHook
    ScopedRate
    mov ecx, eax
    mov eax, edi
    sub eax, [esp + 24] ; real now - real previous timestamp
    MultiplyElapsed
    mov [esp + 28], eax
    mov eax, [esi + 30h]
    mov [esp + 24], eax ; displaced MOV ECX,[ESI+30]
    FinishHook MotionTail

PresentationWait LABEL BYTE
    BeginHook
    mov eax, [esp + 40] ; original cdecl caller
    cmp eax, [ebp + (WaitCallers - PresentationPayloadBegin)]
    je mapWait
    cmp eax, [ebp + (WaitCallers + 4 - PresentationPayloadBegin)]
    je mapWait
    cmp eax, [ebp + (WaitCallers + 8 - PresentationPayloadBegin)]
    jne originalWait
mapWait:
    ScopedRate
    cmp eax, 1
    jbe originalWait
    mov ecx, eax
    mov eax, [esp + 28]
    sub eax, [esp + 44] ; real now - start
    MultiplyElapsed
    cmp eax, [esp + 48] ; requested duration
    setae al
    movzx eax, al
    mov [esp + 28], eax
    popad
    popfd
    lea esp, [esp + 4] ; discard reserved continuation
    ret ; return directly to original cdecl caller; it owns argument cleanup
originalWait:
    mov ecx, [esp + 44]
    mov [esp + 24], ecx
    mov eax, [esp + 28]
    cmp ecx, eax
    pushfd
    pop eax
    mov [esp + 32], eax ; preserve displaced CMP flags across register restoration
    FinishHook WaitTail

PresentationPayloadEnd LABEL BYTE

; Entry patch templates are assembled here; C++ fills only the relative destination.
PresentationRedirectBegin LABEL BYTE
    jmp NEAR PTR PresentationRedirectEnd
PresentationRedirectEnd LABEL BYTE
PresentationNop LABEL BYTE
    nop
END
