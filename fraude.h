#ifndef FRAUDE_H
#define FRAUDE_H

#include<vector>
#include <string>
#include "pessoa.h"

namespace CppPessoa = CppMasterClass::Pessoa;

namespace CppMasterClass::Credito
{

class Fraude
{
public:
    //

    Fraude() = default;
    Fraude(CppPessoa::Pessoa& pessoa);

    //

    CppPessoa::Pessoa pessoaParaAnaliseFraude;
    std::vector<CppPessoa::Pessoa> pessoasComFraude;
    inline static constexpr std::string DESCRICAO = "Fraude!";

    //

    void listarPessoasComFraude() noexcept;
    bool validarRegras() noexcept;

    std::string obterDescricaoValidacao() const
    {
        return DESCRICAO;
    }

};

}
#endif // FRAUDE_H
