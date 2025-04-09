#ifndef SCORE_H
#define SCORE_H

#include <string>
#include "pessoa.h"

namespace CppPessoa = CppMasterClass::Pessoa;

namespace CppMasterClass::Credito
{

enum class ScoreDeRisco
{
    ALTO, MEDIO, BAIXO, INDEFINIDO, DADOS_INVALIDOS
};


class Score
{
public:
    Score() = default;
    virtual ~Score() = default; // <---- destrutor virtual

    ScoreDeRisco calcularScore(const CppPessoa::Pessoa &Pessoa) const noexcept;

private:
    bool validarDados(int idade, double renda) const;

};

}
#endif // SCORE_H
