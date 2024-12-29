#include "credito.h"

Credito::Credito() {}

std::string Credito::analisarRegrasPreCredito(Pessoa& pessoa) noexcept
{
    Analise<Fraude> analiseFraude;
    analiseFraude.adicionarItem(Fraude(pessoa));

    Analise<Pessoa> analisePessoa;
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
