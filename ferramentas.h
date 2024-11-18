#ifndef FERRAMENTAS_H
#define FERRAMENTAS_H

#include <string>
#include <cstring>
#include <memory>

class Ferramentas
{
public:
    Ferramentas() = default;
    char* converteCpfParaValidacao(std::string& cpf);
};
#endif // FERRAMENTAS_H
