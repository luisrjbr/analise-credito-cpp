#include "credito.h"

namespace CppPessoa = CppMasterClass::Pessoa;

namespace CppMasterClass::Credito
{

Credito::Credito() {}

std::string Credito::analisarRegrasPreCredito(CppPessoa::Pessoa& pessoa) noexcept
{
    Analise<Fraude> analiseFraude;
    analiseFraude.adicionarItem(Fraude(pessoa));

    Analise<CppPessoa::Pessoa> analisePessoa;
    analisePessoa.adicionarItem(pessoa);

    auto resultadoFraude = analiseFraude.processarItensAnalise();

    if(!resultadoFraude.has_value())
    {
        return resultadoFraude.error();
    }

    auto resultadoPessoa = analisePessoa.processarItensAnalise();

    if(!resultadoPessoa.has_value())
    {
        return resultadoPessoa.error();
    }

    return resultadoFraude.value() + "\n" + resultadoPessoa.value();

}

}
