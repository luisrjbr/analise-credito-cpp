#ifndef ARRAYFUNCOES_H
#define ARRAYFUNCOES_H

#include <expected>
#include <string>
#include <array>
#include <list>
#include <vector>

namespace CppMasterClass::ArraysAlgoritmos
{
//Ajustar nome ContainersFuncoes
class ArrayFuncoes
{
public:
    ArrayFuncoes() = default;

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
};
}

#endif // ARRAYFUNCOES_H
