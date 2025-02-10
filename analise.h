#ifndef ANALISE_H
#define ANALISE_H

#include <iostream>
#include <string>
#include <vector>
#include <expected>

namespace CppMasterClass::Credito
{

//Solução genérica que funciona com diferentes tipos de objetos usando polimorfismo estático com templates
//Essa implementação funciona como um padrão strategy em que a estratégia é delegada a outros objetos
//que definem suas próprias versões de "estratégia" de Validar Regras.
template <typename T>
class Analise
{
public:
    void adicionarItem(const T& itemAnalise) noexcept
    {
        m_itensAnalise.push_back(itemAnalise);
    }

    //quem está chamando não deve descartar o retorno
    //trata o erro com expected
    //não tem emissão de exeption
    [[nodiscard]] std::expected<std::string, std::string> processarItensAnalise() noexcept
    {
        std::string resultado;
        std::string descricao;

        for(auto& item : m_itensAnalise)
        {
            if(descricao.empty())
                descricao = item.obterDescricaoValidacao();

            if(verificaAlerta(item))
            {
                resultado += "Erro na análise de: " + descricao + "\n";
            }
        }

        if(resultado.empty())
        {
            return std::expected<std::string, std::string>("Análise concluída sem erros: " + descricao);
        }

        return std::unexpected(resultado);
    }

private:
    std::vector<T> m_itensAnalise;

    bool verificaAlerta(T& itemAnalise) noexcept
    {
        return itemAnalise.validarRegras();
    }
};

}
#endif // ANALISE_H
