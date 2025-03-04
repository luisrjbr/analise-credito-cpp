#include "credito.h"

namespace CppPessoa = CppMasterClass::Pessoa;
namespace CppArray = CppMasterClass::ArraysPersonalizados;
namespace CppAlgoritmos = CppMasterClass::ArraysAlgoritmos;

namespace CppMasterClass::Credito
{

Credito::Credito() {}

bool Credito::analisarRegrasPreCredito(CppPessoa::Pessoa& pessoa) noexcept
{
    Analise<Fraude> analiseFraude;
    analiseFraude.adicionarItem(Fraude(pessoa));

    Analise<CppPessoa::Pessoa> analisePessoa;
    analisePessoa.adicionarItem(pessoa);

    auto resultadoFraude = analiseFraude.processarItensAnalise();
    auto resultadoPessoa = analisePessoa.processarItensAnalise();

    if(!resultadoFraude.has_value())
    {
        Credito::mensagemRegrasPreCredito = resultadoFraude.error();
        return false;
    }
    else if(!resultadoPessoa.has_value())
    {
        Credito::mensagemRegrasPreCredito = resultadoPessoa.error();
        return false;
    }
    else
    {
        Credito::mensagemRegrasPreCredito = resultadoFraude.value() + "\n" + resultadoPessoa.value();
        return true;
    }
}

float Credito::informarLimiteDeCredito(CppPessoa::Pessoa& pessoa) noexcept
{
    if(Credito::m_score->calcularScore(pessoa) == ScoreDeRisco::ALTO)
    {
        creditoFornecido = 3000.00;
        return 3000.00;
    }
    if(Credito::m_score->calcularScore(pessoa) == ScoreDeRisco::MEDIO)
    {
        creditoFornecido = 6000.00;
        return 6000.00;
    }
    if(Credito::m_score->calcularScore(pessoa) == ScoreDeRisco::BAIXO)
    {
        creditoFornecido = 9000.00;
        return 9000.00;
    }

    return 0.0;
}

float Credito::obterNumeroParcelasDoCredito() noexcept
{
    CppAlgoritmos::ArrayFuncoes arrayFuncoes;

    float creditoFuturoParcelado = creditoFornecido / NUMEROPARCELAS;
    float juros = 0.01;
    constexpr size_t LIMITESTACK = ((((1024 * 1024) / sizeof(int))) * 8);

    //Heap - aloca na heap para não ter erro de stack overflow
    if constexpr (NUMEROPARCELAS >= LIMITESTACK)
    {
        //stack = heap;
        auto arrParcelas = std::make_unique<CppArray::ArrayPersonalizado<int, NUMEROPARCELAS>>();

        (*arrParcelas)[0] = creditoFuturoParcelado + (creditoFuturoParcelado * juros);

        for(size_t i = 1; i < NUMEROPARCELAS; ++i)
        {
            (*arrParcelas)[i] = (*arrParcelas)[i-1] + ((*arrParcelas)[i-1] * juros);
        }

        const auto res = arrayFuncoes.max_element((*arrParcelas).begin(), (*arrParcelas).end());

        return 0;
    }
    //Stack
    else
    {
        CppArray::ArrayPersonalizado<int, NUMEROPARCELAS> arrParcelas;

        arrParcelas[0] = creditoFuturoParcelado + (creditoFuturoParcelado * juros);

        for(size_t i = 1; i < NUMEROPARCELAS; ++i)
        {
            arrParcelas[i] = arrParcelas[i-1] + (arrParcelas[i-1] * juros);
        }

        const auto res = arrayFuncoes.max_element(arrParcelas.begin(), arrParcelas.end());

        return *res;
    }

    return 0;
}
}

