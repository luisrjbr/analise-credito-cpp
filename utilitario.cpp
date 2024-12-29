#include "utilitario.h"

char* Utilitario::converteCpfParaValidacao(std::string &cpf)
{
    // Cria um unique_ptr para o buffer de char, que gerenciará a memória
    std::unique_ptr<char[]> cpfConvertidoChar(new char[cpf.length() + 1]);

    // Copia o conteúdo da string para o buffer
    std::strncpy(cpfConvertidoChar.get(), cpf.c_str(), cpf.length() + 1);

    // Libera o ponteiro do unique_ptr, retornando o char*
    return cpfConvertidoChar.release();
}
