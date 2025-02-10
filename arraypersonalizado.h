#ifndef ARRAYPERSONALIZADO_H
#define ARRAYPERSONALIZADO_H

#include <array>

using namespace std;


template<typename T, size_t Size>
class ArrayPersonalizado
{
public:
    using value_type = T;
    using size_type = size_t;
    using reference = T&;
    using const_reference = const T&;
    using pointer = T*;

    ArrayPersonalizado() = default;

    [[nodiscard]] constexpr size_type size() const noexcept
    {
        return Size;
    }

    constexpr bool empty() const noexcept
    {
        return Size == 0;
    }

    [[nodiscard]] constexpr reference operator[](size_type pos) noexcept
    {
        return m_elements[pos];
    }

    [[nodiscard]] constexpr const_reference operator[](size_type pos) const noexcept
    {
        return m_elements[pos];
    }

private:
    T m_elements[Size]{};
};

#endif // ARRAYPERSONALIZADO_H
