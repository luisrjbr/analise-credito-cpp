#ifndef ANALISE_H
#define ANALISE_H

#include <iostream>
#include <string>
#include <vector>


template <typename T>
class Analise
{
public:
    Analise();

    void adicionarItem(const T& itemAnalise)
    {
        m_itensAnalise.push_back(itemAnalise);
    }

    void processarItensAnalise() const
    {
        for(const auto& item : m_itensAnalise)
        {
            if(verificaAlerta(item))
            {
                std::cout << "Alerta identificado" << item.descricao() << std::endl;
            }
        }
    }

private:
    std::vector<T> m_itensAnalise;

    bool verificaAlerta(const T& itemAnalise) const
    {
        return itemAnalise.valorAlerta();
    }
};

#endif // ANALISE_H
