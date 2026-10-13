#pragma once
#include <Windows.h>
#include <vector>
#include <cstdint>
#include <cstddef>

enum class ChangeKind2026 { Handle, Allocation, Protection, Bytes };
struct Change2026 {
    ChangeKind2026 kind;
    HANDLE process = nullptr;
    LPVOID address = nullptr;
    SIZE_T size = 0;
    DWORD protection = 0;
    std::vector<BYTE> before;
    SIZE_T transferred = 0;
    bool completed = false;
};
// Successful operations retain only first-observed bytes within each resource epoch.
// Build a new journal so allocation failure never damages the rollback history.
std::vector<Change2026> compactCommittedChanges2026(const std::vector<Change2026>& changes);
// Owns the history and operation boundary; mutable records stay inside the core.
class ChangeJournal2026 final {
public:
    const std::vector<Change2026>& entries() const { return entries_; }
    size_t size() const { return entries_.size(); }
    bool empty() const { return entries_.empty(); }
    size_t boundary() const { return boundary_; }
    Change2026& append(Change2026 entry);
    Change2026& last() { return entries_.back(); }
    void discardLast() { entries_.pop_back(); }
    void begin() { boundary_ = entries_.size(); }
    void commit();
    void restoreAll() { boundary_ = 0; }
    void clear() { entries_.clear(); boundary_ = 0; }
private:
    std::vector<Change2026> entries_;
    size_t boundary_ = 0;
};
