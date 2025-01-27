#include "credito.h"

namespace CppPessoa = CppMasterClass::Pessoa;

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

double Credito::informarLimiteDeCredito(CppPessoa::Pessoa& pessoa) noexcept
{
    if(Credito::m_score->calcularScore(pessoa) == ScoreDeRisco::ALTO)
        return 3000.00;
    if(Credito::m_score->calcularScore(pessoa) == ScoreDeRisco::MEDIO)
        return 6000.00;
    if(Credito::m_score->calcularScore(pessoa) == ScoreDeRisco::BAIXO)
        return 9000.00;
}

}
