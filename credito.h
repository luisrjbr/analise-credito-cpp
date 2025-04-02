#ifndef CREDITO_H
#define CREDITO_H

#include <string>
#include <memory>
#include "analise.h"
#include "fraude.h"
#include "pessoa.h"
#include "score.h"
#include "arraypersonalizado.h"
#include "containersfuncoes.h"

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
    virtual ~Credito() = default; // <--- adicionando destrutor virtual

    //
    std::string mensagemRegrasPreCredito = "";
    //a linha abaixo causa um stack overflow, pois vai além do limite da stack. A única preocupação com a stack é quanto ao tamanho. Ela também é volátil
    //inline static constexpr size_t NUMEROPARCELAS = (((1024 * 1024) / sizeof(int))) * 8;

    //memória global inicializando com inline e global com static
    inline static constexpr size_t NUMEROPARCELAS = 4;
    float creditoFornecido = 0;
    float maiorValorDaParcela = 0;

    //

    bool analisarRegrasPreCredito(CppPessoa::Pessoa& pessoa) noexcept;
    float informarLimiteDeCredito(CppPessoa::Pessoa& pessoa) noexcept;
    float obterNumeroParcelasDoCredito() noexcept;
    const Score& obterScore() const { return *m_score; }

protected:
    std::unique_ptr<Score> m_score;

};

}
#endif // CREDITO_H
