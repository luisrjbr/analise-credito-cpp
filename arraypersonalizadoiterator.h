#ifndef ARRAYPERSONALIZADOITERATOR_H
#define ARRAYPERSONALIZADOITERATOR_H

#include "arraypersonalizadoconstiterator.h"

namespace CppMasterClass::ArraysPersonalizados
{
template <typename T, size_t Size>
class ArrayPersonalizadoIterator : public ArrayPersonalizadoConstIterator<T, Size>
{
public:
    using MyBase = ArrayPersonalizadoConstIterator<T, Size>;
    using typename MyBase::iterator_category;
    using typename MyBase::value_type;
    using typename MyBase::difference_type;
    using typename MyBase::pointer;
    using typename MyBase::const_reference;
    using typename MyBase::reference;

    constexpr ArrayPersonalizadoIterator() noexcept = default;

    constexpr explicit ArrayPersonalizadoIterator(pointer ptr, size_t offset = 0) noexcept : MyBase(ptr,offset)
    {

    }

    [[nodiscard]] constexpr reference operator*() const noexcept
    {
        return const_cast<reference>(MyBase::operator *());
    }

    constexpr ArrayPersonalizadoIterator& operator ++() noexcept
    {
        MyBase::operator ++();
        return *this;
    }

    constexpr ArrayPersonalizadoIterator operator ++(int) noexcept
    {
        auto temp = *this;
        MyBase::operator ++();
        return temp;
    }

    constexpr ArrayPersonalizadoIterator& operator +=(difference_type offset) noexcept
    {
        MyBase::operator +=(offset);
        return *this;
    }

    [[nodiscard]] constexpr auto operator<=>(const ArrayPersonalizadoIterator& other) const noexcept
    {
        return MyBase::operator<=>(other);
    }

    [[nodiscard]] constexpr bool operator==(const ArrayPersonalizadoIterator& other) const noexcept
    {
        return MyBase::operator==(other);
    }

    constexpr ArrayPersonalizadoIterator& operator--() noexcept
    {
        MyBase::operator --();
        return *this;
    }

    constexpr ArrayPersonalizadoIterator operator--(int) noexcept
    {
        auto temp = *this;
        MyBase::operator --();
        return temp;
    }

    constexpr ArrayPersonalizadoIterator& operator-=(difference_type offset) noexcept
    {
        MyBase::operator -=(offset);
        return *this;
    }

    [[nodiscard]] constexpr pointer operator->() const noexcept
    {
        return const_cast<pointer>(MyBase::operator ->());
    }

    [[nodiscard]] constexpr bool operator!=(const ArrayPersonalizadoIterator &other) const noexcept
    {
        return MyBase::operator !=(other);
    }

    [[nodiscard]] constexpr ArrayPersonalizadoIterator& operator+(difference_type offset ) const noexcept
    {
        auto temp = *this;
        temp += offset;
        return temp;
    }

    [[nodiscard]] constexpr ArrayPersonalizadoIterator& operator-() noexcept
    {
        MyBase::operator --();
        return *this;
    }

    [[nodiscard]] constexpr ArrayPersonalizadoIterator operator-(difference_type offset ) const noexcept
    {
        auto temp = *this;
        temp -= offset;
        return temp;
    }

    [[nodiscard]] constexpr difference_type operator-(const ArrayPersonalizadoIterator& other ) const noexcept
    {
        return MyBase::operator -(other);
    }
};
}

#endif // ARRAYPERSONALIZADOITERATOR_H
