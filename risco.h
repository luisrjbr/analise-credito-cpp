#ifndef RISCO_H
#define RISCO_H

#include<vector>
#include "pessoa.h"

enum class TipoDeRisco
{
    ALTO, MEDIO, BAIXO
};

class Risco
{
public:
    Risco() = default;
    std::vector<Pessoa> pessoasComRisco;
    bool verificarPessoaComRisco(Pessoa& pessoa);
    void listaPessoasComRisco();
    TipoDeRisco calcularScoreRisco();

private:


};

#endif // RISCO_H
