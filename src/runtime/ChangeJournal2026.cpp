#include "ChangeJournal2026.h"
#include <algorithm>
#include <map>
#include <limits>
#include <stdexcept>

std::vector<Change2026> compactCommittedChanges2026(const std::vector<Change2026>& changes) {
    std::vector<Change2026> result;
    std::map<std::uintptr_t, std::uintptr_t> covered;
    HANDLE process = nullptr;
    for (const auto& entry : changes) {
        if (!entry.completed) throw std::logic_error("cannot compact an unfinished operation");
        if (entry.kind != ChangeKind2026::Bytes) {
            result.push_back(entry);
            // Never move restoration across protection, allocation or handle ownership.
            covered.clear();
            process = nullptr;
            continue;
        }
        if (entry.process != process) { covered.clear(); process = entry.process; }
        const auto begin = reinterpret_cast<std::uintptr_t>(entry.address);
        if (entry.size > (std::numeric_limits<std::uintptr_t>::max)() - begin
            || entry.before.size() != entry.size)
            throw std::logic_error("invalid journal byte range");
        const std::uintptr_t end = begin + static_cast<std::uintptr_t>(entry.size);
        auto cursor = begin;
        auto range = covered.lower_bound(begin);
        if (range != covered.begin() && std::prev(range)->second >= begin) --range;
        auto append = [&](std::uintptr_t first, std::uintptr_t last) {
            if (first == last) return;
            Change2026 retained{ChangeKind2026::Bytes, entry.process,
                reinterpret_cast<LPVOID>(first), last-first};
            retained.before.assign(entry.before.begin() + (first-begin), entry.before.begin() + (last-begin));
            retained.transferred = retained.size;
            retained.completed = true;
            result.push_back(std::move(retained));
        };
        auto mergedBegin = begin;
        auto mergedEnd = end;
        while (range != covered.end() && range->first <= mergedEnd) {
            const auto gapEnd = (std::min)(end, range->first);
            if (cursor < gapEnd) append(cursor, gapEnd);
            cursor = (std::max)(cursor, range->second);
            mergedBegin = (std::min)(mergedBegin, range->first);
            mergedEnd = (std::max)(mergedEnd, range->second);
            range = covered.erase(range);
        }
        if (cursor < end) append(cursor, end);
        covered.emplace(mergedBegin, mergedEnd);
    }
    return result;
}

Change2026& ChangeJournal2026::append(Change2026 entry) {
    entries_.push_back(std::move(entry));
    return entries_.back();
}
void ChangeJournal2026::commit() {
    if (entries_.size() != boundary_) {
        auto committed = compactCommittedChanges2026(entries_);
        entries_.swap(committed);
    }
    boundary_ = entries_.size();
}
