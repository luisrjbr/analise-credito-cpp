#ifndef ARRAYPERSONALIZADOCONSTITERATOR_H
#define ARRAYPERSONALIZADOCONSTITERATOR_H

#include <list>

namespace CppMasterClass::Containers
{
template<typename T, size_t Size>
class ArrayPersonalizadoConstIterator
{
public:
    using iterator_category = std::contiguous_iterator_tag;
    using value_type = T;
    using difference_type = std::ptrdiff_t;
    using pointer = const T*;
    using const_reference = const T&;
    using reference = T&;

    constexpr ArrayPersonalizadoConstIterator() noexcept = default;

    constexpr explicit ArrayPersonalizadoConstIterator(pointer ptr, size_t offset = 0) noexcept : m_ptr(ptr), m_offset(offset)
    {

    }

    [[nodiscard]] constexpr const_reference operator*() const noexcept
    {
        return m_ptr[m_offset];
    }

    //Pre
    constexpr ArrayPersonalizadoConstIterator& operator++() noexcept
    {
        ++m_offset;
        return *this;
    }

    //Pos
    constexpr ArrayPersonalizadoConstIterator operator++(int) noexcept
    {
        ArrayPersonalizadoConstIterator temp = *this;
        ++(*this);
        return temp;
    }

    constexpr ArrayPersonalizadoConstIterator& operator+=(difference_type offset) noexcept
    {
        m_offset += offset;
        return *this;
    }

    [[nodiscard]] constexpr auto operator<=>(const ArrayPersonalizadoConstIterator &other) const noexcept
    {
        return m_offset <=> other.m_offset;
    }

    [[nodiscard]] constexpr bool operator==(const ArrayPersonalizadoConstIterator &other) const noexcept
    {
        return *this <=> other == 0;
    }

    constexpr ArrayPersonalizadoConstIterator& operator--() noexcept
    {
        --m_offset;
        return *this;
    }

    constexpr ArrayPersonalizadoConstIterator operator--(int) noexcept
    {
        ArrayPersonalizadoConstIterator temp = *this;
        --(*this);
        return temp;
    }

    constexpr ArrayPersonalizadoConstIterator& operator-=(difference_type offset) noexcept
    {
        m_offset -= offset;
        return *this;
    }

    [[nodiscard]] constexpr pointer operator->() const noexcept
    {
        return m_ptr + m_offset;
    }

    [[nodiscard]] constexpr bool operator!=(const ArrayPersonalizadoConstIterator &other) const noexcept
    {
        return !(*this == other);
    }

    [[nodiscard]] constexpr ArrayPersonalizadoConstIterator& operator+(difference_type offset ) const noexcept
    {
        auto temp = *this;
        temp += offset;
        return temp;

    }

    [[nodiscard]] constexpr ArrayPersonalizadoConstIterator& operator-() noexcept
    {
        --m_offset;
        return *this;
    }

    [[nodiscard]] constexpr ArrayPersonalizadoConstIterator operator-(difference_type offset ) const noexcept
    {
        auto temp = *this;
        temp -= offset;
        return temp;
    }

    [[nodiscard]] constexpr difference_type operator-(const ArrayPersonalizadoConstIterator& other ) const noexcept
    {
        return m_offset - other.m_offset;
    }



protected:
    pointer m_ptr {nullptr};
    size_t m_offset{0};
};
}

#endif // ARRAYPERSONALIZADOCONSTITERATOR_H
