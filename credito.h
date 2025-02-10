#ifndef CREDITO_H
#define CREDITO_H

#include <string>
#include <memory>
#include "analise.h"
#include "fraude.h"
#include "pessoa.h"
#include "score.h"
#include "arraypersonalizado.h"
#include "arrayfuncoes.h"

namespace CppPessoa = CppMasterClass::Pessoa;

namespace CppMasterClass::Credito
{

enum class TipoDeRisco
{
    ALTO, MEDIO, BAIXO
};


class Credito
{
public:
    Credito();

    //
    std::string mensagemRegrasPreCredito = "";
    inline static constexpr size_t NUMEROPARCELAS = 4;
    int parcelaSemJuros = 0;
    float creditoFornecido = 0;
    float maiorValorDaParcela = 0;

    //

    bool analisarRegrasPreCredito(CppPessoa::Pessoa& pessoa) noexcept;
    float informarLimiteDeCredito(CppPessoa::Pessoa& pessoa) noexcept;
    float obterNumeroParcelasDoCredito() noexcept;
    const Score& obterScore() const { return *m_score; }

private:
    std::unique_ptr<Score> m_score;

};

}
#endif // CREDITO_H
