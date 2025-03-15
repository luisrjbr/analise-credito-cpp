#ifndef VECTORPERSONALIZADO_H
#define VECTORPERSONALIZADO_H

#include <iostream>
#include "vectorpersonalizadoconstiterator.h"

namespace CppMasterClass::Containers
{
template<typename T>
class VectorPersonalizado
{

public:
    using iterator = VectorPersonalizadoConstIterator<T>;

    //corrige a regra dos 3
    VectorPersonalizado() = default;

    //A implementação com o construtor torna mais rápida a execução, pois já aloca o tamanho total e não precisa realocar no push back
    VectorPersonalizado(std::size_t size) : m_size(size), m_capacity(size) {
        m_data = new T[m_capacity](); // Aloca e inicializa com valores padrão
    }

    VectorPersonalizado(const VectorPersonalizado &other)
    {
        m_size = other.m_size;
        m_capacity = other.m_capacity;
        m_data = new T[m_capacity];

        for(std::size_t i = 0; i < m_size; ++i)
        {
            m_data[i] = other.m_data[i];
        }
    }

    //corrige a regra dos 5 O(1)
    VectorPersonalizado(VectorPersonalizado &&other)
    {
        m_size = other.m_size;
        m_capacity = other.m_capacity;
        m_data = other.m_data;

        other.m_size = 0;
        other.m_capacity = 0;
        other.m_data = nullptr;
    }


    ~VectorPersonalizado()
    {
        delete []m_data;
    }

    //corrige a regra dos 3 O(n)
    VectorPersonalizado& operator=(const VectorPersonalizado &other)
    {
        if(this != &other)
        {
            clear();
            m_size = other.m_size;
            m_capacity = other.m_capacity;
            m_data = new T[m_capacity];

            for(std::size_t i = 0; i < m_size; ++i)
            {
                m_data[i] = other.m_data[i];
            }
        }

        return *this;
    }

    //corrige a regra dos 5 O(1)
    VectorPersonalizado& operator=(VectorPersonalizado &&other)
    {
        if(this != &other)
        {
            clear();
            m_size = other.m_size;
            m_capacity = other.m_capacity;
            m_data = other.m_data;

            other.m_size = 0;
            other.m_capacity = 0;
            other.m_data = nullptr;
        }

        return *this;
    }


    constexpr void clear()
    {
        delete []m_data;
        m_data = nullptr;
        m_size = 0;
        m_capacity = 0;
    }

    constexpr void resize(const std::size_t sz)
    {
        auto newData = new T[sz]{};
        const auto minSize = (sz < m_size) ? sz : m_size;

        for(std::size_t i = 0; i < minSize; ++i)
        {
            newData[i] = m_data[i];
        }

        delete []m_data;
        m_data = newData;
        m_size = sz;
        m_capacity = 0;
    }

    constexpr void push_back(const T& value)
    {
        if(m_size == m_capacity) //Reallocation, ajuste de performance
        {
            m_capacity = m_size > 0 ? m_size * 2 : 2;

            auto newData = new T[m_capacity];

            for(std::size_t i = 0; i < m_size; ++i)
            {
                //se ele pode ser movido
                if(std::is_move_constructible<T>())
                {
                    newData[i] = std::move(m_data[i]);
                }
                // se não copia se não tiver o construtor de move
                else
                {
                    newData[i] = m_data[i];
                }
            }

            delete []m_data;
            m_data = newData;
        }

        m_data[m_size] = value;
        ++m_size;
    }

    [[nodiscard]] constexpr std::size_t size() const noexcept
    {
        return m_size;
    }

    [[nodiscard]] constexpr bool empty() const noexcept
    {
        return m_size == 0;
    }

    [[nodiscard]] constexpr T& operator[](const std::size_t index) noexcept
    {
        return m_data[index];
    }

    [[nodiscard]] constexpr const T& operator[](const std::size_t index) const noexcept
    {
        return m_data[index];
    }

    iterator begin() noexcept
    {
        return iterator(m_data);
    }

    iterator end() noexcept
    {
        return iterator(m_data, m_size);
    }



private:
    T *m_data{nullptr};
    std::size_t m_size{0};
    std::size_t m_capacity{0};

};

}
#endif // VECTORPERSONALIZADO_H
