#ifndef CREDITO_H
#define CREDITO_H

#include <string>
#include <memory>
#include "analise.h"
#include "fraude.h"
#include "pessoa.h"
#include "score.h"

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

    //

    bool analisarRegrasPreCredito(CppPessoa::Pessoa& pessoa) noexcept;
    double informarLimiteDeCredito(CppPessoa::Pessoa& pessoa) noexcept;
    const Score& obterScore() const { return *m_score; }

private:
    std::unique_ptr<Score> m_score;

};

}
#endif // CREDITO_H
