#ifndef VECTORPERSONALIZADOCONSTITERATOR_H
#define VECTORPERSONALIZADOCONSTITERATOR_H

#include <vector>

namespace CppMasterClass::Containers
{
template<typename T>
class VectorPersonalizadoConstIterator
{
public:
    using iterator_category = std::random_access_iterator_tag;
    using value_type = T;
    using difference_type = std::ptrdiff_t;
    using pointer = const T*;
    using const_reference = const T&;
    using reference = T&;

    constexpr VectorPersonalizadoConstIterator() noexcept = default;

    constexpr explicit VectorPersonalizadoConstIterator(pointer ptr, size_t offset = 0) noexcept
        : m_ptr(ptr), m_offset(offset) {}

    [[nodiscard]] constexpr const_reference operator*() const noexcept
    {
        return m_ptr[m_offset];
    }

    constexpr VectorPersonalizadoConstIterator& operator++() noexcept
    {
        ++m_offset;
        return *this;
    }

    constexpr VectorPersonalizadoConstIterator operator++(int) noexcept
    {
        VectorPersonalizadoConstIterator temp = *this;
        ++(*this);
        return temp;
    }

    constexpr VectorPersonalizadoConstIterator& operator+=(difference_type offset) noexcept
    {
        m_offset += offset;
        return *this;
    }

    [[nodiscard]] constexpr auto operator<=>(const VectorPersonalizadoConstIterator &other) const noexcept
    {
        return m_offset <=> other.m_offset;
    }

    [[nodiscard]] constexpr bool operator==(const VectorPersonalizadoConstIterator &other) const noexcept
    {
        return m_ptr == other.m_ptr && m_offset == other.m_offset;
    }

    constexpr VectorPersonalizadoConstIterator& operator--() noexcept
    {
        --m_offset;
        return *this;
    }

    constexpr VectorPersonalizadoConstIterator operator--(int) noexcept
    {
        VectorPersonalizadoConstIterator temp = *this;
        --(*this);
        return temp;
    }

    constexpr VectorPersonalizadoConstIterator& operator-=(difference_type offset) noexcept
    {
        m_offset -= offset;
        return *this;
    }

    [[nodiscard]] constexpr pointer operator->() const noexcept
    {
        return m_ptr + m_offset;
    }

    [[nodiscard]] constexpr bool operator!=(const VectorPersonalizadoConstIterator &other) const noexcept
    {
        return !(*this == other);
    }

    [[nodiscard]] constexpr VectorPersonalizadoConstIterator operator+(difference_type offset) const noexcept
    {
        auto temp = *this;
        temp += offset;
        return temp;
    }

    [[nodiscard]] constexpr VectorPersonalizadoConstIterator operator-(difference_type offset) const noexcept
    {
        auto temp = *this;
        temp -= offset;
        return temp;
    }

    [[nodiscard]] constexpr difference_type operator-(const VectorPersonalizadoConstIterator& other) const noexcept
    {
        return m_offset - other.m_offset;
    }

protected:
    pointer m_ptr {nullptr};
    size_t m_offset {0};
};
}

#endif // VECTORPERSONALIZADOCONSTITERATOR_H
