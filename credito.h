#ifndef CREDITO_H
#define CREDITO_H

#include <string>
#include "analise.h"
#include "fraude.h"
#include "pessoa.h"

namespace CppPessoa = CppMasterClass::Pessoa;

namespace CppMasterClass::Credito
{

enum class TipoDeRisco
{
    ALTO, MEDIO, BAIXO
};


class Credito
{
public:
    Credito();

    //

    std::string analisarRegrasPreCredito(CppPessoa::Pessoa& pessoa) noexcept;

};

}
#endif // CREDITO_H
