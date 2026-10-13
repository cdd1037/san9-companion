#pragma once
#include "../platform/NativeWidgets.h"
#include <functional>
namespace ui
{
struct NumberBinding
{
    int id, minimum, maximum;
    std::function<int()> get;
    std::function<void(int)> set;
};
template <class T> NumberBinding bind(int id, int minimum, int maximum, T &value)
{
    return {id, minimum, maximum, [&value] { return int(value); },
            [&value](int input) { value = static_cast<T>(input); }};
}
inline void loadNumbers(Dialog &view, const std::vector<NumberBinding> &fields)
{
    for (const auto &field : fields)
        view.number(field.id, field.get());
}
inline bool saveNumbers(Dialog &view, const std::vector<NumberBinding> &fields)
{
    std::vector<int> values;
    for (const auto &field : fields)
    {
        int value = 0;
        if (!view.number(field.id, field.minimum, field.maximum, value))
            return false;
        values.push_back(value);
    }
    for (size_t i = 0; i < fields.size(); ++i)
        fields[i].set(values[i]);
    return true;
}
} // namespace ui
