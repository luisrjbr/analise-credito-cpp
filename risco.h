#ifndef RISCO_H
#define RISCO_H

#include<vector>
#include "pessoa.h"

class Risco
{
public:
    Risco() = default;
    std::vector<Pessoa> pessoasComRisco;
    bool verificarPessoaComRisco(Pessoa& pessoa);
    void listaPessoasComRisco();

private:


};

#endif // RISCO_H
