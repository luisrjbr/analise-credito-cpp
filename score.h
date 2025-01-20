#ifndef SCORE_H
#define SCORE_H

#include <string>
#include "pessoa.h"

namespace CppPessoa = CppMasterClass::Pessoa;

namespace CppMasterClass::Credito
{

class score
{
public:
    score();

    //

    std::string calcularScore(CppPessoa::Pessoa &Pessoa);

};

}
#endif // SCORE_H
