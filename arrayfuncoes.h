#ifndef ARRAYFUNCOES_H
#define ARRAYFUNCOES_H

#include <expected>
#include <string>
#include <array>

class ArrayFuncoes
{
public:
    ArrayFuncoes();

    template<typename T>
    constexpr std::expected<typename T::value_type, std::string> max_element(const T &arr) noexcept
    {
        if(arr.empty())
            return std::unexpected("Array is empty");

        auto greatElement = arr[0];

        for(size_t i; i < arr.size(); ++i)
        {
            if(arr[i] > greatElement)
                greatElement = arr[i];
        }

        return greatElement;
    }
};

#endif // ARRAYFUNCOES_H
