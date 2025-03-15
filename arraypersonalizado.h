#ifndef ARRAYPERSONALIZADO_H
#define ARRAYPERSONALIZADO_H

#include <array>
#include "arraypersonalizadoconstiterator.h"
#include "arraypersonalizadoiterator.h"


namespace CppMasterClass::Containers
{
template<typename T, size_t Size>
class ArrayPersonalizado
{
public:
    using value_type = T;
    using size_type = size_t;
    using reference = T&;
    using const_reference = const T&;
    using pointer = T*;
    using const_iterator = ArrayPersonalizadoConstIterator<T, Size>;
    using iterator = ArrayPersonalizadoIterator<T, Size>;

    ArrayPersonalizado() = default;

    template<typename... Values>
    constexpr ArrayPersonalizado(Values... values)
    {
        static_assert(sizeof...(Values) <= Size, "Too many initializers");
        static_assert((std::is_constructible_v<Values, T> && ...), "All values must be T");
        const std::array<T, sizeof...(Values)> temp = {values...};
        std::copy(temp.begin(), temp.end(), m_elements);
    }

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

    const_iterator begin() const noexcept
    {
        return const_iterator(m_elements);
    }

    const_iterator end() const noexcept
    {
        return const_iterator(m_elements, Size);
    }

    iterator begin() noexcept
    {
        return iterator(m_elements);
    }

    iterator end() noexcept
    {
        return iterator(m_elements, Size);
    }


private:
    T m_elements[Size]{};
};
}

#endif // ARRAYPERSONALIZADO_H
