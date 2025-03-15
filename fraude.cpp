#include "fraude.h"

namespace CppPessoa = CppMasterClass::Pessoa;

namespace CppMasterClass::Credito
{

Fraude::Fraude(CppPessoa::Pessoa& pessoa) : pessoaParaAnaliseFraude(pessoa) {}

bool Fraude::validarRegras() noexcept
{
    //cria uma lista fake de pessoas com produtos contratados
    listarPessoasComFraude();

    if (pessoasComFraude.empty() && pessoasComFraude.size() == 0)
    {
        for(const CppPessoa::Pessoa& p : pessoasComFraude)
        {
            if (p.obterCpf() == pessoaParaAnaliseFraude.obterCpf())
                return true;
        }
    }

    return false;
}

//Passo 3: Verificar Padrão de Análise de Fraudes (Padrões e Anomalias)
//Todas as listas são fakes para testes
void Fraude::listarPessoasComFraude() noexcept
{
    //94089300029, 44440285058, 71925017001, 41852198060

    char input_cpf1[12] {'9','4','0','8','9','3','0','0','0','2','9'};
    char input_cpf2[12] {'4','4','4','4','0','2','8','5','0','5','8'};
    char input_cpf3[12] {'7','1','9','2','5','0','1','7','0','0','1'};
    char input_cpf4[12] {'4','1','8','5','2','1','9','8','0','6','0'};

    Fraude::pessoasComFraude.push_back(CppPessoa::Pessoa(input_cpf1, 1500, 25));
    Fraude::pessoasComFraude.push_back(CppPessoa::Pessoa(input_cpf2, 2500, 35));
    Fraude::pessoasComFraude.push_back(CppPessoa::Pessoa(input_cpf3, 3500, 45));
    Fraude::pessoasComFraude.push_back(CppPessoa::Pessoa(input_cpf4, 4500, 55));
}
}
