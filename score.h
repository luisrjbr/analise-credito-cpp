#ifndef SCORE_H
#define SCORE_H

#include <string>
#include "pessoa.h"

namespace CppPessoa = CppMasterClass::Pessoa;

namespace CppMasterClass::Credito
{

enum class ScoreDeRisco
{
    ALTO, MEDIO, BAIXO
};


class Score
{
public:
    Score();

    //

    ScoreDeRisco calcularScore(CppPessoa::Pessoa &Pessoa) noexcept;

};

}
#endif // SCORE_H
