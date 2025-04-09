#include "score.h"


namespace CppMasterClass::Credito
{

namespace
{
    constexpr int IDADE_MINIMA = 18;
    constexpr int IDADE_JOVEM_MAXIMA = 30;
    constexpr int IDADE_ADULTO_MAXIMA = 60;
    constexpr double RENDA_MINIMA = 2000.0;
    constexpr double RENDA_MEDIA = 10000.0;
}


bool Score::validarDados(int idade, double renda) const
{
    return idade >= 0 && renda >= 0.0;
}

ScoreDeRisco Score::calcularScore(const CppPessoa::Pessoa& pessoa) const noexcept
    {
        int idade = pessoa.obterIdade();
        double renda = pessoa.obterRenda();

        if(!validarDados(idade, renda))
            return ScoreDeRisco::DADOS_INVALIDOS;

        if(idade >=IDADE_MINIMA && idade <=IDADE_JOVEM_MAXIMA)
        {
            if (renda >RENDA_MINIMA && renda <=RENDA_MEDIA)
                return ScoreDeRisco::ALTO;

            if(renda >= RENDA_MEDIA)
                return ScoreDeRisco::MEDIO;
        }
        else if(idade >IDADE_JOVEM_MAXIMA && idade <=IDADE_ADULTO_MAXIMA)
        {
            if(renda > RENDA_MINIMA && renda <=RENDA_MEDIA)
                return ScoreDeRisco::MEDIO;

            if(renda > RENDA_MEDIA)
                return ScoreDeRisco::BAIXO;
        }

        return ScoreDeRisco::INDEFINIDO;
    }
}
