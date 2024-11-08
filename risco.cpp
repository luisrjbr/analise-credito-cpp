#include "risco.h"

bool Risco::verificarPessoaComRisco(Pessoa& pessoa)
{
    listaPessoasComRisco();

    for(Pessoa p : pessoasComRisco)
    {
        if (p.obterCpf() == pessoa.obterCpf())
            return true;
    }
    return false;
}

void Risco::listaPessoasComRisco()
{
    char input_cpf1[12] {'9','4','0','8','9','3','0','0','0','2','9'};
    char input_cpf2[12] {'4','4','4','4','0','2','8','5','0','5','8'};
    char input_cpf3[12] {'7','1','9','2','5','0','1','7','0','0','1'};
    char input_cpf4[12] {'4','1','8','5','2','1','9','8','0','6','0'};

    Risco::pessoasComRisco.push_back(Pessoa(input_cpf1, 1500, 25));
    Risco::pessoasComRisco.push_back(Pessoa(input_cpf2, 2500, 35));
    Risco::pessoasComRisco.push_back(Pessoa(input_cpf3, 3500, 45));
    Risco::pessoasComRisco.push_back(Pessoa(input_cpf4, 4500, 55));
}
