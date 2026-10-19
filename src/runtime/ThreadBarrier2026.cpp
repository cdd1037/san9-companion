#include "ThreadBarrier2026.h"
#include <algorithm>

RuntimeFailure2026 ThreadBarrier2026::resume() {
    complete_=false;
    RuntimeFailure2026 failure;
    for (auto it=threads_.begin(); it!=threads_.end();) {
        if (it->suspended) {
            if (api_.resumeThread(it->handle)==MAXDWORD) {
                const DWORD error=GetLastError();
                if (api_.wait(it->handle,0)!=WAIT_OBJECT_0) {
                    if (!failure) failure={RuntimeOperation2026::ResumeThreads,it->id,0,0,error};
                    ++it; continue;
                }
            }
            it->suspended=false;
        }
        if (!api_.closeHandle(it->handle)) {
            if (!failure) failure={RuntimeOperation2026::ResumeThreads,it->id,0,0,GetLastError()};
            ++it; continue;
        }
        it=threads_.erase(it);
    }
    return failure;
}
RuntimeFailure2026 ThreadBarrier2026::pause(DWORD pid, const std::vector<ExecutionRange2026>& ranges) {
    if (complete_) return {};
    if (auto failure=resume()) return failure;
    // Repeat the inventory after suspension: threads created during the first snapshot must also stop.
    for (unsigned pass=0;pass<4;++pass) {
        HANDLE snapshot=api_.snapshot(TH32CS_SNAPTHREAD,0);
        if (snapshot==INVALID_HANDLE_VALUE)
            return {RuntimeOperation2026::PauseThreads,0,0,0,GetLastError()};
        THREADENTRY32 entry{}; entry.dwSize=sizeof(entry);
        BOOL next=api_.threadFirst(snapshot,&entry);
        DWORD error=next?0:GetLastError();
        bool added=false;
        RuntimeFailure2026 failure;
        while (next) {
            if (entry.th32OwnerProcessID==pid && std::none_of(threads_.begin(),threads_.end(),
                    [&](const Thread& thread){return thread.id==entry.th32ThreadID;})) {
                HANDLE thread=api_.openThread(THREAD_SUSPEND_RESUME|THREAD_GET_CONTEXT|THREAD_QUERY_INFORMATION,
                                             FALSE,entry.th32ThreadID);
                if (!thread) { failure={RuntimeOperation2026::PauseThreads,entry.th32ThreadID,0,0,GetLastError()}; break; }
                // Register ownership before suspending, including allocation failure safety.
                try { threads_.push_back({entry.th32ThreadID,thread,false}); }
                catch (...) { api_.closeHandle(thread); api_.closeHandle(snapshot); throw; }
                if (api_.suspendThread(thread)==MAXDWORD) {
                    failure={RuntimeOperation2026::PauseThreads,entry.th32ThreadID,0,0,GetLastError()}; break;
                }
                threads_.back().suspended=true; added=true;
                CONTEXT context{}; context.ContextFlags=CONTEXT_CONTROL;
                if (!api_.threadContext(thread,&context)) {
                    failure={RuntimeOperation2026::PauseThreads,entry.th32ThreadID,0,0,GetLastError()}; break;
                }
                for (const auto& range:ranges) {
                    if (context.Eip>=range.address && context.Eip-range.address<range.size) {
                        failure={RuntimeOperation2026::SpeedBusy,context.Eip,range.size,0,0}; break;
                    }
                }
                if (failure) break;
            }
            next=api_.threadNext(snapshot,&entry);
            if (!next) error=GetLastError();
        }
        if (!api_.closeHandle(snapshot) && !failure)
            failure={RuntimeOperation2026::PauseThreads,0,0,0,GetLastError()};
        if (failure) return failure;
        if (error!=ERROR_NO_MORE_FILES) return {RuntimeOperation2026::PauseThreads,0,0,0,error};
        if (!added) {
            if (threads_.empty()) return {RuntimeOperation2026::PauseThreads,0,0,0,ERROR_NOT_FOUND};
            complete_=true;
            return {};
        }
    }
    return {RuntimeOperation2026::SpeedBusy};
}
RuntimeFailure2026 ThreadBarrier2026::validateClock(DWORD pid, DWORD clock) {
    HANDLE snapshot=api_.snapshot(TH32CS_SNAPMODULE,pid);
    if (snapshot==INVALID_HANDLE_VALUE) return {RuntimeOperation2026::ValidateSpeed,clock,0,0,GetLastError()};
    MODULEENTRY32W entry{}; entry.dwSize=sizeof(entry);
    BOOL next=api_.moduleFirst(snapshot,&entry);
    bool valid=false;
    while (next) {
        const auto start=reinterpret_cast<DWORD>(entry.modBaseAddr);
        if (clock>=start && clock-start<entry.modBaseSize && _wcsicmp(entry.szModule,L"winmm.dll")==0) {
            valid=true; break;
        }
        next=api_.moduleNext(snapshot,&entry);
    }
    const DWORD error=valid?0:ERROR_INVALID_ADDRESS;
    if (!api_.closeHandle(snapshot)) return {RuntimeOperation2026::ValidateSpeed,clock,0,0,GetLastError()};
    return valid?RuntimeFailure2026{}:RuntimeFailure2026{RuntimeOperation2026::ValidateSpeed,clock,0,0,error};
}
