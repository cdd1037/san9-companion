; Native test adapters and game continuations for the production presentation hooks.
; Linked only into the test executable; no instruction bytes are built in C++.
.686p
.model flat, C
option casemap:none
.code

PUBLIC PresentationTestReturn, PresentationTestEnterTail, PresentationTestWaitTail
PUBLIC PresentationTestWaitCaller

; Preserve the C ABI while supplying the game's register inputs to a hook.
PresentationTestInvoke PROC uses esi edi, hook:DWORD, object:DWORD, now:DWORD, previous:DWORD, ediValue:DWORD
    mov esi, object
    mov edi, now
    mov eax, now
    mov ecx, previous
    mov edx, previous
    call hook
    mov edx, ediValue
    mov [edx], edi
    ret
PresentationTestInvoke ENDP

; Synthetic cdecl caller of the game's elapsed-time helper.
; The exported return label supplies the caller identity checked by the payload.
PresentationTestInvokeWait PROC uses ebx esi edi, hook:DWORD, now:DWORD, start:DWORD, duration:DWORD
    mov eax, now
    push duration
    push start
    call hook
PresentationTestWaitCaller LABEL BYTE
    add esp, 8
    ret
PresentationTestInvokeWait ENDP

PresentationTestReturn LABEL BYTE
    ret

PresentationTestEnterTail LABEL BYTE
    add esp, 4 ; consume the displaced callback argument
    ret

; Original TC101 53033B..530354 continuation, after the displaced CMP ECX,EAX.
PresentationTestWaitTail LABEL BYTE
    jae wrappedWait
    mov edx, [esp + 8]
    sub eax, ecx
    cmp eax, edx
    sbb eax, eax
    inc eax
    ret
wrappedWait:
    mov edx, [esp + 8]
    add ecx, edx
    cmp eax, ecx
    sbb eax, eax
    inc eax
    ret

END
