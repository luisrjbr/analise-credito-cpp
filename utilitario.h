#ifndef UTILITARIO_H
#define UTILITARIO_H

#include <string>
#include <cstring>
#include <memory>

namespace CppMasterClass::Pessoa
{

class Utilitario
{
public:
    Utilitario() = default;
    static char* converteCpfParaValidacao(std::string& cpf);
};

}
#endif // UTILITARIO_H
