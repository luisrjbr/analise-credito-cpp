#include "score.h"


namespace CppMasterClass::Credito
{
    ScoreDeRisco Score::calcularScore(CppPessoa::Pessoa& pessoa) noexcept
    {
        int idade = pessoa.obterIdade();
        double renda = pessoa.obterRenda();

        if(idade >=18 && idade <=30)
        {
            if (renda >2000 && renda <=10000)
                return ScoreDeRisco::ALTO;

            if(renda >= 10000)
                return ScoreDeRisco::MEDIO;
        }
        else if(pessoa.obterIdade() >30 && pessoa.obterIdade() <=60)
        {
            if(renda > 2000 && renda <=10000)
                return ScoreDeRisco::MEDIO;

            if(renda > 10000)
                return ScoreDeRisco::BAIXO;
        }

        return ScoreDeRisco::INDEFINIDO;
    }
}


