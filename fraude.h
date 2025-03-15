#ifndef FRAUDE_H
#define FRAUDE_H

#include <string>
#include <memory>
#include "vectorpersonalizado.h"
#include "pessoa.h"

namespace CppPessoa = CppMasterClass::Pessoa;
namespace CppContainers = CppMasterClass::Containers;

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
    //vetor personalizado
    CppContainers::VectorPersonalizado<CppPessoa::Pessoa> pessoasComFraude;

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
