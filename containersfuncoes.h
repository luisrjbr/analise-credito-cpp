#ifndef CONTAINERSFUNCOES_H
#define CONTAINERSFUNCOES_H

#include <expected>
#include <string>
#include <array>
#include <list>
#include <vector>
#include <chrono>

namespace CppMasterClass::Containers
{
//Ajustar nome ContainersFuncoes
class ContainersFuncoes
{
public:
    ContainersFuncoes() = default;

    template<typename It>
    constexpr It max_element(It begin, It end) noexcept
    {
        auto greaterElement = begin;

        for(auto it = std::next(begin); it != end; it++)
        {
            if(*it > *greaterElement)
                greaterElement = it;
        }

        return greaterElement;
    }

    template<typename VecType>
    auto performanceTest(const std::size_t size)
    {
        VecType vec;
        const auto start = std::chrono::high_resolution_clock::now();
        for (std::size_t i = 0; i < size; ++i)
        {
            vec.push_back(i);
        }

        const auto end = std::chrono::high_resolution_clock::now();
        const auto time = duration_cast<std::chrono::milliseconds>(end - start).count();
        return time;
    }

    template<typename VecType>
    auto performanceTest2(const std::size_t size)
    {
        VecType vec(size);
        const auto start = std::chrono::high_resolution_clock::now();
        for (std::size_t i = 0; i < size; ++i)
        {
            vec[i] = i;
        }

        const auto end = std::chrono::high_resolution_clock::now();
        const auto time = duration_cast<std::chrono::milliseconds>(end - start).count();
        return time;
    }
};
}

#endif // CONTAINERSFUNCOES_H
