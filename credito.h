#ifndef CREDITO_H
#define CREDITO_H

#include <string>
#include "analise.h"
#include "fraude.h"
#include "pessoa.h"

enum class TipoDeRisco
{
    ALTO, MEDIO, BAIXO
};

class Credito
{
public:
    Credito();

    //

    std::string analisarRegrasPreCredito(Pessoa& pessoa) noexcept;

};

#endif // CREDITO_H
