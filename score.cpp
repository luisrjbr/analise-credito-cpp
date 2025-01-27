#include "score.h"


namespace CppMasterClass::Credito
{
    ScoreDeRisco Score::calcularScore(CppPessoa::Pessoa& pessoa) noexcept
    {
        bool temRisco = false;

        temRisco = (pessoa.obterIdade() >=18 && pessoa.obterIdade() <=30) &&
               (pessoa.obterRenda() >2000 && pessoa.obterRenda() <= 10000);

        if (temRisco)
            return ScoreDeRisco::ALTO;

        temRisco = (pessoa.obterIdade() >=18 && pessoa.obterIdade() <=30) &&
                            (pessoa.obterRenda() >= 10000);

        if (temRisco)
            return ScoreDeRisco::MEDIO;

        temRisco = (pessoa.obterIdade() >30 && pessoa.obterIdade() <=60) &&
                        (pessoa.obterRenda() > 2000 && pessoa.obterRenda() <=10000);

        if (temRisco)
            return ScoreDeRisco::MEDIO;

        temRisco = (pessoa.obterIdade() >30 && pessoa.obterIdade() <=60) &&
                        (pessoa.obterRenda() > 10000);

        if (temRisco)
            return ScoreDeRisco::BAIXO;
    }
}


